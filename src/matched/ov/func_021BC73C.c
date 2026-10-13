/*
 * function: WIFICLUB_StateCountdownExit
 * address:  0x021BC73C
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
 * Ages the counter at +0x1E0 into the guard call, then stamps the byte at
 * +0x1353 and selector 0x8A when it has gone negative; returns the selector.
 * The guard call takes the aged value, not the selector.
 */
#include "../include/Obj07225.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern int WIFICLUB_UpdateTalkStream(void *p, int v);

int WIFICLUB_StateCountdownExit(char *p, int v)
{
    WIFICLUB_UpdateTalkStream(p, --((struct Obj07225 *)p)->f1E0);

    if (((struct Obj07225 *)p)->f1E0 < 0) {
        ((struct Obj07225 *)p)->f1353 = 0x79;
        ((struct Obj07225 *)p)->f1CC = 0x8A;
    }

    return v;
}
