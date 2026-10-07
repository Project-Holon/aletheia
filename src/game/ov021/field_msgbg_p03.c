/*
 * file:     field_msgbg_p03.c
 * unit:     yes
 * function: func_0218A824, func_0218A878, func_0218A8BC, func_0218A9B0, func_0218AA2C, func_0218AA74, func_0218AAD0, func_0218AB0C, func_0218AB50, func_0218AB9C, func_0218AC08, func_0218AC4C, func_0218AC84, func_0218ACA8
 * address:  0x0218A824
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
 *   func_0218A784  0x0218A784  thumb
 *   func_0217B4D8  0x0217B4D8  thumb ov018
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021A2FA4  0x021A2FA4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB188  0x021AB188  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0216282C  0x0216282C  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021A3098  0x021A3098  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_02188C84  0x02188C84  thumb
 *   func_02188C80  0x02188C80  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02008970  0x02008970  thumb
 *   func_0200896C  0x0200896C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C3378  0x021C3378  thumb
 *   func_02008978  0x02008978  thumb
 *   func_02008980  0x02008980  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02013FFC  0x02013FFC  thumb
 *   func_021D220C  0x021D220C  thumb
 *   func_02008990  0x02008990  thumb
 *   func_02008988  0x02008988  thumb
 *   func_0200D564  0x0200D564  thumb
 *   func_02188CE8  0x02188CE8  thumb
 *   func_021AA944  0x021AA944  thumb
 *   func_021AA80C  0x021AA80C  thumb
 *   func_02010F18  0x02010F18  thumb
 *   func_020124AC  0x020124AC  thumb
 *   abs_id_83      0x00000053  data
 *   func_021F532C  0x021F532C  thumb  ov083
 */
#include "../../matched/include/Obj04981.h"

struct Ctx784;
struct Ctx;
struct Obj00020;
struct VecFx32;
struct BigObj;
struct Desc;
struct Rec;
struct Big;
struct Sub02008828Obj;
struct Blk38;
struct Self;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

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

struct BgEvent {
    u16 msg;
    char pad02[0x06];
    u16 f8;
    struct {
        u16 x;
        u16 z;
        u16 w;
        u16 h;
    } rect;
};

struct Ctx9B0 {
    char pad00[0x08];
    void *f8;
    char pad0C[0x04];
    u16 f10;
    char pad12[0x2A];
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
};

