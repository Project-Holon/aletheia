/*
 * file:     field_flash_p01.c
 * unit:     yes
 * function: func_021C6E5C, func_021C6E74, func_021C6E94, func_021C6EA8, func_021C6EDC, func_021C6F00, func_021C6F30, func_021C701C, func_021C7058, func_021C7094, func_021C70DC, func_021C71A4, func_021C71D4, func_021C7220, func_021C7260, func_021C72AC, func_021C72F8, func_021C734C, func_021C73B4, func_021C7418, func_021C748C, func_021C7500, func_021C754C, func_021C7584, func_021C7684, func_021C76C4, func_021C7730, func_021C77D8, func_021C7814, func_021C7844, func_021C7858, func_021C7878, func_021C78DC, func_021C7940, func_021C7A20, func_021C7A7C, func_021C7AE4, func_021C7B1C, func_021C7C10, func_021C7C74, func_021C7D28, func_021C7D78, func_021C7DAC, func_021C7DE0, func_021C7DFC, func_021C7E30, func_021C7E50, func_021C7E54, func_021C7E58, func_021C7E64, func_021C7E70, func_021C7E90, func_021C7EEC, func_021C7EF0, func_021C7EF4, func_021C7EF8, func_021C7EFC, func_021C7F18, func_021C7F44, func_021C7F70, func_021C7F9C, func_021C7FAC
 * address:  0x021C6E5C
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
 *   func_021C6CA8  0x021C6CA8  thumb  ov021
 *   func_021C6CBC  0x021C6CBC  thumb  ov021
 *   func_021C6CC4  0x021C6CC4  thumb  ov021
 *   func_021C6CE0  0x021C6CE0  thumb  ov021
 *   func_021C6CD0  0x021C6CD0  thumb  ov021
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
 *   func_0218ED40  0x0218ED40  thumb  ov021
 *   func_0218ED2C  0x0218ED2C  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   _ffixu         0x0209C4C8  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   d_021DAAC0  0x021DAAC0  data  ov021  a2
 *   d_021DAAB8  0x021DAAB8  data  ov021  a2
 *   d_021DAAC8     0x021DAAC8  data  ov021  a2
 *   func_0209C5E0  0x0209C5E0  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02164010  0x02164010  thumb  ov010
 *   func_020520A4  0x020520A4  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   _ll_mul        0x0209C054  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0207CEE4  0x0207CEE4  arm
 *   func_021ADD7C  0x021ADD7C  thumb  ov021
 *   d_021DE4FC  0x021DE4FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021C8018  0x021C8018  thumb  ov021
 *   func_021C8054  0x021C8054  thumb  ov021
 *   d_021DAAD0  0x021DAAD0  data  ov021  a4
 *   func_021C8078  0x021C8078  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_0207C768  0x0207C768  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021DE50C  0x021DE50C  data  ov021  a4
 *   func_021C7FC0  0x021C7FC0  thumb  ov021
 *   func_021C7FF0  0x021C7FF0  thumb  ov021
 *   func_021C8000  0x021C8000  thumb  ov021
 */
#include "../../matched/include/Obj05086.h"
#include "../../matched/include/Obj05087.h"
#include "../../matched/include/Obj05088.h"
#include "../../matched/include/Obj05089.h"
#include "../../matched/include/Obj07232.h"
#include "../../matched/include/Obj18324.h"
#include "../../matched/include/Obj03529.h"
#include "../../matched/include/Obj18326.h"
#include "../../matched/include/Obj18327.h"
#include "../../matched/include/Obj18328.h"
#include "../../matched/include/Obj18329.h"
#include "../../matched/include/Obj18330.h"

#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
#define FX32_ONE 0x1000
struct Obj00020;
struct Vec3;
struct Actor;
struct VecFx32_021C7878;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Q Q;

typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;

typedef struct { u32 f0; u8 f4; u8 f5; u16 f6; u16 f8; u16 fA; u32 fC; u32 f10; } W_021C6F00;

typedef int s32_021C6E5C;

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
} Work_021C6E94;

typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; u32 f14; u32 f18; } W_021C701C;

typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; u32 f14; u32 f18; } W_021C7058;

typedef struct {
    u32 w0;
    void *obj;
    u32 mode;
    u16 hc;
    u16 cnt;
    u16 max;
    u16 pad;
    u32 from;
    u32 to;
} Work_021C70DC;

typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; u32 f14; u32 f18; } W_021C6E5C;

typedef struct { u16 v[4]; } T4;

typedef struct {
    u32 w0;
    u32 w4;
    u16 h8;
    u16 ha;
    u8  bc;
    u8  pad;
    u16 he;
} Ctl;

typedef struct { u32 x, y, z; } V;

