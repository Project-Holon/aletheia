/*
 * function: SYMBOL_MAP_ScrCmdGetSyncBlockItem
 * address:  0x02166980
 * packet:   pkt_02166980
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 64 compiled 62
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveSyncBlock  0x02012F38  thumb
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SYMBOL_MAP_GetSyncBlockItem  0x02166824  thumb  ov010
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Stream;
extern int GAME_DATA_GetSaveSyncBlock(int base);
extern u16 VM_GetU16(struct Stream *s);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int SYMBOL_MAP_GetSyncBlockItem(int a0, int a1);

int SYMBOL_MAP_ScrCmdGetSyncBlockItem(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    void *p;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216698C:
a0 = t6 + 0;
    p = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_02166992:
    p = GAMESYSTEM_GetGameData((const struct Ctx *)p);
loc_02166996:
    a0 = GAME_DATA_GetSaveSyncBlock((int)p);
loc_0216699A:
t7 = a0 + 0;
a0 = t5 + 0;
    a0 = VM_GetU16((struct Stream *)a0);
loc_021669A2:
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1); /* int-typed on purpose: pointer local changes codegen */
loc_021669AE:
t5 = a0 + 0;
a0 = t7 + 0;
a1 = t4 + 0;
    a0 = SYMBOL_MAP_GetSyncBlockItem(a0, a1);
loc_021669B8:
*(u16 *)&((struct Obj00005 *)((char *)t5))->f0 = a0;
a0 = 0;
    return a0;}
