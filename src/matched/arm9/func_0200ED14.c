/*
 * function: MISC_SAVEDATA_GetRingRecordDate
 * address:  0x0200ED14
 * packet:   pkt_0200ED14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MISC_SAVEDATA_GetRecordDate   0x0200EC98  thumb
 *
 * An unlabelled accessor (its bytes print as a `.word` run after the pool
 * of MISC_SAVEDATA_ExportRingRecord): the header of ring entry `count - 1 - idx`, a tail call
 * to MISC_SAVEDATA_GetRecordDate through a pool word. Same shape as MISC_SAVEDATA_GetRingRecordIndex in
 * unit_0200ECB4.c. Its only caller is ov171 DENDOU_VIEW_LoadHallOfFame.
 */
typedef unsigned char u8;

struct Out0200EC98;
extern void MISC_SAVEDATA_GetRecordDate(const u8 *o, struct Out0200EC98 *out);

void MISC_SAVEDATA_GetRingRecordDate(u8 *o, int idx, void *out)
{
    int n = *(int *)(o + 0x1554) - 1 - idx;

    if (n < 0)
        n += 0xf;
    MISC_SAVEDATA_GetRecordDate(o + n * 0x16c, out);
}
