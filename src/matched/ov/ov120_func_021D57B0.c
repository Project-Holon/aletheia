/*
 * function: GTSNEGO_DISP_ShowPokemonList
 * address: 0x021D57B0
 * packet: pkt_ov120_021D57B0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   GTSNEGO_MSG_ClearRows 0x021D7D3C thumb ov120
 *   GTSNEGO_MSG_InitWindows 0x021D6BB0 thumb ov120
 *   GTSNEGO_MSG_PrintList 0x021D81E0 thumb ov120
 *   GTSNEGO_MSG_PrintListRange 0x021D82A8 thumb ov120
 *   GTSNEGO_MSG_FillListRange 0x021D72A0 thumb ov120
 *   GTSNEGO_MSG_DrawTileRows 0x021D6D10 thumb ov120
 *   GTSNEGO_MSG_CreateTooltip 0x021D7ECC thumb ov120
 *   GTSNEGO_MSG_SetIconY 0x021D733C thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_WaitSelectStart 0x021D5758 thumb ov120
 *   GTSNEGO_DISP_HandleListInput 0x021D5334 thumb ov120
 *   GAME_DATA_GetSaveBlock1F  0x02012F14  thumb  arm9
 */
#include "../include/Obj00532.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *GAME_DATA_GetSaveBlock1F(void **);
typedef unsigned int   u32;
struct Sub02009D9CObj;
extern int func_02009E8C(struct Sub02009D9CObj *obj);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern u8 func_020355C4(void);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void GTSNEGO_MSG_ClearRows(char *p);
extern void GTSNEGO_MSG_InitWindows(u8 *, int);
extern void GTSNEGO_MSG_PrintList(char *, void *);
extern void GTSNEGO_MSG_PrintListRange(char *p, void *q, int start);
extern void GTSNEGO_MSG_FillListRange(u8 *p, void *container, int offset);
extern void GTSNEGO_MSG_DrawTileRows(u8 *p, void *list, int first);
extern void *GTSNEGO_MSG_CreateTooltip(char *, u16);
extern void GTSNEGO_MSG_SetIconY(u8 *p, int index, int count);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_WaitSelectStart(u8 *);
struct Ctx;
extern void GTSNEGO_DISP_HandleListInput(struct Ctx *p);
void GTSNEGO_DISP_ShowPokemonList(u8 *p)
{
    int flag = 1;
    int n = func_02009E8C(GAME_DATA_GetSaveBlock1F(*(void ** *)&((struct Obj00532 *)p)->f2C));
    ((struct Obj00532 *)p)->f138 = flag;
    if (n == 0) {
        GTSNEGO_MSG_PrintWindow(((struct Obj00532 *)p)->f40, 0x1d);
        ((struct Obj00532 *)p)->f14 = 0x78;
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_WaitSelectStart, 0x7e7);
        return;
    }
    ((struct Obj00532 *)p)->f150 = n;
    GTSNEGO_MSG_PrintWindow(((struct Obj00532 *)p)->f40, 0x13);
    if (func_020355C4() == 0)
        GTSNEGO_DISP_SetCursorState(((struct Obj00532 *)p)->f3C, 0, ((struct Obj00532 *)p)->f164);
    else
        GTSNEGO_DISP_SetCursorState(((struct Obj00532 *)p)->f3C, 0, 9);
    GTSNEGO_MSG_ClearRows(((struct Obj00532 *)p)->f40);
    if (n <= 3) flag = 0;
    GTSNEGO_MSG_InitWindows(*(u8 * *)&((struct Obj00532 *)p)->f3C, flag);
    GTSNEGO_MSG_PrintList(*(char * *)&((struct Obj00532 *)p)->f40, ((struct Obj00532 *)p)->f2C);
    GTSNEGO_MSG_PrintListRange(((struct Obj00532 *)p)->f40, ((struct Obj00532 *)p)->f2C, ((struct Obj00532 *)p)->f158 - 2);
    GTSNEGO_MSG_FillListRange(((struct Obj00532 *)p)->f3C, ((struct Obj00532 *)p)->f2C, ((struct Obj00532 *)p)->f158 - 2);
    GTSNEGO_MSG_DrawTileRows(((struct Obj00532 *)p)->f3C, ((struct Obj00532 *)p)->f2C, ((struct Obj00532 *)p)->f158 - 2);
    ((struct Obj00532 *)p)->f34 = GTSNEGO_MSG_CreateTooltip(*(char * *)&((struct Obj00532 *)p)->f40, 0x2c);
    GTSNEGO_MSG_SetIconY(((struct Obj00532 *)p)->f3C, ((struct Obj00532 *)p)->f158 + ((struct Obj00532 *)p)->f164 - 6, ((struct Obj00532 *)p)->f150);
    GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_HandleListInput, 0x815);
}
