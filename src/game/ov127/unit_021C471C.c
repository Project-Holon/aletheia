/*
 * file:     unit_021C471C.c
 * unit: yes
 * function: func_021C471C, func_021C4740, func_021C4750, func_021C4760, func_021C4770, func_021C4780
 * address: 0x021C471C
 * packet: pkt_ov127_021C471C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../../matched/include/Obj08122.h"
#include "../../matched/include/Obj23027.h"
#include "../../matched/include/Obj23028.h"
#include "../../matched/include/Obj23029.h"
#include "../../matched/include/Obj23030.h"
#include "../../matched/include/Obj23031.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021C471C(u8 *p)
{
    if (((struct Obj08122 *)p)->f14 == 0) CLACT_AddActorAnimFrame(((struct Obj08122 *)p)->f4, 1);
    else func_0204B878(((struct Obj08122 *)p)->f4, ((struct Obj08122 *)p)->f10 + 5);
}
void func_021C4740(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23027 *)p)->f4, 8192); }
void func_021C4750(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23028 *)p)->f4, 4096); }
void func_021C4760(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23029 *)p)->f4, 4096); }
void func_021C4770(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23030 *)p)->f4, 32768); }
void func_021C4780(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23031 *)p)->f4, 24576); }
