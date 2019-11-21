#include "Model.h"
#include "Player.h"
#include "Stage.h"

/*プレイヤーのモデル情報*/
LPD3DXMESH PlayerModel::Mesh;
DWORD PlayerModel::MaterialCount;
LPD3DXBUFFER PlayerModel::MaterialBuffer;
int* PlayerModel::TextureIDs;
D3DMATERIAL9 PlayerModel::Material;

/*馬車のモデル情報*/
LPD3DXMESH HorseModel::Mesh;
DWORD HorseModel::MaterialCount;
LPD3DXBUFFER HorseModel::MaterialBuffer;
int* HorseModel::TextureIDs;
D3DMATERIAL9 HorseModel::Material;

/*ステージのモデル情報*/
LPD3DXMESH StageModel::Mesh;
DWORD StageModel::MaterialCount;
LPD3DXBUFFER StageModel::MaterialBuffer;
int* StageModel::TextureIDs;
D3DMATERIAL9 StageModel::Material;



void PlayerModelInit()
{
	PlayerModel::Material.Diffuse = { 255,255,255,255 };	//マテリアル初期化

	HRESULT hr = D3DXLoadMeshFromX("gradriel\\gradriel.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &PlayerModel::MaterialBuffer, NULL, &PlayerModel::MaterialCount, &PlayerModel::Mesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	if (FAILED(hr))	//メッシュ読み込み失敗
	{
		MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	}

	/////////////////////////////////////////////////剣士
	/*メッシュの読み込み*/

	D3DXMATERIAL* pMtx = (D3DXMATERIAL*)PlayerModel::MaterialBuffer->GetBufferPointer();	//マテリアル情報を入れる

	PlayerModel::TextureIDs = new int[PlayerModel::MaterialCount];	//動的にマテリアル数だけメモリを確保する

																/*各マテリアル情報の取得*/
	for (int i = 0; i < PlayerModel::MaterialCount; i++)	//マテリアル数だけループさせる
	{
		/*色彩情報*/
		pMtx[i].MatD3D.Diffuse;

		/*テクスチャロード*/
		if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
		{
			/*未格納の処理*/

			PlayerModel::TextureIDs [i] = -1;

		}
		else//テクスチャ格納済み
		{
			char TexNameBuf[MAX_PATH];	//ファイル名宣言
			strcpy(TexNameBuf, MODEL_FILE_PATH);	//ファイル名に文字列を追加する
			strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
			PlayerModel::TextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

		}
	}


}

void HorseModelInit(void)
{
	/*馬*/
	HRESULT hr = D3DXLoadMeshFromX("cart\\cart.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &HorseModel::MaterialBuffer, NULL, &HorseModel::MaterialCount, &HorseModel::Mesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	if (FAILED(hr))	//メッシュ読み込み失敗
	{
		MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	}

	D3DXMATERIAL* pMtx = (D3DXMATERIAL*)HorseModel::MaterialBuffer->GetBufferPointer();	//マテリアル情報を入れる

	HorseModel::TextureIDs= new int[HorseModel::MaterialCount];	//動的にマテリアル数だけメモリを確保する

															/*各マテリアル情報の取得*/
	for (int i = 0; i < HorseModel::MaterialCount; i++)	//マテリアル数だけループさせる
	{
		/*色彩情報*/
		pMtx[i].MatD3D.Diffuse;

		/*テクスチャロード*/
		if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
		{
			/*未格納の処理*/

			HorseModel::TextureIDs[i] = -1;

		}
		else//テクスチャ格納済み
		{
			char TexNameBuf[MAX_PATH];	//ファイル名宣言
			strcpy(TexNameBuf, MODEL_FILE_UMA_PATH);	//ファイル名に文字列を追加する
			strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
			HorseModel::TextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

		}
	}
}


void StageModelInit(void)
{
	HRESULT hr = D3DXLoadMeshFromX("Stage\\West_Block24.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &StageModel::MaterialBuffer, NULL, &StageModel::MaterialCount, &StageModel::Mesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	if (FAILED(hr))	//メッシュ読み込み失敗
	{
		MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	}

	D3DXMATERIAL* pMtx = (D3DXMATERIAL*)StageModel::MaterialBuffer->GetBufferPointer();	//マテリアル情報を入れる

	StageModel::TextureIDs = new int[StageModel::MaterialCount];	//動的にマテリアル数だけメモリを確保する

															/*各マテリアル情報の取得*/
	for (int i = 0; i < StageModel::MaterialCount; i++)	//マテリアル数だけループさせる
	{
		/*色彩情報*/
		pMtx[i].MatD3D.Diffuse;

		/*テクスチャロード*/
		if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
		{
			/*未格納の処理*/

			StageModel::TextureIDs[i] = -1;

		}
		else//テクスチャ格納済み
		{
			char TexNameBuf[MAX_PATH];	//ファイル名宣言
			strcpy(TexNameBuf, MODEL_STAGE_PATH);	//ファイル名に文字列を追加する
			strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
			StageModel::TextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

		}
	}


}
//
//void ModelInit(const char* FileName,const char* AddFileName, LPD3DXMESH* Mesh, LPD3DXBUFFER* MaterialBuffer,LPVOID MaterialBufferPointer, DWORD* MaterialCount, int* TexID)
//{
//
//	/////////////////////////////////////////////////剣士
//	/*メッシュの読み込み*/
//	HRESULT hr = D3DXLoadMeshFromX(FileName, D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, MaterialBuffer, NULL, MaterialCount, Mesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ
//
//	if (FAILED(hr))	//メッシュ読み込み失敗
//	{
//		MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
//	}
//
//	D3DXMATERIAL* pMtx = (D3DXMATERIAL*)MaterialBufferPointer;	//マテリアル情報を入れる
//
//	TexID = new int[*MaterialCount];	//動的にマテリアル数だけメモリを確保する
//
//										/*各マテリアル情報の取得*/
//	for (int i = 0; i < *MaterialCount; i++)	//マテリアル数だけループさせる
//	{
//		/*色彩情報*/
//		pMtx[i].MatD3D.Diffuse;
//
//		/*テクスチャロード*/
//		if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
//		{
//			/*未格納の処理*/
//
//			TexID[i] = -1;
//
//		}
//		else//テクスチャ格納済み
//		{
//			char TexNameBuf[MAX_PATH];	//ファイル名宣言
//			strcpy(TexNameBuf, AddFileName);	//ファイル名に文字列を追加する
//			strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
//			TexID[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)
//
//		}
//	}
//
//
//
//
//
//}



void ModelUpdate()
{

}


void PlayerModelDraw(D3DXVECTOR3 Position, D3DXVECTOR3 Scaling, const D3DXVECTOR3 Rotate, bool Lighting)
{
	/*行列設定*/
	D3DXMATRIX mtxWorld, mtxScaling,mtxTranslation, mtxRotationX,mtxRotationY, mtxRotationZ;//ワールド変換行列・回転行列・平行移動行列

	D3DXMatrixIdentity(&mtxWorld);	//行列の単位化	(*1)
	D3DXMatrixTranslation(&mtxTranslation, Position.x, Position.y, Position.z);//ワールド座標を更新
	D3DXMatrixScaling(&mtxScaling, Scaling.x, Scaling.x, Scaling.z);	//拡大縮小行列
	D3DXMatrixRotationX(&mtxRotationX, Rotate.x);	//x軸回転
	D3DXMatrixRotationY(&mtxRotationY, Rotate.y);	//y軸回転
	D3DXMatrixRotationZ(&mtxRotationZ, Rotate.z);	//z軸回転
	//D3DXMatrixRotationQuaternion(&mtxRotation, );



	mtxWorld = mtxRotationX* mtxRotationY*mtxRotationZ *mtxScaling* mtxTranslation;	//合成の順番に注意

	GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映



													  /*ライティング設定(光の影響を受けるかどうか)*/
	GetDevice()->SetRenderState(D3DRS_LIGHTING, Lighting);	//Value値をtrueにすることでライティングを行う



	//新規マテリアル宣言、初期化


	GetDevice()->SetMaterial(&PlayerModel::Material);	//マテリアルセット

									/*モデルを読み込む際は第二引数をD3DMCS_MATERIALにする。(頂点カラーが存在するものにはD3DMCS_COLOR1にする)*/
	GetDevice()->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_MATERIAL);



	for (DWORD i = 0; i < PlayerModel::MaterialCount; i++)	//マテリアル数描画を行う(メッシュはマテリアルで分割されていることが多い) 
	{
		/*マテリアルの設定*/

		if (PlayerModel::TextureIDs[i] < 0)//テクスチャがないがない場合-1が入る
		{
			/*マテリアルのみでの設定*/

		}
		else
		{
			/*マテリアルカラーを白にしてテクスチャを設定*/
			GetDevice()->SetTexture(0, Texture_GetTexture(PlayerModel::TextureIDs[i]));	//テクスチャのIDを指定して張り付ける
		}

		/*メッシュ描画*/
		PlayerModel::Mesh->DrawSubset(i);
	}

}

void HorseModelDraw(D3DXVECTOR3 Position, D3DXVECTOR3 Scaling, const D3DXVECTOR3 Rotate, bool Lighting)
{
	/*行列設定*/
	D3DXMATRIX mtxWorld, mtxScaling, mtxTranslation, mtxRotationX, mtxRotationY, mtxRotationZ;//ワールド変換行列・回転行列・平行移動行列

	D3DXMatrixIdentity(&mtxWorld);	//行列の単位化	(*1)
	D3DXMatrixTranslation(&mtxTranslation, Position.x, Position.y, Position.z);//ワールド座標を更新
	D3DXMatrixScaling(&mtxScaling, Scaling.x, Scaling.x, Scaling.z);	//拡大縮小行列
	D3DXMatrixRotationX(&mtxRotationX, Rotate.x);	//x軸回転
	D3DXMatrixRotationY(&mtxRotationY, Rotate.y);	//y軸回転
	D3DXMatrixRotationZ(&mtxRotationZ, Rotate.z);	//z軸回転
													//D3DXMatrixRotationQuaternion(&mtxRotation, );



	mtxWorld = mtxRotationX * mtxRotationY*mtxRotationZ *mtxScaling* mtxTranslation;	//合成の順番に注意

	GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映



													  /*ライティング設定(光の影響を受けるかどうか)*/
	GetDevice()->SetRenderState(D3DRS_LIGHTING, Lighting);	//Value値をtrueにすることでライティングを行う



															//新規マテリアル宣言、初期化


	GetDevice()->SetMaterial(&HorseModel::Material);	//マテリアルセット

														/*モデルを読み込む際は第二引数をD3DMCS_MATERIALにする。(頂点カラーが存在するものにはD3DMCS_COLOR1にする)*/
	GetDevice()->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_MATERIAL);



	for (DWORD i = 0; i < HorseModel::MaterialCount; i++)	//マテリアル数描画を行う(メッシュはマテリアルで分割されていることが多い) 
	{
		/*マテリアルの設定*/

		if (HorseModel::TextureIDs[i] < 0)//テクスチャがないがない場合-1が入る
		{
			/*マテリアルのみでの設定*/

		}
		else
		{
			/*マテリアルカラーを白にしてテクスチャを設定*/
			GetDevice()->SetTexture(0, Texture_GetTexture(HorseModel::TextureIDs[i]));	//テクスチャのIDを指定して張り付ける
		}

		/*メッシュ描画*/
		HorseModel::Mesh->DrawSubset(i);
	}
}

void StageModelDraw(D3DXVECTOR3 Position, D3DXVECTOR3 Scaling, const D3DXVECTOR3 Rotate, bool Lighting)
{
	/*行列設定*/
	D3DXMATRIX mtxWorld, mtxScaling, mtxTranslation, mtxRotationX, mtxRotationY, mtxRotationZ;//ワールド変換行列・回転行列・平行移動行列

	D3DXMatrixIdentity(&mtxWorld);	//行列の単位化	(*1)
	D3DXMatrixTranslation(&mtxTranslation, Position.x, Position.y, Position.z);//ワールド座標を更新
	D3DXMatrixScaling(&mtxScaling, Scaling.x, Scaling.x, Scaling.z);	//拡大縮小行列
	D3DXMatrixRotationX(&mtxRotationX, Rotate.x);	//x軸回転
	D3DXMatrixRotationY(&mtxRotationY, Rotate.y);	//y軸回転
	D3DXMatrixRotationZ(&mtxRotationZ, Rotate.z);	//z軸回転
													//D3DXMatrixRotationQuaternion(&mtxRotation, );



	mtxWorld = mtxRotationX * mtxRotationY*mtxRotationZ *mtxScaling* mtxTranslation;	//合成の順番に注意

	GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映



													  /*ライティング設定(光の影響を受けるかどうか)*/
	GetDevice()->SetRenderState(D3DRS_LIGHTING, Lighting);	//Value値をtrueにすることでライティングを行う



															//新規マテリアル宣言、初期化


	GetDevice()->SetMaterial(&StageModel::Material);	//マテリアルセット

														/*モデルを読み込む際は第二引数をD3DMCS_MATERIALにする。(頂点カラーが存在するものにはD3DMCS_COLOR1にする)*/
	GetDevice()->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_MATERIAL);



	for (DWORD i = 0; i < StageModel::MaterialCount; i++)	//マテリアル数描画を行う(メッシュはマテリアルで分割されていることが多い) 
	{
		/*マテリアルの設定*/

		if (StageModel::TextureIDs[i] < 0)//テクスチャがないがない場合-1が入る
		{
			/*マテリアルのみでの設定*/

		}
		else
		{
			/*マテリアルカラーを白にしてテクスチャを設定*/
			GetDevice()->SetTexture(0, Texture_GetTexture(StageModel::TextureIDs[i]));	//テクスチャのIDを指定して張り付ける
		}

		/*メッシュ描画*/
		StageModel::Mesh->DrawSubset(i);
	}
}




void ModelUnInit()
{
}

