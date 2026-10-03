/*
 * function: func_021D85C4
 * address: 0x021D85C4
 * packet: pkt_ov123_021D85C4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8590 0x021D8590 thumb ov123
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D57B8 0x021D57B8 thumb ov123
 */
extern void func_021D6EE0(char *, int, int);
extern void func_021D8590(char *);
extern int func_021D580C(char *);
extern void func_021D57B8(char *, int);
void func_021D85C4(char *p)
{
    if (func_021D580C(*(char **)(p + 0x18))) {
        func_021D57B8(*(char **)(p + 0x18), 17);
        func_021D6EE0(p, (int)func_021D8590, 0x739);
    }
}
