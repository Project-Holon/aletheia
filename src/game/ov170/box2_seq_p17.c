/*
 * file:     box2_seq_p17.c
 * unit:     yes
 * function: func_021E7258, func_021E7298, func_021E73D8, func_021E754C, func_021E75E0, func_021E78F4, func_021E7904, func_021E79C8, func_021E7A10, func_021E7BD0
 * address:  0x021E7258
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
 *   func_021EF57C  0x021EF57C  thumb  ov170
 *   func_021ED6E4  0x021ED6E4  thumb  ov170
 *   func_021EBA5C  0x021EBA5C  thumb  ov170
 *   func_021DD14C  0x021DD14C  thumb  ov170
 *   func_021EF670  0x021EF670  thumb  ov170
 *   func_021EF68C  0x021EF68C  thumb  ov170
 *   func_021E8FE0  0x021E8FE0  thumb  ov170
 *   func_021E8FC0  0x021E8FC0  thumb  ov170
 *   func_021EA750 0x021EA750 thumb ov170
 *   func_021EBCB4 0x021EBCB4 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_0202136C 0x0202136C thumb
 *   func_021ECB60 0x021ECB60 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8F50 0x021E8F50 thumb ov170
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DD2B4 0x021DD2B4 thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021DD718 0x021DD718 thumb
 *   func_021DD8A8 0x021DD8A8 thumb
 *   func_021EC48C 0x021EC48C thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021ED094 0x021ED094 thumb
 *   func_021ED1C8 0x021ED1C8 thumb
 *   func_021E1988 0x021E1988 thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EEEA4 0x021EEEA4 thumb
 *   func_021ED588 0x021ED588 thumb
 *   func_021E070C 0x021E070C thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021EF534 0x021EF534 thumb
 *   d_021EF8EC 0x021EF8EC data a1
 *   func_021EBC58  0x021EBC58  thumb  ov170
 *   func_021EBD1C 0x021EBD1C thumb ov170
 *   func_021DD908 0x021DD908 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EBD50 0x021EBD50 thumb ov170
 *   func_021E8FE8 0x021E8FE8 thumb ov170
 *   func_021E95CC 0x021E95CC thumb ov170
 *   func_021ED508 0x021ED508 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EF508 0x021EF508 thumb
 *   func_021EBAF8 0x021EBAF8 thumb
 *   func_021EBB1C 0x021EBB1C thumb ov170
 *   func_021EBD78 0x021EBD78 thumb
 *   func_021DEF98 0x021DEF98 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021E9968 0x021E9968 thumb ov170
 *   func_021E9938 0x021E9938 thumb ov170
 *   func_021E99B0 0x021E99B0 thumb ov170
 *   func_021E9B74 0x021E9B74 thumb ov170
 *   func_021E22B8 0x021E22B8 thumb ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23912.h"

#define W(p) (*(u8 **)((p) + 44))
#define WORK(p) (*(char **)((p) + 0x2C))
#define ITEM(p) (*(unsigned short *)(WORK(p) + 0xA16C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))
#define TOP(p) (*(char **)(p))
struct WinMgr;
struct Sound;
struct Struct_02025CD0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

typedef unsigned int   u32;

typedef struct {
    unsigned char pad0[2];
    unsigned char pad2[0x26];
    unsigned short h28;
    unsigned char b2A;
    unsigned char b2B;
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

typedef struct { unsigned char pad[0x1C]; unsigned char lo:4; unsigned char hi:4; } Flags;

extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *p, int i);
extern void func_021DD14C(char *);
extern void func_021EF670(char *p);
extern void func_021EF68C(char *p);
extern int func_021E8FE0(char *, int);
extern int func_021E8FC0(char *p, int a, int b);
extern void func_021EA750(char *p);
extern void func_021EBCB4(u8 *, int, int);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021ED55C(char **p, int flag);
extern unsigned func_0202136C(u16);
extern void func_021ECB60(char *p, int i, int f);
extern void func_020061E4(unsigned);
extern int func_021E8F50(char *p, int v);
extern void func_021ED108(char *p, int on);
extern void func_021EBFA8(char *p, int i, int v);
extern unsigned int func_021EBFEC(char *p, int i);
extern void func_021EC000(char *w, int i, int v);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern int func_021DD718(void **pp, void *mon);
extern void func_021DD8A8(unsigned char *p, unsigned idx);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFEC(char *p, int b);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021ED094(char *w, unsigned item);
extern void func_021ED1C8(char *w);
extern int func_021E1988(unsigned char *p);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021DF040(char *p);
extern void func_021DF0BC(unsigned char *p);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E949C(char *p, int a, int b);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021E8FD0(char *p, int a);
extern unsigned func_021EEEA4(char *p);
extern void func_021ED588(char *p);
extern int func_021E070C(char *p);
extern int func_021E0190(char *p);
extern void func_021EB988(Obj *p, const void *e, unsigned n);
extern void func_021EF534(struct WinMgr *mgr);
extern void func_021EBC58(unsigned char *p, int sel, int kind, int i);
extern void func_021EBD1C(char *p, int row, int b);
extern int func_021DD908(char *p, u32 a);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EBD50(unsigned char *p);
extern int func_021E8FE8(unsigned char *p, int sel);
extern int func_021E95CC(unsigned char *p, unsigned char v);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021ED888(char *w, int a);
extern void func_021EF508(struct WinMgr *mgr);
extern void func_021EBAF8(unsigned char *p, unsigned v, int i);
extern void func_021EBB1C(unsigned char *p, int i);
extern void func_021EBD78(char *p, int b);
extern int func_021DEF98(char *p, int a, unsigned b);
extern void func_021ED544(char *p, int b);
extern int func_021E9968(unsigned char *p);
extern int func_021E9938(unsigned char *p);
extern int func_021E99B0(unsigned char *p);
extern int func_021E9B74(unsigned char *p);
extern int func_021E22B8(int p);
int func_021E7258(char *p);
int func_021E7298(u8 *p);
int func_021E73D8(unsigned char *p);
int func_021E754C(unsigned char *p);
int func_021E75E0(Obj *p);
int func_021E78F4(char *p);
int func_021E7904(unsigned char *p);
void func_021E79C8(unsigned char *p);
int func_021E7A04(unsigned char *p);
int func_021E7A10(unsigned char *p);
int func_021E7BD0(unsigned char *p);
extern const unsigned char d_021EF8EC[];

/*
 * Wrapper family member: func_021EF68C, state 0x46 and
 *   0x021E0E51 as the selector.
 */
