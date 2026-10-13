/*
 * function: WIFICLUB_StateOpenKindMenu
 * address:  0x021BC940
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_CreateKindMenu  0x021BB9C8  thumb  ov099
 *
 * Runs the setup for selector 0x56 and stamps it 0x1CC bytes in.
 */
#include "../include/Obj18193.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUB_CreateKindMenu(int a);

int WIFICLUB_StateOpenKindMenu(char *p, int v)
{
    WIFICLUB_CreateKindMenu((int)p);
    ((struct Obj18193 *)p)->f1CC = 0x56;
    return v;
}
