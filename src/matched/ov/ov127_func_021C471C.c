/*
 * unit: yes
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
#include "../include/Obj08122.h"
#include "../include/Obj23027.h"
#include "../include/Obj23028.h"
#include "../include/Obj23029.h"
#include "../include/Obj23030.h"
#include "../include/Obj23031.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void WF2DMAP_ANIM_ApplyActorAnim(u8 *p)
{
    if (((struct Obj08122 *)p)->f14 == 0) CLACT_AddActorAnimFrame(((struct Obj08122 *)p)->f4, 1);
    else CLACT_SetActorAnimSeq(((struct Obj08122 *)p)->f4, ((struct Obj08122 *)p)->f10 + 5);
}
void WF2DMAP_ANIM_AddActorFrame8192(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23027 *)p)->f4, 8192); }
void WF2DMAP_ANIM_AddActorFrame4096A(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23028 *)p)->f4, 4096); }
void WF2DMAP_ANIM_AddActorFrame4096B(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23029 *)p)->f4, 4096); }
void WF2DMAP_ANIM_AddActorFrame32768(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23030 *)p)->f4, 32768); }
void WF2DMAP_ANIM_AddActorFrame24576(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23031 *)p)->f4, 24576); }
