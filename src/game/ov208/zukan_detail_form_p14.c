/*
 * file:     zukan_detail_form_p14.c
 * unit:     yes
 * function: func_021C75FC, func_021C7860
 * address:  0x021C75FC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C80CC        0x021C80CC  thumb
 *   func_021C80AC        0x021C80AC  thumb
 *   func_02015C30        0x02015C30  thumb
 *   func_02015C48        0x02015C48  thumb
 *   ov208_func_021C5F34  0x021C5F34  thumb
 *   func_021C7D80        0x021C7D80  thumb
 *   func_021C5200        0x021C5200  thumb
 *   func_021C5CF0        0x021C5CF0  thumb
 *   func_021C4E54        0x021C4E54  thumb
 *   func_021C4EAC        0x021C4EAC  thumb
 *   ov208_func_021C6A10  0x021C6A10  thumb
 *   func_021BC3C0        0x021BC3C0  thumb
 *   func_021BC3A4        0x021BC3A4  thumb
 *   func_0200CA1C        0x0200CA1C  thumb
 *   func_0200CA98        0x0200CA98  thumb
 *   ov208_func_021C7448  0x021C7448  thumb
 *   _fflt                0x0209BDBC  arm
 *   _fdiv                0x0209CE10  arm
 *   _fgr                 0x0209BBB0  arm
 *   _fmul                0x0209C77C  arm
 *   _fadd                0x0209C95C  arm
 *   _fsub                0x0209CB8C  arm
 *   _ffix                0x0209C494  arm
 *   _fgeq                0x0209BB54  arm
 *   _fleq                0x0209BC0C  arm
 *   ov208_func_021C80CC  0x021C80CC  thumb  ov208
 *   ov208_func_021C7FF8  0x021C7FF8  thumb  ov208
 */
#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
struct Blk37;
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

extern void func_021C80CC(void *u, int k, VecF *v);
extern void func_021C80AC(int a, int b, int c);
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void ov208_func_021C5F34(void *a0, u8 *p, void *ctx, int ev);
extern void func_021C7D80(void *a0, u8 *p, void *ctx);
extern void func_021C5200(int *p);
extern void func_021C5CF0(void *a0, u8 *p, void *ctx);
extern void func_021C4E54(void *a0, u8 *p, void *ctx);
extern void func_021C4EAC(void *a0, u8 *p, void *ctx);
extern void ov208_func_021C6A10(void *a0, u8 *p, void *ctx);
extern u16  func_021BC3C0(void *ctx);
extern int func_021BC3A4(int *p);
extern void *func_0200CA1C(void *a);
extern void func_0200CA98(struct Blk37 *p, u16 id, u32 sel, u32 alt, u32 form);
extern void ov208_func_021C7448(void *a0, u8 *p, void *ctx);
extern void ov208_func_021C80CC(void *u, int k, VecF *v);
extern void ov208_func_021C7FF8(void *u, int k, Vec *v);
void ov208_func_021C75FC(void *a0, u8 *p, void *ctx);
void ov208_func_021C7860(void *a0, u8 *p, void *ctx);


