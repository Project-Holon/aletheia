/*
 * function: SCRCMD_NETWORK_HasSituationWarpChanged
 * address: 0x0215F630
 * packet: pkt_ov010_0215F630
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MAP_REPLACE_GetDefaultWarpId 0x02159F80 thumb ov010
 *   GAME_DATA_GetSituationWarpId 0x02012914 thumb
 */

extern int MAP_REPLACE_GetDefaultWarpId(void);
typedef unsigned short u16;
struct BigObj;
extern u16 GAME_DATA_GetSituationWarpId(const struct BigObj *p);
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
BOOL SCRCMD_NETWORK_HasSituationWarpChanged(void *p) { int a = MAP_REPLACE_GetDefaultWarpId(); if(a == GAME_DATA_GetSituationWarpId(p)) return FALSE; else return TRUE; }
