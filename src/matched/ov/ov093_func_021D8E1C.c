/*
 * function: func_021D8E1C
 * address: 0x021D8E1C
 * packet: pkt_ov093_021D8E1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8E00 0x021D8E00 thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D8E7C 0x021D8E7C thumb ov093
 * The thunk's caller supplies r0 and consumes its forwarded return.
 */
extern int func_021D8E00(void *, int);
extern int func_021C8288(void *);
extern void func_021D8E7C(int, void *, unsigned int, unsigned int, unsigned char);
void func_021D8E1C(int a, void *b, int c, int *d)
{
    if (func_021D8E00(b, c)) {
        func_021D8E7C(a, b, c, (unsigned char)(func_021C8288(b) == 1), 1);
        *d = 1;
    }
}
