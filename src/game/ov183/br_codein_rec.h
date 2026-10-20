#ifndef GAME_OV183_BR_CODEIN_REC_H
#define GAME_OV183_BR_CODEIN_REC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_codein_rec.c, prototypes copied from their definitions. */

struct CodeinSoclWork;
struct CodeinMenuArg;
struct BrCodeinRecPair;

void BR_CODEIN_ShowMenuText(struct CodeinSoclWork *menu);
void BR_CODEIN_HideMenuText(struct CodeinSoclWork *menu);
void BR_CODEIN_GetMenuCallbacks(struct BrCodeinRecPair *out);
void BR_CODEIN_CreateMenuButtons(struct CodeinSoclWork *menu,struct CodeinMenuArg *arg);
void BR_CODEIN_DeleteMenuButtons(struct CodeinSoclWork *menu,struct CodeinMenuArg *arg);
int BR_CODEIN_HitTestOptionLeft(struct CodeinSoclWork *menu, int x, int y);
int BR_CODEIN_HitTestOptionRight(struct CodeinSoclWork *menu, int x, int y);
/* END mkheaders: generated region */

#endif
