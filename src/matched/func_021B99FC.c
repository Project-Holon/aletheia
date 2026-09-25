/*
 * function: func_021B99FC
 * address:  0x021B99FC
 * packet:   pkt_021B99FC
 * region:   ov182
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9AAC  0x021B9AAC  thumb  ov182
 *   func_021B9B18  0x021B9B18  thumb  ov182
 */

extern void func_021B9AAC(void *);
extern void func_021B9B18(void *);

void func_021B99FC(int a0, char *p)
{
    func_021B9AAC(p);
    func_021B9B18(p + 4);
}
