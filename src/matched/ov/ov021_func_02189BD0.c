/*
 * function: func_02189BD0
 * address:  0x02189BD0
 * packet:   pkt_ov021_02189BD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Root of the field input tree: builds the FieldInput record on the stack
 * and runs the talk / step / menu / surf / script checks in order,
 * returning the first non-zero result.  The u16 local at sp+0x28 is the
 * out slot of func_021CD440; its address doubles as the base for the
 * in.f0 / in.f10 loads, which is why `add r1, sp, #0x28` sits above the
 * beq after the func_021CFAC0 test.
 *
 * symbols:
 *   func_0218A4E0  0x0218A4E0  thumb
 *   func_0218A738  0x0218A738  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_021C868C  0x021C868C  thumb
 *   func_021AE0CC  0x021AE0CC  thumb
 *   func_0218A728  0x0218A728  thumb
 *   func_0218A76C  0x0218A76C  thumb
 *   func_0218ACD0  0x0218ACD0  thumb
 *   func_0218AD28  0x0218AD28  thumb
 *   func_0218A9B0  0x0218A9B0  thumb
 *   func_0218A7F0  0x0218A7F0  thumb
 *   func_0218A824  0x0218A824  thumb
 *   func_0218A878  0x0218A878  thumb
 *   func_0218B208  0x0218B208  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021A2F20  0x021A2F20  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   func_0217BFD8  0x0217BFD8  thumb  ov018
 *   func_0217CA84  0x0217CA84  thumb  ov018
 *   func_02026454  0x02026454  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_0217B810  0x0217B810  thumb  ov018
 *   func_0217689C  0x0217689C  thumb  ov011
 *   func_02012FB0  0x02012FB0  thumb
 *   func_0216B3A8  0x0216B3A8  thumb  ov010
 *   func_021754B4  0x021754B4  thumb  ov011
 *   func_021A2F6C  0x021A2F6C  thumb
 *   func_0217FC6C  0x0217FC6C  thumb  ov018
 *   func_0217BDE0  0x0217BDE0  thumb  ov018
 *   func_0217AFC4  0x0217AFC4  thumb  ov018
 *   func_0217FB5C  0x0217FB5C  thumb  ov018
 *   func_021A3050  0x021A3050  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_0218B4B0  0x0218B4B0  thumb
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 *   func_02158D90  0x02158D90  thumb  ov010
 *   func_0219F01C  0x0219F01C  thumb
 *   func_02162A54  0x02162A54  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 *   func_0218B56C  0x0218B56C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_021CFAC0  0x021CFAC0  thumb
 *   func_021CFC14  0x021CFC14  thumb
 *   func_021CD440  0x021CD440  thumb
 *   func_02013FFC  0x02013FFC  thumb
 *   func_02162940  0x02162940  thumb  ov010
 *   func_0218B408  0x0218B408  thumb
 *   func_0218AED4  0x0218AED4  thumb
 *   func_0218AF90  0x0218AF90  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_02188CCC  0x02188CCC  thumb
 *   func_0215FF34  0x0215FF34  thumb  ov010
 *   func_021A0ED4  0x021A0ED4  thumb
 *   func_0215FF54  0x0215FF54  thumb  ov010
 *   func_0201212C  0x0201212C  thumb
 *   func_021C06CC  0x021C06CC  thumb
 *   func_021A0F90  0x021A0F90  thumb
 *   func_0215FC40  0x0215FC40  thumb  ov010
 *   func_021A0EB0  0x021A0EB0  thumb
 *   func_0218ACA8  0x0218ACA8  thumb
 *   func_0217B410  0x0217B410  thumb  ov018
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldInput {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    u32 f18;
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

struct Obj00020;
extern void func_0218A4E0(struct FieldInput *p, void *sys, struct Obj00020 *pos);
typedef signed int     s32;
struct Big;
struct Ctx738;
struct Ctx9B0;
struct FieldCtx;
extern int func_0218A738(struct Ctx738 *c);
extern u32 *func_02012ED0(void *p);
struct BigObj;
struct Ctx;
struct Desc;
struct VecFx32;
extern int func_021C868C(int a, char *b);
extern int func_021AE0CC(int a);
extern int func_0218A728(void *a);
extern int func_0218A76C(void *p);
extern int func_0218ACD0(u8 *p, void *a, void *arg);
extern void *func_0218AD28(struct FieldCtx *p, struct Obj00020 *pos);
extern int func_0218A9B0(struct Ctx9B0 *p, u8 *pos);
extern int func_0218A7F0(struct FieldCtx *p);
extern int func_0218A824(struct FieldCtx *p);
extern void *func_0218A878(u8 *p, void *a, void *b);
extern int func_0218B208(struct FieldCtx *p, void *unused, u8 *pos);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern int func_021A2F20(u32 *p, int a, int b, int c);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void *func_021A3074(u8 *p);
extern int func_0217BFD8(const struct Ctx *a, int b);
extern int func_0217CA84(void *sys, int v);
extern u32 func_02026454(void *obj);
extern int func_02012B70(const struct BigObj *p);
extern int func_0217C070(u8 *p);
extern void *func_0217B810(void *a, u8 *pos);
extern int func_0217689C(u8 *ctx, int arg);
extern int func_02012FB0(unsigned char *base);
struct Desc;
extern struct Desc *func_0216B3A8(int a0, int a1, int a2);
extern int func_021754B4(u8 *p, int *out);
extern void func_021A2F6C(u32 *p);
extern void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e);
extern int func_0217BDE0(int a, u8 *b, int c);
extern int func_0217AFC4(int *a, u8 *b, int *out);
extern void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f);
extern u16 func_021A3050(u8 *p);
extern void func_021A3038(u8 *p, struct VecFx32 *out);
extern void func_02164208(int dir, int *p, int amt);
extern int func_0218B4B0(struct FieldCtx *p, u8 *pos);
extern u32 func_0216D5B8(void *p);
extern int func_02158D90(u16 v);
extern int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
extern u32 func_02162A54(void *p, void *q, int *pos, u32 d);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern u16 func_0218B56C(struct FieldCtx *p, u8 *pos);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u16 func_02188C9C(u8 *p);
extern int func_021CFAC0(u8 *base, int a, int b, int c, int d);
extern void *func_021CFC14(void *a, void *unused, void *c);
extern int func_021CD440(void *a, u16 *out);
extern u32 func_02013FFC(u32 id);
extern u16 func_02162940(void *p, void *q, int key);
extern int func_0218B408(char *p, void *a, void *x);
extern int func_0218AED4(char *p, int unused, void *a);
extern int func_0218AF90(struct FieldInput *p, void *sys, u8 *pos);
extern u32 func_020221A4(void);
extern u32 func_02188CCC(u8 *p);
extern int func_0215FF34(void *sys);
extern int func_021A0ED4(u32 a);
extern struct Desc *func_0215FF54(int a0, int a1, u16 a2);
extern u8 func_0201212C(const struct Ctx *p);
extern int func_021C06CC(void *sys, u8 *pos);
extern u32 func_021A0F90(u8 *p);
extern struct Desc *func_0215FC40(int a0, int a1, u16 a2);
extern int func_021A0EB0(u32 *p, u32 a);
extern struct Desc *func_0218ACA8(void *a);
extern int func_0217B410(int a0, int a1, int a2);

int func_02189BD0(void *sys, struct Obj00020 *pos, int *outA, int *outB)
{
    struct FieldInput in;
    int xyz[3];
    u32 out;
    u16 id;
    int r;
    u32 flags;
    void *ev;
    void *obj;
    void *model;

    *outA = 0;
    *outB = 0;
    func_0218A4E0(&in, sys, pos);
    r = func_0218A738((struct Ctx738 *)(&in));
    if (r != 0) {
        *outA = 1;
        return r;
    }
    r = func_021C868C((int)sys, (char *)(*func_02012ED0(in.f8)));
    if (r != 0)
        return r;
    r = func_021AE0CC((int)pos);
    if (r != 0) {
        *outA = 1;
        return r;
    }
    if (in.b2)
        func_0218A728(in.f8);
    if (in.b2) {
        r = func_0218A76C(&in);
        if (r != 0) {
            *outA = 1;
            return r;
        }
        r = func_0218ACD0((u8 *)(&in), pos, (void *)in.f34);
        if (r != 0)
            return r;
        r = (int)func_0218AD28((struct FieldCtx *)(&in), (struct Obj00020 *)pos);
        if (r != 0)
            return r;
    }
    r = func_0218A9B0((struct Ctx9B0 *)(&in), (u8 *)pos);
    if (r != 0)
        return r;
    if (in.b3) {
        r = func_0218A7F0((struct FieldCtx *)(&in));
        if (r != 0)
            return r;
    }
    r = func_0218A824((struct FieldCtx *)(&in));
    if (r != 0)
        return r;
    r = (int)func_0218A878((u8 *)(&in), sys, pos);
    if (r != 0)
        return r;
    r = func_0218B208((struct FieldCtx *)(&in), sys, (u8 *)pos);
    if (r != 0)
        return r;

    flags = 0;
    if ((int)func_020142E8((void *)func_0201296C(in.f8), (u32)0x964) == 1)
        flags |= 1;
    r = func_021A2F20((u32 *)in.f18, in.trg, in.cont, flags);
    if (r != 0)
        return r;

    obj = (void *)func_02012138(sys);
    ev = (void *)func_02158344((int)obj);
    model = func_021A3074((u8 *)in.f18);
    if (func_0217BFD8((const struct Ctx *)sys, in.f10) == 1)
        return func_0217CA84(sys, 0);
    if ((int)func_02026454(obj) == 2 && ev != 0) {
        if (func_02012B70(in.f8) == 1 && func_0217C070(ev) == 1)
            return (int)func_0217B810(sys, (u8 *)pos);
        if (func_0217689C(ev, in.f10) == 1)
            return (int)func_0216B3A8((int)sys, 9, (u32)func_02012FB0(in.f8));
        if (in.b10 == 1 && func_021754B4(ev, (int *)(&out)) == 1) {
            func_021A2F6C((u32 *)in.f18);
            return (int)func_0217FC6C(sys, (int)pos, (int)ev, (int)model, out, in.f0);
        }
        if (in.b3) {
            r = func_0217BDE0((int)sys, ev, in.f18);
            if (r != 0)
                return r;
        }
        if (in.b0 && func_0217AFC4(ev, (u8 *)in.f18, (int *)(&out)) == 1) {
            func_021A2F6C((u32 *)in.f18);
            return (int)func_0217FB5C(sys, (int)pos, (int)ev, (int)model, out, in.f0);
        }
    }

    if (in.b0) {
        u32 dir = func_021A3050((u8 *)in.f18);
        int target;
        u32 msg;
        int x;
        int y;
        int z;
        void *map;

        func_021A3038((u8 *)in.f18, (struct VecFx32 *)xyz);
        func_02164208((u32)dir, xyz, 0x10000);
        target = func_0218B4B0((struct FieldCtx *)(&in), (u8 *)pos);
        if (target != 0) {
            u32 kind = func_0216D5B8((void *)target);

            if (func_02158D90(kind) == 1) {
                void *m = func_021A3074((u8 *)in.f18);

                func_021A2F6C((u32 *)in.f18);
                *outA = 1;
                return func_0219F01C((u32)sys, (u32)pos, kind, (u32)m, target, in.f0);
            }
        }
        msg = func_02162A54(in.fC, (void *)func_0201296C(in.f8), xyz, dir);
        if (msg != 0xFFFF)
            return (int)func_02158768((int)sys, msg, 0, in.f0);
        msg = func_0218B56C((struct FieldCtx *)(&in), (u8 *)pos);
        if (msg != 0xFFFF)
            return (int)func_02158768((int)sys, msg, 0, in.f0);
        x = xyz[0] >> 12;
        y = xyz[1] >> 12;
        z = xyz[2] >> 12;
        map = func_0200BE48(func_02012EBC(in.f8));
        msg = (u32)func_021CFAC0(map, (u16)func_02188C9C((u8 *)pos), (s16)(x / 16), (s16)(y / 16), (s16)(z / 16));
        if (msg != 0xFF)
            return (int)func_021CFC14(sys, (void *)in.f0, (void *)msg);
        if (func_021CD440(pos, &id) == 1)
            return (int)func_02158768((int)sys, 0x271B, 0, in.f0);
        if (func_02013FFC(in.f10)) {
            msg = func_02162940(in.fC, (void *)func_0201296C(in.f8), (int)xyz);
            if (msg != 0xFFFF)
                return (int)func_02158768((int)sys, msg, 0, in.f0);
        }
    }

    if (in.f1C == 3 || in.f1C == 0) {
        r = func_0218B408((char *)(&in), sys, pos);
        if (r != 0)
            return r;
    }
    if (in.b5) {
        r = func_0218AED4((char *)(&in), (int)sys, pos);
        if (r != 0)
            return r;
        r = func_0218AF90(&in, sys, (u8 *)pos);
        if (r != 0)
            return r;
    }
    if (in.b6 && func_020221A4()) {
        void *pl = (void *)func_02188CCC((u8 *)pos);

        if (func_0215FF34(sys) && func_021A0ED4((u32)pl)) {
            r = (int)func_0215FF54((int)sys, (int)pos, in.f0);
            if (r != 0)
                return r;
        }
    }
    if (func_0201212C(sys) == 1 && func_020221A4() && in.b10)
        return func_021C06CC(sys, (u8 *)pos);
    if (in.b1 && func_020221A4()) {
        if ((int)func_021A0F90((void *)func_02188CCC((u8 *)pos)) == 6)
            return 0;
        *outB = 1;
        return (int)func_0215FC40((int)sys, (int)pos, in.f0);
    }
    if (func_020221A4()) {
        r = func_021A0EB0((void *)func_02188CCC((u8 *)pos), in.b7);
        if (r != 0)
            return r;
    }
    if (in.b7 && func_020221A4()) {
        r = (int)func_0218ACA8(sys);
        if (r != 0)
            return r;
    }
    r = func_0217B410((int)pos, (int)sys, in.f18);
    if (r == 0)
        return 0;
    return r;
}
