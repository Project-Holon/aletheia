/*
 * file:     unit_021DE980_p01.c
 * unit:     yes
 * function: func_021DE980, func_021DE9B8, func_021DE9D4, func_021DEA1C
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
 */
#include "../../matched/include/Obj07819.h"
#include "../../matched/include/Obj07820.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_0201C1E8(int a);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021E89D4(u32 a);
void func_021DE980(int a,int b,int c);
int *func_021DE9AC(int *p);
void func_021DE9B8(int a,int b,int c);
void func_021DE9D4(int a, void *b, int c);
void func_021DEA1C(int a,void *b,int c);
int *func_021DEA4C(int *p);
extern int d_021F1904;
extern int d_021F16BC;

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
