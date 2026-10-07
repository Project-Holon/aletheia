/*
 * file:     unit_0219B508_p09.c
 * unit:     yes
 * function: func_0219BF54, func_0219BF60
 * address:  0x0219BF54
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
 *   func_0216D69C  0x0216D69C  thumb
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

void *func_0216D69C(void);
extern void *func_0216D684(int a0, int a1, u32 a2, u32 a3);
extern u32 func_0216D5E0(u32, u32);
void func_0219BF54(int a0);
u32 func_0219BF60(u32 a, u32 b, u32 c, u32 a3);


void func_0219BF54(int a0)
{
    char *p = func_0216D69C();

    p[2] = 1;
}


u32 func_0219BF60(u32 a, u32 b, u32 c, u32 a3)
{
    u8 *p = func_0216D684(a, 4, c, a3);
    p[1] = 9;
    p[2] = c;
    return func_0216D5E0(a, 0);
}
