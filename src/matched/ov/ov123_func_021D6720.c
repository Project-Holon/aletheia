/*
 * function: func_021D6720
 * address: 0x021D6720
 * packet: pkt_ov123_021D6720
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6C48 0x021D6C48 thumb ov123
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   d_021DA730 0x021DA730 data a2
 *   d_021DA750 0x021DA750 data a4
 */
#include "../include/Obj13979.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Pos { short x,y; };
struct Pair { int a,b; };
extern const struct Pos d_021DA730;
extern const struct Pair d_021DA750;
extern void func_021D6C48(char *p, int i, void *h);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
void func_021D6720(u8 *p, int i)
{
    struct Pos pos;
    struct Pair pair;
    void *h;
    func_021D6C48((char *)p,i,((struct Obj13979 *)p)->fB4);
    h = ((struct Obj13979 *)p)->fB4;
    pos = d_021DA730; pair = d_021DA750;
    CLACT_AddActorSurfacePos(h,(const struct Vec2 *)(&pos),0); CLACT_SetActorScale(h,&pair);
    CLACT_SetActorAutoAnim(h,0); CLACT_SetActorDrawEnable(h,0);
    CLACT_SetActorObjMode(h,1); CLACT_SetActorAffineMode(h,2);
    *(void **)(p+i*24+0x40f4) = h;
}
