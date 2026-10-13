/*
 * function: FIELD_CAMERA_AreaKeepOutBox
 * address:  0x0218F460
 * packet:   pkt_ov021_0218F460
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pushes a point inside the box [+8,+0xc] x [+0x10,+0x14] (whole units,
 * converted to fx32) out through the nearest side; returns 1 when it moved.
 * Reading p.z directly (no named local) is what puts its CSE slot below the
 * a->x0 temp.
 *
 * symbols:
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 * Addresses are Black-image addresses.
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

int FIELD_CAMERA_AreaKeepOutBox(Box *a, V *b, V *out)
{
    V p;
    int r;
    int best;
    int side;

    p = *b;
    r = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(a->x0) < p.x && FX_F32_TO_FX32(a->x1) > p.x &&
        FX_F32_TO_FX32(a->z0) < p.z && FX_F32_TO_FX32(a->z1) > p.z) {
        r = 1;
        best = out->x - FX_F32_TO_FX32(a->x0);
        side = 0;
        if (best > FX_F32_TO_FX32(a->x1) - out->x) {
            best = FX_F32_TO_FX32(a->x1) - out->x;
            side = 1;
        }
        if (best > out->z - FX_F32_TO_FX32(a->z0)) {
            best = out->z - FX_F32_TO_FX32(a->z0);
            side = 2;
        }
        if (best > FX_F32_TO_FX32(a->z1) - out->z) {
            best = FX_F32_TO_FX32(a->z1) - out->z;
            side = 3;
        }
        switch (side) {
        case 0:
            out->x = FX_F32_TO_FX32(a->x0);
            break;
        case 1:
            out->x = FX_F32_TO_FX32(a->x1);
            break;
        case 2:
            out->z = FX_F32_TO_FX32(a->z0);
            break;
        case 3:
            out->z = FX_F32_TO_FX32(a->z1);
            break;
        }
    }
    return r;
}
