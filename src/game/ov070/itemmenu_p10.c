/*
 * file:     itemmenu_p10.c
 * unit:     yes
 * function: func_021B8904, func_021B8990, func_021B8AF4, func_021B8B0C, func_021B8B24, func_021B8B6C, func_021B8B7C, func_021B8C1C, func_021B8CB4, func_021B8CE4, func_021B8D88, func_021B8DAC, func_021B8DCC, func_021B8E08, func_021B8E48
 * address:  0x021B8904
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 *   func_021BA41C  0x021BA41C  thumb  ov070
 *   func_021BA4A4  0x021BA4A4  thumb  ov070
 *   func_021B9ED8  0x021B9ED8  thumb  ov070
 *   func_021BB73C  0x021BB73C  thumb  ov070
 *   func_020310C4  0x020310C4  arm
 *   func_020221A4  0x020221A4  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_02008298  0x02008298  thumb
 *   func_02008288  0x02008288  thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_021B9AF8  0x021B9AF8  thumb  ov070
 *   func_021B9758  0x021B9758  thumb  ov070
 *   func_02031140  0x02031140  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021BAF10  0x021BAF10  thumb  ov070
 *   func_0203FB44  0x0203FB44  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02028604  0x02028604  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_021B8E84  0x021B8E84  thumb  ov070
 *   func_02051C6C  0x02051C6C  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02036270  0x02036270  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_021B6100 0x021B6100 thumb ov070
 *   func_021B7250 0x021B7250 thumb ov070
 *   func_021B66FC 0x021B66FC thumb ov070
 *   func_0202E940  0x0202E940  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0202E9AC  0x0202E9AC  thumb
 *   func_02049238  0x02049238  arm
 *   func_0202EA20 0x0202EA20 thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB398  0x021BB398  thumb  ov070
 *   func_0202EB04  0x0202EB04  thumb
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021B7128  0x021B7128  thumb  ov070
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021B6288  0x021B6288  thumb  ov070
 *   func_021B80BC  0x021B80BC  thumb  ov070
 *   func_021B81F4  0x021B81F4  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_02035C08 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   d_021BB978 0x021BB978 data a4
 *   func_021B7DD0 0x021B7DD0 thumb ov070
 *   func_021BB3F4 0x021BB3F4 thumb ov070
 *   func_020355C4 0x020355C4 arm
 *   func_021B80C4 0x021B80C4 thumb ov070
 *   func_021B7CD0  0x021B7CD0  thumb  ov070
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 */
#include "../../matched/include/Obj01365.h"
#include "../../matched/include/Obj07690.h"
#include "../../matched/include/Obj20671.h"
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj04331.h"

struct Tcbl;
struct MyItemSave;
struct Descriptor;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
struct S020315D4;
struct CodeIn;
struct Obj0202EA20;
struct Obj;
struct Row;
struct Actor;
struct PalAnmSlot;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef short s16;

typedef struct Parent {
    u8 pad00[0x34];
    u32 f34;
    u32 f38;
} Parent;

typedef struct Obj {
    u8 pad000[0x14];
    void *gfx;
    u8 pad018[0x4FC - 0x18];
    u32 f4FC;
    u8 pad500[0x50C - 0x500];
    u32 f50C;
    u8 pad510[0x518 - 0x510];
    u32 f518;
    u32 f51C;
    u32 f520;
    u32 f524;
    u32 f528;
    u32 f52C;
    u32 f530;
    u8 pad534[0x694 - 0x534];
    u32 f694;
    u32 f698;
    u8 pad69C[0x730 - 0x69C];
    u32 f730;
    u8 pad734[0x7E0 - 0x734];
    u32 f7E0;
    u8 pad7E4[0x80C - 0x7E4];
    int f80C;
    int f810;
    int f814;
    u8 pad818[0x838 - 0x818];
    u32 f838;
    u8 pad83C[0x844 - 0x83C];
    u32 f844;
    u8 pad848[0x84C - 0x848];
    u32 f84C;
    u8 pad850[0x86C - 0x850];
    u32 f86C;
    u32 f870;
} Obj;

typedef signed int     s32;

typedef void (*Callback)(void *);

extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021BA41C(char *p);
extern void func_021BA4A4(char *p);
extern void func_021B9ED8(char *p);
extern void func_021BB73C(u8 *p);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_020221A4(void);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02030EAC(struct Node *n);
extern void func_02008298(struct MyItemSave *p, u16 v);
extern void func_02008288(struct MyItemSave *p, int i, s16 a, s16 b);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021B9AF8(char *p);
extern void func_021B9758(char *p);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021BAF10(char *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern u32 func_0201D83C(void *ptr);
extern int func_02028604(int a0);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021B8E84(char *p);
extern void func_02051C6C(void *p);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern int func_02036270(int a0, int a1);
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int a);
extern void func_021B6100(char *p, int k);
extern void func_021B7250(void *p);
extern void func_021B66FC(u8 *p);
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern void func_02049238(void *arc);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void func_020061E4(u32 a);
extern void func_021BB398(int p, u32 val);
extern void func_0202EB04(struct CodeIn *p);
extern s32 func_0202EA40(struct Row *p);
extern void func_021B7128(struct Obj *o);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *obj, unsigned int v);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021B6288(struct Obj *o, int a, int b);
extern void func_021B80BC(void *p);
extern void func_021B81F4(u8 *p);
extern void func_021B6138(char *p);
extern int func_02035C08(const void *p);
extern void func_020355D8(u8 v);
extern void func_021B7DD0(unsigned char *p);
extern void func_021BB3F4(int p, int mode);
extern u8 func_020355C4(void);
extern void func_021B80C4(struct Obj *o, int flag);
extern void func_021B7CD0(struct Obj *o);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
int func_021B8904(int a, int b, int c, int p);
int func_021B8990(void *proc, int b, Parent *par, Obj *o);
void func_021B8AF4(void *p);
int func_021B8B0C(void *p);
void func_021B8B24(int p);
void func_021B8B6C(char *p);
void func_021B8B7C(int p);
void func_021B8C1C(int p, int a, int b);
void func_021B8CB4(char *p);
void func_021B8CE4(int p, int u, int a, int b);
void func_021B8D88(char *p);
int func_021B8DAC(void);
void func_021B8DCC(char *p);
void func_021B8E08(unsigned char *p);
void func_021B8E48(char *p);
extern const char d_021BB978[];


int func_021B8904(int a, int b, int c, int p)
{
    void (*fn)(int) = *(void (**)(int))((char *)p + 0x4F8);
    if (fn == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, ((struct Obj01365 *)p)->f544);
        return 1;
    }
    ((struct Obj01365 *)p)->f818 = ((struct Obj01365 *)p)->f814;
    fn(p);
    if (((struct Obj01365 *)p)->f83E != 0) {
        func_021BA41C((char *)p);
        ((struct Obj01365 *)p)->f83E = 0;
    }
    if (((struct Obj01365 *)p)->f83C != 0) {
        func_021BA4A4((char *)p);
        ((struct Obj01365 *)p)->f83C = 0;
    }
    func_021B9ED8((char *)p);
    func_021BB73C((u8 *)p);
    func_020310C4((struct Tcbl *)(((struct Obj01365 *)p)->f730));
    return 0;
}


int func_021B8990(void *proc, int b, Parent *par, Obj *o)
{
    if (func_020221A4() != 1)
        return 0;
    if (func_0201C6B4((const struct PrintSys *)o->f50C) == 0)
        return 0;
    func_02030EAC((struct Node *)o->f698);
    func_02008298(o->gfx, o->f80C);
    func_02008288(o->gfx, (u16)o->f80C, o->f810, o->f814 + 1);
    func_02027FD8((struct TaskMenuState *)o->f7E0);
    func_021B9AF8((char *)o);
    func_021B9758((char *)o);
    func_02031140((struct S02031140 *)o->f730);
    func_02045C04((struct Rec *)o->f51C);
    func_02045808((struct U16Vec *)o->f524);
    func_02045808((struct U16Vec *)o->f528);
    func_02045808((struct U16Vec *)o->f52C);
    func_0201ED04((struct WordSet *)o->f520);
    func_021BAF10((char *)o);
    if (o->f4FC != 0) {
        func_0203FB44((int)3, (unsigned short)o->f838, (unsigned short)(o->f838 >> 16));
        func_020452E8((struct Descriptor *)o->f4FC);
    }
    func_02040DA8(3, 1, 0);
    func_0201D83C((void *)o->f530);
    func_02028604(o->f518);
    func_0201C6EC((struct PrintSys *)o->f50C);
    func_0201C4C0((struct PrintSys *)o->f50C);
    func_021B8E84((char *)o);
    func_021B8B6C((char *)o);
    func_02051C6C((void *)o->f694);
    func_020450C8();
    func_0203F9B4();
    par->f34 = o->f844;
    par->f38 = o->f84C;
    func_02036270(o->f86C, o->f870);
    func_020315D4(proc);
    func_020306F0(0xE);
    return 1;
}

void func_021B8AF4(void *p)
{
    func_021B6100(p, (int)func_021B7250);
    func_02036270(3, 6);
}

int func_021B8B0C(void *p)
{
    func_021B6100(p, (int)func_021B66FC);
    return func_02036270(3, 6);
}


