/*
 * function: FIELD_SOUND_SYSTEM_PauseSlots
 * address:  0x02028BA0
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 */
#include "../include/Obj00164.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_USE_StopSeSlot(int i);

void FIELD_SOUND_SYSTEM_PauseSlots(u8 *o, u32 v)
{
    int i;

    if (((struct Obj00164 *)o)->fB4 == 0) {
        for (i = 0; i < 2; i++) {
            if (*(u16 *)(o + 0xac + i * 2) != 0xffff) {
                GFL_USE_StopSeSlot(i + 1);
            }
        }
    }
    ((struct Obj00164 *)o)->fB4 |= v;
}
