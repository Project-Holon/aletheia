/*
 * function: func_021C4910
 * address: 0x021C4910
 * packet: pkt_ov093_021C4910
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D74F8(int);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
void func_021C4910(u8 *p, u32 a, int k)
{
    func_021D74F8(9667);
    func_021D75EC(2, a);
    func_021D70F0(p, k);
    func_021D7540(9670);
}
