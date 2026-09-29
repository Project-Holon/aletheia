/*
 * function: func_021C7C74
 * address:  0x021C7C74
 * packet:   pkt_ov021_021C7C74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 * Addresses are Black-image addresses.
 */

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
} Obj;

extern int func_02188C58(int);
extern int func_0218E138(int);
extern void func_0218E13C(int, int);
extern void func_0218EC90(int, Vec *);
extern void func_0207CEE4(int, Vec *, Vec *, Vec *);

int func_021C7C74(Obj *p)
{
    int h;
    int n;
    float t;
    Vec v;

    h = func_02188C58(p->f4);
    switch (p->f0) {
    case 0:
        p->f30 = func_0218E138(h);
        func_0218E13C(h, 0);
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
            func_0218E13C(h, p->f30);
            return 1;
        }
        break;
    }
    return 0;
}
