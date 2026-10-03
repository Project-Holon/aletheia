/*
 * function: func_021CF45C
 * address:  0x021CF45C
 * packet:   pkt_ov021_021CF45C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE5FC     0x021DE5FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021DE5FC[];

void *func_021CF45C(u32 heap, u32 v)
{
    u32 *p = func_02030734(heap, 0x20, 1, d_021DE5FC, 0x6c);

    p[2] = v;
    p[6] = 0;
    return p;
}
