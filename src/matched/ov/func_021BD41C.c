/*
 * function: WIFICLUB_StateWaitRuleMessageTimer
 * address:  0x021BD41C
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
 * Ages the counter at +0x1E0 under the guard and stamps selector 0x6A when it
 * underflows; returns the selector.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern int WIFICLUB_UpdateTalkStream(void *p, int v);

int WIFICLUB_StateWaitRuleMessageTimer(char *p, int v)
{
    if (WIFICLUB_UpdateTalkStream(p, v) != 0) {
        int x = ((struct Obj00008 *)p)->f1E0;

        ((struct Obj00008 *)p)->f1E0 = x - 1;

        if (x < 0) {
            *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x6A;
        }
    }

    return v;
}