typedef struct { u8 f0; u32 f4; u32 f8; u32 fC; u8 pad[0xc]; V f1C; } X;

typedef signed int     s32_021C7500;

typedef struct VecFx32_021C6E5C { s32_021C7500 x; s32_021C7500 y; s32_021C7500 z; } VecFx32_021C6E5C;

typedef struct {
    u8 state;
    u8 pad[3];
    void *id;
    int cnt;
    int max;
    VecFx32_021C6E5C from;
    VecFx32_021C6E5C to;
} Work_021C6E5C;

typedef struct {
    u8    st;
    u32   w4;
    u16   h8;
    u16   ha;
    float fc;
    u32   w10;
} Fx;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec_021C7500;

typedef struct {
    int x;
    int y;
    int z;
} Vec_021C7730;

typedef struct { u16 f0; u16 f2; } X_021C77D8;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; } X_021C7814;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } Vec;

typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    int f8;
    u16 fC;
    u16 fE;
    Vec f10;
    int f1C[3];
    int f28;
} Obj_021C6E5C;

typedef signed int     s32;

typedef struct VecFx32_021C7878 { s32 x; s32 y; s32 z; } VecFx32_021C7878;

typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    int f8;
    u16 fC;
    u16 fE;
    Vec f10;
    Vec f1C;
    int f28;
} Obj_021C7A20;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct {
    u8 state;
    u8 pad[3];
    void *id;
    int cnt;
    int max;
    VecFx32 from;
    VecFx32 to;
} Work_021C7A20;

typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    u16 f8;
    u16 fA;
    Vec fC;
    Vec f18;
    Vec f24;
    int f30;
} Obj;

typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    u16 f8;
    u16 fA;
    Vec fC;
    Vec f18;
    Vec f24;
    int f30;
} Obj_021C7C74;

typedef struct {
    int f0;
    int f4;
    void *f8;
    u8 fC;
    u8 padD;
    u16 fE;
    u16 f10;
    u16 f12;
} Obj_021C7D28;

typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; } W_021C7D78;

typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;

typedef struct Obj_021C7D78 {
    u8 pad00[0x1C];
    u16 f1c;            /* 0x1C */
} Obj_021C7D78;

typedef short s16_021C7E90;

typedef struct {
    int f0;
    u8 f4;
    u8 pad5;
    u16 f6;
    u16 f8;
    u8 padA[2];
    int fC;
    int f10;
    s16_021C7E90 f14;
    s16_021C7E90 f16;
} Obj_021C7E90;

typedef signed short   s16_021C7EFC;

