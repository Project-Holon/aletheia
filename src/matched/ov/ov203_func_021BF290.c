/*
 * function: DEMO3D_DATA_TaskShowMessage
 * address:  0x021BF290
 * packet:   pkt_021BF290
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DEMO3D_DATA_IsCaptureDone 0x021BF7AC thumb
 *   DEMO3D_DATA_CreateMessage 0x021BF2DC thumb
 */
#include "../include/Obj25327.h"

extern int DEMO3D_DATA_IsCaptureDone(char *p, int v);
extern void DEMO3D_DATA_CreateMessage(char *p, int a, int b, int c, unsigned char d, unsigned char e, unsigned char f, unsigned char g);

void DEMO3D_DATA_TaskShowMessage(int a, int b, int *s)
{
    unsigned char x = ((struct Obj25327 *)b)->f80;
    int r6 = s[2] * x;
    int r4 = s[1];
    int t = DEMO3D_DATA_IsCaptureDone((char *)a, s[3]);

    DEMO3D_DATA_CreateMessage((char *)a, s[0], r4 + r6, t, (unsigned char)s[4],
                  (unsigned char)s[5], (unsigned char)s[6], (unsigned char)s[7]);
}
