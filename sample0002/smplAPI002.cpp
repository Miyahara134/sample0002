/*****************************************************************************/
/* サンプル２																 */
/* [テストダイアログ]														 */
/* 1)ダイアログのOKボタン押下で一旦ダイアログを非表示						 */
/* 2)別のデスクトップサイズのダイアログ(真ん中に「処理中」の文字列のみで、	 */
/* 　右上の×や最大化、最小化無し)を最前面表示								 */
/* 3)一定時間後（３秒後）にダイアログをクローズ								 */
/* 4)最初のダイアログを表示													 */
/*****************************************************************************/

#include <windows.h>

#define cExec TEXT("処理中")

/*
	イベント（処理中）
*/
LRESULT CALLBACK ExeProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (msg) {
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
		GetClientRect(hWnd, &rect);
		TextOut(hdc, rect.right / 2, rect.bottom / 2, cExec, lstrlen(cExec));
		EndPaint(hWnd, &ps);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}

/*
	主処理
*/
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow) {
	
	int on_button;

	HWND hWnd;
	MSG msg;
	WNDCLASS exeWinc;

	exeWinc.style = CS_HREDRAW | CS_VREDRAW;
	exeWinc.lpfnWndProc = ExeProc;
	exeWinc.cbClsExtra = exeWinc.cbWndExtra = 0;
	exeWinc.hInstance = hInstance;
	exeWinc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	exeWinc.hCursor = LoadCursor(NULL, IDC_ARROW);
	exeWinc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	exeWinc.lpszMenuName = NULL;
	exeWinc.lpszClassName = TEXT("EXEC");

	if (!RegisterClass(&exeWinc)) return 1;

	TCHAR str1[128] = TEXT("処理開始指示");

	while (1) {
		on_button = MessageBox(NULL, str1,
			TEXT("処理開始"), MB_OKCANCEL | MB_ICONQUESTION);

		if (on_button == IDOK) {
			//処理中画面を作成(子ウィンドウ)
			HWND exeWnd = CreateWindow(
				TEXT("EXEC"),		//ウィンドウクラス名
				cExec,				//ウィンドウ名
				WS_CAPTION,			//ウィンドウスタイル
				CW_USEDEFAULT,		//初期位置（ｘ）
				CW_USEDEFAULT,		//初期位置（ｙ）
				CW_USEDEFAULT,		//横幅
				CW_USEDEFAULT,		//縦幅
				NULL,
				NULL,
				hInstance,
				NULL
			);

			//処理中画面の作成に失敗したとき
			if (exeWnd == NULL) {
				return 0;
			}

			//処理中ダイアログを表示@最大化
			ShowWindow(exeWnd, SW_SHOWMAXIMIZED);

			//3秒待つ
			Sleep(3000);

			//処理中ダイアログをクローズ
			ShowWindow(exeWnd, SW_HIDE);

			//完了画面の表示
			MessageBox(NULL, TEXT("処理終了"), TEXT("完了"), MB_OK);
		}
		else {
			//プログラム終了
			return 0;
		}
	}
	return 0;
}
