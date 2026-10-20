/*
 * file:     wf2dmap_anim.c
 * unit:     yes
 * function: WF2DMAP_ANIM_ApplyActorAnim, WF2DMAP_ANIM_AddActorFrame8192, WF2DMAP_ANIM_AddActorFrame4096A, WF2DMAP_ANIM_AddActorFrame4096B, WF2DMAP_ANIM_AddActorFrame32768, WF2DMAP_ANIM_AddActorFrame24576
 * address: 0x021C471C
 * packet: pkt_ov127_021C471C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */

#include "../types.h"

struct Obj;

/*
 * Object whose actor (offset 4) gets an animation frame or sequence. Only
 * the actor pointer, the sequence base and the mode byte are read here; the
 * other bytes are unread in this file (open item).
 */
typedef struct Wf2dmapAnimTarget {
    unsigned char pad_0[4];
    void *actor;
    unsigned char pad_8[8];
    unsigned int animSeq;
    short animMode;
} Wf2dmapAnimTarget;
struct Actor;

#include "../arm9/clact.h"

void WF2DMAP_ANIM_ApplyActorAnim(u8 *p)
{
    if (((Wf2dmapAnimTarget *)p)->animMode == 0) CLACT_AddActorAnimFrame(((Wf2dmapAnimTarget *)p)->actor, 1);
    else CLACT_SetActorAnimSeq(((Wf2dmapAnimTarget *)p)->actor, ((Wf2dmapAnimTarget *)p)->animSeq + 5);
}
void WF2DMAP_ANIM_AddActorFrame8192(u8 *p) { CLACT_AddActorAnimFrame(((Wf2dmapAnimTarget *)p)->actor, 8192); }
void WF2DMAP_ANIM_AddActorFrame4096A(u8 *p) { CLACT_AddActorAnimFrame(((Wf2dmapAnimTarget *)p)->actor, 4096); }
void WF2DMAP_ANIM_AddActorFrame4096B(u8 *p) { CLACT_AddActorAnimFrame(((Wf2dmapAnimTarget *)p)->actor, 4096); }
void WF2DMAP_ANIM_AddActorFrame32768(u8 *p) { CLACT_AddActorAnimFrame(((Wf2dmapAnimTarget *)p)->actor, 32768); }
void WF2DMAP_ANIM_AddActorFrame24576(u8 *p) { CLACT_AddActorAnimFrame(((Wf2dmapAnimTarget *)p)->actor, 24576); }
