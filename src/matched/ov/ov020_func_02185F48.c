/*
 * function: EVENT_MAPCHANGE_ResetPlayerObjectCode
 * address: 0x02185F48
 * packet: pkt_ov020_02185F48
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerObjectCode 0x02012B28 thumb
 *   GAME_DATA_SetPlayerObjectCode 0x02012B2C thumb
 */
typedef unsigned int   u32;
struct Rec44;
struct SaveBlock;
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);
extern void GAME_DATA_SetPlayerObjectCode(struct Rec44 *p, u32 v);
void EVENT_MAPCHANGE_ResetPlayerObjectCode(void *p) { void *q; q=GAME_DATA_GetMyPlayerWork(p); if (GAME_DATA_GetPlayerObjectCode(q)!=3) GAME_DATA_SetPlayerObjectCode(q,0); else GAME_DATA_SetPlayerObjectCode(q,2); }
