/*
 * function: func_021D8448
 * address: 0x021D8448
 * packet: pkt_ov123_021D8448
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5AB0 0x021D5AB0 thumb ov123
 *   func_021D56FC 0x021D56FC thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D5960 0x021D5960 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D840C 0x021D840C thumb ov123
 */
typedef unsigned char u8;
extern u8 *func_02012944(void *p);
extern int func_0200853C(void *);
extern void func_021D5AB0(u8 *, int);
extern void func_021D56FC(char *, int);
extern void func_021D5950(char *, int);
extern void func_021D5960(char *, int, int);
extern void func_021D6EE0(char *, int, int);
extern void func_021D840C(char *p);
void func_021D8448(char *p)
{
    func_021D5AB0(*(u8 **)(p + 0x18), func_0200853C(func_02012944(*(void **)(*(char **)(p + 0x20) + 4))));
    func_021D56FC(*(char **)(p + 0x18), 1);
    func_021D5950(*(char **)(p + 0x18), 47);
    func_021D5960(*(char **)(p + 0x18), 7, 14);
    func_021D6EE0(p, (int)func_021D840C, 0x6b7);
}
