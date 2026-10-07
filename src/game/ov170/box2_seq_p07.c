/*
 * file:     box2_seq_p07.c
 * unit:     yes
 * function: func_021E2CBC, func_021E3258, func_021E3340, func_021E3568, func_021E35D8
 * address:  0x021E2CBC
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
 *   func_021E8F50 0x021E8F50 thumb
 *   func_020362DC 0x020362DC arm
 *   func_021DD238 0x021DD238 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EA064 0x021EA064 thumb
 *   func_021EE754 0x021EE754 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EF1D4 0x021EF1D4 thumb
 *   func_021EA808 0x021EA808 thumb
 *   func_021EE850 0x021EE850 thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021ECC1C 0x021ECC1C thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021EA14C 0x021EA14C thumb
 *   func_021DD1C4 0x021DD1C4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E1A28 0x021E1A28 thumb
 *   func_021E19D4 0x021E19D4 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EA798 0x021EA798 thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021EA114 0x021EA114 thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EA858 0x021EA858 thumb ov170
 *   func_021EF35C 0x021EF35C thumb ov170
 *   func_021EF36C 0x021EF36C thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 *   func_021DD530 0x021DD530 thumb
 *   func_021EA1E8 0x021EA1E8 thumb
 *   func_021EF770 0x021EF770 thumb
 *   func_021EF45C 0x021EF45C thumb
 *   func_021EBD1C 0x021EBD1C thumb
 *   func_021EBD78 0x021EBD78 thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021E2094 0x021E2094 thumb ov170
 *   func_020260F0 0x020260F0 thumb
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EC5A0 0x021EC5A0 thumb ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23893.h"
#include "../../matched/include/Obj23894.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define MODE(p) (*(unsigned char *)(WORK(p) + 0xA173))
#define STATE(p) (*(int *)((p) + 0x28))
struct Sound;
struct Struct_02025CD0;
struct WinMgr;
typedef unsigned int u32;

typedef struct {
    void *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
    unsigned char b17;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1A;
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char b1D;
    unsigned char pad1E[0x28 - 0x1E];
    int x28;
    char *work;
} Obj;

typedef unsigned char  u8;

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

extern int func_021E8F50(char *p, int v);
extern u32 func_020362DC(void);
extern void func_021DD238(char *p);
extern unsigned func_021EF170(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021EE008(char *p, int a, int b);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_020061E4(unsigned se);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021DEFEC(char *p, int b);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern int func_021EA064(unsigned char *p, int i, int v);
extern void func_021EE754(unsigned char *p, unsigned r);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF040(char *p);
extern int func_021EF1D4(unsigned *a, unsigned *b);
extern void func_021EA808(char *p);
extern unsigned func_021EE850(char *p);
extern void func_021DF0BC(unsigned char *p);
extern void func_021ECC1C(unsigned char *p);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E949C(char *p, int a, int b);
extern u8 func_020260E0(struct Sound *obj);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern int func_021EA14C(unsigned char *p, unsigned i, int v);
extern void func_021DD1C4(char *p, int a);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E1A28(char *p);
extern int func_021E19D4(char *p);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021EA798(unsigned char *p, int sel);
extern void func_021ECB84(char *w, unsigned i);
extern int func_021EA114(char *p, int a);
extern void func_021ED55C(char **,int);
extern void func_021EE038(char *p, int a, int b, int c);
extern int func_021EA858(char *p, int a);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern int func_021E01B0(u8 *);
extern void func_021EE364(char **,int,int);
extern void func_021ED544(char *p, int b);
extern void func_021ED508(u8 *,int,int);
extern void func_021EF68C(char *);
extern void func_021DD530(unsigned char *p);
extern void func_021EA1E8(char *p);
extern int func_021EF770(struct WinMgr *mgr);
extern int func_021EF45C(struct WinMgr *mgr);
extern void func_021EBD1C(char *p, int row, int b);
extern void func_021EBD78(char *p, int b);
extern void func_021EF670(char *w);
extern int func_021E2094(char *);
extern u32 func_020260F0(struct Sound *obj);
extern void func_021EC000(char *, int, int);
extern void func_021EBA5C(char *, int);
extern void func_021DD14C(char *p);
extern void func_021EC5A0(char **,int);
int func_021E2CBC(Obj *p);
int func_021E3258(u8 *p);
int func_021E3340(unsigned char *p);
int func_021E3568(unsigned char *p);
int func_021E35D8(u8 *p);


#define OBJ(p) (*(void **)((p)->work + 0x70))


int func_021E2CBC(Obj *p)
{
    unsigned r;
    unsigned x;
    unsigned y;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return func_021E8F50((char *)p, 0x16);
    }
    if ((func_020362DC() & 4) && p->lo != 0 && p->b18 == 0) {
        func_021DD238((char *)p);
        p->lo = 0;
        return func_021E8F50((char *)p, 0x16);
    }
    if (p->b18 == 0) {
        r = func_021EF170();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            func_021EE008((char *)p, 0, 0);
            if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
                func_020061E4(0x666);
                func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
                func_021DEFEC((char *)p, r);
                func_020260E4(OBJ(p), r);
                return func_021EA064((unsigned char *)p, r, 0x15);
            }
            func_020260E4(OBJ(p), r);
            func_021EE754((unsigned char *)p, r);
            *(int *)(p->work + 0xA168) = r;
            func_021EE3E4((char **)p, r);
            func_021DF040((char *)p);
            return 0x15;
        }
    }
    if (func_021EF1D4(&x, &y) == 1) {
        *(unsigned *)(p->work + 0xA184) = y;
        p->x28 = 0x15;
        func_021EA808((char *)p);
        return 0xF;
    }
    r = func_021EE850((char *)p);
    switch (r) {
    case 0x1E:
        func_021EE008((char *)p, 0, 0);
        if (p->b18 != 0)
            break;
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        func_020061E4(0x548);
        func_021EE008((char *)p, 0, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        func_021EE754((unsigned char *)p, 0x1E);
        *(int *)(p->work + 0xA168) = 0x1E;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9C94((char *)p, 0, 0x15);
    case 0x20:
        func_020061E4(0x548);
        func_021EE008((char *)p, 0, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        func_021EE754((unsigned char *)p, 0x1E);
        *(int *)(p->work + 0xA168) = 0x1E;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9CE0((char *)p, 0, 0x15);
    case 0x27:
        func_020061E4(0x54C);
        if (p->b18 == 0)
            func_021DF040((char *)p);
        return func_021E949C((char *)p, 0xA, func_021E8F50((char *)p, 0x19));
    case 0x28:
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v >= 0x1E || func_021DD25C((void ***)p, v, p->b14, 0xA9, 0) == 0)
                break;
            p->b16 = v;
            p->b17 = p->b14;
            p->b13 = 2;
        } else {
            p->b13 = 3;
            p->b1D = func_020260E0(OBJ(p));
        }
        func_020061E4(0x54C);
        return func_021E954C(p, 8, 1, 0x4F);
    case 0x29:
        if (p->b18 != 0)
            break;
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x16));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return func_021E8F50((char *)p, 0x16);
    case -2:
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, 0xFF, 0x15);
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x16));
    case -8:
        if (func_020260E0(OBJ(p)) != 0x22)
            break;
        func_020061E4(0x548);
        func_021DD1C4((char *)p, -1);
        return func_021E8FC0((char *)p, (int)func_021E1A28, 0x15);
    case -7:
        if (func_020260E0(OBJ(p)) != 0x25)
            break;
        func_020061E4(0x548);
        func_021DD1C4((char *)p, 1);
        return func_021E8FC0((char *)p, (int)func_021E19D4, 0x15);
    case -6:
        if (func_020260E0(OBJ(p)) != 0x1E)
            break;
        func_020061E4(0x548);
        return func_021E9C94((char *)p, 0, 0x15);
    case -5:
        if (func_020260E0(OBJ(p)) != 0x1E)
            break;
        func_020061E4(0x548);
        return func_021E9CE0((char *)p, 0, 0x15);
    case -3: {
        unsigned char v;
        func_020061E4(0x548);
        v = func_020260E0(OBJ(p));
        if (p->b18 == 0) {
            if (v < 0x1E)
                func_021DEFEC((char *)p, v);
            else
                func_021DF040((char *)p);
        }
        if (v >= 0x22 && v <= 0x25)
            func_021EE008((char *)p, v - 0x22, 1);
        else
            func_021EE008((char *)p, 0, 0);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x15));
    }
    case -4:
        func_020061E4(0x548);
        break;
    case 0x21:
        func_020061E4(0x548);
        func_021DD1C4((char *)p, -1);
        return func_021E8FC0((char *)p, (int)func_021E1A28, 0x15);
    case 0x26:
        func_020061E4(0x548);
        func_021DD1C4((char *)p, 1);
        return func_021E8FC0((char *)p, (int)func_021E19D4, 0x15);
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
        func_021EE008((char *)p, r - 0x22, 1);
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, r + 2, 0x15);
        func_020061E4(0x548);
        func_021DF040((char *)p);
        *(unsigned char *)(p->work + 0xA17F) = p->b19 + r - 0x22;
        if (*(unsigned char *)(p->work + 0xA17F) >= p->b15)
            *(unsigned char *)(p->work + 0xA17F) -= p->b15;
        if (*(unsigned char *)(p->work + 0xA17F) != p->b14)
            return func_021EA798((unsigned char *)p, 0);
        break;
    case -1:
        break;
    default:
        func_021EE008((char *)p, 0, 0);
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, r, 0x15);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            p->b16 = r;
            p->b17 = p->b14;
            func_021ECB84(p->work, p->b16);
            return func_021EA114((char *)p, p->b16);
        }
        break;
    }
    return 0x15;
}

#define W(p) (*(char **)((p)+0x2C))

int func_021E3258(u8 *p)
{
    unsigned n;
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        func_021ED55C((char **)p,0);
        func_021EE008((char *)p,0,0);
        func_021EE038((char *)p,0,0,1);
        if(func_020260E0(*(void **)(W(p)+0x70))>=30) func_021DF040((char *)p);
        (*(int *)(W(p)+0xA194))++;
        func_020061E4(0x669);
        return func_021EA858((char *)p,22);
    case 1:
        if(p[0x1B]==1) {
            func_021EF35C(*(struct WinMgr **)(W(p)+0x74));
            func_021EF36C(*(struct WinMgr **)(W(p)+0x74));
            (*(int *)(W(p)+0xA194))++;
            return func_021E8FC0((char *)p,(int)func_021E01B0,22);
        }
        n=func_020260E0(*(void **)(W(p)+0x70));
        if(n>=30) n=0;
        func_021EE364((char **)p,3,n);
        func_021ED544((char *)p,6);
        func_021ED508(p,14,1);
        func_021DEFEC((char *)p,n);
        *(int *)(W(p)+0xA194)=0;
        return 17;
    case 2:
        func_021EF68C(W(p));
        *(int *)(W(p)+0xA194)=0;
        return 33;
    }
    return 22;
}

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))


/*
 * Re-entry of the box menu: restores the cursor, redraws the box and picks
 * the message for the current mode.
 */
