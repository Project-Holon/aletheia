/*
 * function: FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset
 * address:  0x021C12E4
 * packet:   pkt_ov021_021C12E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Offsets a position by (0, 1.0, 5.0) fx32 and applies it.
 *
 * symbols:
 *   FLDMMDL_SetDrawOffsetOutside  0x0216D8E0  thumb  ov010
 */

typedef unsigned int u32;
typedef struct { int x, y, z; } V3;

extern void FLDMMDL_SetDrawOffsetOutside(u32 a, V3 *v);

void FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(u32 a, const V3 *v)
{
    V3 t = *v;

    t.y += 0x1000;
    t.z += 0x5000;
    FLDMMDL_SetDrawOffsetOutside(a, &t);
}
