/*
 * function: HAND_TOKUSEI_RemoveAbilityHandlers
 * address: 0x021D8510
 * packet: pkt_ov093_021D8510
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_FindFactor 0x021D732C thumb ov093
 *   BTL_EVENT_RemoveFactor 0x021D7040 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct Node;
extern struct Node *BTL_EVENT_FindFactor(int id, int sub);
extern void BTL_EVENT_RemoveFactor(struct Node *n);
void HAND_TOKUSEI_RemoveAbilityHandlers(void *p) { int n = BTL_POKEPARAM_GetPokeId(p); void *a; while ((a=BTL_EVENT_FindFactor(4,n)) != 0) { BTL_EVENT_RemoveFactor(a); } }
