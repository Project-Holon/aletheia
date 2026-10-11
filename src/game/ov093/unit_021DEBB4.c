/*
 * file:     unit_021DEBB4.c
 * unit:     yes
 * function: func_021DEBB4, func_021DEBEC, func_021DEC44, func_021DEC70
 * address:  0x021DEBB4
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
 *   func_0689C8CC  0x0689C8CC  thumb
 *   d_021F16DC 0x021F16DC data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021DD008 0x021DD008 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   d_021F13BC 0x021F13BC data a4
 *   func_021D679C  0x021D679C  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 */
#include "../../matched/include/Obj13494.h"

struct S;
struct QL;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_021DD008(int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_0689C8CC(u16 v);
extern u16 func_021D679C(u8 *p);
extern u16 func_021D67A8(struct QL *p);
extern int func_021DCFF8(int a, int b);
void func_021DEBB4(int a,int b,int c);
int *func_021DEBE0(int *p);
void func_021DEBEC(int a, void *b, int c);
void func_021DEC44(int a,int b,int c);
int *func_021DEC64(int *p);
void func_021DEC70(int a, void *b, int c);
extern int d_021F16DC;
extern int d_021F13BC;

/*
 * extent: includes store-return follower 0x021DEBE0.
 */
void func_021DEBB4(int a,int b,int c) { if(c==func_021D775C(3)) { if(func_021D775C(56)>3) func_021D7704(53,func_021DD008(a)); } }

int *func_021DEBE0(int *p) { *p=2; return &d_021F16DC; }


void func_021DEBEC(int a, void *b, int c)
{
    void *m;
    u8 *r;

    if (c == func_021D775C(3)) {
        m = func_021C7CF4(b, c);
        r = (u8 *)func_021C88A4(b, 7, c);
        r[6] = c;
        ((struct Obj13494 *)r)->f4 = func_021D7B74(m, 10);
        func_021C8838(r + 12, 2, 0x3f5);
        func_021C8860((struct S *)(r + 12), c);
        func_021C88C8(b, r);
    }
}

/*
 * extent: includes store-return follower 0x021DEC64.
 */
void func_021DEC44(int a,int b,int c) { if(c==func_021D775C(3)) func_021D7704(53,func_021DD008(a)); }

int *func_021DEC64(int *p) { *p=1; return &d_021F13BC; }


void func_021DEC70(int a, void *b, int c)
{
    void *m;
    u16 n;
    u16 v;
    u16 id;
    int t;
    float x;

    if (c == func_021D775C(3)) {
        if (func_0689C8CC(func_021D775C(0x12)) == 0) {
            m = func_021C7CF4(b, c);
            n = (int)func_021D679C(m);
            if (n >= 1) {
                id = func_021D775C(0x12);
                if (id == func_021D67A8(m)) {
                    v = n * func_021DCFF8(a, 2) + 100;
                    if (v > 200)
                        v = 200;
                    if (v != 0)
                        x = 0.5f + (float)(v << 12);
                    else
                        x = (float)(v << 12) - 0.5f;
                    t = (int)x;
                    func_021D7704(0x35, t / 100);
                }
            }
        }
    }
}
