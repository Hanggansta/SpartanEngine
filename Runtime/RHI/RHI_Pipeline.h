/*
Copyright(c) 2016-2019 Panos Karabelas

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
#include "RHI_Definition.h"
#include "RHI_Viewport.h"
#include <memory>
#include "../Math/Rectangle.h"
//============================

namespace Spartan
{
	class RHI_Pipeline
	{
	public:
		RHI_Pipeline() = default;
		~RHI_Pipeline();
	
		bool Create();
		void ImGuiDescriptorTest(uint32_t slot, void* texture);
		
		void* GetPipeline() const		{ return m_graphics_pipeline; }
		void* GetPipelineLayout() const	{ return m_pipeline_layout; }
		void* GetRenderPass() const		{ return m_render_pass; }
		void* GetDescriptorSet() const	{ return m_descriptor_set; }

		std::shared_ptr<RHI_Device> m_rhi_device;
		std::shared_ptr<RHI_Shader> m_shader_vertex;
		std::shared_ptr<RHI_Shader> m_shader_pixel;
		std::shared_ptr<RHI_ConstantBuffer> m_constant_buffer;
		std::shared_ptr<RHI_InputLayout> m_input_layout;	
		std::shared_ptr<RHI_RasterizerState> m_rasterizer_state;
		std::shared_ptr<RHI_BlendState> m_blend_state;
		std::shared_ptr<RHI_DepthStencilState> m_depth_stencil_state;
		RHI_Viewport m_viewport;
		Math::Rectangle m_scissor;
		RHI_PrimitiveTopology_Mode m_primitive_topology;

		// Temp
		std::shared_ptr<RHI_Texture> m_texture;
		std::shared_ptr<RHI_Sampler> m_sampler;

	private:
		void* m_graphics_pipeline		= nullptr;
		void* m_pipeline_layout			= nullptr;
		void* m_render_pass				= nullptr;
		void* m_descriptor_pool			= nullptr;
		uint32_t m_descriptor_count		= 0;
		void* m_descriptor_set_layout	= nullptr;
		void* m_descriptor_set			= nullptr;
	};
}
