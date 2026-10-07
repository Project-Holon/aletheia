/*
 * file:     unit_02198D3C_p17.c
 * unit:     yes
 * function: func_0219A5E0, func_0219A604
 * address:  0x0219A5E0
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
 *   d_021D4DE8  0x021D4DE8  data  a4
 *   func_0219B200  0x0219B200  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int (*Step)(u32, u8 *);

extern void *func_0216D69C(void *p);
extern int func_0219B200(int a, int id, int end);
extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
void func_0219A5E0(u32 a);
int func_0219A604(u32 a, u8 *s);
extern Step d_021D4DE8[];


void func_0219A5E0(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4DE8[(s8)p[2]](a, p) == 1) {
    }
}


int func_0219A604(u32 a, u8 *s)
{
    u32 v = func_0219B200(a, 0x26, 9);
    if (v == 9) {
        v = func_0216D5F8((void *)a);
    }
    func_0216D438((char *)a, (u16)((u32)func_02197E7C((u16)v, (u16)0)));
    s[2] = 1;
    return 1;
}
