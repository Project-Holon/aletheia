/*
 * file:     box2_seq_p16.c
 * unit:     yes
 * function: func_021E6A60, func_021E6C3C, func_021E6CD4, func_021E6D00, func_021E6EC0
 * address:  0x021E6A60
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EA750 0x021EA750 thumb
 *   func_021ECB60 0x021ECB60 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EBB28 0x021EBB28 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DD2B4 0x021DD2B4 thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021DD718 0x021DD718 thumb
 *   func_021DD8A8 0x021DD8A8 thumb
 *   func_021EC48C 0x021EC48C thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021ED094 0x021ED094 thumb
 *   func_021ED108 0x021ED108 thumb
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021ED1C8 0x021ED1C8 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E122C 0x021E122C thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   func_021EBA70 0x021EBA70 thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_020260F0 0x020260F0 thumb
 *   func_021EA728 0x021EA728 thumb
 *   func_020362DC 0x020362DC arm
 *   func_021EA9F4 0x021EA9F4 thumb
 *   func_021EF194 0x021EF194 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EA598 0x021EA598 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_021E7258 0x021E7258 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021EEB40 0x021EEB40 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021EAA3C 0x021EAA3C thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EA66C 0x021EA66C thumb
 */
#include "../../matched/include/Obj00000.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define ITEM(p) (*(unsigned short *)(WORK(p) + 0xA16C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))
#define STATE(p) (*(int *)((p) + 0x28))
#define NIB(p) ((Nib *)((p) + 0x1C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define CUR(p) (*(unsigned short *)(WORK(p) + 0xA16E))
#define TGT(p) (*(unsigned char *)(WORK(p) + 0xA17E))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))
struct Sound;
struct WinMgr;
struct Struct_02025CD0;
typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct { unsigned char pad[0x1C]; unsigned char lo:4; unsigned char hi:4; } Flags;

typedef unsigned short u16;

typedef struct {
    unsigned char pad0[2];
    unsigned char pad2[0x26];
    unsigned short h28;
} Top;

typedef struct {
    Top *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char pad15;
    unsigned char b16;
    unsigned char b17;
    unsigned char pad18[3];
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1D[0x24 - 0x1D];
    int x24;
    int x28;
    char *work;
} Obj;

