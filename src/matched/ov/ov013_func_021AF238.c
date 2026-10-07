/*
 * function: func_021AF238
 * address:  0x021AF238
 * packet:   pkt_ov013_021AF238
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021B3C80     0x021B3C80  data  ov013
 *   func_021B21A4  0x021B21A4  arm  ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Work Work;

extern struct Work *d_021B3C80;
extern int func_021B21A4(u8 i);

int func_021AF238(u32 mask, int n)
{
    int i;

    if (d_021B3C80 == 0 || d_021B3C80->f19A8 != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == n) {
            continue;
        }
        if (!(mask & (1 << i))) {
            continue;
        }
        if (d_021B3C80->a[i] == 1) {
            continue;
        }
        if (func_021B21A4(i)) {
            return 0;
        }
        d_021B3C80->a[i] = 1;
    }
    return 1;
}
