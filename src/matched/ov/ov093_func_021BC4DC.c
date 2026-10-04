/*
 * function: func_021BC4DC
 * address:  0x021BC4DC
 * packet:   pkt_ov093_021BC4DC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC540  0x021BC540  thumb  ov093
 *   func_021BB930  0x021BB930  thumb  ov093
 */
#include "../include/Obj21043.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021BC540(u8 *p, u8 i, u8 *buf);
extern void func_021BB930(u8 *p, u32 value);

int func_021BC4DC(u8 *p, u8 *out)
{
    u8 buf[4];
    u8 i;
    u8 n;
    u8 j;
    int ok = 0;
    *out = 0;
    for (i = 0; i < 4; i++) {
        n = func_021BC540(p + 0x1ab8, i, buf);
        if (n != 0) {
            for (j = 0; j < n; j++)
                func_021BB930(((struct Obj21043 *)p)->f0, buf[j]);
            ok = 1;
            out[(*out)++ + 1] = i;
        }
    }
    return ok;
}
