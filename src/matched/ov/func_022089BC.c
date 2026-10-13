/*
 * function: BTLV_GAUGE_HideSlot
 * address:  0x022089BC
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_GAUGE_HideSlot   0x022089BC  thumb
 *   BODY

 *
 * lane O10 candidate
 */

void BTLV_GAUGE_HideSlot(char *p, int i)
{
    if (*(int *)(p + (i << 7) + 0x40) != 0)
        *(unsigned int *)(p + 0xb0 + (i << 7)) |= 0x40000000;
}

