#include <windows.h>


int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow){
    
    MessageBox(NULL, L"Привет, мир!!!", L"Оконная процедура", MB_OK);
    return NULL;
}