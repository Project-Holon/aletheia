/*
 * function: func_0219C680
 * address:  0x0219C680
 * packet:   pkt_ov021_0219C680
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216E2E0  0x0216E2E0  thumb  ov010
 *   func_0216E2AC  0x0216E2AC  thumb  ov010
 *   func_0219CB64  0x0219CB64  thumb  ov021
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D520(void *p);
extern u16 func_0216E2E0(void *p);
extern void func_0216E2AC(u32, int, u8 *);
extern void func_0219CB64(u32, u8 *, u32);

void func_0219C680(u32 a)
{
    u8 buf[28];
    u32 s = func_0216D520((void *)a);
    int n = func_0216E2E0((void *)a);
    int i;
    for (i = 0; i < n; i++) {
        func_0216E2AC(a, i, buf);
        func_0219CB64(s, buf, 0);
    }
}
