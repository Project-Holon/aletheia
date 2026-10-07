/*
 * file:     pmsiv_wordwin_p01.c
 * unit:     yes
 * function: func_021BEB78, func_021BEC20, func_021BED84, func_021BEDC4, func_021BEDD0, func_021BEDE0, func_021BEDE4, func_021BEDE8, func_021BEDEC, func_021BEE60, func_021BEF4C, func_021BF08C, func_021BF0C0, func_021BF1C4, func_021BF208, func_021BF338, func_021BF360, func_021BF3A0, func_021BF3D4, func_021BF408, func_021BF444, func_021BF4C4, func_021BF4F8, func_021BF500, func_021BF508, func_021BF53C, func_021BF608, func_021BF680, func_021BF6CC, func_021BF6D4, func_021BF6D8, func_021BF6DC, func_021BF6E4, func_021BF6F0, func_021BF708, func_021BF714, func_021BF71C, func_021BF724, func_021BF72C, func_021BF734
 * address:  0x021BEB78
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C3978 0x021C3978 data a1
 *   func_021BB240 0x021BB240 thumb ov110
 *   func_021BB250 0x021BB250 thumb ov110
 *   func_021BB260 0x021BB260 thumb ov110
 *   func_021BB270 0x021BB270 thumb ov110
 *   func_021BB280 0x021BB280 thumb ov110
 *   func_021B9C90 0x021B9C90 thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_020061E4 0x020061E4 thumb
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 *   d_021C39A8 0x021C39A8 data a1
 *   d_021C3900 0x021C3900 data a1
 *   func_02035C08 0x02035C08 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02035D40 0x02035D40 arm
 *   func_021BACDC 0x021BACDC thumb ov110
 *   func_021BAD14 0x021BAD14 thumb ov110
 *   func_02035CB8 0x02035CB8 arm
 *   func_021BE7F0 0x021BE7F0 thumb ov110
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_020362DC 0x020362DC arm
 *   func_021BAD20 0x021BAD20 thumb ov110
 *   func_021B99C4 0x021B99C4 thumb ov110
 *   func_021BB1E4 0x021BB1E4 thumb ov110
 *   func_021BABF4 0x021BABF4 thumb ov110
 *   func_020245A0 0x020245A0 thumb
 *   func_021BAC0C 0x021BAC0C thumb ov110
 *   func_020245AC 0x020245AC thumb
 *   func_020241E0 0x020241E0 thumb
 *   func_02024464 0x02024464 thumb
 *   func_0202452C  0x0202452C  thumb
 *   func_020244F0 0x020244F0 thumb
 *   func_021B999C 0x021B999C thumb ov110
 *   func_021BB1C0 0x021BB1C0 thumb ov110
 */
#include "../../matched/include/Obj01532.h"
#include "../../matched/include/Obj00296.h"
#include "../../matched/include/Obj02165.h"
#include "../../matched/include/Obj10283.h"
#include "../../matched/include/Obj22381.h"
#include "../../matched/include/Obj22382.h"
#include "../../matched/include/Obj22383.h"
#include "../../matched/include/Obj00012.h"
#include "../../matched/include/Obj01394.h"
#include "../../matched/include/Obj00493.h"
#include "../../matched/include/Obj04449.h"
#include "../../matched/include/Obj01923.h"
#include "../../matched/include/Obj05296.h"
#include "../../matched/include/Obj04450.h"
#include "../../matched/include/Obj04451.h"
#include "../../matched/include/Obj13793.h"
#include "../../matched/include/Obj13795.h"
#include "../../matched/include/Obj22384.h"
#include "../../matched/include/Obj13796.h"
#include "../../matched/include/Obj08007.h"
#include "../../matched/include/Obj22385.h"
#include "../../matched/include/Obj22386.h"
#include "../../matched/include/Obj22387.h"
#include "../../matched/include/Obj22388.h"
#include "../../matched/include/Obj22389.h"
#include "../../matched/include/Obj22390.h"
#include "../../matched/include/Obj22391.h"
#include "../../matched/include/Obj08008.h"

struct Ctx;
struct T245;
struct T241;
struct T;
struct Struct_0202441C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef int (*Handler_021BEE60)(u8 *,void *);

struct Box { u8 b[8]; };

