#ifndef GAME_OV016_SCENESETLIST_H
#define GAME_OV016_SCENESETLIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scenesetlist.c, prototypes copied from their definitions. */

void DWCi_SceneSetList(void);
void pushWinButton(int focus);
void drawWindow(void);
void drawColumnChar(int column, int idx);
void drawColumnObj(int column, int idx);
void dispObj(int kind, int st, int idx);
void drawString(unsigned char *txt, int idx);
void drawAddress(const unsigned char *addr, int idx);
int isPush(void);
void applyForcus(void);
void taskPushCount(void * unused0, void * unused1);
void pushButtonYesNo(void);
void DWCi_SetListReturn(unsigned char v);
/* END mkheaders: generated region */

#endif
