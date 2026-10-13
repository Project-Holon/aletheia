/*
 * function: VCT_DSP_InitEchoState
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
 *   gEchoState  0x021B4C48  data  a4
 *   gEchoDefaultCoeffs  0x021B3C60  data  a2
 *   gEchoRing  0x021B50CC  data  a2
 *   gEchoFirDelayAlias  0x021B4C74  data  a4
 *   gEchoFirCoeffsAlias  0x021B4C5C  data  a4
 */

#include "../include/G_021B4C48.h"

typedef short s16;

extern struct G_021B4C48 gEchoState;
extern s16 gEchoDefaultCoeffs[];
extern s16 gEchoRing[];
extern int gEchoFirDelayAlias[];
extern int gEchoFirCoeffsAlias[];

void VCT_DSP_InitEchoState(void)
{
    int i;
    s16 *src;

    src = gEchoDefaultCoeffs;
    ((int *)&gEchoState)[3] = 0;
    ((int *)&gEchoState)[2] = 0x19D;
    for (i = 0; i < 0x800; i++)
        gEchoRing[i] = 0;
    for (i = 0; i < 6; i++) {
        gEchoFirDelayAlias[i] = 0;
        gEchoFirCoeffsAlias[i] = src[i];
    }
}
