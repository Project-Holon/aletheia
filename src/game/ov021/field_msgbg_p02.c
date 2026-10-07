/*
 * file:     field_msgbg_p02.c
 * unit:     yes
 * function: func_0218A4E0, func_0218A6E8, func_0218A728, func_0218A738, func_0218A76C, func_0218A784, func_0218A7F0
 * address:  0x0218A4E0
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
 *   func_02188C84  0x02188C84  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A2FE4  0x021A2FE4  thumb
 *   func_021A3080  0x021A3080  thumb
 *   func_021A308C  0x021A308C  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_02014478  0x02014478  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021A3584  0x021A3584  thumb
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021A1358  0x021A1358  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   func_021F2AB8  0x021F2AB8  thumb  ov029
 *   func_021F2AD4  0x021F2AD4  thumb  ov029
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02014474  0x02014474  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_02158B00  0x02158B00  thumb  ov010
 *   func_0218A8BC  0x0218A8BC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB188  0x021AB188  thumb
 *   func_02162928  0x02162928  thumb  ov010
 *   func_021A2FA4  0x021A2FA4  thumb
 */
struct BigObj;
struct Ctx;
struct Sub02014444Obj;
struct Obj00020;
struct SoundSys;
struct Sub02008C20Obj;
struct Desc;
struct Ctx784;
struct FieldCtx;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct FieldInput {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    void *f18;
    u32 f1C;
    u32 f20;
    u16 f24;
    u16 f26;
    u32 trg;
    u32 cont;
    u16 dir;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
};

typedef signed short   s16;

typedef signed char    s8;

struct Ctx738 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    char pad0C[0x1A];
    u16 f26;
};

struct Ctx784 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    char pad10[0x08];
    void *f18;
};

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    char pad10[0x08];
    void *f18;
    u32 f1C;
    char pad20[0x04];
    u16 f24;
    u16 f26;
    char pad28[0x04];
    u32 f2C;
};

