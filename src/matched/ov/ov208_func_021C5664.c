/*
 * function: ZUKAN_DETAIL_FORM_RefreshFormEntries
 * address:  0x021C5664
 * packet:   pkt_ov208_021C5664
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_BuildFormEntries  0x021C53F4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void ZUKAN_DETAIL_FORM_BuildFormEntries(u16 *heap, int key, u8 *out, u16 *count, u16 *groups,
                                u16 *twos, u16 *sel, u16 *next);

void ZUKAN_DETAIL_FORM_RefreshFormEntries(u16 *heap, u8 *p, int key)
{
    ZUKAN_DETAIL_FORM_BuildFormEntries(heap, key, p + 0x148, (u16 *)(p + 0x548), (u16 *)(p + 0x54a),
                        (u16 *)(p + 0x54c), (u16 *)(p + 0x54e), (u16 *)(p + 0x550));
}
