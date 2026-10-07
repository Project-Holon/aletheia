/*
 * file:     guru2_main_p08.c
 * unit:     yes
 * function: func_021DED88, func_021DEDAC, func_021DEE4C, func_021DEED8
 * address:  0x021DED88
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E1974 0x021E1974 thumb ov137
 *   func_021E1954 0x021E1954 thumb ov137
 *   d_021E1FA0 0x021E1FA0 data a2
 *   func_021E16AC 0x021E16AC thumb ov137
 *   func_021E1768 0x021E1768 thumb ov137
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 *   func_021DEF6C 0x021DEF6C thumb ov137
 *   func_021E0304 0x021E0304 thumb ov137
 *   func_021E16C0 0x021E16C0 thumb ov137
 *   func_021E0C08 0x021E0C08 thumb ov137
 *   d_021E1FDC 0x021E1FDC data a2
 */
#include "../../matched/include/Obj06536.h"
#include "../../matched/include/Obj02869.h"
#include "../../matched/include/Obj08215.h"
#include "../../matched/include/Obj23748.h"
#include "../../matched/include/Obj23749.h"
#include "../../matched/include/Obj06537.h"
#include "../../matched/include/Obj14222.h"

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { u8 pad[0x90]; void *slots[5]; void *other[5]; } Obj;

extern int func_021E1974(char *);
extern int func_021E1954(char *);
extern u8 *func_021E16AC(void *, int);
extern int func_021E1768(char *, int);
extern void *func_021DEB10(char *p);
extern char *func_02184180(unsigned char *p, int i);
extern void func_02008500(void *, void *);
extern void func_021DEF6C(void *);
extern void func_02005D90(int, int);
extern void func_021E0304(u8 *p);
extern char *func_021E16C0(char *p);
extern void func_021E0C08(char *,int,int,int,int,int,int *);
int func_021DED88(char *p);
int func_021DEDAC(Obj *obj);
int func_021DEE4C(char *p);
int func_021DEED8(char *p);
extern const u16 d_021E1FA0[][5];
extern const u16 d_021E1FDC[][5];

int func_021DED88(char *p) {if(func_021E1974(p)==1)((struct Obj06536 *)p)->f0=45;else if(((struct Obj06536 *)p)->f30==func_021E1954(p))((struct Obj06536 *)p)->f0=16;return 0;}

int func_021DEDAC(Obj *obj)
{
    u8 *p = (u8 *)obj;
    u8 *q;
    int i, count;
    q = func_021E16AC(p, 24);
    ((struct Obj08215 *)q)->f10 = ((struct Obj02869 *)p)->f2C;
    count = ((struct Obj02869 *)p)->f30;
    ((struct Obj08215 *)q)->f14 = count;
    ((struct Obj08215 *)q)->f4 = d_021E1FA0[count][((struct Obj02869 *)p)->f2C];
    for (i = 0; i < 5; i++) {
        if (func_021E1768((char *)p, i)) {
            obj->slots[i] = func_02184180(func_021DEB10((char *)p), (u8)i);
            func_02008500(obj->slots[i], obj->other[i]);
        }
    }
    func_021DEF6C(p);
    ((struct Obj02869 *)p)->f120 = ((struct Obj08215 *)q)->f4 << 12;
    ((struct Obj02869 *)p)->f0 = 17;
    func_02005D90(1157, 65535);
    ((struct Obj23749 *)(*(u8 * *)&((struct Obj23748 *)(*(u8 * *)&((struct Obj02869 *)p)->fD8))->f14))->f14 = 1;
    func_021E0304(p);
    return 1;
}

/*
 * extent: unlabelled follower at 021DEED8, filed separately.
 * lever: raw unsigned byte-table address and a named row byte offset restore r6.
 */
int func_021DEE4C(char *p)
{
    int *r;
    int value, a, row;
    if (--((struct Obj06537 *)p)->fC>0) return 0;
    ((struct Obj06537 *)p)->fC=15;
    r=(int *)func_021E16C0(p);
    row=r[5]*10;
    value=*(const u16 *)((unsigned)d_021E1FDC+row+r[4]*2);
    a=*(u16 *)(p+0x7e + r[4]*4);
    *(u16 *)(p+0x60+r[4]*2)=value;
    func_021E0C08(p,a,r[4],r[0],value,r[1],(int *)(p+0x2e0+r[4]*0xb4));
    r[4]++;
    r[4]%=r[5];
    if (++r[0]==r[5]) {
        ((struct Obj06537 *)p)->fC=0;
        ((struct Obj06537 *)p)->f0=18;
    }
    return 0;
}

int func_021DEED8(char *p)
{
    char *q=p+0x1a0;
    int i,n,count;
    count=((struct Obj14222 *)p)->f30;
    i=0;
    n=0;
    do {
        if (*(int *)(q+i*0xb4+0x148)==1) n++;
        i++;
    } while(i<count);
    if (n==count) {((struct Obj14222 *)p)->f0=19;return 1;}
    return 0;
}
