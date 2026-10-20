#ifndef GAME_OV010_MUSICAL_PROGRAM_H
#define GAME_OV010_MUSICAL_PROGRAM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_program.c, prototypes copied from their definitions. */

#include "../ov010/musical_event_shared_types.h"
#include "../types.h"
#include "../ov010/musical_event_shared_types.h"

MusicalShowProgram *MUSICAL_PROGRAM_Create(u32 heapId, MusicalSystemHead *musicalSystem, u16 maxLevel);
int MUSICAL_PROGRAM_Delete(MusicalShowProgram *program);
void MUSICAL_PROGRAM_SplitBonus(u32 heapId, MusicalShowProgram *program, MusicalStage *stage);
u8 MUSICAL_PROGRAM_GetCategoryBonus(MusicalShowProgram *program, int index);
u32 MUSICAL_PROGRAM_PackBonus(const MusicalShowProgram *program);
void MUSICAL_PROGRAM_UnpackBonus(MusicalShowProgram *program, u32 packed);
u32 MUSICAL_PROGRAM_PackPicks(const MusicalShowProgram *program);
void MUSICAL_PROGRAM_UnpackPicks(MusicalShowProgram *program, u32 packed);
u8 MUSICAL_PROGRAM_GetBestCategory(MusicalShowProgram *program);
void MUSICAL_PROGRAM_CreateNpcPerformer(MusicalShowProgram *program, MusicalStage *stage, u8 slot, u8 npcIndex, u16 heapId);
u8 MUSICAL_PROGRAM_GetBaseProgramId(MusicalShowProgram *program);
int MUSICAL_PROGRAM_GetPropRow(MusicalShowProgram *program);
u8 MUSICAL_PROGRAM_GetNpcPortraitClass(MusicalShowProgram *program, u8 npcIndex);
u8 MUSICAL_PROGRAM_GetNpcNameId(MusicalShowProgram *program, int npcIndex);
u16 MUSICAL_PROGRAM_GetCategoryShare(MusicalShowProgram *program, int category);
/* END mkheaders: generated region */

#endif
