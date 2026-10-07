/*
 * file:     box2_seq_p11.c
 * unit:     yes
 * function: func_021E4E6C, func_021E4EAC, func_021E4EE8, func_021E4F60, func_021E5374, func_021E53B0, func_021E543C, func_021E5524, func_021E557C, func_021E58D8
 * address:  0x021E4E6C
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
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021EA1E8 0x021EA1E8 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021EF480 0x021EF480 thumb ov170
 *   func_020362DC 0x020362DC arm
 *   func_021EA9F4 0x021EA9F4 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021E9D2C 0x021E9D2C thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021EE57C 0x021EE57C thumb
 *   func_021E9DF8 0x021E9DF8 thumb
 *   func_021E9D98 0x021E9D98 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021E954C 0x021E954C thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_021EAA3C 0x021EAA3C thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021E9E7C 0x021E9E7C thumb
 *   d_021EF9B4 0x021EF9B4 data a1
 *   func_021E070C 0x021E070C thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021EC61C 0x021EC61C thumb ov170
 *   func_021EF35C 0x021EF35C thumb ov170
 *   func_021EF36C 0x021EF36C thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021ECB84 0x021ECB84 thumb ov170
 *   func_021EA1C0 0x021EA1C0 thumb ov170
 *   func_021E0068 0x021E0068 thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EF194 0x021EF194 thumb
 *   func_021E9FA8 0x021E9FA8 thumb
 *   func_021EE474 0x021EE474 thumb
 *   func_021EA020 0x021EA020 thumb
 *   d_021EF950 0x021EF950 data a1
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23902.h"
#include "../../matched/include/Obj23904.h"

#define WORK(p) (*(char **)((p) + 0x2c))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
struct WinMgr;
struct Sound;
struct Struct_02025CD0;
typedef unsigned char u8;

typedef unsigned short u16;

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

extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *p, int i);
extern void func_021DD14C(char *);
extern void func_021EF670(char *p);
extern void func_021EF68C(char *p);
extern int func_021E8FE0(char *, int);
extern int func_021E8FC0(char *p, int a, int b);
extern void func_021DD530(u8 *);
extern void func_021EA1E8(char *);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **,unsigned);
extern void func_021EE038(char *,int,int,int);
extern void func_021EBC58(u8 *,int,int,int);
extern void func_020061E4(unsigned);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern u8 func_020355C4(void);
extern unsigned func_0201AA18(void *);
extern void func_021DF0BC(unsigned char *);
extern void func_021DEFEC(char *p, int b);
extern void func_021ED55C(char **, int);
extern void func_021ED508(unsigned char *, int, int);
extern void func_021ED888(char *, int);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021EF34C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC000(char *, int, int);
extern u32 func_021EBFEC(char *p, int i);
extern void func_021ED108(char *, int);
extern void func_021EA878(unsigned char *, int);
extern void func_021EBCB4(unsigned char *, int, int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EC5A0(char **p, int flag);
extern void func_021EE364(char **p, int idx, int v);
extern int func_021EA83C(char *p, int a);
extern int func_021E8F50(char *p, int v);
extern int func_021E0190(char *p);
extern int func_021E01B0(unsigned char *);
extern u32 func_020362DC(void);
extern int func_021EA9F4(Obj *p, int v);
extern unsigned func_021EF170(void);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021EB988(Obj *p, const void *e, unsigned n);
extern int func_021E9D2C(Obj *p, int i);
extern void func_021DF040(char *p);
extern unsigned func_021EE57C(char *p);
extern int func_021E9DF8(Obj *p, int i);
extern int func_021E9D98(Obj *p, int i);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E949C(char *p, int a, int b);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021EAA3C(Obj *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021E9E7C(Obj *p, int i, int v);
extern int func_021E070C(char *p);
extern void func_021EC61C(u8 *);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021ECB84(char *, unsigned);
extern void func_021EA1C0(void *p);
extern int func_021E0068(char *p);
extern unsigned func_021EF194(void);
extern int func_021E9FA8(Obj *p, int i);
extern unsigned func_021EE474(char *p);
extern int func_021EA020(Obj *p, int i, int v);
void func_021E4E6C(char *p);
int func_021E4EAC(u8 *p);
int func_021E4EE8(unsigned char *p);
int func_021E4F60(Obj *p);
void func_021E5374(u8 *p);
int func_021E53B0(unsigned char *p);
int func_021E543C(u8 *p);
int func_021E5524(unsigned char *p);
int func_021E557C(Obj *p);
void func_021E58D8(u8 *p);
extern const unsigned char d_021EF9B4[];
extern const unsigned char d_021EF950[];

/*
 * Wrapper family member: func_021EF68C and state 0x27.
 */
