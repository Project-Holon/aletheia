/*
 * function: ENCEFF_QueueGridSpreadCell
 * address:  0x021F5BFC
 * packet:   pkt_ov081_021F5BFC
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENCEFF_IsGridSpreadQueued  0x021F5BCC  thumb  ov081
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13220.h"
#include "../include/Obj20799.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern int ENCEFF_IsGridSpreadQueued(int a, u32 p);

void ENCEFF_QueueGridSpreadCell(u8 *w, int x, int y)
{
    u8 *t = w + 0x300C;
    int k = x + y * ((struct Obj20799 *)w)->f3008;

    if (*(int *)(w + k * 64 + 0x34) == 0) {
        if (ENCEFF_IsGridSpreadQueued(k, (u32)t) == 0) {
            *(u16 *)(t + 0xC0 + ((struct Obj13220 *)t)->f182 * 2) = k;
            (((struct Obj13220 *)t)->f182)++;
        }
    }
}
