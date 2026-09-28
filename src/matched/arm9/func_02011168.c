/*
 * function: func_02011168
 * address:  0x02011168
 * packet:   pkt_0201102C
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
 * Two mode bytes (+0x1b, +0x1c) and two scales (+0x10, +0x12) on the same two
 * tables; the first arm returns early, the second falls into the shared exit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011168.c \
 *       --func func_02011168 --addr 0x02011168 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 g_02146208[];
extern u8 g_02146228[];

u32 func_02011168(u32 v)
{
    if (g_02146208[0x1b] != 0x30)
        return *(u16 *)(g_02146228 + 0x10) * v / 100;
    if (g_02146208[0x1c] != 0x30)
        v = *(u16 *)(g_02146228 + 0x12) * v / 100;
    return v;
}
