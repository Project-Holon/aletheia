/*
 * function: FLDEFF_BUBBLE_CreateRes
 * address:  0x021D0610
 * packet:   pkt_ov021_021D0610
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE664     0x021DE664  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   FLDEFF_BUBBLE_LoadResources  0x021D0648  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct S;
extern void FLDEFF_BUBBLE_LoadResources(struct S *p);
extern char d_021DE664[];

void *FLDEFF_BUBBLE_CreateRes(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0x20, 1, d_021DE664, 0xd5);

    p[0] = v;
    FLDEFF_BUBBLE_LoadResources((struct S *)p);
    return p;
}