extern void func_021ED6E4(char **p, int v);
extern void func_021EA750(char *p);
extern void func_021ECB60(char *w, int i, int f);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE038(char *p, int a, int b, int c);
extern unsigned func_0202136C(unsigned short v);
extern void func_020061E4(unsigned se);
extern void func_021EBB28(char *p, int b);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern int func_021DD718(void **pp, void *mon);
extern void func_021DD8A8(void **pp, u32 idx);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFEC(char *p, int b);
extern void func_021ED094(char *w, unsigned item);
extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);
extern void func_021ED1C8(char *w);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E122C(unsigned char *p);
extern void func_021ED55C(char **p, int flag);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EBA70(char *,int);
extern void func_021DD14C(char *);
extern u32 func_020260F0(struct Sound *obj);
extern void func_021EA728(void *p);
extern u32 func_020362DC(void);
extern int func_021EA9F4(Obj *p, int v);
extern unsigned func_021EF194(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021EF5E8(struct WinMgr *mgr);
extern int func_021EA598(Obj *p, int i);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF040(char *p);
extern int func_021E7258(char *p);
extern unsigned func_021EEB40(char *p);
extern int func_021E8F50(char *p, int v);
extern int func_021E949C(char *p, int a, int b);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021EAA3C(Obj *p, int v);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021EA66C(Obj *p, int i);
int func_021E6A60(unsigned char *p);
int func_021E6C3C(unsigned char *p);
int func_021E6CD4(u8 *p);
int func_021E6D00(unsigned char *p);
int func_021E6EC0(Obj *p);

#define OBJ(p) (*(void **)(WORK(p) + 0x70))


/*
 * Drop of a held item onto a slot: put it back when dropped where it was
 * picked up, otherwise swap the two slots' items.
 */
int func_021E6A60(unsigned char *p)
{
    Entry *o;
    if (NIB(p)->lo == 0)
        NIB(p)->hi = 1;
    func_021ED6E4((char **)p, 0);
    o = *(Entry **)(WORK(p) + 0x60);
    if (o->idx == p[0x16] && (p[0x17] == 0xFF || p[0x17] == p[0x14])) {
        unsigned short from = o->slot;
        func_021EA750((char *)p);
        func_021ECB60(WORK(p), p[0x16], 0);
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE038((char *)p, 0, 1, 1);
        if (func_0202136C(ITEM(p)) == 1 && from != p[0x16]) {
            func_020061E4(0x557);
            func_021EBB28((char *)p, 0x18);
            STATE(p) = 0x44;
            return 6;
        }
        return 0x40;
    } else {
        unsigned short item;
        if (p[0x17] == p[0x14] || p[0x16] >= 0x1E)
            func_021ECB60(WORK(p), p[0x16], 1);
        func_021ECB60(WORK(p), o->idx, 0);
        item = func_021DD25C((void ***)p, o->idx, p[0x14], 6, 0);
        func_021DD2B4((int)p, o->idx, p[0x14], 6, ITEM(p));
        if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], o->idx)) == 1) {
            func_021DD8A8((void **)p, o->idx);
            func_021EC48C(p, p[0x14], o->idx, WIN(p, o->idx));
        }
        func_021DEFEC((char *)p, o->idx);
        func_020260E4(OBJ(p), o->idx);
        ITEM(p) = item;
        func_021DD2B4((int)p, p[0x16], p[0x17], 6, ITEM(p));
        if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x17], p[0x16])) == 1) {
            func_021DD8A8((void **)p, p[0x16]);
            if (p[0x17] == 0xFF || p[0x17] == p[0x14])
                func_021EC48C(p, p[0x14], p[0x16], WIN(p, p[0x16]));
        }
        if (ITEM(p) == 0) {
            p[0x16] = o->idx;
            func_021EA750((char *)p);
            func_021EE038((char *)p, 0, 1, 1);
            return 0x40;
        }
        func_021ED094(WORK(p), ITEM(p));
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        func_021ED1C8(WORK(p));
        func_020061E4(0x666);
        return func_021E8FC0((char *)p, (int)func_021E122C, 0x43);
    }
}

int func_021E6C3C(unsigned char *p)
{
    unsigned short *o;
    unsigned char old;
    unsigned short slot, item;
    unsigned char r;
    if (((Flags *)p)->lo == 0)
        ((Flags *)p)->hi = 1;
    o = *(unsigned short **)(WORK(p) + 0x60);
    func_021ECB60(WORK(p), o[0], 0);
    old = p[0x16];
    slot = o[1];
    p[0x16] = o[0];
    func_021EA750((char *)p);
    item = *(unsigned short *)(WORK(p) + 0xA16C);
    *(unsigned short *)(WORK(p) + 0xA16C) = 0;
    if (func_0202136C(item) == 1 && slot != old) {
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBB28((char *)p, 0x18);
        ((struct Obj00000 *)p)->f28 = 0x44;
        return 6;
    }
    func_021ED55C((char **)p, 1);
    r = func_020260E0(*(void **)(WORK(p) + 0x70));
    if (r < 0x24)
        func_021DEFEC((char *)p, r);
    func_021EE038((char *)p, 0, 1, 1);
    return 0x40;
}

/*
 *   unsigned func_020260F0(unsigned char *p) { return *(unsigned *)(p+4); }
 */
int func_021E6CD4(u8 *p){func_021EBA70(*(char **)(p+0x2c),24);func_021DD14C((char *)p);if(func_020260F0(*(void **)(*(char **)(p+0x2c)+0x70))==1)func_021EC000(*(char **)(p+0x2c),4,1);return 64;}

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))


