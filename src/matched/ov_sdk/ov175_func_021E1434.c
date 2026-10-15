/*
 * function: DWC_GdbGetState
 * address:  0x021E1434
 * packet:   pkt_021E1434
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gDwcGdbEntity  0x021E5334  data
 *   DWCi_IsError  0x02059F38  arm  arm9
 *
 * Return 4 once 0x02059F38 says the block is live, else the queued count at
 * +8.
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x02059F38 now has an
 * EXACT arm9 shard entry (pkt_02059F38), so `bl 0x02059F38` resolves via
 * `matched`.  The trailing `*` is the usual unlabelled-follower extent.
 * Verified EXACT*, 32 bytes.
 */

typedef unsigned long u32;

extern int DWCi_IsError(void);
extern u32 gDwcGdbEntity[];

int DWC_GdbGetState(void)
{
    if (DWCi_IsError())
        return 4;
    return gDwcGdbEntity[2];
}

