/*
 * function: func_021BFC64
 * address: 0x021BFC64
 * packet: pkt_ov110_021BFC64
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x,y; } Vec2;
extern void func_0204B404(void *, const Vec2 *, unsigned);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
void func_021BFC64(u8 *p, unsigned i) {
    Vec2 pos;
    if (i != -1) {
        pos.x = 0x70*(i&1)+0x3e;
        pos.y = 0x18*((i>>1)+1);
        func_0204B404(*(void **)(p+0x14), &pos, 0);
        func_0204B878(*(void **)(p+0x14), 8);
    }
}
