#ifndef GAME_OV021_SCRCMD_SHOP_H
#define GAME_OV021_SCRCMD_SHOP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_shop.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;
struct FieldMap;

#include "../ov021/scrcmd_proc_fld_types.h"

int SCRCMD_SHOP_StartShop(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_SHOP_PrepareFieldCamera(ShopTask *task, struct FieldMap *fieldMap, void *fieldCamera);
/* END mkheaders: generated region */

#endif
