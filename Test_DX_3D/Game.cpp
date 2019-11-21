#include "input.h"
#include "Cube.h"
#include "grid.h"
#include "camera.h"
#include "Light.h"
#include "Model.h"
#include "Player.h"
#include "Stage.h"


void GameInit()
{
	CameraInit();
	GridInit();
	Player_Init();
	StageInit();
	CubeInit();
	LightInit();

}


void GameUpdate()
{
	CameraUpdate();

	GridUpdate();

	Keyboard_Update();
	ModelUpdate();
	CubeUpdate();
}

void GameDraw()
{
	GridDraw();
	CameraDraw();
	StageDraw();
	Player_Draw();
	//CubeDraw();
}


void GameUninit()
{
	CubeUnInit();
	ModelUnInit();
}




