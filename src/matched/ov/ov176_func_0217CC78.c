/*
 * function: LIVEBATTLEMATCH_FLOW_Sub
 * address: 0x0217CC78
 * packet: pkt_ov176_0217CC78
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 0200AE14 leaves supplied pointer in r0 despite its void own declaration.
 * symbols:
 *   DIGITALCARDCHECK_WaitRecord 0x0217D160 thumb ov176
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   func_0200E918 0x0200E918 thumb
 *   REGULATION_GetRuleValue 0x0200AE54 thumb
 *   DIGITALCARDCHECK_UpdateMenu 0x0217CFE8 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   DIGITALCARDCHECK_SetRecordMode 0x0217D1A0 thumb ov176
 *   LIVEBATTLEMATCH_FLOW_DrawMenu 0x0217CEAC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_GetWindowResult 0x0217CFDC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_HideWindow 0x0217CFD0 thumb ov176
 *   DIGITALCARDCHECK_IsWorkDone 0x0217D194 thumb ov176
 *   DIGITALCARDCHECK_DeleteRecord 0x0217D174 thumb ov176
 *   BATTLE_REC_IsVersionSupported 0x0200BA38 thumb
 *   DIGITALCARDCHECK_End 0x0217D010 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_Battle 0x0217C2EC thumb ov176
 *   DIGITALCARDCHECK_GetMenuResult 0x0217D000 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 */
#include "../include/Obj00053.h"
#include "../include/Obj24416.h"
#include "../include/Obj24417.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void DIGITALCARDCHECK_WaitRecord(int *);
typedef signed int     s32;
typedef unsigned short u16;
struct Big;
struct Obj;
struct Reg;
struct Reg2;
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern void *REGULATION_NoOp(void *);
extern u8 func_0200E918(const u8 *, u32);
extern u32 REGULATION_GetRuleValue(struct Reg *p, u32 id);
extern void DIGITALCARDCHECK_UpdateMenu(void *, int, int);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32, u32);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *);
extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);
extern int GAME_DATA_SaveStart(int a0);
extern int GAME_DATA_SaveMain(u8 *p);
extern void DIGITALCARDCHECK_SetRecordMode(u8 *, int);
extern void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *, int);
extern int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *);
extern void LIVEBATTLEMATCH_FLOW_HideWindow(int *);
extern int DIGITALCARDCHECK_IsWorkDone(int *);
extern void DIGITALCARDCHECK_DeleteRecord(int *);
extern u32 BATTLE_REC_IsVersionSupported(u32 v);
extern void DIGITALCARDCHECK_End(u8 *, int);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *, int);
extern void LIVEBATTLEMATCH_FLOW_Battle(int *sys, u32 *state, u8 *p);
extern int DIGITALCARDCHECK_GetMenuResult(u8 *);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
void LIVEBATTLEMATCH_FLOW_Sub(int *a, int *state, u8 *p)
{
    void *record;
    u32 value;
    int result;
    switch (*state) {
    case 0:
        DIGITALCARDCHECK_WaitRecord((int *)p);
        if (REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38, 10) == 3) *state = 6;
        else *state = 1;
        break;
    case 1:
        record = REGULATION_NoOp(((struct Obj00053 *)p)->f38);
        value = func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34, 0);
        if (value >= REGULATION_GetRuleValue(record, 0x16)) *state = 2;
        else *state = 16;
        break;
    case 2: DIGITALCARDCHECK_UpdateMenu(p, 10, 2); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 3); break;
    case 3:
        REGULATION_Card_SetValue(((struct Obj00053 *)p)->f38, 10, 3);
        BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8)), 2);
        GAME_DATA_SaveStart((int)(((struct Obj00053 *)p)->f1B8)); *state = 4; break;
    case 4:
        switch (GAME_DATA_SaveMain(((struct Obj00053 *)p)->f1B8)) {
        case 0: case 1: break;
        case 2: case 3: *state = 5; break;
        }
        break;
    case 5: DIGITALCARDCHECK_SetRecordMode(p, 1); DIGITALCARDCHECK_UpdateMenu(p, 25, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 6); break;
    case 6: DIGITALCARDCHECK_UpdateMenu(p, 29, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 7); break;
    case 7: LIVEBATTLEMATCH_FLOW_DrawMenu(p, 2); *state = 8; break;
    case 8:
        result = LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if (result != -1) {
            LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);
            if (((struct Obj00053 *)p)->f1D0 && ((struct Obj24416 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC == 0) {
                switch (result) { case 0: *state = 11; break; case 1: *state = 9; break; }
            } else if (result == 0) *state = 9;
        }
        break;
    case 9: DIGITALCARDCHECK_UpdateMenu(p, 31, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 10); break;
    case 10: if (DIGITALCARDCHECK_IsWorkDone((int *)p)) { DIGITALCARDCHECK_DeleteRecord((int *)p); *state = 15; } break;
    case 11:
        if (BATTLE_REC_IsVersionSupported((u8)(((struct Obj24417 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C0))->f44))) *state = 12;
        else *state = 13;
        break;
    case 12: DIGITALCARDCHECK_UpdateMenu(p, 16, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 14); break;
    case 13: DIGITALCARDCHECK_UpdateMenu(p, 34, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((u32)a, 6); break;
    case 14: DIGITALCARDCHECK_End(p, 4); break;
    case 15: DIGITALCARDCHECK_End(p, 1); break;
    case 16: WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)LIVEBATTLEMATCH_FLOW_Battle); break;
    case 17: if (DIGITALCARDCHECK_GetMenuResult(p)) WIFIBATTLEMATCH_UTIL_CommitRequest((u32)a); break;
    }
}
