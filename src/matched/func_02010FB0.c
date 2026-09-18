/*
 * function: func_02010FB0
 * address:  0x02010FB0
 * packet:   pkt_02010EEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146208      0x02146208  data
 *   g_02146228      0x02146228  data
 *   _u32_div_f      0x0209C2B0  arm
 *
 * Two mode bytes (+0x14, +0x15) and two scales (+2, +4), each arm clamped to 100
 * (`if (v > 100) v = 100;`) after the unsigned scale divide.  The two arms end
 * at one shared `pop`, which is why the compiler tail-merged them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010FB0.c \
 *       --func func_02010FB0 --addr 0x02010FB0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 g_02146208[];
extern u8 g_02146228[];

u32 func_02010FB0(u32 v)
{
    if (g_02146208[0x14] != 0x30) {
        v = *(u16 *)(g_02146228 + 2) * v / 100;
        if (v > 100) v = 100;
        return v;
    }
    if (g_02146208[0x15] != 0x30) {
        v = *(u16 *)(g_02146228 + 4) * v / 100;
        if (v > 100) v = 100;
    }
    return v;
}
