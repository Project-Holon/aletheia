/*
 * function: func_020362A4
 * address:  0x020362A4
 * packet:   pkt_020362A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224   0x02035224  arm
 *   func_02036290   0x02036290  arm
 */

struct UiCtx;
extern struct UiCtx *func_02035224(void);
extern void func_02036290(int a, const void *p);

void func_020362A4(const void *p)
{
    func_02036290((int)func_02035224(), p);
}