extern void func_021C6CA8(Q *q);
extern void func_021C6CBC(void);
extern u32 func_021C6CE0(u8 *p);
extern void func_021C6CC4(u32 *a0);
extern int func_021C6CD0(u32 a);
extern u16 func_02188C84(u8 *p);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern u32 func_021C6CCC(u8 *p);
extern void *func_02188C58(void *o);
extern u32 func_0218ED54(u8 *p);
extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0218ED58(u8 *p, u32 v);
extern u16 func_0218ED40(u8 *p);
extern u16 func_0218ED2C(u8 *p);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *);
extern u16 func_0216D5F8(void *a);
extern double func_0209C5E0(double x);
extern void func_0216D410(u32 a, int b);
extern void func_0216D5E0(int a0, int a1);
extern void func_021A3038(unsigned char *, struct VecFx32_021C6E5C *);
extern void func_021A3044(u8 *p, void *v);
extern int func_02164010(int a);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *dst);
extern void func_0207C9D0(const VecFx32_021C6E5C *a, const VecFx32_021C6E5C *b, VecFx32_021C6E5C *c);
extern u32 func_02188CD0(u8 *p);
extern void func_0216D8C0(u32 a, Vec_021C7730 *v);
extern void func_021AC528(u32 a, u32 b);
extern void func_020061E4(u32 a);
extern void func_0204E720(u32 a, s32_021C7500 b, s32_021C7500 c, s32_021C7500 d);
extern void func_0216D88C(const struct Actor *, struct VecFx32_021C7878 *);
extern void func_0216D89C(int, Vec *);
extern void func_0218ECC4(void *o, VecFx32 *out);
extern void func_0218ECD4(void *o, VecFx32 *v);
extern void func_0207CA00(Vec *, Vec *, Vec *);
extern void func_0218EC90(int, Vec *);
extern void func_0207CEE4(int, Vec *, Vec *, Vec *);
extern void func_021ADD7C(int a, int b);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_021C8018(u32);
extern int func_021C8054(void *a);
extern void func_021C8078(u32 h, u32 a, u32 b);
extern void func_02082BCC(void *, int, int);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_021C7FC0(M **pp, u32 flags, u32 heap);
extern void func_021C7FF0(void *p);
extern void func_021C8000(u8 *p);
void func_021C6E5C(R *r, int i, Q *q, u32 v);
void func_021C6E74(R *r, int i);
void func_021C6E94(R *r, int i);
void func_021C6EA8(R *r, int i);
void func_021C6EDC(R *r, int i);
Q *func_021C6F00(u32 a, u16 b, u32 c);
int func_021C6F30(Work_021C6E94 *w);
Q *func_021C701C(u32 a, u16 b, u32 c);
Q *func_021C7058(u32 a, u16 b, u32 c);
void func_021C7094(u32 *p);
void func_021C70DC(Work_021C70DC *w);
int func_021C71A4(W_021C6E5C *w);
void *func_021C71D4(u32 a, u32 b, u32 c);
void *func_021C7220(u32 a, u16 b, int c, u32 d);
void *func_021C7260(u32 a, u16 b, int c);
void *func_021C72AC(u32 a, u16 b, int c, int d);
u16 func_021C72F8(float a, float b, float c);
u16 func_021C734C(float a, float b, float c);
u16 func_021C73B4(float a, float b, float c);
int func_021C7418(Ctl *o);
int func_021C748C(Ctl *o);
int func_021C7500(Ctl *o);
Q *func_021C754C(u32 a, u32 b, V *v);
int func_021C7584(Work_021C6E5C *w);
void *func_021C7684(u32 a, u32 b, int c, int d);
void func_021C76C4(Vec_021C7500 *out, float a, float b, float c);
int func_021C7730(Fx *o);
Q *func_021C77D8(u32 a, u16 b);
int func_021C77FC(X_021C77D8 *x);
Q *func_021C7814(u32 a, u32 b, u32 c, u32 d, u32 e);
int func_021C7844(u32 a, u32 b, u32 c);
int func_021C7858(u32 a, u32 b, u32 c);
int func_021C7878(int a, int b, const Vec *c, int d);
int func_021C78DC(int a, int b, const Vec *c, int d);
void func_021C7940(Vec *out, u16 cnt, Vec *v, u16 max);
int func_021C7A20(Obj_021C7A20 *p);
int func_021C7A7C(Obj_021C7A20 *p);
Q *func_021C7AE4(u32 a, u32 b, const V *v);
int func_021C7B1C(Work_021C7A20 *w);
int func_021C7C10(int a, int b, const Vec *c, const Vec *d);
int func_021C7C74(Obj_021C7C74 *p);
int func_021C7D28(int a, int b, u16 c, u16 d);
int func_021C7D78(W_021C7D78 *w);
M *func_021C7DAC(u32 heap);
void func_021C7DE0(M *m);
void func_021C7DFC(M *m);
void func_021C7E30(M *m);
void func_021C7E50(u8 *p, u16 v);
u16 func_021C7E54(Obj_021C7D78 *p);
void func_021C7E58(u32 a);
void func_021C7E64(u32 a);
int func_021C7E70(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1);
int func_021C7E90(Obj_021C7E90 *p);
u32 func_021C7EEC(u8 *p);
void func_021C7EF0(u8 *p, u32 v);
u8 func_021C7EF4(u8 *p);
u8 *func_021C7EF8(u8 *p, u8 v);
int func_021C7EFC(u32 a, u32 b, u32 c, u32 d);
void func_021C7F18(M *m);
void func_021C7F44(M *m);
void func_021C7F5C(M *m);
M **func_021C7F70(u32 flags, u32 heap);
void func_021C7F9C(u8 *p);
void func_021C7FAC(u32 a);
extern T4 d_021DAAC0;
extern T4 d_021DAAB8;
extern T4 d_021DAAC8;
extern char d_021DE4FC[];
extern char d_021DE50C[];






#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))








void func_021C6E5C(R *r, int i, Q *q, u32 v)
{
    if (r->f4[i] == 0) {
        r->f4[i] = q;
        r->f8[i] = v;
    }
}








void func_021C6E74(R *r, int i){
    if (r->f4[i] != 0) {
        func_021C6CA8(r->f4[i]);
        r->f4[i] = 0;
        r->f8[i] = 0;
    }
}














void func_021C6E94(R *r, int i)
{
    if (r->f4[i] != 0)
        func_021C6CBC();
}














void func_021C6EA8(R *r, int i)
{
    if (r->f4[i] != 0 && r->f8[i] != 0) {
        if (func_021C6CE0((u8 *)r->f4[i]) == 0 && func_021C6CE0((u8 *)r->f8[i]) == 2)
            func_021C6CC4((u32 *)r->f4[i]);
    }
}














void func_021C6EDC(R *r, int i)
{
    if (r->f4[i] != 0 && func_021C6CD0((u32)r->f4[i]) == 1)
        func_021C6E74(r, i);
}














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















