/*
 * file:     zukan_detail_form_p03.c
 * unit:     yes
 * function: func_021C6E60, func_021C6E98, func_021C7448, ov208_func_021C7534, func_021C75FC, func_021C7860, func_021C7CE8, func_021C7D80, func_021C7E74, func_021C7EF8, func_021C7F6C, func_021C7FF8, func_021C80AC
 * address:  0x021C6E60
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
 *   ov208_func_021C5F34  0x021C5F34  thumb  ov208
 *   func_021C80CC        0x021C80CC  thumb
 *   func_02015C48        0x02015C48  thumb
 *   func_021C50F8        0x021C50F8  thumb
 *   func_021C7D80        0x021C7D80  thumb
 *   func_021C5CF0        0x021C5CF0  thumb
 *   func_021C4E54        0x021C4E54  thumb
 *   func_021C4EAC        0x021C4EAC  thumb
 *   ov208_func_021C6A10  0x021C6A10  thumb  ov208
 *   func_021BC3C0        0x021BC3C0  thumb
 *   func_021BC3A4        0x021BC3A4  thumb
 *   func_0200CA1C        0x0200CA1C  thumb
 *   func_0200CA98        0x0200CA98  thumb
 *   tbl_020A1B38         0x020A1B38  data
 *   _fflt                0x0209BDBC  arm
 *   _fdiv                0x0209CE10  arm
 *   _fgr                 0x0209BBB0  arm
 *   _fmul                0x0209C77C  arm
 *   _fadd                0x0209C95C  arm
 *   _fsub                0x0209CB8C  arm
 *   _ffix                0x0209C494  arm
 *   func_021C51A0 0x021C51A0 thumb ov208
 *   func_021C51C8 0x021C51C8 thumb ov208
 *   ov208_func_021C569C 0x021C569C thumb ov208
 *   func_021C7534 0x021C7534 thumb ov208
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02015C30        0x02015C30  thumb
 *   func_021C5200        0x021C5200  thumb
 *   ov208_func_021C7448  0x021C7448  thumb
 *   _fgeq                0x0209BB54  arm
 *   _fleq                0x0209BC0C  arm
 *   ov208_func_021C80CC  0x021C80CC  thumb  ov208
 *   func_02014CEC 0x02014CEC thumb
 *   func_0204B688  0x0204B688  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_021BC518  0x021BC518  thumb
 *   data_021C87C0  0x021C87C0  data
 *   data_021C8854  0x021C8854  data
 *   func_021C7FF8 0x021C7FF8  thumb  ov208
 */
#include "../../matched/include/Obj25527.h"
#include "../../matched/include/Obj00147.h"
#include "../../matched/include/Obj03369.h"

#define W(o) (*(u32 *)(p + (o)))
#define I(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
struct Blk37;
struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

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

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

struct Ov208Mdl_021C6E60 {
    u32 obj;
};

struct Ov208Tri {
    u32 a;
    u32 b;
    u32 c;
};

struct Ov208Unit {
    u32 f0;
    u32 *f4;
    struct Ov208Tri e[5];
};

struct Ov208Battle {
    u32 pad0[3];
    struct Ov208Unit u[4];
    u8 pad11c[0x54e - 0x11c];
    u16 h54e;
    u16 h550;
};

struct Ov208PoseEnt {
    u32 species;
    u32 form;
    u32 gender;
    u32 fc;
    u32 f10;
    u32 side;
    u32 f18;
    VecF pos[5];
};

typedef struct {
    float x;
    float y;
    float z;
} Ov208VecF;

struct Ov208Mdl_021C7CE8 {
    unsigned int obj;
    unsigned int f4;
    Ov208VecF pos[1];
};

