// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#ifndef VGUI_STDAFX_H_
#define VGUI_STDAFX_H_

#define VC_EXTRALEAN    // Exclude rarely-used stuff from Windows headers
#ifndef STRICT
#define STRICT
#endif

// Works with Windows 2000 and later and Windows 98 or later
#undef _WIN32_IE
#undef WINVER
#undef _WIN32_WINDOWS
#undef _WIN32_WINNT
#define WINVER         0x0500 
#define _WIN32_WINDOWS 0x0410 
#define _WIN32_WINNT   0x0500 

#include <windows.h>

// TODO: reference additional headers your program requires here
#ifdef min
#undef min
#undef max
#endif

#endif //VGUI_STDAFX_H_
