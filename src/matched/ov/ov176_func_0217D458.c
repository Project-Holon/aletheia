/*
 * function: DIGITALCARDCHECK_SelectPhase
 * address: 0x0217D458
 * packet: pkt_ov176_0217D458
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   DIGITALCARDCHECK_Phase1 0x0217D4FC thumb ov176
 *   DIGITALCARDCHECK_Phase2 0x0217D730 thumb ov176
 *   DIGITALCARDCHECK_Phase3 0x0217D964 thumb ov176
 *   DIGITALCARDCHECK_Phase4 0x0217DA38 thumb ov176
 *   DIGITALCARDCHECK_Phase5 0x0217DB0C thumb ov176
 *   DIGITALCARDCHECK_Phase6 0x0217DBE0 thumb ov176
 */
#include "../include/Obj14366.h"
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_COMPETITION_GetFromSave(void *sys);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec160;
struct Reg2;
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void DIGITALCARDCHECK_Phase1(int *a, int *state, int *p);
extern void DIGITALCARDCHECK_Phase2(int *a, int *state, int *p);
extern void DIGITALCARDCHECK_Phase3(int *a, int *state, int *p);
extern void DIGITALCARDCHECK_Phase4(int sys, int *state, int *p);
extern void DIGITALCARDCHECK_Phase5(int sys, int *state, int *p);
extern void DIGITALCARDCHECK_Phase6(int a, int *state, int *p);
void DIGITALCARDCHECK_SelectPhase(int a, int unused, char *p)
{
    void *m;
    unsigned x;
    unsigned y;
    m = REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj14366 *)p)->f30)), ((struct Obj14366 *)p)->f14);
    x = REGULATION_Card_GetValue(m, 2);
    y = REGULATION_Card_GetValue(m, 10);
    if (x && y == 1) {
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)a, (int)DIGITALCARDCHECK_Phase1);
        return;
    }
    if (x && y == 2) {
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)a, (int)DIGITALCARDCHECK_Phase2);
        return;
    }
    if (x && y == 3) {
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)a, (int)DIGITALCARDCHECK_Phase3);
        return;
    }
    if (x && y == 4) {
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)a, (int)DIGITALCARDCHECK_Phase4);
        return;
    }
    if (x && y == 5) {
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)a, (int)DIGITALCARDCHECK_Phase5);
        return;
    }
    WIFIBATTLEMATCH_UTIL_SetCallback((int *)a, (int)DIGITALCARDCHECK_Phase6);
}