typedef int (*Handler_021BF0C0)(u8 *, void *);

typedef int (*Handler_021BF53C)(u8 *, void *);

extern u8 func_021BB240(u32 i);
extern u8 func_021BB250(u32 i);
extern u8 func_021BB260(u32 i);
extern int func_021BB270(int n);
extern u8 func_021BB280(u32 i);
extern int func_021B9C90(unsigned int a, int b);
extern void func_021B9BEC(u8 *p, int id);
extern int func_021B9C74(unsigned int a);
extern void func_021BD7A0(u8 *,void *);
extern void func_020061E4(u32);
extern int func_021BE4C0(u8 *p, unsigned *q);
extern int func_021BD894(u8 *,void *);
extern int func_02035C08(const void *p);
extern u32 func_02035D20(u32 *, u32 *);
extern u32 func_02035D40(struct Ctx *, u32, u32);
extern int func_021BACDC(u8 *p, int unused, unsigned n);
extern void func_021BAD14(u8 *, u32);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_021BE7F0(void);
extern int func_021BD808(u8 *,void *);
extern u32 func_020362DC(void);
extern unsigned func_021BAD20(u8 *,unsigned);
extern unsigned short func_021B99C4(unsigned int a, unsigned int b, unsigned int c);
extern u16 func_021BB1E4(u32 p, u32 i);
extern int func_021BABF4(u8 *p, int i);
extern void func_020245A0(u8 *p, unsigned i, u16 v);
extern int func_021BAC0C(u8 *p);
extern void func_020245AC(struct T *p, u32 a1);
extern void func_020241E0(struct T *p, u16 *a1, u16 *a2);
extern int func_02024464(struct T *p, u32 a1);
extern int func_0202452C(const u16 *p);
extern u16 func_020244F0(void *,u32);
extern void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId);
extern u32 func_021B999C(u8 *,int);
extern u8 func_021BB1C0(u8 *);
int func_021BEB78(u8 *p);
int func_021BEC20(u8 *p);
void func_021BED84(u8 *p, void *q);
u32 func_021BEDC4(u8 *p);
unsigned func_021BEDD0(u8 *p);
u32 func_021BEDE0(u8 *p);
u16 func_021BEDE4(u8 *p);
u16 func_021BEDE8(u8 *p);
int func_021BEDEC(u8 *p,u32 *q);
void func_021BEE60(u8 *p,u32 *q);
int func_021BEF4C(u8 *p);
int func_021BF08C(u8 *p);
void func_021BF0C0(u8 *p, u32 *q);
void func_021BF1C4(u8 *p,void *q);
int func_021BF208(u8 *p, u32 keys);
int func_021BF338(u8 *p);
u32 func_021BF360(u8 *p);
int func_021BF3A0(u8 *p,u8 *q);
int func_021BF3D4(u8 *p,u8 *q);
int func_021BF408(u8 *p,u8 *q);
int func_021BF444(u8 *p);
int func_021BF4C4(u8 *p,int *q);
void func_021BF4F8(u8 *p, u32 v);
void func_021BF500(u8 *p);
void func_021BF508(u8 *p,int *q);
void func_021BF53C(u8 *p, u32 *q);
void func_021BF608(u8 *p,u32 *q);
int func_021BF680(u8 *p);
void func_021BF6CC(u8 *p, u8 a, u8 b);
u8 *func_021BF6D4(u8 *p);
u32 func_021BF6D8(u8 *p);
u8 func_021BF6DC(u8 *p);
int func_021BF6E4(u8 *p);
u32 func_021BF6F0(u8 *p,u32 i);
void *func_021BF708(u8 *p, u32 heapId);
u16 func_021BF714(u8 *p);
u16 func_021BF71C(u8 *p);
u16 func_021BF724(u8 *p);
u16 func_021BF72C(u8 *p);
u32 func_021BF734(u8 *p);
extern const u8 d_021C3978[][4];
extern const struct Box d_021C39A8;
extern const struct Box d_021C3900[];

