/*
 * function: EVENT_FIELD_PROCLINK_ReturnZukan
 * address: 0x02160DDC
 * packet: pkt_ov010_02160DDC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   GAMESYSTEM_GetIssSystem 0x02012134 thumb
 *   FIELD_SOUND_SYSTEM_RestoreVolume 0x02029DD8 thumb
 */
#include "../include/Obj12324.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern u32 GAMESYSTEM_GetIssSystem(u32 *);
extern int FIELD_SOUND_SYSTEM_RestoreVolume(int,int);
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
BOOL EVENT_FIELD_PROCLINK_ReturnZukan(u32 *a, u8 *b) { u32 s=GAME_DATA_GetBgmInfo(((struct Obj12324 *)b)->f0); FIELD_SOUND_SYSTEM_RestoreVolume(s,GAMESYSTEM_GetIssSystem(*(u32 **)a[6])); if (((struct Obj12324 *)b)->fE==0) return FALSE; else return TRUE; }
