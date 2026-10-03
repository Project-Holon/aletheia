/*
 * function: func_021BD554
 * address: 0x021BD554
 * packet: pkt_ov093_021BD554
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75A8(int, unsigned int);
extern void func_021D70F0(u8 *, int);
extern void func_021D7540(int);
void func_021BD554(u8 *p, u8 *m)
{
    func_021D74F8(2712);
    func_021D75A8(2, func_021D5440(m));
    func_021D70F0(p, 164);
    func_021D7540(2715);
}
