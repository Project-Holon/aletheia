/*
 * function: func_0219A604
 * address:  0x0219A604
 * packet:   pkt_ov021_0219A604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
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
extern int func_0219B200(int a, int id, int end);
extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(int a0, int a1);

int func_0219A604(u32 a, u8 *s)
{
    u32 v = func_0219B200(a, 0x26, 9);
    if (v == 9) {
        v = func_0216D5F8((void *)a);
    }
    func_0216D438((u32)a, (u16)((u32)func_02197E7C((u16)v, (u16)0)));
    s[2] = 1;
    return 1;
}
