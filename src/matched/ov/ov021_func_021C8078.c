/*
 * function: func_021C8078
 * address:  0x021C8078
 * packet:   pkt_ov021_021C8078
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02046AFC  0x02046AFC  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0206AAD4  0x0206AAD4  arm
 *   func_02082B60  0x02082B60  arm
 *   func_02047788  0x02047788  arm
 *   func_0204755C  0x0204755C  arm
 *   func_0206E394  0x0206E394  arm
 *   func_0206E4FC  0x0206E4FC  arm
 *   func_0206E484  0x0206E484  arm
 *   func_0206E574  0x0206E574  arm
 *   func_0206E40C  0x0206E40C  arm
 *   func_02047A60  0x02047A60  arm
 * Addresses are Black-image addresses.
 */

typedef struct { int x, y, z; } V;
typedef struct { int m[9]; } M;
typedef struct { int m[12]; } M43;
typedef struct { V pos, tgt, up; } Cam;
typedef struct { V t; V s; M r; } SRT;
typedef struct { int f0; void *f4; } Q;
typedef struct { int f0; void *f4; } Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Arg;
extern void func_02046AFC(u8 *dst);
extern void func_0207CA00(V *, V *, V *);
extern void func_0207CCA4(V *, V *);
extern u32 *func_0206AAD4(void);
extern void func_02082B60(M43 *, M *);
extern int func_02047788(int *p);
extern Q *func_0204755C(void *);
extern void func_0206E394(void *, int, int);
extern void func_0206E4FC(void *, int, int);
extern void func_0206E484(void *, int, int);
extern void func_0206E574(void *, int, int);
extern void func_0206E40C(void *, int, int);
extern void func_02047A60(void *a0, struct Arg *a1);

void func_021C8078(Obj *p, int b, int c)
{
    SRT srt;
    Cam cam;
    V v;
    int y;
    void *q;

    if (b == 0) {
        return;
    }
    func_02046AFC((u8 *)(&cam));
    srt.t = cam.pos;
    func_0207CA00(&cam.up, &cam.pos, &v);
    func_0207CCA4(&v, &v);
    y = v.y;
    if (y <= 0) {
        y = -y;
    }
    srt.s.x = b;
    srt.s.y = (int)(((long long)b * y + 0x800) >> 12);
    srt.s.z = 0x4000;
    func_02082B60((M43 *)func_0206AAD4(), &srt.r);
    q = func_0204755C((void *)func_02047788(p->f4))->f4;
    func_0206E394(q, 0, 0);
    func_0206E4FC(q, 0, 0);
    func_0206E484(q, 0, 2);
    func_0206E574(q, 0, c);
    func_0206E40C(q, 0, 0);
    func_02047A60(p->f4, (struct Arg *)(&srt));
}
