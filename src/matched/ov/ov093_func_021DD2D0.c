/*
 * function: func_021DD2D0
 * address: 0x021DD2D0
 * packet: pkt_ov093_021DD2D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DD338 0x021DD338 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern u8 func_021DD338(void *, int);
extern int func_021D76BC(int, u32);
void func_021DD2D0(int a, void *b, int c)
{
    if (c == func_021D775C(2) && func_021DD338(b, c) != 4)
        func_021D76BC(0x51, 1);
}
