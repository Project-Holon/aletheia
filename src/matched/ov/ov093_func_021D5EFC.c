/*
 * function: BTL_POKEPARAM_RaiseLoweredStatStages
 * address:  0x021D5EFC
 * packet:   pkt_021D5EFC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_RaiseLowStatStagesInArray  0x021D53DC  thumb  ov093
 *
 * note: unblocked when src/matched/BTL_POKEPARAM_RaiseLowStatStagesInArray.c was filed EXACT; the
 * relocation now attests as `matched` (ov093) with no C change.
 */

int BTL_POKEPARAM_RaiseLowStatStagesInArray(signed char *p);

int BTL_POKEPARAM_RaiseLoweredStatStages(char *p)
{
    return BTL_POKEPARAM_RaiseLowStatStagesInArray((signed char *)(p + 0xfc));
}
