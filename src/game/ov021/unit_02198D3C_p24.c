/*
 * file:     unit_02198D3C_p24.c
 * unit:     yes
 * function: func_0219ADB8, func_0219ADC8, func_0219ADEC
 * address:  0x0219ADB8
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
 *   func_0219AD18  0x0219AD18  thumb
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D4D78  0x021D4D78  data  a4
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

typedef signed short   s16;

typedef signed char    s8;

typedef int (*Step)(u32, u8 *);

typedef struct { u8 a; s8 b; u8 c[3]; u8 f; } St;

extern void func_0219AD18(u32 a1, u32 a2, u32 a3, u32 a4);
extern void *func_0216D69C(void *p);
void func_0219ADB8(u32 a1);
void func_0219ADC8(u32 a);
void func_0219ADEC(St *p);
extern Step d_021D4D78[];


/*
 * Calls func_0219AD18(its own argument 1, 0x2, 0x0, 0x25) and returns nothing.
 */
void func_0219ADB8(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x0, 0x25);
}


void func_0219ADC8(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4D78[p[0]](a, p) == 1) {
    }
}


void func_0219ADEC(St *p)
{
    if (p->f == 1) {
        p->b--;
        if (p->b < 0) {
            p->b = 3;
        }
    } else {
        p->b++;
    }
}
