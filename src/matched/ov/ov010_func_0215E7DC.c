/*
 * function: MOVE_POKEMON_SetEntryLocation
 * address: 0x0215E7DC
 * packet: pkt_ov010_0215E7DC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MOVE_POKEMON_SAVE_GetEntry 0x0200D4AC thumb
 *   MOVE_POKEMON_SAVE_SetEntryLocation 0x0200D480 thumb
 *   MOVE_POKEMON_SAVE_SetEntryField 0x0200D50C thumb
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Blk38;
struct GdsEnt;
extern struct GdsEnt *MOVE_POKEMON_SAVE_GetEntry(struct Blk38 *p, u32 i);
extern void MOVE_POKEMON_SAVE_SetEntryLocation(struct Blk38 *p, u32 i, u8 v);
extern void MOVE_POKEMON_SAVE_SetEntryField(struct GdsEnt *e, u32 i, u32 v);
void MOVE_POKEMON_SetEntryLocation(void *p,u32 i,u8 v,u32 n)
{
 void *rec = MOVE_POKEMON_SAVE_GetEntry(p,i);
 MOVE_POKEMON_SAVE_SetEntryLocation(p,i,v);
 MOVE_POKEMON_SAVE_SetEntryField(rec,1,n);
}
