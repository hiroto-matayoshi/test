#include"Menu.h"
#include"SceneMgr.h"
#include"DxLib.h"
#include"Input.h"

#define PI 3.1415926535897932384626433832795f

static int mImageTitle; 	// �摜�n���h���i�[�p�ϐ�
static int mImageCone;	
static int mImageMenu;

static int MenuNumber = 0;  //���j���[�J�[�\���Ǘ��p�ϐ�

// ������
void Menu_Initialize() {	
	mImageTitle = LoadGraph("images/Tetris_title.png");     //�摜�̃��[�h
	mImageCone = LoadGraph("images/cone.png");
    mImageMenu = LoadGraph("images/menu_r.png");
}

// �I������
void Menu_Finalize() {
	DeleteGraph(mImageTitle);       // �摜�̉��
	DeleteGraph(mImageCone);
    DeleteGraph(mImageMenu);
}

//�X�V
void Menu_Update() {
    //���j���[�J�[�\���ړ�����
    if (iKeyFlg & PAD_INPUT_DOWN) {
        if (++MenuNumber > 3) MenuNumber = 0;
    }
    if (iKeyFlg & PAD_INPUT_UP) {
        if (--MenuNumber < 0) MenuNumber = 3;
    }

    if (iKeyFlg == PAD_INPUT_1) { //Z�L�[��������Ă�����
        switch (MenuNumber) {       //�V�[���ɂ���ď����𕪊�
        case 0:    //���݂̉�ʂ����j���[�Ȃ�
            SceneMgr_ChangeScene(eScene_Game); //�V�[�����Q�[����ʂɕύX
            break;
        case 1:
            SceneMgr_ChangeScene(eScene_Help); //�V�[�����Q�[����ʂɕύX
            break;
        case 2:
            SceneMgr_ChangeScene(eScene_End); //�V�[�����Q�[����ʂɕύX
            break;

        }
    }

}

// �`��
void Menu_Draw() {
	DrawGraph(0, 0, mImageTitle, FALSE );

    // ���j���[
    DrawGraph(280, 340, mImageMenu, TRUE);

    // ���j���[�J�[�\��
    DrawRotaGraph(245, 360 + MenuNumber * 40, 0.7f, PI / 2, mImageCone, TRUE);

}