int func_021C6F30(Work_021C6E94 *w)
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













void func_021C70DC(Work_021C70DC *w)
{
    u16 max;
    void *o;
    f32 t;
    f32 s;
    u16 v;
    u32 save;

    max = w->max;
    o = w->obj;
    w->cnt++;
    if (w->cnt > max)
        return;
    t = (f32)w->cnt / (f32)max;
    s = (3.0f + -2.0f * t) * (t * t);
    v = (u16)((1.0f - s) * (f32)w->from + s * (f32)w->to);
    save = func_0218E138(o);
    func_0218E13C(o, 0);
    switch (w->mode) {
    case 0:
        func_0218ED48(o, v);
        break;
    case 1:
        func_0218ED34(o, v);
        break;
    }
    func_0218E13C(o, save);
}











int func_021C71A4(W_021C6E5C *w)
{
    switch (w->fC) {
    case 0:
        func_021C7094((u32 *)w);
        w->fC++;
        break;
    case 1:
        func_021C70DC((Work_021C70DC *)w);
        if (w->f10 <= w->fE)
            return 1;
        break;
    }
    return 0;
}












/*
 * Addresses are Black-image addresses.
 */
void *func_021C71D4(u32 a, u32 b, u32 c)
{
    u32 heap = func_02188C84((u8 *)a);
    void *x = func_02188CB4((void *)a);
    void *r = func_021C6C70(heap, 0x10, (void *)func_021C7418);
    u8 *e = (u8 *)func_021C6CCC(r);
    void *t;

    ((struct Obj05086 *)e)->f0 = a;
    t = func_021A3074((void *)x);
    ((struct Obj05086 *)e)->f4 = t;
    ((struct Obj05086 *)e)->f8 = 0;
    ((struct Obj05086 *)e)->fA = b;
    e[12] = c;
    ((struct Obj05086 *)e)->fE = func_0216D5F8(t);
    return r;
}












void *func_021C7220(u32 a, u16 b, int c, u32 d)
{
    void *o;
    u8 *p;

    o = func_021C6C70(func_02188C84((u8 *)a), 0x10, (void *)func_021C7418);
    p = (u8 *)func_021C6CCC(o);
    ((struct Obj05087 *)p)->f0 = a;
    ((struct Obj05087 *)p)->f4 = d;
    ((struct Obj05087 *)p)->f8 = 0;
    ((struct Obj05087 *)p)->fA = b;
    p[0xc] = c;
    ((struct Obj05087 *)p)->fE = func_0216D5F8((void *)d);
    return o;
}












void *func_021C7260(u32 a, u16 b, int c)
{
    void *o;
    u8 *p;
    u32 h;
    void *q;
    void *t;

    h = func_02188C84((u8 *)a);
    q = func_02188CB4((void *)a);
    o = func_021C6C70(h, 0x10, (void *)func_021C748C);
    p = (u8 *)func_021C6CCC(o);
    ((struct Obj05088 *)p)->f0 = a;
    t = func_021A3074((void *)q);
    ((struct Obj05088 *)p)->f4 = t;
    ((struct Obj05088 *)p)->f8 = 0;
    ((struct Obj05088 *)p)->fA = b;
    p[0xc] = c;
    ((struct Obj05088 *)p)->fE = func_0216D5F8(t);
    return o;
}











void *func_021C72AC(u32 a, u16 b, int c, int d)
{
    void *o;
    u8 *p;
    u32 h;
    void *q;

    h = func_02188C84((u8 *)a);
    q = func_02188CB4((void *)a);
    o = func_021C6C70(h, 0x10, (void *)func_021C7500);
    p = (u8 *)func_021C6CCC(o);
    ((struct Obj05089 *)p)->f0 = a;
    ((struct Obj05089 *)p)->f4 = func_021A3074((void *)q);
    ((struct Obj05089 *)p)->f8 = 0;
    ((struct Obj05089 *)p)->fA = b;
    p[0xc] = c;
    ((struct Obj05089 *)p)->fE = d;
    return o;
}











/*
 * Picks one of four halfwords from a table by (int)(4*c/b*a) % 4, in soft float.
 * The last multiply keeps its operand order only through a named float local;
 * inline it and the compiler swaps to a * f.
 */
u16 func_021C72F8(float a, float b, float c)
{
    T4 t = d_021DAAC0;
    float f = 4.0f * c / b;
    int n = (int)(f * a);

    return t.v[n % 4];
}











u16 func_021C734C(float a, float b, float c)
{
    T4 t = d_021DAAB8;
    float f = 4.0f * c / (b * b);
    float g = f * a;
    int n = (int)(a * g);

    return t.v[n % 4];
}











