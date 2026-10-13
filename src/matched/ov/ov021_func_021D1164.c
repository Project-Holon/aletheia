/*
 * function: FIELD_SAVEANIME_Create
 * address:  0x021D1164
 * packet:   pkt_ov021_021D1164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE684     0x021DE684  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   FIELD_SAVEANIME_LoadResource  0x021D11F4  thumb  ov021
 *   FIELD_SAVEANIME_CreateWindow  0x021D1264  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_SAVEANIME_LoadResource(u32 *p, u32 b);
extern void FIELD_SAVEANIME_CreateWindow(u8 *p);
extern char d_021DE684[];

void *FIELD_SAVEANIME_Create(u32 heap, u32 v)
{
    u32 *p = func_02030734(heap, 0x1c, 1, d_021DE684, 0x8f);

    p[0] = v;
    FIELD_SAVEANIME_LoadResource(p, heap);
    FIELD_SAVEANIME_CreateWindow((u8 *)p);
    return p;
}
