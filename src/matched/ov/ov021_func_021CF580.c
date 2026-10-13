/*
 * function: ENCEFF_LoadOverlays4B4D
 * address:  0x021CF580
 * packet:   pkt_ov021_021CF580
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 0x4B and 0x4D are FS_OVERLAY_ID symbols: ENCEFF_LoadOverlay forwards its r1
 * to func_02034AC4 (overlay_id class, ov021-qualified consumer entry,
 * 2026-10-02).  The listing extent (44 bytes) also covers an unlabelled
 * thunk at 0x021CF59C.
 *
 * symbols:
 *   ENCEFF_LoadOverlay  0x021CF564  thumb  ov021
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Res021CF;
extern void ENCEFF_LoadOverlay(struct Res021CF *r, u32 id);
extern char abs_id_4b[];
extern char abs_id_4d[];

void ENCEFF_LoadOverlays4B4D(void *r)
{
    ENCEFF_LoadOverlay(r, (u32)abs_id_4b);
    ENCEFF_LoadOverlay(r, (u32)abs_id_4d);
}
