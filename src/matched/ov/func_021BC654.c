/*
 * function: FIELD_PLACE_NAME_ResetWindow
 * address:  0x021BC654
 * packet:   pkt_021BC654
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
 *   FIELD_PLACE_NAME_ReleaseWindow  0x021BC63C  thumb  ov021
 *   FIELD_PLACE_NAME_SetupWindow  0x021BC5E4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FIELD_PLACE_NAME_ReleaseWindow(void *p);
extern void FIELD_PLACE_NAME_SetupWindow(int *p);

void FIELD_PLACE_NAME_ResetWindow(u8 *p)
{
    FIELD_PLACE_NAME_ReleaseWindow(p);
    FIELD_PLACE_NAME_SetupWindow((int *)p);
}
