/*
 * file:     unit_02198D3C_p10.c
 * unit:     yes
 * function: func_02199CC8, func_02199CE4, func_02199D00
 * address:  0x02199CC8
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
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_0216D674(void *p, u16 v);
extern void *func_0216D6BC(int a0, int a1, int a2);
extern u32 func_0216D7CC(u32);
extern void *func_0216D6D4(void *p);
int func_02199CC8(u32 a, u32 b, u32 c, u32 d);
int func_02199CE4(u32 a);
int func_02199D00(u32 a, u32 b, u32 c, u32 d);


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02199CC8(u32 a, u32 b, u32 c, u32 d)
{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 1);
func_0216D7CC(a);
return 0;
}


int func_02199CE4(u32 a)
{
    int *p = func_0216D6D4((void *)a);
    if (++*p >= 22) {
        func_0216D7CC(a);
    }
    return 0;
}


int func_02199D00(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 10);
func_0216D7CC(a);
return 1;
}
