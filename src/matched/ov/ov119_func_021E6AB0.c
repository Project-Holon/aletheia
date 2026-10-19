/*
 * function: POKETRADE_2D_SetCursorSlidePositions
 * address: 0x021E6AB0
 * packet: pkt_ov119_021E6AB0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: split temporary for first loop base and second loop index; 10-byte
 *         register swap without them. Permuter budget 300, 271 compiles.
 * output: 0204B454 and its full getter chain write both coordinate halfwords.
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   BG_SYS_SetPriority 0x0204047C arm
 */
#include "../include/Obj22816.h"
typedef struct { short x,y; } Pt;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorBgPriority(void *,unsigned int);
extern void BG_SYS_SetPriority(int,unsigned short);
void POKETRADE_2D_SetCursorSlidePositions(const char *p)
{
    int i,j;
    Pt a,b,c;
    int tmp;
    const char *tmp1;
    for(i=0;i<8;i++) {
        tmp1=p+i*4;
        tmp1=tmp1+0x10cc;
        CLACT_GetActorSurfacePos(((struct Obj22816 *)tmp1)->f0,(struct PtS *)&a,1);
        if(i/4) {
            a.x-=128;
            CLACT_SetActorBgPriority(*(void **)(p+i*4+0x10cc),3);
        } else a.x+=128;
        CLACT_AddActorSurfacePos(*(void **)(p+i*4+0x10cc),(const struct Vec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1008)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x1008),(struct PtS *)&b,1);
            b.x+=128;
            tmp=i;
            tmp=tmp*4;
            CLACT_AddActorSurfacePos(*(void **)(p+tmp+0x1008),(const struct Vec2 *)(&b),1);
        }
    }
    for(j=0;j<3;j++) {
        if(*(void **)(p+j*4+0x1014)) {
            CLACT_GetActorSurfacePos(*(void **)(p+j*4+0x1014),(struct PtS *)&c,1);
            c.x-=128;
            CLACT_AddActorSurfacePos(*(void **)(p+j*4+0x1014),(const struct Vec2 *)(&c),1);
            CLACT_SetActorBgPriority(*(void **)(p+j*4+0x1014),3);
        }
    }
    BG_SYS_SetPriority(4,2);
    BG_SYS_SetPriority(5,3);
}
