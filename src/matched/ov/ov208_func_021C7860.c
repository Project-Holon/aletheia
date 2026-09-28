/*
 * function: ov208_func_021C7860
 * address:  0x021C7860
 * packet:   pkt_ov208_021C7860
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021C5F34  0x021C5F34  thumb  ov208
 *   ov208_func_021C80CC  0x021C80CC  thumb  ov208
 *   ov208_func_021C7FF8  0x021C7FF8  thumb  ov208
 *   func_02015C30  0x02015C30  thumb
 *   func_02015C48  0x02015C48  thumb
 *   _fflt  0x0209BDBC  arm
 *   _fdiv  0x0209CE10  arm
 *   _fgr  0x0209BBB0  arm
 *   _fmul  0x0209C77C  arm
 *   _fadd  0x0209C95C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 *   _fgeq  0x0209BB54  arm
 *   _fleq  0x0209BC0C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

typedef struct {
    float x;
    float y;
    float z;
} VecF;

extern void ov208_func_021C5F34(void *a0, u8 *p, void *ctx, int ev);
extern void ov208_func_021C80CC(void *u, int k, VecF *v);
extern void ov208_func_021C7FF8(void *u, int k, Vec *v);
extern void func_02015C30(u32 obj, Vec *v);
extern void func_02015C48(u32 obj, Vec *v);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

void ov208_func_021C7860(void *a0, u8 *p, void *ctx)
{
    Vec v1;
    VecF a1;
    Vec b1;
    VecF a2;
    Vec c1;
    Vec v2;
    VecF a3;
    Vec b3;
    VecF a4;
    Vec c4;
    float x;
    float tx;
    int idx;

    if (H(0x548) < 2) {
        if (W(0x6b8) == 2) {
            ov208_func_021C5F34(a0, p, ctx, 3);
            return;
        }
        if (W(0x6b8) == 6) {
            ov208_func_021C5F34(a0, p, ctx, 7);
            return;
        }
    } else if (W(0x6b8) == 2) {
        if (W(0x6cc) == 0) {
            idx = 0;
            if (W(0x124) == 0)
                idx = 1;
            ov208_func_021C80CC(p + 0xc + idx * 0x44, 3, &a1);
            tx = a1.x;
            func_02015C30(*(u32 *)(p + 0xc + idx * 0x44), &v1);
            x = v1.x / 4096.0f - 0.5f;
            if (x <= tx) {
                x = tx;
                W(0x6cc) = 1;
            }
            v1.x = FX_F32_TO_FX32(x);
            if (W(0xc) != 0)
                func_02015C48(W(0xc), &v1);
            if (W(0x50) != 0)
                func_02015C48(W(0x50), &v1);
            if (W(0x6cc) != 0) {
                if (W(0xc) != 0) {
                    ov208_func_021C7FF8(p + 0xc, 3, &b1);
                    func_02015C48(W(0xc), &b1);
                }
                if (W(0x50) != 0) {
                    ov208_func_021C7FF8(p + 0x50, 3, &b1);
                    func_02015C48(W(0x50), &b1);
                }
            }
        }
        if (W(0x6d0) == 0) {
            idx = 2;
            if (W(0x124) == 0)
                idx = 3;
            ov208_func_021C80CC(p + 0xc + idx * 0x44, 4, &a2);
            tx = a2.x;
            func_02015C30(*(u32 *)(p + 0xc + idx * 0x44), &v1);
            x = v1.x / 4096.0f - 1.5f;
            if (x <= tx) {
                x = tx;
                W(0x6d0) = 1;
            }
            v1.x = FX_F32_TO_FX32(x);
            if (W(0x94) != 0)
                func_02015C48(W(0x94), &v1);
            if (W(0xd8) != 0)
                func_02015C48(W(0xd8), &v1);
            if (W(0x6d0) != 0) {
                if (W(0x94) != 0) {
                    ov208_func_021C7FF8(p + 0x94, 4, &c1);
                    func_02015C48(W(0x94), &c1);
                }
                if (W(0xd8) != 0) {
                    ov208_func_021C7FF8(p + 0xd8, 4, &c1);
                    func_02015C48(W(0xd8), &c1);
                }
            }
        }
        if (W(0x6cc) != 0 && W(0x6d0) != 0) {
            ov208_func_021C5F34(a0, p, ctx, 3);
            return;
        }
    } else if (W(0x6b8) == 3) {
        ov208_func_021C5F34(a0, p, ctx, 4);
        return;
    } else if (W(0x6b8) == 6) {
        if (W(0x6cc) == 0) {
            idx = 0;
            if (W(0x124) == 0)
                idx = 1;
            ov208_func_021C80CC(p + 0xc + idx * 0x44, 0, &a3);
            tx = a3.x;
            func_02015C30(*(u32 *)(p + 0xc + idx * 0x44), &v2);
            x = v2.x / 4096.0f;
            x += 0.5f;
            if (x >= tx) {
                x = tx;
                W(0x6cc) = 1;
            }
            v2.x = FX_F32_TO_FX32(x);
            if (W(0xc) != 0)
                func_02015C48(W(0xc), &v2);
            if (W(0x50) != 0)
                func_02015C48(W(0x50), &v2);
            if (W(0x6cc) != 0) {
                if (W(0xc) != 0) {
                    ov208_func_021C7FF8(p + 0xc, 0, &b3);
                    func_02015C48(W(0xc), &b3);
                }
                if (W(0x50) != 0) {
                    ov208_func_021C7FF8(p + 0x50, 0, &b3);
                    func_02015C48(W(0x50), &b3);
                }
            }
        }
        if (W(0x6d0) == 0) {
            idx = 2;
            if (W(0x124) == 0)
                idx = 3;
            ov208_func_021C80CC(p + 0xc + idx * 0x44, 2, &a4);
            tx = (&a4)->x;
            func_02015C30(*(u32 *)(p + 0xc + idx * 0x44), &v2);
            x = v2.x / 4096.0f;
            x += 1.5f;
            if (x >= tx) {
                x = tx;
                W(0x6d0) = 1;
            }
            v2.x = FX_F32_TO_FX32(x);
            if (W(0x94) != 0)
                func_02015C48(W(0x94), &v2);
            if (W(0xd8) != 0)
                func_02015C48(W(0xd8), &v2);
            if (W(0x6d0) != 0) {
                if (W(0x94) != 0) {
                    ov208_func_021C7FF8(p + 0x94, 2, &c4);
                    func_02015C48(W(0x94), &c4);
                }
                if (W(0xd8) != 0) {
                    ov208_func_021C7FF8(p + 0xd8, 2, &c4);
                    func_02015C48(W(0xd8), &c4);
                }
            }
        }
        if (W(0x6cc) != 0 && W(0x6d0) != 0) {
            ov208_func_021C5F34(a0, p, ctx, 7);
            return;
        }
    } else if (W(0x6b8) == 7) {
        ov208_func_021C5F34(a0, p, ctx, 0);
    }
}
