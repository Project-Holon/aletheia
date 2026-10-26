#ifndef GAME_OV010_FIELD_G3D_MAP_SCR_H
#define GAME_OV010_FIELD_G3D_MAP_SCR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_g3d_map_scr.c, prototypes copied from their definitions. */

struct ScrcmdWork;
typedef struct ScrcmdWork ScrcmdWork;

#include "../arm9/script_vm_types.h"

int FIELD_G3D_MAP_ScrCmdReadSaveByte(ScriptVm *vm, ScrcmdWork *cmdWork);
void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec);
int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *beaconSave, int slot, void *trainerRec);
/* END mkheaders: generated region */

#endif
