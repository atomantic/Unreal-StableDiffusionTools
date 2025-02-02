#pragma once

#include "CoreMinimal.h"
#include "PromptAsset.h"
#include "StableDiffusionGenerationOptions.generated.h"


USTRUCT(BlueprintType)
struct STABLEDIFFUSIONTOOLS_API FStableDiffusionModelOptions
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Model")
		FString Model = "CompVis/stable-diffusion-v1-4";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Model")
		FString Revision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Model")
		FString Precision = "fp16";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Model")
		FString CustomPipeline = "lpw_stable_diffusion";

	/* 
	Padding mode to use for image 2D convulution. Valid options are 'zeros', 'reflect', 'replicate' or 'circular'. 
	See https://pytorch.org/docs/stable/generated/torch.nn.Conv2d.html
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Model")
		FString PaddingMode = "zeros";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Model")
		bool AllowNSFW = false;

	FORCEINLINE bool operator==(const FStableDiffusionModelOptions& Other)
	{
		return Model.Equals(Other.Model) && Revision.Equals(Other.Revision) && Precision.Equals(Other.Precision);
	}

	FORCEINLINE bool operator!=(const FStableDiffusionModelOptions& Other)
	{
		return !Model.Equals(Other.Model) || !Revision.Equals(Other.Revision) || !Precision.Equals(Other.Precision);
	}
};


USTRUCT(BlueprintType)
struct STABLEDIFFUSIONTOOLS_API FStableDiffusionGenerationOptions
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	float Strength = 0.75;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	float GuidanceScale = 7.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	int32 Iterations = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	int32 Seed = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	int32 InSizeX = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	int32 InSizeY = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	int32 OutSizeX = 512;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	int32 OutSizeY = 512;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	TArray<FPrompt> PositivePrompts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	TArray<FPrompt> NegativePrompts;

	void AddPrompt(const FPrompt Prompt){
		if (Prompt.Sentiment == EPromptSentiment::Negative) {
			NegativePrompts.Add(Prompt);
			return;
		}
		PositivePrompts.Add(Prompt);
	}
};


USTRUCT(BlueprintType)
struct STABLEDIFFUSIONTOOLS_API FStableDiffusionInput
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	FStableDiffusionGenerationOptions Options;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	TArray<FColor> InputImagePixels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stable Diffusion|Generation")
	TArray<FColor> MaskImagePixels;
};
