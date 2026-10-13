/*
 * function: FIELD_SOUND_SYSTEM_SetMode7
 * address:  0x02028FB8
 * packet:   pkt_02028F30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker FIELD_SOUND_SYSTEM_SetMode3.c is now a manifest entry (matched class)
 *
 * Node kind 7 setter: guarded by FIELD_SOUND_SYSTEM_IsKindAllowedInState, then the kind tag and
 * this kind's payload members are written.
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_IsKindAllowedInState  0x02028FD0  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/FIELD_SOUND_SYSTEM_SetMode7.c \
 *       --func FIELD_SOUND_SYSTEM_SetMode7 --addr 0x02028FB8 --thumb --cc 1.1p1
 */
#include "../include/Obj00354.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SoundParam;
extern u32 FIELD_SOUND_SYSTEM_IsKindAllowedInState(struct SoundParam *obj, u32 kind);

void FIELD_SOUND_SYSTEM_SetMode7(u8 *p, u32 a)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState((struct SoundParam *)p, 7) != 0) {
        ((struct Obj00354 *)p)->f1C = (u32)7;
        ((struct Obj00354 *)p)->fC = (u32)a;
    }
}
