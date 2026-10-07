/*
 * file:     box2_seq_p13.c
 * unit:     yes
 * function: func_021E5E08, func_021E5E68, func_021E62BC, func_021E62FC, func_021E6374
 * address:  0x021E5E08
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
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021EA1E8 0x021EA1E8 thumb ov170
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_020362DC 0x020362DC arm
 *   func_021EA9F4 0x021EA9F4 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EA1F4 0x021EA1F4 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EEA48 0x021EEA48 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021EAA3C 0x021EAA3C thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EA2DC 0x021EA2DC thumb
 *   func_021EF57C  0x021EF57C  thumb  ov170
 *   func_021ED6E4  0x021ED6E4  thumb  ov170
 *   func_021EBA5C  0x021EBA5C  thumb  ov170
 *   func_021DD14C  0x021DD14C  thumb  ov170
 *   func_021EF670  0x021EF670  thumb  ov170
 *   func_021EF68C  0x021EF68C  thumb  ov170
 *   func_021E8FC0  0x021E8FC0  thumb  ov170
 *   func_021EBFEC 0x021EBFEC thumb ov170
 *   func_021EA878 0x021EA878 thumb ov170
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EBCB4 0x021EBCB4 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021E0F4C 0x021E0F4C thumb ov170
 */
#include "../../matched/include/Obj00000.h"

#define WORK(p) (*(char **)((p) + 0x2c))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
struct Sound;
struct WinMgr;
struct Struct_02025CD0;
typedef unsigned char  u8;

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

typedef unsigned short u16;

extern void func_021DD530(unsigned char *);
extern void func_021EA1E8(char *p);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **, unsigned);
extern void func_021ED55C(char **, int);
extern void func_021EE038(char *, int, int, int);
extern void func_021EBC58(unsigned char *, int, int, int);
extern void func_021ED888(char *, int);
extern void func_021DEFEC(char *p, int b);
extern u32 func_020362DC(void);
extern int func_021EA9F4(Obj *p, int v);
extern unsigned func_021EF170(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_020061E4(unsigned se);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021EF5E8(struct WinMgr *mgr);
extern int func_021EA1F4(Obj *p, int i);
extern void func_021DF040(char *p);
extern unsigned func_021EEA48(char *p);
extern int func_021E8F50(char *p, int v);
extern void func_021DF0BC(unsigned char *p);
extern void func_021EC000(char *p, int i, int v);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E949C(char *p, int a, int b);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021EAA3C(Obj *p, int v);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021EA2DC(Obj *p, int i);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *p, int i);
extern void func_021DD14C(char *);
extern void func_021EF670(char *p);
extern void func_021EF68C(char *p);
extern int func_021E8FC0(char *p, int a, int b);
extern u8 func_020355C4(void);
extern unsigned func_0201AA18(void *);
extern void func_021ED508(unsigned char *, int, int);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021EF34C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern u32 func_021EBFEC(char *p, int i);
extern void func_021ED108(char *, int);
extern void func_021EA878(unsigned char *, int);
extern void func_021EBCB4(unsigned char *, int, int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EC5A0(char **p, int flag);
extern void func_021EE364(char **p, int idx, int v);
extern int func_021EA83C(char *p, int a);
extern int func_021E0190(char *p);
extern int func_021E01B0(unsigned char *);
extern int func_021E0F4C(u8 *);
int func_021E5E08(unsigned char *p);
int func_021E5E68(Obj *p);
int func_021E62BC(char *p);
int func_021E62FC(unsigned char *p);
void func_021E6374(u8 *p);

#define OBJ(p) (*(void **)(WORK(p) + 0x70))

int func_021E5E08(unsigned char *p)
{
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_021EE038((char *)p, 0, 0, 1);
    if (p[0x16] == 0xff) {
        func_020260E4(OBJ(p), 0);
        func_021EE3E4((char **)p, 0);
        func_021DEFEC((char *)p, 0x1e);
    } else {
        func_021EBC58(p, p[0x16], 1, 0x18);
        func_020260E4(OBJ(p), 8);
        func_021EE3E4((char **)p, 8);
    }
    return 0x31;
}

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))

#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))


int func_021E5E68(Obj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        r = func_021EA9F4(p, 0x3F);
        if (p->lo == 1) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 0x1E)
                p->b16 = v;
            else
                p->b16 = 0;
        }
        return r;
    }
    r = func_021EF170();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            func_021DEFEC((char *)p, r);
            return func_021EA1F4(p, r);
        }
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EEF74(p->work, r, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), r);
            return func_021E62BC((char *)p);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        return 0x39;
    }
    r = func_021EEA48((char *)p);
    switch (r) {
    case 0x1E:
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_021EC000(p->work, 10, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 1, 0x39);
    case 0x20:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_021EC000(p->work, 10, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 1, 0x39);
    case 0x21:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 10, func_021E8F50((char *)p, 0x1A));
    case 0x22:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C(p, 7, 8, 0x10);
    case 0x23:
        func_020061E4(0x551);
        p->top->h28 = 0;
        return func_021E954C(p, 6, 9, 0x68);
    case 0x24:
        func_020061E4(0x54C);
        p->lo = 0;
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x3F));
    case 0x25:
        func_020061E4(0x54C);
        if (*(unsigned short *)(p->work + 0xA16C) == 0) {
            p->b13 = 0;
            p->x24 = 0x25;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
        }
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
    case 0x26: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x3A);
    }
    case 0x27:
        r = func_021EAA3C(p, 0x3F);
        if (p->lo == 1) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 0x1E)
                p->b16 = v;
            else
                p->b16 = 0;
        }
        return r;
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 1, 0x39);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 1, 0x39);
        }
        break;
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)p, v);
        else if (v != 0x24 && v != 0x25 && v != 0x26)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x39));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x3A);
        }
        p->top->h28 = 0;
        return func_021E954C(p, 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            return func_021EA2DC(p, r);
        }
        break;
    }
    return 0x39;
}

/*
 * Wrapper family member: func_021EF670, state 0x39 and
 *   0x021E0E51 as the selector.
 */
int func_021E62BC(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF670((char *)(*(int *)&((struct Obj00000 *)p)->f2C));
    return func_021E8FC0(p, 0x21E0E51, func_021E8FE0(p, 0x39));
}

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

int func_021E62FC(unsigned char *p)
{
    if (func_021EBFEC(WORK(p), 0xa) == 1)
        return 0x3b;
    func_021EA878(p, 0);
    func_021ED108(WORK(p), 0);
    func_021EC000(WORK(p), 0xa, 0);
    func_021EBCB4(p, 3, 0x18);
    if (p[0x16] < 0x1e) {
        func_021ECB20((char *)p, 0x81, 1);
        func_021ED888(WORK(p), 1);
    } else {
        func_021ECB20((char *)p, 0x82, 1);
    }
    *(unsigned short *)(WORK(p) + 0xa16c) = 0;
    ((struct Obj00000 *)p)->f28 = 0x3d;
    return func_021E8F50((char *)p, 6);
}

void func_021E6374(u8 *p){func_021ED6E4((char **)p,0);func_021EBA5C(*(char * *)&((struct Obj00000 *)p)->f2C,24);func_021DD14C((char *)p);if(p[0x16]<30)func_021EF670(*(char * *)&((struct Obj00000 *)p)->f2C);else func_021EF68C(*(char * *)&((struct Obj00000 *)p)->f2C);func_021E8FC0((char *)p,(int)func_021E0F4C,61);}
