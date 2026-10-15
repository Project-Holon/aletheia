/*
 * function: DIGITALCARDCHECK_Phase1
 * address: 0x0217D4FC
 * packet: pkt_ov176_0217D4FC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DIGITALCARDCHECK_InitRecord 0x0217DC28 thumb ov176
 *   LIVEBATTLEMATCH_IRC_ShowMenu 0x0217DEA4 thumb ov176
 *   DIGITALCARDCHECK_IsInitRecordDone 0x0217DE8C thumb ov176
 *   KEY_GetTrg 0x020362DC arm
 *   LIVEBATTLEMATCH_IRC_DeleteMenuRecord 0x0217E000 thumb ov176
 *   LIVEBATTLEMATCH_IRC_ToggleSe 0x0217DFF0 thumb ov176
 *   LIVEBATTLEMATCH_IRC_SetMenuValue 0x0217DFD0 thumb ov176
 *   LIVEBATTLEMATCH_IRC_GetMenuValue 0x0217DFE4 thumb ov176
 *   LIVEBATTLEMATCH_IRC_CreateWindow 0x0217DEDC thumb ov176
 *   LIVEBATTLEMATCH_IRC_GetWindowResult 0x0217DFBC thumb ov176
 *   LIVEBATTLEMATCH_IRC_DeleteWindow 0x0217DFA8 thumb ov176
 *   DIGITALCARDCHECK_IsInitWorkDone 0x0217DE98 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   DIGITALCARDCHECK_EndPhase 0x0217DC20 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 */
typedef unsigned int u32;
extern void DIGITALCARDCHECK_InitRecord(int *);
extern void LIVEBATTLEMATCH_IRC_ShowMenu(int *, int);
extern int DIGITALCARDCHECK_IsInitRecordDone(int *);
typedef signed int     s32;
typedef unsigned char  u8;
struct Big;
struct Rec160;
struct Reg2;
extern u32 KEY_GetTrg(void);
extern void LIVEBATTLEMATCH_IRC_DeleteMenuRecord(int *);
extern int LIVEBATTLEMATCH_IRC_ToggleSe(int, int);
extern void LIVEBATTLEMATCH_IRC_SetMenuValue(int *, int, int);
extern int LIVEBATTLEMATCH_IRC_GetMenuValue(int *);
extern void LIVEBATTLEMATCH_IRC_CreateWindow(char *, int);
extern int LIVEBATTLEMATCH_IRC_GetWindowResult(int *);
extern void LIVEBATTLEMATCH_IRC_DeleteWindow(int *);
extern int DIGITALCARDCHECK_IsInitWorkDone(int *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *, int);
extern void DIGITALCARDCHECK_EndPhase(int a);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32, u32);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_COMPETITION_GetFromSave(void *);
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);
extern void *BATTLE_BOX_GetFromSave(void *);
struct Obj;
extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern int GAME_DATA_SaveStart(int a0);
extern int GAME_DATA_SaveMain(u8 *p);
void DIGITALCARDCHECK_Phase1(int *a, int *state, int *p)
{
    int result;
    void *base, *record;
    switch (*state) {
    case 0: DIGITALCARDCHECK_InitRecord(p); LIVEBATTLEMATCH_IRC_ShowMenu(p, 1); *state = 1; break;
    case 1: if (DIGITALCARDCHECK_IsInitRecordDone(p)) *state = 2; break;
    case 2: if (KEY_GetTrg() & 3) *state = 3; break;
    case 3:
        LIVEBATTLEMATCH_IRC_DeleteMenuRecord(p); LIVEBATTLEMATCH_IRC_ToggleSe((int)p, 1); LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x67, 1);
        *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 4); break;
    case 4: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 2); *state = 5; break;
    case 5:
        result = LIVEBATTLEMATCH_IRC_GetWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x71, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 7); break;
    case 7: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 0); *state = 8; break;
    case 8:
        result = LIVEBATTLEMATCH_IRC_GetWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x72, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 10); break;
    case 10: LIVEBATTLEMATCH_IRC_CreateWindow((char *)p, 0); *state = 11; break;
    case 11:
        result = LIVEBATTLEMATCH_IRC_GetWindowResult(p);
        if (result != -1) { LIVEBATTLEMATCH_IRC_DeleteWindow(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6B, 2); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 13); break;
    case 13:
        base = GAME_DATA_GetSaveControl((void *)p[12]);
        record = REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(base), p[5]);
        base = BATTLE_BOX_GetFromSave(base);
        BATTLE_BOX_ClearLockFlags(base, p[5] == 0 ? 1 : 2);
        REGULATION_Card_SetValue(record, 10, 4); *state = 14; break;
    case 14: GAME_DATA_SaveStart((int)((void *)p[12])); *state = 15; break;
    case 15:
        result = GAME_DATA_SaveMain((void *)p[12]);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x73, 1); *state = 19; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 17); break;
    case 17: if (DIGITALCARDCHECK_IsInitWorkDone(p)) *state = 18; break;
    case 18: WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)DIGITALCARDCHECK_EndPhase); break;
    case 19: if (LIVEBATTLEMATCH_IRC_GetMenuValue(p)) WIFIBATTLEMATCH_UTIL_CommitRequest((u32)a); break;
    }
}
