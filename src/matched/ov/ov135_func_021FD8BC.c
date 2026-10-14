/*
 * function: WORLDTRADE_LIST_VBlank
 * address:  0x021FD8BC
 * packet:   pkt_021FD8BC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040618  0x02040618  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xD3C];
    int scroll;
} Work;

extern void func_02040618(u32 layer, u32 a, u32 b);

void WORLDTRADE_LIST_VBlank(Work *p)
{
    func_02040618(0, 3, p->scroll);
    func_02040618(1, 3, p->scroll);
    func_02040618(2, 3, p->scroll);
    func_02040618(3, 3, p->scroll);
    func_02040618(4, 3, -p->scroll);
    func_02040618(5, 3, -32 - p->scroll);
    func_02040618(6, 3, -p->scroll);
    func_02040618(7, 3, -p->scroll);
}
