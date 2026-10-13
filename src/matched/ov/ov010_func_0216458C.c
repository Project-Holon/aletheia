/*
 * function: EVENTDATA_SYSTEM_CheckNormalFieldZone
 * address: 0x0216458C
 * packet: pkt_ov010_0216458C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 2-byte zero alignment padding at 0x0216459A.
 * symbols:
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   func_02013E04 0x02013E04 thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 func_02013E04(u32 id);
int EVENTDATA_SYSTEM_CheckNormalFieldZone(void *a, void *b, void *c) { return func_02013E04(GAME_DATA_GetPlayerZoneId(c)); }