int func_021E7258(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF68C((char *)(*(int *)&((struct Obj00000 *)p)->f2C));
    return func_021E8FC0(p, 0x21E0E51, func_021E8FE0(p, 0x46));
}

/*
 *   void func_020260E4(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 */
int func_021E7298(u8 *p)
{
    u16 *pair = *(u16 **)(W(p) + 96);
    u16 item = *(u16 *)(W(p) + 0xa16c);
    u16 second;
    if (item == 0) {
        func_021EA750((char *)p);
        func_021EBCB4(p, 0, 24);
        func_020260E4(*(void **)(W(p) + 112), 10);
        func_021EE3E4((char **)p, 10);
        func_021ED55C((char **)p, 1);
        return 70;
    }
    if (pair[0] == p[22]) {
        second = pair[1];
        func_021EA750((char *)p);
        func_020260E4(*(void **)(W(p) + 112), 9);
        func_021EE3E4((char **)p, 9);
        if (func_0202136C(*(u16 *)(W(p) + 0xa16c)) == 1 && second != p[22]) {
            func_021ECB60((char *)W(p), p[22], 0);
            func_021EBCB4(p, 7, 24);
            func_020061E4(0x557);
            *(int *)(p + 40) = 14;
            return func_021E8F50((char *)p, 6);
        }
        func_021EBCB4(p, 1, 24);
        func_021ED55C((char **)p, 1);
        return 70;
    }
    if (func_0202136C(item) == 1) {
        func_021EA750((char *)p);
        func_020061E4(0x557);
        func_021ECB60((char *)W(p), p[22], 0);
        func_021EBCB4(p, 7, 24);
        func_020061E4(0x557);
        func_020260E4(*(void **)(W(p) + 112), 9);
        func_021EE3E4((char **)p, 9);
        func_021ED55C((char **)p, 1);
        *(int *)(p + 40) = 14;
        return func_021E8F50((char *)p, 6);
    }
    func_021ECB60((char *)W(p), pair[0], 0);
    func_021ECB60((char *)W(p), p[22], 1);
    func_021ED6E4((char **)p, 0);
    func_021ED108((char *)W(p), 1);
    func_021EBFA8((char *)W(p), 10, 2);
    return 73;
}

#define OBJ(p) (*(void **)(WORK(p) + 0x70))