extern void func_02082BCC(void *p, int v, u32 n);
extern u16 func_02188C84(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern u16 func_02188C9C(u8 *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A2FE4(u32 *p);
extern u32 func_021A3080(u8 *p);
extern u32 func_021A308C(u8 *p);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void *func_0216D888(void *p);
extern void *func_02012B38(const struct BigObj *p);
extern u16 func_02014478(struct Sub02014444Obj *o);
extern u32 func_021A30C8(void **ctx);
extern int func_021A3584(void *v);
extern unsigned int func_02188CCC(unsigned char *p);
extern u32 func_021A1358(u32 *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A70(struct SoundSys *sys);
extern int func_021F2AB8(char *p);
extern void func_021F2AD4(u8 *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *func_02012F2C(int *p);
extern void func_02014474(struct Sub02014444Obj *o, u16 v);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern void *func_02158B00(void *a, u32 b);
extern int func_0218A8BC(struct FieldCtx *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB188(u16 id);
extern u16 func_02162928(void *p, void *q, int key, int mode);
extern u16 func_021A2FA4(u8 *p, u32 a1);
void func_0218A4E0(struct FieldInput *p, void *sys, struct Obj00020 *pos);
void func_0218A6E8(void *sys, void *q);
int func_0218A728(void *a);
int func_0218A738(struct Ctx738 *c);
int func_0218A76C(void *p);
int func_0218A784(struct Ctx784 *c, int a);
int func_0218A7F0(struct FieldCtx *p);


/*
 * Fills the 0x40 byte field input record for one frame: pad trigger and held
 * keys, the held d-pad direction, the player object's position, facing and
 * movement state, and the request bitfield at 0x3C (talk on A, menu on X,
 * registered item on Y, no-input, step, surf and push flags).
 *
 * Addresses are Black-image addresses.
 */
void func_0218A4E0(struct FieldInput *p, void *sys, struct Obj00020 *pos)
{
    void *obj;

    func_02082BCC(p, 0, 0x40);
    p->f0 = func_02188C84((u8 *)pos);
    p->sys = sys;
    p->f8 = func_020120F4(sys);
    p->fC = (void *)func_02012844(p->f8);
    p->f10 = func_02188C9C((u8 *)pos);
    p->trg = func_020362DC();
    p->cont = func_0203630C();
    p->dir = 9;
    if (p->cont & 0x40)
        p->dir = 0;
    else if (p->cont & 0x80)
        p->dir = 1;
    else if (p->cont & 0x20)
        p->dir = 2;
    else if (p->cont & 0x10)
        p->dir = 3;
    p->pos = (u8 *)pos;
    p->f18 = func_02188CB4(pos);
    func_021A2FE4(p->f18);
    p->f20 = func_021A3080(p->f18);
    p->f1C = func_021A308C(p->f18);
    obj = func_021A3074(p->f18);
    p->f24 = func_0216D5F8(obj);
    p->f34 = (u32)func_0216D888(obj);
    p->f26 = func_02014478(func_02012B38(p->f8));
    p->f38 = func_021A30C8(p->f18);

    if (p->f1C == 3 || p->f1C == 0) {
        u8 n;

        p->b10 = 1;
        p->b0 = (p->trg & 1) ? 1 : 0;
        p->b1 = (p->trg & 0x400) ? 1 : 0;
        p->b6 = (p->trg & 0x800) ? 1 : 0;
        n = 0;
        n += p->b0;
        n += p->b1;
        n += p->b6;
        if (n == 0)
            p->b7 = 1;
    }
    p->b2 = 0;
    p->b9 = 0;
    if (p->f20 == 1)
        p->b2 = (p->f1C == 3) ? 1 : 0;
    if (func_021A3584(p->f18))
        p->b9 = 1;
    p->b3 = (p->f1C == 3) ? 1 : 0;
    p->b4 = 0;
    if (p->f1C != 3 && p->f20 == 2)
        p->b4 = 1;
    if ((p->f24 == 0 && (p->cont & 0x40)) || (p->f24 == 1 && (p->cont & 0x80))
        || (p->f24 == 2 && (p->cont & 0x20)) || (p->f24 == 3 && (p->cont & 0x10)))
        p->b5 = 1;
    else
        p->b5 = 0;
}


void func_0218A6E8(void *sys, void *q)
{
    void *r;

    r = (void *)func_021A1358((u32 *)func_02188CCC(q));
    if (r == 0) {
        func_02028A70((struct SoundSys *)func_02012A30(func_020120F4(sys)));
        return;
    }
    if (func_021F2AB8(r) == 0) {
        func_02028A70((struct SoundSys *)func_02012A30(func_020120F4(sys)));
        func_021F2AD4(r);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A728(void *a)
{
return func_02008DF0((struct Sub02008C20Obj *)func_02012F2C((int *)a), 0);
}


/*
 * Starts the pending script (field 0x26) through func_02158768, or else asks
 * func_02158B00 for the default one; returns the result.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A738(struct Ctx738 *c)
{
    int r;

    if (c->f26 != 0) {
        func_02014474(func_02012B38(c->f8), 0);
        return (int)func_02158768((int)c->f4, c->f26, 0, c->f0);
    }
    r = (int)func_02158B00(c->f4, c->f0);
    if (r == 0)
        return 0;
    return r;
}


/*
 * Tries func_0218A8BC, then func_0218A784 with direction 9.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A76C(void *p)
{
    int r = func_0218A8BC(p);

    if (r != 0)
        return r;
    return func_0218A784(p, 9);
}


/*
 * Unless the tile attribute under the object's position blocks it
 * (func_021AB188), asks ov010 func_02162928 for a message id and shows it
 * through func_02158768; returns 0 otherwise.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A784(struct Ctx784 *c, int a)
{
    void *x = func_0201210C(c->f4);
    void *y = (void *)func_0201296C(c->f8);
    u32 pos[3];
    u32 msg;

    func_021A3038(c->f18, (struct VecFx32 *)pos);
    if (func_021AB188(func_021AB0F0(func_021AB0D4((void *)func_02188C98(x), pos))) == 1)
        return 0;
    msg = func_02162928(c->fC, y, (int)pos, a);
    if (msg != 0xFFFF)
        return (int)func_02158768((int)c->f4, msg, 0, c->f0);
    return 0;
}


/*
 * Tries func_0218A784 for the current facing, then for the direction from
 * func_021A2FA4 when that differs and is not 9.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A7F0(struct FieldCtx *p)
{
    int r = func_0218A784((struct Ctx784 *)p, p->f24);
    int dir;

    if (r != 0)
        return r;
    dir = func_021A2FA4(p->f18, p->f2C);
    if (dir == 9 || dir == p->f24)
        return 0;
    r = func_0218A784((struct Ctx784 *)p, dir);
    if (r == 0)
        return 0;
    return r;
}
