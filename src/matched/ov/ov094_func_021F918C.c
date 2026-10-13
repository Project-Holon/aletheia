/*
 * function: func_021F918C
 * address:  0x021F918C
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FX_Div  0x0207C768  arm
 */
typedef unsigned int u32;
typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

extern u32 FX_Div(u32 a, u32 b);

void func_021F918C(const VecFx32 *a, const VecFx32 *b, VecFx32 *out, fx32 div)
{
    out->x = 0;
    out->y = 0;
    out->z = 0;
    if (div == 0)
        div = 0x1000;
    if (b->x - a->x != 0) {
        out->x = FX_Div(b->x - a->x, div);
        if (out->x == 0)
            out->x = (b->x > a->x) ? 1 : -1;
    }
    if (b->y - a->y != 0) {
        out->y = FX_Div(b->y - a->y, div);
        if (out->y == 0)
            out->y = (b->y > a->y) ? 1 : -1;
    }
    if (b->z - a->z != 0) {
        out->z = FX_Div(b->z - a->z, div);
        if (out->z == 0)
        {
            if (b->z > a->z)
                out->z = 1;
            else
                out->z = -1;
        }
    }
}