/*
 * Item swap on drop (template 021E6A60): moves the held item onto the
 * target slot, returns the target's old item to the source, and either
 * finishes or keeps the new item held.
 */
int func_021E73D8(unsigned char *p)
{
    Entry *o;
    unsigned short item;

    if (func_021EBFEC(WORK(p), 10) == 1)
        return 0x49;
    func_021ED108(WORK(p), 0);
    func_021EC000(WORK(p), 10, 0);
    o = *(Entry **)(WORK(p) + 0x60);
    item = func_021DD25C((void ***)p, o->idx, p[0x14], 6, 0);
    func_021DD2B4((int)p, o->idx, p[0x14], 6, ITEM(p));
    if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], o->idx)) == 1) {
        func_021DD8A8(p, o->idx);
        func_021EC48C(p, p[0x14], o->idx, WIN(p, o->idx));
    }
    func_021DEFEC((char *)p, o->idx);
    ITEM(p) = item;
    func_021DD2B4((int)p, p[0x16], p[0x17], 6, ITEM(p));
    if (p[0x17] == 0xFF || p[0x17] == p[0x14]) {
        if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16])) == 1) {
            func_021DD8A8(p, p[0x16]);
            func_021EC48C(p, p[0x14], p[0x16], WIN(p, p[0x16]));
        }
    }
    if (ITEM(p) == 0) {
        p[0x16] = o->idx;
        func_021EA750((char *)p);
        func_021EF68C(WORK(p));
        func_020260E4(OBJ(p), p[0x16] - 0x1E);
        func_021DEFEC((char *)p, p[0x16]);
        func_020260F4(OBJ(p), 1);
        return 0x46;
    }
    func_020061E4(0x666);
    func_021ED094(WORK(p), ITEM(p));
    func_021ED108(WORK(p), 1);
    func_021EBFA8(WORK(p), 10, 1);
    func_021EC000(WORK(p), 10, 1);
    func_021ED1C8(WORK(p));
    return func_021E8FC0((char *)p, (int)func_021E1988, func_021E8F50((char *)p, 0x4A));
}

int func_021E754C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_020061E4(0x667);
        func_021ECB60(WORK(p), **(unsigned short **)(WORK(p) + 0x60), 0);
        func_021ED6E4((char **)p, 0);
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16] - 0x1E);
        func_021EA750((char *)p);
        STEP(p)++;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) == 1)
            break;
        func_021DEFEC((char *)p, p[0x16]);
        func_020260F4(*(void **)(WORK(p) + 0x70), 1);
        func_021EF68C(WORK(p));
        return 0x46;
    }
    return 0x4A;
}

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))

#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))


int func_021E75E0(Obj *p)
{
    unsigned r = func_021EEEA4((char *)p);
    switch (r) {
    case 0x1E:
        func_021DF0BC((unsigned char *)p);
        break;
    case 0x1F:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 0, 0x4B);
    case 0x20:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 0, 0x4B);
    case 0x21:
        func_020061E4(0x551);
        p->top->h28 = 0;
        p->top->b2A = 0xFF;
        p->top->b2B = 0xFF;
        return func_021E954C(p, 6, 9, 0x68);
    case 0x22:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x4D));
    case 0x23: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x4E);
    }
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 0, 0x4B);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 0, 0x4B);
        }
        break;
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)p, v);
        else if (v != 0x22 && v != 0x23)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x4B));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x4E);
        }
        p->top->h28 = 0;
        p->top->b2A = 0xFF;
        p->top->b2B = 0xFF;
        return func_021E954C(p, 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            p->b16 = r;
            func_021EB988(p, d_021EF8EC, 2);
            func_021DEFEC((char *)p, r);
            func_021ED588((char *)p);
            func_020260E4(OBJ(p), 0x22);
            if (func_021EF5E8(MGR(p)) == 1)
                return func_021E78F4((char *)p);
            func_021EEF74(p->work, 0x22, r);
            func_021EF534(MGR(p));
            return func_021E8FC0((char *)p, (int)func_021E070C, func_021E8FE0((char *)p, 0x4C));
        }
        func_020061E4(0x548);
        func_021DEFEC((char *)p, r);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x4B);
        }
        break;
    }
    return 0x4B;
}

/*
 * Push the 0x16 field through the 0x18 selector; return 75.
 */
int func_021E78F4(char *p)
{
    func_021EBC58((unsigned char *)p, (unsigned char)p[0x16], 1, 0x18);
    return 0x4b;
}