int func_021BEB78(u8 *p) {
    u16 v=((struct Obj01532 *)p)->f4C;
    u16 n=v;
    if(v==254) n=12;
    if(v!=254) {
        ((struct Obj01532 *)p)->f4E=v;
        if(((struct Obj01532 *)p)->f38&64) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][0]; return 1; }
        if(((struct Obj01532 *)p)->f38&128) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][1]; return 1; }
        if(((struct Obj01532 *)p)->f38&32) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][2]; return 1; }
        if(((struct Obj01532 *)p)->f38&16) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][3]; return 1; }
    } else {
        ((struct Obj01532 *)p)->f4E=254;
        if(((struct Obj01532 *)p)->f38&64) { ((struct Obj01532 *)p)->f4C=11; return 1; }
        if(((struct Obj01532 *)p)->f38&128) { ((struct Obj01532 *)p)->f4C=2; return 1; }
    }
    return 0;
}

/*
 * lever: repeat the halfword store before a shared return label to retain the cross-jumped branch; descending switch bodies retain the tail layout.
 * abi: full getter bodies at 021BB240/250/260/270/280 read only r0 and return a zero-extended table byte.
 */
int func_021BEC20(u8 *p) {
    int x=((struct Obj00296 *)p)->f4C;
    int y;
    if(x!=254 && x!=252 && x!=253) {
        y=255;
        if(((struct Obj00296 *)p)->f38&64) y=func_021BB240(x);
        else if(((struct Obj00296 *)p)->f38&128) y=func_021BB250(x);
        else if(((struct Obj00296 *)p)->f38&16) y=func_021BB270(x);
        else if(((struct Obj00296 *)p)->f38&32) y=func_021BB260(x);
        if(y!=255) { ((struct Obj00296 *)p)->f4E=((struct Obj00296 *)p)->f4C; ((struct Obj00296 *)p)->f4C=y; return 1; }
    } else if(((struct Obj00296 *)p)->f38&64) {
        if(((struct Obj00296 *)p)->f4E<=26) y=func_021BB280(((struct Obj00296 *)p)->f4E); else y=255;
        if(((struct Obj00296 *)p)->f4C==252) {
            if(y>=20 && y<=23) { ((struct Obj00296 *)p)->f4C=y; goto end64; }
            else { ((struct Obj00296 *)p)->f4C=22; goto end64; }
        } else if(((struct Obj00296 *)p)->f4C==253) {
            if(y==24 || y==25 || y==16) { ((struct Obj00296 *)p)->f4C=y; goto end64; }
            else { ((struct Obj00296 *)p)->f4C=25; goto end64; }
        } else {
            if(y==17 || y==18 || y==26) { ((struct Obj00296 *)p)->f4C=y; goto end64; }
            else { ((struct Obj00296 *)p)->f4C=26; goto end64; }
        }
end64: return 1;
    } else if(((struct Obj00296 *)p)->f38&128) {
        if(((struct Obj00296 *)p)->f4E<=26) y=func_021BB280(((struct Obj00296 *)p)->f4E); else y=255;
        if(((struct Obj00296 *)p)->f4C==252) {
            if(y>=0 && y<=3) { ((struct Obj00296 *)p)->f4C=y; goto end128; }
            else { ((struct Obj00296 *)p)->f4C=2; goto end128; }
        } else if(((struct Obj00296 *)p)->f4C==253) {
            if(y>=4 && y<=6) { ((struct Obj00296 *)p)->f4C=y; goto end128; }
            else { ((struct Obj00296 *)p)->f4C=5; goto end128; }
        } else {
            if(y>=7 && y<=9) { ((struct Obj00296 *)p)->f4C=y; goto end128; }
            else { ((struct Obj00296 *)p)->f4C=8; goto end128; }
        }
end128: return 1;
    } else if(((struct Obj00296 *)p)->f38&32) {
        switch(x) {
        case 254: ((struct Obj00296 *)p)->f4C=253; break;
        case 253: ((struct Obj00296 *)p)->f4C=252; break;
        case 252: ((struct Obj00296 *)p)->f4C=254; break;
        }
        return 1;
    } else if(((struct Obj00296 *)p)->f38&16) {
        switch(x) {
        case 254: ((struct Obj00296 *)p)->f4C=252; break;
        case 253: ((struct Obj00296 *)p)->f4C=254; break;
        case 252: ((struct Obj00296 *)p)->f4C=253; break;
        }
        return 1;
    }
    return 0;
}

