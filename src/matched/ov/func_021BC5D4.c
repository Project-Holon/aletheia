/*
 * function: FIELD_PLACE_NAME_RestoreWindow
 * address:  0x021BC5D4
 * packet:   pkt_021BC5D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FIELD_PLACE_NAME_ResetWindow  0x021BC654  thumb  ov021
 *   FIELD_PLACE_NAME_ClearWindow  0x021BC720  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FIELD_PLACE_NAME_ResetWindow(u8 *p);
extern void FIELD_PLACE_NAME_ClearWindow(void *p);

void FIELD_PLACE_NAME_RestoreWindow(u8 *p)
{
    FIELD_PLACE_NAME_ResetWindow(p);
    FIELD_PLACE_NAME_ClearWindow(p);
}
