/*****************************************************************************/
/* サンプル１																 */
/* [テストダイアログ]														 */
/* 画面項目:																 */
/* ・staticテキスト															 */
/* ・テキストボックス														 */
/* ・OK／NOボタン															 */
/* ・キャンセルボタン														 */
/*																			 */
/* ボタン動作 :																 */
/* ・OK／NOボタン															 */
/* ->テキストボックスの内容をメッセージボックスとして表示					 */
/* ・キャンセルボタン														 */
/* ->ダイアログ非表示(プログラム終了)										 */
/*****************************************************************************/

#include<windows.h>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow) {
	int on_button;

	TCHAR str1[128] = TEXT("質問１．CPP?");

	/* TEXT()は、UNICODE識別するマクロ */
	/* 文字列の定数には、とりあえず全て使う。*/
	on_button = MessageBox(NULL, str1,
		TEXT("質問"), MB_YESNOCANCEL | MB_ICONQUESTION);

	if (on_button == IDYES) {
		//str1の文字列に"_YES"を追記
		lstrcat(str1, TEXT("_YES_はい"));
		MessageBox(NULL, str1,
			TEXT("回答"), MB_OK);
	}
	else if (on_button == IDNO) {
		//str1の文字列に"NO"を追記
		lstrcat(str1, TEXT("_NO‗いいえ"));
		MessageBox(NULL, str1,
			TEXT("回答"), MB_OK);
	}
	else {
		//プログラム終了
		return 0;
	}
	return 0;
}
