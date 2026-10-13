/*
 * function: func_021D478C
 * address: 0x021D478C
 * packet: pkt_ov123_021D478C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: seven independent offset locals each receive 0x2ac then their final literal; both spill stores survive.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`o1 = 0x2ac;` before `o1 = 0x294;`; `o2 = 0x2ac;` before `o2 = 0x290;`
 * and 5 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 *
 * symbols:
 *   d_021DA638 0x021DA638 data a1
 *   d_021DA634 0x021DA634 data a1
 *   d_021DA63C 0x021DA63C data a1
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 */
#include "../include/Obj00471.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Point { u16 x, y, z; u8 a, b; };
struct Triple { u8 v[3]; };
extern const struct Triple d_021DA638, d_021DA634, d_021DA63C;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Actor;
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
void func_021D478C(char *p)
{
    struct Triple x, y, z;
    struct Point pt;
    int i;
    int o1, o2, o3, o4, o5, o6, o7;
    x = d_021DA638;
    y = d_021DA634;
    z = d_021DA63C;
    i = 0;
    o1 = 0x294;
    o2 = 0x290;
    o3 = 0x298;
    o4 = 0x2a0;
    o5 = 0x2a0;
    o6 = 0x2a0;
    o7 = 0x2a0;
    for (; i < 3; i++) {
        pt.x = x.v[i]; pt.y = y.v[i]; pt.z = z.v[i];
        pt.a = 0; pt.b = 2;
        *(void **)(p + i * 4 + o4) = CLACT_CreateActor((void *)((struct Obj00471 *)p)->f2AC, (unsigned int)*(void **)(p + o1), *(u32 *)(p + o2), *(u32 *)(p + o3), &pt, 1, ((struct Obj00471 *)p)->fC);
        CLACT_SetActorAutoAnim(*(void **)(p + i * 4 + o5), 0);
        CLACT_SetActorDrawEnable(*(void **)(p + i * 4 + o6), 1);
        CLACT_SetActorObjMode(*(void **)(p + i * 4 + o7), 1);
    }
}
