/*
 * function: func_021E9928
 * address:  0x021E9928
 * packet:   pkt_ov093_021E9928
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F8A78  0x021F8A78  thumb  ov094
 *   func_021E9944  0x021E9944  thumb  ov093
 *   func_021E9730  0x021E9730  thumb  ov093
 */
extern void func_021F8A78(void);
extern void func_021E9944(void *p);
extern void func_021E9730(void *p);

void func_021E9928(char *p)
{
    func_021F8A78();
    func_021E9944(*(void **)(p + 0x180));
    func_021E9730(p);
}
