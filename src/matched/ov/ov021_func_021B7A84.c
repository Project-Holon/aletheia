/*
 * function: FIELD_RAIL_FindSegmentLocation
 * address:  0x021B7A84
 * packet:   pkt_ov021_021B7A84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_GetOpenLine  0x021B9510  thumb  ov021
 *   FIELD_RAIL_SETTING_GetPoint  0x021B87D8  thumb  ov021
 *   FIELD_RAIL_SETTING_GetLinePos  0x021B8848  thumb  ov021
 *   FIELD_RAIL_SETTING_GetLineFunc  0x021B88B8  thumb  ov021
 *   FIELD_RAIL_IntersectSegmentPlane  0x021B9828  thumb  ov021
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_Distance  0x0207CF3C  arm
 *   gRailUpAxis     0x021D9A00  data   a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20053.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { u16 a, b, c, d; } Rect4;

typedef struct Node {
    u8 pad[0x30];
    VecFx32 pos;
} Node;

typedef int (*HitFn)(int i, u8 *p, VecFx32 *hit, Rect4 *r, VecFx32 *out);

extern u8 *FIELD_RAIL_GetOpenLine(u16 *p, u8 *q, u32 v);
extern u8 *FIELD_RAIL_SETTING_GetPoint(u8 *p, u32 idx);
extern u32 *FIELD_RAIL_SETTING_GetLinePos(u8 *a, u32 b);
extern HitFn FIELD_RAIL_SETTING_GetLineFunc(u8 *a, u32 b);
extern int FIELD_RAIL_IntersectSegmentPlane(VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *d, VecFx32 *e, VecFx32 *f);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern fx32 VEC_Distance(const VecFx32 *v1, const VecFx32 *v2);
extern const VecFx32 gRailUpAxis;

int FIELD_RAIL_FindSegmentLocation(u8 *p, const VecFx32 *pa, const VecFx32 *pb, Rect4 *r, VecFx32 *out)
{
    VecFx32 hit;
    VecFx32 d;
    VecFx32 n;
    VecFx32 up;
    VecFx32 bestPos;
    VecFx32 a;
    VecFx32 b;
    Rect4 bestR;
    int i;
    fx32 best;
    int found;
    u32 *t;
    Node *n0;
    Node *n1;
    u32 *m;
    HitFn f;
    fx32 dist;

    up = gRailUpAxis;
    a = *pa;
    b = *pb;
    found = 0;
    for (i = 0; i < ((struct Obj20053 *)p)->f22; i++) {
        t = (u32 *)FIELD_RAIL_GetOpenLine((u16 *)(p + 0x50), p + 0x20, i);
        if (t == 0) {
            continue;
        }
        n0 = (Node *)FIELD_RAIL_SETTING_GetPoint(p + 0x20, t[0]);
        n1 = (Node *)FIELD_RAIL_SETTING_GetPoint(p + 0x20, t[1]);
        m = FIELD_RAIL_SETTING_GetLinePos(p + 0x20, t[3]);
        VEC_Subtract(&n0->pos, &n1->pos, &d);
        VEC_CrossProduct(&d, &up, &n);
        if (FIELD_RAIL_IntersectSegmentPlane(&d, &n, &n1->pos, &a, &b, &hit) == 0) {
            continue;
        }
        f = FIELD_RAIL_SETTING_GetLineFunc(p + 0x20, *m);
        if (f == 0) {
            continue;
        }
        if (f(i, p, &hit, r, out) == 0) {
            continue;
        }
        if (!found) {
            bestR = *r;
            bestPos = *out;
            best = VEC_Distance(&a, out);
            found = 1;
        } else {
            dist = VEC_Distance(&a, out);
            if (dist < best) {
                bestR = *r;
                bestPos = *out;
                best = dist;
            }
        }
    }
    if (found) {
        *r = bestR;
        *out = bestPos;
    }
    return found;
}
