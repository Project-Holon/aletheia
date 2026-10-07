/*
 * file:     unit_02198D3C_p13.c
 * unit:     yes
 * function: func_02199F94, func_0219A014, func_0219A028, func_0219A03C, func_0219A058
 * address:  0x02199F94
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
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0219FCC0  0x0219FCC0  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0219FE64  0x0219FE64  thumb  ov021
 *   func_0219FE20  0x0219FE20  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0216D6D4(void *p);
extern int func_0219FCC0(u32, u16 *, u16 *);
extern u16 func_0216D598(void *p);
extern void func_020061E4(u32);
extern void func_0216D7CC(u32);
extern void func_0216D674(void *p, u16 v);
extern void func_0219FE64(u32 a);
extern u32 func_0219FE20(u32, u32, u32, u32);
int func_02199F94(u32 a);
int func_0219A014(u32 a, u32 b, u32 c, u32 d);
int func_0219A028(u32 a, u32 b, u32 c, u32 d);
int func_0219A03C(u32 a, u32 b, u32 c, u32 d);
int func_0219A058(u32 a, u32 b, u32 c, u32 d);


int func_02199F94(u32 a)
{
    u16 *p;
    u16 v[2];
    p = func_0216D6D4((void *)a);
    if (func_0219FCC0(a, &v[1], &v[0]) != 1)
        return 0;
    p[0] = p[0] + 1;
    v[0] = v[0] - 1;
    if (func_0216D598((void *)a) == 0xDD && v[1] == 0 && *((u8 *)p + 2) != v[0]) {
        *((u8 *)p + 2) = v[0];
        switch (v[0]) {
        case 0:
            func_020061E4(0x7E5);
            break;
        case 3:
            func_020061E4(0x7E6);
            break;
        }
    }
    if (p[0] < 0x5F)
        return 0;
    func_0216D7CC(a);
    return 1;
}


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
int func_0219A014(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 10);
func_0216D7CC(a);
return 0;
}


int func_0219A028(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 11);
func_0216D7CC(a);
return 0;
}


int func_0219A03C(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 12);
func_0219FE64(a);
func_0216D7CC(a);
return 0;
}


int func_0219A058(u32 a, u32 b, u32 c, u32 d)
{
if (func_0219FE20(a, b, c, d) == 1) {
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}
return 0;
}
