/*
 * function: func_0216DA44
 * address:  0x0216DA44
 * packet:   pkt_0216DA44
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_0216D568 with a masked second argument.
 *
 * symbols:
 *   func_0216D568  0x0216D568  thumb  ov010

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void func_0216D568(void *p, u32 v);


void func_0216DA44(u32 a)
{
    func_0216D568((void *)a, 0x10);
}

