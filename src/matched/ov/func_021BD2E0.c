/*
 * function: ZKND_TBAR_GetPressedKey
 * address:  0x021BD2E0
 * packet:   pkt_021BD2E0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKND_TBAR_GetButtonActorBase 0x021BD7F8  thumb  ov208

 * Returns +0x14 of the 0x38-byte record selected by the index at +0, or -1.
 */
#include "../include/Obj12116.h"


extern int ZKND_TBAR_GetButtonActorBase(char *);

int ZKND_TBAR_GetPressedKey(char *p)
{
    int i;

    if (((struct Obj12116 *)p)->f8 == 3) {
        i = ((struct Obj12116 *)p)->f0;
        if (i != -1)
            return ZKND_TBAR_GetButtonActorBase(p + 0x28 + i * 0x38);
    }
    return -1;
}
