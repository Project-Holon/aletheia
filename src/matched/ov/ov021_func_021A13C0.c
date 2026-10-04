/*
 * function: func_021A13C0
 * address:  0x021A13C0
 * packet:   pkt_ov021_021A13C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0217394C  0x0217394C  thumb  ov012
 *   func_021F00D4  0x021F00D4  thumb  ov031
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Ctx;
extern void *func_02188C80(void *p);
extern int func_0217394C(const struct Ctx *p);
extern void func_021F00D4(char *p, int mode);

void func_021A13C0(u32 *p, u32 a)
{
    u32 h = (u32)func_02188C80((void *)p[5]);
    if (a == 1 && func_0217394C((const struct Ctx *)h) == 0)
        a = 0;
    func_021F00D4((char *)p[8], a);
}
