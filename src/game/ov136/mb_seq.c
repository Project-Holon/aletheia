/*
 * file:     mb_seq.c
 * unit:     yes
 * function: func_021C6984, func_021C6A5C, func_021C6AD4, func_021C6AF0, func_021C6B4C, func_021C6BC4, func_021C6BD8, func_021C6BF0, func_021C6C34, func_021C6E18, func_021C6E28, func_021C6E64, func_021C6E98, func_021C6EA4, func_021C6FA8, func_021C6FD4, func_021C7024, func_021C7048, func_021C7064, func_021C7084, func_021C7094, func_021C70C0, func_021C70EC, func_021C7110, func_021C714C, func_021C7178, func_021C71A8, func_021C71BC, func_021C71D0, func_021C7250, func_021C7298, func_021C730C, func_021C7350, func_021C7360, func_021C73C8, func_021C7420, func_021C7430, func_021C7494, func_021C74BC, func_021C74C8, func_021C74F8, func_021C7504, func_021C7540, func_021C758C, func_021C7600, func_021C7620, func_021C7648, func_021C7658, func_021C76A8, func_021C76B8, func_021C76BC, func_021C76C0, func_021C76C8, func_021C76D0, func_021C770C, func_021C7738
 * address:  0x021C6984
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020056A0       0x020056A0  thumb
 *   func_0203064C   0x0203064C  arm
 *   func_02030734        0x02030734  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4             0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02082AC0    0x02082AC0  arm
 *   func_021C54FC 0x021C54FC thumb
 *   func_021C5508 0x021C5508 thumb
 *   func_021C5518 0x021C5518 thumb
 *   func_021C574C 0x021C574C thumb
 *   func_021C5828 0x021C5828 thumb
 *   func_021C587C 0x021C587C thumb
 *   func_021C5924 0x021C5924 thumb
 *   func_021C59B8 0x021C59B8 thumb
 *   func_021C5B40 0x021C5B40 thumb
 *   func_021C5C00 0x021C5C00 thumb
 *   func_021C5DD8 0x021C5DD8 thumb
 *   func_021C5E58 0x021C5E58 thumb
 *   func_021C6170 0x021C6170 thumb
 *   func_021C64A8 0x021C64A8 thumb
 *   d_021C7F04 0x021C7F04 data a1
 *   func_020307B0 0x020307B0 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021C5AA8 0x021C5AA8 thumb ov136
 *   func_021C5954 0x021C5954 thumb ov136
 *   func_021C5E30 0x021C5E30 thumb ov136
 *   func_021C657C 0x021C657C thumb ov136
 *   func_021C5918 0x021C5918 thumb ov136
 *   func_021C5F44 0x021C5F44 thumb ov136
 *   func_021C5714 0x021C5714 thumb ov136
 *   func_021C5BE0 0x021C5BE0 thumb ov136
 *   func_020221A4  0x020221A4  thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   d_021C7D68 0x021C7D68 data a4
 *   func_021C5C84  0x021C5C84  thumb
 *   d_021C7D78 0x021C7D78 data a4
 *   func_02031330 0x02031330 arm
 *   d_021C7D7C 0x021C7D7C data a4
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C7738 0x021C7738 thumb
 *   func_021C66B8 0x021C66B8 thumb
 *   func_021C5C64  0x021C5C64  thumb
 *   func_021C6284 0x021C6284 thumb
 *   func_021C62BC 0x021C62BC thumb
 *   func_021C5AEC  0x021C5AEC  thumb
 *   func_02008FA4 0x02008FA4 thumb
 *   func_020213AC 0x020213AC thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_0202CC70  0x0202CC70  thumb
 *   func_021C5B30 0x021C5B30 thumb
 *   func_021C61CC 0x021C61CC thumb
 *   func_021C62F4 0x021C62F4 thumb
 *   func_021C630C 0x021C630C thumb
 *   func_021C6884 0x021C6884 thumb
 *   func_021C61D0 0x021C61D0 thumb ov136
 *   func_0204B98C   0x0204B98C  arm
 *   func_0202208C   0x0202208C  thumb
 *   func_021C5974 0x021C5974 thumb
 *   func_021C670C 0x021C670C thumb ov136
 *   func_0207D63C 0x0207D63C arm
 *   func_021C5D68 0x021C5D68 thumb
 *   func_021C6374 0x021C6374 thumb
 *   func_02008FC8 0x02008FC8 thumb
 *   func_02024450 0x02024450 thumb
 *   func_020414EC 0x020414EC arm
 *   func_0200902C 0x0200902C thumb
 *   func_02031348  0x02031348  arm
 *   ov091_id 0x0000005B data
 *   d_021BED00 0x021BED00 data ov091 a4
 *   func_0202138C  0x0202138C  thumb
 *   func_021C3CC0  0x021C3CC0  thumb
 *   d_021C7D5C 0x021C7D5C data a4
 *   func_021C3E00 0x021C3E00 thumb ov136
 *   func_021C3E04 0x021C3E04 thumb ov136
 *   func_021C3E24 0x021C3E24 thumb ov136
 *   func_02035C08  0x02035C08  arm
 *   d_021C7E2C 0x021C7E2C data a4
 *   func_02025CD0 0x02025CD0 thumb
 *   d_021C7E40 0x021C7E40 data a4
 *   d_021C7E1C 0x021C7E1C data a4
 *   func_02025D14  0x02025D14  thumb
 *   func_0202616C  0x0202616C  thumb
 *   func_021C66CC 0x021C66CC thumb
 *   d_021C7E14 0x021C7E14 data a4
 */
