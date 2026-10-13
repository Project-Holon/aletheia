/*
 * function: FIELD_FK_SOUND_ANIME_UpdateAmbientSoundB
 * address:  0x021F401C
 * packet:   pkt_021F401C
 * region:   ov056
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_ReleaseSlot  0x02028B50  thumb
 */
#include "../include/Obj07670.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_SOUND_SYSTEM_ReleaseSlot(u8 *p, int a0);

void FIELD_FK_SOUND_ANIME_UpdateAmbientSoundB(void *a, void *b, u8 *c)
{
    if (*(u16 *)(((struct Obj07670 *)c)->f0) != 0 && ((struct Obj07670 *)c)->f4 == 0) {
        FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)(((struct Obj07670 *)c)->fC), 0x7ef);
        ((struct Obj07670 *)c)->f4 = 1;
    }
}
