/*
 * file:     unit_021D5EA8_p05.c
 * unit:     yes
 * function: func_021D6324, func_021D63B8, func_021D63EC, func_021D6408, func_021D6440, func_021D646C, func_021D64F0, func_021D6580, func_021D65C8
 * address:  0x021D6324
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_02082BCC 0x02082BCC arm
 *   func_021D67F4 0x021D67F4 thumb ov093
 *   func_021D6824 0x021D6824 thumb ov093
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_021D533C  0x021D533C  thumb  ov093
 *   func_021D5150  0x021D5150  thumb  ov093
 *   func_021D5364  0x021D5364  thumb  ov093
 *   func_021D539C  0x021D539C  thumb  ov093
 *   func_021D6E88  0x021D6E88  thumb  ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021D6D70  0x021D6D70  thumb  ov093
 *   func_021D53C0  0x021D53C0  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D4EFC  0x021D4EFC  thumb  ov093
 *   func_021D66A0 0x021D66A0 thumb ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   func_021D5970 0x021D5970 thumb ov093
 */
#include "../../matched/include/Obj00041.h"

struct Unk021D62A8;
struct S;
struct Unk021D6C2C;
struct UtilWork;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Slot_021D6324 { u32 a : 3; u32 rest : 29; };

struct UtilSlots { u8 pad[0x1c]; struct Slot_021D6324 s[16]; u8 pad5C[0x50]; u8 b[16]; };

typedef enum { SLOT_FIRST, SLOT_LIMIT=36, SLOT_UNSIGNED=0xFFFFFFFF } SlotIndex;

struct Slot_021D63B8 { u32 a:3; u32 rest:29; };

