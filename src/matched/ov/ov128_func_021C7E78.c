/*
 * function: func_021C7E78
 * address: 0x021C7E78
 * packet: pkt_ov128_021C7E78
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CA3A0 0x021CA3A0 thumb ov128
 *   func_021CA3C4 0x021CA3C4 thumb ov128
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj23080.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021CA3A0(char *p);
extern void func_021CA3C4(char *p);
int func_021C7E78(s16 *p, u8 *a, void *b, int n)
{
    if (n == 0) {
        GFL_USE_PlaySeDefaultVolume(0x551); func_021CA3A0(b); return 3;
    }
    if (n == 6) {
        GFL_USE_PlaySeDefaultVolume(0x556); func_021CA3C4(b); return 4;
    }
    if (n == 5) {
        if (p[2] == 8) { GFL_USE_PlaySeDefaultVolume(0x551); func_021CA3A0(b); return 3; }
        if (p[2] == 9) { GFL_USE_PlaySeDefaultVolume(0x556); func_021CA3C4(b); return 4; }
        if (((struct Obj23080 *)a)->f10 <= (unsigned int)(p[2] + p[0] * 8)) return 0;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        p[4] = 0;
        return 5;
    }
    if (n == 1) return 1;
    return n == 2 ? 2 : 0;
}
