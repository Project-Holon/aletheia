/*
 * function: FIELD_CAMERA_RestartDelay
 * address:  0x0218F05C
 * packet:   pkt_ov021_0218F05C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Resets a table object's two entry arrays (12-byte entries) and cursors.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01653.h"

void FIELD_CAMERA_RestartDelay(unsigned char *a)
{
    int *p = *(int * *)&((struct Obj01653 *)a)->fEC;
    int i;

    if (p != 0) {
        for (i = 0; i < p[0]; i++) {
            int *e = (int *)((unsigned char *)p[8] + i * 12);
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
            e = (int *)((unsigned char *)p[9] + i * 12);
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
        }
        p[1] = 0;
        p[2] = p[3];
        p[4] = 0;
        p[10] = 1;
        p[11] = 0;
    }
}