#include "ov136_types.h"

struct Node;
struct Rec3;
struct TaskMenu;
struct PrintSys;
struct Sound;
struct WinMgr;
struct Sub02008F80Obj;
struct Actor;
struct Obj0202DC98;
struct Sub02008F80Entry;
struct BigObj;
struct Struct_02025CD0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

struct HandlerPair { int (*a)(u8 *); int (*b)(u8 *); };

struct StateEnt {
    void (*fn)(u8 *);
    u32 a;
    u32 b;
};

struct StateCall { int (*call)(u8 *); int result; int other; };

struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};

typedef signed char s8;

typedef signed short s16;

struct Control {
    u8 enabled : 1;
    u8 mode : 7;
    u8 action : 4;
    u8 phase : 4;
    u8 a, b, c, d, e, f;
};

struct Flags { u8 index : 7; u8 flag : 1; };

extern void func_02030EAC(struct Node *n);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204363C(u32);
extern void func_0203064C(u32, u32, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(u32, void *, u32);
extern void func_021C5B40(u8 *);
extern void func_021C5508(void);
extern void func_021C5518(u8 *);
extern void func_021C574C(u8 *);
extern void func_021C5828(void *a0);
extern void func_021C5E58(u8 *);
extern void func_021C587C(u8 *);
extern void func_021C64A8(u8 *);
extern void func_021C5DD8(u8 *);
extern void func_021C5924(u8 *);
extern void func_021C6170(u8 *);
extern void func_021C5C00(u8 *);
extern void func_021C59B8(u8 *);
extern void func_021C54FC(void *);
extern void *func_020056A0(void (*)(void *), void *, u32);
extern void func_0203D34C(u32, u32);
extern void func_021C5AA8(u8 *);
extern void func_021C5954(u8 *p);
extern void func_021C5E30(u8 *p);
extern void func_021C657C(u8 *);
extern void func_021C5918(u8 *p);
extern void func_021C5F44(u8 *p);
extern void func_021C5714(void *);
extern void func_021C5BE0(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_020306F0(u32);
extern u32 func_020221A4(void);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
extern int func_021C5C84(u8 *p);
extern unsigned int func_02031330(void *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021C66A0(u8 *p, int i, u32 v);
extern int func_02025DE8(struct Sound *obj);
extern u8 func_020260E0(struct Sound *obj);
extern int func_021C7738(void);
extern void func_021C66B8(u8 *, int, u32);
extern void func_021C5C64(u8 *);
extern void func_021C62BC(u8 *);
extern void func_021C6284(u8 *);
extern void func_021C5AEC(u8 *);
extern void func_021C5B30(u8 *);
extern void func_021C62F4(u8 *);
extern void func_021C61CC(u8 *);
extern void func_021C6884(u8 *);
extern void func_021C630C(u8 *p, unsigned int i);
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern u16 func_020213AC(u32);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_021C61D0(void *);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021C5974(u8 *);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0202CFC0(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
extern void func_021C670C(u8 *p, int i, int on);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_021C5D68(u8 *);
extern void func_021C6374(u8 *);
extern struct Sub02008F80Entry *func_02008FC8(struct Sub02008F80Obj *obj, u32 i);
extern int func_02024450(const u16 *p);
extern void func_0202DC9C(struct Obj0202DC98 *o, int i, u32 a1);
extern void func_020414EC(u32);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0200CA1C(void *a);
extern void func_02031348(void *, u32, const void *, void *);
extern u8 func_0202138C(u16 v);
extern void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
extern u32 func_021C3E00(u32 *p);
extern int func_021C3E04(u32 *p, void *q);
extern void func_021C3E24(u8 *);
extern void *func_0201AB28(void *, u32);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern int func_02035C08(const void *);
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern u32 func_02025D14(void *a0);
extern void *func_0202616C(void **obj, u32 idx);
extern void func_021C66CC(u8 *, int, int, int);
int func_021C6984(u8 *p);
u32 func_021C6A5C(u8 *p);
int func_021C6AD4(struct MbSeqCtx *p);
u32 func_021C6AF0(u8 *p);
int func_021C6B4C(u8 *p);
int func_021C6BC4(u8 *p);
int func_021C6BD8(u8 *p);
int func_021C6BF0(u8 *p);
int func_021C6C28(u8 *p);
int func_021C6C34(u8 *p);
int func_021C6E18(u8 *p);
int func_021C6E28(u8 *p);
void func_021C6E64(u8 *p);
int func_021C6E98(u8 *p);
int func_021C6EA4(u8 *p);
int func_021C6FA8(struct MbSeqCtx *p);
int func_021C6FD4(u8 *p);
int func_021C7018(char *p);
void func_021C7024(char *p);
int func_021C703C(char *p);
int func_021C7048(u8 *p);
void func_021C7064(u8 *p);
void func_021C7084(u8 *p);
int func_021C7094(u8 *p);
int func_021C70C0(struct MbSeqCtx *p);
int func_021C70EC(struct MbSeqCtx *p);
int func_021C7110(u8 *p);
int func_021C714C(u8 *p, u32 v);
int func_021C7178(u8 *p, u32 v);
int func_021C71A8(char *p, int v, int w);
int func_021C71BC(u8 *p, int v);
int func_021C71D0(u8 *p, int v, int w);
int func_021C7250(u8 *p, int v, int w);
void func_021C7298(void *p, int v);
void func_021C730C(void *p);
void func_021C7350(u8 *p);
void func_021C7360(u8 *p);
void func_021C73C8(u8 *p);
void func_021C7420(u8 *p);
void func_021C7430(u8 *p, int a, u16 b, u16 c);
int func_021C7494(u8 *p);
int func_021C74BC(struct MbSeqCtx *p);
int func_021C74C8(u8 *p);
int func_021C74F8(struct MbSeqCtx *p);
int func_021C7504(u8 *p);
int func_021C7540(u8 *p);
void func_021C758C(u8 *p);
int func_021C7600(u8 *p);
void func_021C7620(u8 *p);
int func_021C7648(u8 *p);
void func_021C7658(u8 *p);
void func_021C76A8(u8 *p);
void func_021C76B8(void);
void func_021C76BC(void);
void func_021C76C0(u8 *p, u32 v);
void func_021C76C8(u8 *p, u32 v);
void func_021C76D0(u8 *p, u32 v);
int func_021C770C(struct MbSeqCtx *a0);
extern const char d_021C7F04[];
extern const struct HandlerPair d_021C7D68[];
extern const struct StateEnt d_021C7D78[];
extern const struct StateCall d_021C7D7C[];
extern const u8 d_021BED00[];
extern u8 ov091_id[];
extern const u8 d_021C7D5C[];
extern const u8 d_021C7E2C[];
extern const u8 d_021C7E40[],d_021C7E1C[];
extern const u8 d_021C7E14[];




int func_021C6984(u8 *p)
{
    if (((struct MbSeqCtx *)p)->f2C != 0) {
        func_02030EAC(((struct MbSeqCtx *)p)->f2C);
        *(u32 *)&((struct MbSeqCtx *)p)->f2C = 0;
    }
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(0);
    func_0203064C(1, 0x66, 0x60000);
    ((struct MbSeqCtx *)p)->f8 = func_02030734(0x66, 0x370, 0, d_021C7F04, 0x10C);
    func_02082AC0(0, ((struct MbSeqCtx *)p)->f8, 0x370);
    func_021C5B40(p);
    func_021C5508();
    func_021C5518(p);
    func_021C574C(p);
    func_021C5828(p);
    func_021C5E58(p);
    func_021C587C(p);
    func_021C64A8(p);
    func_021C5DD8(p);
    func_021C7658(p);
    func_021C5924(*(u8 * *)&((struct MbSeqCtx *)p)->f8);
    func_021C6170(p);
    func_021C5C00(p);
    func_021C59B8(p);
    ((struct MbSeqCtx *)p)->f2C = func_020056A0(func_021C54FC, p, 1);
    func_0203D34C(0, 0x66);
    return ((struct MbSeqCtx *)p)->f28;
}




u32 func_021C6A5C(u8 *p)
{
    if (((struct MbSeqCtx *)p)->f2C != 0) {
        func_02030EAC(((struct MbSeqCtx *)p)->f2C);
        ((struct MbSeqCtx *)p)->f2C = 0;
    }
    func_021C5AA8(p);
    func_021C5954(((struct MbSeqCtx *)p)->f8);
    func_021C76A8(p);
    func_021C5E30(p);
    func_021C657C(p);
    func_021C5918(p);
    func_021C5F44(p);
    func_021C5714(p);
    func_021C5BE0(p);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_020307B0(((struct MbSeqCtx *)p)->f8);
    ((struct MbSeqCtx *)p)->f8 = 0;
    func_020306F0(102);
    return ((struct MbSeqCtx *)p)->f28;
}





/*
 * Addresses are Black-image addresses.
 */
int func_021C6AD4(struct MbSeqCtx *p)
{
    if (func_020221A4() == 1)
        return *(int *)&((struct MbUnitBCtx *)p->f8)->f308;
    return 2;
}




u32 func_021C6AF0(u8 *p)
{
    if (func_0201CE30(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1C8) == 2) {
        if ((*(u8 * *)&((struct MbSeqCtx *)p)->f8)[0x1dd] == 0) {
            func_0201CE48(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1C8);
            return ((struct MbSeqCtx *)p)->f28;
        }
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
            func_0201CE48(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1C8);
            func_020061E4(1352);
            return ((struct MbSeqCtx *)p)->f28;
        }
    }
    return 3;
}




int func_021C6B4C(u8 *p)
{
    func_02027974(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f310);
    if (func_020279E8(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f310) == 0) return 4;
    switch (func_02027A04(*(u8 * *)&((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f310)) {
    case 0:
        func_02027858(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f310);
        return d_021C7D68[*(int *)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x1E0)].a(p);
    case 1:
        func_02027858(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f310);
        return d_021C7D68[*(int *)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x1E0)].b(p);
    }
    return 4;
}





int func_021C6BC4(u8 *p)
{
    if (func_021C5C84(p) == 0)
        return *(int *)&((struct MbSeqCtx *)p)->f28;
    return 5;
}




int func_021C6BD8(u8 *p)
{
    d_021C7D78[*(u32 *)(p + 0x14)].fn(p);
    return 7;
}




int func_021C6BF0(u8 *p)
{
    if (func_02031330(((struct MbSeqCtx *)p)->f30) == 1) return 7;
    *(int *)&((struct MbSeqCtx *)p)->f28 = d_021C7D7C[*(int *)&((struct MbSeqCtx *)p)->f14].call(p);
    return d_021C7D7C[*(int *)&((struct MbSeqCtx *)p)->f14].result;
}




int func_021C6C28(u8 *p)
{
    return func_021C714C(p, 9);
}





int func_021C6C34(u8 *p)
{
    u32 k;
    u8 *r;

    if (func_0201C6B4(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1C4) == 0) {
        return 9;
    }
    switch (func_021C7648(p)) {
    case 0:
        if (((struct MbSeqCtx *)p)->f1C != 0) {
            ((struct MbSeqCtx *)p)->f1C -= 1;
            func_020061E4(0x548);
            return func_021C7250(p, 0, 0xB);
        }
        return 9;
    case 1:
        if (((struct MbSeqCtx *)p)->f1C != ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f2FE) {
            ((struct MbSeqCtx *)p)->f1C += 1;
            func_020061E4(0x548);
            return func_021C7250(p, 1, 0xB);
        }
        return 9;
    case 2:
        func_020061E4(0x551);
        func_021C66A0(((struct MbSeqCtx *)p)->f8, 3, 9);
        ((struct MbSeqCtx *)p)->f28 = 10;
        return 0x18;
    case 3:
        func_020061E4(0x556);
        func_021C66A0(((struct MbSeqCtx *)p)->f8, 7, 8);
        ((struct MbSeqCtx *)p)->f28 = 10;
        return 0x19;
    }
    k = func_02025DE8(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f294);
    switch (k) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        r = *(u8 * *)&((struct MbSeqCtx *)p)->f8 + k + ((struct MbSeqCtx *)p)->f1C * 10;
        if (r[0x2E8] == 0xFF) {
            break;
        }
        p[0x1E] = k;
        p[0x1F] = r[0x2E8];
        func_020061E4(0x54C);
        return func_021C71D0(p, k, 0xC);
    case (u32)-2:
        func_020061E4(0x551);
        func_021C66A0(((struct MbSeqCtx *)p)->f8, 3, 9);
        ((struct MbSeqCtx *)p)->f28 = 10;
        return 0x18;
    case (u32)-5:
        func_020260E0(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f294);
        if (((struct MbSeqCtx *)p)->f1C != ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f2FE) {
            ((struct MbSeqCtx *)p)->f1C += 1;
            func_020061E4(0x548);
            return func_021C7250(p, 1, 0xB);
        }
        break;
    case (u32)-6:
        func_020260E0(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f294);
        if (((struct MbSeqCtx *)p)->f1C != 0) {
            ((struct MbSeqCtx *)p)->f1C -= 1;
            func_020061E4(0x548);
            return func_021C7250(p, 0, 0xB);
        }
        break;
    case (u32)-3:
        func_020061E4(0x548);
        break;
    case (u32)-4:
        break;
    default:
        if (func_021C7738()) {
            func_020061E4(0x556);
            func_021C66A0(((struct MbSeqCtx *)p)->f8, 7, 8);
            ((struct MbSeqCtx *)p)->f28 = 10;
            return 0x19;
        }
        break;
    }
    return 9;
}












int func_021C6E18(u8 *p)
{
    ((struct MbSeqCtx *)p)->f28 = 0x1b;
    return func_021C7178(p, 1);
}



int func_021C6E28(u8 *p)
{
    if (((struct MbSeqCtx *)p)->f1C == 0) {
        func_021C66B8(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 0, 0);
        func_021C66B8(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 1, 1);
    } else {
        func_021C66B8(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 0, 1);
        func_021C66B8(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 1, 0);
    }
    func_021C5C00(p);
    return 9;
}












void func_021C6E64(u8 *p)
{
    func_021C66B8(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 2, 0);
    func_021C7298(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 1);
    func_021C5C64(p);
    func_021C62BC(p);
    func_021C6284(p);
    func_021C71A8((char *)p, 0, 0xD);
}












int func_021C6E98(u8 *p)
{
    func_021C5AEC(p);
    return 0xE;
}












int func_021C6EA4(u8 *p)
{
    func_02027974(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f310);
    if (func_020279E8(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f310) == 0) {
        return 0xE;
    }
    switch (func_02027A04(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f310)) {
    case 0:
        func_021C5B30(p);
        func_021C62F4(p);
        func_021C66B8(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 2, 0);
        func_021C61CC(*(u8 * *)&((struct MbSeqCtx *)p)->f8);
        func_021C6884(*(u8 * *)&((struct MbSeqCtx *)p)->f8);
        func_021C7350(p);
        func_021C66A0(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 7, 0xE);
        func_021C730C(*(u8 * *)&((struct MbSeqCtx *)p)->f8);
        return 0xF;
    case 1:
        func_021C5B30(p);
        func_021C630C(p, 0);
        return func_021C71A8((char *)p, 0, 0x11);
    case 2: {
        u8 k;
        func_021C5B30(p);
        k = p[0x1F];
        func_021C7430(p, 0xE, func_020213AC(func_02008FA4(*(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + k * 4 + 0x298))), k);
        *(unsigned int *)&((struct MbSeqCtx *)p)->f14 = 0;
        ((struct MbSeqCtx *)p)->f28 = 6;
        return func_021C7178(p, 1);
    }
    case -2:
    case 3:
        func_021C5B30(p);
        func_021C62F4(p);
        func_0202CC70(**(void ** *)&((struct MbSeqCtx *)p)->f8, 10);
        func_021C7298(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 0);
        func_021C66B8(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 2, 1);
        return 9;
    default:
        return 0xE;
    }
}












int func_021C6FA8(struct MbSeqCtx *p)
{
    if (func_021C770C(p) == 1) {
        func_020061E4(0x551);
        func_021C66A0(*(u8 * *)&p->f8, 3, 9);
        p->f28 = 0x10;
        return 0x18;
    }
    return 0xF;
}












int func_021C6FD4(u8 *p)
{
    func_021C7360(p);
    func_021C76D0(p, func_020260E0(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f294));
    func_021C61D0(((struct MbSeqCtx *)p)->f8);
    func_0202CC70(**(void ** *)&((struct MbSeqCtx *)p)->f8, 10);
    func_021C66B8(((struct MbSeqCtx *)p)->f8, 2, 1);
    func_021C7298(((struct MbSeqCtx *)p)->f8, 0);
    return 9;
}












int func_021C7018(char *p)
{
    return func_021C71BC((u8 *)p, 0);
}












/*
 * extent: stops before separately filed leaf func_021C7048.
 */
void func_021C7024(char *p)
{
    func_021C630C((unsigned char *)p, 2);
    func_021C71A8(p, 0, 0x13);
}












int func_021C703C(char *p)
{
    return func_021C71BC((u8 *)p, 1);
}












int func_021C7048(u8 *p)
{
    if (p[0x20] != 6) {
        *(int *)&((struct MbSeqCtx *)p)->f28 = 0x15;
        return 0;
    }
    *(int *)&((struct MbSeqCtx *)p)->f14 = 2;
    return 6;
}












void func_021C7064(u8 *p)
{
    func_021C66B8(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 2, 0);
    func_021C7298(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 1);
    func_021C714C(p, 0x16);
}












void func_021C7084(u8 *p)
{
    func_021C62BC(p);
    func_021C7620(p);
}












int func_021C7094(u8 *p)
{
    if (*(unsigned int *)&((struct MbSeqCtx *)p)->f24 == 0) {
        ((struct MbSeqCtx *)p)->f28 = 0x15;
        return 0;
    }
    func_021C7430(p, 0xB, ((struct MbSeqCtx *)p)->f22, ((struct Bf7 *)(p + 0x21))->v);
    *(unsigned int *)&((struct MbSeqCtx *)p)->f14 = 3;
    return 6;
}












int func_021C70C0(struct MbSeqCtx *p)
{
    if (func_0204B98C(((struct MbUnitBCtx *)p->f8)->f1FC) == 0) {
        ((struct MbSeqCtx_f4 *)p->f4)->f4 = 0;
        func_021C66A0(*(u8 * *)&p->f8, 7, 0);
        return p->f28;
    }
    return 0x18;
}












int func_021C70EC(struct MbSeqCtx *p)
{
    if (func_0204B98C(((struct MbUnitBCtx *)p->f8)->f20C) == 0) {
        ((struct MbSeqCtx_f4 *)p->f4)->f4 = 1;
        return p->f28;
    }
    return 0x19;
}












int func_021C7110(u8 *p)
{
    func_021C62F4(p);
    func_0202CC70(**(void ** *)&((struct MbSeqCtx *)p)->f8, 10);
    func_021C76D0(p, func_020260E0(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f294));
    func_021C66B8(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 2, 1);
    func_021C7298(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 0);
    return 9;
}












int func_021C714C(u8 *p, u32 v)
{
    func_0202208C((void *)0, 1, 1, 0, 6, 1, 0x66);
    ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f308 = v;
    return 2;
}












int func_021C7178(u8 *p, u32 v)
{
    func_0202208C((void *)0, 0, 0, 0, 6, 1, 0x66);
    ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f308 = v;
    return 2;
}












int func_021C71A8(char *p, int v, int w)
{
    ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1DD = v;
    *(int *)&((struct MbSeqCtx *)p)->f28 = w;
    return 3;
}











int func_021C71BC(u8 *p, int v)
{
    ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1E0 = v;
    func_021C5974(p);
    return 4;
}











int func_021C71D0(u8 *p, int v, int w)
{
    struct Temp { s8 b, a; u16 c, d; } t;
    struct Control *q;
    func_0202CF98(**(void ** *)&((struct MbSeqCtx *)p)->f8, v, &t.a, &t.b);
    func_0202CFC0(**(void ** *)&((struct MbSeqCtx *)p)->f8, v, &t.d, &t.c);
    q = (struct Control *)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x300);
    q->enabled = 1;
    q->mode = 2;
    q->action = 2;
    q->phase = 1;
    q->a = 0;
    q->b = 0;
    q->c = t.a;
    q->d = t.b;
    q->e = t.d;
    q->f = t.c;
    *(int *)&((struct MbSeqCtx *)p)->f28 = w;
    return 5;
}











/*
 * extent: trailing 021C7296 halfword is zero alignment padding.
 */
int func_021C7250(u8 *p, int v, int w)
{
    struct Control *q = (struct Control *)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x300);
    q->enabled = 0;
    q->mode = (u8)v;
    q->action = 1;
    q->phase = 0;
    q->a = 0;
    q->b = 0;
    *(int *)&((struct MbSeqCtx *)p)->f28 = w;
    return 5;
}











