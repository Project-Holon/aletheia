/*
 * file:     unit_021B3018_p05.c
 * unit:     yes
 * function: func_021B38B0, func_021B3924
 * address:  0x021B38B0
 * packet:   pkt_ov013_021B38B0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60CC  0x021B60CC  data  a4
 *   func_021B3924  0x021B3924  arm  ov013
 */

#include "../../matched/include/G_021B60CC.h"

extern int d_021B60CC[];
typedef struct {
    unsigned int magic;
    unsigned char type;
} Hdr_021B3924;

extern int func_021B3924(int a, Hdr_021B3924 *b, int c, int *out);

int func_021B38B0(int a, int b, int c)
{
    int out[2];

    switch (func_021B3924(a, (Hdr_021B3924 *)b, c, out)) {
    case 0:
        break;
    case 1:
        ((struct G_021B60CC *)d_021B60CC)->fn(a, out[0], out[1], ((struct G_021B60CC *)d_021B60CC)->arg);
        return 1;
    case 2:
        return 0;
    }
    return 1;
}

#pragma opt_common_subs off
extern unsigned long long func_020870D0(void);
extern int func_021B0F38(int a0, Hdr_021B3924 *h, int a2, unsigned long long t);
extern int func_021B2488(int a, unsigned char *p, int len, int x);

int func_021B3924(int a0, Hdr_021B3924 *h, int a2, int *a3)
{
    unsigned long long t;

    if (h == 0)
        return 0;
    if (h->magic != 0x5F564354)
        return 2;
    if (d_021B60CC[7] == 0 || d_021B60CC[2] == 0)
        return 0;
    a3[0] = 0;
    a3[1] = 0;
    t = func_020870D0();
    if ((h->type & 0xf0) == 0x40) {
        d_021B60CC[1]++;
        func_021B0F38(a0, h, a2, t);
        return 0;
    }
    if (h->type == 0 || h->type == 0xff)
        return func_021B2488(a0, (unsigned char *)h, a2, (int)a3) != 0;
    return 0;
}
#pragma opt_common_subs reset

