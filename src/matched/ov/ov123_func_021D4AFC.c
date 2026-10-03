/*
 * function: func_021D4AFC
 * address: 0x021D4AFC
 * packet: pkt_ov123_021D4AFC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4E7C 0x021D4E7C thumb ov123
 *   func_02035C60 0x02035C60 arm
 *   func_021D4E64 0x021D4E64 thumb ov123
 *   func_020061E4 0x020061E4 thumb
 *   func_021D4D40 0x021D4D40 thumb ov123
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4A04 0x021D4A04 thumb ov123
 */
typedef unsigned int u32;
extern int func_021D4E7C(char *);
extern int func_02035C60(void);
extern void func_021D4E64(void *);
extern void func_020061E4(u32 a);
extern void func_021D4D40(char *, int);
extern void func_021D4244(char *, void *, int);
extern void func_021D4A04(char *);
void func_021D4AFC(char *p)
{
    if (func_021D4E7C(p) != 0 && func_02035C60() != 0) {
        func_021D4E64(p);
        *(u32 *)(p + 0x27c) = 0;
        func_020061E4(0x73b);
        func_021D4D40(p, 0);
        func_021D4244(p, func_021D4A04, 0x360);
    }
}
