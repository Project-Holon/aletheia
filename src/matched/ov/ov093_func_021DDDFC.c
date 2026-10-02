/*
 * function: func_021DDDFC
 * address: 0x021DDDFC
 * packet: pkt_ov093_021DDDFC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern void *func_021C7CF4(void *, int);
extern int func_021DDEA4(void *, int, unsigned int);
extern void func_021DD044(void *, void *, int);
extern int func_021DCFF8(int, int);

void func_021DDDFC(int a, void *b, int c)
{
    func_021C7CF4(b, c);
    if (func_021DDEA4(b, c, func_021DCFF8(a, 2)) != 0) func_021DD044((void *)a, b, c);
}
