/*
 * function: func_021D7190
 * address: 0x021D7190
 * packet: pkt_ov120_021D7190
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y; } Vec;
extern void func_0204B404(void *, const Vec *, u32);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021D7190(u8 *p, int index, int x, int y)
{
    Vec pos;
    if (index < 6) {
        pos.x = x;
        pos.y = y;
        func_0204B404(*(void **)((u32)p + 0x14c + (u32)index * 4), &pos, 1);
        func_0204B3DC(*(void **)((u32)p + 0x14c + (u32)index * 4), 1);
    }
}
