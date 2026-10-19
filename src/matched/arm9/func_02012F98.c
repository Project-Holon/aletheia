/*
 * function: GAME_DATA_GetPerapVoiceSave
 * address:  0x02012F98
 * packet:   pkt_02012F98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: tail-calls func_02007B44(*(void **)p).
 *
 * symbols:
 *   GAME_DATA_GetPerapVoiceSave  0x02012F98  thumb
 *   func_02007B44  0x02007B44  thumb
 */
#include "../include/Obj00054.h"

struct Sub02007AC8Entry;
extern struct Sub02007AC8Entry *func_02007B44(void *sys);

struct Sub02007AC8Entry *GAME_DATA_GetPerapVoiceSave(void *p)
{
    return func_02007B44(((struct Obj00054 *)p)->f0);
}
