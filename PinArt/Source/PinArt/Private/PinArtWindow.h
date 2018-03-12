#pragma once


class PinArtWindow : public SCompoundWidget
{

	int _Xdimension;
	int _Ydimension;
	int _Zdimension;
	float _cylinderWidth = 10.0f;   // diameter of cylinders

	float _spacing;					// space between cylinders
	float _heightPercent;			// minimum height percentage (use for the random height)

	void XdimensionChanged(int32 value);
	TOptional<int32> GetXdimension() const;

	void YdimensionChanged(int32 value);
	TOptional<int32> GetYdimension() const;

	void ZdimensionChanged(int32 value);
	TOptional<int32> GetZdimension() const;

	void CylinderWidthChanged(float value);
	TOptional<float> GetCylinderWidth() const;

	void HeightPercentChanged(float value);
	TOptional<float> GetHeighPercent() const;

	void SpacingChanged(float value);
	TOptional<float> GetSpacing() const;

	UWorld* GetWorld();

	// cylinder brush
	void CreateBrush(FVector position, float radius, float height);
	// excute on mouseClick (Build button)
	FReply DoBuild();

public:
	PinArtWindow();

	SLATE_BEGIN_ARGS(PinArtWindow)
	{

	}

	SLATE_END_ARGS()

	void Construct(const FArguments& args);
};