void func_021BED84(u8 *p, void *q) {
    ((struct Obj02165 *)p)->f0=0; p[6]=0; p[7]=0;
    ((struct Obj02165 *)p)->f4=func_021BF734(q);
    ((struct Obj02165 *)p)->f8=0;
    ((struct Obj02165 *)p)->fC=0; ((struct Obj02165 *)p)->fE=65535;
    if (((struct Obj02165 *)p)->f4>14) ((struct Obj02165 *)p)->f2=(((struct Obj02165 *)p)->f4-14)/2+(((struct Obj02165 *)p)->f4&1);
    else ((struct Obj02165 *)p)->f2=0;
}


u32 func_021BEDC4(u8 *p) { return p[6] + p[7] * 2; }

unsigned func_021BEDD0(u8 *p) { return ((struct Obj10283 *)p)->f0*2+func_021BEDC4(p); }


u32 func_021BEDE0(u8 *p)
{
    return ((struct Obj22381 *)p)->f8;
}

/*
 * note: unlabelled blocker leaf for func_021BF7AC; ends at filed EDE8.
 */
u16 func_021BEDE4(u8 *p) { return ((struct Obj22382 *)p)->f0; }

u16 func_021BEDE8(u8 *p) { return ((struct Obj22383 *)p)->f2; }

int func_021BEDEC(u8 *p,u32 *q) {
    switch(*q) {
    case 0: func_021BF1C4(p,q); break;
    case 1: if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),20)) *q=0; break;
    case 2: if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),20)) { func_021B9BEC(((struct Obj00012 *)p)->f14,19); *q=0; } break;
    case 3: if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),31)) *q=0; break;
    case 4: if(func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) { func_021BD7A0(p,((struct Obj00012 *)p)->f28); *q=0; } break;
    }
    return 0;
}

void func_021BEE60(u8 *p,u32 *q) {
    switch(func_021BF208(p+0x54,((struct Obj01394 *)p)->f38)) {
    case 1: func_020061E4(1352); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,19); return;
    case 2: func_020061E4(1352); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,20); *q=1; return;
    case 3: func_020061E4(1352); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,20); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,19); *q=2; return;
    }
    if(((struct Obj01394 *)p)->f34&2) {
        func_020061E4(1361); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,13);
        *(Handler_021BEE60 *)&((struct Obj01394 *)p)->f28=(Handler_021BEE60)func_021BE4C0; *q=4; return;
    } else if(((struct Obj01394 *)p)->f34&1) {
        if(((struct Obj01394 *)p)->f60!=0) {
            func_020061E4(1361); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,13);
            *(Handler_021BEE60 *)&((struct Obj01394 *)p)->f28=(Handler_021BEE60)func_021BE4C0; *q=4; return;
        } else {
            func_020061E4(1356); ((struct Obj01394 *)p)->f62=65535;
            func_021BF444(p);
            func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,34); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,14);
            *(Handler_021BEE60 *)&((struct Obj01394 *)p)->f28=func_021BD894; *q=4;
        }
    }
}

/*
 * prototype: BAD14 retains r1 explicitly loaded at EF4C+68/+86 despite its unused input.
 */
int func_021BEF4C(u8 *p)
{
    u32 x, y;
    struct Box box = d_021C39A8;
    int outer, inner, stop;
    u16 index;
    if (func_02035C08(d_021C3900) == 0) {
        func_02035D20(&x, &y);
        switch (func_021BACDC(*(u8 * *)&((struct Obj00493 *)p)->f14, x, y)) {
        case 0:
            p[106] = 1;
            func_020061E4(1352);
            return 0;
        case 1:
            p[106] = 1;
            func_021BAD14(*(u8 * *)&((struct Obj00493 *)p)->f14, y);
            return func_021BF3A0(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84);
        case 2:
            p[106] = 1;
            func_021BAD14(*(u8 * *)&((struct Obj00493 *)p)->f14, y);
            return func_021BF3D4(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84);
        case 3:
            break;
        }
    }
    func_02035D20(&x, &y);
    index = ((struct Obj00493 *)p)->f54 * 2;
    stop = 0;
    for (outer = 0; outer < 6; outer++) {
        box.b[0] = 24 * outer + 13;
        box.b[1] = box.b[0] + 22;
        for (inner = 0; inner < 2; inner++) {
            box.b[2] = 112 * inner + 16;
            box.b[3] = box.b[2] + 102;
            if (func_02035D40((struct Ctx *)&box, x, y) != (u32)-1) {
                ((struct Obj00493 *)p)->f62 = index;
                p[90] = inner;
                p[91] = outer;
                return 5;
            }
            index++;
            if (index >= ((struct Obj00493 *)p)->f58 - 2) {
                stop = 1;
                break;
            }
        }
        if (stop) break;
    }
    return 0;
}

