/*
 * function: func_021D62F8
 * address: 0x021D62F8
 * packet: pkt_ov123_021D62F8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x, y; u16 f4; u8 f6, f7; };
extern void *func_0204B294(u32, void *, u32, u32, struct Point *, u16, u16);
extern void func_0204B92C(void *, u32);
extern void func_0204B3DC(void *, u32);
void func_021D62F8(u8 *p, int x, int y)
{
    struct Point pt;
    if (*(void **)(p + 0xac) == 0) {
        pt.x = x; pt.y = y; pt.f4 = 0; pt.f6 = 0; pt.f7 = 1;
        *(void **)(p + 0xac) = func_0204B294(*(u32 *)(p + 0xc), *(void **)(p + 0x3c), *(u32 *)(p + 0x24), *(u32 *)(p + 0x58), &pt, 1, *(u16 *)(p + 0x43c4));
        func_0204B92C(*(void **)(p + 0xac), 1);
        func_0204B3DC(*(void **)(p + 0xac), 1);
    }
}
