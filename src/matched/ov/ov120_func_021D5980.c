/*
 * function: GTSNEGO_DISP_OnPartySelected
 * address: 0x021D5980
 * packet: pkt_ov120_021D5980
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_CheckPartySelect 0x021D596C thumb ov120
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   GTSNEGO_MSG_ClearRows 0x021D7D3C thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_CreateConfirmUi 0x021D4EC0 thumb ov120
 *   GTSNEGO_DISP_ShowPokemonList 0x021D57B0 thumb ov120
 */
#include "../include/Obj05346.h"
typedef unsigned char u8;
extern int GTSNEGO_DISP_CheckPartySelect(u8 *, int);
typedef unsigned int   u32;
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void GTSNEGO_MSG_ClearRows(char *);
extern void func_02041B6C(u32 bit);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_CreateConfirmUi(u8 *p);
extern void GTSNEGO_DISP_ShowPokemonList(u8 *p);
void GTSNEGO_DISP_OnPartySelected(u8 *p)
{
    int state = GTSNEGO_DISP_CheckPartySelect(p, ((struct Obj05346 *)p)->f15C);
    if (state == 0) {
        GTSNEGO_DISP_SetCursorState(((struct Obj05346 *)p)->f3C, ((struct Obj05346 *)p)->f34, 9);
        GTSNEGO_MSG_ClearRows(*(char * *)&((struct Obj05346 *)p)->f40);
        func_02041B6C(6);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_CreateConfirmUi, 0x8a3);
        return;
    }
    if (state == 1) {
        GTSNEGO_DISP_SetCursorState(((struct Obj05346 *)p)->f3C, ((struct Obj05346 *)p)->f34, 9);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_ShowPokemonList, 0x8a7);
    }
}
