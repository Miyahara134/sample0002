/*****************************************************************************/
/* �T���v���P																 */
/* [�e�X�g�_�C�A���O]														 */
/* ��ʍ���:																 */
/* �Estatic�e�L�X�g															 */
/* �E�e�L�X�g�{�b�N�X														 */
/* �EOK�{�^��																 */
/* �E�L�����Z���{�^��														 */
/*																			 */
/* �{�^������ :																 */
/* �EOK�{�^��																 */
/* ->�e�L�X�g�{�b�N�X�̓��e�����b�Z�[�W�{�b�N�X�Ƃ��ĕ\��					 */
/* �E�L�����Z���{�^��														 */
/* ->�_�C�A���O��\��(�v���O�����I��)										 */
/*****************************************************************************/

#include<windows.h>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow) {
	int on_button;

	TCHAR str1[128] = TEXT("����P�D");
	TCHAR* str2 = TEXT("");

	/* TEXT()�́AUNICODE���ʂ���}�N�� */
	/* ������̒萔�ɂ́A�Ƃ肠�����S�Ďg���B*/
	on_button = MessageBox(NULL, str1,
		TEXT("����"), MB_YESNOCANCEL | MB_ICONQUESTION);

	if (on_button == IDYES) {
		//str1�̕������"YES"��ǋL
		lstrcat(str1, TEXT("YES!"));
		MessageBox(NULL, str1,
			TEXT("��"), MB_OK);
	}
	else if (on_button == IDCANCEL){
		return 0;
	}
	else {
		//str1�̕������"NO"��ǋL
		lstrcat(str1, TEXT("NO!"));
		MessageBox(NULL, str1,
			TEXT("��"), MB_OK);
	}
	return 0;
}
