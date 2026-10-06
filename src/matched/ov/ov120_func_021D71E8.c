/*
 * function: func_021D71E8
 * address: 0x021D71E8
 * packet: pkt_ov120_021D71E8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y; } Vec;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021D71E8(u8 *p, int index, int delta)
{
    Vec pos;
    if (*(void **)((u32)p + 0x14c + (u32)index * 4) != 0) {
        func_0204B454(*(void **)((u32)p + 0x14c + (u32)index * 4), (struct PtS *)&pos, 1);
        pos.y += (s16)delta;
        func_0204B404(*(void **)((u32)p + 0x14c + (u32)index * 4), (const struct Vec2 *)(&pos), 1);
    }
}
