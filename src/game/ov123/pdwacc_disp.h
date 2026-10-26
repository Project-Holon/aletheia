#ifndef GAME_OV123_PDWACC_DISP_H
#define GAME_OV123_PDWACC_DISP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pdwacc_disp.c, prototypes copied from their definitions. */

#include "../ov123/pdwacc_disp_types.h"

PdwaccDispWork *PDWACC_DISP_Init(int heap);
void PDWACC_DISP_Draw(PdwaccDispWork *disp);
void PDWACC_DISP_Exit(PdwaccDispWork *disp);
void PDWACC_DISP_InitBgLayers(PdwaccDispWork *disp);
void PDWACC_DISP_VBlankTask(struct TcbTask * unused0, void * unused1);
void PDWACC_DISP_LoadResources(PdwaccDispWork *disp);
void PDWACC_DISP_PaletteTask(void *unused, PdwaccPaletteAnim *palette);
void PDWACC_DISP_DeleteActors(PdwaccDispWork *disp);
/* END mkheaders: generated region */

#endif
