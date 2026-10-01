/*
 * function: func_021D0140
 * address:  0x021D0140
 * packet:   pkt_ov021_021D0140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE608     0x021DE608  data  ov021  a4
 *   func_02030734  0x02030734  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern char d_021DE608[];

void *func_021D0140(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0x54, 1, d_021DE608, 0x5f);

    p[0] = v;
    return p;
}
