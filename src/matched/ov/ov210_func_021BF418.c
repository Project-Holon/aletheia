/*
 * function: func_021BF418
 * address: 0x021BF418
 * packet: pkt_ov210_021BF418
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: matched caller BD118 consumes r0. The inactive arm retains the
 *      nested object pointer; the active arm retains BEDF0's return register.
 *      Declare BEDF0's observable r0 return despite void legacy declarations.
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BED98 0x021BED98 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021BEDF0(u8 *, unsigned, unsigned);
extern void func_021BED98(char *, int, int);
extern void func_021BEE38(char *, int, u16, u16, u16);
unsigned func_021BF418(u8 *p)
{
    u8 *data;
    func_021BEDF0(p, 6, 0);
    func_021BEDF0(p, 5, 0);
    func_021BEDF0(p, 2, 1);
    func_021BEDF0(p, 3, 1);
    func_021BEDF0(p, 4, 1);
    data = *(u8 **)(*(u8 **)p + 8);
    if (data[6] != 255) {
        func_021BED98((char *)p, 7, data[6]);
        func_021BEE38((char *)p, 7, 192, 116, 0);
        return func_021BEDF0(p, 7, 1);
    }
    return (unsigned)data;
}
