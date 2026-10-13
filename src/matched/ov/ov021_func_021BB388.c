/*
 * function: FIELD_NOGRID_MAPPER_UpdateCameraForced
 * address:  0x021BB388
 * packet:   pkt_ov021_021BB388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_RAIL_UpdateCamera  0x021B79F0  thumb ov021
 */

struct Obj;
extern int FIELD_RAIL_UpdateCamera(struct Obj *o, int flag);
int FIELD_NOGRID_MAPPER_UpdateCameraForced(void **h) { return FIELD_RAIL_UpdateCamera(*h, 1); }
