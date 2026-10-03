/*
 * function: func_021C8018
 * address:  0x021C8018
 * packet:   pkt_ov021_021C8018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE520  0x021DE520  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02046DB8  0x02046DB8  arm
 *   func_02047400  0x02047400  arm
 *   func_0204767C  0x0204767C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern void func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021DE520[];
extern u32 func_02046DB8(u32 a, u32 b);
extern u32 func_02047400(u32 a, u32 b, u32 c);
extern u32 func_0204767C(u32 a, u32 b, u32 c);
typedef struct { u32 f0; u32 f4; } N;
N *func_021C8018(u32 heap)
{
    N *n = func_02030734(heap, 8, 1, d_021DE520, 0x24);
    n->f0 = func_02046DB8(0x4a, 0);
    n->f4 = func_0204767C(func_02047400(n->f0, 0, 0), 0, 0);
    return n;
}
