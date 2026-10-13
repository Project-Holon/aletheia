/*
 * function: ENCEFF_StepGridSpread
 * address:  0x021F5B30
 * packet:   pkt_ov081_021F5B30
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENCEFF_QueueGridSpreadNeighbors  0x021F5C3C  thumb  ov081
 *   ENCEFF_StartGridSpreadWave  0x021F5CA0  thumb  ov081
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06199.h"
#include "../include/Obj20797.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern void ENCEFF_QueueGridSpreadNeighbors(u8 *w, int k);
extern void ENCEFF_StartGridSpreadWave(u8 *w);

void ENCEFF_StepGridSpread(u8 *w)
{
    int *c = (int *)(w + 0x3000);
    u8 *t = w + 0x300C;

    if (c[0] < ((struct Obj06199 *)w)->f3008 * ((struct Obj06199 *)w)->f300A) {
        if (c[1] == 0) {
            int i;

            for (i = 0; i < ((struct Obj20797 *)t)->f180; i++)
                ENCEFF_QueueGridSpreadNeighbors(w, *(u16 *)(t + i * 2));
            ENCEFF_StartGridSpreadWave(w);
            c[1] = 1;
        } else {
            c[1]--;
        }
    }
}
