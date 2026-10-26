#ifndef GAME_OV177_WIFIBATTLEMATCH_GRAPHIC_H
#define GAME_OV177_WIFIBATTLEMATCH_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifibattlematch_graphic.c, prototypes copied from their definitions. */

struct WifibattlematchGraphic;
struct Unit;
struct TcbTask;
struct WifibattlematchClact;
struct DispVramCfg;

#include "../types.h"

struct WifibattlematchGraphic *WIFIBATTLEMATCH_GRAPHIC_Create(unsigned swap, u16 heap);
void WIFIBATTLEMATCH_GRAPHIC_Delete(struct WifibattlematchGraphic *p);
void WIFIBATTLEMATCH_GRAPHIC_Draw(struct WifibattlematchGraphic *p);
struct Unit *WIFIBATTLEMATCH_GRAPHIC_GetCamera(struct WifibattlematchGraphic *p);
void WIFIBATTLEMATCH_GRAPHIC_VBlank(struct TcbTask *task, void *work);
void WIFIBATTLEMATCH_GRAPHIC_InitBg(void *p, unsigned short heap);
void WIFIBATTLEMATCH_GRAPHIC_DeleteBg(void *p);
void WIFIBATTLEMATCH_GRAPHIC_Noop(void *p);
void WIFIBATTLEMATCH_GRAPHIC_TickDisplay(int *unused);
void WIFIBATTLEMATCH_GRAPHIC_InitClact(struct WifibattlematchClact *p, struct DispVramCfg *b, int c);
void WIFIBATTLEMATCH_GRAPHIC_DeleteClact(struct WifibattlematchClact *p);
void WIFIBATTLEMATCH_GRAPHIC_DrawClact(void *p);
void WIFIBATTLEMATCH_GRAPHIC_VBlankClact(int *unused);
struct Unit *WIFIBATTLEMATCH_GRAPHIC_GetClactBank(struct WifibattlematchClact *p);
/* END mkheaders: generated region */

#endif
