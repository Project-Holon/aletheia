/*
 * file:     shinka_demo_view_p04.c
 * unit:     yes
 * function: func_02205B6C, func_02205BAC, func_02205BC8, func_02205BD0, func_02205BD8, func_02205BDC, func_02205C48, func_02205C58, func_02205C6C, func_02205C74, func_02205D28, func_02205D50, func_0220602C
 * address:  0x02205B6C
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   d_020A1EB8 0x020A1EB8 data a4
 *   d_02208C88 0x02208C88 data a4
 *   d_02208C7C 0x02208C7C data a4
 *   d_02208C94 0x02208C94 data a4
 *   func_02205854 0x02205854 thumb ov195
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 *   d_02208F68 0x02208F68 data
 *   func_02030734 0x02030734 arm
 *   func_020173EC 0x020173EC thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   func_020178D8 0x020178D8 thumb
 *   func_0220609C 0x0220609C thumb ov195
 *   func_02206108 0x02206108 thumb ov195
 *   func_022063E0 0x022063E0 thumb ov195
 *   func_022065C8 0x022065C8 thumb ov195
 *   func_0220623C 0x0220623C thumb ov195
 *   func_022060BC 0x022060BC thumb ov195
 *   func_020307B0 0x020307B0 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_02006984 0x02006984 thumb
 *   func_02006650 0x02006650 thumb
 *   func_02015F50 0x02015F50 thumb
 *   func_02206264 0x02206264 thumb ov195
 *   func_02015E04 0x02015E04 thumb
 *   func_0201600C 0x0201600C thumb
 *   func_022063AC 0x022063AC thumb ov195
 *   func_02206768 0x02206768 thumb ov195
 *   func_02015EE8 0x02015EE8 thumb
 *   func_02064CBC 0x02064CBC arm
 *   func_022067BC 0x022067BC thumb ov195
 *   func_022067FC 0x022067FC thumb ov195
 *   func_0220672C 0x0220672C thumb ov195
 *   func_0220682C 0x0220682C thumb ov195
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015E4C 0x02015E4C thumb
 *   func_02014C08 0x02014C08 thumb
 *   func_02206604 0x02206604 thumb ov195
 *   func_02014D2C 0x02014D2C thumb
 *   func_02206664 0x02206664 thumb ov195
 */
#include "../../matched/include/Obj14529.h"
#include "../../matched/include/Obj24953.h"
#include "../../matched/include/Obj24957.h"
#include "../../matched/include/Obj02911.h"

#define W(n) (*(u32 *)(p+(n)))
#define P(n) (*(void **)(p+(n)))
#define B(n) (*(u8 *)(p+(n)))
#define NODE(i) (*(void **)(p+0x50+(u32)(i)*4))
struct Cfg;
struct Bank;
struct RecDC;
struct McssFade;
struct Obj;
struct Owner;
struct McssSys;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short s16;

typedef struct Owner_02205C74 {
    u16 heap;
    u16 pad02;
    void *res0;
    u32 f08;
    u16 f0c;
    u16 pad0e;
    void *res1;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u8 pad28[0x34 - 0x28];
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    float scale;
    u8 f48;
    u8 pad49[0x5c - 0x49];
    u32 f5c;
} Owner_02205C74;

typedef struct Owner_02205D28 Owner_02205D28;

typedef signed int     s32;

typedef struct Owner_0220602C {
    u16 heap;
    u8 pad02[0x4a];
    void *mcss;
    u8 pad50[0x5c - 0x50];
    u32 f5c;
} Owner_0220602C;

extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(int);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02205854(void);
extern void func_02046440(int, int, int, int, int, void *, void *);
extern u32 func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, void *);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(int);
extern void func_02047964(void *);
extern int func_02048AD0(int);
extern void func_020479D8(int);
extern void func_02047970(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020173EC(void);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void func_020178D8(void *p, u32 a);
extern void func_0220609C(char *a);
extern void func_02206108(Owner_02205C74 *o);
extern void func_022063E0(Owner_02205C74 *o);
extern void func_022065C8(char *);
extern void func_0220623C(struct Owner_02205D28 *o);
extern void func_022060BC(char *);
extern u32 func_020307B0(void *p);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern int func_02006650(void);
extern void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern u8 func_02206264(u8);
extern void func_02015E04(void *);
extern int func_0201600C(void *);
extern void func_022063AC(char *,u32);
extern void func_02206768(char *,u32,u32,u32);
extern void *func_02015EE8(void *);
extern void func_02064CBC(struct Obj *);
extern void func_022067BC(struct Owner *);
extern int func_022067FC(char *);
extern void func_0220672C(struct Owner *);
extern int func_0220682C(char *);
extern void func_02015EB0(void *);
extern void func_02015EA0(void *);
extern void func_02015E4C(void *);
extern void func_02014C08(char *);
extern void func_02206604(struct Owner *);
extern void func_02014D2C(struct McssSys *sys);
extern void func_02206664(Owner_0220602C *o);
void func_02205B6C(unsigned char *p, int a, u32 b);
void func_02205BAC(char *a);
void func_02205BC8(void *a0);
void func_02205BD0(void *a0);
int func_02205BD8(int *p);
void func_02205BDC(u32 *a, void *b);
void func_02205C48(int *p);
void func_02205C58(char *a);
void func_02205C6C(void *p);
Owner_02205C74 *func_02205C74(u16 heap, u32 f08, void *res0, u16 f0c);
void func_02205D28(char *p);
void func_02205D50(char *p);
void func_0220602C(Owner_0220602C *o);
extern const s16 d_020A1EB8[];
extern u32 d_02208C88[];
extern u32 d_02208C7C[];
extern u32 d_02208C94[];
extern char d_02208F68[];


void func_02205B6C(unsigned char *p, int a, u32 b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x02208CB0, a, b);
    ((struct Obj14529 *)p)->f0 = func_0204B100(0x80, 0, b);
    func_0204B270(((struct Obj14529 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


void func_02205BAC(char *a)
{
    func_0204A5AC(func_0204B1CC((struct Bank *)(((struct Obj24953 *)a)->f0)));
    func_02082BCC(a, 0, 4);
}

void func_02205BC8(void *a0){func_0204A600();}

void func_02205BD0(void *a0){func_0204A648();}

int func_02205BD8(int *p)
{
    return *p;
}


void func_02205BDC(u32 *a, void *b)
{
    func_02046440(0, 2, 0, 1, 0, b, func_02205854);
    *a = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                       d_02208C88, d_02208C7C, d_02208C94, b);
}


void func_02205C48(int *p)
{
    func_02046788(func_02048AC4((void *)(*p)));
}


void func_02205C58(char *a)
{
    func_02047964(a);
    func_020479D8(func_02048AD0(((struct Obj24957 *)a)->f0));
}


void func_02205C6C(void *p)
{
    func_02047970();
}


Owner_02205C74 *func_02205C74(u16 heap, u32 f08, void *res0, u16 f0c)
{
    Owner_02205C74 *o = func_02030734(heap, 0x60, 1, d_02208F68, 0x201);

    o->heap = heap;
    o->f08 = f08;
    o->res0 = res0;
    o->f0c = f0c;
    o->res1 = 0;
    if (f08 == 0) {
        o->res1 = func_02030734(o->heap, func_020173EC(), 1, d_02208F68, 0x213);
        func_02019CE0(o->res0, o->res1);
        func_020178D8(o->res1, o->f0c);
    }
    if (o->f08 == 0)
        o->f14 = 0;
    else
        o->f14 = 0x16;
    o->f18 = 0;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f34 = 0;
    o->f38 = 0;
    o->f3c = 0;
    o->f40 = 0;
    o->scale = 16.0f;
    if (o->f08 == 0)
        o->f48 = 0;
    else
        o->f48 = 1;
    func_0220609C((char *)o);
    func_02206108(o);
    func_022063E0(o);
    o->f5c = 1;
    return o;
}

/*
 * extent: two trailing bytes of zero alignment padding.
 */
void func_02205D28(char *p){func_022065C8(p);func_0220623C((Owner_02205D28 *)p);func_022060BC(p);if(((struct Obj02911 *)p)->f10)func_020307B0(((struct Obj02911 *)p)->f10);func_020307B0(p);}

void func_02205D50(char *p)
{
    switch(W(0x14)) {
    case 0:
        if(W(0x1c)) {
            u32 a,b;
            W(0x14)=1;
            a=func_02017E1C(P(4),5,0);
            b=func_02017E1C(P(4),0x6f,0);
            func_02006984(a,b,0x40,0,0,0,0,0);
        }
        break;
    case 1:
        if(!func_02006650()){W(0x14)=2;W(0x20)=1;}
        break;
    case 2:if(W(0x24))W(0x14)=3;break;
    case 3:
        W(0x14)=4;
        func_02015F50((struct McssFade *)NODE(B(0x48)),0,16,0,0x7fff);
        func_02015F50((struct McssFade *)NODE(func_02206264(B(0x48))),16,16,0,0x7fff);
        func_02015E04(NODE(B(0x48)));
        break;
    case 4:if(!func_0201600C(NODE(B(0x48))))W(0x14)=5;break;
    case 5:
        if(W(0x18)>=8){W(0x14)=6;W(0x18)=0;}
        else W(0x18)++;
        break;
    case 6:
        W(0x14)=8;
        func_022063AC(p,0x100000);
        func_02206768(p,0,0xfffff800,0);
        W(0x5c)=0;
        func_02064CBC((struct Obj *)func_02015EE8(NODE(B(0x48))));
        break;
    case 7:
        if(W(0x18)>=1){W(0x14)=8;W(0x18)=0;}
        else W(0x18)++;
        break;
    case 8:W(0x14)=9;func_022067BC((struct Owner *)p);break;
    case 9:
        if(func_022067FC(p)){W(0x14)=10;W(0x38)=1;func_0220672C((struct Owner *)p);}
        break;
    case 10:if(func_0220682C(p))W(0x14)=11;break;
    case 11:
        if(W(0x18)>=30){W(0x14)=13;W(0x18)=0;W(0x3c)=1;W(0x28)=1;}
        else W(0x18)++;
        break;
    case 12:if(func_0220682C(p)){W(0x14)=13;W(0x3c)=1;W(0x28)=1;}break;
    case 13:if(W(0x2c))W(0x14)=14;break;
    case 14:
        W(0x14)=15;
        if(W(0x40))W(0x18)=0;
        else {
            B(0x48)=func_02206264(B(0x48));
            func_02015EB0(NODE(B(0x48)));
            func_02015EA0(NODE(func_02206264(B(0x48))));
            W(0x18)=30;
        }
        func_022063AC(p,0);
        func_02206768(p,0x100000,0xfffff800,0);
        W(0x5c)=1;
        break;
    case 15:if(W(0x30))W(0x14)=16;break;
    case 16:
        W(0x14)=17;
        func_02015F50((struct McssFade *)NODE(B(0x48)),16,0,1,0x7fff);
        break;
    case 17:
        if(!func_0201600C(NODE(B(0x48)))){W(0x14)=18;func_02015E4C(NODE(B(0x48)));}
        break;
    case 18:
        if(!W(0x18)){W(0x14)=19;W(0x18)=0;}
        else W(0x18)--;
        break;
    case 19:
        {
            void *obj;
            u32 a,b;
            W(0x14)=20;
            if(W(0x40))obj=P(4);else obj=P(0x10);
            a=func_02017E1C(obj,5,0);
            b=func_02017E1C(obj,0x6f,0);
            func_02006984(a,b,0x40,0,0,0,0,0);
        }
        break;
    case 20:if(!func_02006650()){W(0x14)=21;W(0x18)=0;W(0x34)=1;}break;
    case 21:case 22:break;
    }
    if(W(0x5c))func_02014C08(P(0x4c));
    func_02206604((struct Owner *)p);
}


void func_0220602C(Owner_0220602C *o)
{
    if (o->f5c != 0)
        func_02014D2C(o->mcss);
    else
        func_02206664(o);
}
