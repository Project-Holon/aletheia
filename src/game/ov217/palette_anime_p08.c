/*
 * file:     palette_anime_p08.c
 * unit:     yes
 * function: func_021C1DE8, func_021C1DF0, func_021C1E00, func_021C1E0C, func_021C1F44, func_021C2070, func_021C209C, func_021C20B4, func_021C20C4, func_021C20CC
 * address:  0x021C1DE8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0E08  0x021C0E08  thumb  ov217
 *   func_021C0E3C  0x021C0E3C  thumb  ov217
 *   cos            0x0209A390  arm
 *   sin            0x0209AA08  arm
 *   _fflt          0x0209BDBC  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   _ffix          0x0209C494  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fgr           0x0209BBB0  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_021C2550  0x021C2550  thumb  ov217
 *   func_021C256C  0x021C256C  thumb  ov217
 *   func_021C25B0  0x021C25B0  thumb  ov217
 *   func_021C25D0  0x021C25D0  thumb  ov217
 *   func_021C2630  0x021C2630  thumb  ov217
 *   func_021C25A8  0x021C25A8  thumb  ov217
 *   func_021C25C4  0x021C25C4  thumb  ov217
 *   func_021C2614  0x021C2614  thumb  ov217
 *   func_021C2288  0x021C2288  thumb  ov217
 *   func_021C20EC  0x021C20EC  thumb  ov217
 *   func_021C218C  0x021C218C  thumb  ov217
 */
#include "../../matched/include/Obj14762.h"

#define FX32_CONST(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    u32 w[3];
    u32 a;
} Rec;

typedef signed short s16;

typedef float f32;

typedef double f64;

typedef signed char s8;

typedef struct { s32 x; s32 y; s32 z; } VecFx32;

extern u32 func_020307B0(void *p);
extern int func_021C0E08(int a0, int a1);
extern void func_021C0E3C(void *p);
extern f64 cos(f64 x);
extern f64 sin(f64 x);
extern void func_0206DF3C(const VecFx32 *pos, s32 *px, s32 *py);
extern u32 func_021C2550(u32 a0);
extern u32 func_021C256C();
extern void func_021C25B0(u8 *p);
extern void func_021C25D0(u8 *p);
extern void func_021C2630(char *p, char *q);
extern u32 func_021C25A8(void *a0);
extern void func_021C25C4(u8 *a0);
extern void func_021C2614(char *p);
extern void func_021C2288(u8 *p, int a, int b, int c, int d);
extern void func_021C20EC(void *p);
extern void func_021C218C(void *p, u32 v);
u32 func_021C1DE8(void *a0);
void func_021C1DF0(char *p);
void func_021C1E00(Rec *p);
void func_021C1E0C(u8 *p);
void func_021C1F44(const s16 *p, s32 *px, s32 *py);
u32 func_021C2070(u32 a0, u32 a1);
u32 func_021C209C(void *a0);
void func_021C20B4(int a0, int a1, int a2, int a3, int a4);
void func_021C20C4(void *p);
void func_021C20CC(u32 a0);


/*
 * Tail-call veneer: branch to func_020307B0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C1DE8(void *a0)
{
    return func_020307B0(a0);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C1DF0(char *p)
{
    ((struct Obj14762 *)p)->fC = func_021C0E08(0xa, ((struct Obj14762 *)p)->f0);
}


/*
 * Tail-call veneer with one argument load: passes the word at offset 0xc on
 * to func_021C0E3C.  Reached from func_021C1D74's veneer.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1E00(Rec *p)
{
    func_021C0E3C((void *)p->a);
}


/*
 * 100 points on a circle of radius r = (p+0x1b0)/4096, stored as FX32 s16
 * triples at p+0x1ba+6i. The base offset 0x1b0 is a local (o + 0xa, o + 0xc,
 * o + 0xe stay as spilled runtime adds); the first converted value goes through
 * a local so its _ffix call comes before the p + i*6 address.
 */
void func_021C1E0C(u8 *p)
{
    s32 i;
    f32 r;
    s32 o = 0x1b0;
    r = *(s32 *)(p + o) / 4096.0f;
    for (i = 0; i < 100; i++) {
        f32 t = 1.5707964f - (6.2831855f * (f32)i) / 100.0f;
        f32 x = r * (f32)cos((f64)t);
        f32 y = r * (f32)sin((f64)t);
        f32 z = 0.0f;
        s32 v = FX32_CONST(x);
        *(s16 *)(p + i * 6 + (o + 0xa)) = v;
        *(s16 *)(p + i * 6 + (o + 0xc)) = FX32_CONST(y);
        *(s16 *)(p + i * 6 + (o + 0xe)) = FX32_CONST(z);
    }
}


void func_021C1F44(const s16 *p, s32 *px, s32 *py)
{
    VecFx32 v;
    v.x = FX32_CONST(FX_FX32_TO_F32(p[0]));
    v.y = FX32_CONST(FX_FX32_TO_F32(p[1]));
    v.z = FX32_CONST(FX_FX32_TO_F32(p[2]));
    func_0206DF3C(&v, px, py);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2070(u32 a0, u32 a1)
{
    u32 v1 = func_021C2550(a0);
    func_021C256C(v1, a0);
    func_021C2630((char *)v1, (char *)a1);
    func_021C25B0((u8 *)v1);
    func_021C25D0((u8 *)v1);
    return v1;
}

u32 func_021C209C(void *a0)
{
    func_021C2614((char *)a0);
    func_021C25C4((u8 *)a0);
    return func_021C25A8(a0);
}


/*
 * Forwarding wrapper: passes a fifth (stack) argument through.
 *
 * Addresses are Black-image addresses.
 */
void func_021C20B4(int a0, int a1, int a2, int a3, int a4)
{
    func_021C2288((u8 *)a0, a1, a2, a3, a4);
}


/*
 * Tail-call veneer: branch to func_021C20EC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C20C4(void *p)
{
    func_021C20EC(p);
}


/*
 * Tail-call veneer: forwards arg(s) a0, 1 to func_021C218C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C20CC(u32 a0)
{
    func_021C218C((void *)a0, 1);
}
