/*
 * function: ENTRANCE_CAMERA_IsActive
 * address:  0x021BDD40
 * packet:   pkt_ov021_021BDD40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub onto ENTRANCE_CAMERA_IsPhaseActive.
 *
 * symbols:
 *   ENTRANCE_CAMERA_IsPhaseActive  0x021BE1C4  thumb  ov021
 */

typedef unsigned int   u32;
extern int ENTRANCE_CAMERA_IsPhaseActive(u32 a);

int ENTRANCE_CAMERA_IsActive(void *a)
{
    return ENTRANCE_CAMERA_IsPhaseActive((u32)a);
}
