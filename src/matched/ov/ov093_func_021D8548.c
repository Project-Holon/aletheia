/*
 * function: HAND_TOKUSEI_EnableAbilityHandlers
 * address: 0x021D8548
 * packet: pkt_ov093_021D8548
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_EnablePokeFactors 0x021D7438 thumb ov093
 *   HAND_TOKUSEI_AddAbilityHandlers 0x021D8484 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_EVENT_EnablePokeFactors(int,int);
extern void *HAND_TOKUSEI_AddAbilityHandlers(void *);
void HAND_TOKUSEI_EnableAbilityHandlers(void *p) { if (!BTL_EVENT_EnablePokeFactors(BTL_POKEPARAM_GetPokeId(p),4)) HAND_TOKUSEI_AddAbilityHandlers(p); }
