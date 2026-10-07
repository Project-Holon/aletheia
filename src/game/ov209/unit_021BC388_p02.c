/*
 * file:     unit_021BC388_p02.c
 * unit:     yes
 * function: func_021BCBE0, func_021BCC2C, func_021BCC58, func_021BCC94, func_021BCD48, func_021BCDE0, func_021BCDF8, func_021BCE98, func_021BD148, func_021BD1A0, func_021BD1C8, func_021BD268, func_021BD280, func_021BD2C4, func_021BD2F4, func_021BD314, func_021BD340, func_021BD354, func_021BD398
 * address:  0x021BCBE0
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9398 0x021B9398 thumb ov067
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021BDD7C 0x021BDD7C thumb ov209
 *   func_021BE51C 0x021BE51C thumb ov209
 *   func_021BE34C 0x021BE34C thumb ov209
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021BE5D4 0x021BE5D4 thumb ov209
 *   d_021BE96C 0x021BE96C data a4
 *   func_021BD838 0x021BD838 thumb ov209
 *   func_021BD3FC 0x021BD3FC thumb ov209
 *   func_021C93E4 0x021C93E4 thumb ov212
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_0204363C 0x0204363C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_021BC6C4 0x021BC6C4 thumb ov209
 *   func_021BC370 0x021BC370 thumb ov209
 *   func_021BC388 0x021BC388 thumb ov209
 *   func_021BC574 0x021BC574 thumb ov209
 *   func_021BC824 0x021BC824 thumb ov209
 *   func_021BD7F8 0x021BD7F8 thumb ov209
 *   func_021BC88C 0x021BC88C thumb ov209
 *   func_021BC9A8 0x021BC9A8 thumb ov209
 *   func_021BD628 0x021BD628 thumb ov209
 *   func_021BD704 0x021BD704 thumb ov209
 *   func_021BC7B8 0x021BC7B8 thumb ov209
 *   func_021BC7D0 0x021BC7D0 thumb ov209
 *   func_021BC8B4 0x021BC8B4 thumb ov209
 *   func_021BC298 0x021BC298 thumb ov209
 *   func_021BC2E4 0x021BC2E4 thumb ov209
 *   func_02034A5C 0x02034A5C arm
 *   func_021BC91C 0x021BC91C thumb ov209
 *   func_021BC2FC 0x021BC2FC thumb ov209
 *   func_021BC2B0 0x021BC2B0 thumb ov209
 *   func_021BC810 0x021BC810 thumb ov209
 *   func_021BCB60 0x021BCB60 thumb ov209
 *   func_021BC8A4 0x021BC8A4 thumb ov209
 *   func_021BD824 0x021BD824 thumb ov209
 *   func_021BD3E0 0x021BD3E0 thumb ov209
 *   func_021BC868 0x021BC868 thumb ov209
 *   func_021BC52C 0x021BC52C thumb ov209
 *   func_021BC704 0x021BC704 thumb ov209
 *   func_02021ED8 0x02021ED8 thumb
 *   func_021B7A64 0x021B7A64 thumb ov067
 *   func_021BE588 0x021BE588 thumb ov209
 *   func_021BE43C 0x021BE43C thumb ov209
 *   func_021BC730 0x021BC730 thumb ov209
 *   func_021BC90C 0x021BC90C thumb ov209
 *   func_021B7AB0 0x021B7AB0 thumb ov067
 *   func_021BD890 0x021BD890 thumb ov209
 *   func_021BE4A8 0x021BE4A8 thumb ov209
 *   func_021BE658 0x021BE658 thumb ov209
 *   func_021B93A4 0x021B93A4 thumb ov067
 *   func_021B93D4 0x021B93D4 thumb ov067
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0200CA70 0x0200CA70 thumb
 *   func_0200CA5C 0x0200CA5C thumb
 *   func_021BD8C4 0x021BD8C4 thumb ov209
 *   func_021B9280 0x021B9280 thumb ov067
 *   func_02041B6C 0x02041B6C arm
 *   func_020216D4 0x020216D4 thumb
 *   func_0200CA78 0x0200CA78 thumb
 *   func_02012BF8 0x02012BF8 thumb
 *   func_02012BE0 0x02012BE0 thumb
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_021BD5D4 0x021BD5D4 thumb ov209
 *   d_021BE990 0x021BE990 data a1
 */
