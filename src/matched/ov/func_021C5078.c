/*
 * function: func_021C5078
 * address:  0x021C5078
 * packet:   pkt_021C5078
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_Del  0x02015BA4  thumb  arm9

 * BLOCKED.  MATCH: the call at +0x08 targets 02015EA0, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */


extern void MCSS_SetVanishFlag(void *p);
extern void MCSS_Del(void *sys, void *obj);

void func_021C5078(int a, int b)
{
    MCSS_SetVanishFlag((void *)b);
    MCSS_Del((void *)a, (void *)b);
}

