/*
 * function: WIFICLUB_StateOpenMainMenu
 * address:  0x021BC29C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_UpdateTalkStream  0x021BA928  thumb  ov099
 *   WIFICLUB_CreateMainMenu  0x021BAD50  thumb  ov099
 *
 * Early-returns the selector when the guard is false, else runs the second setup and stamps 0x46.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WIFICLUB_UpdateTalkStream(void *p, int v);
extern void WIFICLUB_CreateMainMenu(int a);

int WIFICLUB_StateOpenMainMenu(char *p, int v)
{
    if (WIFICLUB_UpdateTalkStream(p, v) == 0) {
        return v;
    }

    WIFICLUB_CreateMainMenu((int)p);
    *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x46;
    return v;
}
