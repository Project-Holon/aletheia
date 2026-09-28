/*
 * function: func_02035C48
 * address:  0x02035C48
 * packet:   pkt_02035C48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035750   0x02035750  arm
 *   func_020357C0   0x020357C0  arm
 */

extern int func_02035750(void);
extern int func_020357C0(const void *p);

int func_02035C48(const void *p)
{
    func_02035750();
    return func_020357C0(p);
}
