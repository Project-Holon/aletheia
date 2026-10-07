/*
 * function: func_021B3364
 * address:  0x021B3364
 * packet:   pkt_ov013_021B3364
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B4C48  0x021B4C48  data  a4
 *   d_021B3C60  0x021B3C60  data  a2
 *   d_021B50CC  0x021B50CC  data  a2
 *   d_021B4C74  0x021B4C74  data  a4
 *   d_021B4C5C  0x021B4C5C  data  a4
 */

#include "../include/G_021B4C48.h"

typedef short s16;

extern struct G_021B4C48 d_021B4C48;
extern s16 d_021B3C60[];
extern s16 d_021B50CC[];
extern int d_021B4C74[];
extern int d_021B4C5C[];

void func_021B3364(void)
{
    int i;
    s16 *src;

    src = d_021B3C60;
    ((int *)&d_021B4C48)[3] = 0;
    ((int *)&d_021B4C48)[2] = 0x19D;
    for (i = 0; i < 0x800; i++)
        d_021B50CC[i] = 0;
    for (i = 0; i < 6; i++) {
        d_021B4C74[i] = 0;
        d_021B4C5C[i] = src[i];
    }
}
