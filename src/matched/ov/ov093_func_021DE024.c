/*
 * function: func_021DE024
 * address: 0x021DE024
 * packet: pkt_ov093_021DE024
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 * Lever: named byte local shifts r0 into r2 directly; inline cast adds a copy.
 */
extern void *func_021C7CF4(int *p, int i);
extern int func_021DDEA4(void *, int, unsigned int);
extern void func_021DD044(void *, void *, int);
extern int func_021DCFF8(int, int);

void func_021DE024(int a, void *b, int c, int d)
{
    unsigned char n;
    func_021C7CF4(b, c);
    n = func_021DCFF8(a, 2);
    if (func_021DDEA4(b, c, n) != 0) func_021DD044((void *)a, b, c);
}
