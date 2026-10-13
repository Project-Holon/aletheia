/*
 * function: IRCBATTLEMATCH_MoveActor
 * address: 0x021B9800
 * packet: pkt_ov100_021B9800
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
struct Point { s16 x,y; };
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void IRCBATTLEMATCH_MoveActor(int a,int b,int c,int d) { struct Point p; int obj; obj=*(int *)(a+0x2c8+d*4); if(obj){p.x=b;p.y=c;CLACT_AddActorSurfacePos((struct Obj *)obj,(const struct Vec2 *)(&p),0);} }
