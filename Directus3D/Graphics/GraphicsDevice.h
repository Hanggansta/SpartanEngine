/*
Copyright(c) 2016 Panos Karabelas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

//= INCLUDES =================
#include "D3D11/D3D11Device.h"
//============================

enum InputLayout
{
	Auto,
	Position,
	PositionColor,
	PositionTexture,
	PositionTextureNormalTangent
};

enum CullMode
{
	CullBack,
	CullFront,
	CullNone,
};

class GraphicsDevice
{
public:
	GraphicsDevice();
	~GraphicsDevice();

	void Initialize(HWND drawPaneHandle);
	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();

	void Begin();
	void End();
	void ResetRenderTarget();
	void ResetViewport();
	void EnableZBuffer(bool enable);
	bool SetInputLayout(InputLayout inputLayout);
	void SetCullMode(CullMode cullMode);
	void SetViewport(int width, int height);
private:
	D3D11Device* m_D3D11Device;
	InputLayout m_inputLayout;
	CullMode m_cullMode;
};