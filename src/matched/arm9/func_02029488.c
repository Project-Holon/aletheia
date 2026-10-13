/*
 * function: FIELD_SOUND_SYSTEM_FadeInTask
 * address:  0x02029488
 * packet:   pkt_02029488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * closed:   blocker FIELD_SOUND_SYSTEM_FadeInTask.c is now a manifest entry (matched class)
 *
 * Two-state stepper.  State 0 emits the descriptor (kind 1, selector from the
 * config block) and advances; state 1 reports done.
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/FIELD_SOUND_SYSTEM_FadeInTask.c \
 *       --func FIELD_SOUND_SYSTEM_FadeInTask --addr 0x02029488 --thumb --cc 1.1p1
 */
#include "../include/Obj11297.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sys;
extern void FIELD_SOUND_SYSTEM_PostRequest(struct Sys *s, u32 a, u32 b, u16 c, u16 d);

int FIELD_SOUND_SYSTEM_FadeInTask(u32 unused, u32 *state, u8 *cfg)
{
    u32 v = ((struct Obj11297 *)cfg)->f4;

    switch (*state) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest((struct Sys *)v, 1, 0, 0, ((struct Obj11297 *)cfg)->fC);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
