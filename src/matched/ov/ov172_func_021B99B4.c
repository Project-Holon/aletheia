/*
 * function: CTVT_TALK_UpdateVoiceIcon
 * address:  0x021B99B4
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Translates the +0xa4 state into a +0xa0 buffer code, doing nothing when the
 * state already equals the +0xa8 one.
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06561.h"

typedef unsigned int u32;

typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void CTVT_TALK_UpdateVoiceIcon(void *a0, char *a1)
{
    u32 v = ((struct Obj06561 *)a1)->fA4;
    u32 w = ((struct Obj06561 *)a1)->fA8;

    if (v == w)
        return;
    if (v == 1) {
        CLACT_SetActorAnimSeq(((struct Obj06561 *)a1)->fA0, 0x17);
        return;
    }
    if (v == 2) {
        CLACT_SetActorAnimSeq(((struct Obj06561 *)a1)->fA0, 0x23);
        return;
    }
    CLACT_SetActorAnimSeq(((struct Obj06561 *)a1)->fA0, 0x18);
}
