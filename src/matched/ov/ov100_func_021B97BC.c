/*
 * function: func_021B97BC
 * address: 0x021B97BC
 * packet: pkt_ov100_021B97BC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef signed short s16;
typedef unsigned short u16;
struct Point { s16 x,y; };
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021B97BC(int a,int b,int c,int d)
{
 struct Point p;
 if(*(int *)(a+0x2c8+d*4) != 0) {
  func_0204B454((struct Actor *)*(int *)(a+0x2c8+d*4),(struct PtS *)&p,0);
  p.x += (s16)b;
  p.y += (s16)c;
  func_0204B404((struct Obj *)(*(int *)(a+0x2c8+d*4)),(const struct Vec2 *)(&p),0);
 }
}
