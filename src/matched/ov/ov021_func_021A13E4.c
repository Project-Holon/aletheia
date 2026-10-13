/*
 * function: FIELD_SUBSCREEN_InitIntrude
 * address:  0x021A13E4
 * packet:   pkt_ov021_021A13E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   INTRUDE_SUBDISP_Init  0x0217CFE4  thumb  ov018
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char  u8;
extern void *FIELDMAP_GetGameSystem(void *p);
extern u8 *INTRUDE_SUBDISP_Init(void *a);

void FIELD_SUBSCREEN_InitIntrude(u32 *p)
{
    p[8] = (u32)INTRUDE_SUBDISP_Init(FIELDMAP_GetGameSystem((void *)p[5]));
}
