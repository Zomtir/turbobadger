// ================================================================================
// ==      This file is a part of Turbo Badger. (C) 2011-2014, Emil Segerås      ==
// ==                     See tb_core.h for more information.                    ==
// ================================================================================

#ifdef TB_SYSTEM_WINDOWS

#include "tb_system.h"

#include <Windows.h>

#include <Timeapi.h>
//timeGetTime

#include <Wingdi.h>
//GetDeviceCaps

#include <Winuser.h>
//GetDC
//ReleaseDC

#ifdef TB_RUNTIME_DEBUG_INFO

void TBDebugOut(const char *str)
{
	OutputDebugString(str);
}

#endif // TB_RUNTIME_DEBUG_INFO

namespace tb {

// == TBSystem ========================================

double TBSystem::GetTimeMS()
{
	return (double)timeGetTime();
}

// Implementation currently done in port_glfw.cpp.
// Windows timer suck. Glut timers suck too (can't be canceled) but that will do for now.
//void TBSystem::RescheduleTimer(double fire_time)
//{
//}

int TBSystem::GetLongClickDelayMS()
{
	return 500;
}

int TBSystem::GetPanThreshold()
{
	return 5 * GetDPI() / 96;
}

int TBSystem::GetPixelsPerLine()
{
	return 40 * GetDPI() / 96;
}

int TBSystem::GetDPI()
{
	HDC hdc = GetDC(nullptr);
	int DPI_x = GetDeviceCaps(hdc, LOGPIXELSX);
	ReleaseDC(nullptr, hdc);
#if 0 // TEST CODE!
	DPI_x *= 2;
#endif
	return DPI_x;
}

} // namespace tb

#endif // TB_SYSTEM_WINDOWS