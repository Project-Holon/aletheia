/*
 * file:     field_place_name_p04.c
 * unit:     yes
 * function: func_021BC138, func_021BC338, func_021BC340, func_021BC388, func_021BC424, func_021BC484, func_021BC4F0, func_021BC550, func_021BC578, func_021BC5A0, func_021BC5BC, func_021BC5D4, func_021BC5E4
 * address:  0x021BC138
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
 *   func_02050080  0x02050080  arm
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_020507D0  0x020507D0  arm
 *   func_020507A0  0x020507A0  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_0204F638  0x0204F638  arm
 *   func_020508C4  0x020508C4  arm
 *   func_0204F5E4  0x0204F5E4  arm
 *   func_0204F604  0x0204F604  arm
 *   func_0204F654  0x0204F654  arm
 *   func_0204F66C  0x0204F66C  arm
 *   func_0204F684  0x0204F684  arm
 *   func_0204F794  0x0204F794  arm
 *   func_0204F748  0x0204F748  arm
 *   func_0204F764  0x0204F764  arm
 *   d_021D9B40     0x021D9B40  data  a4
 *   d_021D9B58     0x021D9B58  data  a4
 *   d_021D9B4C     0x021D9B4C  data  a4
 *   func_021BCF88  0x021BCF88  thumb  ov021
 *   func_021BCFA4  0x021BCFA4  thumb  ov021
 *   func_021BD0E0  0x021BD0E0  thumb  ov021
 *   func_021BC810  0x021BC810  thumb  ov021
 *   func_021BCFE0  0x021BCFE0  thumb  ov021
 *   func_021BCFF0  0x021BCFF0  thumb  ov021
 *   func_021BD008  0x021BD008  thumb  ov021
 *   func_021BD098  0x021BD098  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_021BD09C  0x021BD09C  thumb  ov021
 *   func_021BC730  0x021BC730  thumb  ov021
 *   func_021BC75C  0x021BC75C  thumb  ov021
 *   func_021BC794  0x021BC794  thumb  ov021
 *   func_021BC7BC  0x021BC7BC  thumb  ov021
 *   func_021BC998  0x021BC998  thumb  ov021
 *   func_021BC7D4  0x021BC7D4  thumb  ov021
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_021BC664  0x021BC664  thumb  ov021
 *   func_021BC6E8  0x021BC6E8  thumb  ov021
 *   func_021BD01C  0x021BD01C  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 *   func_021BD0FC  0x021BD0FC  thumb  ov021
 *   func_021BC6B4  0x021BC6B4  thumb  ov021
 *   func_021BC7F8  0x021BC7F8  thumb  ov021
 *   func_021BD068  0x021BD068  thumb  ov021
 *   func_021BC9AC  0x021BC9AC  thumb  ov021
 *   func_021BC7B0  0x021BC7B0  thumb  ov021
 *   func_021BC788  0x021BC788  thumb  ov021
 *   func_021BC748  0x021BC748  thumb  ov021
 *   func_021BD040  0x021BD040  thumb  ov021
 *   func_021BD054  0x021BD054  thumb  ov021
 *   func_021BD07C  0x021BD07C  thumb  ov021
 *   func_021BC704  0x021BC704  thumb  ov021
 *   func_021BC824  0x021BC824  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 *   func_021BCFD8  0x021BCFD8  thumb  ov021
 *   func_021BD0B0  0x021BD0B0  thumb  ov021
 *   func_021BD0A4  0x021BD0A4  thumb  ov021
 *   func_021BCC3C  0x021BCC3C  thumb  ov021
 *   func_021BCC80  0x021BCC80  thumb  ov021
 *   func_021BCD34  0x021BCD34  thumb  ov021
 *   func_021BCD70  0x021BCD70  thumb  ov021
 *   func_021BCD84  0x021BCD84  thumb  ov021
 *   func_021BCDD8  0x021BCDD8  thumb  ov021
 *   func_021BCE88  0x021BCE88  thumb  ov021
 *   func_021BC970  0x021BC970  thumb  ov021
 *   func_021BCEAC  0x021BCEAC  thumb  ov021
 *   func_021BCEB0  0x021BCEB0  thumb  ov021
 *   func_021BCEB4  0x021BCEB4  thumb  ov021
 *   func_021BCF18  0x021BCF18  thumb  ov021
 *   func_021BCF1C  0x021BCF1C  thumb  ov021
 *   func_021BCF20  0x021BCF20  thumb  ov021
 *   func_021BCF24  0x021BCF24  thumb  ov021
 *   func_021BD120  0x021BD120  thumb  ov021
 *   func_021BD140  0x021BD140  thumb  ov021
 *   func_021BCBC8  0x021BCBC8  thumb  ov021
 *   func_021BCA78  0x021BCA78  thumb  ov021
 *   func_021BCA64  0x021BCA64  thumb  ov021
 *   func_021BCA80  0x021BCA80  thumb  ov021
 *   func_021BCA6C  0x021BCA6C  thumb  ov021
 *   func_021BC654  0x021BC654  thumb  ov021
 *   func_021BC720  0x021BC720  thumb  ov021
 *   func_021BC6D0  0x021BC6D0  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 */
