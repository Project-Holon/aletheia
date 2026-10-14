/*
 * function: CTVT_CAMVIEW_GetOwnSlotBuffer
 * address:  0x021B7818
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Forward three arguments, the third from COMM_TVT_SYS_GetSelfSlot.
 *
 * symbols:
 *   COMM_TVT_SYS_GetSelfSlot  0x021BE0A4  thumb  ov172
 *   CTVT_CAMVIEW_GetSlotBuffer  0x021B7830  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 COMM_TVT_SYS_GetSelfSlot(void *p);
extern int CTVT_CAMVIEW_GetSlotBuffer(void *a0, char *a1, int a2);

u32 CTVT_CAMVIEW_GetOwnSlotBuffer(void *p, void *q)
{
    return CTVT_CAMVIEW_GetSlotBuffer(p, q, COMM_TVT_SYS_GetSelfSlot(p));
}
