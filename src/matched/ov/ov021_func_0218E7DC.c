/*
 * function: FIELD_CAMERA_RefineAngles
 * address:  0x0218E7DC
 * packet:   pkt_ov021_0218E7DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Refines two 16-bit angles (yaw h0, pitch h1) toward a target vector: builds the unit
 * direction for the current angles and for yaw +/- one degree (0xb6), then nudges each
 * angle by a linear interpolation per quadrant. Writes the results to p0/p1.
 *
 * symbols:
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   FX_SinCosTable_     0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */

typedef short s16;
typedef unsigned short u16;
typedef struct { int x, y, z; } V;
typedef struct { s16 x, y, z; } VS;

extern s16 FX_SinCosTable_[];

static inline int FXM(int a, int b)
{
    return (int)(((long long)a * b + 0x800) >> 12);
}
#define ABS(x) ((x) < 0 ? -(x) : (x))

void FIELD_CAMERA_RefineAngles(V *v, u16 h0, u16 h1, u16 *p0, u16 *p1)
{
    VS c = {0, 0, 0};
    VS b = {0, 0, 0};
    VS a = {0, 0, 0};
    int c1;
    int sb, sa;
    int k0, k1, kb, ka;

    *p0 = h0;
    *p1 = h1;

    k0 = (h0 >> 4) * 2;
    k1 = (h1 >> 4) * 2;
    c1 = FX_SinCosTable_[k1 + 1];
    c.x = FXM(FX_SinCosTable_[k0], c1);
    c.y = FX_SinCosTable_[k1];
    c.z = FXM(FX_SinCosTable_[k0 + 1], c1);
    kb = ((h0 - 0xb6) >> 4) * 2;
    b.x = FXM(FX_SinCosTable_[kb], c1);
    b.z = FXM(FX_SinCosTable_[kb + 1], c1);
    sb = FX_SinCosTable_[((h1 - 0xb6) >> 4) * 2];
    ka = ((h0 + 0xb6) >> 4) * 2;
    a.x = FXM(FX_SinCosTable_[ka], c1);
    a.z = FXM(FX_SinCosTable_[ka + 1], c1);
    sa = FX_SinCosTable_[((h1 + 0xb6) >> 4) * 2];

    if (h0 < 0x4000) {
        if (c.x < v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (v->x - c.x) / (b.x - c.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (c.z - v->z) / (c.z - b.z));
            }
        } else if (c.x > v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (c.x - v->x) / (c.x - a.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (v->z - c.z) / (a.z - c.z));
            }
        }
    } else if (h0 < 0x8000) {
        if (c.x > v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (c.x - v->x) / (c.x - b.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (c.z - v->z) / (c.z - b.z));
            }
        } else if (c.x < v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (v->x - c.x) / (a.x - c.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (v->z - c.z) / (a.z - c.z));
            }
        }
    } else if (h0 < 0xC000) {
        if (c.x > v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (c.x - v->x) / (c.x - b.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (v->z - c.z) / (b.z - c.z));
            }
        } else if (c.x < v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (v->x - c.x) / (a.x - c.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (c.z - v->z) / (c.z - a.z));
            }
        }
    } else {
        if (c.x < v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (v->x - c.x) / (b.x - c.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (v->z - c.z) / (b.z - c.z));
            }
        } else if (c.x > v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (c.x - v->x) / (c.x - a.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (c.z - v->z) / (c.z - a.z));
            }
        }
    }

    if (h1 < 0x4000) {
        if (c.y > v->y) {
            h1 = h1 - (u16)(0xb6 * (c.y - v->y) / (c.y - sb));
        } else if (c.y < v->y) {
            h1 = h1 + (u16)(0xb6 * (v->y - c.y) / (sa - c.y));
        }
    } else if (h1 >= 0xC000) {
        if (c.y > v->y) {
            h1 = h1 - (u16)(0xb6 * (c.y - v->y) / (c.y - sb));
        } else if (c.y < v->y) {
            h1 = h1 + (u16)(0xb6 * (v->y - c.y) / (sa - c.y));
        }
    }

    *p0 = h0;
    *p1 = h1;
}
