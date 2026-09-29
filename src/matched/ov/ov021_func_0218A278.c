/*
 * function: func_0218A278
 * address:  0x0218A278
 * packet:   pkt_ov021_0218A278
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218A4E0  0x0218A4E0  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219E634  0x0219E634  thumb  ov021
 *   func_0218A738  0x0218A738  thumb  ov021
 *   func_0218A728  0x0218A728  thumb  ov021
 *   func_0201296C  0x0201296C  thumb
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_02162958  0x02162958  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 *   func_0218B0CC  0x0218B0CC  thumb  ov021
 *   func_0218A9B0  0x0218A9B0  thumb  ov021
 *   func_0218B208  0x0218B208  thumb  ov021
 *   func_0218B53C  0x0218B53C  thumb  ov021
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 *   func_02158D90  0x02158D90  thumb  ov010
 *   func_021A2F6C  0x021A2F6C  thumb  ov021
 *   func_0219F01C  0x0219F01C  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02162A5C  0x02162A5C  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0218B310  0x0218B310  thumb  ov021
 *   func_0218B13C  0x0218B13C  thumb  ov021
 *   func_0218B24C  0x0218B24C  thumb  ov021
 *   func_020221A4  0x020221A4  thumb
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_0215FF34  0x0215FF34  thumb  ov010
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_0215FF54  0x0215FF54  thumb  ov010
 *   func_0201212C  0x0201212C  thumb
 *   func_021C06CC  0x021C06CC  thumb  ov021
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_0215FC40  0x0215FC40  thumb  ov010
 *   func_021A0EB0  0x021A0EB0  thumb  ov021
 *   func_0218ACA8  0x0218ACA8  thumb  ov021
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

typedef struct Cell { u16 x, y, z, w; } Cell;

extern void func_0218A4E0(struct FieldInput *p, void *sys, u8 *pos);
extern u32 func_021A3074(u32 obj);
extern void func_0219E634(u32 obj, Cell *c);
extern int func_0218A738(struct FieldInput *p);
extern void func_0218A728(void *p);
extern void *func_0201296C(void *p);
extern void func_0219E2F4(u32 obj, int *b);
extern u16 func_02162958(void *set, void *flags, int *b);
extern int func_02158768(void *sys, u32 msg, int a, u16 id);
extern int func_0218B0CC(struct FieldInput *p, void *sys, u8 *pos);
extern int func_0218A9B0(struct FieldInput *p, u8 *pos);
extern int func_0218B208(struct FieldInput *p, void *sys, u8 *pos);
extern int func_0218B53C(struct FieldInput *p, u8 *pos);
extern u32 func_0216D5B8(int p);
extern int func_02158D90(u16 v);
extern void func_021A2F6C(u32 obj);
extern int func_0219F01C(void *sys, u8 *pos, u32 a, u32 m, int ev, u16 id);
extern u16 func_0216D5F8(u32 obj);
extern u16 func_02162A5C(void *set, void *flags, const void *where, u16 type);
extern u32 func_02188CB4(u8 *pos);
extern int func_0218B310(u32 obj, struct FieldInput *p);
extern int func_0218B13C(struct FieldInput *p, void *sys, u8 *pos, Cell *c);
extern int func_0218B24C(struct FieldInput *p, void *sys, u8 *pos);
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

int func_0218A278(void *sys, u8 *pos)
{
    struct FieldInput in;
    Cell here;
    int cur[2];
    Cell copy;
    u32 model;
    int r;
    u32 msg;

    func_0218A4E0(&in, sys, pos);
    model = func_021A3074(in.f18);
    func_0219E634(model, &here);
    r = func_0218A738(&in);
    if (r != 0)
        return r;
    if (in.b2)
        func_0218A728(in.f8);
    if (in.b2) {
        u32 obj = func_021A3074(in.f18);
        void *flags = func_0201296C(in.f8);

        func_0219E2F4(obj, cur);
        msg = func_02162958(in.fC, flags, cur);
        if (msg != 0xFFFF)
            return func_02158768(sys, msg, 0, in.f0);
        r = func_0218B0CC(&in, sys, pos);
        if (r != 0)
            return r;
        r = func_0218A9B0(&in, pos);
        if (r != 0)
            return r;
    }
    r = func_0218B208(&in, sys, pos);
    if (r != 0)
        return r;
    if (in.b0) {
        int target = func_0218B53C(&in, pos);
        void *flags;
        u16 d;

        if (target != 0) {
            u32 kind = func_0216D5B8(target);

            if (func_02158D90(kind) == 1) {
                u32 m = func_021A3074(in.f18);

                func_021A2F6C(in.f18);
                return func_0219F01C(sys, pos, kind, m, target, in.f0);
            }
        }
        flags = func_0201296C(in.f8);
        d = func_0216D5F8(model);
        copy = here;
        msg = func_02162A5C(in.fC, flags, &copy, d);
        if (msg != 0xFFFF)
            return func_02158768(sys, msg, 0, in.f0);
    }
    if (in.b5 && func_0218B310(func_02188CB4(pos), &in) == 0) {
        r = func_0218B13C(&in, sys, pos, &here);
        if (r != 0)
            return r;
    }
    r = func_0218B24C(&in, sys, pos);
    if (r != 0)
        return r;
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
        return func_0215FC40(sys, pos, in.f0);
    }
    {
        u32 f = (in.b7 && func_020221A4()) ? 1 : 0;

        r = func_021A0EB0(func_02188CCC(pos), f);
        if (r != 0)
            return r;
    }
    if (in.b7 && func_020221A4()) {
        r = func_0218ACA8(sys);
        if (r != 0)
            return r;
    }
    return 0;
}
