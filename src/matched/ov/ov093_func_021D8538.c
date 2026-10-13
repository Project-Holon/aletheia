/*
 * function: HAND_TOKUSEI_DisableAbilityHandlers
 * address: 0x021D8538
 * packet: pkt_ov093_021D8538
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
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_DisablePokeFactors(u32 sub, int kind);
void HAND_TOKUSEI_DisableAbilityHandlers(void *p) { BTL_EVENT_DisablePokeFactors(BTL_POKEPARAM_GetPokeId(p),4); }
