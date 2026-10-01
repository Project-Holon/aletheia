/*
 * function: func_021D038C
 * address:  0x021D038C
 * packet:   pkt_ov021_021D038C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE618     0x021DE618  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_021D03C4  0x021D03C4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_021D03C4(void *p);
extern char d_021DE618[];

void *func_021D038C(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0xc, 1, d_021DE618, 0x6b);

    p[1] = v;
    func_021D03C4(p);
    return p;
}
