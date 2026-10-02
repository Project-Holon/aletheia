/*
 * function: func_021EA824
 * address:  0x021EA824
 * packet:   pkt_ov093_021EA824
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F8A78  0x021F8A78  thumb  ov094
 *   func_021EE224  0x021EE224  thumb  ov093
 */
extern void func_021F8A78(void);
extern void func_021EE224(char *p);

void func_021EA824(char *p)
{
    func_021F8A78();
    func_021EE224(*(char **)(p + 0x17c));
}
