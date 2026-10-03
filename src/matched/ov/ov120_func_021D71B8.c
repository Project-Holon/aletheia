/*
 * function: func_021D71B8
 * address: 0x021D71B8
 * packet: pkt_ov120_021D71B8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02008554 0x02008554 thumb
 *   func_021D7128 0x021D7128 thumb ov120
 *   func_021D7190 0x021D7190 thumb ov120
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern int func_02008554(int);
extern void func_021D7128(u8 *, int, int);
extern void func_021D7190(u8 *, int, int, int);
void func_021D71B8(u8 *p, void *entry, int index)
{
    if (entry != 0) {
        func_021D7128(p, index, func_02008554((int)entry));
        func_021D7190(p, index, 16, -48 * (1 - index));
    }
}
