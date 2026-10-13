/*
 * function: BTL_HANDLER_ITEM_AddForcedFactor
 * address: 0x021DCF78
 * packet: pkt_ov093_021DCF78
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_HANDLER_ITEM_AddFactor 0x021DCEC4 thumb ov093
 *   BTL_EVENT_EnableFactorSpecialEvent 0x021D70BC thumb ov093
 *   BTL_EVENT_SetFactorWork 0x021D70DC thumb ov093
 */
extern void *BTL_HANDLER_ITEM_AddFactor(void *,unsigned int);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct QR;
extern void BTL_EVENT_EnableFactorSpecialEvent(struct QR *p);
extern void BTL_EVENT_SetFactorWork(u8 *p, int i, u32 v);
void *BTL_HANDLER_ITEM_AddForcedFactor(void *p,unsigned int k) { void *q; if(k) { q=BTL_HANDLER_ITEM_AddFactor(p,k); if(q) { BTL_EVENT_EnableFactorSpecialEvent(q); BTL_EVENT_SetFactorWork(q,6,1); return q; } } return 0; }
