/*
 * function: func_0218F1FC
 * address:  0x0218F1FC
 * packet:   pkt_ov021_0218F1FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clamps a point into the box [+8,+0xc] x [+0x10,+0x14] (whole units,
 * converted to fx32); returns 1 when it moved.  Same box as func_0218F460.
 *
 * symbols:
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */

typedef struct { int x, y, z; } V;
typedef struct {
    char pad00[8];
    int x0;
    int x1;
    int z0;
    int z1;
} Box;

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

int func_0218F1FC(const Box *a, V *b, V *out)
{
    V p;
    int r;

    p = *b;
    r = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(a->x0) > p.x) {
        r = 1;
        out->x = FX_F32_TO_FX32(a->x0);
    } else if (a->x1 * 4096 < p.x) {
        r = 1;
        out->x = FX_F32_TO_FX32(a->x1);
    }
    if (a->z0 * 4096 > p.z) {
        r = 1;
        out->z = FX_F32_TO_FX32(a->z0);
    } else if (a->z1 * 4096 < p.z) {
        r = 1;
        out->z = FX_F32_TO_FX32(a->z1);
    }
    return r;
}
