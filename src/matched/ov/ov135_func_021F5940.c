/*
 * function: func_021F5940
 * address: 0x021F5940
 * packet: pkt_ov135_021F5940
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;
extern void func_02202940(void *);
extern void func_020452E8(void *);
void func_021F5940(u8 *p)
{
    func_02202940(p + 0xfa0);
    func_020452E8(*(void **)(p + 0xde0));
    func_020452E8(*(void **)(p + 0xdd0));
    func_020452E8(*(void **)(p + 0xd54));
    func_020452E8(*(void **)(p + 0xd40));
    func_020452E8(*(void **)(p + 0xd4c));
}
