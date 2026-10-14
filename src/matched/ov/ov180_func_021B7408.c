/*
 * function: HALL_OF_FAME_GetActorPos
 * address: 0x021B7408
 * packet: pkt_ov180_021B7408
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { s16 x,y; } Pair;
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
void HALL_OF_FAME_GetActorPos(u8 *p,int n,s16 *x,s16 *y) { Pair s; CLACT_GetActorSurfacePos(*(void **)(p+n*4+0x9048),(struct PtS *)&s,0); *x=s.x; *y=s.y; }
