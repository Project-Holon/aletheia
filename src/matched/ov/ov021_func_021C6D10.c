/*
 * function: func_021C6D10
 * address:  0x021C6D10
 * packet:   pkt_ov021_021C6D10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DE4E4     0x021DE4E4  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(int, int, int, void *, int);
extern int d_021DE4E4;

u8 *func_021C6D10(int n, int heap)
{
    u8 *p = (u8 *)func_02030734(heap, 12, 0, &d_021DE4E4, 0x34);

    p[0] = n;
    *(void **)(p + 4) = func_02030734(heap, n * 4, 1, &d_021DE4E4, 0x36);
    *(void **)(p + 8) = func_02030734(heap, n * 4, 1, &d_021DE4E4, 0x37);
    return p;
}
