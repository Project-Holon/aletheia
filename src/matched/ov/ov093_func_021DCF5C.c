/*
 * function: BTL_HANDLER_ITEM_AddHeldItemFactor
 * address: 0x021DCF5C
 * packet: pkt_ov093_021DCF5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 021D5B40's u16 field result is kept as a full register value
 * until the explicit halfword truncation at 021DCF68/021DCF6C; the caller
 * therefore uses a wide result and a u16 021DCEC4 argument, as the listing shows.
 * symbols:
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_HANDLER_ITEM_AddFactor 0x021DCEC4 thumb ov093
 */
typedef unsigned short u16;
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
typedef unsigned int   u32;
extern void *BTL_HANDLER_ITEM_AddFactor(void *a, u32 k);
void *BTL_HANDLER_ITEM_AddHeldItemFactor(void *p) { int k; k=BTL_POKEPARAM_GetItem(p); if(k) return BTL_HANDLER_ITEM_AddFactor(p,(unsigned short)k); return 0; }
