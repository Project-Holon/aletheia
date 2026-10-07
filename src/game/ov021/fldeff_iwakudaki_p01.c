/*
 * file:     fldeff_iwakudaki_p01.c
 * unit:     yes
 * function: func_021ADC6C, func_021ADCB8, func_021ADCDC, func_021ADCF0
 * address:  0x021ADC6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021D9254     0x021D9254  data  a4
 *   d_021DE10C  0x021DE10C  data
 *   func_021ADD38  0x021ADD38  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02047180  0x02047180  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021ADD64  0x021ADD64  thumb  ov021
 *   d_021DE0FC     0x021DE0FC  data  a4
 */
#include "../../matched/include/Obj09607.h"

struct Arg;
struct Q;
typedef unsigned char u8;

typedef struct T { int w[15]; } T;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct P { u32 f0; } P;

typedef signed int     s32;

extern void func_0207ADC4(int *m);
extern void func_021AC1B8(int a, T *t);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021ADD38(struct Q *q);
extern u32 func_020307B0(void *p);
extern unsigned int func_021ABE24(u8 *p);
extern void *func_02046E24(unsigned int a0, unsigned int a1);
extern int func_02047180(unsigned int *p);
extern int func_020056A0(void *fn, void *arg, int z);
extern void func_021ADD64(u32 a, struct Q *q);
void func_021ADC6C(int a, u8 *b);
P *func_021ADCB8(u32 a, int heap);
void func_021ADCDC(u32 a, u8 *p);
void func_021ADCF0(int *p);
extern T d_021D9254;
extern char d_021DE10C[];
extern int d_021DE0FC[];


void func_021ADC6C(int a, u8 *b)
{
    T t = d_021D9254;
    int c = ((struct Obj09607 *)b)->f8;

    if (b[3] == 0) {
        func_0207ADC4(&t.w[6]);
        func_021AC1B8(a, &t);
        func_02047AC8((void *)(*(int *)(c + b[0x1c] * 0x18 + 0x28)), (struct Arg *)(&t));
    }
}


P *func_021ADCB8(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x20, 1, d_021DE10C, 0x67);
    p->f0 = a;
    func_021ADCF0((int *)p);
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021ADCDC(u32 a, u8 *p)
{
    func_021ADD38((struct Q *)p);
    func_020307B0(p);
}


void func_021ADCF0(int *p)
{
    int r7 = func_021ABE24((u8 *)p[0]);
    int i;

    func_02047180((unsigned int *)(p[1] = (int)func_02046E24(r7, 0x4d)));
    p[6] = func_020056A0((void *)func_021ADD64, p, 0);
    for (i = 0; i < 4; i++)
        p[2 + i] = (int)func_02046E24(r7, d_021DE0FC[i]);
}
