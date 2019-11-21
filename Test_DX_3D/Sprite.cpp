

#include <d3d9.h>

//�I�[�o���[�h�ɂ��`��ύX�L

#include <d3dx9.h>
#include "Sprite.h"
#include "common.h"
#include "MyDirect3D.h"
#include "MyTex.h"
#include "debug_font.h"

static LPDIRECT3DDEVICE9 g_pDevice = NULL;
LPDIRECT3DINDEXBUFFER9 g_pIndexBuffer = NULL;
static D3DCOLOR g_color = D3DCOLOR_RGBA(255, 255, 255, 255);

static int tex;

LPDIRECT3DVERTEXBUFFER9 g_pVertexBuffer=NULL;



void Sprite_Init()
{
	g_pDevice = GetDevice();

	g_pDevice->CreateVertexBuffer(sizeof(vertex1) * 4,	//�l���_���̃f�[�^��ǂݍ��ނ��Ƃ��\�ɂ���
		D3DUSAGE_WRITEONLY,	//WRITEONLY:�ǂݍ��ݕs��
		FVF_VERTEX2D,
		D3DPOOL_MANAGED,	//�f�o�C�X�j�󂪔��������ۂɃ_�C���N�gX�������I�ɕ������s��
		&g_pVertexBuffer,
		NULL);


	////////////////////////////////////////////////////////////VRAM�ɑ΂��ă|���S�����𑗂�t����
	//VRAM�ɍX�V�������邽�߁A���̏������s���Ƃ���GPU�̕`�揈�����~�߂�B(�������d���Ȃ�)


	

	g_pDevice->CreateIndexBuffer(sizeof(WORD) * 6, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &g_pIndexBuffer, NULL);

	WORD* pIndex;
	g_pIndexBuffer->Lock(0, 0, (void**)&pIndex, D3DLOCK_DISCARD);	//VRAM�̂O�Ԗڂ���؂��EVRAM�̂��ׂĂ��擾����E���z�A�h���X(��������VRAM�͑S���Ⴄ���߁AVRAM�̃A�h���X�����z�I�ɃA�h���X���쐬����B)�E
	pIndex[0] = 0;
	pIndex[1] = 1;
	pIndex[2] = 2;
	pIndex[3] = 1;
	pIndex[4] = 3;
	pIndex[5] = 2;

	g_pIndexBuffer->Unlock();

	///////////////////////////////////////////////////////////VRAM����I��
}

void Sprite_Uninit()
{
	if (g_pVertexBuffer)
	{
		g_pVertexBuffer->Release();
		g_pVertexBuffer=NULL;
		
	}
	if (g_pIndexBuffer)
	{
		g_pIndexBuffer->Release();
		g_pIndexBuffer = NULL;
	}

}



void Sprite_Draw(int Texture_id, float dx, float dy, int cut_x, int cut_y, int cut_w, int cut_h, float angle, float cx, float cy, float zoom)
{//textureid:�摜�ԍ��@dx,dy:����@cut_x,cut_y:�e�N�X�`�����W�̍���@cut_w,cut_h�F����t����e�N�X�`���̕����̍����Ɖ��@angle:�\������|���S���̌X���@cx,cy:��]���̍��W zoom:�g��k��

	g_pDevice = GetDevice();




	int w = Texture_GetWidth(Texture_id);	//�e�N�X�`���̍���
	int h = Texture_GetHeight(Texture_id);	//�e�N�X�`���̕�

	float u0 = cut_x / (float)w;			//����
	float v0 = cut_y / (float)h;			//����
	float u1 = (cut_x + cut_w) / (float)w;	//�E��
	float v1 = (cut_y + cut_h) / (float)h;	//�E��




	vertex1 v[] = {
		{ D3DXVECTOR4(dx,dy,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(u0,v0) },//0����
	{ D3DXVECTOR4(dx + w,dy,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(u1,v0) },//1�E��
	{ D3DXVECTOR4(dx ,dy + h ,0.0f,1.0f) ,D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(u0,v1) },//2����
	{ D3DXVECTOR4(dx + w  ,dy + h ,0.0f,1.0f) ,D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(u1,v1) }//3�E��
	};







	D3DXMATRIX mtxRot;
	D3DXMatrixRotationZ(&mtxRot, angle);


	D3DXMATRIX mtxW, mtxR, mtxT, mtxIT, mtxS;	//W�ŏI�I�Ȍ`�@R��]�@T�ړ��@IT���̍��W��	S�g��k��
	D3DXMatrixTranslation(&mtxT, -cx, -cy, 0.0f);		//�ړ��������I�u�W�F�N�g�����̈ʒu�ɖ߂�
	D3DXMatrixTranslation(&mtxIT, cx + dx, cy + dy, 0.0f);		//�ړ��������I�u�W�F�N�g�����̈ʒu�ɖ߂�
	D3DXMatrixRotationZ(&mtxR, angle);	//��]������
	D3DXMatrixScaling(&mtxS, zoom, zoom, 1.0f);


	mtxW = mtxT * mtxS*mtxR*mtxIT;	//�ŏI�I�Ȍ`������

									//D3DXMatrixTranslation(&mtxT, -cx, -cy, 0.0f);	//0���W�ֈړ�



	for (int i = 0; i < 4; i++)
	{
		D3DXVec4Transform(&v[i].position, &v[i].position, &mtxW);

	}
	vertex1* pv;
	g_pVertexBuffer->Lock(0, 0, (void**)&pv, D3DLOCK_DISCARD);
	memcpy(pv, v, sizeof(v));
	g_pVertexBuffer->Unlock();

	g_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);	//���u�����h��L���ɂ���B	
	g_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);	//���l�ƃe�N�X�`���̒l������������B�i���̎����Ȃ��ƃ��l�����������j

	g_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		//���������ɕ`�悷��RGB*������`�悷�郿+��ʂ�RGB*�i1-������`�悷�郿(0~1)�j
	g_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);



	ReSetSamplerState();

	g_pDevice->SetFVF(FVF_VERTEX2D);




	g_pDevice->SetStreamSource(0, g_pVertexBuffer, 0, sizeof(vertex1));	//0�Ԃ߂̃p�C�v���C���E

	g_pDevice->SetIndices(g_pIndexBuffer);
	g_pDevice->SetTexture(0, Texture_GetTexture(Texture_id));

	g_pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);	//�ō����`��



																		//	g_pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

																		//WORD index[] = { 0,1,2,1,3,2 };	//DWORD��65536�\����WORD�����傫�������������Ƃ��ł���悤�ɂȂ�B

																		//g_pDevice->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST,0,4,2,index,D3DFMT_INDEX16,v,sizeof(vertex1));	//�`���E�ŏ����_�z��ԍ��E

																		//���_�f�[�^���w��





}



