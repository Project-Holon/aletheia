/*
 * file:     field_flash_p03.c
 * unit:     yes
 * function: func_021C6F00, func_021C6F30, func_021C701C, func_021C7058, func_021C7094
 * address:  0x021C6F00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb
 *   func_0218ED54  0x0218ED54  thumb
 *   func_0218E138  0x0218E138  thumb
 *   func_0218E13C  0x0218E13C  thumb
 *   func_0218ED58  0x0218ED58  thumb
 *   _fgr           0x0209BBB0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 *   func_021C71A4  0x021C71A4  thumb  ov021
 *   func_0218ED40  0x0218ED40  thumb  ov021
 *   func_0218ED2C  0x0218ED2C  thumb  ov021
 */
#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Q Q;

typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;

typedef struct { u32 f0; u8 f4; u8 f5; u16 f6; u16 f8; u16 fA; u32 fC; u32 f10; } W_021C6F00;

typedef int s32;

typedef int fx32;

typedef float f32;

typedef struct {
    void *f0;
    u8 f4;
    u8 pad5;
    u16 f6;
    u16 f8;
    u16 padA;
    fx32 fC;
    fx32 f10;
} Work;

typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; u32 f14; u32 f18; } W_021C701C;

typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; u32 f14; u32 f18; } W_021C7058;

extern u16 func_02188C84(u8 *p);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern u32 func_021C6CCC(u8 *p);
extern void *func_02188C58(void *o);
extern u32 func_0218ED54(u8 *p);
extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0218ED58(u8 *p, u32 v);
extern int func_021C71A4(W_021C701C *w);
extern u16 func_0218ED40(u8 *p);
extern u16 func_0218ED2C(u8 *p);
Q *func_021C6F00(u32 a, u16 b, u32 c);
int func_021C6F30(Work *w);
Q *func_021C701C(u32 a, u16 b, u32 c);
Q *func_021C7058(u32 a, u16 b, u32 c);
void func_021C7094(u32 *p);

Q *func_021C6F00(u32 a, u16 b, u32 c)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x14, func_021C6F30);
    W_021C6F00 *w = (W_021C6F00 *)func_021C6CCC((u8 *)q);
    w->f4 = 0;
    w->f0 = a;
    w->f6 = 0;
    w->f8 = b;
    w->f10 = c;
    return q;
}


int func_021C6F30(Work *w)
{
    void *o;
    u32 save;
    f32 t;
    f32 a;
    f32 b;
    f32 v;

    o = func_02188C58(w->f0);
    switch (w->f4) {
    case 0:
        w->fC = func_0218ED54(o);
        w->f4++;
        break;
    case 1:
        w->f6++;
        save = func_0218E138(o);
        func_0218E13C(o, 0);
        t = (f32)w->f6 / (f32)w->f8;
        a = FX_FX32_TO_F32(w->fC);
        b = FX_FX32_TO_F32(w->f10);
        v = (1.0f - t) * a + t * b;
        func_0218ED58(o, FX_F32_TO_FX32(v));
        func_0218E13C(o, save);
        if (w->f8 <= w->f6)
            return 1;
        break;
    }
    return 0;
}

Q *func_021C701C(u32 a, u16 b, u32 c)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x1c, func_021C71A4);
    W_021C701C *w = (W_021C701C *)func_021C6CCC((u8 *)q);
    w->f0 = a;
    w->f4 = (u32)func_02188C58((void *)a);
    w->fC = 0;
    w->f8 = 0;
    w->fE = 0;
    w->f10 = b;
    w->f18 = c;
    return q;
}

Q *func_021C7058(u32 a, u16 b, u32 c)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x1c, func_021C71A4);
    W_021C7058 *w = (W_021C7058 *)func_021C6CCC((u8 *)q);
    w->f0 = a;
    w->f4 = (u32)func_02188C58((void *)a);
    w->fC = 0;
    w->f8 = 1;
    w->fE = 0;
    w->f10 = b;
    w->f18 = c;
    return q;
}


void func_021C7094(u32 *p)
{
    u32 m = p[2];
    u32 a = p[1];
    u32 b = p[6];
    u32 d;

    if (m == 0 || m != 1)
        a = func_0218ED40((u8 *)a);
    else
        a = func_0218ED2C((u8 *)a);
    if (a < b) {
        d = b - a;
        if (d > 0x8000)
            a += 0x10000;
    } else if (b < a) {
        d = a - b;
        if (d > 0x8000)
            b += 0x10000;
    }
    p[5] = a;
    p[6] = b;
}
