/*
 * function: B_PLIST_MAIN_ShiftActors
 * address: 0x0220F22C
 * packet: pkt_ov198_0220F22C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned char u8;
typedef struct {short x,y;} Pair;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
struct Actor; struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void B_PLIST_MAIN_ShiftActors(u8 *p,int a,short delta)
{
    int i=B_PLIST_MAIN_GetOrderIndex(p,a);
    Pair pair;
    CLACT_GetActorSurfacePos(*(void **)(p+0x1ebc+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)(p+0x1ebc+i*4),(const struct Vec2 *)(&pair),1);
    CLACT_GetActorSurfacePos(*(void **)(p+0x1ed8+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)(p+0x1ed8+i*4),(const struct Vec2 *)(&pair),1);
    CLACT_GetActorSurfacePos(*(void **)(p+0x1ef0+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)(p+0x1ef0+i*4),(const struct Vec2 *)(&pair),1);
    CLACT_GetActorSurfacePos(*(void **)(p+0x1f08+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    CLACT_AddActorSurfacePos(*(void **)(p+0x1f08+i*4),(const struct Vec2 *)(&pair),1);
}
