/*
 * function: LAND_DATA_PATCH_Create
 * address:  0x021C939C
 * packet:   pkt_ov021_021C939C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE558  0x021DE558  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern char d_021DE558[];
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
u32 *LAND_DATA_PATCH_Create(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 4, 1, d_021DE558, 0x4f);
    q[0] = ARC_UTIL_LoadMember(0x9c, a, 0, heap);
    return q;
}
