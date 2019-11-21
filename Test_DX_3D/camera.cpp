


#include "MyDirect3D.h"
#include "camera.h"
#include "Cube.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "input.h"


/*デバッグ用カメラ*//////////////////////////////////////////////////////
static D3DXVECTOR3 g_VecFront;	//前方向ベクトル
static D3DXVECTOR3 g_VecRight;	//右方向ベクトル
static D3DXVECTOR3 g_VecUp(0.0f, 0.0f, 0.0f);	//上方向ベクトル

static float g_MoveSpeed=0.0f;	//移動速度
static float g_RotationSpeed=0.0f;	//移動速度
static D3DXVECTOR3 g_Position(0.0f,1.0f,-8.0f);	//座標

static float g_Fov = 0.0f;	//画角
/////////////////////////////////////////////////////////////////////////



void CameraInit()
{
	/*前ベクトルと上ベクトルが垂直になるようにする*/
	g_VecFront = D3DXVECTOR3(0.0f, 0.0f, 1.0f);	//前方向
	g_VecRight = D3DXVECTOR3(1.0f, 0.0f, 0.0f);	//右方向

	D3DXVec3Normalize(&g_VecFront, &g_VecFront);	//単位化する
	D3DXVec3Cross(&g_VecUp, &g_VecFront, &g_VecRight);	//外積を使って前方向ベクトルと右方向ベクトルの両方に対して垂直なベクトルを求める(上方向)...第二引数と第三引数の順番に気を付ける(ミスるとマイナスの値になる) 
	D3DXVec3Normalize(&g_VecUp, &g_VecUp);	//単位化
	
	g_MoveSpeed = 0.08f;	//スピード

	g_RotationSpeed = 0.01f;	//回転速度
	g_Fov = 1.0f;	//画角(1ラジアン約60度)

}


