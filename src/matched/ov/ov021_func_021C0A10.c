/*
 * function: EVENT_RECOVERY_StartBallsAnime
 * address:  0x021C0A10
 * packet:   pkt_ov021_021C0A10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Resets each of the p[0x15] handles, then the optional one at +0x34.
 *
 * symbols:
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb  ov021
 *   FIELD_BUILDMODEL_PlayEntryAnim  0x0218C69C  thumb  ov021
 */
#include "../include/Obj00707.h"

typedef unsigned char u8;

extern void FIELD_BUILDMODEL_PlayNodeSlot(unsigned char *p, int v, int c);
extern void FIELD_BUILDMODEL_PlayEntryAnim(unsigned char *p, int b, int i, int c);

void EVENT_RECOVERY_StartBallsAnime(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        FIELD_BUILDMODEL_PlayNodeSlot((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 0);
    if (((struct Obj00707 *)p)->f34 != 0)
        FIELD_BUILDMODEL_PlayEntryAnim((unsigned char *)(*(int *)&((struct Obj00707 *)p)->f18), ((struct Obj00707 *)p)->f34, 0, 0);
}