#include "../../matched/include/Obj14667.h"
#include "../../matched/include/Obj00088.h"
#include "../../matched/include/Obj08408.h"
#include "../../matched/include/Obj00123.h"
#include "../../matched/include/Obj25546.h"
#include "../../matched/include/Obj14668.h"
#include "../../matched/include/Obj01435.h"
#include "../../matched/include/Obj25555.h"
#include "../../matched/include/Obj25556.h"
#include "../../matched/include/Obj10912.h"

struct Context;
struct Blk37;
struct S;
struct PalAnmSlot;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef struct S S;

enum Value { V0 };

struct Input {u32 a;void *save;u32 b,c,state;};

struct Context {struct Input *in;u8 pad4[0x10];u32 state;u8 pad18[0xc24-0x18];u16 flags;u8 padc26[6];void *list;};

struct Timer { unsigned short low : 1; unsigned short high : 15; };

struct Bits {u16 low:1;u16 high:15;};

extern u32 func_021B9398(char *p, int index);
extern int func_021B93B8(char *);
extern void func_021BDD7C(char *, u16);
extern void func_021BE51C(char *, int);
extern void func_021BE34C(char *,int),func_021BE51C(char *,int),func_021BE5D4(char *,int);
extern int func_021B93B0(char *);
extern void func_021BD838(char *),func_021BD3FC(const struct Context *),func_021C93E4(u32,u32,u8 *);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern int func_02034AC4(int);
extern void func_0204363C(u32);
extern void func_0203D34C(u32, u32);
extern void func_021BC370(void);
extern void func_021BC388(void);
extern void func_021BC574(void);
extern void func_021BC7B8(void);
extern void func_021BC6C4(char *);
extern void func_021BC824(char *);
extern void func_021BD7F8(char *);
extern void func_021BC88C(char *);
extern void func_021BC9A8(struct Context *p);
extern void func_021BD628(char *);
extern void func_021BD704(char *);
extern void func_021BC8B4(char *);
extern void func_021BC298(char *);
extern void func_021BC2E4(char *);
extern void func_021BC7D0(void);
extern u32 func_02021ED8(const char *);
extern void func_02034A5C(int);
extern int func_021BC91C(char *);
extern void func_021BC810(void);
extern void func_021BC52C(void);
extern void func_021BC2FC(char *);
extern void func_021BC2B0(char *);
extern void func_021BCB60(char *);
extern void func_021BC8A4(char *);
extern void func_021BD824(char *);
extern void func_021BD3E0(char *);
extern void func_021BC868(char *);
extern void func_021BC704(char *);
extern int func_021B7A64(struct S *p);
extern void func_021BE588(char *);
extern void func_021BE43C(char *);
extern void func_021BC730(char *p, u8 a, u8 b);
extern void func_021BC90C(char *, int);
extern int func_021B7AB0(struct S *p);
extern void func_021BD890(char *p, int idx, int value);
extern void func_021BE4A8(char *p);
extern int func_021BE658(void *ctx_);
extern int func_021B93A4(char *p);
extern void func_021B93D4(struct S *s, int v);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern void func_020061E4(u32);
extern u32 func_0200CA70(struct Blk37 *p);
extern void func_0200CA5C(struct Blk37 *p, u32 v);
extern u32 func_021BD8C4(char *p, u32 idx);
extern void func_021B9280(u8 *p, int a, u32 b);
extern void func_02041B6C(unsigned);
extern void func_020216D4(struct PalAnmSlot *, unsigned, unsigned, unsigned);
extern void func_0200CA78(void *,u16);
extern int func_02012BF8(int, int);
extern void func_02012BE0(void *, unsigned, unsigned);
extern void func_02045088(unsigned short);
extern unsigned func_020450F0(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);
extern void func_021BD5D4(char *);
void func_021BCBE0(char *p, int index);
void func_021BCC2C(char *p,int delta);
int func_021BCC58(char *p);
int func_021BCC94(char *p);
int func_021BCD48(char *p);
int func_021BCDE0(char *p);
int func_021BCDF8(char *p);
int func_021BCE98(struct Context *p);
int func_021BD148(char *p);
int func_021BD1A0(char *p);
int func_021BD1C8(char *p);
int func_021BD268(char *p);
void func_021BD280(char *p);
int func_021BD2C4(char *p,int a,int b,int c);
int func_021BD2F4(char *p,int i);
void func_021BD314(char *p,int i);
int func_021BD340(char *a, int arg);
void func_021BD354(char *p);
void func_021BD398(char *p);
extern const char ov067_id[];
extern const u8 d_021BE990[][6];

