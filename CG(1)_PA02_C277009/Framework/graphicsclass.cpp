////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;
	for (int i = 0; i < 3; i++)
	{
		m_Model[i] = 0;
	}
	m_ColorShader = 0;
	m_angle = 0.0f;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;


	// Create the Direct3D object.
	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);

	// Create the model object.
	for (int i = 0; i < 3; i++)
	{
		m_Model[i] = new ModelClass;
		if (!m_Model[i])
		{
			return false;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		// Initialize the model object.
		result = m_Model[i]->Initialize(m_D3D->GetDevice(), i);
		if (!result)
		{
			MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
			return false;
		}
	}

	// Create the color shader object.
	m_ColorShader = new ColorShaderClass;
	if(!m_ColorShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_ColorShader->Initialize(m_D3D->GetDevice(), hwnd);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
		return false;
	}

	m_Color = new ColorClass;
	if (!m_Color)
	{
		return false;
	}
	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the color shader object.
	if(m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}

	// Release the model object.
	for (int i = 0; i < 3; i++)
	{
		if (m_Model[i])
		{
			m_Model[i]->Shutdown();
			delete m_Model[i];
			m_Model[i] = 0;
		}
	}

	// Release the camera object.
	if(m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the D3D object.
	if(m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	if (m_Color)
	{
		delete m_Color;
		m_Color = 0;
	}

	return;
}


bool GraphicsClass::Frame()
{
	bool result;


	// Render the graphics scene.
	result = Render();
	if(!result)
	{
		return false;
	}

	return true;
}

void GraphicsClass::setBackgroundColor(float red, float green, float blue, float alpha)
{
	m_Color->setColor(red, green, blue, alpha);
}

void GraphicsClass::setSolid()
{
	m_D3D->setSolid();
}

void GraphicsClass::setWireframe()
{
	m_D3D->setWireframe();
}

void GraphicsClass::setCullBack()
{
	m_D3D->setCullBack();
}

void GraphicsClass::setBrightness(float value)
{
	m_Color->setBrightness(value);
}

float GraphicsClass::calcAngle()
{
	m_angle += 1.0f;
	if (m_angle >= 360.0f)
	{
		m_angle -= 360.0f;
	}
	return m_angle;
}

bool GraphicsClass::Render()
{
	XMMATRIX worldMatrix[3], viewMatrix, projectionMatrix;
	bool result;


	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(m_Color->getRed(), m_Color->getGreen(), m_Color->getBlue(), m_Color->getAlpha());

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Camera->GetViewMatrix(viewMatrix);
	for (int i = 0; i < 3; i++)
	{
		m_D3D->GetWorldMatrix(worldMatrix[i], i);
	}
	m_D3D->GetProjectionMatrix(projectionMatrix);

	// rotate worldmatrix of objects
	worldMatrix[0] *= XMMatrixRotationX((XM_PI / 180) * calcAngle());
	worldMatrix[0] *= XMMatrixTranslation(-3.5f, 0.0f, 0.0f);
	worldMatrix[1] *= XMMatrixRotationY((XM_PI / 180) * calcAngle());
	worldMatrix[1] *= XMMatrixTranslation(0.0f, 0.0f, 0.0f);
	worldMatrix[2] *= XMMatrixRotationZ((XM_PI / 180) * calcAngle());
	worldMatrix[2] *= XMMatrixTranslation(3.5f, 0.0f, 0.0f);

	for (int i = 0; i < 3; i++)
	{
		// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
		m_Model[i]->Render(m_D3D->GetDeviceContext());

		// Render the model using the color shader.
		result = m_ColorShader->Render(m_D3D->GetDeviceContext(), m_Model[i]->GetIndexCount(),
			worldMatrix[i], viewMatrix, projectionMatrix, m_Color->getBrightness());
		if(!result)
		{
			return false;
		}
	}

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}