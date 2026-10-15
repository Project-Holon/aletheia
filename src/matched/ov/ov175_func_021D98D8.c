/*
 * function: WIFIBATTLEMATCH_NET_IsRegSpriteAnimDone
 * address: 0x021D98D8
 * packet: pkt_ov175_021D98D8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt 0x021E8420 thumb ov177
 */
#include "../include/Obj24308.h"
typedef struct Work Work;
extern int WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(Work *);
int WIFIBATTLEMATCH_NET_IsRegSpriteAnimDone(char *p)
{
    return WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(*(Work * *)&((struct Obj24308 *)p)->f24);
}