int func_021BF08C(u8 *p) {
 unsigned x,y;
 if(func_02035CB8(&x,&y)==1 && p[0x6a]==1) { func_021BAD14(*(u8 * *)&((struct Obj00493 *)p)->f14,y); return 1; }
 p[0x6a]=0;
 return 0;
}

/*
 * lever: emit case 5 before cases 1/2/3 as in the original jump table.
 */
void func_021BF0C0(u8 *p, u32 *q)
{
    if (!func_021BE7F0()) {
        func_020061E4(1361);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 13);
        *(Handler_021BF0C0 *)&((struct Obj00493 *)p)->f28 = (Handler_021BF0C0)func_021BE4C0;
        *q = 4;
        return;
    }
    if (func_021BF08C(p) == 1) {
        switch (func_021BF408(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84)) {
        case 2:
            func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
            *q = 3;
            break;
        case 3:
            func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
            func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
            *q = 3;
            break;
        }
        return;
    }
    switch (func_021BEF4C(p)) {
    case 0: break;
    case 5:
        func_020061E4(1356);
        func_021BF444(p);
        *(Handler_021BF0C0 *)&((struct Obj00493 *)p)->f28 = func_021BD894;
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 34);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 14);
        *q = 4;
        break;
    case 1:
        func_020061E4(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
        break;
    case 2:
        func_020061E4(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
        *q = 3;
        break;
    case 3:
        func_020061E4(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 20);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
        *q = 2;
        break;
    case 4: break;
    }
}

void func_021BF1C4(u8 *p,void *q) {
    if(func_021BD808(p,q) && *(u32 *)&((struct Obj00012 *)p)->f70==0 && !(func_020362DC()&2)) { func_020061E4(1352); return; }
    if(*(u32 *)&((struct Obj00012 *)p)->f70==0) func_021BEE60(p,q);
    else func_021BF0C0(p,q);
}

int func_021BF208(u8 *p, u32 keys)
{
    u32 r;
    if (keys & 0x80) {
        if (*(u16 *)(p + 0xC) != 0)
            return 4;
        if (p[7] < 5) {
            p[7]++;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            if (r == (u32)*(u16 *)(p + 4) - 2) {
                if (r & 1) {
                    p[6] = 0;
                    return 1;
                }
                p[7]--;
                return 4;
            }
            p[7]--;
            return 4;
        }
        if (*(u16 *)p < *(u16 *)(p + 2)) {
            *(u32 *)(p + 8) = 1;
            *(u16 *)p = *(u16 *)p + 1;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 2;
            p[6] = 0;
            return 3;
        }
        return 4;
    }
    if (keys & 0x40) {
        if (*(u16 *)(p + 0xC) != 0) {
            *(u16 *)(p + 0xC) = 0;
            return 1;
        }
        if (p[7] != 0) {
            p[7]--;
            return 1;
        }
        if (*(u16 *)p != 0) {
            *(int *)(p + 8) = -1;
            *(u16 *)p = *(u16 *)p - 1;
            return 2;
        }
        return 4;
    }
    if (keys & 0x20) {
        if (p[6] == 1) {
            p[6] ^= 1;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            p[6] ^= 1;
        }
        return 4;
    }
    if (keys & 0x10) {
        if (p[6] == 0) {
            p[6] ^= 1;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            p[6] ^= 1;
        }
        return 4;
    }
    if (keys & 0x200)
        return func_021BF338(p);
    if (keys & 0x100)
        return func_021BF360(p);
    return 0;
}