/*
 * volatile: hardware register write at 021C7302 (0x04000050).
 */
void func_021C7298(void *p, int v)
{
    if (v == 1) {
        func_021C670C(p, 0, 1);
        func_021C670C(p, 1, 1);
        func_021C670C(p, 3, 1);
        func_021C670C(p, 7, 1);
        func_0207D63C((void *)0x04000050, 4, 8, 4, 12);
    } else {
        func_021C670C(p, 0, 0);
        func_021C670C(p, 1, 0);
        func_021C670C(p, 3, 0);
        func_021C670C(p, 7, 0);
        *(volatile unsigned short *)0x04000050 = 0;
    }
}











void func_021C730C(void *p)
{
    func_021C670C(p, 0, 1);
    func_021C670C(p, 1, 1);
    func_021C670C(p, 3, 0);
    func_021C670C(p, 7, 0);
    func_0207D63C((void *)0x04000050, 4, 8, 4, 12);
}











void func_021C7350(u8 *p)
{
    func_021C5D68(p);
    func_021C6374(p);
}











/*
 *   2026-10-02: src/matched/arm9/func_02024450.c exists (EXACT) but has no shard yet.
 *   After the integrator runs manifest on it, re-run: expect EXACT.
 *   Verified Thumb C is preserved here; ARM9 filing belongs to Ilias.
 *   typedef unsigned short u16;
 *   int func_02024450(const u16 *p)
 *   {
 *       if (*p != 0xFFFF) return 1;
 *       return 0;
 *   }
 */
