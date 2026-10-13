/*
 * function: FIELD_RAIL_LOADER_Create
 * address:  0x0219EF44
 * packet:   pkt_ov021_0219EF44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_RAIL_LOADER_InitSetting  0x0219EF14  thumb  ov021
 *   d_021DDE08     0x021DDE08  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern char d_021DDE08[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_RAIL_LOADER_InitSetting(u8 *p);

u8 *FIELD_RAIL_LOADER_Create(u32 heap)
{
    u8 *p = (u8 *)func_02030734((u16)heap, 0x38, 1, d_021DDE08, 0xC0);
    FIELD_RAIL_LOADER_InitSetting(p + 8);
    return p;
}
