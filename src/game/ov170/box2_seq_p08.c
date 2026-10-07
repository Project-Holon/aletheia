/*
 * file:     box2_seq_p08.c
 * unit:     yes
 * function: func_021E36A8, func_021E376C, func_021E3B50, func_021E3BF8, func_021E3C38
 * address:  0x021E36A8
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
 *   func_021DF0BC 0x021DF0BC thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EF34C 0x021EF34C thumb ov170
 *   func_021EF36C 0x021EF36C thumb ov170
 *   func_021EC5A0 0x021EC5A0 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_020362DC 0x020362DC arm
 *   func_021EA9F4 0x021EA9F4 thumb
 *   func_021EF194 0x021EF194 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021E9EC0 0x021E9EC0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021EE8A8 0x021EE8A8 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021E954C 0x021E954C thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_021EAA3C 0x021EAA3C thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EA020 0x021EA020 thumb
 *   d_021EFA10 0x021EFA10 data a1
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021EA1E8 0x021EA1E8 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23895.h"
#include "../../matched/include/Obj23896.h"
#include "../../matched/include/Obj23897.h"
#include "../../matched/include/Obj23898.h"

#define W(p) (*(char **)((p) + 0x2C))
#define WORK(p) (*(char **)((p) + 0x2c))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
struct WinMgr;
struct Sound;
struct Struct_02025CD0;
typedef unsigned int u32;

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

typedef unsigned char  u8;

extern void func_021DF0BC(unsigned char *);
extern void func_021DD14C(char *p);
extern void func_021ED888(char *, int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ED55C(char **, int);
extern void func_021EF34C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC5A0(char **, int);
extern void func_020061E4(unsigned);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E01B0(unsigned char *);
extern void func_021DEFEC(char *p, int b);
extern void func_021EF68C(char *);
extern void func_021EE364(char **p, int idx, int v);
extern u32 func_020362DC(void);
extern int func_021EA9F4(Obj *p, int v);
extern unsigned func_021EF194(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021EB988(Obj *p, const void *e, unsigned n);
extern int func_021E9EC0(Obj *p, int i);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF040(char *p);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *w, int v);
extern int func_021E0190(char *p);
extern unsigned func_021EE8A8(char *p);
extern int func_021E8F50(char *p, int v);
extern int func_021E949C(char *p, int a, int b);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021EAA3C(Obj *p, int v);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021EA020(Obj *p, int i, int v);
extern u8 func_020355C4(void);
extern unsigned func_0201AA18(void *);
extern void func_021ED508(unsigned char *, int, int);
extern void func_021EF670(char *);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021EC000(char *, int, int);
extern u32 func_021EBFEC(char *p, int i);
extern void func_021ED108(char *, int);
extern void func_021EA878(unsigned char *, int);
extern void func_021EBCB4(unsigned char *, int, int);
extern int func_021EA83C(char *p, int a);
extern void func_021EBC58(unsigned char *, int, int, int);
extern void func_021DD530(unsigned char *);
extern void func_021EA1E8(char *p);
extern void func_021EE038(char *, int, int, int);
int func_021E36A8(unsigned char *p);
int func_021E376C(Obj *p);
int func_021E3B50(unsigned char *p);
void func_021E3BF8(char *p);
int func_021E3C38(unsigned char *p);
extern const unsigned char d_021EFA10[];

int func_021E36A8(unsigned char *p)
{
    switch (*(int *)(W(p) + 0xA194)) {
    case 0:
        func_021DF0BC(p);
        func_021DD14C((char *)p);
        func_021ED888(W(p), 0);
        func_021ECB20((char *)p, 1, 1);
        func_021ED55C((char **)p, 0);
        func_021EF34C(*(struct WinMgr **)(W(p) + 0x74));
        func_021EF36C(*(struct WinMgr **)(W(p) + 0x74));
        func_021EC5A0((char **)p, 0);
        if (((struct Obj23895 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3)
            func_021ECB20((char *)p, 0x82, 1);
        func_020061E4(0x669);
        (*(int *)(W(p) + 0xA194))++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x1A);
    case 1:
        *(int *)(W(p) + 0xA194) = 0;
        func_021DEFEC((char *)p, 0x1E);
        func_021EF68C(W(p));
        if (((struct Obj23896 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3) {
            func_021EE364((char **)p, 8, 0);
            return 0x46;
        } else {
            func_021EE364((char **)p, 5, 0);
            return 0x1B;
        }
    }
    return 0x1A;
}


#define OBJ(p) (*(void **)((p)->work + 0x70))

#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))


/*
 * Sibling of src/matched/ov170_func_021E2650.c.  The image computes r + 0x1E
 * separately for func_021DEFEC and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int func_021E376C(Obj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        p->b1B = 1;
        return func_021EA9F4(p, 0x1F);
    }
    r = func_021EF194();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988(p, d_021EFA10, 6);
            func_021DEFEC((char *)p, (int)r + 0x1E);
            return func_021E9EC0(p, r + 0x1E);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            func_021EF68C(p->work);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x1B);
        }
        return 0x1B;
    }
    r = func_021EE8A8((char *)p);
    switch (r) {
    case 6:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 0xA, func_021E8F50((char *)p, 0x1C));
    case 7:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C(p, 7, 8, 0x10);
    case 8:
        func_020061E4(0x551);
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x1C));
    case 9:
        func_020061E4(0x54C);
        p->b1B = 1;
        p->lo = 0;
        return func_021E949C((char *)p, 0, func_021E8F50((char *)p, 0x1F));
    case 10:
        func_020061E4(0x54C);
        p->b17 = p->b14;
        p->b13 = 1;
        return func_021E949C((char *)p, 1, 0x4F);
    case 11:
        func_020061E4(0x54C);
        p->b13 = 1;
        return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x50));
    case 12:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x55));
    case 13:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x59));
    case 14: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16 - 0x1E;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x1D);
    }
    case 15:
        p->b1B = 1;
        return func_021EAA3C(p, 0x1F);
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
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x1B));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x1D);
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
            func_021EB988(p, d_021EFA10, 6);
            func_021DEFEC((char *)p, (int)r + 0x1E);
            func_021EEF74(p->work, 9, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 9);
            return func_021EA020(p, r + 0x1E, 0x1B);
        }
        break;
    }
    return 0x1B;
}

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

int func_021E3B50(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021DF0BC(p);
        func_021DD14C((char *)p);
        func_021EC000(WORK(p), 4, 0);
        func_021EF3A0(MGR(p));
        func_020061E4(0x669);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x1c);
    case 1:
        STEP(p) = 0;
        func_021ED888(WORK(p), 1);
        func_021EF670(WORK(p));
        if (((struct Obj23897 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3) {
            func_021ECB20((char *)p, 0x81, 1);
            func_021EE364((char **)p, 7, 0x21);
            return 0x39;
        } else {
            func_021ECB20((char *)p, 1, 0);
            func_021EE364((char **)p, 3, 0x21);
            return 0x11;
        }
    }
    return 0x1c;
}

/*
 * Wrapper family member: func_021EF68C and state 0x1b.
 */
void func_021E3BF8(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF68C((char *)(*(int *)&((struct Obj00000 *)p)->f2C));
    func_021E8FC0(p, 0x21E070D, func_021E8FE0(p, 0x1B));
}

int func_021E3C38(unsigned char *p)
{
    func_020061E4(0x667);
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_020260E4(((struct Obj23898 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, 9);
    func_021EE3E4((char **)p, 9);
    func_021ED55C((char **)p, 1);
    func_021EE038((char *)p, 0, 0, 1);
    func_021EBC58(p, p[0x16], 1, 0x18);
    return 0x1b;
}