int func_021E3340(unsigned char *p)
{
    unsigned char sel;
    int arg;
    func_021DD530(p);
    p[0x18] = 0;
    p[0x17] = 0xFF;
    if (MODE(p) == 0) {
        sel = func_020260E0(OBJ(p));
    } else {
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE3E4((char **)p, p[0x16]);
        func_021ED55C((char **)p, 1);
        sel = p[0x16];
    }
    *(int *)(WORK(p) + 0xA168) = sel;
    func_021EA1E8((char *)p);
    if (func_021EF770(MGR(p)) == 1) {
        if (STATE(p) == 0x20) {
            func_021EE364((char **)p, 4, sel);
            func_021DEFEC((char *)p, sel);
            STATE(p) = 0x15;
            if (func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x1E && func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0)) {
            func_021DEFEC((char *)p, sel);
            arg = 0;
        } else {
            func_021DF040((char *)p);
            arg = 2;
        }
    } else if (func_021EF45C(MGR(p)) == 1) {
        if (STATE(p) == 0x15) {
            sel = func_020260E0(OBJ(p));
            if (sel > 0x20)
                sel = p[0x16];
            func_021EE364((char **)p, 6, sel);
            func_021DEFEC((char *)p, sel);
            STATE(p) = 0x20;
            if (func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x24 && func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0)) {
            func_021DEFEC((char *)p, sel);
            arg = 0;
        } else {
            func_021DF040((char *)p);
            arg = 2;
        }
    } else if (sel < 0x24 && func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0)) {
        func_021DEFEC((char *)p, sel);
        arg = 0;
    } else {
        func_021DF040((char *)p);
        arg = 2;
    }
    if (((Nib *)(p + 0x1C))->lo == 0) {
        ((Nib *)(p + 0x1C))->hi = 1;
        arg = p[0x21];
    }
    func_021EE038((char *)p, 0, 1, arg);
    switch (MODE(p)) {
    case 2:
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBD1C((char *)p, 2, 0x18);
        return 0x18;
    case 3:
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBD1C((char *)p, 3, 0x18);
        return 0x18;
    case 4:
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBD1C((char *)p, 4, 0x18);
        return 0x18;
    case 5:
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBD78((char *)p, 0);
        return 0x18;
    }
    if (((struct Obj23893 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
        if (func_021EF770(MGR(p)) == 1)
            func_021EF670(WORK(p));
        else
            func_021EF68C(WORK(p));
    }
    return STATE(p);
}

#undef W
#define W(p) (*(char **)((p) + 0x2C))

int func_021E3568(unsigned char *p)
{
    int n;
    if (func_021E2094((char *)p) == 6)
        return 0x18;
    if (func_020260F0(*(void **)(W(p) + 0x70)) == 1)
        func_021EC000(W(p), 4, 1);
    if ((unsigned char)W(p)[0xA173] == 5)
        n = 0x1B;
    else
        n = 0x18;
    func_021EBA5C(W(p), n);
    func_021DD14C((char *)p);
    if (((struct Obj23894 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
        if (func_021EF770(*(struct WinMgr **)(W(p) + 0x74)) == 1)
            func_021EF670(W(p));
        else
            func_021EF68C(W(p));
    }
    W(p)[0xA173] = 0;
    return ((struct Obj00000 *)p)->f28;
}

#undef W
#define W(p) (*(char **)((p)+0x2C))

int func_021E35D8(u8 *p)
{
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        func_021EC000(W(p),4,0);
        func_021EE008((char *)p,0,0);
        func_020061E4(0x669);
        (*(int *)(W(p)+0xA194))++;
        return func_021EA858((char *)p,25);
    case 1:
        func_021EF35C(*(struct WinMgr **)(W(p)+0x74));
        func_021EF36C(*(struct WinMgr **)(W(p)+0x74));
        if(p[0x18]==1) func_021EC5A0((char **)p,1);
        else func_021EC5A0((char **)p,0);
        func_020061E4(0x669);
        (*(int *)(W(p)+0xA194))++;
        return func_021E8FC0((char *)p,(int)func_021E01B0,25);
    case 2:
        func_021EE364((char **)p,6,30);
        func_021EE754(p,30);
        if(p[0x18]==0) func_021DEFEC((char *)p,30);
        func_021EF68C(W(p));
        *(int *)(W(p)+0xA168)=30;
        *(int *)(W(p)+0xA194)=0;
        return 32;
    }
    return 25;
}
