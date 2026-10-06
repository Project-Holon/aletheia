/*
 * function: func_02035C20
 * address:  0x02035C20
 * packet:   pkt_02035C20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035750   0x02035750  arm
 *   func_020357A0   0x020357A0  arm
 */

extern int func_02035750(void);
struct Kind;
extern int func_020357A0(struct Kind *p);

int func_02035C20(const void *p)
{
    func_02035750();
    return func_020357A0((struct Kind *)p);
}
