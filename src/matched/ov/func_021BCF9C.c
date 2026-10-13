/*
 * function: WIFICLUB_StateOpenEntryPrompt
 * address:  0x021BCF9C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_OpenYesNoMenu  0x021BA828  thumb  ov099
 *
 * Runs the setup for selector 0x61 and stamps it 0x1CC bytes in.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUB_OpenYesNoMenu(char *p);

int WIFICLUB_StateOpenEntryPrompt(char *p, int v)
{
    WIFICLUB_OpenYesNoMenu(p);
    *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x61;
    return v;
}
