/*
 * function: FIELD_SOUND_SYSTEM_FinishRequest
 * address:  0x02029364
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_FinishRequest.c \\
 *       --func FIELD_SOUND_SYSTEM_FinishRequest --addr 0x02029364 --thumb --cc 1.1p1
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_ClearRequest  0x02029348  thumb
 */
#include "../include/Obj01618.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_SOUND_SYSTEM_ClearRequest(void *obj);

void FIELD_SOUND_SYSTEM_FinishRequest(u8 *p)
{
    if (((struct Obj01618 *)p)->f1C != 0) {
        FIELD_SOUND_SYSTEM_ClearRequest(p);
    }
}
