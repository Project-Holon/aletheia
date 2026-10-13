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
 *   func_0200D418 0x0200D418 thumb
 *   func_0200D468 0x0200D468 thumb
 *   MOVE_POKEMON_SpawnEntry 0x0215E440 thumb ov010
 */
typedef unsigned char u8;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200D418(void *);
typedef unsigned int   u32;
struct Blk38;
extern u8 func_0200D468(struct Blk38 *p, u32 i);
extern void MOVE_POKEMON_SpawnEntry(void *,u8);
void MOVE_POKEMON_SpawnPendingEntries(void *a)
{
 int i;
 void *p = func_0200D418(GAME_DATA_GetSaveControl(a));
 for(i=0;i<2;i++) {
  if(func_0200D468(p,(u8)i)==2) MOVE_POKEMON_SpawnEntry(a,i);
 }
}
