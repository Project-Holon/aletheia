/*
 * file:     unit_021D93D8_p04.c
 * unit:     yes
 * function: func_021D97B4, func_021D97EC
 * address:  0x021D97B4
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 */
#include "../../matched/include/Obj10056.h"
#include "../../matched/include/Obj09219.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *,void *);
void func_021C8838(void *p, int a, int b);
void func_021D97B4(void *a,int b,int c);
void func_021D97EC(void *a, void *b, int c);

void func_021D97B4(void *a,int b,int c) { unsigned char *p; int k=2; if(b==func_021D775C(k)) { p=func_021C88A4(a,0x1d,b); ((struct Obj10056 *)p)->f0 |= k<<22; p[4]=c; p[5]=0xff; func_021C88C8(a,p); } }


/*
 * Shape F1's long-bodied sibling: gate on func_021D775C(2), then build the
 * record via func_021C88A4, set flag bit 22, and hand it to func_021C8838
 * and func_021C88C8.
 */
void func_021D97EC(void *a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        u8 *p = func_021C88A4(b, 0x1d, c);
        ((struct Obj09219 *)p)->f0 |= 2 << 22;
        ((struct Obj09219 *)p)->f4 = 0;
        ((struct Obj09219 *)p)->f6 = 1;
        func_021C8838(p + 8, 1, 0x5e);
        func_021C88C8(b, p);
    }
}