extern void ov208_func_021C5F34(void *a0, u8 *p, void *ctx, int ev);
extern void func_021C80CC(void *u, int k, VecF *v);
extern void func_02015C48(void *p, u32 *src);
extern void func_021C50F8(u32 obj, Vec *out);
extern void func_021C7D80(void *a0, u8 *p, void *ctx);
extern void func_021C5CF0(void *a0, u8 *p, void *ctx);
extern void func_021C4E54(void *a0, u8 *p, void *ctx);
extern void func_021C4EAC(void *a0, u8 *p, void *ctx);
extern void ov208_func_021C6A10(void *a0, u8 *p, void *ctx);
extern u16  func_021BC3C0(void *ctx);
extern int func_021BC3A4(int *p);
extern void *func_0200CA1C(void *a);
extern void func_0200CA98(struct Blk37 *p, u16 id, u32 sel, u32 alt, u32 form);
extern void func_021C51A0(char *p, int a);
extern void func_021C51C8(u32, int, u8 *);
extern void ov208_func_021C569C(u16 *, u8 *, int, int, int, int, u16);
extern void func_021C7534(u16 *, u8 *, int);
extern void func_02015C30(void *p, u32 *out);
extern void func_021C5200(int *p);
extern void ov208_func_021C7448(void *a0, u8 *p, void *ctx);
extern void ov208_func_021C80CC(void *u, int k, VecF *v);
extern void func_02014CEC(u8 *p, u32 value);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_021BC518(int *p);
extern void func_021C7FF8(int, int, int);
u16 ov208_func_021C6E60(void *unused, u8 *p, int unused2, u16 skip, u16 want);
void ov208_func_021C6E98(void *a0, u8 *p, void *ctx);
void func_021C7448(u16 *a0, u8 *p, int key);
void ov208_func_021C7534(void *unused, u8 *p);
void ov208_func_021C75FC(void *a0, u8 *p, void *ctx);
void ov208_func_021C7860(void *a0, u8 *p, void *ctx);
void func_021C7CE8(u16 *a0, u8 *p, int key);
void ov208_func_021C7D80(void *unused, struct Ov208Battle *p);
void ov208_func_021C7E74(void *a0, u8 *p);
void ov208_func_021C7EF8(void *a0, u8 *p);
void ov208_func_021C7F6C(VecF *pos, u32 species, u32 form, u32 gender, u32 shiny, u32 personality, u32 side, u32 extra);
void ov208_func_021C7FF8(struct Ov208Mdl_021C7CE8 *m, int i, VecFx32 *out);
void func_021C80AC(int a, int b, int c);
extern s16  tbl_020A1B38[];
extern const VecF data_021C87C0[5];
extern const struct Ov208PoseEnt data_021C8854[15];





u16 ov208_func_021C6E60(void *unused, u8 *p, int unused2, u16 skip, u16 want)
{
    u16 r = 0;
    u16 j = 0;
    u16 i;

    for (i = 0; i < ((struct Obj25527 *)p)->f548; i++) {
        if (i != skip) {
            if (j == want) {
                r = i;
                break;
            }
            j++;
        }
    }
    return r;
}





