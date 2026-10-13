/*
 * function: WIFICLUB_StateRulePreviewDone
 * address:  0x021BCF4C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_UpdateTalkStream  0x021BA928  thumb  ov099
 *
 * Stamps selector 0x7B 0x1CC bytes in when the guard answers true.
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

int WIFICLUB_StateRulePreviewDone(char *p, int v)
{
    if (WIFICLUB_UpdateTalkStream(p, v) == 0) {
        return v;
    }

    *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x7B;
    return v;
}
