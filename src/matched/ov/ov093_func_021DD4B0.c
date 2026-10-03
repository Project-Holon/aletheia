/*
 * function: func_021DD4B0
 * address: 0x021DD4B0
 * packet: pkt_ov093_021DD4B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021DDE30 0x021DDE30 thumb ov093
 */
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021DDE30(int, void *, int, int, int);
void func_021DD4B0(int a, void *b, int c)
{
    if (func_021D62C4(func_021C7CF4(b, c), 15) == 0)
        func_021DDE30(a, b, c, 2, 0);
}
