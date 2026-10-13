/*
 * function: TOWNMAP_GRH_GetHandle
 * address:  0x021BB778
 * packet:   pkt_021BB778
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOWNMAP_GRH_GetSpriteHandle  0x021BBB14  thumb
 *
 * blocker: target 0x021BBB14 is an unlabelled Thumb leaf in ov072, so no
 * `label` branch and no `sole-ref/code` function start attests it; the only
 * pool word naming it is this function's own. All 12 bytes and the relocation
 * field are right.
 
 *
 * UNBLOCKED: TOWNMAP_GRH_GetSpriteHandle is now an EXACT entry in layout/matched/ov072;
 * the call site resolves as matched, verdict promoted to EXACT.
*/

unsigned int TOWNMAP_GRH_GetSpriteHandle(void *p, int n);

unsigned int TOWNMAP_GRH_GetHandle(char *p, int n)
{
    return TOWNMAP_GRH_GetSpriteHandle(p + 4, n);
}
