#include <stdio.h>
#include <vulkan/vulkan.h>

/*	Vocabulary
	* VkInstance - Vulkan context, driver access
	* VkPhysicalDevice - Represents a physical GPU
	* VkDevice - Logical device, interface to GPU
	* VkBuffer - GPU memory chunk
	* VkImage - texture to read and write
	* VkPipeline - holds the state of GPU, needed to draw and stores options such as shaders, rasterization, depth
	* VkRenderPass - info about image being rendered into, all drawing commands are donr here
	* VkFrameBuffer - Holds target image for VkRenderPass
	* VkCommandBuffer - Encodes GPU commands, execution to be performed on the GPU must be encoded here
	* VkQueue - GPU's have a set of queue's, some for graphics, some for memory, etc. Command buffers are submitted into a queue
	* VkDescriptorSet - holds info that connects shader inputs to data such as VkBuffer and VkImage. GPU side pointers
	* VkSwapchainKHR - holds images for the screen, allows for rendering to the window. KHR maeans it comes from the VK_KHR_swapchain extension
	* VkSemaphore - syncs GPU command executions like multiple command buffer submissions one after another
	* Vkfence - Syncs GPU command executions as well, used to know if a command buffer has finished being executed
*/

/* App flow
	* Engine init:
	* create VkInstance, 
	* query list of VkPhysicalDevice's for GPU's, eg. discrete and integrated GPU's will both have a VkPhysicalDevice
	* we pick our device(s) and create a VkDevice for it
	* we can use this VkDevice to get VkQueue handles which will allow us to execute commands
	* Init VkSwapchainKHR
	* with our VkQueue, we can reate VkCommandPool objects that let us allocate command buffers
	*
	* Asset init:
	* load materials
	* create a set of VkPipeline's for the shader combinations and the params needed to render 
	* for meshes, upload vertex data into VkBuffer resources and upload textures into VkImage resources, this makes the images readable
	* we also makle VkRenderPass objects for our main rendering passes
	* there may be a VkRenderPass for main rendering, another for shadows, etc. these can be parallelized
	* VkPipeline creation can be expensive
	*
	* Render Loop:
	* we ask VkSwapchainKHR for an image to render to 
	* we allocate a VkCommandBuffer from a VkCommandBufferPool, we can reuses an already existing one
	* we start the VkCommandBuffer so wer can write commands to it
	* we render by starting a VkRenderPass either with a normal one or through dynamic rendering
	* the image pass specifies we are rendering to the image requested from swapchain
	* we create a loop where we bind a VkPipeline, some VkDescriptorSet resources for the shader params, bind the vertex buffers, the execute a draw call
	* once we finish drawing, we end the VkRenderPass
	* if no more to render, we end the VkCommandBuffer
	* we submit the command buffer into the rendering queue
	* this will begin execution of the commands in the command buffer on the GPU
	* we present the image
	* we use a semaphore to ensure the presentation waits until rendering is finished
	* Psuedo Code:
		// Ask the swapchain for the index of the swapchain image we can render onto
		int image_index = request_image(mySwapchain);

		// Create a new command buffer
		VkCommandBuffer cmd = allocate_command_buffer();

		// Initialize the command buffer
		vkBeginCommandBuffer(cmd, ... );

		// Start a new renderpass with the image index from swapchain as target to render onto
		// Each framebuffer refers to a image in the swapchain
		vkCmdBeginRenderPass(cmd, main_render_pass, framebuffers[image_index] );

		// Rendering all objects
		for(object in PassObjects){

			// Bind the shaders and configuration used to render the object
			vkCmdBindPipeline(cmd, object.pipeline);
			
			// Bind the vertex and index buffers for rendering the object
			vkCmdBindVertexBuffers(cmd, object.VertexBuffer,...);
			vkCmdBindIndexBuffer(cmd, object.IndexBuffer,...);

			// Bind the descriptor sets for the object (shader inputs)
			vkCmdBindDescriptorSets(cmd, object.textureDescriptorSet);
			vkCmdBindDescriptorSets(cmd, object.parametersDescriptorSet);

			// Execute drawing
			vkCmdDraw(cmd,...);
		}

		// Finalize the render pass and command buffer
		vkCmdEndRenderPass(cmd);
		vkEndCommandBuffer(cmd);


		// Submit the command buffer to begin execution on GPU
		vkQueueSubmit(graphicsQueue, cmd, ...);

		// Display the image we just rendered on the screen
		// renderSemaphore makes sure the image isn't presented until `cmd` is finished executing
		vkQueuePresent(graphicsQueue, renderSemaphore);
*/ 

/*
	* Layout:
	* \assets // textures, 3d models
	* \bin  // build
	* \shaders // shaders and compiled output
	* \chapter_n // chapter of guide
	* \third_party // libraries
	*
	* Libraries:
	* GLM - openGL math for linear algebra
	* SDL - window and input
	* dear IMGUI - GUI 
	* STB Image - image loading
	* Tiny Obj Loader
	* Vk Bootstrap - boilerplayer abstraction
	* VMA - vulcan memory allocator
*/

/* Useful Links
 * https://vkguide.dev
 * https://github.com/vblanco20-1/vulkan-guide/
 * https://vulkan-tutorial.com/en/Drawing_a_triangle/Setup/Base_code
 * https://www.vulkan.org/learn
*/

int main(int argc, char *argv[])
{
	// Program overview:
	// Create a VkInstance
	// Select a supported graphics card (VkPhysicalDevice)
	// Create a VkDevice and VkQueue for drawing and presentation
	// Create a window, window surface and swap chain
	// Wrap the swap chain images into VkImageView
	// Create a render pass that specifies the render targets and usage
	// Create framebuffers for the render pass
	// Set up the graphics pipeline
	// Allocate and record a command buffer with the draw commands for every possible swap chain image
	// Draw frames by acquiring images, submitting the right draw command buffer and returning the images back to the swap chain
	printf("%s\n", "Hello from C");

	return 0;
}
