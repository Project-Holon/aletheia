/*
 * function: func_021D317C
 * address:  0x021D317C
 * packet:   pkt_ov021_021D317C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE6C8     0x021DE6C8  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_02082BCC(void *, unsigned, unsigned);
extern char d_021DE6C8[];

void *func_021D317C(u32 heap)
{
    u8 *p = func_02030734(heap, 0x38, 1, d_021DE6C8, 0x80);

    func_02082BCC(p + 0x2c, 0xff, 8);
    return p;
}
