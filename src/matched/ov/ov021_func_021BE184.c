/*
 * function: ENTRANCE_CAMERA_SetRequest
 * address:  0x021BE184
 * packet:   pkt_ov021_021BE184
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    char pad[0x58];
    Vec v58;
} Obj;

void ENTRANCE_CAMERA_SetRequest(Obj *p, const Vec *v)
{
    p->v58 = *v;
}
