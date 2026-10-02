/*
 * function: func_021C6E00
 * address: 0x021C6E00
 * packet: pkt_ov093_021C6E00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D74F8(int);
extern void func_021D7540(int);
extern u8 func_021D5440(u8 *);
extern void func_021D75A8(int, u32);
extern void func_021D70E4(u8 *, int);
void func_021C6E00(u8 *p, u8 *a, u32 k)
{
    int line = 12093;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D75A8(3, k);
    func_021D70E4(p, 115);
    func_021D7540(line + 4);
}