void func_021E4E6C(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF68C((char *)(*(int *)&((struct Obj00000 *)p)->f2C));
    func_021E8FC0(p, 0x21E070D, func_021E8FE0(p, 0x27));
}

/*
 *   void func_020260E4(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 */
int func_021E4EAC(u8 *p){func_021DD530(p);func_021EA1E8((char *)p);func_020260E4(*(void **)(*(char **)(p+0x2c)+0x70),9);func_021EE3E4((char **)p,9);func_021EE038((char *)p,0,0,1);func_021EBC58(p,p[0x16],1,24);return 39;}

#define OBJ(p) (*(void **)(WORK(p) + 0x70))

#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

int func_021E4EE8(unsigned char *p)
{
    func_021EBA5C(WORK(p), 0x1b);
    func_021ED6E4((char **)p, 0);
    func_021DD14C((char *)p);
    if (func_020355C4() == 0)
        func_020260F4(OBJ(p), 1);
    if (func_021EF480(MGR(p)) == 1) {
        func_020260E4(OBJ(p), p[0x16] - 0x1e);
        func_021EE3E4((char **)p, p[0x16] - 0x1e);
        func_021EF68C(WORK(p));
        return 0x27;
    } else {
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE3E4((char **)p, p[0x16]);
        func_021EF670(WORK(p));
        return 0x23;
    }
}

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))


int func_021E4F60(Obj *p)
{
    unsigned r;
    r = func_021EF170();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988(p, d_021EF9B4, 5);
            func_021DEFEC((char *)p, r);
            return func_021E9DF8(p, r);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x2C);
        }
        return 0x2C;
    }
    r = func_021EE57C((char *)p);
    switch (r) {
    case 0x1E:
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 0, 0x2C);
    case 0x20:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 0, 0x2C);
    case 0x21:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C(p, 7, 8, 0x10);
    case 0x22:
        func_020061E4(0x551);
        p->top->h28 = 0;
        return func_021E954C(p, 6, 9, 0x68);
    case 0x23:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 1, func_021E8F50((char *)p, 0x2E));
    case 0x24:
        func_020061E4(0x54C);
        p->b17 = p->b14;
        p->x24 = 0x24;
        return func_021E949C((char *)p, 2, 0x4F);
    case 0x25:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x55));
    case 0x26:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x59));
    case 0x27: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x2D);
    }
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 0, 0x2C);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 0, 0x2C);
        }
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)p, v);
        else if (v != 0x23 && v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x2C));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x2D);
        }
        p->top->h28 = 0;
        return func_021E954C(p, 6, 9, 0x68);
    case -4:
        func_020061E4(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            func_021EB988(p, d_021EF9B4, 5);
            func_021DEFEC((char *)p, r);
            func_021EEF74(p->work, 0x23, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 0x23);
            return func_021E9E7C(p, r, 0x2C);
        }
        break;
    }
    return 0x2C;
}

