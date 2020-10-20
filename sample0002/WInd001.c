/*****************************************************************************/
/* サンプル１																 */
/* [テストダイアログ]														 */
/* 画面項目:																 */
/* ・staticテキスト															 */
/* ・テキストボックス														 */
/* ・OKボタン																 */
/* ・キャンセルボタン														 */
/*																			 */
/* ボタン動作 :																 */
/* ・OKボタン																 */
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

	TCHAR str1[128] = TEXT("質問１．");
	TCHAR* str2 = TEXT("");

	/* TEXT()は、UNICODE識別するマクロ */
	/* 文字列の定数には、とりあえず全て使う。*/
	on_button = MessageBox(NULL, str1,
		TEXT("質問"), MB_YESNOCANCEL | MB_ICONQUESTION);

	if (on_button == IDYES) {
		//str1の文字列に"YES"を追記
		lstrcat(str1, TEXT("YES!"));
		MessageBox(NULL, str1,
			TEXT("回答"), MB_OK);
	}
	else if (on_button == IDCANCEL){
		return 0;
	}
	else {
		//str1の文字列に"NO"を追記
		lstrcat(str1, TEXT("NO!"));
		MessageBox(NULL, str1,
			TEXT("回答"), MB_OK);
	}
	return 0;
}
