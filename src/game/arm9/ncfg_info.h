#ifndef GAME_ARM9_NCFG_INFO_H
#define GAME_ARM9_NCFG_INFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ncfg_info.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_ncfg.h"
#include "../sdk_math.h"

u32 NCFG_ReadConfig(NCFGConfig *config);
s32 NCFG_CheckConfig(void *work);
s32 NCFG_CheckConfigEx(void *work);
s32 checkConfig(NCFGConfig *config, MATHCRC16Table *tbl);
s32 checkConfigEx(NCFGConfigEx *configEx, MATHCRC16Table *tbl);
void initPage(NCFGConfig *config, int page);
void initPageEx(NCFGConfigEx *config, int page);
int readAllSlots(NCFGConfig *config);
int readAllExSlots(NCFGConfigEx *configEx);
int writeAllSlots(NCFGConfig *config, MATHCRC16Table *tbl);
int writeAllExSlots(NCFGConfigEx *configEx, MATHCRC16Table *tbl);
/* END mkheaders: generated region */

#endif