extern int func_0218A784(struct Ctx784 *c, int a);
extern u32 func_02013D5C(u32 id);
extern u16 func_021A2FA4(u8 *p, u32 a1);
extern void *func_0217B4D8(void *a, void *b, void *c, int *d, u16 e, int f);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *id, struct VecFx32 *out);
extern u32 func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB188(u16 id);
extern u32 func_0201296C(const struct BigObj *p);
extern struct Rec *func_0216282C(struct Ctx *c, void *a, int *key, int mode);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern u32 func_021A3098(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D7C4(u8 *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern void func_02008970(const struct Sub02008828Obj *obj, u32 *out);
extern void func_0200896C(struct Sub02008828Obj *obj, u32 value);
extern u32 func_02010FF4(u32 v);
extern void *func_02012934(const struct BigObj *p);
extern void *func_02188D50(u8 *p);
extern int func_021C3378(void **p);
extern u16 func_02008978(const struct Sub02008828Obj *obj);
extern void func_02008980(struct Sub02008828Obj *obj, u16 value);
extern u16 func_02188C9C(u8 *p);
extern void func_0201B7EC(void *mon, int a, int b);
extern u32 func_02013FFC(u32 id);
extern int func_021D220C(void *msg, u8 *pos);
extern u16 func_02008990(const struct Sub02008828Obj *obj);
extern void func_02008988(struct Sub02008828Obj *obj, u16 value);
extern void *func_0200D418(void *p);
extern u32 func_0200D564(struct Blk38 *p);
extern u32 func_02188CE8(u8 *p);
extern int func_021AA944(struct Self *self);
extern void func_021AA80C(struct Ctx *ctx);
extern u8 func_02010F18(void);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void func_021F532C(void *p);
int func_0218A824(struct FieldCtx *p);
void *func_0218A878(u8 *p, void *a, void *b);
int func_0218A8BC(struct FieldCtx *p);
int func_0218A9B0(struct Ctx9B0 *p, u8 *pos);
int func_0218AA2C(void *party);
void func_0218AA74(void *party);
void func_0218AAD0(void *sys, void *party);
int func_0218AB0C(void *party);
int func_0218AB50(void *p, u8 *pos, void *msg, void *sys);
void func_0218AB9C(void *sys, u8 *pos);
int func_0218AC08(void *msg, u8 *pos, u16 id);
int func_0218AC4C(u8 *pos, void *msg, void *sys);
int func_0218AC84(u8 *pos, void *msg, void *sys);
struct Desc *func_0218ACA8(void *a);
extern u8 abs_id_83[];


/*
 * Maps the held d-pad bits (up, down, left, right) to a direction and, unless
 * it is the current facing, none, or the movement mode is 1 or 2, tries
 * func_0218A784 with it. The two-value mode test is a switch.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A824(struct FieldCtx *p)
{
    u32 keys = p->f2C;
    u32 mode = p->f1C;
    int dir = 9;

    if (keys & 0x40)
        dir = 0;
    else if (keys & 0x80)
        dir = 1;
    else if (keys & 0x20)
        dir = 2;
    else if (keys & 0x10)
        dir = 3;
    if (dir == p->f24)
        return 0;
    if (dir == 9)
        return 0;
    switch (mode) {
    case 1:
    case 2:
        return 0;
    }
    return func_0218A784((struct Ctx784 *)p, dir);
}


/*
 * When flag field 0x10 is set and func_021A2FA4 does not report 9, forwards
 * the object to ov018 func_0217B4D8; returns 0 otherwise.
 *
 * Addresses are Black-image addresses.
 */
void *func_0218A878(u8 *p, void *a, void *b)
{
    int r;

    if (func_02013D5C(((struct Obj04981 *)p)->f10) == 0)
        return 0;
    r = func_021A2FA4(((struct Obj04981 *)p)->f18, ((struct Obj04981 *)p)->f2C);
    if (r == 9)
        return 0;
    return func_0217B4D8(a, b, ((struct Obj04981 *)p)->f18, *(int * *)&((struct Obj04981 *)p)->f34, ((struct Obj04981 *)p)->f24, r);
}


/*
 * Checks the background event in front of the player: shows its message when
 * the player stands at the event's centre tile, or when the tile behaviour is
 * one of 0x58..0x5B or 0xA3..0xA6 (range test spelled as the add of the
 * complement,
 * docs/idioms/a-masked-byte-subtract-in-a-range-test-is-an-add-of-the-complement.md)
 * or func_021A3098 allows it.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A8BC(struct FieldCtx *p)
{
    void *obj = func_0201210C(p->f4);
    void *id = func_02188CB4(obj);
    int pos[3];
    struct BgEvent *e;
    int a;
    u16 b;
    u32 cx;
    u16 *r;
    u32 cz;

    func_021A3038(id, (struct VecFx32 *)pos);
    if (func_021AB188(func_021AB0F0(func_021AB0D4((void *)func_02188C98(obj), pos))) != 1)
        return 0;
    e = (struct BgEvent *)func_0216282C(p->fC, (void *)func_0201296C(p->f8), pos, 9);
    if (e == 0)
        return 0;
    if (e->f8 != 0)
        return 0;
    r = (u16 *)&e->rect;
    cz = r[1] + ((u32)r[3] >> 1);
    cx = e->rect.x + ((u32)r[2] >> 1);
    if (cx == (pos[0] >> 12) / 16 && cz == (pos[2] >> 12) / 16)
        return (int)func_02158768((int)p->f4, e->msg, 0, p->f0);
    a = func_021A3098(id);
    b = func_0216D7C4(func_021A3074(id));
    if (a != 0 || b == 0x58 || b == 0x59 || b == 0x5A || b == 0x5B || (u16)(b + 0xFF5D) <= 3)   /* b - 0xA3 */
        return (int)func_02158768((int)p->f4, e->msg, 0, p->f0);
    return 0;
}


/*
 * Field step handler: runs the step-triggered checks in order (func_0218AC84,
 * the 128-step counter, milestones, egg hatching, the save flag message) and
 * returns the first non-zero result. Flags come from the u32 bitfield at
 * 0x3C.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A9B0(struct Ctx9B0 *p, u8 *pos)
{
    void *msg;
    void *sys;
    int r;

    func_02188C84(pos);
    msg = func_02188C80(pos);
    sys = func_020120F4(msg);
    if (p->b2 || p->b9) {
        r = func_0218AC84(pos, msg, sys);
        if (r != 0)
            return r;
    }
    if (!p->b2)
        return 0;
    func_0218AB9C(p->f8, pos);
    r = func_0218AC08(msg, pos, p->f10);
    if (r != 0)
        return r;
    r = func_0218AB50(p, pos, msg, sys);
    if (r != 0)
        return r;
    r = func_0218AC4C(pos, msg, sys);
    if (r == 0)
        return 0;
    return r;
}


/*
 * Returns 2 when a non-egg party member holds item 0x31 or 0x28, else 1.
 */
int func_0218AA2C(void *party)
{
    int count = func_0201AA18(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 item = func_02017E1C(mon, 0xA, 0);
        if (func_02017E1C(mon, 0x4C, 0) == 0 && (item == 0x31 || item == 0x28))
            return 2;
    }
    return 1;
}


/*
 * For every egg in the party, lowers field 9 (the step counter) by the amount
 * from func_0218AA2C, clamping at zero.
 *
 * Addresses are Black-image addresses.
 */
void func_0218AA74(void *party)
{
    int count = func_0201AA18(party);
    u32 amount = func_0218AA2C(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 flag = func_02017E1C(mon, 0x4C, 0);
        u32 v = func_02017E1C(mon, 9, 0);
        if (flag == 1) {
            u32 nv = 0;
            if (v >= amount)
                nv = v - amount;
            func_02017E40(mon, 9, nv);
        }
    }
}


/*
 * Adds func_02010FF4(0x100) to the step accumulator in the save block; once
 * it passes 0x10000 it advances the party's egg counters (func_0218AA74) and
 * resets it.
 *
 * Addresses are Black-image addresses.
 */
void func_0218AAD0(void *sys, void *party)
{
    void *save = func_02008854(func_02012EBC(sys));
    u32 steps;

    func_02008970(save, &steps);
    steps += func_02010FF4(0x100);
    if (steps > 0x10000) {
        func_0218AA74(party);
        steps = 0;
    }
    func_0200896C(save, steps);
}


/*
 * Returns 1 when some egg in the party has field 9 (the step counter) at
 * zero.
 */
int func_0218AB0C(void *party)
{
    int count = func_0201AA18(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 flag = func_02017E1C(mon, 0x4C, 0);
        u32 v = func_02017E1C(mon, 9, 0);
        if (flag == 1 && v == 0)
            return 1;
    }
    return 0;
}


/*
 * Step hook: updates func_021C3378, advances the party step counter
 * (func_0218AAD0) and, when an egg is ready (func_0218AB0C), shows message
 * 0x8CA.
 *
 * Addresses are Black-image addresses.
 */
int func_0218AB50(void *p, u8 *pos, void *msg, void *sys)
{
    u16 v = func_02188C84(pos);
    void *party = func_02012934(sys);

    func_021C3378(func_02188D50(pos));
    func_0218AAD0(sys, party);
    if (func_0218AB0C(party))
        return (int)func_02158768((int)msg, 0x8CA, 0, v);
    return 0;
}


/*
 * Bumps a 7-bit counter in the save block; when it wraps, calls func_0201B7EC
 * on every party member with the two coordinates read from the position
 * object.
 *
 * Addresses are Black-image addresses.
 */
void func_0218AB9C(void *sys, u8 *pos)
{
    void *save = func_02008854(func_02012EBC(sys));
    int wrapped = 0;
    u16 count = func_02008978(save) + 1;

    if (count >= 0x80) {
        count = 0;
        wrapped = 1;
    }
    func_02008980(save, count);
    if (wrapped) {
        void *party = func_02012934(sys);
        int a;
        int b;
        int n;
        int i;

        a = func_02188C9C(pos);
        b = func_02188C84(pos);
        n = func_0201AA18(party);
        for (i = 0; i < n; i++)
            func_0201B7EC(func_0201AB28(party, i), a, b);
    }
}


/*
 * When func_02013FFC accepts the id, shows the milestone message
 * (func_021D220C) and increments the save block counter; returns the message
 * result.
 *
 * Addresses are Black-image addresses.
 */
int func_0218AC08(void *msg, u8 *pos, u16 id)
{
    void *save = func_02008854(func_02012EBC(func_020120F4(msg)));
    int r = 0;

    if (func_02013FFC(id)) {
        r = func_021D220C(msg, pos);
        func_02008988(save, func_02008990(save) + 1);
    }
    return r;
}


int func_0218AC4C(u8 *pos, void *msg, void *sys)
{
    if ((u8)func_0200D564(func_0200D418(func_02012EBC(sys))))
        return (int)func_02158768((int)msg, 0x2792, 0, func_02188C84(pos));
    return 0;
}


/*
 * Runs func_021AA944 on the position's object; when it declines, calls
 * func_021AA80C and returns 0.
 *
 * Addresses are Black-image addresses.
 */
int func_0218AC84(u8 *pos, void *msg, void *sys)
{
    void *obj;
    int r;

    func_02012EBC(sys);
    obj = (void *)func_02188CE8(pos);
    r = func_021AA944(obj);
    if (r == 0) {
        func_021AA80C(obj);
        return 0;
    }
    return r;
}


struct Desc *func_0218ACA8(void *a)
{
    if (func_02010F18() == 0x30) {
        return 0;
    }
    return func_020124AC(a, (u32)abs_id_83, (u32 (*)(void *, u32))func_021F532C, 0);
}