void func_021B8B24(int p)
{
    void *h;
    *(struct CodeIn * *)&((struct Obj07690 *)p)->f850 =
        func_0202E940(0x10, 0x10, 0xFFFE, ((struct Obj07690 *)p)->f544);
    h = func_020490F4(0x58, ((struct Obj07690 *)p)->f544);
    func_0202E9AC(*(struct CodeIn * *)&((struct Obj07690 *)p)->f850, h, 0x15, 0x10, 0x20);
    func_02049238(h);
}

void func_021B8B6C(char *p)
{
    func_0202EA20(*(struct Obj0202EA20 * *)&((struct Obj20671 *)p)->f850);
}


void func_021B8B7C(int p)
{
    switch (((struct Obj00002 *)p)->f864) {
    case 0:
        func_020061E4(0x54C);
    case 3:
        func_021BB398(p, 0);
        ((struct Obj00002 *)p)->f864 += 1;
        return;
    case 1:
    case 4:
    case 6:
        ((struct Obj00002 *)p)->f866 += 1;
        if (((struct Obj00002 *)p)->f866 == 4) {
            ((struct Obj00002 *)p)->f866 = 0;
            ((struct Obj00002 *)p)->f864 += 1;
        }
        return;
    case 2:
    case 5:
        func_021BB398(p, 2);
        ((struct Obj00002 *)p)->f864 += 1;
        return;
    case 7:
        ((struct Obj00002 *)p)->f864 = 0;
        func_021BB398(p, 1);
        func_0202EB04((struct CodeIn *)(*(int *)&((struct Obj00002 *)p)->f850));
        func_0202EA40((struct Row *)(*(int *)&((struct Obj00002 *)p)->f850));
        func_021B6100((char *)p, (int)func_021B7128);
        return;
    }
}


void func_021B8C1C(int p, int a, int b)
{
    int x;
    if (a == 4) {
        func_020061E4(0x551);
        x = 9;
    } else if (a == 3) {
        func_020061E4(0x556);
        x = 8;
    } else if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    ((struct Obj00002 *)p)->f864 = a;
    func_0204B8C4((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), 0);
    func_0204B878((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), (unsigned short)x);
    func_0204B92C((struct Obj *)*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710), 1);
    *(int *)&((struct Obj00002 *)p)->f868 = b;
    func_021B6100((char *)p, (int)func_021B8CB4);
}

void func_021B8CB4(char *p)
{
    if (func_0204B98C((struct Actor *)(*(int *)(p + 0x710 + ((struct Obj00002 *)p)->f864 * 4))) == 0) {
        ((struct Obj00002 *)p)->f864 = 0;
        func_021B6100(p, (int)(*(Callback *)&((struct Obj00002 *)p)->f868));
    }
}


void func_021B8CE4(int p, int u, int a, int b)
{
    int x;
    func_021B6288((struct Obj *)p, u, ((struct Obj00002 *)p)->f80C);
    func_021B80BC((void *)p);
    func_021B81F4((u8 *)p);
    ((struct Obj00002 *)p)->f818 = 0xFFFF;
    func_021B6138((char *)p);
    if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    ((struct Obj00002 *)p)->f864 = a;
    ((struct Obj00002 *)p)->f866 = 6;
    func_0204B8C4((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), 0);
    func_0204B878((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), (unsigned short)x);
    func_0204B92C((struct Obj *)*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710), 1);
    *(int *)&((struct Obj00002 *)p)->f868 = b;
    func_021B6100((char *)p, (int)func_021B8D88);
}

void func_021B8D88(char *p)
{
    if (((struct Obj00002 *)p)->f866 == 0) {
        ((struct Obj00002 *)p)->f864 = 0;
        func_021B6100(p, (int)(*(Callback *)&((struct Obj00002 *)p)->f868));
    } else {
        ((struct Obj00002 *)p)->f866 -= 1;
    }
}

/*
 * Return-observed exception: 02035C08's legacy definition says void,
 * but the original retains its r0 result in r4 and returns it.
 */
int func_021B8DAC(void)
{
    int result;
    result = func_02035C08(d_021BB978);
    if (result != -1)
        func_020355D8(1);
    return result;
}

void func_021B8DCC(char *p)
{
    int flag;
    func_021B7DD0((unsigned char *)p);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4((int)p, 1);
    flag = 1;
    if (func_020355C4())
        flag = 0;
    func_021B80C4((struct Obj *)p, flag);
    func_021B8AF4(p);
}


void func_021B8E08(unsigned char *p)
{
    int f;
    func_021B7DD0(p);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4((int)p, 1);
    f = 1;
    if (func_020355C4()) {
        f = 0;
    }
    func_021B80C4((struct Obj *)p, f);
    func_021B6100((char *)p, (int)func_021B7CD0);
}

void func_021B8E48(char *p)
{
    *(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854 = func_02021518(((struct Obj04331 *)p)->f544);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 2, 0x200, ((struct Obj04331 *)p)->f544);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 0, 0x20, ((struct Obj04331 *)p)->f544);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 0, 0, 0x20);
}
