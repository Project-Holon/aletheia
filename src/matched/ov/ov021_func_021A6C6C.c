/*
 * function: func_021A6C6C
 * address:  0x021A6C6C
 * packet:   pkt_ov021_021A6C6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_02162598  0x02162598  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);
extern u32 func_02188C80(u32 p);
extern u32 func_020120F4();
extern u32 func_02012844();
extern int func_0219E664(u32 o, u32 k, u32 *buf);
extern int func_02162598(u32 a, u32 *b);

int func_021A6C6C(u8 *p, u32 k)
{
    u32 buf[2];
    void *o = func_021A3960(*(void **)(p + 0x14));
    u32 r4;

    func_02188C80(*(u32 *)(p + 0x18));
    func_020120F4();
    r4 = func_02012844();
    func_0219E664(o, k, buf);
    return func_02162598(r4, buf) != 0xFFFF;
}
