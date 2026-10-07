/*
 * file:     unit_0219B508_p13.c
 * unit:     yes
 * function: func_0219C118, func_0219C13C
 * address:  0x0219C118
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
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D5394  0x021D5394  data  a4
 *   func_0216DA50  0x0216DA50  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int (*Step)(u32, u8 *);

extern void *func_0216D69C(void *p);
extern void func_0216DA50(u8 *p);
void func_0219C118(u32 a);
int func_0219C13C(u32 a, u8 *s);
extern Step d_021D5394[];


void func_0219C118(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D5394[p[0]](a, p) == 1) {
    }
}


int func_0219C13C(u32 a, u8 *s)
{
    func_0216DA50((u8 *)a);
    s[0]++;
    return 1;
}
