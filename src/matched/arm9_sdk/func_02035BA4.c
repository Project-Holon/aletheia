/*
 * function: func_02035BA4
 * address:  0x02035BA4
 * packet:   pkt_02035BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224   0x02035224  arm
 *   func_02035B58   0x02035B58  arm
 */

extern int func_02035224(void);
extern void func_02035B58(int a, const void *p);

void func_02035BA4(const void *p)
{
    func_02035B58(func_02035224(), p);
}
