/*
 * function: func_021DDEFC
 * address: 0x021DDEFC
 * packet: pkt_ov093_021DDEFC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern int func_021DDEA4(void *, int, unsigned int);
extern void func_021DD044(void *, void *, int);
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);

void func_021DDEFC(int a, void *b, int c)
{
    if (c == func_021D775C(2) && func_021DDEA4(b, c, 4) != 0 && func_021D76BC(17, 2) != 0) func_021DD044((void *)a, b, c);
}