void CameraUpdate()
{

	/*移動*/
	D3DXVECTOR3 vecDir(0.0f,0.0f,0.0f);
	if (Keyboard_IsPress(DIK_LSHIFT) || Keyboard_IsPress(DIK_RSHIFT))
	{
		if (Keyboard_IsPress(DIK_W))
		{
			vecDir+=g_VecUp;	//上昇
		}

		if (Keyboard_IsPress(DIK_S))
		{
			vecDir-=g_VecUp;	//下降
		}
	}
	else
	{
		if (Keyboard_IsPress(DIK_W))
		{
			vecDir += g_VecFront;

		}
		if (Keyboard_IsPress(DIK_A))
		{
			vecDir -= g_VecRight;

		}
		if (Keyboard_IsPress(DIK_D))
		{
			vecDir += g_VecRight;

		}
		if (Keyboard_IsPress(DIK_S))
		{
			vecDir -= g_VecFront;

		}
	}
	D3DXVec3Normalize(&vecDir, &vecDir);	//単位化(同時押ししても変に加速しないようにする)
	g_Position += g_MoveSpeed * vecDir;	//座標を変更






	/*回転*/

	D3DXMATRIX mtxRotation;
	D3DXVECTOR3 At_Point = g_Position + g_VecFront*5;	//注視点


	
	 if (Keyboard_IsPress(DIK_LCONTROL) || Keyboard_IsPress(DIK_RCONTROL))	//中心点を軸とした回転(未完成)
	{
		if (Keyboard_IsPress(DIK_RIGHTARROW))	//右回転
		{
			D3DXMatrixRotationY(&mtxRotation, g_RotationSpeed);
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//Wの値を0にする⇒平行移動の影響を受けない
			D3DXVec3TransformNormal(&g_VecRight, &g_VecRight, &mtxRotation);
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

			g_Position=At_Point - g_VecFront * 5;	//回転後に自分が移動する座標を求める(注視点を求める式を逆算する)

			//D3DXVec3TransformCoord()	//Wの値を1にする⇒平行移動の影響を受ける(今回は回転だけするためこっちを使っても結果的には変わらない。)
		}
		if (Keyboard_IsPress(DIK_LEFTARROW))	//左回転
		{
			D3DXMatrixRotationY(&mtxRotation, -g_RotationSpeed);
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//Wの値を0にする⇒平行移動の影響を受けない
			D3DXVec3TransformNormal(&g_VecRight, &g_VecRight, &mtxRotation);
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);
			
			g_Position = At_Point - g_VecFront * 5;//回転後に自分が移動する座標を求める(注視点を求める式を逆算する)

			//D3DXVec3TransformCoord()	//Wの値を1にする⇒平行移動の影響を受ける(今回は回転だけするためこっちを使っても結果的には変わらない。)
		}
	}
	else//座標軸回転
	{
		if (Keyboard_IsPress(DIK_RIGHTARROW))	//右回転
		{
			D3DXMatrixRotationY(&mtxRotation, g_RotationSpeed);
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//Wの値を0にする⇒平行移動の影響を受けない
			D3DXVec3TransformNormal(&g_VecRight, &g_VecRight, &mtxRotation);
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

		}
		if (Keyboard_IsPress(DIK_LEFTARROW))	//左回転
		{

			D3DXMatrixRotationY(&mtxRotation, -g_RotationSpeed);
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//Wの値を0にする⇒平行移動の影響を受けない
			D3DXVec3TransformNormal(&g_VecRight, &g_VecRight, &mtxRotation);
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

		}
		if (Keyboard_IsPress(DIK_UPARROW))	//上回転
		{
			D3DXMatrixRotationAxis(&mtxRotation, &g_VecRight, -g_RotationSpeed);	//VecUpを軸に右回転
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//Wの値を0にする⇒平行移動の影響を受けない
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

		}
		if (Keyboard_IsPress(DIK_DOWNARROW))	//下回転
		{
			D3DXMatrixRotationAxis(&mtxRotation, &g_VecRight, g_RotationSpeed);	//VecUpを軸に右回転
			D3DXVec3TransformNormal(&g_VecFront, &g_VecFront, &mtxRotation);	//Wの値を0にする⇒平行移動の影響を受けない
			D3DXVec3TransformNormal(&g_VecUp, &g_VecUp, &mtxRotation);

		}
	}

	

	if (Keyboard_IsPress(DIK_R) && Keyboard_IsPress(DIK_LSHIFT) && Keyboard_IsPress(DIK_LCONTROL))	//リセット
	{
		g_Position=D3DXVECTOR3(0.0f, 1.0f, -8.0f);	//座標
		g_VecFront = D3DXVECTOR3(0.0f, 0.0f, 1.0f);	//前方向
		g_VecRight = D3DXVECTOR3(1.0f, 0.0f, 0.0f);	//右方向

		D3DXVec3Normalize(&g_VecFront, &g_VecFront);	//単位化する
		D3DXVec3Cross(&g_VecUp, &g_VecFront, &g_VecRight);	//外積を使って前方向ベクトルと右方向ベクトルの両方に対して垂直なベクトルを求める(上方向)...第二引数と第三引数の順番に気を付ける(ミスるとマイナスの値になる) 
		D3DXVec3Normalize(&g_VecUp, &g_VecUp);	//単位化
	}


	D3DXVec3Normalize(&g_VecFront, &g_VecFront);	//誤差の発生をなくすために単位化
	D3DXVec3Normalize(&g_VecRight, &g_VecRight);
	D3DXVec3Normalize(&g_VecUp, &g_VecUp);


}


void CameraDraw()
{

	/*ビュー変換行列*/
	D3DXMATRIX mtxView;
	D3DXVECTOR3 camera_eye=g_Position;	//カメラの座標
	D3DXVECTOR3 camera_at=g_Position+g_VecFront;	//カメラが見ている先(注視点)
	D3DXVECTOR3 camera_up=g_VecUp;	//カメラの上方向ベクトルを設定

	D3DXMatrixLookAtLH(&mtxView, &camera_eye, &camera_at, &camera_up);	//カメラに移るように世界を動かす行列

	GetDevice()->SetTransform(D3DTS_VIEW, &mtxView);	//ビュー変換行列を反映


													/*プロジェクション変換(パースペクティヴ)*/
	D3DXMATRIX mtxProjection;
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(30),//画角の半分
		(float)SCREEN_WIDTH / SCREEN_HEIGHT,//アス比 小数になるためFloatでキャストする
		0.1f,	//near	//0よりも大きく
		1000.0f//far
	);


	GetDevice()->SetTransform(D3DTS_PROJECTION, &mtxProjection);//パースペクティブ変換行列を反映

}
void CameraUnInit()
{

}


