/*
 * function: func_021F7108
 * address: 0x021F7108
 * packet: pkt_ov094_021F7108
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_GetUp 0x02048B30 arm
 *   _ll_mul 0x0209C054 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 */
typedef signed short s16;
extern const s16 FX_SinCosTable_[];
extern void G3D_CAMERA_GetUp(int, int *);
#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

void func_021F7108(int *p, int a, int b, int *out, int *base)
{
    G3D_CAMERA_GetUp(p[1], base);
    p[2] += a;
    p[3] += b;
    out[0] = MUL(FX_SinCosTable_[(p[3] >> 4) * 2 + 1], FX_SinCosTable_[(p[2] >> 4) * 2 + 1]);
    out[1] = FX_SinCosTable_[(p[2] >> 4) * 2];
    out[2] = MUL(FX_SinCosTable_[(p[3] >> 4) * 2], FX_SinCosTable_[(p[2] >> 4) * 2 + 1]);
    out[0] = MUL(out[0], p[4]);
    out[1] = MUL(out[1], p[4]);
    out[2] = MUL(out[2], p[4]);
    out[0] += base[0];
    out[1] += base[1];
    out[2] += base[2];
}
