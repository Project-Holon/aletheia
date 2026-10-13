/*
 * function: MOVE_POKEMON_SpawnPendingEntries
 * address: 0x0215E580
 * packet: pkt_ov010_0215E580
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MOVE_POKEMON_SAVE_GetBlock 0x0200D418 thumb
 *   MOVE_POKEMON_SAVE_GetEntryState 0x0200D468 thumb
 *   MOVE_POKEMON_SpawnEntry 0x0215E440 thumb ov010
 */
typedef unsigned char u8;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *);
typedef unsigned int   u32;
struct Blk38;
extern u8 MOVE_POKEMON_SAVE_GetEntryState(struct Blk38 *p, u32 i);
extern void MOVE_POKEMON_SpawnEntry(void *,u8);
void MOVE_POKEMON_SpawnPendingEntries(void *a)
{
 int i;
 void *p = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(a));
 for(i=0;i<2;i++) {
  if(MOVE_POKEMON_SAVE_GetEntryState(p,(u8)i)==2) MOVE_POKEMON_SpawnEntry(a,i);
 }
}
