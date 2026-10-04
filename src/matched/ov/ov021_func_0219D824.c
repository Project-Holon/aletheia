/*
 * function: func_0219D824
 * address:  0x0219D824
 * packet:   pkt_ov021_0219D824
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0219DA20  0x0219DA20  thumb  ov021
 *   func_0219D9D8  0x0219D9D8  thumb  ov021
 *   func_0216D570  0x0216D570  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D57C(void *p, u32 v);
extern void func_0219DA20(u32);
extern void func_0219D9D8(u32);
extern void func_0216D570(char *p, u32 v);

void func_0219D824(u32 a)
{
    if (func_0216D57C((void *)a, 0x100) != 0) {
        func_0219DA20(a);
    } else if (func_0216D57C((void *)a, 0x40) != 0) {
        func_0219D9D8(a);
    }
    func_0216D570((char *)a, 0x140);
}
