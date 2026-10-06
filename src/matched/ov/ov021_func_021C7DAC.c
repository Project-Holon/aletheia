/*
 * function: func_021C7DAC
 * address:  0x021C7DAC
 * packet:   pkt_ov021_021C7DAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE4FC  0x021DE4FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021C7E58  0x021C7E58  thumb  ov021
 *   func_021C8018  0x021C8018  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021DE4FC[];
extern u32 func_021C8018(u32 heap);
extern void func_021C7E58(u32 a);
M *func_021C7DAC(u32 heap)
{
    M *m = func_02030734(heap, 0x20, 1, d_021DE4FC, 0x7a);
    m->f0 = func_021C8018(heap);
    m->f1C = 0;
    m->f1E = 4;
    func_021C7E58((u32)m->sub);
    return m;
}
