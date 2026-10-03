/*
 * function: func_0219D488
 * address:  0x0219D488
 * packet:   pkt_ov021_0219D488
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D528  0x0216D528  thumb  ov010
 *   func_0219D4EC  0x0219D4EC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D528(u32);
extern void func_0219D4EC(u8 *s);
extern void func_020307B0(void *p);

void func_0219D488(u32 a)
{
    void *s = func_0216D528(a);
    func_0219D4EC(s);
    func_020307B0(s);
}
