/*
 * file:     box2_seq_p06.c
 * unit:     yes
 * function: func_021E2648, func_021E2650, func_021E2B04, func_021E2B48, func_021E2B88
 * address:  0x021E2648
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
 *   func_021E9284 0x021E9284 thumb
 *   func_020362DC 0x020362DC arm
 *   func_021EA9F4 0x021EA9F4 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021E9D2C 0x021E9D2C thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021EE65C 0x021EE65C thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021E954C 0x021E954C thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_021EAA3C 0x021EAA3C thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021E9E7C 0x021E9E7C thumb
 *   d_021EFA10 0x021EFA10 data a1
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021EA1E8 0x021EA1E8 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_021EF68C  0x021EF68C  thumb  ov170
 *   func_021ECB84 0x021ECB84 thumb ov170
 *   func_021EA83C 0x021EA83C thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EA114 0x021EA114 thumb ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23892.h"

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))
#define W(p) (*(char **)((p)+0x2C))
#define LO(p) (((Nib *)((p)+0x1C))->lo)
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

typedef struct { u8 lo:4; u8 hi:4; } Nib;

extern int func_021E9284(char *p);
extern u32 func_020362DC(void);
extern int func_021EA9F4(Obj *p, int v);
extern unsigned func_021EF170(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_020061E4(unsigned se);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021EB988(Obj *p, const void *e, unsigned n);
extern void func_021DEFEC(char *p, int b);
extern int func_021E9D2C(Obj *p, int i);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF040(char *p);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021EF670(char *w);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern unsigned func_021EE65C(char *p);
extern int func_021E8F50(char *p, int v);
extern void func_021DF0BC(unsigned char *p);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E949C(char *p, int a, int b);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021EAA3C(Obj *p, int v);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021E9E7C(Obj *p, int i, int v);
extern void func_021DD530(unsigned char *);
extern void func_021EA1E8(char *p);
extern void func_021ED55C(char **, int);
extern void func_021EE038(char *, int, int, int);
extern void func_021EBC58(unsigned char *, int, int, int);
extern void func_021EF68C(char *p);
extern void func_021ECB84(char *,unsigned);
extern int func_021EA83C(char *p, int a);
extern void func_021EE364(char **,int,int);
extern void func_021ED544(char *p, int b);
extern void func_021ED508(u8 *,int,int);
extern int func_021EA114(char *p, int a);
int func_021E2648(unsigned char *p);
int func_021E2650(Obj *p);
int func_021E2B04(unsigned char *p);
void func_021E2B48(char *p);
int func_021E2B88(u8 *p);
extern const unsigned char d_021EFA10[];


/*
 * State handler (table entry at 0x021EFABC) that forwards to
 * func_021E9284.
 */
int func_021E2648(unsigned char *p)
{
    return func_021E9284((char *)p);
}


int func_021E2650(Obj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        p->b1B = 0;
        return func_021EA9F4(p, 0x14);
    }
    r = func_021EF170();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988(p, d_021EFA10, 6);
            func_021DEFEC((char *)p, r);
            return func_021E9D2C(p, r);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            func_021EF670(p->work);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x11);
        }
        return 0x11;
    }
    r = func_021EE65C((char *)p);
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
        return func_021E9C94((char *)p, 1, 0x11);
    case 0x20:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 1, 0x11);
    case 0x21:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 0xA, func_021E8F50((char *)p, 0x1A));
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
        p->b1B = 0;
        p->lo = 0;
        return func_021E949C((char *)p, 0, func_021E8F50((char *)p, 0x14));
    case 0x25:
        func_020061E4(0x54C);
        p->b13 = 0;
        p->b17 = p->b14;
        p->x24 = 0x25;
        return func_021E949C((char *)p, 1, 0x4F);
    case 0x26:
        func_020061E4(0x54C);
        p->b13 = 0;
        p->x24 = 0x26;
        return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x50));
    case 0x27:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x55));
    case 0x28:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x59));
    case 0x29: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x13);
    }
    case 0x2A:
        p->b1B = 0;
        return func_021EAA3C(p, 0x14);
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 1, 0x11);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 1, 0x11);
        }
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)p, v);
        else if (v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27 && v != 0x28 && v != 0x29)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x11));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x13);
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
            func_021EB988(p, d_021EFA10, 6);
            func_021DEFEC((char *)p, r);
            func_021EEF74(p->work, 0x24, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 0x24);
            return func_021E9E7C(p, r, 0x11);
        }
        break;
    }
    return 0x11;
}

int func_021E2B04(unsigned char *p)
{
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_020260E4(((struct Obj23892 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, 0x24);
    func_021EE3E4((char **)p, 0x24);
    func_021ED55C((char **)p, 1);
    func_021EE038((char *)p, 0, 0, 1);
    func_021EBC58(p, p[0x16], 1, 0x18);
    return 0x11;
}

/*
 * Re-key the p+0x2c+0x74 object, clear the frame, retag 0x18,
 *   forward the status bytes, refresh, then store state 0x11 with the
 *   0x021E070D thumb pointer as the selector.  Six-member wrapper family
 *   (see func_021E3BF8 / func_021E498C / func_021E4E6C / func_021E62BC /
 *   func_021E7258): only the mid call, the selector and the state differ.
 */
void func_021E2B48(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF670((char *)(*(int *)&((struct Obj00000 *)p)->f2C));
    func_021E8FC0(p, 0x21E070D, func_021E8FE0(p, 0x11));
}

int func_021E2B88(u8 *p)
{
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        p[0x19]=p[0x14];
        if(LO(p)==1) {
            p[0x17]=255;
            p[0x16]=func_020260E0(*(void **)(W(p)+0x70));
            if(p[0x16]>=30) {
                p[0x16]=0;
                func_021DEFEC((char *)p,p[0x16]);
            }
        } else {
            p[0x17]=p[0x14];
            func_021EBA5C(W(p),24);
            func_021DD14C((char *)p);
            func_021EF670(W(p));
            func_021ECB84(W(p),p[0x16]);
        }
        func_021ED55C((char **)p,0);
        func_021EF57C(*(struct WinMgr **)(W(p)+0x74));
        (*(int *)(W(p)+0xA194))++;
        return func_021E8FC0((char *)p,(int)func_021E0190,20);
    case 1:
        func_020061E4(0x669);
        (*(int *)(W(p)+0xA194))++;
        return func_021EA83C((char *)p,20);
    case 2:
        func_021EE364((char **)p,4,p[0x16]);
        func_021ED544((char *)p,6);
        func_021EE038((char *)p,0,1,0);
        *(int *)(W(p)+0xA168)=p[0x16];
        *(int *)(W(p)+0xA194)=0;
        if(LO(p)==1) {
            if(!func_021DD25C((void ***)p,p[0x16],p[0x14],0xA9,0))
                func_021EE038((char *)p,0,1,2);
            func_021ED508(p,13,1);
            return 21;
        }
        if(LO(p)==2) func_021ED508(p,13,1);
        else func_021ED508(p,14,1);
        return func_021EA114((char *)p,p[0x16]);
    }
    return 20;
}
