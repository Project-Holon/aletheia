#ifndef GAME_OV067_YESNO_MENU_H
#define GAME_OV067_YESNO_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of yesno_menu.c, prototypes copied from their definitions. */

struct PrintSys;
struct Strbuf;

#include "../ov067/yesno_menu_types.h"
#include "../types.h"

YesNoMenu *YESNO_MENU_Create(u16 heapId, u32 textBgLayer, u32 actorPriority, u32 plttSlot, u8 actorPlttSlot, void *actorSys, struct GfFont *font, struct PrintQueue *printer);
void YESNO_MENU_Delete(YesNoMenu *menu);
void YESNO_MENU_Start(YesNoMenu *menu, struct Strbuf *upperText, struct Strbuf *lowerText);
void YESNO_MENU_Close(YesNoMenu *menu);
void YESNO_MENU_Update(YesNoMenu *menu);
int YESNO_MENU_GetAnswer(YesNoMenu *menu);
u8 YESNO_MENU_GetButtonPos(u32 cursorIndex, u32 buttonIndex, u32 axis);
void YESNO_MENU_CopyPalette(int target, u8 slot, void *colors);
/* END mkheaders: generated region */

#endif
