/*
 * function: BTL_ADAPTER_ClearSlots
 * address:  0x021EEA30
 * packet:   pkt_ov093_021EEA30
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlAdapterSlots  0x021F6388  data  a4
 *   gBtlAdapterMode  0x021F6384  data  a4
 */

extern void *gBtlAdapterSlots[];
extern int gBtlAdapterMode;

void BTL_ADAPTER_ClearSlots(int v)
{
    int i;

    for (i = 0; i < 4; i++)
        gBtlAdapterSlots[i] = 0;
    gBtlAdapterMode = v;
}
