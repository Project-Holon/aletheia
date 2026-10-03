/*
 * function: func_021D8154
 * address: 0x021D8154
 * packet: pkt_ov123_021D8154
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D57B8 0x021D57B8 thumb ov123
 *   func_021D5A7C 0x021D5A7C thumb ov123
 *   func_021D62E0 0x021D62E0 thumb ov123
 *   func_021D65F4 0x021D65F4 thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8130 0x021D8130 thumb ov123
 */
typedef unsigned char u8;
extern void func_021D57B8(char *, int);
extern void func_021D5A7C(char *);
extern void func_021D62E0(u8 *, int);
extern void func_021D65F4(char *);
extern void func_021D6650(char *, int);
extern void func_021D62BC(u8 *, int, unsigned int);
extern void func_021D62B4(char *, int);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_021D6EE0(char *, int, int);
extern void func_021D8130(char *p);
void func_021D8154(char *p)
{
    func_021D57B8(*(char **)(p + 0x18), 11);
    func_021D5A7C(*(char **)(p + 0x18));
    func_021D62E0(*(u8 **)(p + 0x14), 8);
    func_021D65F4(*(char **)(p + 0x14));
    func_021D6650(*(char **)(p + 0x14), 1);
    func_021D62BC(*(u8 **)(p + 0x14), 6, 5);
    func_021D62B4(*(char **)(p + 0x14), 0);
    func_021D62B4(*(char **)(p + 0x14), 12);
    func_020061E4(0x657);
    func_021D6EE0(p, (int)func_021D8130, 0x5c3);
}