void ov208_func_021C6E98(void *a0, u8 *p, void *ctx)
{
    Vec u;
    VecF a;
    VecF b;
    Vec v;
    VecF c;
    VecF d;
    Vec w;
    float t;
    float x;
    float y;
    int idx;
    u16 id;
    void *obj;
    u32 f;
    u32 sh;

    if (I(0x6bc) == 1) {
        I(0x6c0) += 0x400;
        if (I(0x6c0) >= 0x8000) {
            I(0x6c0) = 0x8000;
            I(0x6bc) = 0;
            ov208_func_021C5F34(a0, p, ctx, 4);
            if (H(0x548) >= 2) {
                if (W(0x94) != 0) {
                    func_021C80AC((int)(p + 0x94), 1, (int)(&u));
                    func_02015C48((void *)W(0x94), (u32 *)(&u));
                }
                if (W(0xd8) != 0) {
                    func_021C80AC((int)(p + 0xd8), 1, (int)(&u));
                    func_02015C48((void *)W(0xd8), (u32 *)(&u));
                }
                idx = W(0x124) != 0 ? 2 : 3;
                func_021C50F8(*(u32 *)(p + idx * 0x44 + 0xc), &u);
                if (W(0xc) != 0) {
                    func_021C80AC((int)(p + 0xc), 2, (int)(&u));
                    func_02015C48((void *)W(0xc), (u32 *)(&u));
                }
                if (W(0x50) != 0) {
                    func_021C80AC((int)(p + 0x50), 2, (int)(&u));
                    func_02015C48((void *)W(0x50), (u32 *)(&u));
                }
                func_021C7D80(a0, p, ctx);
                func_021C5CF0(a0, p, ctx);
                func_021C4E54(a0, p, ctx);
                func_021C4EAC(a0, p, ctx);
                ov208_func_021C6A10(a0, p, ctx);
                id = func_021BC3C0(ctx);
                obj = func_0200CA1C((void *)func_021BC3A4(ctx));
                f = *(p + H(0x54e) * 16 + 0x152);
                sh = *(p + H(0x54e) * 16 + 0x153) != 0 ? 1 : 0;
                func_0200CA98(obj, id, f, sh, *(u16 *)(p + H(0x54e) * 16 + 0x154));
                if (H(0x548) >= 3)
                    W(0x698) = 1;
            }
        } else {
            t = tbl_020A1B38[(I(0x6c0) >> 4) * 2] / 4096.0f;
            if (W(0xc) != 0) {
                func_021C80CC(p + 0xc, 3, &a);
                func_021C80CC(p + 0xc, 4, &b);
                x = a.x + I(0x6c0) * (b.x - a.x) / 32768.0f;
                y = a.y + 16.0f * t;
                v.x = FX_F32_TO_FX32(x);
                v.y = FX_F32_TO_FX32(y);
                v.z = FX_F32_TO_FX32(a.z);
                func_02015C48((void *)W(0xc), (u32 *)(&v));
            }
            if (W(0x50) != 0) {
                func_021C80CC(p + 0x50, 3, &a);
                func_021C80CC(p + 0x50, 4, &b);
                x = a.x + I(0x6c0) * (b.x - a.x) / 32768.0f;
                y = a.y + 16.0f * t;
                v.x = FX_F32_TO_FX32(x);
                v.y = FX_F32_TO_FX32(y);
                v.z = FX_F32_TO_FX32(a.z);
                func_02015C48((void *)W(0x50), (u32 *)(&v));
            }
            if (W(0x94) != 0) {
                func_021C80CC(p + 0x94, 3, &c);
                func_021C80CC(p + 0x94, 4, &d);
                x = d.x + I(0x6c0) * (c.x - d.x) / 32768.0f;
                y = d.y + -16.0f * t;
                w.x = FX_F32_TO_FX32(x);
                w.y = FX_F32_TO_FX32(y);
                w.z = FX_F32_TO_FX32(d.z);
                func_02015C48((void *)W(0x94), (u32 *)(&w));
            }
            if (W(0xd8) != 0) {
                func_021C80CC(p + 0xd8, 3, &c);
                func_021C80CC(p + 0xd8, 4, &d);
                x = d.x + I(0x6c0) * (c.x - d.x) / 32768.0f;
                y = d.y + -16.0f * t;
                w.x = FX_F32_TO_FX32(x);
                w.y = FX_F32_TO_FX32(y);
                w.z = FX_F32_TO_FX32(d.z);
                func_02015C48((void *)W(0xd8), (u32 *)(&w));
            }
        }
    }
}




void func_021C7448(u16 *a0, u8 *p, int key)
{
    u16 old = ((struct Obj00147 *)p)->f550;
    int a;
    int b;
    if (((struct Obj00147 *)p)->f6C8 == 0) {
        if (((struct Obj00147 *)p)->f548 >= 3) {
            ((struct Obj00147 *)p)->f550 = ((struct Obj00147 *)p)->f54E + ((struct Obj00147 *)p)->f548 - 1;
            ((struct Obj00147 *)p)->f550 = (u32)((struct Obj00147 *)p)->f550 % (u32)((struct Obj00147 *)p)->f548;
        }
    } else {
        if (((struct Obj00147 *)p)->f548 >= 3) {
            ((struct Obj00147 *)p)->f550 = ((struct Obj00147 *)p)->f54E + 1;
            ((struct Obj00147 *)p)->f550 = (u32)((struct Obj00147 *)p)->f550 % (u32)((struct Obj00147 *)p)->f548;
        }
    }
    if ((((struct Obj00147 *)p)->f124 != 0 && *(u32 *)&((struct Obj00147 *)p)->f94 == 0)
        || (((struct Obj00147 *)p)->f124 == 0 && *(u32 *)&((struct Obj00147 *)p)->fD8 == 0)
        || ((struct Obj00147 *)p)->f550 != old) {
        func_021C51A0((char *)(p + 0x94), ((struct Obj00147 *)p)->f8);
        func_021C51A0((char *)(p + 0xD8), ((struct Obj00147 *)p)->f8);
        a = ((struct Obj00147 *)p)->f124 != 0 ? 2 : 4;
        b = ((struct Obj00147 *)p)->f124 != 0 ? 4 : 3;
        ov208_func_021C569C(a0, p, key, a, b, 2, ((struct Obj00147 *)p)->f550);
        if (a != 4) func_021C51C8(((struct Obj00147 *)p)->f98, 2, p);
        if (b != 4) func_021C51C8(((struct Obj00147 *)p)->fDC, 3, p);
    }
    func_021C7534(a0, p, key);
}




