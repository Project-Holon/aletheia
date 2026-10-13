/*
 * function: SYMBOL_MAP_ScrCmdGetSyncBlockHeader
 * address:  0x021669C0
 * packet:   pkt_021669C0
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
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SYMBOL_MAP_GetSyncBlockHeader  0x02166834  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetSaveSyncBlock(int base);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int SYMBOL_MAP_GetSyncBlockHeader(int a0, int a1);

int SYMBOL_MAP_ScrCmdGetSyncBlockHeader(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    void *ctx;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_021669CC:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_021669D2:
    ctx = GAMESYSTEM_GetGameData((const struct Ctx *)v1);
loc_021669D6:
    a0 = GAME_DATA_GetSaveSyncBlock((int)ctx);
loc_021669DA:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_021669E4:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_021669EE:
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = SYMBOL_MAP_GetSyncBlockHeader(a0, a1);
loc_021669F8:
*q = a0;
a0 = 0;
    return a0;}
