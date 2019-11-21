#include "Stage.h"
#include "Model.h"

Stage stage(D3DXVECTOR3(-80, -37.5f, -100), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

Stage hew1(D3DXVECTOR3(5, 0, 5), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
Stage hew2(D3DXVECTOR3(2, 0, 2), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage hew3(D3DXVECTOR3(-1, 0, -1), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
Stage hew4(D3DXVECTOR3(-4, 0, -4), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
Stage hew5(D3DXVECTOR3(0 - 7, 0, 0 - 7), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
Stage hew6(D3DXVECTOR3(0 - 10, 0, 0 - 10), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.01f, 0.01f, 0.01f));
Stage hew7(D3DXVECTOR3(0 - 13, 0, 0 - 13), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.1f, 0.1f, 0.1f));

/////////////////////////////////////////////////////////////////////////////////////////
Stage stage1(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage2_1(D3DXVECTOR3(1.0f, 0.0f, 2.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0,1.0,1.0));
Stage stage2_2(D3DXVECTOR3(-1.0f, 0.0f, 2.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f,1.0f,1.0f));
Stage stage3_1(D3DXVECTOR3(2.0f, 0.0f, 4.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage3_2(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage3_3(D3DXVECTOR3(-2.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage4_1(D3DXVECTOR3(4.0f, 0.0f, 6.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage4_2(D3DXVECTOR3(2.0f, 0.0f, 6.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage4_3(D3DXVECTOR3(0.0f, 0.0f, 6.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage4_4(D3DXVECTOR3(-2.0f, 0.0f, 6.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage5(D3DXVECTOR3(8.0f, 0.0f, 8.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage6(D3DXVECTOR3(0.0f, 0.0f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
Stage stage7(D3DXVECTOR3(0.0f, 0.0f, 12.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));



void StageInit()
{
	StageModelInit();
	

	/*コースブロック*/
	/////////////////////////////////////////////////////////////////////
	//hr = D3DXLoadMeshFromX("HEW_Xfile\\Jumppole.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &hew2.g_pMaterialsBuffer, NULL, &hew2.g_MaterialsCount, &hew2.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)hew2.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//hew2.g_pTextureIDs = new int[hew2.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//														/*各マテリアル情報の取得*/
	//for (int i = 0; i < hew2.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		hew2.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Hew_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		hew2.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}

	/////////////////////////////////////////////////////////////////////
	//hr = D3DXLoadMeshFromX("HEW_Xfile\\swimmer.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &hew3.g_pMaterialsBuffer, NULL, &hew3.g_MaterialsCount, &hew3.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)hew3.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//hew3.g_pTextureIDs = new int[hew3.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//														/*各マテリアル情報の取得*/
	//for (int i = 0; i < hew3.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		hew3.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Hew_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		hew3.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}

	/////////////////////////////////////////////////////////
	//hr = D3DXLoadMeshFromX("HEW_Xfile\\swimmer2.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &hew4.g_pMaterialsBuffer, NULL, &hew4.g_MaterialsCount, &hew4.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)hew4.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//hew4.g_pTextureIDs = new int[hew4.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//														/*各マテリアル情報の取得*/
	//for (int i = 0; i < hew4.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		hew4.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Hew_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		hew4.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}

	/////////////////////////////////////////////////////////
	//hr = D3DXLoadMeshFromX("HEW_Xfile\\SyncroSwimmer.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &hew5.g_pMaterialsBuffer, NULL, &hew5.g_MaterialsCount, &hew5.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)hew5.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//hew5.g_pTextureIDs = new int[hew5.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//														/*各マテリアル情報の取得*/
	//for (int i = 0; i < hew5.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		hew5.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Hew_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		hew5.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}


	/////////////////////////////////////////////////////////
	//hr = D3DXLoadMeshFromX("HEW_Xfile\\Wood.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &hew6.g_pMaterialsBuffer, NULL, &hew6.g_MaterialsCount, &hew6.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)hew6.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//hew6.g_pTextureIDs = new int[hew6.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//														/*各マテリアル情報の取得*/
	//for (int i = 0; i < hew6.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		hew6.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Hew_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		hew6.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}


	/////////////////////////////////////////////////////////
	//hr = D3DXLoadMeshFromX("HEW_Xfile\\Wood2.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &hew7.g_pMaterialsBuffer, NULL, &hew7.g_MaterialsCount, &hew7.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)hew7.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//hew7.g_pTextureIDs = new int[hew7.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//														/*各マテリアル情報の取得*/
	//for (int i = 0; i < hew7.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		hew7.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Hew_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		hew7.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}






	////////////////////////////////////////////////////////////////
	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course1.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage1.g_pMaterialsBuffer, NULL, &stage1.g_MaterialsCount, &stage1.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage1.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage1.g_pTextureIDs = new int[stage1.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//														/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage1.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage1.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage1.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}


	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course2_1.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage2_1.g_pMaterialsBuffer, NULL, &stage2_1.g_MaterialsCount, &stage2_1.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage2_1.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage2_1.g_pTextureIDs = new int[stage2_1.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//															/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage2_1.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage2_1.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage2_1.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}


	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course2_2.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage2_2.g_pMaterialsBuffer, NULL, &stage2_2.g_MaterialsCount, &stage2_2.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage2_2.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage2_2.g_pTextureIDs = new int[stage2_2.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//																/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage2_2.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage2_2.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage2_2.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}


	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course3_1.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage3_1.g_pMaterialsBuffer, NULL, &stage3_1.g_MaterialsCount, &stage3_1.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage3_1.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage3_1.g_pTextureIDs = new int[stage3_1.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//																/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage3_1.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage3_1.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage3_1.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}

	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course3_2.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage3_2.g_pMaterialsBuffer, NULL, &stage3_2.g_MaterialsCount, &stage3_2.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage3_2.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage3_2.g_pTextureIDs = new int[stage3_2.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//																/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage3_2.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage3_2.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage3_2.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}

	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course3_3.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage3_3.g_pMaterialsBuffer, NULL, &stage3_3.g_MaterialsCount, &stage3_3.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage3_3.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage3_3.g_pTextureIDs = new int[stage3_3.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//																/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage3_3.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage3_3.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage3_3.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}

	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course4_1.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage4_1.g_pMaterialsBuffer, NULL, &stage4_1.g_MaterialsCount, &stage4_1.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage4_1.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage4_1.g_pTextureIDs = new int[stage4_1.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//																/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage4_1.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage4_1.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage4_1.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}

	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course4_2.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage4_2.g_pMaterialsBuffer, NULL, &stage4_2.g_MaterialsCount, &stage4_2.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage4_2.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage4_2.g_pTextureIDs = new int[stage4_2.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//																/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage4_2.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage4_2.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage4_2.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}

	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course4_3.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage4_3.g_pMaterialsBuffer, NULL, &stage4_3.g_MaterialsCount, &stage4_3.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage4_3.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage4_3.g_pTextureIDs = new int[stage4_3.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//																/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage4_3.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage4_3.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage4_3.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}


	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course4_4.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage4_4.g_pMaterialsBuffer, NULL, &stage4_4.g_MaterialsCount, &stage4_4.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage4_4.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage4_4.g_pTextureIDs = new int[stage4_4.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//																/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage4_4.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage4_4.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage4_4.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}


	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course5.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage5.g_pMaterialsBuffer, NULL, &stage5.g_MaterialsCount, &stage5.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage5.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage5.g_pTextureIDs = new int[stage5.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//																/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage5.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage5.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage5.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}


	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course6.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage6.g_pMaterialsBuffer, NULL, &stage6.g_MaterialsCount, &stage6.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage6.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage6.g_pTextureIDs = new int[stage6.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//															/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage6.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage6.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage6.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}

	//hr = D3DXLoadMeshFromX("Course_Xfile\\Course7.x", D3DXMESH_MANAGED /*|D3DXMESH_32BIT*/, GetDevice(), NULL, &stage7.g_pMaterialsBuffer, NULL, &stage7.g_MaterialsCount, &stage7.g_pMesh);//Exeからの相対パスファイル名(10万近いポリゴン数のモデルを読み込む場合"～32BIT"を入れる),デバイス,null,マテリアルの格納先,NULL,読み込むマテリアルの数,メッシュ

	//if (FAILED(hr))	//メッシュ読み込み失敗
	//{
	//	MessageBox(NULL, "モデルの読み込みに失敗しました。", "警告", MB_OK);
	//}

	//pMtx = (D3DXMATERIAL*)stage7.g_pMaterialsBuffer->GetBufferPointer();	//マテリアル情報を入れる

	//stage7.g_pTextureIDs = new int[stage7.g_MaterialsCount];	//動的にマテリアル数だけメモリを確保する

	//															/*各マテリアル情報の取得*/
	//for (int i = 0; i < stage7.g_MaterialsCount; i++)	//マテリアル数だけループさせる
	//{
	//	/*色彩情報*/
	//	pMtx[i].MatD3D.Diffuse;

	//	/*テクスチャロード*/
	//	if (pMtx[i].pTextureFilename == NULL)	//テクスチャがない
	//	{
	//		/*未格納の処理*/

	//		stage7.g_pTextureIDs[i] = -1;

	//	}
	//	else//テクスチャ格納済み
	//	{
	//		char TexNameBuf[MAX_PATH];	//ファイル名宣言
	//		strcpy(TexNameBuf, "Course_Xfile\\");	//ファイル名に文字列を追加する
	//		strcat(TexNameBuf, pMtx[i].pTextureFilename);//ファイル名の連結
	//		stage7.g_pTextureIDs[i] = Texture_SetLoadFile(TexNameBuf, 0, 0);	//テクスチャ読み込み(ファイル名は加工する必要がある。)

	//	}
	//}


}
void StageUpdate()
{

}
void StageDraw()
{
	StageModelDraw(stage.Position, stage.Scale, stage.Rotate, false);
	/*ModelDraw(hew1.g_pMesh, hew1.Position, hew1.Scale, hew1.Rotate.y, true, hew1.g_MaterialsCount, hew1.g_pTextureIDs);
	ModelDraw(hew2.g_pMesh, hew2.Position, hew2.Scale, hew2.Rotate.y, true, hew2.g_MaterialsCount, hew2.g_pTextureIDs);
	ModelDraw(hew3.g_pMesh, hew3.Position, hew3.Scale, hew3.Rotate.y, true, hew3.g_MaterialsCount, hew3.g_pTextureIDs);
	ModelDraw(hew4.g_pMesh, hew4.Position, hew4.Scale, hew4.Rotate.y, true, hew4.g_MaterialsCount, hew4.g_pTextureIDs);
	ModelDraw(hew5.g_pMesh, hew5.Position, hew5.Scale, hew5.Rotate.y, true, hew5.g_MaterialsCount, hew5.g_pTextureIDs);
	ModelDraw(hew6.g_pMesh, hew6.Position, hew6.Scale, hew6.Rotate.y, true, hew6.g_MaterialsCount, hew6.g_pTextureIDs);
	ModelDraw(hew7.g_pMesh, hew7.Position, hew7.Scale, hew7.Rotate.y, true, hew7.g_MaterialsCount, hew7.g_pTextureIDs);*/

	//ModelDraw(stage1.g_pMesh, stage1.Position, stage1.Scale, stage1.Rotate.y, true, stage1.g_MaterialsCount, stage1.g_pTextureIDs);
	//ModelDraw(stage2_1.g_pMesh, stage2_1.Position, stage2_1.Scale, stage2_1.Rotate.y, true, stage2_1.g_MaterialsCount, stage2_1.g_pTextureIDs);
	//ModelDraw(stage2_2.g_pMesh, stage2_2.Position, stage2_2.Scale, stage2_2.Rotate.y, true, stage2_2.g_MaterialsCount, stage2_2.g_pTextureIDs);
	//ModelDraw(stage3_1.g_pMesh, stage3_1.Position, stage3_1.Scale, stage3_1.Rotate.y, true, stage3_1.g_MaterialsCount, stage3_1.g_pTextureIDs);
	//ModelDraw(stage3_2.g_pMesh, stage3_2.Position, stage3_2.Scale, stage3_2.Rotate.y, true, stage3_2.g_MaterialsCount, stage3_2.g_pTextureIDs);
	//ModelDraw(stage3_3.g_pMesh, stage3_3.Position, stage3_3.Scale, stage3_3.Rotate.y, true, stage3_3.g_MaterialsCount, stage3_3.g_pTextureIDs);
	//ModelDraw(stage4_1.g_pMesh, stage4_1.Position, stage4_1.Scale, stage4_1.Rotate.y, true, stage4_1.g_MaterialsCount, stage4_1.g_pTextureIDs);
	//ModelDraw(stage4_2.g_pMesh, stage4_2.Position, stage4_2.Scale, stage4_2.Rotate.y, true, stage4_2.g_MaterialsCount, stage4_2.g_pTextureIDs);
	//ModelDraw(stage4_3.g_pMesh, stage4_3.Position, stage4_3.Scale, stage4_3.Rotate.y, true, stage4_3.g_MaterialsCount, stage4_3.g_pTextureIDs);
	//ModelDraw(stage4_4.g_pMesh, stage4_4.Position, stage4_4.Scale, stage4_4.Rotate.y, true, stage4_4.g_MaterialsCount, stage4_4.g_pTextureIDs);
	//ModelDraw(stage5.g_pMesh, stage5.Position, stage5.Scale, stage5.Rotate.y, true, stage5.g_MaterialsCount, stage5.g_pTextureIDs);
	//ModelDraw(stage6.g_pMesh, stage6.Position, stage6.Scale, stage6.Rotate.y, true, stage6.g_MaterialsCount, stage6.g_pTextureIDs);
	//ModelDraw(stage7.g_pMesh, stage7.Position, stage7.Scale, stage7.Rotate.y, true, stage7.g_MaterialsCount, stage7.g_pTextureIDs);


}
void StageUnInit()
{

}

