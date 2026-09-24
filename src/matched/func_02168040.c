/*
 * function: func_02168040
 * address:  0x02168040
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls func_0217C104 when func_0217C384 returns 3 to 5.
 *
 * symbols:
 *   func_0217C384  0x0217C384  arm  ov009
 *   func_0217C104  0x0217C104  arm  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_02168040(void)
{
    int func_0217C384(void);
    void func_0217C104(void);
    int v = func_0217C384();
    if ((u32)(v - 3) <= 2) func_0217C104();
    return v;
}
