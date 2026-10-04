/*
 * function: func_0219EB18
 * address:  0x0219EB18
 * packet:   pkt_ov021_0219EB18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219E968  0x0219E968  thumb  ov021
 *   func_0219EA10  0x0219EA10  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   d_021D84AC     0x021D84AC  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u32 d_021D84AC[];
extern void *func_0219E968(u32 a, u32 size);
extern u16 func_0219EA10(u32 *, int);
extern void func_0216D674(void *p, u16 v);
extern void func_0216DA50(u8 *p);

void func_0219EB18(u32 a, u16 b)
{
    u8 *q = func_0219E968(a, 16);
    *(u16 *)(q + 0xc) = func_0219EA10(d_021D84AC, -1);
    *(u16 *)(q + 0xe) = b;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
}
