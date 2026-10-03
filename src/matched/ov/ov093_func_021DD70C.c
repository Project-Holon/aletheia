/*
 * function: func_021DD70C
 * address: 0x021DD70C
 * packet: pkt_ov093_021DD70C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021DDE30 0x021DDE30 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern void *func_021C7CF4(int *p, int i);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *, int);
extern void func_021DDE30(int, int, int, int, int);

void func_021DD70C(int a, void *b, int c, int *d)
{
    if (*d == 0 && func_021D62C4(func_021C7CF4(b, c), 15) == 0) func_021DDE30(a, (int)b, c, 2, 1);
}
