/*
 * function: BTL_POKEPARAM_ResetStatStages
 * address:  0x021D5F08
 * packet:   pkt_021D5F08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_SetNeutralStatStages  0x021D53C8  thumb  ov093
 *
 * blocker: target 0x021D53C8 is unlabelled in ov093 and in all 11 overlapping
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 */

void BTL_POKEPARAM_SetNeutralStatStages(unsigned char *p);

void BTL_POKEPARAM_ResetStatStages(char *p)
{
    BTL_POKEPARAM_SetNeutralStatStages((unsigned char *)(p + 0xfc));
}