typedef struct {
    void *w;
    u8 pad4[0x12];
    u16 f16;
    u8 pad18[3];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj;

struct Slot_021D65C8 {u32 kind:3, rest:29;};

struct Byte7 {u8 v[7];};

struct Work {u8 pad[0x1c]; struct Slot_021D65C8 slots[36]; u8 counters[36]; u8 padD0[0x2c]; struct Byte7 copy; u8 pad103[0xef]; u16 f1f2;};

extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021E8A78(struct Slot_021D6324 s);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_02082BCC(void *, int, u32);
extern void func_021D67F4(u8 *);
extern void func_021D6824(u8 *);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_020185C4(void *p);
extern void func_021D533C(struct S *p);
extern void func_021D5150(struct Work *p);
extern void func_021D5364(struct UtilWork *p);
extern void func_021D539C(struct UtilWork *p);
extern void func_021D6E88(u8 *p);
extern void func_021D6C2C(struct Unk021D6C2C *p);
extern void func_021D6D70(unsigned char *p);
extern void func_021D53C0(unsigned char *p);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D4EFC(struct S *a, void *mon, u32 c, u32 d);
extern int func_021D66A0(u32);
extern void func_021D5FE4(u8 *p, unsigned int n);
extern int func_021D58A8(u8 *, int);
extern void func_021D5970(u8 *, int, u16);
int func_021D6324(struct UtilSlots *p, int k);
void func_021D63B8(u8 *p, int all);
void func_021D63EC(u8 *p, u16 n);
void func_021D6408(u8 *p);
void func_021D6440(u8 *p,u32 n);
void func_021D646C(Obj *p);
void func_021D64F0(Obj *p);
void func_021D6580(Obj *p);
void func_021D65C8(struct Work *p, struct Work *q);


int func_021D6324(struct UtilSlots *p, int k)
{
    if (func_021D62C4((struct Unk021D62A8 *)p, k) != 0) {
        switch (k) {
        case 5:
            if (func_021E8A78(p->s[k]) != 0)
                return func_021D7B74((u8 *)p, 0x10) * p->b[k];
            return func_021D7B74((u8 *)p, 8);
        case 4:
            return func_021D7B74((u8 *)p, 8);
        case 9:
            if (func_021D62C4((struct Unk021D62A8 *)p, 2) != 0)
                return func_021D7B74((u8 *)p, 4);
            break;
        case 10:
            return func_021D7B74((u8 *)p, 4);
        default:
            return 0;
        }
    }
    return 0;
}

/*
 * lever: enum loop counter with unsigned bound retains the entry guard;
 *   word-array indexing settles zero/offset scratch register allocation.
 */
void func_021D63B8(u8 *p, int all)
{
    SlotIndex i;
    i = 0;
    if (all == 0) i = 6;
    for (; i < 36U; i++) {
        ((u32 *)(p + 0x1c))[i] = 0;
        ((struct Slot_021D63B8 *)(p + 0x1c))[i].a = 0;
    }
    func_02082BCC(p + 0xac, 0, 36);
}

void func_021D63EC(u8 *p, u16 n)
{
    ((struct Obj00041 *)p)->f148 = n;
    ((struct Obj00041 *)p)->f146 = 0;
    p[0x1b] |= 0x80;
    func_021D67F4(p);
}

/*
 * volatile: halfword at +0x146 re-read at 021D641C and 021D6428.
 */
void func_021D6408(u8 *p)
{
    func_02082BCC(p + 0x153, 0, 2);
    if (*(volatile u16 *)&((struct Obj00041 *)p)->f146 < 9999)
        *(volatile u16 *)&((struct Obj00041 *)p)->f146 += 1;
    func_021D6824(p);
}

void func_021D6440(u8 *p,u32 n) { u8 *q; u8 i; u8 bit; q=p+0x153; i=n>>3; bit=1<<(n&7); q[i]&=(u8)~bit; }


void func_021D646C(Obj *p)
{
    func_02082BCC((u8 *)p + 0x153, 0, 2);
    func_02082BCC((u8 *)p + 0x155, 0, 2);
    func_021D533C((struct S *)p);
    func_021D5150((struct Work *)p);
    func_021D5364((struct UtilWork *)p);
    func_021D539C((struct UtilWork *)p);
    func_021D6E88((u8 *)p);
    func_021D6C2C((struct Unk021D6C2C *)p);
    func_021D6D70((unsigned char *)p);
    func_021D63B8((u8 *)p, 1);
    func_021D53C0((unsigned char *)((char *)p + 0xfc));
    ((u8 *)p)[0x141] = p->f1b_lo;
    ((struct Obj00041 *)p)->f13C = p->f16;
    func_02017E40(p->w, 0x6f, ((u8 *)p)[0x141]);
    func_020185C4(p->w);
}


void func_021D64F0(Obj *p)
{
    func_02082BCC((u8 *)p + 0x153, 0, 2);
    func_021D533C((struct S *)p);
    func_021D5150((struct Work *)p);
    func_021D5364((struct UtilWork *)p);
    func_021D539C((struct UtilWork *)p);
    func_021D6E88((u8 *)p);
    func_021D6C2C((struct Unk021D6C2C *)p);
    if (func_021D5BDC((struct UtilWork *)p, 0xe) == 0) {
        func_021D6D70((unsigned char *)p);
        func_021D63B8((u8 *)p, 0);
        func_021D53C0((unsigned char *)((char *)p + 0xfc));
        func_02082BCC((u8 *)p + 0x155, 0, 2);
    }
    ((u8 *)p)[0x141] = p->f1b_lo;
    ((struct Obj00041 *)p)->f13C = p->f16;
    func_02017E40(p->w, 0x6f, ((u8 *)p)[0x141]);
    func_020185C4(p->w);
}


void func_021D6580(Obj *p)
{
    func_021D4EFC((struct S *)p, p->w, 0, 1);
    func_02082BCC((u8 *)p + 0x155, 0, 2);
    func_02082BCC((u8 *)p + 0x153, 0, 2);
    func_021D6D70((unsigned char *)p);
    func_021D5364((struct UtilWork *)p);
    func_021D63B8((u8 *)p, 0);
    func_021D53C0((unsigned char *)((char *)p + 0xfc));
}

void func_021D65C8(struct Work *p, struct Work *q)
{
    unsigned long i;
    u16 t;
    u16 t2;
    p->copy = q->copy;
    p->f1f2 = q->f1f2;
    for (i = 0; i < 36; i++) {
        if (q->slots[i].kind != 0 && func_021D66A0(i)) {
            p->slots[i] = q->slots[i];
            p->counters[i] = q->counters[i];
        }
    }
    if (func_021D5BDC((void *)q, 10)) {
        func_021D5FE4((u8 *)p, 10);
        t = func_021D58A8((u8 *)p, 8);
        t2 = func_021D58A8((u8 *)p, 9);
        func_021D5970((u8 *)p, 8, t2);
        func_021D5970((u8 *)p, 9, t);
    }
    if (func_021D5BDC((void *)q, 9)) func_021D5FE4((u8 *)p, 9);
    func_021D6D70((u8 *)q);
    func_021D63B8((void *)q, 0);
    func_021D53C0((unsigned char *)((char *)q + 0xfc));
    func_02082BCC((u8 *)q + 0x155, 0, 2);
}
