/*
 * function: func_0219C5FC
 * address:  0x0219C5FC
 * packet:   pkt_ov021_0219C5FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219D0F4  0x0219D0F4  thumb  ov021
 *   func_0219CDAC  0x0219CDAC  thumb  ov021
 *   func_0219D390  0x0219D390  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *func_0216D520(u32);
extern void func_0219D0F4(u8 *);
extern void func_0219CDAC(u8 *);
extern void func_0219D390(u8 *);

void func_0219C5FC(u32 a)
{
    u8 *s = func_0216D520(a);
    if (s != 0) {
        if (*(u32 *)(s + 0x1c) != 0) {
            func_0219D0F4(s);
            func_0219CDAC(s);
        }
        func_0219D390(s);
        s[0] = 0;
    }
}