void ov208_func_021C75FC(void *a0, u8 *p, void *ctx)
{
    Vec v;
    VecF a;
    Vec u;
    Vec w;
    float x;
    float tx;
    int done;
    int idx;
    u16 id;
    void *obj;
    u32 f;
    u32 sh;

    if (W(0x6c4) == 1) {
        done = 0;
        idx = W(0x124) != 0 ? 2 : 3;
        func_021C80CC(p + 0xc + idx * 0x44, 0, &a);
        tx = a.x;
        func_02015C30((void *)(*(u32 *)(p + 0xc + idx * 0x44)), (u32 *)(&v));
        x = v.x / 4096.0f;
        if (W(0x6c8) == 0) {
            x += 2.0f;
            if (x >= tx)
                done = 1;
        } else {
            x -= 2.0f;
            if (x <= tx)
                done = 1;
        }
        if (done) {
            x = tx;
            W(0x6c4) = 2;
        }
        v.x = FX_F32_TO_FX32(x);
        if (W(0x94) != 0)
            func_02015C48((void *)W(0x94), (u32 *)(&v));
        if (W(0xd8) != 0)
            func_02015C48((void *)W(0xd8), (u32 *)(&v));
        idx = 0;
        if (W(0x124) == 0)
            idx = 1;
        func_02015C30((void *)(*(u32 *)(p + idx * 0x44 + 0xc)), (u32 *)(&v));
        x = v.x / 4096.0f;
        if (W(0x6c8) == 0)
            x += 2.0f;
        else
            x -= 2.0f;
        v.x = FX_F32_TO_FX32(x);
        if (W(0xc) != 0)
            func_02015C48((void *)W(0xc), (u32 *)(&v));
        if (W(0x50) != 0)
            func_02015C48((void *)W(0x50), (u32 *)(&v));
    } else if (W(0x6c4) == 2) {
        sh = 0;
        ov208_func_021C5F34(a0, p, ctx, 0);
        func_021C7D80(a0, p, ctx);
        func_021C5200((int *)(p + 0x94));
        func_021C5200((int *)(p + 0xd8));
        func_021C5CF0(a0, p, ctx);
        func_021C4E54(a0, p, ctx);
        func_021C4EAC(a0, p, ctx);
        ov208_func_021C6A10(a0, p, ctx);
        id = func_021BC3C0(ctx);
        obj = func_0200CA1C((void *)func_021BC3A4(ctx));
        f = *(p + H(0x54e) * 16 + 0x152);
        if (*(p + H(0x54e) * 16 + 0x153) != 0)
            sh = 1;
        func_0200CA98(obj, id, f, sh, *(u16 *)(p + H(0x54e) * 16 + 0x154));
        if (W(0xc) != 0) {
            func_021C80AC((int)(p + 0xc), 0, (int)(&u));
            func_02015C48((void *)W(0xc), (u32 *)(&u));
        }
        if (W(0x50) != 0) {
            func_021C80AC((int)(p + 0x50), 0, (int)(&w));
            func_02015C48((void *)W(0x50), (u32 *)(&w));
        }
        W(0x6c8) = 1;
        ov208_func_021C7448(a0, p, ctx);
        W(0x6c4) = 0;
    }
}


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
            func_02015C30((void *)(*(u32 *)(p + 0xc + idx * 0x44)), (u32 *)(&v1));
            x = v1.x / 4096.0f - 0.5f;
            if (x <= tx) {
                x = tx;
                W(0x6cc) = 1;
            }
            v1.x = FX_F32_TO_FX32(x);
            if (W(0xc) != 0)
                func_02015C48((void *)W(0xc), (u32 *)(&v1));
            if (W(0x50) != 0)
                func_02015C48((void *)W(0x50), (u32 *)(&v1));
            if (W(0x6cc) != 0) {
                if (W(0xc) != 0) {
                    ov208_func_021C7FF8(p + 0xc, 3, &b1);
                    func_02015C48((void *)W(0xc), (u32 *)(&b1));
                }
                if (W(0x50) != 0) {
                    ov208_func_021C7FF8(p + 0x50, 3, &b1);
                    func_02015C48((void *)W(0x50), (u32 *)(&b1));
                }
            }
        }
        if (W(0x6d0) == 0) {
            idx = 2;
            if (W(0x124) == 0)
                idx = 3;
            ov208_func_021C80CC(p + 0xc + idx * 0x44, 4, &a2);
            tx = a2.x;
            func_02015C30((void *)(*(u32 *)(p + 0xc + idx * 0x44)), (u32 *)(&v1));
            x = v1.x / 4096.0f - 1.5f;
            if (x <= tx) {
                x = tx;
                W(0x6d0) = 1;
            }
            v1.x = FX_F32_TO_FX32(x);
            if (W(0x94) != 0)
                func_02015C48((void *)W(0x94), (u32 *)(&v1));
            if (W(0xd8) != 0)
                func_02015C48((void *)W(0xd8), (u32 *)(&v1));
            if (W(0x6d0) != 0) {
                if (W(0x94) != 0) {
                    ov208_func_021C7FF8(p + 0x94, 4, &c1);
                    func_02015C48((void *)W(0x94), (u32 *)(&c1));
                }
                if (W(0xd8) != 0) {
                    ov208_func_021C7FF8(p + 0xd8, 4, &c1);
                    func_02015C48((void *)W(0xd8), (u32 *)(&c1));
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
            func_02015C30((void *)(*(u32 *)(p + 0xc + idx * 0x44)), (u32 *)(&v2));
            x = v2.x / 4096.0f;
            x += 0.5f;
            if (x >= tx) {
                x = tx;
                W(0x6cc) = 1;
            }
            v2.x = FX_F32_TO_FX32(x);
            if (W(0xc) != 0)
                func_02015C48((void *)W(0xc), (u32 *)(&v2));
            if (W(0x50) != 0)
                func_02015C48((void *)W(0x50), (u32 *)(&v2));
            if (W(0x6cc) != 0) {
                if (W(0xc) != 0) {
                    ov208_func_021C7FF8(p + 0xc, 0, &b3);
                    func_02015C48((void *)W(0xc), (u32 *)(&b3));
                }
                if (W(0x50) != 0) {
                    ov208_func_021C7FF8(p + 0x50, 0, &b3);
                    func_02015C48((void *)W(0x50), (u32 *)(&b3));
                }
            }
        }
        if (W(0x6d0) == 0) {
            idx = 2;
            if (W(0x124) == 0)
                idx = 3;
            ov208_func_021C80CC(p + 0xc + idx * 0x44, 2, &a4);
            tx = (&a4)->x;
            func_02015C30((void *)(*(u32 *)(p + 0xc + idx * 0x44)), (u32 *)(&v2));
            x = v2.x / 4096.0f;
            x += 1.5f;
            if (x >= tx) {
                x = tx;
                W(0x6d0) = 1;
            }
            v2.x = FX_F32_TO_FX32(x);
            if (W(0x94) != 0)
                func_02015C48((void *)W(0x94), (u32 *)(&v2));
            if (W(0xd8) != 0)
                func_02015C48((void *)W(0xd8), (u32 *)(&v2));
            if (W(0x6d0) != 0) {
                if (W(0x94) != 0) {
                    ov208_func_021C7FF8(p + 0x94, 2, &c4);
                    func_02015C48((void *)W(0x94), (u32 *)(&c4));
                }
                if (W(0xd8) != 0) {
                    ov208_func_021C7FF8(p + 0xd8, 2, &c4);
                    func_02015C48((void *)W(0xd8), (u32 *)(&c4));
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
