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
extern void func_0204B454(void *, Vec *, u32);
extern void func_0204B404(void *, const Vec *, u32);
void func_021D71E8(u8 *p, int index, int delta)
{
    Vec pos;
    if (*(void **)((u32)p + 0x14c + (u32)index * 4) != 0) {
        func_0204B454(*(void **)((u32)p + 0x14c + (u32)index * 4), &pos, 1);
        pos.y += (s16)delta;
        func_0204B404(*(void **)((u32)p + 0x14c + (u32)index * 4), &pos, 1);
    }
}
