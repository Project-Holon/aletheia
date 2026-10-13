/*
 * function: FIELD_RAIL_GetFocusPos
 * address:  0x021B79D4
 * packet:   pkt_ov021_021B79D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_RAIL_WORK_GetPos(void *, void *);

void FIELD_RAIL_GetFocusPos(void **o, void *out)
{
    if (o[5] != 0) {
        FIELD_RAIL_WORK_GetPos(o[5], out);
    }
}
