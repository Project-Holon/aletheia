/*
 * function: WIFICLUB_StateOpenLevelMenu
 * address:  0x021BC9FC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_CreateLevelMenu  0x021BB9F4  thumb  ov099
 *
 * Runs the setup for selector 0x58 and stamps it 0x1CC bytes in.
 */
#include "../include/Obj18194.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUB_CreateLevelMenu(int a);

int WIFICLUB_StateOpenLevelMenu(char *p, int v)
{
    WIFICLUB_CreateLevelMenu((int)p);
    ((struct Obj18194 *)p)->f1CC = 0x58;
    return v;
}
