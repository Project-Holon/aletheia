/*
 * function: func_0219D7D0
 * address:  0x0219D7D0
 * packet:   pkt_ov021_0219D7D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0219D8DC  0x0219D8DC  thumb  ov021
 *   func_0216D570  0x0216D570  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D57C(void *p, u32 v);
extern void func_0219D8DC(u32);
extern char *func_0216D570(char *p, u32 v);

void func_0219D7D0(u32 a)
{
    if (func_0216D57C((void *)a, 0x20) != 0) {
        func_0219D8DC(a);
    }
    func_0216D570((char *)a, 0xA0);
}