///////////////////////////////////////////////////����


void Sprite_Draw_Mirror(int Texture_id, float dx, float dy, int cut_x, int cut_y, int cut_w, int cut_h)
{
	//textureid:�摜�ԍ��@dx,dy:����@cut_x,cut_y:�e�N�X�`�����W�̍���@cut_w,cut_h�F����t����e�N�X�`���̕����̍����Ɖ��@angle:�\������|���S����

	g_pDevice = GetDevice();




	int w = Texture_GetWidth(Texture_id);	//�e�N�X�`���̍���
	int h = Texture_GetHeight(Texture_id);	//�e�N�X�`���̕�

	float u0 = cut_x / (float)w;			//����
	float v0 = cut_y / (float)h;			//����
	float u1 = (cut_x + cut_w) / (float)w;	//�E��
	float v1 = (cut_y + cut_h) / (float)h;	//�E��


	vertex1 v[] = {
		{ D3DXVECTOR4(dx,dy,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(u0+1,v0) },//0����
	{ D3DXVECTOR4(dx + cut_w,dy,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(u1+1,v0) },//1�E��
	{ D3DXVECTOR4(dx ,dy + cut_h ,0.0f,1.0f) ,D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(u0+1,v1) },//2����
	{ D3DXVECTOR4(dx + cut_w  ,dy + cut_h ,0.0f,1.0f) ,D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(u1+1,v1) }//3�E��
	};

	vertex1* pv;
	g_pVertexBuffer->Lock(0, 0, (void**)&pv, D3DLOCK_DISCARD);	//VRAM�����b�N
	memcpy(pv, v, sizeof(v));			//VRAM�̉��z�A�h���X�ɑ΂��Ċi�[
	g_pVertexBuffer->Unlock();			//�������ݏI���A���b�N����

	g_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);	//���u�����h��L���ɂ���B	
	g_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);	//���l�ƃe�N�X�`���̒l������������B�i���̎����Ȃ��ƃ��l�����������j

	g_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		//���������ɕ`�悷��RGB*������`�悷�郿+��ʂ�RGB*�i1-������`�悷�郿(0~1)�j
	g_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);


	ReSetSamplerState();


	g_pDevice->SetFVF(FVF_VERTEX2D);




	g_pDevice->SetStreamSource(0, g_pVertexBuffer, 0, sizeof(vertex1));	//0�Ԃ߂̃p�C�v���C���E

	g_pDevice->SetIndices(g_pIndexBuffer);
	g_pDevice->SetTexture(0, Texture_GetTexture(Texture_id));

	g_pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);	//�ō����`��


}

void ReSetSamplerState()	//�e�N�X�`���t�B���^�����O
{
	LPDIRECT3DDEVICE9 Device=GetDevice();

	Device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTEXF_LINEAR);

	Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);		
	Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_ANISOTROPIC);
	Device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);	

	Device->SetSamplerState(0, D3DSAMP_MAXANISOTROPY, 16);	//�������d���Ȃ邪�������̂ڂ₯�����������Y��ɂ���


																		//Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);	//�������茩���邪�A�W���M�B���ڗ���

																		//Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_ANISOTROPIC);	//�J�������琅���ɉf��e�N�X�`���ɑ΂��ĕ�����v�Z�������邽�߁A���ꂢ�ɉf�����Ƃ��ł���B	(Z�t�@�C�g���N����Ȃ��c�H)
																		//Device->SetSamplerState(0, D3DSAMP_MAXANISOTROPY, 8);				//���̍s�̃R�[�h���L�q���邱�Ƃŋ@�\����B

																		//Device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);	//
																		//Device->SetSamplerState(0, D3DSAMP_BORDERCOLOR, D3DCOLOR_RGBA(255, 0, 0, 1));
}