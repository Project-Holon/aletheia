/*
 * file:     unit_021DDCA4_p03.c
 * unit:     yes
 * function: func_021DDFDC, func_021DE000, func_021DE024, func_021DE058, func_021DE0C0
 * address:  0x021DDFDC
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
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E89D4  0x021E89D4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F160C 0x021F160C data a4
 */
#include "../../matched/include/Obj10067.h"
#include "../../matched/include/Obj21380.h"

struct QQ;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021DDEA4(void *, int, unsigned int);
extern void func_021DD044(void *, void *, int);
extern int func_021DCFF8(int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021E89D4(u32 a);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
void func_021DDFDC(int a, void *b, int c, int d);
void func_021DE000(int a, void *b, int c, int d);
void func_021DE024(int a, void *b, int c, int d);
void func_021DE058(void *a, void *b, int c, u8 *a3);
void func_021DE0C0(void *a, void *b, int c, u8 *d);
void *func_021DE0D0(int *p);
extern u8 d_021F160C[];


/*
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
void func_021DDFDC(int a, void *b, int c, int d)
{
    if (c == func_021D775C(2)) func_021DE024(a, b, c, d);
}


void func_021DE000(int a, void *b, int c, int d)
{
    if (func_021D775C(12) != 6) func_021DDFDC(a, b, c, d);
}


void func_021DE024(int a, void *b, int c, int d)
{
    unsigned char n;
    func_021C7CF4(b, c);
    n = func_021DCFF8(a, 2);
    if (func_021DDEA4(b, c, n) != 0) func_021DD044((void *)a, b, c);
}


void func_021DE058(void *a, void *b, int c, u8 *a3)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        func_021C7CF4(b, c);
        m = (u8 *)func_021C88A4(b, 0xc, c);
        m[0xf] = c;
        ((struct Obj10067 *)m)->f4 = 0x22;
        ((struct Obj10067 *)m)->f8 = func_021E89D4(0x78);
        func_021C8838(m + 0x14, 2, 0x404);
        func_021C8860((struct S *)(m + 0x14), c);
        func_021C8860((struct S *)(m + 0x14), func_021D70A8(a));
        func_021C88C8(b, m);
    }
}

void func_021DE0C0(void *a, void *b, int c, u8 *d) { if (((struct Obj21380 *)d)->f18) func_021DE058(a,b,c,d); }

/*
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 */
void *func_021DE0D0(int *p) { *p=2; return d_021F160C; }
