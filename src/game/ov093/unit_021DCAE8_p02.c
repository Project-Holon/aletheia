/*
 * file:     unit_021DCAE8_p02.c
 * unit:     yes
 * function: func_021DCC80, func_021DCCEC, func_021DCD20
 * address:  0x021DCC80
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
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B9A5C  0x021B9A5C  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7320  0x021D7320  thumb  ov093
 *   func_021D70AC 0x021D70AC thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_020213C0 0x020213C0 thumb
 *   d_021F0AE8 0x021F0AE8 data a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021B8C5C  0x021B8C5C  thumb  ov093
 *   func_021C8020  0x021C8020  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 */
#include "../../matched/include/Obj10065.h"

struct S;
struct QS;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 h0; u16 pad2; u8 b4; u8 pad5[3]; } Args;

extern unsigned char func_021B9A40(unsigned int x);
extern u8 func_021B9A5C(u32 x);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern void func_021D7320(struct QS *p, u32 v);
extern u8 func_021D70AC(u8 *);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_020213C0(u32 a);
extern int func_021D775C(int key);
extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C815C(int *p);
extern u8 func_021B8C5C(int kind, u32 flags);
extern u8 func_021C8020(u8 *p, u8 v);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B68(void *p);
void func_021DCC80(void *a, void *b, int c, int *d);
int func_021DCCEC(u8 *a,int b,int c,int d,Args e);
int *func_021DCD14(int *p);
void func_021DCD20(int a, void *b, int c);
extern int d_021F0AE8;


void func_021DCC80(void *a, void *b, int c, int *d)
{
    u8 *m;
    u32 x;

    if (*d == 0) {
        x = func_021B9A5C(func_021B9A40(c));
        func_021C88B4(b, 2, c);
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 1, 0xb0);
        func_021C8860((struct S *)(m + 4), x);
        func_021C88C8(b, m);
        func_021C88B4(b, 3, c);
        func_021D7320(a, (u32)((void *)func_021DCCEC));
        *d = 1;
    }
}

/*
 * extent: callback followed by store-and-return leaf at 021DCD14.
 * stack: the by-value record begins in the fifth argument slot; the body
 * reads its halfword at +0 and byte at +4 using a common stack base.
 */
int func_021DCCEC(u8 *a,int b,int c,int d,Args e)
{
    if(c==5) {
        if(!func_021B9A24(func_021D70AC(a),e.b4)) {
            if(func_020213C0(e.h0)) return 1;
        }
    }
    return 0;
}

int *func_021DCD14(int *p) { *p=3; return &d_021F0AE8; }


void func_021DCD20(int a, void *b, int c)
{
    u8 *m;
    void *p;
    int k;
    int n;

    if (c == func_021D775C(2)) {
        n = func_021C8010(b, c);
        k = func_021C8020(b, func_021B8C5C(func_021C815C(b), n));
        p = func_021C7CF4(b, k);
        if (func_021D5B68(func_021C7CF4(b, c)) == 0 && func_021D5B68(p) == 0) {
            m = (u8 *)func_021C88A4(b, 0x33, c);
            ((struct Obj10065 *)m)->f0 |= 2 << 22;
            m[4] = k;
            func_021C8838(m + 8, 2, 0x284);
            func_021C8860((struct S *)(m + 8), c);
            func_021C8860((struct S *)(m + 8), m[4]);
            func_021C88C8(b, m);
        }
    }
}