void func_021BCBE0(char *p, int index)
{
    u32 v;
    v = func_021B9398(((struct Obj14667 *)p)->fC2C, index);
    if ((v & 0xF0000000) >> 28) func_021BDD7C(p, v & 0x0FFFFFFF);
    else func_021BDD7C(p, 0);
    func_021BE51C(p, index - func_021B93B8(*(char * *)&((struct Obj14667 *)p)->fC2C));
}

void func_021BCC2C(char *p,int delta) { func_021BE34C(p,(signed char)-delta);func_021BE51C(p,func_021B93B0(*(char * *)&((struct Obj00088 *)p)->fC2C));func_021BE5D4(p,1); }

extern int (*const d_021BE96C[])(char *);

int func_021BCC58(char *p) { ((struct Obj08408 *)p)->f10=(*(int (**)(char *))((u32)d_021BE96C+*(u32 *)(p+16)*4))(p);if(((struct Obj08408 *)p)->f10==9)return 0;func_021BD838(p);func_021BD3FC((const struct Context *)p);func_021C93E4(3,7,(u8 *)p+0xc3c);return 1; }

/*
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCCB0, 021BCCB2
 */
int func_021BCC94(char *p)
{
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_0204363C(0);
    func_021BC6C4(p);
    func_021BC370();
    func_021BC388();
    func_021BC574();
    func_021BC824(p);
    func_021BD398(p);
    func_021BD7F8(p);
    func_021BC88C(p);
    func_021BC9A8((struct Context *)p);
    if (((struct Obj25546 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f8 == 0) func_021BD628(p);
    else func_021BD704(p);
    func_0203D34C(1, 0x6B);
    func_021BC7B8();
    func_021BC7D0();
    func_021BC8B4(p);
    func_021BC298(p);
    func_021BC2E4(p);
    return 3;
}

/*
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCDB6, 021BCDBA
 */
int func_021BCD48(char *p)
{
    if (func_021BC91C(p) == 1 || func_02021ED8(*(char * *)&((struct Obj00088 *)p)->fC) != 0) return 1;
    func_021BC2FC(p);
    func_021BC2B0(p);
    func_021BC810();
    func_021BCB60(p);
    func_021BC8A4(p);
    func_021BD824(p);
    func_021BD3E0(p);
    func_021BC868(p);
    func_021BC52C();
    func_021BC704(p);
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_02034A5C((int)ov067_id);
    return 9;
}

int func_021BCDE0(char *p) { if(func_02021ED8(*(char * *)&((struct Obj14668 *)p)->fC)==0)return ((struct Obj14668 *)p)->f1C;return 2; }

/*
 * note: int step schedules the p copy before movs r6,16; enum step swaps those instructions (DIFF4).
 */
int func_021BCDF8(char *p)
{
    int step;
    switch (((struct Obj00088 *)p)->fC30) {
    case 0:
        if (func_021B7A64(*(S * *)&((struct Obj00088 *)p)->fC2C) == 0) {
            func_021BE5D4(p, 0);
            func_021BE588(p);
            func_021BE43C(p);
            func_021BD280(p);
            (((struct Obj00088 *)p)->fC30)++;
        }
        break;
    case 1:
        if (func_02021ED8(*(char * *)&((struct Obj00088 *)p)->fC) == 0) {
            func_0207D534((unsigned short *)0x0400006c, 0);
            func_0207D534((unsigned short *)0x0400106c, 0);
            func_021BC730(p, step = 16, 0);
            step -= 24;
            func_021BC90C(p, step);
            (((struct Obj00088 *)p)->fC30)++;
        }
        break;
    case 2:
        if (func_021BC91C(p) == 0 && func_02021ED8(*(char * *)&((struct Obj00088 *)p)->fC) == 0) {
            ((struct Obj00088 *)p)->fC30 = 0;
            return 4;
        }
        break;
    }
    return 3;
}

/*
 * ov067 region follows the paired loader path 021BCC94/021BCD48.
 * 021B93D4's value is full width here: original subtract feeds r1 without narrowing.
 */
int func_021BCE98(struct Context *p)
{
    int result=4;
    int selected;
    u32 action;
    u8 old;
    switch(func_021B7AB0(p->list)){
    case -12: break;
    case -11:case -10:case -9:case -8:
        func_021BE5D4((char *)p,0);break;
    case -7:
        func_021BD890((char *)p,7,12);
        p->flags=(p->flags&~0xfffe)|14;p->state=0;result=5;break;
    case -6:
        func_021BD890((char *)p,6,13);
        p->flags=(p->flags&~0xfffe)|12;p->state=0;result=5;break;
    case -5:return func_021BD2C4((char *)p,7,12,4);
    case -4:return func_021BD2C4((char *)p,6,13,4);
    case -3:case -2:
        func_021BE4A8((char *)p);
        p->flags=(p->flags&~0xfffe)|120;p->state=1;result=5;break;
    case -1:
        old=func_020355C4();
        action=func_021BE658(p);
        switch(action){
        case 0:
            selected=func_021B93A4(p->list);
            if(func_021BD2F4((char *)p,selected)==1){func_020061E4(1356);return func_021BD340((char *)p,selected);}
            func_020355D8(old);break;
        case 1:case 2:case 3:case 4:case 5:case 6:case 7:
            selected=action+func_021B93B8(p->list)-1;
            if(func_021BD2F4((char *)p,selected)==1){
                func_020061E4(1356);func_021B93D4(p->list,action-1);return func_021BD340((char *)p,selected);
            }break;
        case 8:
            func_020061E4(1356);p->in->state=4;
            func_021BD314((char *)p,func_021B93A4(p->list));return func_021BD2C4((char *)p,9,4,8);
        case 9:
            func_020061E4(1356);
            if(func_0200CA70(p->in->save)==1)func_0200CA5C(p->in->save,0);else func_0200CA5C(p->in->save,1);
            p->in->state=2;
            func_021BD314((char *)p,func_021B93A4(p->list));return func_021BD2C4((char *)p,8,5,8);
        case 10:func_020061E4(1606);func_021BD354((char *)p);break;
        case 11:
            func_020061E4(1366);p->in->state=1;
            func_021BD314((char *)p,func_021B93A4(p->list));return func_021BD2C4((char *)p,4,8,8);
        case 12:
            func_020061E4(1361);p->in->state=0;
            func_021BD314((char *)p,func_021B93A4(p->list));return func_021BD2C4((char *)p,3,9,8);
        case 13:
            func_020061E4(1361);p->in->state=0;
            func_021BD314((char *)p,func_021B93A4(p->list));return func_021BD2C4((char *)p,3,9,8);
        }
        break;
    default:
        selected=func_021B93A4(p->list);func_021BE5D4((char *)p,0);
        if(func_021BD2F4((char *)p,selected)==1){func_020061E4(1356);return func_021BD340((char *)p,selected);}
        break;
    }
    func_021BE588((char *)p);func_021BE43C((char *)p);return result;
}

int func_021BD148(char *p)
{
    switch (*(int *)&((struct Obj00088 *)p)->f14) {
    case 0:
        if (func_021B7AB0((struct S *)(*(char * *)&((struct Obj00088 *)p)->fC2C)) == -1) (*(int *)&((struct Obj00088 *)p)->f14)++;
        break;
    case 1:
        if (((struct Timer *)(p + 0xc24))->high == 60 || func_021BD8C4(p, ((struct Timer *)(p + 0xc24))->high) == 0) {
            *(int *)&((struct Obj00088 *)p)->f14 = 0;
            func_021BE5D4(p, 0);
            return 4;
        }
        break;
    }
    return 5;
}

int func_021BD1A0(char *p) { if(func_021BD8C4(p,((struct Bits *)(p+0xc24))->high)==0){func_021BE5D4(p,0);return ((struct Obj00088 *)p)->f18;}return 6; }

/*
 * note: repeated decrement in each arm cross-jumps through branch stubs; explicit shared goto costs DIFF81/156.
 */
int func_021BD1C8(char *p)
{
    switch (((struct Obj01435 *)p)->fC26) {
    case 0:
    case 2:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            func_021B9280((u8 *)(*(char * *)&((struct Obj01435 *)p)->fC2C), (unsigned short)func_021B93B0(*(char * *)&((struct Obj01435 *)p)->fC2C), 1);
            ((struct Obj01435 *)p)->fC27 = 4;
            (((struct Obj01435 *)p)->fC26)++;
        } else (((struct Obj01435 *)p)->fC27)--;
        break;
    case 1:
    case 3:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            func_021B9280((u8 *)(*(char * *)&((struct Obj01435 *)p)->fC2C), (unsigned short)func_021B93B0(*(char * *)&((struct Obj01435 *)p)->fC2C), 2);
            func_02041B6C(2);
            ((struct Obj01435 *)p)->fC27 = 4;
            (((struct Obj01435 *)p)->fC26)++;
        } else (((struct Obj01435 *)p)->fC27)--;
        break;
    case 4:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            ((struct Obj01435 *)p)->fC26 = 0;
            return 8;
        }
        (((struct Obj01435 *)p)->fC27)--;
        break;
    }
    return 7;
}