int func_021E7904(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x4D);
    case 1:
        if (func_021DD25C((void ***)p, p[0x16], p[0x14], 0x4C, 0) != 0) {
            func_021EBD1C((char *)p, 4, 0x18);
            ((struct Obj00000 *)p)->f28 = 0xE;
            return func_021E8F50((char *)p, 6);
        }
        if (func_021DD908((char *)p, p[0x16]) == 0) {
            func_021EBD1C((char *)p, 6, 0x1B);
            ((struct Obj00000 *)p)->f28 = 0xE;
            return func_021E8F50((char *)p, 6);
        }
        func_021ECB20((char *)p, 1, 1);
        func_021ECB60(WORK(p), p[0x16], 0);
        func_021EBD50(p);
        STEP(p) = 0;
        return func_021E8FE8(p, 5);
    }
    return 0x4D;
}

void func_021E79C8(unsigned char *p)
{
    func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    func_021E8FC0((char *)p, (int)func_021E070C, func_021E8FE0((char *)p, 0x4B));
}

int func_021E7A04(unsigned char *p)
{
    return func_021E95CC(p, 0);
}

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))


/*
 * Item menu "give": checks the slot, then asks to swap or confirms.  A
 * four-step machine on the work word at 0xA194 (template 021E3C88).
 */
int func_021E7A10(unsigned char *p)
{
    switch (STEP(p)) {
    case 0: {
        unsigned item;
        if (*(int *)(TOP(p) + 0x24) == 4 && *(int *)(TOP(p) + 0x14) == 1) {
            func_021EC000(WORK(p), 4, 0);
            func_021EF57C(MGR(p));
            STEP(p) = 3;
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x50);
        }
        if (func_021DD25C((void ***)p, p[0x16], p[0x14], 0x4C, 0) == 0) {
            item = func_021DD25C((void ***)p, p[0x16], p[0x14], 6, 0);
            if (item == 0)
                return func_021E95CC(p, 1);
            func_021EC000(WORK(p), 4, 0);
            func_021ED508(p, 0xE, 0);
            func_021ED888(WORK(p), 0);
            if (func_0202136C(item) == 1) {
                func_021EF57C(MGR(p));
                STEP(p) = 1;
                return func_021E8FC0((char *)p, (int)func_021E0190, 0x50);
            }
            if (p[0x16] < 0x1E)
                func_021ECB20((char *)p, 1, 1);
            else
                func_021ECB20((char *)p, 2, 1);
            func_021ECB60(WORK(p), p[0x16], 0);
            *(unsigned char *)(WORK(p) + 0xA170) = 1;
            func_021EF508(MGR(p));
            func_021EBAF8(p, item, 0x18);
            if (*(int *)(TOP(p) + 0x24) == 3)
                return func_021E8FE8(p, 2);
            return func_021E8FE8(p, 0);
        }
        func_021EC000(WORK(p), 4, 0);
        func_021EF57C(MGR(p));
        STEP(p) = 2;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x50);
    }
    case 1:
        func_020061E4(0x557);
        func_021EBB1C(p, 0x18);
        STATE(p) = 0xE;
        return func_021E8F50((char *)p, 6);
    case 2:
        func_020061E4(0x557);
        func_021EBCB4(p, 5, 0x18);
        STATE(p) = 0xE;
        return func_021E8F50((char *)p, 6);
    case 3:
        func_020061E4(0x557);
        func_021EBD78((char *)p, 1);
        STATE(p) = 0x2B;
        return 6;
    }
    return 0x50;
}

int func_021E7BD0(unsigned char *p)
{
    if (p[0x17] != 0xFF)
        func_021DEF98((char *)p, p[0x17], p[0x16]);
    else
        func_021DEFEC((char *)p, p[0x16]);
    func_021ED544((char *)p, 6);
    if (((Flags *)p)->lo == 0)
        func_021ED508(p, 0xE, 1);
    else
        func_021ED508(p, 0xD, 1);
    switch (((struct Obj23912 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0:
        *(int *)(WORK(p) + 0xA198) = func_021E9968(p);
        break;
    case 1:
        *(int *)(WORK(p) + 0xA198) = func_021E9938(p);
        break;
    case 2:
        *(int *)(WORK(p) + 0xA198) = func_021E99B0(p);
        break;
    case 4:
        *(int *)(WORK(p) + 0xA198) = func_021E9B74(p);
        break;
    case 3:
        break;
    }
    return func_021E22B8((int)p);
}
