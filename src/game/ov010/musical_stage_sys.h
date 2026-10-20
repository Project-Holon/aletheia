#ifndef GAME_OV010_MUSICAL_STAGE_SYS_H
#define GAME_OV010_MUSICAL_STAGE_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_stage_sys.c, prototypes copied from their definitions. */

struct MusicalStageWork;
typedef struct MusicalStageWork MusicalStageWork;

#include "../ov010/musical_event_shared_types.h"
#include "../types.h"

int MUSICAL_STAGE_SYS_Init(void *proc, void *unused, MusicalStage *prevStage);
int MUSICAL_STAGE_SYS_Exit(void *proc, int unused, int keepStage, MusicalStageWork *work);
int MUSICAL_STAGE_SYS_Main(void *proc, int *state, int unused, MusicalStageWork *work);
MusicalStage *MUSICAL_STAGE_SYS_Create(u32 heapId, void *session);
int MUSICAL_STAGE_SYS_Delete(MusicalStage *stage);
int MUSICAL_STAGE_SYS_SetLocalPerformer(MusicalStage *stage, int slot, MusicalPerformer *performer);
void MUSICAL_STAGE_SYS_CreateNpcPerformer(MusicalStage *stage, u8 slot, u16 monsNo, u8 form, u32 personality, u16 appealBase, u16 heapId);
int MUSICAL_STAGE_SYS_SetRemotePerformer(MusicalStage *stage, int slot, MusicalPerformer *performer);
void MUSICAL_STAGE_SYS_SetPerformerProp(MusicalStage *stage, u8 slot, u8 bodySlot, u16 propId, s16 offset, u8 order);
/* END mkheaders: generated region */

#endif
