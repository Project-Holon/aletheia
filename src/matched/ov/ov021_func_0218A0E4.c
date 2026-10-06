/*
 * function: func_0218A0E4
 * address:  0x0218A0E4
 * packet:   pkt_ov021_0218A0E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0218A4E0  0x0218A4E0  thumb  ov021
 *   func_0200FB24  0x0200FB24  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021C06CC  0x021C06CC  thumb  ov021
 *   func_021850FC  0x021850FC  thumb  ov020
 *   func_0217391C  0x0217391C  thumb  ov012
 *   func_02173928  0x02173928  thumb  ov012
 *   func_02026400  0x02026400  thumb
 *   func_0218A784  0x0218A784  thumb  ov021
 *   func_0217B80C  0x0217B80C  thumb  ov019
 *   func_0217B83C  0x0217B83C  thumb  ov019
 *   func_0217394C  0x0217394C  thumb  ov012
 *   func_0218B4B0  0x0218B4B0  thumb  ov021
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 *   func_02158D90  0x02158D90  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0217AF38  0x0217AF38  thumb  ov019
 *   func_021A2F6C  0x021A2F6C  thumb  ov021
 *   func_0219F01C  0x0219F01C  thumb  ov021
 *   func_0201212C  0x0201212C  thumb
 *   func_0215FCE0  0x0215FCE0  thumb  ov010
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

struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026474(void *obj);
extern void func_0218A4E0(struct FieldInput *p, void *sys, u8 *pos);
struct Comm;
struct Ctx;
extern u32 func_0200FB24(void);
extern u32 func_020221A4(void);
extern int func_021C06CC(void *sys, u8 *pos);
extern void *func_021850FC(void *p, u8 *pos);
extern int func_0217391C(u8 *p);
extern int func_02173928(u8 *p);
extern void func_02026400(struct Comm *p);
struct Ctx784;
struct FieldCtx;
extern int func_0218A784(struct Ctx784 *c, int a);
extern int func_0217B80C(int a, int b);
extern int func_0217B83C(void *sys, void *pos);
extern int func_0217394C(const struct Ctx *p);
extern int func_0218B4B0(struct FieldCtx *p, u8 *pos);
extern u32 func_0216D5B8(void *p);
extern int func_02158D90(u16 v);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D588(void *p);
extern int func_0217AF38(u16 a);
extern void func_021A2F6C(u32 *p);
extern int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
extern u8 func_0201212C(const struct Ctx *p);
extern int func_0215FCE0(int a, int b, unsigned short c);

int func_0218A0E4(void *sys, u8 *pos)
{
    struct FieldInput in;
    void *a;
    void *ev;
    int r;
    int obj;
    u32 k;
    void *m;

    a = (void *)func_02012138(sys);
    ev = (void *)func_02026474(a);
    func_0218A4E0(&in, sys, pos);
    if (ev == 0) {
        if (func_0200FB24() != 0) {
            if (func_020221A4() != 0)
                return func_021C06CC(sys, pos);
            return 0;
        }
        return (int)func_021850FC(sys, pos);
    }
    if (func_0217391C(ev) == 1) {
        if (func_02173928(ev) == 0)
            func_02026400(a);
        return 0;
    }
    if (in.b2 && (r = func_0218A784((struct Ctx784 *)(&in), 9)) != 0)
        return r;
    if ((r = func_0217B80C((int)sys, (int)pos)) != 0)
        return r;
    if (in.b0 && (r = func_0217B83C(sys, pos)) != 0)
        return r;
    if (in.b0 && func_0217394C(sys) == 1) {
        obj = func_0218B4B0((struct FieldCtx *)(&in), pos);
        if (obj != 0) {
            k = func_0216D5B8((void *)obj);
            if (func_02158D90(k) == 1) {
                m = func_021A3074((u8 *)in.f18);
                if (func_0217AF38(func_0216D588((void *)obj)) == 0) {
                    func_021A2F6C((u32 *)in.f18);
                    return func_0219F01C((u32)sys, (u32)pos, k, (u32)m, obj, in.f0);
                }
            }
        }
    }
    if (func_0201212C(sys) == 1 && func_020221A4() != 0)
        return func_021C06CC(sys, pos);
    if (func_0217394C(sys) == 0)
        return 0;
    if (in.b1 && func_020221A4() != 0)
        return func_0215FCE0((int)sys, (int)pos, in.f0);
    return 0;
}
