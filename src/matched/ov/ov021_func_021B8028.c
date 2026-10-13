/*
 * function: FIELD_RAIL_WORK_GetPos
 * address:  0x021B8028
 * packet:   pkt_ov021_021B8028
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w[3];
} Triple;

void FIELD_RAIL_WORK_GetPos(u8 *o, Triple *out)
{
    *out = *(Triple *)(o + 0x38);
}
