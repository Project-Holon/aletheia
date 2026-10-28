#ifndef GAME_OV124_CG_HELP_H
#define GAME_OV124_CG_HELP_H
struct TcbTask;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of cg_help.c, prototypes copied from their definitions. */

struct CgHelpWork;
struct BgTemplate;
struct CgHelpArgs;
struct Proc;
typedef struct CgHelpWork CgHelpWork;
typedef struct CgHelpArgs CgHelpArgs;

#include "../types.h"

void CG_HELP_Setup(CgHelpWork *work);
void CG_HELP_Teardown(CgHelpWork *work);
int CG_HELP_Main(CgHelpWork *work);
void CG_HELP_VBlank(struct TcbTask * unused0, void * unused1);
void CG_HELP_InitDisplay(CgHelpWork *work);
void CG_HELP_ExitDisplay(CgHelpWork *work);
void CG_HELP_SetupBgLayer(const struct BgTemplate *bgTemplate, int layer, int type);
void CG_HELP_LoadActorResources(CgHelpWork *work);
void CG_HELP_FreeActorResources(CgHelpWork *work);
void CG_HELP_InitWindows(CgHelpWork *work);
void CG_HELP_FreeWindows(CgHelpWork *work);
void CG_HELP_HandleTouchInput(CgHelpWork *work);
void CG_HELP_DrawPageText(CgHelpWork *work, int page);
void CG_HELP_UpdatePageGraphics(CgHelpWork *work, u32 page);
int CG_HELP_ProcInit(void *a,int b,CgHelpArgs *c);
int CG_HELP_ProcExit(struct Proc *task, int b, int keep, CgHelpWork *work);
int CG_HELP_ProcMain(int a, int b, int c, CgHelpWork *work);
/* END mkheaders: generated region */

#endif
