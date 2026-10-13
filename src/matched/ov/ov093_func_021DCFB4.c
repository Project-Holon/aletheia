/*
 * function: HAND_ITEM_EnablePokeFactors
 * address: 0x021DCFB4
 * packet: pkt_ov093_021DCFB4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_EnablePokeFactors 0x021D7438 thumb ov093
 *   HAND_ITEM_AddHeldItemFactor 0x021DCF5C thumb ov093
 */
typedef unsigned char u8;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_EVENT_EnablePokeFactors(int,int);
extern void *HAND_ITEM_AddHeldItemFactor(void *);
void HAND_ITEM_EnablePokeFactors(void *p) { if(!BTL_EVENT_EnablePokeFactors(BTL_POKEPARAM_GetPokeId(p),5)) HAND_ITEM_AddHeldItemFactor(p); }
