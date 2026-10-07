/*
 * file:     zukan_detail_form_p13.c
 * unit:     yes
 * function: func_021C6E60, func_021C6E98, func_021C7448
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
 *   func_021C80AC        0x021C80AC  thumb
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
 */
#include "../../matched/include/Obj25527.h"
#include "../../matched/include/Obj00147.h"

#define W(o) (*(u32 *)(p + (o)))
#define I(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
struct Blk37;
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

extern void ov208_func_021C5F34(void *a0, u8 *p, void *ctx, int ev);
extern void func_021C80AC(int a, int b, int c);
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
u16 ov208_func_021C6E60(void *unused, u8 *p, int unused2, u16 skip, u16 want);
void ov208_func_021C6E98(void *a0, u8 *p, void *ctx);
void func_021C7448(u16 *a0, u8 *p, int key);
extern s16  tbl_020A1B38[];


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
