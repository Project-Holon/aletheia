/*
 * function: FLDEFF_HIDE_CreateResources
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
 *   sFldeffHideFileName     0x021DE618  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   FLDEFF_HIDE_LoadResources  0x021D03C4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct W;
extern void FLDEFF_HIDE_LoadResources(struct W *p);
extern char sFldeffHideFileName[];

void *FLDEFF_HIDE_CreateResources(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0xc, 1, sFldeffHideFileName, 0x6b);

    p[1] = v;
    FLDEFF_HIDE_LoadResources((struct W *)p);
    return p;
}