void ov208_func_021C7534(void *unused, u8 *p)
{
    VecFx32 v;

    if (((struct Obj03369 *)p)->f6C8 == 0) {
        v.x = -0x40000;
        v.y = -0xde66;
        v.z = 0;
        if (((struct Ov208Mdl_021C6E60 *)(p + 0x94))->obj != 0) {
            ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0x94)), 1, (VecFx32 *)&v);
            func_02015C48((void *)(((struct Ov208Mdl_021C6E60 *)(p + 0x94))->obj), (u32 *)(&v));
        }
        if (((struct Ov208Mdl_021C6E60 *)(p + 0xd8))->obj != 0) {
            ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0xd8)), 1, (VecFx32 *)&v);
            func_02015C48((void *)(((struct Ov208Mdl_021C6E60 *)(p + 0xd8))->obj), (u32 *)(&v));
        }
    } else {
        v.x = 0x40000;
        v.y = -0xde66;
        v.z = 0;
        if (((struct Ov208Mdl_021C6E60 *)(p + 0x94))->obj != 0) {
            ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0x94)), 2, (VecFx32 *)&v);
            func_02015C48((void *)(((struct Ov208Mdl_021C6E60 *)(p + 0x94))->obj), (u32 *)(&v));
        }
        if (((struct Ov208Mdl_021C6E60 *)(p + 0xd8))->obj != 0) {
            ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0xd8)), 2, (VecFx32 *)&v);
            func_02015C48((void *)(((struct Ov208Mdl_021C6E60 *)(p + 0xd8))->obj), (u32 *)(&v));
        }
    }
}




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
                    ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0xc)), 3, (VecFx32 *)&b1);
                    func_02015C48((void *)W(0xc), (u32 *)(&b1));
                }
                if (W(0x50) != 0) {
                    ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0x50)), 3, (VecFx32 *)&b1);
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
                    ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0x94)), 4, (VecFx32 *)&c1);
                    func_02015C48((void *)W(0x94), (u32 *)(&c1));
                }
                if (W(0xd8) != 0) {
                    ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0xd8)), 4, (VecFx32 *)&c1);
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
                    ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0xc)), 0, (VecFx32 *)&b3);
                    func_02015C48((void *)W(0xc), (u32 *)(&b3));
                }
                if (W(0x50) != 0) {
                    ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0x50)), 0, (VecFx32 *)&b3);
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
                    ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0x94)), 2, (VecFx32 *)&c4);
                    func_02015C48((void *)W(0x94), (u32 *)(&c4));
                }
                if (W(0xd8) != 0) {
                    ov208_func_021C7FF8((struct Ov208Mdl_021C7CE8 *)((struct Ov208Mdl_021C6E60 *)(p + 0xd8)), 2, (VecFx32 *)&c4);
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


void func_021C7CE8(u16 *a0, u8 *p, int key)
{
    int a;
    int b;
    if (((struct Obj00147 *)p)->f6B8 != 0) return;
    func_021C51A0((char *)(p + 0x94), ((struct Obj00147 *)p)->f8);
    func_021C51A0((char *)(p + 0xD8), ((struct Obj00147 *)p)->f8);
    func_02014CEC((u8 *)(((struct Obj00147 *)p)->f8), 0);
    a = ((struct Obj00147 *)p)->f124 != 0 ? 2 : 4;
    b = ((struct Obj00147 *)p)->f124 != 0 ? 4 : 3;
    ov208_func_021C569C(a0, p, key, a, b, 2, ((struct Obj00147 *)p)->f550);
    if (a != 4) func_021C51C8(((struct Obj00147 *)p)->f98, 2, p);
    if (b != 4) func_021C51C8(((struct Obj00147 *)p)->fDC, 3, p);
    func_02014CEC((u8 *)(((struct Obj00147 *)p)->f8), ((struct Obj00147 *)p)->f120);
}



void ov208_func_021C7D80(void *unused, struct Ov208Battle *p)
{
    struct Ov208Tri t;
    struct Ov208Tri t2;
    u16 h;
    u32 w;
    u32 *q;
    u8 i;

    h = p->h54e;
    p->h54e = p->h550;
    p->h550 = h;
    w = p->u[0].f0;
    p->u[0].f0 = p->u[2].f0;
    p->u[2].f0 = w;
    q = p->u[0].f4;
    p->u[0].f4 = p->u[2].f4;
    p->u[2].f4 = q;
    if (p->u[0].f4 != 0)
        *p->u[0].f4 = 0;
    if (p->u[2].f4 != 0)
        *p->u[2].f4 = 2;
    w = p->u[1].f0;
    p->u[1].f0 = p->u[3].f0;
    p->u[3].f0 = w;
    q = p->u[1].f4;
    p->u[1].f4 = p->u[3].f4;
    p->u[3].f4 = q;
    if (p->u[1].f4 != 0)
        *p->u[1].f4 = 1;
    if (p->u[3].f4 != 0)
        *p->u[3].f4 = 3;
    for (i = 0; i < 5; i++) {
        t = p->u[0].e[i];
        p->u[0].e[i] = p->u[2].e[i];
        p->u[2].e[i] = t;
        t2 = p->u[1].e[i];
        p->u[1].e[i] = p->u[3].e[i];
        p->u[3].e[i] = t2;
    }
}



void ov208_func_021C7E74(void *a0, u8 *p)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(u32 *)(p + i * 4 + 0x13c) != 0)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0x13c)), 0);
    }
    func_0204B688((struct Actor *)W(0x5e4), 0);
    func_0204B688((struct Actor *)W(0x5e8), 0);
    for (i = 0; i < 4; i++)
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 0x28 + 0x618)), 0);
    func_0207D63C(0x04000050, 0, 0x3f, 0xc, 4);
    func_0207D63C(0x04001050, 8, 0x3f, 0xc, 4);
}



