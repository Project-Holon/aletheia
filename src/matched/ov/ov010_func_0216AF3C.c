/*
 * function: SCRCMD_SYMBOL_SendEntryFlag
 * address:  0x0216AF3C
 * packet:   pkt_0216AF3C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unblocked by matching INTRUDE_COMM_SetPendingValue (ov011, EXACT): the +0032 call site now
 * attests as `matched`.
 * 
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 *   INTRUDE_COMM_SetPendingValue  0x0217688C  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *SYMBOL_SAVE_GetBlock(void *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern int GAME_DATA_GetSymbolMapFlag(unsigned char *base);
extern int INTRUDE_COMM_SetPendingValue();

void SCRCMD_SYMBOL_SendEntryFlag(int a0)
{
    int a1;
    int t4;
    int t5;
    void *c;
    void *e;
    void *w;

t5 = a0 + 0;
    c = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216AF44:
a0 = t5 + 0;
    e = SCRCMD_WORK_GetGameData((void *)a0);
loc_0216AF4C:
    w = GAME_DATA_GetSaveControl(e);
loc_0216AF52:
    SYMBOL_SAVE_GetBlock(w);
loc_0216AF56:
    a0 = GAMESYSTEM_GetGameComm(c);
loc_0216AF5C:
    a0 = INTRUDE_COMM_GetWorkIfRunning(a0);
loc_0216AF60:
t4 = a0 + 0;
    if (t4 == 0) goto loc_0216AF72;
loc_0216AF64:
    a0 = GAME_DATA_GetSymbolMapFlag(e);
loc_0216AF6A:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = INTRUDE_COMM_SetPendingValue(a0, a1);
loc_0216AF72:
    return;}