int func_021BD268(char *p) { func_021BC730(p,0,16);func_021BC90C(p,8);return 1; }

void func_021BD280(char *p)
{
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 0, 0, 512);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 1, 0, 512);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 2, 0, 512);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 3, 0, 512);
    func_021BC730(p, 16, 16);
}

int func_021BD2C4(char *p,int a,int b,int c) { func_021BD890(p,a,b);((struct Bits *)(p+0xc24))->high=(u16)a;((struct Obj25555 *)p)->f18=c;return 6; }

int func_021BD2F4(char *p,int i) { if((func_021B9398(*(char * *)&((struct Obj00088 *)p)->fC2C,i)&0xf0000000u)>>28)return 1;return 0; }

void func_021BD314(char *p,int i) { if(func_021BD2F4(p,i)==1)func_0200CA78(((struct Obj25556 *)(*(char * *)&((struct Obj00088 *)p)->f0))->f4,func_021B9398(*(char * *)&((struct Obj00088 *)p)->fC2C,i)); }


int func_021BD340(char *a, int arg)
{
    func_021BD314(a, arg);
    *(int *)(*(int *)&((struct Obj00088 *)a)->f0 + 0x10) = 3;
    return 7;
}

/*
 * extent: 021BD396 two-byte alignment padding before 021BD398.
 */
void func_021BD354(char *p)
{
    if (func_02012BF8(**(int * *)&((struct Obj10912 *)p)->f0, 15) == 1) {
        func_02012BE0(**(void ** *)&((struct Obj10912 *)p)->f0, 15, 0);
        func_021BD890(p, 5, 6);
    } else {
        func_02012BE0(**(void ** *)&((struct Obj10912 *)p)->f0, 15, 1);
        func_021BD890(p, 5, 7);
    }
}

void func_021BD398(char *p)
{
    unsigned i;
    func_02045088(107);
    for (i = 0; i < 3; i++)
        *(unsigned *)(p + i * 8 + 32) = func_020450F0(d_021BE990[i][0], d_021BE990[i][1], d_021BE990[i][2], d_021BE990[i][3], d_021BE990[i][4], d_021BE990[i][5], 1);
    func_021BD5D4(p);
}
