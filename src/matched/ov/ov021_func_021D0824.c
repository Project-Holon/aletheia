/*
 * function: FLDEFF_BUBBLE_SpawnBubble
 * address:  0x021D0824
 * packet:   pkt_ov021_021D0824
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDEFF_BUBBLE_GetFacingVector  0x021D0914  thumb  ov021
 */

typedef short s16;
typedef long long s64;

struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern int FLDEFF_BUBBLE_GetFacingVector(int a, s16 *v);

void FLDEFF_BUBBLE_SpawnBubble(int *p, int a)
{
    s16 v[3];
    int k;

    p[0] = 1;
    p[1] = 0;
    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)(p + 2));
    if (FLDEFF_BUBBLE_GetFacingVector(a, v) == 0) {
        k = 0xE000;
    } else {
        k = 1 << 14;
    }
    p[3] += 0x7000;
    p[2] += (int)(((s64)v[0] * k + 0x800) >> 12);
    p[4] += (int)(((s64)v[2] * k + 0x800) >> 12);
}
