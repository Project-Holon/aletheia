/*
 * function: BTL_MAIN_CheckSetupStatusFlag
 * address:  0x021BA1A8
 * packet:   pkt_021BA1A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SETUP_CheckStatusFlag  0x02013158  thumb
 *
 * blocker: target 0x02013158 has no `func_`/`sub_` label and no outside
 * branch, so the pool relocation cannot be witnessed.  All bytes correct.
 */

int BTL_SETUP_CheckStatusFlag(char *base, int m);

int BTL_MAIN_CheckSetupStatusFlag(char **p, int m)
{
    return BTL_SETUP_CheckStatusFlag(*p, m);
}