void func_021C7360(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (func_02024450((const u16 *)func_02008FC8(*(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + p[0x1F]*4 + 0x298), (u8)i)) != 0) {
            func_0202DC9C(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f35C, (u8)i, (int)0);
        }
    }
    if (((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f364 != 0) {
        func_0202DC9C(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f35C, (u8)i, (int)0);
    }
    func_020414EC(4);
    func_020414EC(5);
}











/*
 * extent: trailing 021C741E halfword is zero alignment padding.
 */
void func_021C73C8(u8 *p)
{
    void *q = func_0201292C(**(void ** *)&((struct MbSeqCtx *)p)->f4);
    ((struct MbSeqCtx *)p)->f22 = func_020213AC(func_02008FA4(*(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + p[0x1F]*4 + 0x298)));
    if (func_02007E50(q, ((struct MbSeqCtx *)p)->f22, 1, 0x66) == 1) {
        ((struct Flags *)(p + 0x21))->flag = 0;
        return;
    } else {
        ((struct Flags *)(p + 0x21))->flag = 1;
        return;
    }
}











void func_021C7420(u8 *p)
{
    func_0200902C(((struct MbSeqCtx *)p)->f0, 0, p[0x1F]);
}











void func_021C7430(u8 *p, int a, u16 b, u16 c)
{
    u8 *q = func_02030734(0x65, 0x98, 1, d_021C7F04, 0x529);
    ((struct MbSeqCtx *)q)->f0 = func_02012934(**(void ** *)&((struct MbSeqCtx *)p)->f4);
    ((struct MbSeqCtx *)q)->f4 = func_0201292C(**(void ** *)&((struct MbSeqCtx *)p)->f4);
    ((struct MbSeqCtx *)q)->f8 = ((struct MbSeqCtx *)p)->f0;
    ((struct MbSeqCtx *)q)->f38 = 0;
    ((struct MbSeqCtx *)q)->f34 = a;
    ((struct MbSeqCtx *)q)->f44 = b;
    ((struct MbSeqCtx *)q)->f5C = c;
    ((struct MbSeqCtx *)q)->f18 = (u32)func_0200CA1C(**(void ** *)&((struct MbSeqCtx *)p)->f4);
    *(u8 * *)&((struct MbSeqCtx *)p)->f10 = q;
}











int func_021C7494(u8 *p)
{
    u32 v = ((struct Bf7 *)(p + 0x21))->v;
    ((struct MbSeqCtx_f10 *)((struct MbSeqCtx *)p)->f10)->f3C = v;
    func_02031348(((struct MbSeqCtx *)p)->f30, (u32)ov091_id, d_021BED00, ((struct MbSeqCtx *)p)->f10);
    return 0;
}










int func_021C74BC(struct MbSeqCtx *p)
{
    func_020307B0(p->f10);
    return 8;
}










int func_021C74C8(u8 *p)
{
    u8 *q = *(u8 * *)&((struct MbSeqCtx *)p)->f10;
    ((struct Bf7 *)(p + 0x21))->v = *(unsigned int *)&((struct MailViewCtx *)q)->f3C;
    p[0x20] = *(unsigned int *)&((struct MailViewCtx *)q)->f40;
    func_020307B0(q);
    return 0;
}










int func_021C74F8(struct MbSeqCtx *p)
{
    func_020307B0(p->f10);
    return 8;
}








int func_021C7504(u8 *p)
{
    ((struct MbSeqCtx *)p)->f10 = (void *)func_021C3CC0(**(void ** *)&((struct MbSeqCtx *)p)->f4, 2, ((struct Bf7 *)(p + 0x21))->v, func_0202138C(((struct MbSeqCtx *)p)->f22), 0x65);
    func_02031348(((struct MbSeqCtx *)p)->f30, (u32)-1, d_021C7D5C, ((struct MbSeqCtx *)p)->f10);
    return 0;
}







/*
 * extent: trailing 021C758A halfword is zero alignment padding.
 */
int func_021C7540(u8 *p)
{
    ((struct MbSeqCtx *)p)->f24 = func_021C3E00((u32 *)(*(u8 * *)&((struct MbSeqCtx *)p)->f10));
    if (((struct MbSeqCtx *)p)->f24 == 1) {
        func_021C3E04((u32 *)(*(u8 * *)&((struct MbSeqCtx *)p)->f10), func_0201AB28(func_02012934(**(void ** *)&((struct MbSeqCtx *)p)->f4), ((struct Flags *)(p + 0x21))->index));
        func_02007F1C(func_0201292C(**(void ** *)&((struct MbSeqCtx *)p)->f4), ((struct MbSeqCtx *)p)->f22, 1, 0x65);
    }
    func_021C3E24(*(u8 * *)&((struct MbSeqCtx *)p)->f10);
    return 0;
}






/*
 * func_021C73C8 0x021C73C8 thumb ov136
 * func_021C7420 0x021C7420 thumb ov136
 * func_021C5BE0 0x021C5BE0 thumb ov136
 * func_021C5B40 0x021C5B40 thumb ov136
 * func_021C66B8 0x021C66B8 thumb ov136
 * func_021C5C00 0x021C5C00 thumb ov136
 * func_021C630C 0x021C630C thumb ov136
 * func_021C71A8 0x021C71A8 thumb ov136
 */
void func_021C758C(u8 *p)
{
    u16 n;
    func_021C73C8(p); func_021C7420(p); func_021C5BE0(p); func_021C5B40(p);
    if(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f2FC<=10) {
        func_021C66B8(((struct MbSeqCtx *)p)->f8,0,0);
        func_021C66B8(((struct MbSeqCtx *)p)->f8,1,0);
    }
    n=((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f2FE;
    if(((struct MbSeqCtx *)p)->f1C>n) { ((struct MbSeqCtx *)p)->f1C=n; p[30]=0; }
    func_021C5C00(p);
    func_0202CC70(**(void ** *)&((struct MbSeqCtx *)p)->f8,10);
    func_021C630C(p,1);
    func_021C71A8((char *)p,1,18);
}






int func_021C7600(u8 *p)
{
    func_021C7430(p, 9, ((struct MbSeqCtx *)p)->f22, 0);
    *(unsigned int *)&((struct MbSeqCtx *)p)->f14 = 1;
    ((struct MbSeqCtx *)p)->f28 = 6;
    return func_021C7178(p, 1);
}






static inline unsigned int choose(const struct Bf7 *flag)
{
    return flag->w==0 ? 3 : 4;
}






/*
 * lever: call in each conditional arm keeps p live in r0 and bit test in r1;
 *   inline selector/ternary instead use r0 for test and rebuild p, DIFF17/38.
 * extent: 38 code bytes followed by two zero alignment bytes at021C7646;
 *   next function begins021C7648 outside this inferred40-byte extent.
 */
void func_021C7620(u8 *p)
{
    if(((const struct Bf7 *)(p+0x21))->w==0)
        func_021C630C(p,3);
    else
        func_021C630C(p,4);
    func_021C71A8((char *)p, 1, 0x1A);
}






int func_021C7648(u8 *p)
{
    return func_02035C08(d_021C7E2C);
}




void func_021C7658(u8 *p)
{
    int v;
    u16 n=((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f2FE;
    if (((struct MbSeqCtx *)p)->f1C>n) { ((struct MbSeqCtx *)p)->f1C=n; v=0; }
    else v=p[0x1e];
    *(unsigned int *)&((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f294=(u32)func_02025CD0((u32)d_021C7E40,(u32)d_021C7E1C,(u32)p,1,v,102);
    func_021C76D0(p,v);
}



void func_021C76A8(u8 *p)
{
    func_02025D14(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f294);
}


void func_021C76B8(void)
{
}


void func_021C76BC(void)
{
}


void func_021C76C0(u8 *p, u32 v)
{
    func_021C76D0(p, v);
}


void func_021C76C8(u8 *p, u32 v)
{
    func_021C76D0(p, v);
}


void func_021C76D0(u8 *p, u32 v)
{
    u8 *q = func_0202616C(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f294, v);
    func_021C66CC(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 2, q[0], q[1]);
    if (v == 10) {
        func_021C66A0(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 2, 4);
    } else {
        func_021C66A0(*(u8 * *)&((struct MbSeqCtx *)p)->f8, 2, 5);
    }
}


int func_021C770C(struct MbSeqCtx *a0)
{
    if (func_02035C08(d_021C7E14) != -1) {
        return 1;
    }
    if ((func_020362DC() & 3) != 0) {
        return 1;
    }
    return 0;
}

int func_021C7738(void)
{
    return (func_020362DC() & 0x400) ? 1 : 0;
}

