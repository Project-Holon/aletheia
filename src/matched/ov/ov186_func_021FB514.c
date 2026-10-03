/*
 * function: func_021FB514
 * address: 0x021FB514
 * packet: pkt_ov186_021FB514
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0202590C 0x0202590C thumb
 */
struct Obj; struct Grid; struct Vec2{short x,y;};
extern void func_0204B404(struct Obj *,const struct Vec2 *,unsigned short);
extern void func_0202590C(struct Grid *,short,short);
void func_021FB514(char *p,short x,short y) { struct Vec2 v;v.x=x;v.y=y;func_0204B404(*(struct Obj **)p,&v,*(unsigned *)(p+0x10));func_0202590C(*(struct Grid **)(p+4),v.x+32,v.y-8); }
