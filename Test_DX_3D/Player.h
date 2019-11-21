#pragma once


#define MODEL_FILE_PATH ("gradriel\\")

#define MODEL_FILE_UMA_PATH ("cart\\")


void Player_Init(void);	//初期座標・テクスチャの準備

void Player_Update(void);	//キー入力で移動・

void Player_Draw(void);	//プレイヤーの状態を監視して描画(生存・死亡・爆発など)

void Player_Uninit(void);	//テクスチャ解放(シーン終了時に開放するなら、ここに書く必要はない。)



class Gradriel
{
public:

	D3DXVECTOR3 Position;	//ワールド座標格納変数
	D3DXVECTOR3 Rotate;	//回転
	D3DXVECTOR3 Scale;

	Gradriel(D3DXVECTOR3 position, D3DXVECTOR3 rotate,D3DXVECTOR3 scale)
	{
		Position = position;
		Rotate = rotate;
		Scale = scale;
	}

};




class Cart
{
public:
	LPD3DXMESH g_pMesh = NULL;
	DWORD g_MaterialsCount = 0;	//マテリアルナンバー(マテリアル格納番号)
	LPD3DXBUFFER g_pMaterialsBuffer = NULL;	//マテリアル情報の格納先(MaterialCountの数のマテリアルが入ってる)

	int* g_pTextureIDs = NULL;	//テクスチャ管理番号格納変数

	D3DMATERIAL9 mat = {};

	D3DXVECTOR3 Position;	//ワールド座標格納変数
	D3DXVECTOR3 Rotate;	//回転
	D3DXVECTOR3 Scale;

	Cart(D3DXVECTOR3 position, D3DXVECTOR3 rotate, D3DXVECTOR3 scale)
	{
		Position = position;
		Rotate = rotate;
		Scale = scale;

		/*ディフューズ値*/
		mat.Diffuse.r = 255;
		mat.Diffuse.g = 255;
		mat.Diffuse.b = 255;
		mat.Diffuse.a = 255;
		/*アンビエント値*/
		mat.Ambient.r = 255;
		mat.Ambient.g = 255;
		mat.Ambient.b = 255;
		mat.Ambient.a = 255;

	}

};




