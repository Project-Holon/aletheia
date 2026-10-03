/*
 * function: func_021BCC88
 * address: 0x021BCC88
 * packet: pkt_ov110_021BCC88
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCAD8 0x021BCAD8 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021BCAD8(void *);
extern void func_0204B3DC(void *, u32);
extern void func_0204B878(void *, u16);
void func_021BCC88(u8 *p)
{
    func_021BCAD8(p);
    func_0204B3DC(*(void **)(p + 0x28), 1);
    func_0204B878(*(void **)(p + 0x28), 1);
    *(u32 *)(p + 0x2c) = 0;
}
