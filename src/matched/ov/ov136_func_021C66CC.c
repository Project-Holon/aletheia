/*
 * function: func_021C66CC
 * address: 0x021C66CC
 * packet: pkt_ov136_021C66CC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B8C4 0x0204B8C4 arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef struct { s16 x, y; } Pair;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, unsigned int which);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B8C4(struct Obj *p, u32 value);
void func_021C66CC(u8 *p, int i, int x, int y)
{
    Pair v;
    v.x = x;
    v.y = y;
    if (y < 256)
        func_0204B404(*(void **)(p + 0x1f0 + i * 4), (const struct Vec2 *)(&v), 0);
    else
        func_0204B404(*(void **)(p + 0x1f0 + i * 4), (const struct Vec2 *)(&v), 1);
    func_0204B8C4(*(void **)(p + 0x1f0 + i * 4), 0);
}