void ov208_func_021C7EF8(void *a0, u8 *p)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(u32 *)(p + i * 4 + 0x13c) != 0)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0x13c)), 1);
    }
    func_0204B688((struct Actor *)W(0x5e4), 1);
    func_0204B688((struct Actor *)W(0x5e8), 1);
    for (i = 0; i < 4; i++)
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 0x28 + 0x618)), 1);
    func_021BC518((int *)W(0x6a4));
    func_021BC518((int *)W(0x6a8));
}



void ov208_func_021C7F6C(VecF *pos, u32 species, u32 form, u32 gender, u32 shiny, u32 personality,
                         u32 side, u32 extra)
{
    u16 k;
    u8 i;

    for (i = 0; i < 5; i++)
        pos[i] = data_021C87C0[i];
    for (k = 0; k < 15; k++) {
        if (species == data_021C8854[k].species && form == data_021C8854[k].form &&
            side == data_021C8854[k].side &&
            (data_021C8854[k].gender == 3 || gender == data_021C8854[k].gender)) {
            for (i = 0; i < 5; i++)
                pos[i] = data_021C8854[k].pos[i];
            return;
        }
    }
}



void ov208_func_021C7FF8(struct Ov208Mdl_021C7CE8 *m, int i, VecFx32 *out)
{
    out->x = FX_F32_TO_FX32(m->pos[i].x);
    out->y = FX_F32_TO_FX32(m->pos[i].y);
    out->z = FX_F32_TO_FX32(m->pos[i].z);
}



void func_021C80AC(int a, int b, int c)
{
    int m = 0;

    switch (b) {
    case 0:
        break;
    case 1:
        m = 3;
        break;
    case 2:
        m = 4;
        break;
    }
    func_021C7FF8(a, m, c);
}