int func_021BF338(u8 *p) {
 if(((struct Obj04449 *)p)->f0!=0) {
  if(((struct Obj04449 *)p)->f0>=6) { ((struct Obj04449 *)p)->f0-=6; ((struct Obj04449 *)p)->f8=-6; }
  else { ((struct Obj04449 *)p)->f8=-((struct Obj04449 *)p)->f0; ((struct Obj04449 *)p)->f0=0; }
  return 2;
 }
 return 4;
}

/*
 * extent: two bytes zero alignment padding at 0x021BF39E.
 */
u32 func_021BF360(u8 *p) {
    if (((struct Obj01923 *)p)->f0<((struct Obj01923 *)p)->f2) {
        if (((struct Obj01923 *)p)->f0+6<=((struct Obj01923 *)p)->f2) { ((struct Obj01923 *)p)->f8=6; ((struct Obj01923 *)p)->f0+=6; }
        else { ((struct Obj01923 *)p)->f8=((struct Obj01923 *)p)->f2-((struct Obj01923 *)p)->f0; ((struct Obj01923 *)p)->f0=((struct Obj01923 *)p)->f2; }
        if((int)func_021BEDD0(p)<((struct Obj01923 *)p)->f4-2) return 2;
        p[6]=0; return 3;
    }
    return 4;
}

int func_021BF3A0(u8 *p,u8 *q) {
 if(((struct Obj05296 *)q)->f0!=0) {
  ((struct Obj05296 *)q)->f0=func_021BAD20(p,((struct Obj05296 *)q)->f2);
  ((struct Obj05296 *)q)->f8=0;
  if((int)func_021BEDD0(q)<((struct Obj05296 *)q)->f4-2) return 2;
  q[6]=0; return 3;
 }
 return 4;
}

int func_021BF3D4(u8 *p,u8 *q) {
 if(((struct Obj04450 *)q)->f0<((struct Obj04450 *)q)->f2) {
  ((struct Obj04450 *)q)->f0=func_021BAD20(p,((struct Obj04450 *)q)->f2);
  ((struct Obj04450 *)q)->f8=0;
  if((int)func_021BEDD0(q)<((struct Obj04450 *)q)->f4-2) return 2;
  q[6]=0; return 3;
 }
 return 4;
}

int func_021BF408(u8 *p,u8 *q) {
 u16 n=((struct Obj04451 *)q)->f0;
 ((struct Obj04451 *)q)->f0=func_021BAD20(p,((struct Obj04451 *)q)->f2);
 ((struct Obj04451 *)q)->f8=0;
 if(n!=((struct Obj04451 *)q)->f0) func_020061E4(0x548);
 if((int)func_021BEDD0(q)<((struct Obj04451 *)q)->f4-2) return 2;
 q[6]=0; return 3;
}

/*
 *   Verified EXACT (blocker-r1.log), 12 bytes:
 *   void func_020245A0(u8 *p,unsigned i,u16 v) {
 *       if(i<2) *(u16 *)(p+4+2*i)=v;
 *   }
 */
int func_021BF444(u8 *p) {
    int i=*(u16 *)(p+98);
    u16 v;
    if(i==65535) i=func_021BEDD0(p+84);
    if(p[105]==0) v=func_021B99C4((unsigned int)(*(void **)(p+24)),*(u16 *)(p+76),i);
    else v=func_021BB1E4((u32)(*(void **)(p+28)),i);
    switch(*(u32 *)(p+4)) {
    case 0: *(u16 *)(p+16)=v; break;
    case 1: *(u16 *)(p+16+2* *(u16 *)(p+74))=v; break;
    case 2: func_020245A0(p+8,func_021BABF4(*(void **)(p+20),*(u16 *)(p+74)),v); break;
    }
    return func_021BF680(p);
}

int func_021BF4C4(u8 *p,int *q) {
 switch(*q) {
 case 0: func_021B9BEC(*(u8 * *)&((struct Obj13793 *)p)->f14,1); ++*q; break;
 case 1: if(func_021B9C74(*(unsigned *)&((struct Obj13793 *)p)->f14)!=0) return 1; break;
 }
 return 0;
}


void func_021BF4F8(u8 *p, u32 v) { ((struct Obj13795 *)p)->f30 = v; ((struct Obj13795 *)p)->f2C = 0; }


void func_021BF500(u8 *p) { ((struct Obj22384 *)p)->f30 = 0; }

