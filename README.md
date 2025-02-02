Stable Diffusion Tools for Unreal Engine
========================================

Description
-----------
This plugin feeds your editor viewport through the [Diffusers](https://github.com/huggingface/diffusers) library to create AI synthesized imagery.

![StableDiffusionPluginUnreal](https://user-images.githubusercontent.com/795851/195005569-b7b33432-a981-4f76-81d5-d9948861fd84.png)

Requirements
------------

* Unreal Engine 5.0
* CUDA compatible GPU (Nvidia)
* Minimum 6GB Vram (to run Unreal and fp16 Stable Diffusion simultaneously)


Installation
------------
Clone this repo and copy the `StableDiffusionTools` folder to `YourProjectFolder/Plugins/` or download the latest release from the [releases page.](https://github.com/Mystfit/Unreal-StableDiffusionTools/releases)

Usage
-----
[Video walkthrough for v0.1](https://youtu.be/dihSydSkd4I)

### Enabling the plugin
After installing the plugin, activate it through `Windows->Plugins`. To open the main tool window for the plugin, go to `Windows->StableDiffusionTools`.

### Dependencies
The first time you use the plugin you will need to install the required python dependencies using the `Update/Install dependencies` button in the Dependencies section. You may need to restart the Unreal Editor the first time you install dependencies.

### Models

![androidquinn](https://user-images.githubusercontent.com/795851/197150314-1b2fee89-3670-47ff-a9ab-473243ba544c.gif)


To download a model from [huggingface.co](https://huggingface.co), you will need an account and a token with read permissions. The button next to the token input in the `Models` section will open a browser window that will take you to the token creation page if you are logged in to huggingface.co, or you can visit [this link.](https://huggingface.co/settings/tokens)

You can use any diffusers based model from [the diffusers category on huggingface.co.](https://huggingface.co/models?library=diffusers) To choose a model, enter it in the format `Username/Modelname`. To use the default model, you need to vist the [model card page](https://huggingface.co/CompVis/stable-diffusion-v1-4) and accept the usage agreement in order to download the weights. 

The `revision` property will allow you to pick a specific branch of the model to download. I recommend the `fp16` branch of the default `CompVis/stable-diffusion-v1-4` in case you don't have a limited amount of VRAM (under 6GB). You can also choose the level of precision you want to model to use where 16-bit floating point is the default.

**Note:** For the first release, there may be an issue with downloading git lfs files hosted in models.

### Prompt based image generation

Use the generation section to tweak your prompt, iteration count, viewport influence strength and the seed. If you are new to prompt authoring then I recommend reading [this guide.](https://www.howtogeek.com/833169/how-to-write-an-awesome-stable-diffusion-prompt/)

After you click the `Generate image` button, the in-progress image will display in the plugin window and log its progress in the editor's `Output Log` panel.

### Saving results

The Image outputs section contains options for saving a generated image to either a texture or an external file as well as upsampling options. Enter the destination paths and the name of the image and click the `Save` button for the asset type of your choice, or upsample the output 4x first using Real-ESRGAN.

### Sequencer and exporting animations

https://user-images.githubusercontent.com/795851/198834362-5d6e31eb-9a06-4092-adb0-ee5f8bbf1094.mov

![image](https://user-images.githubusercontent.com/795851/196573891-09b07713-5a29-4bde-8592-f028c28b32f3.png)

The plugin will add two new types of tracks to the Sequencer which can be added using the `+Track` button, a `Stable Diffusion Options` track and `Stable Diffusion Prompt` tracks. 

To create an animation, create a single Options track with a section that will span the length of your animation. You can right-click the section and go to properties to modify parameters that will stay consistent over the course of the animation such as the model options and output frame size. 

The options track has 3 animatable channels, Iterations, Seed and Strength. All of these can be keyframed across the length of your animation.

To add prompts, you can create multiple prompt tracks containing multiple prompt sections. To set the prompt text, right-click on a prompt section, go to properties, and set the prompt text as well as the sentiment. A positive sentiment will tell Stable Diffusion that this prompt is something we would like to see in our generated output, whilst negative sentiments will instruct it to exclude unwanted prompts from the output.

Prompt tracks have a single animatable parameters, `Weight`. Increasing or decreasing this value will increase or decrease the influence of the prompt in your animation.

To render your animation, click the `Render movie` button to open the movie pipeline panel for your sequence. Add a `SDMoviePipelineConfig` config asset to instruct the pipeline to export a Stable Diffusion image sequence. Rendered frames by default will show up in `YourProjectFolder/Saved/MovieRenders`.

**Note:** Currently the Stable Diffusion Movie Pipeline will only export floating point images so I recommend sticking to OpenEXR as the output file type.

Click `Render (local)` to render your stable diffusion animation. If you haven't already initialised a model, then the pipeline will use the model options set in your Options track to initialise a model at the start of the render which may cause a white screen.

## Known issues

* Fix texture memory usage.
* Panning the generated image only works when grabbing it from the upper right quarter.
* You may have to restart the editor after installing dependencies.
* When restarting the editor the may be in a broken state with `Install dependencies` the only option available to select. If this is the case, then close the StableDiffusionTools panel and re-open it.
* No persistence for fields in the editor. These will eventually be stored in a data asset.

## Roadmap

* Add data assets to hold input information like prompt and seed along with the generated textures.
* Add input image masking using layers and stencil buffers.
   
