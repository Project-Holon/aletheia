/*
 * function: STAFF_ROLL_CalcVelocity
 * address: 0x021BA028
 * packet: pkt_ov181_021BA028
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021BA0AA, then the next function.
 * Match lever: target load precedes base load; local declaration order b,a.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef struct { int x, y, z; } Vec;
void STAFF_ROLL_CalcVelocity(Vec *out, const Vec *base, const Vec *target, unsigned duration)
{
    Vec v;
    int b, a, diff;
    b = target->x;
    a = base->x;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.x = ((unsigned)diff << 8) / duration;
    if (a > b) v.x *= -1;
    b = target->y;
    a = base->y;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.y = ((unsigned)diff << 8) / duration;
    if (a > b) v.y *= -1;
    b = target->z;
    a = base->z;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.z = ((unsigned)diff << 8) / duration;
    if (a > b) v.z *= -1;
    *out = v;
}
