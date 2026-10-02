/*
 * function: func_021DDDC4
 * address: 0x021DDDC4
 * packet: pkt_ov093_021DDDC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021DDE30 0x021DDE30 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern void *func_021C7CF4(void *, int);
extern void func_021DDE30(int, int, int, int, int);
extern int func_021D775C(int);
extern int func_021DCFF8(int, int);

void func_021DDDC4(int a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        func_021C7CF4(b, c);
        func_021DDE30(a, (int)b, c, func_021DCFF8(a, 2), 0);
    }
}
