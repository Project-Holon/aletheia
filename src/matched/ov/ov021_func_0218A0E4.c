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

extern void *func_02012138(void *sys);
extern void *func_02026474(void *p);
extern void func_0218A4E0(struct FieldInput *p, void *sys, u8 *pos);
extern int func_0200FB24(void);
extern int func_020221A4(void);
extern int func_021C06CC(void *sys, u8 *pos);
extern int func_021850FC(void *sys, u8 *pos);
extern int func_0217391C(void *ev);
extern int func_02173928(void *ev);
extern void func_02026400(void *p);
extern int func_0218A784(struct FieldInput *p, int d);
extern int func_0217B80C(void *sys, u8 *pos);
extern int func_0217B83C(void *sys, u8 *pos);
extern int func_0217394C(void *sys);
extern int func_0218B4B0(struct FieldInput *p, u8 *pos);
extern u32 func_0216D5B8(int p);
extern int func_02158D90(u16 v);
extern void *func_021A3074(u32 p);
extern u32 func_0216D588(int p);
extern int func_0217AF38(u32 v);
extern void func_021A2F6C(u32 obj);
extern int func_0219F01C(void *sys, u8 *pos, u32 a, void *m, int ev, u16 id);
extern int func_0201212C(void *sys);
extern int func_0215FCE0(void *sys, u8 *pos, u16 id);

int func_0218A0E4(void *sys, u8 *pos)
{
    struct FieldInput in;
    void *a;
    void *ev;
    int r;
    int obj;
    u32 k;
    void *m;

    a = func_02012138(sys);
    ev = func_02026474(a);
    func_0218A4E0(&in, sys, pos);
    if (ev == 0) {
        if (func_0200FB24() != 0) {
            if (func_020221A4() != 0)
                return func_021C06CC(sys, pos);
            return 0;
        }
        return func_021850FC(sys, pos);
    }
    if (func_0217391C(ev) == 1) {
        if (func_02173928(ev) == 0)
            func_02026400(a);
        return 0;
    }
    if (in.b2 && (r = func_0218A784(&in, 9)) != 0)
        return r;
    if ((r = func_0217B80C(sys, pos)) != 0)
        return r;
    if (in.b0 && (r = func_0217B83C(sys, pos)) != 0)
        return r;
    if (in.b0 && func_0217394C(sys) == 1) {
        obj = func_0218B4B0(&in, pos);
        if (obj != 0) {
            k = func_0216D5B8(obj);
            if (func_02158D90(k) == 1) {
                m = func_021A3074(in.f18);
                if (func_0217AF38(func_0216D588(obj)) == 0) {
                    func_021A2F6C(in.f18);
                    return func_0219F01C(sys, pos, k, m, obj, in.f0);
                }
            }
        }
    }
    if (func_0201212C(sys) == 1 && func_020221A4() != 0)
        return func_021C06CC(sys, pos);
    if (func_0217394C(sys) == 0)
        return 0;
    if (in.b1 && func_020221A4() != 0)
        return func_0215FCE0(sys, pos, in.f0);
    return 0;
}
