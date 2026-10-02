/*
 * function: func_021EA600
 * address:  0x021EA600
 * packet:   pkt_ov093_021EA600
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EA730  0x021EA730  thumb  ov093
 */
extern void func_021EA730(char *p, int a, int b, int c);

void func_021EA600(char *p)
{
    func_021EA730(p, *(int *)(p + 0xac), 0x50, 0);
}
