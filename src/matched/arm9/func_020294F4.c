/*
 * function: FIELD_SOUND_SYSTEM_FadeOutTask
 * address:  0x020294F4
 * packet:   pkt_02029488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * closed:   blocker FIELD_SOUND_SYSTEM_FadeInTask.c is now a manifest entry (matched class)
 *
 * Two-state stepper, kind 2 variant: state 0 emits the descriptor with the
 * selector on the register argument instead of the stack one.
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/FIELD_SOUND_SYSTEM_FadeOutTask.c \
 *       --func FIELD_SOUND_SYSTEM_FadeOutTask --addr 0x020294F4 --thumb --cc 1.1p1
 */
#include "../include/Obj11300.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sys;
extern void FIELD_SOUND_SYSTEM_PostRequest(struct Sys *s, u32 a, u32 b, u16 c, u16 d);

int FIELD_SOUND_SYSTEM_FadeOutTask(u32 unused, u32 *state, u8 *cfg)
{
    u32 v = ((struct Obj11300 *)cfg)->f4;

    switch (*state) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest((struct Sys *)v, 2, 0, ((struct Obj11300 *)cfg)->fE, 0);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
