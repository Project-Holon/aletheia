/*
 * file:     ircbattlemenu_p17.c
 * unit:     yes
 * function: func_02198A8C, func_02198AD4, func_02198AE8, func_02198AFC, func_02198B10
 * address:  0x02198A8C
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
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } Vec;

extern void *func_0216D6D4(void *p);
extern void func_0216D8C0(u32, Vec *);
extern u32 func_0216D7CC(u32);
extern u32 *func_0216D548(u32 *p, u32 v);
extern u32 *func_0216D550(u32 *p, u32 v);
int func_02198A8C(u32 a);
int func_02198AD4(u32 a, u32 b, u32 c, u32 d);
int func_02198AE8(u32 a, u32 b, u32 c, u32 d);
int func_02198AFC(u32 a, u32 b, u32 c, u32 d);
int func_02198B10(u32 a, u32 b, u32 c, u32 d);


/*
 * Addresses are Black-image addresses.
 */
int func_02198A8C(u32 a)
{
    int *p;

    p = func_0216D6D4((void *)a);
    p[0] = p[0] + p[1];
    if (p[0] < 0) {
        p[0] = 0;
    }
    {
        Vec v = { 0, 0, 0 };
        v.y = p[0];
        func_0216D8C0(a, &v);
    }
    if (p[0] > 0) {
        return 0;
    }
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
int func_02198AD4(u32 a, u32 b, u32 c, u32 d)
{
func_0216D548((u32 *)a, 4);
func_0216D7CC(a);
return 1;
}


int func_02198AE8(u32 a, u32 b, u32 c, u32 d)
{
func_0216D550((u32 *)a, 4);
func_0216D7CC(a);
return 1;
}


int func_02198AFC(u32 a, u32 b, u32 c, u32 d)
{
func_0216D548((u32 *)a, 8);
func_0216D7CC(a);
return 1;
}


int func_02198B10(u32 a, u32 b, u32 c, u32 d)
{
func_0216D550((u32 *)a, 8);
func_0216D7CC(a);
return 1;
}
