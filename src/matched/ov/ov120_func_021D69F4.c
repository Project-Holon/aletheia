/*
 * function: func_021D69F4
 * address: 0x021D69F4
 * packet: pkt_ov120_021D69F4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8B70 0x021D8B70 data a1
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_02028218 0x02028218 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef struct Entry { u8 code, x, y, other; } Entry;
typedef struct Vec { s16 x, y; } Vec;
extern const Entry d_021D8B70[];
extern void func_0204B3DC(void *, u32);
extern void func_0204B404(void *, const Vec *, u32);
extern void func_0204B878(void *, u32);
extern void func_02028218(void *, u32);
void func_021D69F4(u8 *p, void *q, u32 n)
{
    Vec v;
    switch (n) {
    case 9:
        func_0204B3DC(*(void **)(p + 0x134), 0);
        return;
    case 5:
        func_0204B3DC(*(void **)(p + 0x134), 0);
        if (q) func_02028218(q, 1);
        return;
    case 2: case 3: case 4: case 6: case 7: case 8:
        if (q) func_02028218(q, 0);
        break;
    case 0: case 1: default: break;
    }
    v.x = d_021D8B70[n].x;
    v.y = d_021D8B70[n].y;
    func_0204B404(*(void **)(p + 0x134), &v, 1);
    func_0204B878(*(void **)(p + 0x134), d_021D8B70[n].code);
    func_0204B3DC(*(void **)(p + 0x134), 1);
}
