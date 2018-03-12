
#include "PinArtWindow.h"
#include "PinArt.h"

#define LOCTEXT_NAMESPACE "PinArtWindow"

PinArtWindow::PinArtWindow() :
	_Xdimension(1),
	_Ydimension(1),
	_Zdimension(1),
	_cylinderWidth(5),
	_heightPercent(50),
	_spacing(1)
{

}

void PinArtWindow::Construct(const FArguments& args)
{

	// generate slate interface
	TSharedRef<SVerticalBox> vertBox = SNew(SVerticalBox);

	ChildSlot
		[
			vertBox
		];
	
	vertBox->AddSlot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(LOCTEXT("XName", "X Dimension"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(SNumericEntryBox<int32>)
				.AllowSpin(true)
				.MinValue(1).MaxValue(100)
				.MinSliderValue(1).MaxSliderValue(100)
				.Value(this, &PinArtWindow::GetXdimension)
				.OnValueChanged(this, &PinArtWindow::XdimensionChanged)
			]
		];

	vertBox->AddSlot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(LOCTEXT("YName", "Y Dimension"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(SNumericEntryBox<int32>)
				.AllowSpin(true)
				.MinValue(1).MinSliderValue(1)
				.MaxValue(100).MaxSliderValue(100)			
				.Value(this, &PinArtWindow::GetYdimension)
				.OnValueChanged(this, &PinArtWindow::YdimensionChanged)
			]
		];

	vertBox->AddSlot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock).Text(LOCTEXT("ZName", "Z Dimension"))
		]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(SNumericEntryBox<int32>)
			.AllowSpin(true)
			.MinValue(1).MinSliderValue(1)
			.MaxValue(100).MaxSliderValue(100)
			.Value(this, &PinArtWindow::GetZdimension)
			.OnValueChanged(this, &PinArtWindow::ZdimensionChanged)
		]
		];

	vertBox->AddSlot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock).Text(LOCTEXT("CylinderName", "Cylinder Radius"))
		]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(SNumericEntryBox<float>)
			.AllowSpin(true)
			.MinValue(0).MinSliderValue(0)
			.MaxValue(100).MaxSliderValue(100)
			.Value(this, &PinArtWindow::GetCylinderWidth)
			.OnValueChanged(this, &PinArtWindow::CylinderWidthChanged)
		]
		];

	vertBox->AddSlot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(LOCTEXT("HeightPercentName", "Height Percent"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(SNumericEntryBox<float>)
				.AllowSpin(true)
				.MinValue(0).MinSliderValue(0)
				.MaxValue(100).MaxSliderValue(100)
				.Value(this, &PinArtWindow::GetHeighPercent)
				.OnValueChanged(this, &PinArtWindow::HeightPercentChanged)
			]
		];

	

	vertBox->AddSlot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(LOCTEXT("SpacingName", "Spacing"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(SNumericEntryBox<float>)
				.AllowSpin(true)
				.MinValue(0).MinSliderValue(0)
				.MaxValue(20).MaxSliderValue(20)
				.Value(this, &PinArtWindow::GetSpacing)
				.OnValueChanged(this, &PinArtWindow::SpacingChanged)
			]
		];
	
	vertBox->AddSlot()
	.AutoHeight()
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Build")))
			.OnClicked(this, &PinArtWindow::DoBuild)
		]
	]; 
}

void PinArtWindow::XdimensionChanged(int32 value) {
	_Xdimension = value;
}

TOptional<int32> PinArtWindow::GetXdimension() const {
	return _Xdimension;
}

void PinArtWindow::YdimensionChanged(int32 value) {
	_Ydimension = value;
}

TOptional<int32> PinArtWindow::GetYdimension() const {
	return _Ydimension;
}

void PinArtWindow::ZdimensionChanged(int32 value) {
	_Zdimension = value;
}

TOptional<int32> PinArtWindow::GetZdimension() const {
	return _Zdimension;
}

void PinArtWindow::HeightPercentChanged(float value) {
	_heightPercent = value;
}

TOptional<float> PinArtWindow::GetHeighPercent() const {
	return _heightPercent;
}

void PinArtWindow::CylinderWidthChanged(float value) {
	_cylinderWidth = value;
}

TOptional<float> PinArtWindow::GetCylinderWidth() const {
	return _cylinderWidth;
;
}

void PinArtWindow::SpacingChanged(float value) {
	_spacing = value;
}

TOptional<float> PinArtWindow::GetSpacing() const {
	return _spacing;
}

UWorld* PinArtWindow::GetWorld() {
	UWorld* world = NULL;
	const TIndirectArray<FWorldContext>& context = GEngine->GetWorldContexts();
	for (int32 i = 0; i < context.Num(); ++i) {
		if (context[i].WorldType == EWorldType::PIE)
			return context[i].World();

		if (context[i].WorldType == EWorldType::Editor)
			world = context[i].World(); 
	}

	return world;
}

void PinArtWindow::CreateBrush(FVector position, float radius, float height) {
	UWorld* world = GetWorld();

	UCylinderBuilder* cylinderBuilder = Cast<UCylinderBuilder>(GEditor->FindBrushBuilder(UCylinderBuilder::StaticClass()));
	cylinderBuilder->OuterRadius = radius;
	cylinderBuilder->Z = height;
	cylinderBuilder->Build(world);
	
	world->GetDefaultBrush()->SetActorLocation(position);
	GEditor->RedrawLevelEditingViewports();
	GEditor->Exec(world, TEXT("Brush Add"));
}

FReply PinArtWindow::DoBuild() {

	FVector position, size;
	position = FVector(0, 0, 0);
	size = FVector(_Xdimension, _Ydimension, _Zdimension);

	// create a box actor for putting in cylinders
	UWorld* world = GetWorld();
	AActor* boundingBox = world->SpawnActor(ATriggerBox::StaticClass());
	boundingBox->EditorApplyScale(size, &position, false, false, false);
	
	FVector boundsSize = boundingBox->GetComponentsBoundingBox().GetExtent();
	FVector boundsMin = position - boundsSize / 2;
	
	// calculate cylinder amount according to the diameter of cylinder
	int xNumber = boundsSize.X / (_cylinderWidth + _spacing);
	int yNumber = boundsSize.Y / (_cylinderWidth + _spacing);

	for (int x = 0; x < xNumber; ++x) {
		for (int y = 0; y < yNumber; ++y) {
			position.X = boundsMin.X + (_cylinderWidth * x) + _spacing * x + _spacing;
			position.Y = boundsMin.Y + (_cylinderWidth * y) + _spacing * y + _spacing;
			position.Z = boundsMin.Z;

			// randomize height of cylinder
			float height = FMath::FRandRange(_heightPercent * boundsSize.Z / 100.0f, boundsSize.Z);

			CreateBrush(position, _cylinderWidth / 2, height);
		}
	}
	return FReply::Handled();
}
