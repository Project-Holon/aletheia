/*
 * function: func_021BA0AC
 * address: 0x021BA0AC
 * packet: pkt_ov181_021BA0AC
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct { int x, y, z; } Vec;
void func_021BA0AC(Vec *out, const Vec *base, const Vec *velocity, unsigned step)
{
    Vec v = *base;
    unsigned n;
    n = ((unsigned)(velocity->x < 0 ? -velocity->x : velocity->x) * step) >> 8;
    if (velocity->x > 0) v.x += n; else v.x -= n;
    n = ((unsigned)(velocity->y < 0 ? -velocity->y : velocity->y) * step) >> 8;
    if (velocity->y > 0) v.y += n; else v.y -= n;
    n = ((unsigned)(velocity->z < 0 ? -velocity->z : velocity->z) * step) >> 8;
    if (velocity->z > 0) v.z += n; else v.z -= n;
    *out = v;
}
