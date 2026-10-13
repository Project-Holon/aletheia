/*
 * function: FIELD_NOGRID_MAPPER_SetCameraLocation
 * address:  0x021BB3D0
 * packet:   pkt_ov021_021BB3D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_RAIL_UpdateCameraAtLocation  0x021B7D68  thumb ov021
 */

struct Obj;
extern void FIELD_RAIL_UpdateCameraAtLocation(struct Obj *o, void *r);
void FIELD_NOGRID_MAPPER_SetCameraLocation(void **h, void *r) { FIELD_RAIL_UpdateCameraAtLocation(*h, r); }
