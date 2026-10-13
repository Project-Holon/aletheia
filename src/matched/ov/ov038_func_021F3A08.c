/*
 * function: GIMMICK38_FindDoor
 * address:  0x021F3A08
 * packet:   pkt_ov038_021F3A08
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gGimmick38DoorPos 0x021F4694 data a4
 */

#include "../include/G_S3A08.h"

extern struct S3A08 gGimmick38DoorPos[];

int GIMMICK38_FindDoor(int *base, int x, int y, int *o1, int *o2)
{
    int f;
    int ax;
    int bz;
    int i;
    struct S3A08 *e;

    for (i = 0; i < 7; i++) {
        e = &gGimmick38DoorPos[i];
        ax = e->a / 0x10000;
        bz = e->c / 0x10000;
        f = 0;
        if (ax == x && bz == y) {
            *o2 = 1;
            f = 1;
        } else if (ax - 1 == x && bz == y) {
            *o2 = 0;
            f = 1;
        } else if (ax + 1 == x && bz == y) {
            *o2 = 0;
            f = 1;
        }
        if (f != 0) {
            *o1 = *(int *)((char *)base + i * 4 + 0x48);
            return i;
        }
    }
    *o2 = 0;
    *o1 = 0;
    return 7;
}