u16 func_021C73B4(float a, float b, float c)
{
    T4 t = d_021DAAC8;
    float x = 4.0f * c;
    float f = x * x / b;
    int n = (int)(float)func_0209C5E0((double)(f * a));

    return t.v[n % 4];
}











int func_021C7418(Ctl *o)
{
    u32 s;
    int k;

    s = o->w4;
    func_0216D410(s,func_021C72F8((float)(u32)o->h8, (float)(u32)o->ha, (float)(u32)o->bc));
    o->h8 = o->h8 + 1;
    if (o->ha < o->h8) {
        switch (o->he) {
        default:
        case 0: k = 0; break;
        case 1: k = 1; break;
        case 2: k = 2; break;
        case 3: k = 3; break;
        }
        func_0216D410(s, k);
        return 1;
    }
    return 0;
}









int func_021C748C(Ctl *o)
{
    u32 s;
    int k;

    s = o->w4;
    func_0216D410(s, func_021C734C((float)(u32)o->h8, (float)(u32)o->ha, (float)(u32)o->bc));
    o->h8 = o->h8 + 1;
    if (o->ha < o->h8) {
        switch (o->he) {
        default:
        case 0: k = 0; break;
        case 1: k = 1; break;
        case 2: k = 2; break;
        case 3: k = 3; break;
        }
        func_0216D410(s, k);
        return 1;
    }
    return 0;
}






#undef FX_F32_TO_FX32





#undef FX_F32_TO_FX32




#undef FX_F32_TO_FX32



#undef FX_F32_TO_FX32


#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32




#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))












int func_021C7500(Ctl *o){
    u32 s;

    s = o->w4;
    func_0216D410((u32)((void *)s), func_021C73B4((float)(u32)o->h8, (float)(u32)o->ha, (float)(u32)o->bc));
    o->h8 = o->h8 + 1;
    if (o->ha < o->h8) {
        func_0216D5E0(s, o->he);
        return 1;
    }
    return 0;
}












static inline void set3(V *d, u32 x, u32 y, u32 z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}












Q *func_021C754C(u32 a, u32 b, V *v)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x28, func_021C7584);
    X *x = (X *)func_021C6CCC((u8 *)q);
    x->f0 = 0;
    x->f4 = a;
    x->f8 = 0;
    x->fC = b;
    set3(&x->f1C, v->x, v->y, v->z);
    return q;
}













int func_021C7584(Work_021C6E5C *w)
{
    void *o;
    void *m;
    fx32 t;
    VecFx32_021C6E5C a;
    VecFx32_021C6E5C b;
    VecFx32_021C6E5C c;

    o = func_02188CB4(w->id);
    m = func_021A3074(o);
    switch (w->state) {
    case 0:
        func_021A3038(o, (struct VecFx32_021C6E5C *)(&w->from));
        w->state++;
        break;
    case 1:
        w->cnt++;
        t = FX_F32_TO_FX32((f32)w->cnt / (f32)w->max);
        func_020520A4((const struct Vec3 *)(&w->from), FX32_ONE - t, (struct Vec3 *)(&a));
        func_020520A4((const struct Vec3 *)(&w->to), t, (struct Vec3 *)(&b));
        func_0207C9D0((const VecFx32_021C6E5C *)&a, (const VecFx32_021C6E5C *)&b, (VecFx32_021C6E5C *)&c);
        func_021A3044(o, &c);
        func_02164010((int)m);
        if (w->max <= w->cnt)
            return 1;
        break;
    }
    return 0;
}













void *func_021C7684(u32 a, u32 b, int c, int d)
{
    void *o;
    Fx *p;

    o = func_021C6C70(func_02188C84((u8 *)a), 0x14, (void *)func_021C7730);
    p = (Fx *)func_021C6CCC(o);
    p->st = 0;
    p->w4 = a;
    p->h8 = 0;
    p->ha = c;
    p->fc = (float)d;
    p->w10 = b;
    return o;
}










#undef FX_F32_TO_FX32









#undef FX_F32_TO_FX32








#undef FX_F32_TO_FX32







#undef FX_F32_TO_FX32






#undef FX_F32_TO_FX32





#undef FX_F32_TO_FX32




#undef FX_F32_TO_FX32



#undef FX_F32_TO_FX32


#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))











void func_021C76C4(Vec_021C7500 *out, float a, float b, float c)
{
    float y = c / (b * b);
    float z = y * a;
    float v = c - a * z;

    out->x = 0;
    out->y = FX_F32_TO_FX32(v);
    out->z = 0;
}










