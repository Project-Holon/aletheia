/*
 * function: func_0218AF90
 * address:  0x0218AF90
 * packet:   pkt_ov021_0218AF90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218AE48  0x0218AE48  thumb  ov021
 *   func_021BE288  0x021BE288  thumb  ov021
 *   func_021F3A88  0x021F3A88  thumb  ov038
 *   func_021F38A4  0x021F38A4  thumb  ov051
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_0218B630  0x0218B630  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB310  0x021AB310  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 *   func_0218AE04  0x0218AE04  thumb  ov021
 *   func_021F404C  0x021F404C  thumb  ov039
 *   func_021F37E0  0x021F37E0  thumb  ov041
 * Addresses are Black-image addresses.
 */

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
};

typedef struct Vec { int x, y, z; } Vec;

struct Obj;
extern void func_0218AE48(struct Obj *p, struct Vec *out);
extern int func_021BE288(u8 *pos, int k);
struct Desc;
extern int func_021F3A88(int a0, int a1, int a2);
extern int func_021F38A4(int a, int b);
extern u32 func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F8(u32 attr);
extern int func_021A3098(void *obj);
extern int func_0218B630(void *p, u32 move);
extern u16 func_021AB0F0(u32 a);
extern int func_021AB310(u16 a);
extern void *func_021A3074(unsigned char *p);
extern void func_02164208(int dir, int *p, int amt);
extern int func_02163E58(void *m, Vec *pos, int *h);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern u32 func_0218AE04(u8 *p, void *arg);
extern int func_021F404C(void *a);
extern int func_021F37E0(void *a);

int func_0218AF90(struct FieldInput *p, void *a, u8 *pos)
{
    Vec v;
    Vec w;
    int h;
    u32 attr;
    void *m;

    func_0218AE48((struct Obj *)p, &v);
    if (func_021BE288(pos, 6))
        return func_021F3A88((int)a, v.x / 0x10000, v.z / 0x10000);
    if (func_021BE288(pos, 0x19) || func_021BE288(pos, 0x1A) || func_021BE288(pos, 0x1B))
        return func_021F38A4((int)pos, p->f24);
    attr = func_021AB0D4((void *)func_02188C98(pos), &v);
    if ((func_021AB0F8(attr) & 1) == 0)
        return 0;
    if (func_021A3098(p->f18) == 2 && func_0218B630(p->f8, 0x7F) != 6
        && func_021AB310(func_021AB0F0(attr)) == 1) {
        w = v;
        m = func_021A3074(p->f18);
        func_02164208(p->f24, (int *)(&w), 0x10000);
        if (func_02163E58(m, &w, &h) == 1 && v.y > h)
            return (int)func_02158768((int)p->sys, 0x271F, 0, p->f0);
    }
    if (func_0218AE04((u8 *)p, &v) == 0xFFFF) {
        if (func_021BE288(pos, 2))
            return func_021F404C(a);
        if (func_021BE288(pos, 5))
            return func_021F37E0(a);
    }
    return 0;
}
