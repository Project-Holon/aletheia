/*
 * function: ZUKAN_INFO_ShowPage
 * address: 0x021BA64C
 * packet: pkt_ov206_021BA64C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_INFO_ClearSlotWindows 0x021BAF50 thumb ov206
 *   ZUKAN_INFO_DeleteRow 0x021BB92C thumb ov206
 *   ZUKAN_INFO_ShowFormPair 0x021BB4E0 thumb ov206
 *   ZUKAN_INFO_SetDrawEnable 0x021BBDA8 thumb ov206
 *   ZUKAN_INFO_DrawMainPage 0x021BAA4C thumb ov206
 *   ZUKAN_INFO_DrawPage 0x021BACB0 thumb ov206
 */
#include "../include/Obj00031.h"
extern void ZUKAN_INFO_ClearSlotWindows(char *);
extern void ZUKAN_INFO_DeleteRow(char *,int);
extern void ZUKAN_INFO_ShowFormPair(char *,int,int);
struct State;
extern void ZUKAN_INFO_SetDrawEnable(struct State *p, int v);
extern void ZUKAN_INFO_DrawMainPage(char *);
extern void ZUKAN_INFO_DrawPage(char *,int);
void ZUKAN_INFO_ShowPage(char *p,int mode)
{
    if (((struct Obj00031 *)p)->fE0) ((struct Obj00031 *)p)->fE0=0;
    else ((struct Obj00031 *)p)->fE0=1;
    ZUKAN_INFO_ClearSlotWindows(p);
    ZUKAN_INFO_DeleteRow(p,((struct Obj00031 *)p)->fE0);
    ZUKAN_INFO_ShowFormPair(p,mode,((struct Obj00031 *)p)->fE0);
    ZUKAN_INFO_SetDrawEnable((struct State *)p,((struct Obj00031 *)p)->f8);
    if(mode==6 || ((struct Obj00031 *)p)->fC>493) ZUKAN_INFO_DrawMainPage(p);
    else ZUKAN_INFO_DrawPage(p,mode);
}
