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

extern void func_0218A4E0(struct FieldInput *p, void *sys, u8 *pos);
extern int func_0218A738(struct FieldInput *p);
extern u32 *func_02012ED0(void *p);
extern int func_021C868C(void *sys, u32 v);
extern int func_021AE0CC(u8 *pos);
extern void func_0218A728(void *p);
extern int func_0218A76C(struct FieldInput *p);
extern int func_0218ACD0(struct FieldInput *p, u8 *pos, u32 arg);
extern void *func_0218AD28(struct FieldInput *p, u8 *pos);
extern int func_0218A9B0(struct FieldInput *p, u8 *pos);
extern int func_0218A7F0(struct FieldInput *p);
extern int func_0218A824(struct FieldInput *p);
extern int func_0218A878(struct FieldInput *p, void *sys, u8 *pos);
extern int func_0218B208(struct FieldInput *p, void *sys, u8 *pos);
extern void *func_0201296C(void *p);
extern int func_020142E8(void *p, u32 id);
extern int func_021A2F20(u32 obj, u32 trg, u32 cont, u32 flags);
extern void *func_02012138(void *sys);
extern void *func_02158344(void *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0217BFD8(void *sys, u16 v);
extern int func_0217CA84(void *sys, int v);
extern int func_02026454(void *p);
extern int func_02012B70(void *p);
extern int func_0217C070(void *ev);
extern int func_0217B810(void *sys, u8 *pos);
extern int func_0217689C(void *ev, u16 v);
extern u32 func_02012FB0(void *p);
struct Desc;
extern struct Desc *func_0216B3A8(void *sys, int a1, int a2);
extern int func_021754B4(void *ev, u32 *out);
extern void func_021A2F6C(u32 obj);
extern int func_0217FC6C(void *sys, u8 *pos, void *ev, u32 m, u32 out, u16 id);
extern int func_0217BDE0(void *sys, void *ev, u32 obj);
extern int func_0217AFC4(void *ev, u32 obj, u32 *out);
extern int func_0217FB5C(void *sys, u8 *pos, void *ev, u32 m, u32 out, u16 id);
extern u32 func_021A3050(u32 obj);
extern void func_021A3038(u32 obj, int *out);
extern void func_02164208(u32 v, int *pos, int step);
extern int func_0218B4B0(struct FieldInput *p, u8 *pos);
extern u32 func_0216D5B8(int p);
extern int func_02158D90(u16 v);
extern int func_0219F01C(void *sys, u8 *pos, u32 a, u32 m, int ev, u16 id);
extern u32 func_02162A54(void *p, void *q, int *pos, u32 d);
extern int func_02158768(void *sys, u32 msg, int a, u16 id);
extern u16 func_0218B56C(struct FieldInput *p, u8 *pos);
extern void *func_02012EBC(void *p);
extern void *func_0200BE48(void *p);
extern u16 func_02188C9C(u8 *p);
extern u32 func_021CFAC0(void *p, u16 v, s16 x, s16 y, s16 z);
extern int func_021CFC14(void *sys, u16 id, u32 v);
extern int func_021CD440(u8 *pos, u16 *out);
extern int func_02013FFC(u16 id);
extern u32 func_02162940(void *p, void *q, int *pos);
extern int func_0218B408(struct FieldInput *p, void *sys, u8 *pos);
extern int func_0218AED4(struct FieldInput *p, void *sys, u8 *pos);
extern int func_0218AF90(struct FieldInput *p, void *sys, u8 *pos);
extern int func_020221A4(void);
extern void *func_02188CCC(u8 *pos);
extern int func_0215FF34(void *sys);
extern int func_021A0ED4(void *p);
extern int func_0215FF54(void *sys, u8 *pos, u16 id);
extern int func_0201212C(void *sys);
extern int func_021C06CC(void *sys, u8 *pos);
extern int func_021A0F90(void *p);
extern int func_0215FC40(void *sys, u8 *pos, u16 id);
extern int func_021A0EB0(void *p, u32 flag);
extern int func_0218ACA8(void *sys);
extern int func_0217B410(u8 *pos, void *sys, u32 obj);

int func_02189BD0(void *sys, u8 *pos, int *outA, int *outB)
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
    r = func_0218A738(&in);
    if (r != 0) {
        *outA = 1;
        return r;
    }
    r = func_021C868C(sys, *func_02012ED0(in.f8));
    if (r != 0)
        return r;
    r = func_021AE0CC(pos);
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
        r = func_0218ACD0(&in, pos, in.f34);
        if (r != 0)
            return r;
        r = (int)func_0218AD28(&in, pos);
        if (r != 0)
            return r;
    }
    r = func_0218A9B0(&in, pos);
    if (r != 0)
        return r;
    if (in.b3) {
        r = func_0218A7F0(&in);
        if (r != 0)
            return r;
    }
    r = func_0218A824(&in);
    if (r != 0)
        return r;
    r = func_0218A878(&in, sys, pos);
    if (r != 0)
        return r;
    r = func_0218B208(&in, sys, pos);
    if (r != 0)
        return r;

    flags = 0;
    if (func_020142E8(func_0201296C(in.f8), 0x964) == 1)
        flags |= 1;
    r = func_021A2F20(in.f18, in.trg, in.cont, flags);
    if (r != 0)
        return r;

    obj = func_02012138(sys);
    ev = func_02158344(obj);
    model = func_021A3074(in.f18);
    if (func_0217BFD8(sys, in.f10) == 1)
        return func_0217CA84(sys, 0);
    if (func_02026454(obj) == 2 && ev != 0) {
        if (func_02012B70(in.f8) == 1 && func_0217C070(ev) == 1)
            return func_0217B810(sys, pos);
        if (func_0217689C(ev, in.f10) == 1)
            return func_0216B3A8(sys, 9, func_02012FB0(in.f8));
        if (in.b10 == 1 && func_021754B4(ev, &out) == 1) {
            func_021A2F6C(in.f18);
            return func_0217FC6C(sys, pos, ev, model, out, in.f0);
        }
        if (in.b3) {
            r = func_0217BDE0(sys, ev, in.f18);
            if (r != 0)
                return r;
        }
        if (in.b0 && func_0217AFC4(ev, in.f18, &out) == 1) {
            func_021A2F6C(in.f18);
            return func_0217FB5C(sys, pos, ev, model, out, in.f0);
        }
    }

    if (in.b0) {
        u32 dir = func_021A3050(in.f18);
        int target;
        u32 msg;
        int x;
        int y;
        int z;
        void *map;

        func_021A3038(in.f18, xyz);
        func_02164208(dir, xyz, 0x10000);
        target = func_0218B4B0(&in, pos);
        if (target != 0) {
            u32 kind = func_0216D5B8(target);

            if (func_02158D90(kind) == 1) {
                void *m = func_021A3074(in.f18);

                func_021A2F6C(in.f18);
                *outA = 1;
                return func_0219F01C(sys, pos, kind, m, target, in.f0);
            }
        }
        msg = func_02162A54(in.fC, func_0201296C(in.f8), xyz, dir);
        if (msg != 0xFFFF)
            return func_02158768(sys, msg, 0, in.f0);
        msg = func_0218B56C(&in, pos);
        if (msg != 0xFFFF)
            return func_02158768(sys, msg, 0, in.f0);
        x = xyz[0] >> 12;
        y = xyz[1] >> 12;
        z = xyz[2] >> 12;
        map = func_0200BE48(func_02012EBC(in.f8));
        msg = func_021CFAC0(map, func_02188C9C(pos), x / 16, y / 16, z / 16);
        if (msg != 0xFF)
            return func_021CFC14(sys, in.f0, msg);
        if (func_021CD440(pos, &id) == 1)
            return func_02158768(sys, 0x271B, 0, in.f0);
        if (func_02013FFC(in.f10)) {
            msg = func_02162940(in.fC, func_0201296C(in.f8), xyz);
            if (msg != 0xFFFF)
                return func_02158768(sys, msg, 0, in.f0);
        }
    }

    if (in.f1C == 3 || in.f1C == 0) {
        r = func_0218B408(&in, sys, pos);
        if (r != 0)
            return r;
    }
    if (in.b5) {
        r = func_0218AED4(&in, sys, pos);
        if (r != 0)
            return r;
        r = func_0218AF90(&in, sys, pos);
        if (r != 0)
            return r;
    }
    if (in.b6 && func_020221A4()) {
        void *pl = func_02188CCC(pos);

        if (func_0215FF34(sys) && func_021A0ED4(pl)) {
            r = func_0215FF54(sys, pos, in.f0);
            if (r != 0)
                return r;
        }
    }
    if (func_0201212C(sys) == 1 && func_020221A4() && in.b10)
        return func_021C06CC(sys, pos);
    if (in.b1 && func_020221A4()) {
        if (func_021A0F90(func_02188CCC(pos)) == 6)
            return 0;
        *outB = 1;
        return func_0215FC40(sys, pos, in.f0);
    }
    if (func_020221A4()) {
        r = func_021A0EB0(func_02188CCC(pos), in.b7);
        if (r != 0)
            return r;
    }
    if (in.b7 && func_020221A4()) {
        r = func_0218ACA8(sys);
        if (r != 0)
            return r;
    }
    r = func_0217B410(pos, sys, in.f18);
    if (r == 0)
        return 0;
    return r;
}