void func_021E5374(u8 *p){func_021EF57C(*(struct WinMgr * *)&((struct Obj23902 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74);func_021ED6E4((char **)p,0);func_021EBA5C(*(char * *)&((struct Obj00000 *)p)->f2C,24);func_021DD14C((char *)p);func_021E8FC0((char *)p,(int)func_021E070C,func_021E8FE0((char *)p,44));}

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

int func_021E53B0(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        func_021EF57C(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x2e);
    case 1:
        if (func_0201AA18(((void **)((struct Obj00000 *)p)->f0)[2]) != 6)
            return func_021E8F50((char *)p, 0x2f);
        func_020061E4(0x557);
        func_021EBC58(p, 0, 2, 0x18);
        ((struct Obj00000 *)p)->f28 = 0xe;
        return func_021E8F50((char *)p, 6);
    }
    return 0x2e;
}

int func_021E543C(u8 *p)
{
    switch (*(u32 *)(*(u8 **)(p + 44) + 0xa194)) {
    case 0:
        func_020061E4(0x669);
        func_021EC61C(p);
        func_021EF35C((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        func_021EF36C((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        p[26] = 2;
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 47);
    case 1:
        p[23] = p[20];
        func_021ECB84(*(char **)(p + 44), p[22]);
        func_021EA1C0(p);
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0((char *)p, (int)func_021E0068, 47);
    case 2:
        func_020061E4(0x669);
        func_021DD530(p);
        func_021EA1E8((char *)p);
        func_021DF040((char *)p);
        func_021EF3A0((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 47);
    case 3:
        func_020260E4(*(void **)(*(u8 **)(p + 44) + 112), p[22]);
        func_021EE3E4((char **)p, p[22]);
        func_021ED55C((char **)p, 1);
        p[22] = 255;
        *(u32 *)(*(u8 **)(p + 44) + 0xa194) = 0;
        return 44;
    }
    return 47;
}

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))

int func_021E5524(unsigned char *p)
{
    unsigned r = *(unsigned *)(*(char **)(WORK(p) + 0x60) + 0xac);
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_021ED888(WORK(p), 1);
    func_021EE038((char *)p, 0, 0, 1);
    if (p[0x16] != 0xff) {
        func_021EBC58(p, p[0x16], 1, 0x18);
        r = 0x23;
    }
    func_020260E4(OBJ(p), r);
    func_021EE3E4((char **)p, r);
    return 0x2c;
}

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))


/*
 * Sibling of src/matched/ov170_func_021E2650.c.  The image computes r + 0x1E
 * separately for func_021DEFEC and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int func_021E557C(Obj *p)
{
    unsigned r = func_021EF194();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988(p, d_021EF950, 5);
            func_021DEFEC((char *)p, (int)r + 0x1E);
            return func_021E9FA8(p, r + 0x1E);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r + 0x3C);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x31);
        }
        return 0x31;
    }
    r = func_021EE474((char *)p);
    switch (r) {
    case 6:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C(p, 7, 8, 0x10);
    case 7:
        func_020061E4(0x551);
        p->top->h28 = 0;
        return func_021E954C(p, 6, 9, 0x68);
    case 8:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 1, func_021E8F50((char *)p, 0x34));
    case 9:
        func_020061E4(0x54C);
        p->x24 = 9;
        return func_021E949C((char *)p, 2, 0x4F);
    case 10:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x55));
    case 11:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x59));
    case 12: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16 - 0x1E;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x32);
    }
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 6)
            func_021DEFEC((char *)p, v + 0x1E);
        else if (v != 8 && v != 9 && v != 10 && v != 11 && v != 12)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x31));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x32);
        }
        p->top->h28 = 0;
        return func_021E954C(p, 6, 9, 0x68);
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            func_021EB988(p, d_021EF950, 5);
            func_021DEFEC((char *)p, (int)r + 0x1E);
            func_021EEF74(p->work, 8, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 8);
            return func_021EA020(p, r + 0x1E, 0x31);
        }
        break;
    }
    return 0x31;
}

void func_021E58D8(u8 *p){func_021EF57C(*(struct WinMgr * *)&((struct Obj23904 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74);func_021ED6E4((char **)p,0);func_021EBA5C(*(char * *)&((struct Obj00000 *)p)->f2C,24);func_021DD14C((char *)p);func_021E8FC0((char *)p,(int)func_021E070C,func_021E8FE0((char *)p,49));}