/*
 * Twin of func_021E6A60 driven by the work fields: moves the held item from
 * slot 0xA16E to slot 0xA17E, swapping with what is there.
 */
int func_021E6D00(unsigned char *p)
{
    unsigned short item;
    if (NIB(p)->lo == 0)
        NIB(p)->hi = 1;
    if (TGT(p) == CUR(p) && (p[0x17] == 0xFF || p[0x17] == p[0x14])) {
        ITEM(p) = 0;
        func_021EE038((char *)p, 0, 1, 1);
        return 0x40;
    }
    if (p[0x17] == p[0x14] || CUR(p) >= 0x1E)
        func_021ECB60(WORK(p), CUR(p), 1);
    func_021ECB60(WORK(p), TGT(p), 0);
    item = func_021DD25C((void ***)p, TGT(p), p[0x14], 6, 0);
    func_021DD2B4((int)p, TGT(p), p[0x14], 6, ITEM(p));
    if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], TGT(p))) == 1) {
        func_021DD8A8((void **)p, TGT(p));
        func_021EC48C(p, p[0x14], TGT(p), WIN(p, TGT(p)));
    }
    func_021DEFEC((char *)p, TGT(p));
    ITEM(p) = item;
    func_021DD2B4((int)p, CUR(p), p[0x17], 6, ITEM(p));
    if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x17], CUR(p))) == 1) {
        func_021DD8A8((void **)p, CUR(p));
        if (p[0x17] == 0xFF || p[0x17] == p[0x14])
            func_021EC48C(p, p[0x14], CUR(p), WIN(p, CUR(p)));
    }
    if (ITEM(p) == 0) {
        func_021EE038((char *)p, 0, 1, 1);
        return 0x40;
    }
    func_021EA728(p);
    (*(Entry **)(WORK(p) + 0x60))->idx = TGT(p);
    func_021ED094(WORK(p), ITEM(p));
    func_021ED108(WORK(p), 1);
    func_021EBFA8(WORK(p), 10, 1);
    func_021EC000(WORK(p), 10, 1);
    func_021ED1C8(WORK(p));
    func_020061E4(0x666);
    return func_021E8FC0((char *)p, (int)func_021E122C, 0x43);
}

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))


/*
 * Sibling of src/matched/ov170_func_021E5E68.c and ov170_func_021E376C.c.
 */
int func_021E6EC0(Obj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        r = func_021EA9F4(p, 0x3F);
        if (p->lo == 1) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 6)
                p->b16 = v + 0x1E;
            else
                p->b16 = 0x1E;
        }
        return r;
    }
    r = func_021EF194();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            func_021DEFEC((char *)p, (int)r + 0x1E);
            return func_021EA598(p, r + 0x1E);
        }
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EEF74(p->work, (unsigned char)r, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), r + 0x1E);
            return func_021E7258((char *)p);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        return 0x46;
    }
    r = func_021EEB40((char *)p);
    switch (r) {
    case 6:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 10, func_021E8F50((char *)p, 0x1C));
    case 7:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C(p, 7, 8, 0x10);
    case 8:
        func_020061E4(0x551);
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x1C));
    case 9:
        func_020061E4(0x54C);
        p->lo = 0;
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x3F));
    case 10:
        func_020061E4(0x54C);
        if (*(unsigned short *)(p->work + 0xA16C) == 0) {
            p->b13 = 1;
            p->x24 = 10;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
        }
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
    case 11: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16 - 0x1E;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x47);
    }
    case 12:
        r = func_021EAA3C(p, 0x3F);
        if (p->lo == 1) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 6)
                p->b16 = v + 0x1E;
            else
                p->b16 = 0x1E;
        }
        return r;
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 6)
            func_021DEFEC((char *)p, v + 0x1E);
        else if (v == 6)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x46));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x47);
        }
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x1C));
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            return func_021EA66C(p, r + 0x1E);
        }
        break;
    }
    return 0x46;
}
