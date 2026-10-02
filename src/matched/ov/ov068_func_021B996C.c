/*
 * function: func_021B996C
 * address: 0x021B996C
 * packet: pkt_ov068_021B996C
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Task callback ignores its task handle; preserve the pointers visibly loaded.
 * symbols:
 *   func_021B9D60 0x021B9D60 thumb ov068
 *   func_021BA010 0x021BA010 thumb ov068
 */
extern void func_021B9D60(char *);
extern void func_021BA010(char *);
void func_021B996C(void *task, char *p)
{
    func_021B9D60(p);
    func_021BA010(p + 0x7c);
}
