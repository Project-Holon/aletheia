/*
 * function: FLD_VREQ_Create
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
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern char d_021DE6C8[];

void *FLD_VREQ_Create(u32 heap)
{
    u8 *p = func_02030734(heap, 0x38, 1, d_021DE6C8, 0x80);

    MI_CpuFill8(p + 0x2c, 0xff, 8);
    return p;
}
