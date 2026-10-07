/*
 * file:     b_plist_main_p05.c
 * unit:     yes
 * function: func_02210EFC, func_02210F04, func_02210F1C, func_02210F4C, func_02210F84, func_02210F98, func_02210FCC, func_02211034, func_022110B8, func_022110D4, func_022110E0
 * address:  0x02210EFC
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202F72C 0x0202F72C thumb
 *   func_022119F8 0x022119F8 thumb ov198
 *   d_02212138 0x02212138 data a4
 */
#include "../../matched/include/Obj25272.h"
#include "../../matched/include/Obj08364.h"
#include "../../matched/include/Obj25273.h"
#include "../../matched/include/Obj25275.h"
#include "../../matched/include/Obj10852.h"
#include "../../matched/include/Obj14569.h"
#include "../../matched/include/Obj25276.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int s32;

extern u32 func_0202F72C(void *,u16,u16);
extern void func_022119F8(u8 *,u32,u32);
int func_02210EFC(char **p);
u32 func_02210F04(u32 a, u32 b);
u32 func_02210F1C(u8 *p);
int func_02210F4C(u8 *p,int i);
int func_02210F84(char **p, unsigned int v);
unsigned func_02210F98(u8 *p, int index);
void func_02210FCC(u8 *p, u32 state);
void func_02211034(u8 *p);
void func_022110A4(u8 *p, int a, int b);
u32 func_022110B8(u8 **p, u32 c);
int func_022110D4(u8 *p, int i);
void func_022110E0(u8 **p, u32 b, u32 c);
extern u8 d_02212138[][6];

int func_02210EFC(char **p) { return ((struct Obj25272 *)(*p))->f18; }


/*
 * Addresses are Black-image addresses.
 */
u32 func_02210F04(u32 a, u32 b)
{
    if (func_02210EFC((char **)a) == 1 && b >= 3) {
        return 1;
    }
    return 0;
}

/*
 * lever: Group the unsigned address sum as base plus row, then column, then offset.
 */
u32 func_02210F1C(u8 *p) { u8 *q;unsigned long i;int row;q=*(u8 * *)&((struct Obj25273 *)p)->f0;i=q[75];if(i==4)return 0;row=(u32)p+q[32]*76;return func_0202F72C(((struct Obj08364 *)q)->f0,*(u16 *)(row+i*8+48),((struct Obj08364 *)q)->f10); }

int func_02210F4C(u8 *p,int i) { u32 v;v=func_022110D4(p,i);if(func_02210EFC((char **)p)==1) {if(v==0 || v==3)return 1;return 0;}else {if(v<(*(u8 **)p)[34])return 1;return 0;} }


int func_02210F84(char **p, unsigned int v)
{
    return v < ((struct Obj25275 *)(*p))->f22;
}

unsigned func_02210F98(u8 *p, int index)
{
    unsigned selected = func_022110D4(p, index);
    u8 *q = *(u8 * *)&((struct Obj10852 *)p)->f0;
    if (q[0x22] != 1) {
        if (selected == q[0x1d] || selected == q[0x1e]) return 1;
        return func_022110B8((u8 **)p, selected);
    }
    return 0;
}

void func_02210FCC(u8 *p, u32 state)
{
    u32 value;
    switch(state) {
    case 0: case 8:
        p[0x2190]=0;
        (*(u8 **)p)[0x4B]=0;
        value=(*(u8 **)p)[0x20];
        break;
    case 1:
        (*(u8 **)p)[0x4B]=0;
        value=p[0x2190];
        break;
    case 3: case 4:
        value=(*(u8 **)p)[0x4B];
        break;
    case 6: value=p[0x2191]; break;
    case 7: value=p[0x2192]; break;
    case 2: case 5: value=0; break;
    }
    func_022119F8(p,state,value);
}

/*
 * Lead 112 bytes includes two pool words; follower 022110A4 is a
 * 20-byte independent push/pop swap leaf. No padding remains.
 */
void func_02211034(u8 *p)
{
    unsigned i;
    if(((struct Obj25276 *)(*(u8 * *)&((struct Obj14569 *)p)->f0))->f18==1) {
        for(i=0;i<6;i++) (p+i)[0x1CC]=d_02212138[(*(u8 **)p)[28]][i];
    } else {
        for(i=0;i<6;i++) (p+i)[0x1CC]=i;
    }
    for(i=0;i<3;i++) (*(u8 * *)&((struct Obj14569 *)p)->f0+i)[72]=255;
    for(i=0;i<2;i++) {
        *(u16 *)(p+i*4+0x249C)=255;
        *(u16 *)(p+i*4+0x249E)=255;
    }
}

void func_022110A4(u8 *p, int a, int b)
{
    u8 *q=p+0x1CC;
    u8 t=q[a];
    q[a]=q[b];
    q[b]=t;
}


u32 func_022110B8(u8 **p, u32 c)
{
    u32 i;

    for (i = 0; i < 3; i++) {
        if (c == *(u8 *)(*p + i + 0x48)) {
            return 1;
        }
    }
    return 0;
}


/*
 * Recursive MATCH unblocker: named callee of the parked ov198 func_0220C8F0
 * (the first statement, `func_022110D4(a0)`, and every later use of the
 * resulting entry pointer).  `(p + i)[0x1cc]` is what keeps the added index in
 * r1 and the 0x1cc constant in r0 (`ldrb r0,[r1,r0]`); the subscript form folds
 * the constant into the pointer add.  The two-byte follower is the listing's
 * alignment word, so the extent runs one word long.
 *
 * Addresses are Black-image addresses.
 */
int func_022110D4(u8 *p, int i)
{
    return (p + i)[0x1cc];
}


void func_022110E0(u8 **p, u32 b, u32 c)
{
    u8 v = func_022110D4((u8 *)p, c);

    *(u8 *)(*p + b + 0x48) = v;
}
