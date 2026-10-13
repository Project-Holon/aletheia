/*
 * function: HAND_ITEM_DisablePokeFactors
 * address: 0x021DCFA4
 * packet: pkt_ov093_021DCFA4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_DisablePokeFactors 0x021D7404 thumb ov093
 */
typedef unsigned char u8;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_DisablePokeFactors(unsigned int,int);
void HAND_ITEM_DisablePokeFactors(void *p) { BTL_EVENT_DisablePokeFactors(BTL_POKEPARAM_GetPokeId(p),5); }
