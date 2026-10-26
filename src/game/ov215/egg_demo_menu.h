#ifndef GAME_OV215_EGG_DEMO_MENU_H
#define GAME_OV215_EGG_DEMO_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of egg_demo_menu.c, prototypes copied from their definitions. */

struct EggDemoArgs;

void EGG_DEMO_MENU_FadeInBgm();
void EGG_DEMO_MENU_Create(void *unused,char *work);
void EGG_DEMO_MENU_Delete(void *unused,char *work);
void EGG_DEMO_MENU_Main(void *unused, char *work);
void EGG_DEMO_MENU_Draw(void *unused, char *work);
void EGG_DEMO_MENU_SetText(struct EggDemoArgs *args,char *work,unsigned entry);
int EGG_DEMO_MENU_WaitText(void *unused,char *work);
void EGG_DEMO_MENU_InitDialog(void *unused, unsigned char *work);
void EGG_DEMO_MENU_Noop(struct EggDemoArgs *args, char *work);
void EGG_DEMO_MENU_ProcessDialog(void *unused, char *work);
int EGG_DEMO_MENU_CreateDialog(void *unused, char *work);
int EGG_DEMO_MENU_GetDialogResult(void *unused, char *work);
void EGG_DEMO_MENU_InitGraphics(void);
/* END mkheaders: generated region */

#endif