struct Manager0204F684;
struct Trip;
struct Actor;
struct VecFx32;
struct BgTemplate;
struct S;
struct Descriptor;
struct Cfg;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_021BC138;

typedef int            fx32;

typedef struct { fx32 x, y, z; } Vec;

typedef struct {
    u8 pad0[7];
    u8 f7;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 padC[0x14 - 0xC];
    u32 *f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Param;

typedef signed short   s16_021BC338;

typedef signed char    s8;

typedef signed short   s16_021BC5BC;

typedef signed int     s32;

extern u32 func_02050080(u32 *p);
extern int func_0216D7A8(void *p, unsigned int v);
extern u32 func_021ABE14(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern int func_020507D0(u32 a, u16 b);
extern int func_020507A0(void *p, int idx, u32 x);
extern void func_020507F0(void *p, int idx, u32 v);
extern void *func_0216E3C4(void *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern void func_0216D8B0(u8 *p, u8 *q);
extern int func_02163E58(u32 a, Vec *v, int *y);
extern void func_0216D8D0(u8 *p, u8 *q);
extern u32 func_0216D7DC(void *p);
extern u16 func_021AB0F8(u32 attr);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_02048B30(u32 cam, Vec *out);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern u32 func_020508C4(u32 a, u16 b);
extern void func_0204F5E4(u8 *a0, u32 i, u16 *out);
extern void func_0204F604(void *p, u32 idx, u16 *src);
extern void func_0204F654(u32 h, u32 i, s16_021BC138 *v);
extern void func_0204F66C(int p0, int p1, int p2);
extern void func_0204F684(struct Manager0204F684 *mgr, int idx, const s16_021BC138 *p12, const s16_021BC138 *p14);
extern void func_0204F794(void *p, u32 idx, u32 *val);
extern u32 func_0204F748(u8 *a0, int i);
extern void func_0204F764(void *p, u32 idx, u32 *val);
extern void *func_021BCF88(int a);
extern void func_021BCFA4(int a, int b);
extern void func_021BD0E0(int a);
extern void func_021BC810(int a);
extern void func_021BCFE0(int a);
extern void func_021BCFF0(int a);
extern void func_021BD008(int a);
extern void func_021BD098(int a, int b);
extern u32 func_021904AC(u8 *p);
extern void func_021BD09C(u8 *p, u32 v);
extern void func_021BC730(int a);
extern void func_021BC75C(int a);
extern void func_021BC794(int a);
extern void func_021BC7BC(int a, int b);
extern void func_021BC998(int a);
extern void func_021BC7D4(int a);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_021BC664(struct S *p);
extern void func_021BC6E8(int a);
extern void func_021BD01C(int a);
extern void func_021BCB9C(void *p, int keep);
extern int func_021BD0FC(u32 a);
extern void func_021BC6B4(int a);
extern void func_021BC7F8(int a);
extern void func_021BD068(u8 *p);
extern void func_021BC9AC(int a);
extern void func_021BC7B0(u8 *p);
extern void func_021BC788(u8 *p);
extern void func_021BC748(u8 *p);
extern void func_021BD040(int a);
extern void func_021BD054(u8 *p);
extern void func_021BD07C(int a);
extern void func_021BC704(int a);
extern void func_021BC824(u8 *p);
extern void func_020403F4(u32 i);
extern void func_021BCFD8(int a);
extern void func_021BD0B0(int a);
extern u32 func_021BD0A4(u8 *p);
extern void func_021BCC3C(void *p);
extern void func_021BCC80(char *p);
extern void func_021BCD34(int a);
extern void func_021BCD70(int a);
extern void func_021BCD84(char *p);
extern void func_021BCDD8(char *p);
extern void func_021BCE88(char *p);
extern void func_021BC970(int a);
extern void func_021BCEAC(int a);
extern void func_021BCEB0(int a);
extern void func_021BCEB4(char *p);
extern void func_021BCF18(int a);
extern void func_021BCF1C(int a);
extern void func_021BCF20(int a);
extern void func_021BCF24(char *p);
extern void func_021BD120(void *p, u16 v);
extern int func_021BD140(u16 v);
extern void func_021BCBC8(char *p);
extern void func_021BCA78(u8 *p);
extern void func_021BCA64(u8 *p);
extern u8 *func_021BCA6C(u8 *p);
extern void func_021BCA80(u8 *p);
extern void func_021BC654(u8 *p);
extern void func_021BC720(void *p);
extern void func_021BC6D0(int a);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(int a, int b, int c, int d, int e);
void func_021BC138(u16 id, Param *p);
int func_021BC338(u32 a);
int func_021BC340(int a, int b);
int func_021BC388(int a, int b, int c);
void func_021BC424(u32 a);
void func_021BC484(u32 a);
void func_021BC4F0(int a);
void func_021BC550(void *p, int v);
void func_021BC578(void *p, int v);
void func_021BC5A0(void *p, int v);
int func_021BC5BC(u8 *a);
void func_021BC5D4(u8 *p);
void func_021BC5E4(int *p);
extern const fx32 d_021D9B40[];
extern const fx32 d_021D9B58[];
extern const fx32 d_021D9B4C[];


/*
 * Witnesses: arm9 leaves func_02050080, func_020507D0, func_020507F0,
 * func_020508C4, func_0204F654 filed in src/matched/arm9 (wave A1).
 *
 * The u16 `slot` local is what truncates func_020507D0's result straight
 * into r2 (a (u16) cast or a u16 parameter adds a copy first).
 *
 * Addresses are Black-image addresses.
 */
void func_021BC138(u16 id, Param *p)
{
    Vec v;
    Vec w;
    Vec u;
    int y;
    u32 flag;
    s16_021BC138 rot[4];
    u16 kind;
    u32 h2;
    u32 h;
    int idx;
    u32 obj;
    Info *info;
    u32 i1;
    u32 i2;
    u16 slot;

    h2 = p->f24;
    h = func_02050080((u32 *)h2);
    idx = func_0216D7A8((void *)p->f1C, 0);
    if (id == 0xFFFF) {
        return;
    }
    kind = func_02188C9C((u8 *)func_021ABE14((u8 *)(*p->f14)));
    slot = func_020507D0(h2, idx);
    func_020507A0((void *)h2, id, slot);
    func_020507F0((void *)h2, id, 0);
    obj = p->f1C;
    info = func_0216E3C4((void *)obj);
    func_0216D88C((const struct Actor *)obj, (struct VecFx32 *)&v);
    v.z += d_021D9B40[info->f7];
    func_0216D8B0((u8 *)obj, (u8 *)(&w));
    v.x += w.x;
    v.z -= w.z;
    if (func_02163E58(obj, &v, &y) == 1) {
        v.y = y;
    }
    v.y += d_021D9B58[p->f18];
    func_0216D8D0((u8 *)obj, (u8 *)(&w));
    v.x += w.x;
    v.y -= w.y;
    v.z -= w.z;
    v.y += d_021D9B4C[info->f7];
    if (info->f7 == 2) {
        if (func_021AB0F8(func_0216D7DC((void *)obj)) & 0x40) {
            v.y -= 0x3800;
        } else {
            v.y -= 0x8000;
        }
    }
    v.y += func_021BC340(kind, info->f7);
    func_02048B30(func_0218EC2C(func_02188C58((void *)func_021ABE14((u8 *)(*p->f14)))), &u);
    v.x += (v.x / 4096 - u.x / 4096) * 298;
    func_0204F638((u8 *)h, id, (struct Trip *)(&v));
    flag = 1;
    i1 = func_020508C4(h2, idx);
    i2 = func_020508C4(h2, id);
    rot[3] = p->f8;
    rot[2] = p->f4;
    rot[2] += (s16_021BC138)func_021BC338(kind);
    rot[1] = 0;
    rot[0] = 0;
    func_0204F5E4((u8 *)h, i1, (u16 *)(&rot[1]));
    func_0204F604((void *)h, i2, (u16 *)(&rot[1]));
    func_0204F654(h, i1, &rot[0]);
    func_0204F66C(h, i2, (int)(&rot[0]));
    func_0204F684((struct Manager0204F684 *)h, i2, &rot[3], &rot[2]);
    func_0204F794((void *)h, i2, &flag);
    flag = func_0204F748((u8 *)h, i1);
    func_0204F764((void *)h, i2, &flag);
}


int func_021BC338(u32 a)
{
return (~255);
}

int func_021BC340(int a, int b)
{
    int r = 0;

    if (a == 0x71 || a == 0x159) {
        if (b == 0) {
            r = -0x800;
        }
    } else if (a == 0x8f) {
        if (b == 0) {
            r = 2 << 10;
        }
    } else if (a == 0x159 + 0x12) {
        if (b == 0) {
            r = -0x5800;
        }
    } else {
        if (b == 0) {
            r = 6 << 10;
        }
    }
    return r;
}


int func_021BC388(int a, int b, int c)
{
    int r4;

    r4 = (int)func_021BCF88(b);
    func_021BCFA4(r4, a);
    func_021BD0E0(r4);
    func_021BC810(r4);
    func_021BCFE0(r4);
    func_021BCFF0(r4);
    func_021BD008(r4);
    func_021BD098(r4, b);
    func_021BD09C((u8 *)r4, func_021904AC((u8 *)c));
    func_021BC730(r4);
    func_021BC75C(r4);
    func_021BC794(r4);
    func_021BC7BC(r4, 0);
    func_021BC998(r4);
    func_021BC7D4(r4);
    func_0203FCA0(3, (const struct BgTemplate *)0x021DE334, 0);
    func_021BC664((struct S *)r4);
    func_021BC6E8(r4);
    func_021BD01C(r4);
    func_021BCB9C((void *)r4, 0);
    return r4;
}


void func_021BC424(u32 a)
{
    func_021BD0FC(a);
    func_021BC6B4(a);
    func_021BC7F8(a);
    func_021BD068((u8 *)a);
    func_021BC9AC(a);
    func_021BC7B0((u8 *)a);
    func_021BC788((u8 *)a);
    func_021BC748((u8 *)a);
    func_021BD040(a);
    func_021BD054((u8 *)a);
    func_021BD07C(a);
    func_021BC704(a);
    func_021BC824((u8 *)a);
    func_020403F4(3);
    func_021BCFD8(a);
}


void func_021BC484(u32 a)
{
    func_021BD0B0(a);
    switch (func_021BD0A4((u8 *)a)) {
    case 0:
        func_021BCC3C((void *)a);
        break;
    case 1:
        func_021BCC80((char *)a);
        break;
    case 2:
        func_021BCD34(a);
        break;
    case 3:
        func_021BCD70(a);
        break;
    case 4:
        func_021BCD84((char *)a);
        break;
    case 5:
        func_021BCDD8((char *)a);
        break;
    case 6:
        func_021BCE88((char *)a);
        break;
    }
    func_021BC970(a);
}


void func_021BC4F0(int a)
{
    switch (func_021BD0A4((u8 *)a)) {
    case 0:
        func_021BCEAC(a);
        break;
    case 1:
        func_021BCEB0(a);
        break;
    case 2:
        func_021BCEB4((char *)a);
        break;
    case 3:
        func_021BCF18(a);
        break;
    case 4:
        func_021BCF1C(a);
        break;
    case 5:
        func_021BCF20(a);
        break;
    case 6:
        func_021BCF24((char *)a);
        break;
    }
}


void func_021BC550(void *p, int v)
{
    func_021BD120(p, (u16)v);
    if (func_021BD140((u16)v)) {
        func_021BCBC8(p);
        func_021BCA78(p);
    }
}


void func_021BC578(void *p, int v)
{
    func_021BD120(p, (u16)v);
    if (func_021BD140((u16)v)) {
        func_021BCBC8(p);
        func_021BCA64(p);
    }
}


void func_021BC5A0(void *p, int v)
{
    func_021BD120(p, (u16)v);
    func_021BCBC8(p);
    func_021BCA64(p);
}


int func_021BC5BC(u8 *a)
{
func_021BCB9C((void *)a, 0);
func_021BCA80((u8 *)a);
return (int)func_021BCA6C(a);
}


void func_021BC5D4(u8 *p)
{
    func_021BC654(p);
    func_021BC720(p);
}


void func_021BC5E4(int *p)
{
    int r4;

    func_021BC6D0((int)p);
    func_021BC6E8((int)p);
    func_021BD01C((int)p);
    r4 = p[9];
    func_02045334((struct Descriptor *)r4);
    func_02045374((struct Cfg *)r4);
    func_020409B4(func_02045730((struct Descriptor *)r4));
    func_0204047C(3, 1);
    func_02040588(3, 0);
    func_0207D63C(0x04000050, 8, 0x11, 0x10, 4);
}
