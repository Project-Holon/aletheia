#ifndef GAME_OV051_FIELD_GIMMICK_D06_H
#define GAME_OV051_FIELD_GIMMICK_D06_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_d06.c, prototypes copied from their definitions. */

struct FieldMap;
struct GameEvent;
struct Mmdl;
struct FieldEffectObj;

#include "../ov051/field_gimmick_d06_types.h"

const GimmickD06ZoneTable *FIELD_GIMMICK_D06_FindStoneTableRow(int zoneId);
const GimmickD06GridPos *FIELD_GIMMICK_D06_GetStonePositions(int zoneId);
int FIELD_GIMMICK_D06_GetStoneCount(int zoneId);
const GimmickD06ZoneTable *FIELD_GIMMICK_D06_FindPanelTable(int zoneId);
const GimmickD06GridPos *FIELD_GIMMICK_D06_GetPanelPositions(int zoneId);
int FIELD_GIMMICK_D06_GetPanelCount(int zoneId);
void FIELD_GIMMICK_D06_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_D06_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_D06_Update(void);
struct GameEvent *FIELD_GIMMICK_D06_CheckPushStone(struct FieldMap *fieldMap, int facingDir);
struct GameEvent *FIELD_GIMMICK_D06_CreateSlideEvent(struct FieldMap *fieldMap, struct Mmdl *stone, int direction);
int FIELD_GIMMICK_D06_EventSlideStone(struct GameEvent *event, int *seq, void *work);
int FIELD_GIMMICK_D06_EventStoneBlocked(struct GameEvent *event, int *seq, void *work);
void FIELD_GIMMICK_D06_AddStone(GimmickD06Work *work, GimmickD06StoneSlot *slot, int gridX, int gridZ);
void FIELD_GIMMICK_D06_AttachStone(GimmickD06Work *work, GimmickD06StoneSlot *slot, struct Mmdl *mmdl);
int FIELD_GIMMICK_D06_ScanSlide(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction, unsigned short maxSteps, unsigned int *steps);
int FIELD_GIMMICK_D06_GetSlideSteps(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction);
int FIELD_GIMMICK_D06_IsStoneNextToPanel(GimmickD06Work *work, GimmickD06StoneSlot *slot);
void FIELD_GIMMICK_D06_AddPanelPulse(GimmickD06Work *work, struct FieldEffectObj **pulse, int gridX, int gridY, int gridZ);
void FIELD_GIMMICK_D06_TriggerPanelPulse(struct FieldMap *fieldMap, int panelIndex);
struct Mmdl *FIELD_GIMMICK_D06_AddStoneMmdl(struct FieldMap *fieldMap, int gridX, int gridZ);
GimmickD06Work *FIELD_GIMMICK_D06_GetWork(struct FieldMap *fieldMap);
int FIELD_GIMMICK_D06_GetGimmickId(int zoneId);
/* END mkheaders: generated region */

#endif