void func_021BF508(u8 *p,int *q) {
 switch(*q) {
 case 0: func_021B9BEC(*(u8 * *)&((struct Obj13796 *)p)->f14,2); ++*q; break;
 case 1: if(func_021B9C74(*(unsigned *)&((struct Obj13796 *)p)->f14)!=0) func_021BF500(p); break;
 }
}

void func_021BF53C(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) {
            if (func_021BF680(p)) {
                func_021BF6CC(p + 107, 1, 0);
                ((struct Obj00012 *)p)->f48 = 0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14, 21);
                *q = 1;
            } else *q = 3;
        }
        break;
    case 1:
        switch (func_021BAC0C(((struct Obj00012 *)p)->f14)) {
        case 0:
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14, 23);
            *q = 3;
            break;
        case 1:
            if (((struct Obj00012 *)p)->f4 == 2) func_020245AC((struct T *)(p + 8), 42);
            func_020241E0((struct T *)(*(struct T241 * *)&((struct Obj00012 *)p)->f0), (u16 *)(p + 16), (u16 *)(p + 8));
            func_021BD7A0(p, (Handler_021BF53C)func_021BF4C4);
            *q = 3;
            break;
        }
        break;
    case 2:
        if (((struct Obj00012 *)p)->f34 & 243) *q = 3;
        break;
    case 3:
        if (func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) func_021BF500(p);
        break;
    }
}

void func_021BF608(u8 *p,u32 *q) {
    switch(*q) {
    case 0: func_021BF6CC(p+107,1,1); ((struct Obj00012 *)p)->f48=1; func_021B9BEC(((struct Obj00012 *)p)->f14,21); *q=1; break;
    case 1:
        switch(func_021BAC0C(((struct Obj00012 *)p)->f14)) {
        case 0: func_021B9BEC(((struct Obj00012 *)p)->f14,23); *q=2; break;
        case 1: func_021BD7A0(p,(void (*)(void))func_021BF4C4); *q=2; break;
        }
        break;
    case 2: if(func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) func_021BF500(p); break;
    }
}

int func_021BF680(u8 *p) {
    switch(((struct Obj08007 *)p)->f4) {
    case 0: if(((struct Obj08007 *)p)->f10!=65535) return 1; else return 0;
    case 1: if(((struct Obj08007 *)p)->f10!=65535 && ((struct Obj08007 *)p)->f12!=65535) return 1; else return 0;
    case 2: return func_02024464((struct T *)(p+8),42);
    }
    return 0;
}


void func_021BF6CC(u8 *p, u8 a, u8 b) { p[0] = b; p[1] = a; }


u8 *func_021BF6D4(u8 *p) { return p + 0x70; }


u32 func_021BF6D8(u8 *p) { return ((struct Obj22385 *)p)->f4; }


u8 func_021BF6DC(u8 *p) { return ((struct Obj22386 *)p)->f69; }

/*
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_0202452C          -> unresolved: 0202452C (arm, from name) has no witness outside 021BF6E4..021BF6F0
 */
int func_021BF6E4(u8 *p) { return func_0202452C((const u16 *)(p + 8)); }

u32 func_021BF6F0(u8 *p,u32 i) {
    if(((struct Obj22387 *)p)->f4==2) return func_020244F0(p+8,i);
    return *(u16 *)((u32)p+i*2+0x10);
}

void *func_021BF708(u8 *p, u32 heapId) { return func_0202441C((const struct Struct_0202441C *)(p + 8), heapId); }


u16 func_021BF714(u8 *p) { return ((struct Obj22388 *)p)->f4A; }


u16 func_021BF71C(u8 *p) { return ((struct Obj22389 *)p)->f48; }


u16 func_021BF724(u8 *p) { return ((struct Obj22390 *)p)->f4C; }


u16 func_021BF72C(u8 *p) { return ((struct Obj22391 *)p)->f50; }

u32 func_021BF734(u8 *p) {
    if(p[0x69]==0) return func_021B999C(*(u8 * *)&((struct Obj08008 *)p)->f18,((struct Obj08008 *)p)->f4C)+2;
    else return func_021BB1C0(*(u8 * *)&((struct Obj08008 *)p)->f1C)+2;
}
