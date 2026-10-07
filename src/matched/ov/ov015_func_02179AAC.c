/*
 * function: func_02179AAC
 * address:  0x02179AAC
 * packet:   pkt_ov015_02179AAC
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021798DC  0x021798DC  thumb  ov015
 *   g_0217AB80  0x0217AB80  data  a4
 *   d_0217AAC0  0x0217AAC0  data  ov015
 *   d_0217ABA0  0x0217ABA0  data  ov015
 */
#include "../include/Obj03560.h"
#include "../include/G_s_aba0.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021798DC(void *dst, int n, u8 a, u8 b);
extern u8 g_0217AB80[];
extern u8 d_0217AAC0[];
extern struct s_aba0 d_0217ABA0;

void func_02179AAC(void)
{
    u8 *p;

    p = d_0217AAC0;
    if (g_0217AB80[0xE] == 1) {
        if (p[0xE4] == 1) {
            func_021798DC((void *)(((struct Obj03560 *)p)->fC4), p[0xDE], p[0xDF], p[0xE0] | (((u8 *)&d_0217ABA0)[3] << 4));
            p[0xE4] = 0;
        } else {
            func_021798DC(0, 0, 0xEE, p[0xE0] | (((u8 *)&d_0217ABA0)[3] << 4));
        }
        p[0xCE] = 0;
    }
}
