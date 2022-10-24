#pragma once

#include "CoreMinimal.h"
#include "StableDiffusionGenerationOptions.h"
#include "MovieSceneSection.h"
#include "StableDiffusionGenerationOptions.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "Channels/MovieSceneIntegerChannel.h"
#include "StableDiffusionOptionsSection.generated.h"


UCLASS()
class STABLEDIFFUSIONSEQUENCER_API UStableDiffusionOptionsSection : public UMovieSceneSection
{
	GENERATED_BODY()
	UStableDiffusionOptionsSection(const FObjectInitializer& ObjectInitializer);
public:

	UPROPERTY(EditAnywhere, Category = "StableDiffusion|Sequencer", meta = (Multiline = true, ShowOnlyInnerProperties))
	FStableDiffusionGenerationOptions GenerationOptions;

	UPROPERTY(EditAnywhere, Category = "StableDiffusion|Sequencer", meta = (Multiline = true, ShowOnlyInnerProperties))
	FStableDiffusionModelOptions ModelOptions;

	/**
	 * Public access to this section's internal data function
	 */
	const FMovieSceneFloatChannel& GetStrengthChannel() const { return StrengthCurve; }
	const FMovieSceneIntegerChannel& GetIterationsChannel() const { return IterationsCurve; }
	const FMovieSceneIntegerChannel& GetSeedChannel() const { return SeedCurve; }

protected:

	/** Float data */
	FMovieSceneFloatChannel StrengthCurve;
	FMovieSceneIntegerChannel IterationsCurve;
	FMovieSceneIntegerChannel SeedCurve;
	

private:

	//virtual EMovieSceneChannelProxyType CacheChannelProxy() override;
};
