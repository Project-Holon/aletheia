/*
 * function: ZUKAN_DETAIL_AREA_LoadAreaEntryData
 * address:  0x021C1F28
 * packet:   pkt_021C1F28
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm  arm9
 *   (none)

 * Forwards to ARC_UTIL_LoadHandleMemberWithSize with the first argument less one and an out slot.
 */


typedef unsigned int   u32;
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

void *ZUKAN_DETAIL_AREA_LoadAreaEntryData(int a, int b, int c)
{
    int out;

    return ARC_UTIL_LoadHandleMemberWithSize((void *)c, a - 1, 0, b, (u32 *)(&out));
}

