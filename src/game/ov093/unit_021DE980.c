/*
 * file:     unit_021DE980.c
 * unit:     yes
 * function: func_021DE980, func_021DE9B8, func_021DE9D4, func_021DEA1C, func_021DEA58, func_021DEA8C, func_021DEAE8, func_021DEAF4, func_021DEB30, func_021DEB5C
 * address:  0x021DE980
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F1904 0x021F1904 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E89D4  0x021E89D4  thumb  ov093
 *   d_021F16BC 0x021F16BC data a4
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   d_021F191C 0x021F191C data a4
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021DCFD0 0x021DCFD0 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 */
#include "../../matched/include/Obj07819.h"
#include "../../matched/include/Obj07820.h"

struct S;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_0201C1E8(int a);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021E89D4(u32 a);
extern void *func_021C7CF4(int *,int);
extern int func_021D5B48(u8 *p);
extern int func_021D76BC(int,unsigned int);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern int func_021DCFF8(int,int);
extern int func_021DCFD0(int *,unsigned int);
extern void func_021DD044(void *,void *,int);
void func_021DE980(int a,int b,int c);
int *func_021DE9AC(int *p);
void func_021DE9B8(int a,int b,int c);
void func_021DE9D4(int a, void *b, int c);
void func_021DEA1C(int a,void *b,int c);
int *func_021DEA4C(int *p);
void func_021DEA58(int a,int *b,int c,int *p);
void func_021DEA8C(int a, void *b, int c, int *d);
int *func_021DEAE8(int *p);
void func_021DEAF4(int a,int *b,int c,int *p);
void func_021DEB30(int a,int b,int c,int *p);
void func_021DEB5C(int a, void *b, int c);
extern int d_021F1904;
extern int d_021F16BC;
extern int d_021F191C;



void func_021DE980(int a,int b,int c) { if(c==func_021D775C(3)) { if(func_0201C1E8((unsigned short)func_021D775C(18))==2) func_021D7704(53,6144); } }



/*
 * extent: includes store-return follower 0x021DE9AC.
 */
int *func_021DE9AC(int *p) { *p=3; return &d_021F1904; }



/*
 * extent: remaining two bytes are zero alignment padding.
 */
void func_021DE9B8(int a,int b,int c) { if(c==func_021D775C(2)) func_021D7704(53,6144); }




void func_021DE9D4(int a, void *b, int c)
{
    u16 v;
    u8 *r;

    if (c == func_021D775C(3)) {
        v = func_021D775C(0x12);
        if (v != 0xa5) {
            r = (u8 *)func_021C88A4(b, 12, c);
            r[0xf] = c;
            ((struct Obj07819 *)r)->f4 = 0x1b;
            ((struct Obj07819 *)r)->f8 = func_021E89D4(v);
            r[0x10] = 2;
            func_021C88C8(b, r);
        }
    }
}



/*
 * extent: includes store-return follower 0x021DEA4C.
 */
void func_021DEA1C(int a,void *b,int c) { unsigned char *p; if(c==func_021D775C(2)) { p=func_021C88A4(b,11,c); ((struct Obj07820 *)p)->f4=27; p[8]=c; p[20]=1; p[21]=1; func_021C88C8(b,p); } }



int *func_021DEA4C(int *p) { *p=2; return &d_021F16BC; }



/*
 * interface: func_021C7CF4 returns its live r0 here (the matched
 * tail forwarder is declared void); r1 is visibly loaded with c before
 * the call and is retained as an argument, per canonical exceptions.
 */
void func_021DEA58(int a,int *b,int c,int *p) { if(c==func_021D775C(4)) { if(func_021D5B48(func_021C7CF4(b,c))) *p=func_021D76BC(58,3); else *p=0; } }




void func_021DEA8C(int a, void *b, int c, int *d)
{
    u8 *r;

    if (c == func_021D775C(2) && *d != 0) {
        r = (u8 *)func_021C88A4(b, 0x23, c);
        func_021C8838(r + 8, 2, 0x3ef);
        func_021C8860((struct S *)(r + 8), c);
        func_021C8860((struct S *)(r + 8), func_021D70A8((void *)a));
        func_021C88C8(b, r);
        *d = 0;
    }
}


/*
 * lever: int n = (unsigned char)func_021DCFF8(a,2) schedules the
 * narrowing in r0 then r1. An inline call cast costs an extra copy (62 B).
 */
int *func_021DEAE8(int *p)
{
    *p = 3;
    return &d_021F191C;
}


void func_021DEAF4(int a,int *b,int c,int *p) { int n; if(c==func_021D775C(4)) { n=(unsigned char)func_021DCFF8(a,2); if(func_021DCFD0(b,n)) *p=func_021D76BC(58,3); else *p=0; } }


void func_021DEB30(int a,int b,int c,int *p) { if(c==func_021D775C(2)) { if(*p) { func_021DD044((void *)a,(void *)b,c); *p=0; } } }



void func_021DEB5C(int a, void *b, int c)
{
    u8 *r;

    if (c == func_021D775C(2)) {
        r = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(r + 4, 2, 0x3ef);
        func_021C8860((struct S *)(r + 4), c);
        func_021C8860((struct S *)(r + 4), func_021D70A8((void *)a));
        func_021C88C8(b, r);
    }
}
