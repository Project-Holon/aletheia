/*
 * function: func_021C94BC
 * address:  0x021C94BC
 * packet:   pkt_ov021_021C94BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE578  0x021DE578  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021C94F4  0x021C94F4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_020307B0(void *p);
extern char d_021DE578[];
extern void func_021C94F4(u32 *q);
u32 *func_021C94BC(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 0x1c, 1, d_021DE578, 0x66);
    q[0] = a;
    func_021C94F4(q);
    return q;
}
