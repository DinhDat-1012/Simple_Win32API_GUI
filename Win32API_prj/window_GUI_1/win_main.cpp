#include "Windows.h"
#include "text_define.h"

#include<WinUser.h>


LRESULT CALLBACK WndProc(HWND ,UINT,WPARAM,LPARAM);
void add_menu(HWND);
void add_edit_tab(HWND,_Text_Flag);
void update_edit_tab(HWND);

int WINAPI WinMain(HINSTANCE h_instance, HINSTANCE h_prev_instance, LPSTR l_comand_line, int n_cmd_show) {

	HWND hwnd;
	MSG msg;
	WNDCLASS wnd_class = {0};
	

	wnd_class.style = CS_HREDRAW | CS_VREDRAW;
	wnd_class.lpszClassName = L"Program_main";
	wnd_class.cbClsExtra = 0;
	wnd_class.cbWndExtra = 0;
	wnd_class.hInstance = h_instance;
	wnd_class.lpszMenuName = L"menu";
	wnd_class.hbrBackground = GetSysColorBrush(COLOR_3DDKSHADOW);
	wnd_class.lpfnWndProc = WndProc;
	wnd_class.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd_class.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	
	

	RegisterClass(&wnd_class);
	hwnd = CreateWindow(L"Program_main",L"Program_1", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,720,480,NULL,NULL,h_instance,NULL);
	

	ShowWindow(hwnd, n_cmd_show);

	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param) {
	switch (msg) {
	case WM_CREATE: 
		add_menu(hwnd);
		break;
	case WM_SIZE:
		update_edit_tab(hwnd);
		break;
	case WM_COMMAND: {
		switch (LOWORD(w_param)) {
			case _View_ :
				MessageBox(hwnd, L"View menu clicked", L"Menu Event", MB_OK);
				break;
			case _Setting_:
				MessageBox(hwnd, L"Setting menu clicked", L"Menu Event", MB_OK);
				break;
			case _Help_:
				MessageBoxW(hwnd, L"When I create this code. \nOnly me and God know how it works, \nAnd now only God knows! \nJust kidding! \nContact me: dinhdat1012vn@gmail.com ", L"GOD will help you. ", MB_OK);
				break;
		    case _Window_:
				MessageBox(hwnd, L"Open menu clicked", L"Menu Event", MB_OK);
				break;
			case _Save_:
				MessageBox(hwnd, L"Save menu clicked", L"Menu Event", MB_OK);
				break;
			case _About_:
				MessageBox(hwnd, L"Created By Dinh Dat from Hatinh. \n With luv!!!", L"About me: ", MB_ICONINFORMATION);
				break;
			case _Open_:
				Beep(1000,300);
				break;
			case _New_File_:
				Beep(1000, 300);
				add_edit_tab(hwnd,0);
				break;
			case _Save_As_ :
				Beep(1000, 300);
				break;
		case _EXIT_:
				int out_confim = MessageBox(hwnd, L" Do you want to exit the program? ", L"Notifications !!!", MB_YESNO);
				if (out_confim == IDYES) {
					PostQuitMessage(0);
				}
				else {
					break;
				}
			return 0;
		}
		break;
	}
	case WM_DESTROY: 
		PostQuitMessage(0);
		break;
	default: {
		return DefWindowProc(hwnd, msg, w_param, l_param);
		}
	}
}
void add_menu(HWND hwnd) {

	HMENU handle_to_menubar;
	HMENU handle_to_menu_file;
	HMENU handle_to_New;
	handle_to_menu_file = CreateMenu();
	handle_to_menubar = CreateMenu();
	handle_to_New = CreateMenu();
	//handle_menu = CreateMenu();

	//AppendMenu(handle_menu,MF_STRING, _Window_,L"Window");


	AppendMenu(handle_to_menu_file, MF_POPUP, (UINT_PTR)handle_to_New, L"New");
	AppendMenu(handle_to_menu_file, MF_STRING, _File_, L"File");

	AppendMenu(handle_to_menu_file, MF_STRING, _Open_, L"Open");
	AppendMenu(handle_to_menu_file, MF_STRING, _Edit_, L"Edit");
	AppendMenu(handle_to_menu_file, MF_STRING, _Save_, L"Save");
	AppendMenu(handle_to_menu_file, MF_STRING, _Save_As_, L"Save as");
	AppendMenu(handle_to_menu_file, MF_STRING, _Import_, L"Import");
	AppendMenu(handle_to_menu_file, MF_STRING, _Export_, L"Export");
	AppendMenu(handle_to_menu_file, MF_STRING, _EXIT_, L"Exit");


	AppendMenu(handle_to_New, MF_POPUP, _New_, L"New");
	AppendMenu(handle_to_New, MF_POPUP, _New_File_, L"New file");
	AppendMenu(handle_to_New, MF_POPUP, _New_src_, L"New source");
	AppendMenu(handle_to_New, MF_POPUP, _New_project_, L"New project");

	AppendMenu(handle_to_menubar, MF_POPUP, (UINT_PTR)handle_to_menu_file, L"File");
	AppendMenu(handle_to_menubar, MF_POPUP, _Window_, L"Window");
	AppendMenu(handle_to_menubar, MF_POPUP, _View_, L"View");
	AppendMenu(handle_to_menubar, MF_POPUP, _Setting_, L"Setting");
	AppendMenu(handle_to_menubar, MF_POPUP, _About_, L"About");
	AppendMenu(handle_to_menubar, MF_POPUP, _Help_, L"Help");

	SetMenu(hwnd, handle_to_menubar);
}
void add_edit_tab(HWND hwnd,_Text_Flag text_flag) {
	HWND hwnd_text_box;
	RECT rect;
	GetWindowRect(hwnd, &rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
		switch (text_flag) {
			case 1:
					hwnd_text_box = CreateWindowEx(WS_EX_WINDOWEDGE, L"EDIT",L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL, 0, 0, width, height, hwnd, (HMENU)_ID_edittad, __No_hinstance, NULL);
					break;
			case 0:
					hwnd_text_box = CreateWindowEx(WS_EX_WINDOWEDGE, L"EDIT",L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL, 0, 0, width, height, hwnd, (HMENU)_ID_edittad, __No_hinstance, NULL);
					break;
			default: 
					hwnd_text_box = CreateWindowEx(WS_EX_WINDOWEDGE, L"EDIT",L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL, 0, 0, width, height, hwnd, (HMENU)_ID_edittad, __No_hinstance, NULL);
		}
	
	}
void update_edit_tab(HWND hwnd) {
	RECT rect;
	GetClientRect(hwnd, &rect); 
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	HWND hwndTextBox = GetDlgItem(hwnd, _ID_edittad);
	SetWindowPos(hwndTextBox, NULL, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER);
}

