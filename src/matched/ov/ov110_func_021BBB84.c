/*
 * function: func_021BBB84
 * address: 0x021BBB84
 * packet: pkt_ov110_021BBB84
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { s16 x, y; } Vec2;
extern unsigned func_0204B3F4(void *);
extern void func_0204B3DC(void *, unsigned);
extern u8 func_021BF6DC(u8 *);
extern void func_021BB224(unsigned, int *, int *);
extern void func_0204B404(void *, const Vec2 *, unsigned);
extern void func_0204B878(void *, u16);
void func_021BBB84(u8 *p, unsigned index)
{
    Vec2 pos;
    int x, y;
    int state;
    *(unsigned *)(p + 0x58) = func_0204B3F4(*(void **)(p + 0x54));
    func_0204B3DC(*(void **)(p + 0x54), 1);
    if (func_021BF6DC(*(u8 **)(p + 4)) == 0 && index != 254) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        state = 31;
    } else {
        state = 16;
        switch (index) {
        case 252: case 253: case 254: break;
        default:
            func_021BB224(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            state = 30;
            break;
        }
    }
    func_0204B404(*(void **)(p + 0x54), &pos, 0);
    func_0204B878(*(void **)(p + 0x54), state);
}
