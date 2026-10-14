/*
 * function: GSYNC_DISP_SpawnParticleRight
 * address: 0x021D67B4
 * packet: pkt_ov123_021D67B4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DISP_CopyIconPaletteSub 0x021D6C90 thumb ov123
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   d_021DA734 0x021DA734 data a2
 *   d_021DA740 0x021DA740 data a4
 */
#include "../include/Obj13980.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Pos { short x,y; };
struct Pair { int a,b; };
extern const struct Pos d_021DA734;
extern const struct Pair d_021DA740;
extern void GSYNC_DISP_CopyIconPaletteSub(char *p, int i, void *h);
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
void GSYNC_DISP_SpawnParticleRight(u8 *p, int i)
{
    struct Pos pos;
    struct Pair pair;
    void *h;
    GSYNC_DISP_CopyIconPaletteSub((char *)p,i,((struct Obj13980 *)p)->fB8);
    h = ((struct Obj13980 *)p)->fB8;
    pos = d_021DA734; pair = d_021DA740;
    CLACT_AddActorSurfacePos(h,(const struct Vec2 *)(&pos),0); CLACT_SetActorScale(h,&pair);
    CLACT_SetActorAutoAnim(h,0); CLACT_SetActorDrawEnable(h,0);
    CLACT_SetActorObjMode(h,1); CLACT_SetActorAffineMode(h,2);
    *(void **)(p+i*24+0x40f4) = h;
}
