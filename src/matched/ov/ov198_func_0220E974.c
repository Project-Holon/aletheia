/*
 * function: func_0220E974
 * address: 0x0220E974
 * packet: pkt_ov198_0220E974
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0220E7CC 0x0220E7CC thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj; struct Vec2;
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32),func_0204B878(struct Obj *,u32);
extern void func_0220E7CC(u8 *,u32);
void func_0220E974(int mode,u8 *p,const struct Vec2 *q) { if(mode==8)func_0204B404((struct Obj *)p,q,1);else {func_0204B878((struct Obj *)p,mode);func_0220E7CC(p,(u32)q);} }
