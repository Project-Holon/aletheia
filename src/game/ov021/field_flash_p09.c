/*
 * file:     field_flash_p09.c
 * unit:     yes
 * function: func_021C7C74, func_021C7D28
 * address:  0x021C7C74
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
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0207CEE4  0x0207CEE4  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 *   _fadd          0x0209C95C  arm
 *   _fgr           0x0209BBB0  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021C7D78  0x021C7D78  thumb  ov021
 */
struct Obj00020;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

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

extern void *func_02188C58(void *p);
extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0218EC90(int, Vec *);
extern void func_0207CEE4(int, Vec *, Vec *, Vec *);
extern u16 func_02188C84(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02188CD0(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern int func_021C6C70(int, int, int (*)(Obj_021C7D28 *));
extern u32 func_021C6CCC(u8 *p);
extern int func_021C7D78(Obj_021C7D28 *);
int func_021C7C74(Obj_021C7C74 *p);
int func_021C7D28(int a, int b, u16 c, u16 d);


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


/*
 * Addresses are Black-image addresses.
 */
int func_021C7D28(int a, int b, u16 c, u16 d)
{
    int w;
    void *s;
    int h;
    Obj_021C7D28 *o;

    w = func_02188C84((u8 *)a);
    s = func_02188CB4((void *)a);
    h = func_021C6C70(w, 0x14, func_021C7D78);
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
