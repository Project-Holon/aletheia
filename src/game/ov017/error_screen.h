#ifndef GAME_OV017_ERROR_SCREEN_H
#define GAME_OV017_ERROR_SCREEN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of error_screen.c, prototypes copied from their definitions. */

void ERROR_SCREEN_ShowAndWait(void);
void ERROR_SCREEN_Setup(int messageIndex);
void ERROR_SCREEN_LoadBackground(void);
void ERROR_SCREEN_PrintMessage(int messageIndex);
void ERROR_SCREEN_Teardown(void);
/* END mkheaders: generated region */

#endif