int func_021C7730(Fx *o)
{
    Vec_021C7730 v;
    u32 s;

    func_02188CB4((struct Obj00020 *)o->w4);
    s = o->w10;
    switch (o->st) {
    case 0:
        func_021C76C4((Vec_021C7500 *)(&v), (float)(u32)o->h8, (float)(u32)o->ha, o->fc);
        func_0216D8C0(s, &v);
        func_020061E4(0x681);
        o->st = o->st + 1;
        break;
    case 1:
        o->h8 = o->h8 + 1;
        func_021C76C4((Vec_021C7500 *)(&v), (float)(u32)o->h8, (float)(u32)o->ha, o->fc);
        func_0216D8C0(s, &v);
        if (o->ha <= o->h8) {
            func_021AC528(s, func_02188CD0((u8 *)o->w4));
            func_020061E4(0x682);
            return 1;
        }
        break;
    }
    return 0;
}









Q *func_021C77D8(u32 a, u16 b)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 4, func_021C77FC);
    X_021C77D8 *x = (X_021C77D8 *)func_021C6CCC((u8 *)q);
    x->f0 = 0;
    x->f2 = b;
    return q;
}










int func_021C77FC(X_021C77D8 *x)
{
    x->f0++;
    if (x->f2 <= x->f0)
        return 1;
    return 0;
}









Q *func_021C7814(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x14, func_021C7844);
    X_021C7814 *x = (X_021C7814 *)func_021C6CCC((u8 *)q);
    x->f0 = a;
    x->f4 = b;
    x->f8 = c;
    x->fC = d;
    x->f10 = e;
    return q;
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C7844(u32 a, u32 b, u32 c)
{
func_0204E720(((struct Obj07232 *)((u8 *)(a)))->f4, ((struct Obj07232 *)((u8 *)(a)))->f8, ((struct Obj07232 *)((u8 *)(a)))->fC, ((struct Obj07232 *)((u8 *)(a)))->f10);
return 1;
}








int func_021C7858(u32 a, u32 b, u32 c)
{
return func_021C7878(a, b, (const Vec *)c, (int)(func_021A3074(func_02188CB4((struct Obj00020 *)a))));
}





#undef FX_F32_TO_FX32




#undef FX_F32_TO_FX32



#undef FX_F32_TO_FX32


#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))








/* The Vec copy is a VEC_Set-style inline setter: its arguments are
 * evaluated right to left, which is what puts y in r1 and z in r2
 * (three plain field copies swap them; a struct assignment is ldm/stm). */
static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}








int func_021C7878(int a, int b, const Vec *c, int d)
{
    Obj_021C6E5C *o;
    int h;

    h = (int)func_021C6C70(func_02188C84((u8 *)a), 0x2c, func_021C7A20);
    o = (Obj_021C6E5C *)func_021C6CCC((u8 *)h);
    o->f0 = 0;
    o->f4 = a;
    o->f28 = d;
    func_0216D88C((const struct Actor *)d, (struct VecFx32_021C7878 *)o->f1C);
    if (b >= 0) {
        o->f8 = 0;
        o->fC = 0;
        o->fE = b;
    } else {
        o->f8 = 1;
        o->fC = 0;
        o->fE = -b;
    }
    vset(&o->f10, c->x, c->y, c->z);
    return h;
}








int func_021C78DC(int a, int b, const Vec *c, int d)
{
    Obj_021C6E5C *o;
    int h;

    h = (int)func_021C6C70(func_02188C84((u8 *)a), 0x2c, func_021C7A7C);
    o = (Obj_021C6E5C *)func_021C6CCC((u8 *)h);
    o->f0 = 0;
    o->f4 = a;
    o->f28 = d;
    func_0216D88C((const struct Actor *)d, (struct VecFx32_021C7878 *)o->f1C);
    if (b >= 0) {
        o->f8 = 0;
        o->fC = 0;
        o->fE = b;
    } else {
        o->f8 = 1;
        o->fC = 0;
        o->fE = -b;
    }
    vset(&o->f10, c->x, c->y, c->z);
    return h;
}







void func_021C7940(Vec *out, u16 cnt, Vec *v, u16 max){
    fx32 t;

    t = FX_F32_TO_FX32((f32)cnt / (f32)max);
    out->x = (fx32)(((long long)v->x * t + 0x800) >> 12);
    out->y = (fx32)(((long long)v->y * t + 0x800) >> 12);
    out->z = (fx32)(((long long)v->z * t + 0x800) >> 12);
}




#undef FX_F32_TO_FX32



#undef FX_F32_TO_FX32


#undef FX_F32_TO_FX32

#undef FX_F32_TO_FX32
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))







int func_021C7A20(Obj_021C7A20 *p)
{
    int h = p->f28;
    Vec v;

    if (p->f0 == 0) {
        p->fC = p->fC + 1;
        if (p->f8 == 0) {
            func_021C7940(&v, p->fC, &p->f10, p->fE);
        } else if (p->f8 == 1) {
            func_021C7940(&v, p->fE - p->fC, &p->f10, p->fE);
        }
        func_0216D8C0(h, (Vec_021C7730 *)&v);
        if (p->fE <= p->fC) {
            return 1;
        }
    }
    return 0;
}







