/*
 * file:     unit_0217A148.c
 * function: func_0217A148
 * address:  0x0217A148
 * packet:   pkt_02179F28
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   d_0217ABA8  0x0217ABA8  data  ov015
 *   d_0217AAB0  0x0217AAB0  data  ov015
 *   func_0217A034  0x0217A034  arm  ov015
 */

#include "../../matched/include/G_ov015_0217ABA8.h"

extern struct G_ov015_0217ABA8 d_0217ABA8;
extern unsigned char d_0217AAB0[];
extern void func_0217A034(int a0, int a1, int a2, int a3);

void func_0217A148(int a0, int a1, int a2)
{
    if (*(int *)(((char *)&d_0217ABA8) + 0x24))
        func_0217A034(a0, a1, a2, d_0217AAB0[0]);
}
