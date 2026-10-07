/*
 * file:     unit_021D9ADC_p01.c
 * unit:     yes
 * function: func_021D9ADC, func_021D9B40
 * address:  0x021D9ADC
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0878     0x021F0878  data   ov093  a4
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   d_021F0870     0x021F0870  data   ov093  a4
 */
#include "../../matched/include/Obj06251.h"
#include "../../matched/include/Obj10058.h"

struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D85C0(int a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021D76BC(int key, u32 val);
extern int func_021D7B74(u8 *p, u32 k);
void func_021D9ADC(int a, void *b, int c);
int *func_021D9B34(int *p);
void func_021D9B40(int a, void *b, int c);
int *func_021D9B98(int *p);
extern int d_021F0878[];
extern int d_021F0870[];


void func_021D9ADC(int a, void *b, int c)
{
    u8 *p;

    if (c == func_021D775C(2)) {
        if (func_021D62A8(func_021C7CF4(b, c))) {
            if (func_021D85C0((int)b, 0x21)) {
                p = func_021C88A4(b, 0xb, c);
                ((struct Obj06251 *)p)->f0 |= 0x800000;
                ((struct Obj06251 *)p)->f0 |= 0x2000000;
                ((struct Obj06251 *)p)->f4 = 0x24;
                p[8] = c;
                p[0x14] = 1;
                func_021C88C8(b, p);
            }
        }
    }
}


int *func_021D9B34(int *p)
{
    *p = 1;
    return d_021F0878;
}


void func_021D9B40(int a, void *b, int c)
{
    void *q;
    u8 *p;

    if (c == func_021D775C(2) && func_021D775C(0x1d) == 5) {
        q = func_021C7CF4(b, c);
        func_021D76BC(0x32, 0);
        p = func_021C88A4(b, 5, c);
        ((struct Obj10058 *)p)->f4 = func_021D7B74(q, 8);
        p[6] = c;
        ((struct Obj10058 *)p)->f0 |= 0x800000;
        func_021C88C8(b, p);
    }
}


int *func_021D9B98(int *p)
{
    *p = 1;
    return d_021F0870;
}
