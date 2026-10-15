/*
 * function: BEACON_DETAIL_GRA_SetNameSlots
 * address: 0x021BCE04
 * packet: pkt_ov216_021BCE04
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_BEACON_ACCESSOR_GetDetailsType 0x02165DAC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetDetailsMonsNo 0x02165DF0 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetDetailsTrainerNo 0x02165DBC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetZoneId 0x02165D28 thumb ov010
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb  arm9
 *   WORDSET_Callback  0x0201EE60  thumb  arm9
 *   WORDSET_SetSlotPokeData  0x0201F104  thumb  arm9
 *   WORDSET_SetSlotFromMsgBE  0x0201F134  thumb  arm9
 *   WORDSET_SetSlotFromMsg59  0x0201F158  thumb  arm9
 */
struct Bits;
extern unsigned GAME_BEACON_ACCESSOR_GetDetailsType(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetDetailsMonsNo(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetZoneId(const struct Bits *);
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern u32 ZONEDATA_GetPlaceNameId(u32 id);
extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);
extern void WORDSET_SetSlotPokeData(struct WordSet *p, u32 i, u32 a);
extern void WORDSET_SetSlotFromMsgBE(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsg59(struct WordSet *p, u32 i, u32 v);
void BEACON_DETAIL_GRA_SetNameSlots(void *p,void *q)
{
    switch(GAME_BEACON_ACCESSOR_GetDetailsType(p)) {
    case 0: case 1:
        WORDSET_Callback(q,0,GAME_BEACON_ACCESSOR_GetDetailsMonsNo(p)); break;
    case 2: {
        unsigned a=GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(p);
        WORDSET_SetSlotPokeData(q,0,a); WORDSET_SetSlotFromMsgBE(q,1,a); break;
    }
    case 3: case 4: break;
    default: {
        unsigned a=GAME_BEACON_ACCESSOR_GetZoneId(p);
        if(a>=427) a=317;
        WORDSET_SetSlotFromMsg59(q,0,ZONEDATA_GetPlaceNameId(a)); break;
    }
    }
}
