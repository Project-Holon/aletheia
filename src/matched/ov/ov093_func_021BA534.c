/*
 * function: func_021BA534
 * address: 0x021BA534
 * packet: pkt_ov093_021BA534
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two bytes are alignment padding at 0x021BA54A.
 * lever: switch preserves two equality tests; logical OR folds to a range check.
 * symbols:
 *   func_021B86B8 0x021B86B8 thumb ov093
 */
extern void *func_021B86B8(void ***);
int func_021BA534(void ***p)
{
    int v = (int)func_021B86B8(p);
    switch (v) {
    case 2:
    case 3: return 1;
    default: return 0;
    }
}
