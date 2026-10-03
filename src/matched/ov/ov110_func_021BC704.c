/*
 * function: func_021BC704
 * address: 0x021BC704
 * packet: pkt_ov110_021BC704
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BC69C 0x021BC69C thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204B3DC(void *, u32);
extern void func_021BC69C(u8 *, int);
void func_021BC704(u8 *p, u32 flag)
{
    func_0204B3DC(*(void **)(p + 0x14), flag);
    func_0204B3DC(*(void **)(p + 0x18), flag);
    func_021BC69C(p, 1);
}
