
struct TcbTask;
#ifndef GAME_OV211_ZUKAN_SEARCH_SCREEN_H
#define GAME_OV211_ZUKAN_SEARCH_SCREEN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_search_screen.c, prototypes copied from their definitions. */

struct ZukanSearchWork;

void ZUKAN_SEARCH_SCREEN_SetupVram(void);
void ZUKAN_SEARCH_SCREEN_VBlank(struct TcbTask *unused0, void *unused1);
void ZUKAN_SEARCH_SCREEN_RegisterVBlank(struct ZukanSearchWork *p);
void ZUKAN_SEARCH_SCREEN_UnregisterVBlank(struct ZukanSearchWork *p);
void ZUKAN_SEARCH_SCREEN_InitBg(void);
void ZUKAN_SEARCH_SCREEN_DeleteBg(void);
void ZUKAN_SEARCH_SCREEN_LoadGraphics(struct ZukanSearchWork *p);
void ZUKAN_SEARCH_SCREEN_LoadSaveGraphics(struct ZukanSearchWork *p);
int ZUKAN_SEARCH_SCREEN_Init(struct ZukanSearchWork *p);
int ZUKAN_SEARCH_SCREEN_Delete(struct ZukanSearchWork *p);
int ZUKAN_SEARCH_SCREEN_WaitWipe(void);
int ZUKAN_SEARCH_SCREEN_WaitWipeExit(void);
int ZUKAN_SEARCH_SCREEN_HandleInput(struct ZukanSearchWork *p);
int ZUKAN_SEARCH_SCREEN_Update(struct ZukanSearchWork *p);
void ZUKAN_SEARCH_SCREEN_Tick(void);
/* END mkheaders: generated region */

#endif
