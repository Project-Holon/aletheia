/*
 * function: FIELD_G3D_MAPPER_SetFocusPos
 * address:  0x0218D158
 * packet:   pkt_ov021_0218D158
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Copies a vector into dst+0x34 through an inline set3 helper with a const
 * source.  The image's c,b,a load order with the b,a,c store order needs
 * both: without const (or with plain statements or locals) the stores come
 * out in a,b,c order.  EXACT* only for the 2-byte alignment pad.
 */

typedef int s32;

typedef struct V3 { s32 x, y, z; } V3;

typedef struct T {
    char pad[0x34];
    V3 v;
} T;

static inline void set3(V3 *d, s32 x, s32 y, s32 z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

void FIELD_G3D_MAPPER_SetFocusPos(T *dst, const V3 *src)
{
    set3(&dst->v, src->x, src->y, src->z);
}