int func_021C7A7C(Obj_021C7A20 *p)
{
    int h = p->f28;
    Vec v;

    if (p->f0 == 0) {
        p->fC = p->fC + 1;
        if (p->f8 == 0) {
            func_021C7940(&v, p->fC, &p->f10, p->fE);
        } else if (p->f8 == 1) {
            func_021C7940(&v, p->fE - p->fC, &p->f10, p->fE);
        }
        func_0207C9D0((const VecFx32_021C6E5C *)&v, (const VecFx32_021C6E5C *)(&p->f1C), (VecFx32_021C6E5C *)&v);
        func_0216D89C(h, &v);
        if (p->fE <= p->fC) {
            return 1;
        }
    }
    return 0;
}






/*
 * The source vector is `const V *`: the const lets the scheduler hoist each
 * load above the preceding store (ldr x; str fC; ldr y; str x; ...).  The
 * sibling func_021C754C takes a plain `V *` and keeps loads after the fC store.
 */
Q *func_021C7AE4(u32 a, u32 b, const V *v)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x28, func_021C7B1C);
    X *x = (X *)func_021C6CCC((u8 *)q);
    x->f0 = 0;
    x->f4 = a;
    x->f8 = 0;
    x->fC = b;
    set3(&x->f1C, v->x, v->y, v->z);
    return q;
}







int func_021C7B1C(Work_021C7A20 *w)
{
    void *o;
    fx32 t;
    VecFx32 a;
    VecFx32 b;
    VecFx32 c;

    o = func_02188C58(w->id);
    switch (w->state) {
    case 0:
        func_0218ECC4(o, &w->from);
        w->state++;
        break;
    case 1:
        w->cnt++;
        t = FX_F32_TO_FX32((f32)w->cnt / (f32)w->max);
        func_020520A4((const struct Vec3 *)(&w->from), FX32_ONE - t, (struct Vec3 *)(&a));
        func_020520A4((const struct Vec3 *)(&w->to), t, (struct Vec3 *)(&b));
        func_0207C9D0((const VecFx32_021C6E5C *)((Vec *)(&a)), (const VecFx32_021C6E5C *)((Vec *)(&b)), (VecFx32_021C6E5C *)((Vec *)(&c)));
        func_0218ECD4(o, &c);
        if (w->max <= w->cnt)
            return 1;
        break;
    }
    return 0;
}




int func_021C7C10(int a, int b, const Vec *c, const Vec *d)
{
    int w;
    int h;
    Obj *o;

    w = func_02188C84((u8 *)a);
    func_02188C58((void *)a);
    h = (int)func_021C6C70(w, 0x34, func_021C7C74);
    o = (Obj *)func_021C6CCC((u8 *)h);
    o->f0 = 0;
    o->f4 = a;
    o->f8 = 0;
    o->fA = b;
    o->fC = *c;
    o->f18 = *d;
    func_0207CA00(&o->f18, &o->fC, &o->f24);
    return h;
}




int func_021C7C74(Obj_021C7C74 *p)
{
    int h;
    int n;
    float t;
    Vec v;

    h = (int)func_02188C58((void *)p->f4);
    switch (p->f0) {
    case 0:
        p->f30 = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        p->f0 = p->f0 + 1;
        break;
    case 1:
        p->f8 = p->f8 + 1;
        t = (float)(u32)p->f8 / (float)(u32)p->fA;
        if (t > 0.0f) {
            n = (int)(4096.0f * t + 0.5f);
        } else {
            n = (int)(4096.0f * t - 0.5f);
        }
        func_0207CEE4(n, &p->f24, &p->fC, &v);
        func_0218EC90(h, &v);
        if (p->fA <= p->f8) {
            func_0218E13C((u8 *)h, p->f30);
            return 1;
        }
        break;
    }
    return 0;
}




int func_021C7D28(int a, int b, u16 c, u16 d)
{
    int w;
    void *s;
    int h;
    Obj_021C7D28 *o;

    w = func_02188C84((u8 *)a);
    s = func_02188CB4((void *)a);
    h = (int)func_021C6C70(w, 0x14, func_021C7D78);
    o = (Obj_021C7D28 *)func_021C6CCC((u8 *)h);
    o->f0 = a;
    o->f4 = func_02188CD0((u8 *)a);
    o->f8 = func_021A3074((void *)s);
    o->fC = 0;
    o->fE = 0;
    o->f10 = c;
    o->f12 = d;
    return h;
}



int func_021C7D78(W_021C7D78 *w)
{
    if (w->fC == 0) {
        if (w->fE % w->f12 == 0)
            func_021ADD7C(w->f8, w->f4);
        if (w->f10 <= w->fE++)
            return 1;
    }
    return 0;
}



