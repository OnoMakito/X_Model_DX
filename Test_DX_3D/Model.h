#pragma once
#include "common.h"
#include "MyDirect3D.h"
#include "MyTex.h"



void PlayerModelInit(void);
void HorseModelInit(void);
void StageModelInit(void);

//void ModelInit(const char* FileName, const char* AddFileName, LPD3DXMESH* Mesh, LPD3DXBUFFER* MaterialBuffer, LPVOID MaterialBufferPointer, DWORD* MaterialCount, int* TexID);
void ModelUpdate(void);
void PlayerModelDraw( D3DXVECTOR3 Position, D3DXVECTOR3 Scaling,const D3DXVECTOR3 Rotate, bool Lighting);
void HorseModelDraw( D3DXVECTOR3 Position, D3DXVECTOR3 Scaling,const D3DXVECTOR3 Rotate, bool Lighting);
void StageModelDraw( D3DXVECTOR3 Position, D3DXVECTOR3 Scaling,const D3DXVECTOR3 Rotate, bool Lighting);

void ModelUnInit(void);


class PlayerModel
{
public:
	static LPD3DXMESH Mesh;
	static DWORD MaterialCount;
	static LPD3DXBUFFER MaterialBuffer;
	static int* TextureIDs;
	static D3DMATERIAL9 Material;
};

class HorseModel
{
public:
	static LPD3DXMESH Mesh;
	static DWORD MaterialCount;
	static LPD3DXBUFFER MaterialBuffer;
	static int* TextureIDs;
	static D3DMATERIAL9 Material;
};

class StageModel
{
public:
	static LPD3DXMESH Mesh;
	static DWORD MaterialCount;
	static LPD3DXBUFFER MaterialBuffer;
	static int* TextureIDs;
	static D3DMATERIAL9 Material;
};
