/*
 * function: FIELD_NOGRID_MAPPER_SetLineEnable
 * address:  0x021BB3DC
 * packet:   pkt_ov021_021BB3DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x0, r1/r2 passed through
 * (ov046 GIMMICK46_ApplyPoseLines calls it with three arguments).
 *
 * symbols:
 *   FIELD_RAIL_SetLineEnable  0x021B7C04  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern void FIELD_RAIL_SetLineEnable(u8 *o, int k, int flag);

void FIELD_NOGRID_MAPPER_SetLineEnable(u32 *p, int b, int c)
{
    FIELD_RAIL_SetLineEnable((u8 *)(*p), b, c);
}
