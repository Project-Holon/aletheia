/*
 * function: func_021D83CC
 * address: 0x021D83CC
 * packet: pkt_ov121_021D83CC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: sole callback blocker of 021D81B0; root claim granted.
 * symbols:
 *   func_021D6CEC 0x021D6CEC thumb ov121
 */
typedef unsigned char  u8;
extern void func_021D6CEC(u8 *p);
void func_021D83CC(char *p)
{
    func_021D6CEC((u8 *)(p+660));
}
