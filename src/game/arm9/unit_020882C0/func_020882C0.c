/*
 * function: func_020882C0
 * address:  0x020882C0
 * packet:   pkt_020882C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_020882D0  0x020882D0  arm
 */

extern void func_02087988(void);
extern void func_020882D0(void);

void func_020882C0(void)
{
    func_02087988();
    while (1) {
        func_020882D0();
    }
}
