/*
 * function: func_021B73E4
 * address: 0x021B73E4
 * packet: pkt_ov180_021B73E4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {short x,y;} Pair;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021B73E4(char *p, int i, short x, short y){Pair v;v.x=x;v.y=y;func_0204B404(*(void **)((u32)p+i*4+36936),(const struct Vec2 *)(&v),0);}