M *func_021C7DAC(u32 heap)
{
    M *m = func_02030734(heap, 0x20, 1, d_021DE4FC, 0x7a);
    m->f0 = (unsigned int)func_021C8018(heap);
    m->f1C = 0;
    m->f1E = 4;
    func_021C7E58((u32)m->sub);
    return m;
}



void func_021C7DE0(M *m)
{
    if (m != 0) {
        func_021C7E64((u32)m->sub);
        func_021C8054((void *)m->f0);
        func_020307B0(m);
    }
}



extern void (*d_021DAAD0[])(M *m);



void func_021C7DFC(M *m)
{
    if (m != 0) {
        if (m->f1E != 4) {
            d_021DAAD0[m->f1E](m);
            m->f1E = 4;
        }
        if (m->f1C == 2 && func_021C7E90((Obj_021C7E90 *)m->sub))
            m->f1C = 3;
    }
}



void func_021C7E30(M *m)
{
    u32 a;
    if (m != 0) {
        a = func_021C7EEC(m->sub);
        func_021C8078(m->f0, a, func_021C7EF4(m->sub));
    }
}




/*
 * Field setter at +0x1e.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7E50(u8 *p, u16 v)
{
    ((struct Obj18324 *)p)->f1E = v;
}




/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the u16 at +0x1C (func_021C7E50 sets +0x1E).
 * Sole blocker of ov010 func_0215ECBC's MATCH.
 */
u16 func_021C7E54(Obj_021C7D78 *p)
{
    return p->f1c;
}




/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 24.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7E58(u32 a)
{
    func_02082BCC((void *)a, 0, 24);
}




void func_021C7E64(u32 a)
{
    func_02082BCC((void *)a, 0, 24);
}




int func_021C7E70(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1)
{
((struct Obj03529 *)((u8 *)(a)))->f0 = b;
((struct Obj03529 *)((u8 *)(a)))->fC = b;
((struct Obj03529 *)((u8 *)(a)))->f10 = (c - b);
((struct Obj03529 *)((u8 *)(a)))->f4 = d;
((struct Obj03529 *)((u8 *)(a)))->f14 = d;
((struct Obj03529 *)((u8 *)(a)))->f16 = (*(u8 *)((u8 *)((u8 *)&e0)) - d);
((struct Obj03529 *)((u8 *)(a)))->f6 = 0;
((struct Obj03529 *)((u8 *)(a)))->f8 = e1;
return a;
}




int func_021C7E90(Obj_021C7E90 *p)
{
    if (p->f6 < p->f8) {
        p->f6 = p->f6 + 1;
        p->f0 = p->fC + func_0207C768((int)(((long long)p->f10 * (p->f6 << 12) + 0x800) >> 12), p->f8 << 12);
        p->f4 = p->f14 + p->f16 * p->f6 / p->f8;
        return 0;
    }
    return 1;
}




u32 func_021C7EEC(u8 *p)
{
    return ((struct Obj18326 *)p)->f0;
}




/*
 * Field setter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7EF0(u8 *p, u32 v)
{
    ((struct Obj18327 *)p)->f0 = v;
}




/*
 * Loads the byte at +0x4 of the object.
 */
u8 func_021C7EF4(u8 *p)
{
    return ((struct Obj18328 *)p)->f4;
}




u8 *func_021C7EF8(u8 *p, u8 v)
{
    ((struct Obj18329 *)p)->f4 = v;
    return p;
}




int func_021C7EFC(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj18330 *)((u8 *)(a)))->f1C = 1;
func_021C7EF0((u8 *)(a + 4), (3 << 12));
return (int)func_021C7EF8((u8 *)(a + 4), 31);
}



void func_021C7F18(M *m)
{
    m->f1C = 2;
    func_021C7E70((u32)m->sub, 0x3000, 0xaa00, 0x1f, 0x1f, 0xf);
    func_020061E4(0x767);
}



void func_021C7F44(M *m)
{
    m->f1C = 3;
    func_021C7EF0(m->sub, 0xaa00);
    func_021C7EF8(m->sub, 0x1f);
}




void func_021C7F5C(M *m)
{
    m->f1C = 0;
    func_021C7EF0(m->sub, 0);
}



M **func_021C7F70(u32 flags, u32 heap)
{
    M **pp = func_02030734(heap, 4, 1, d_021DE50C, 0x49);
    func_021C7FC0(pp, flags, heap);
    return pp;
}




/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7F9C(u8 *p)
{
    func_021C7FF0(p);
    func_020307B0(p);
}




/*
 * Tail-call thunk: forwards to func_021C8000 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7FAC(u32 a)
{
    func_021C8000((u8 *)a);
}
