/*
 * function: func_021B8A6C
 * address: 0x021B8A6C
 * packet: pkt_ov106_021B8A6C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef struct {s16 x,y;} Pair;
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(void *,Pair *,u16);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021B8A6C(u8 *p,int delta) {
    Pair pos;
    int offsets[2];
    int i;
    offsets[0]=-delta;
    offsets[1]=-delta;
    for(i=0;i<2;i++) {
        CLACT_GetActorSurfacePos(*(void **)((u8 *)((unsigned int *)p+i)+8),(struct PtS *)&pos,(u16)i);
        pos.y=offsets[i]+*(s16 *)((u8 *)((s16 *)p+i)+16);
        func_0204B404(*(void **)((u8 *)((unsigned int *)p+i)+8),&pos,i);
        if(pos.y>-16 && pos.y<208) func_0204B3DC(*(void **)((u8 *)((unsigned int *)p+i)+8),1);
        else func_0204B3DC(*(void **)((u8 *)((unsigned int *)p+i)+8),0);
    }
}
