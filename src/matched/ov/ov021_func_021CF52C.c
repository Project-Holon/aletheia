/*
 * function: func_021CF52C
 * address:  0x021CF52C
 * packet:   pkt_ov021_021CF52C
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

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern char d_021DE5FC[];

void func_021CF52C(u8 *p, u32 size, u32 heap)
{
    *(void **)(p + 0x1c) = func_02030734(heap, size, 1, d_021DE5FC, 0xe3);
}
