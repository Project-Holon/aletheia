#ifndef GAME_OV132_STA_ACTING_H
#define GAME_OV132_STA_ACTING_H
struct TcbTask;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_acting.c, prototypes copied from their definitions. */

struct BgTemplate;

#include "../types.h"

u8 *STA_ACTING_Create(u8 *input, int heap);
void STA_ACTING_Delete(char *p);
int STA_ACTING_Update(u8 *p);
void STA_ACTING_VBlankCallback(struct TcbTask * unused0, void * unused1);
void STA_ACTING_InitDisplay(u8 *p);
void STA_ACTING_UploadPalettes(u8 *p);
void STA_ACTING_SetBaseProgram(u8 *p, u32 unused);
void STA_ACTING_SetupBg(const struct BgTemplate *p,u32 id,u32 type);
void STA_ACTING_CreateActors(u8 *p);
void STA_ACTING_CreateActObj(char *p);
void STA_ACTING_CreateActorSys(char *p);
void STA_ACTING_UpdateCamera(u8 *p);
void STA_ACTING_LoadCharAnims(u8 *p);
void STA_ACTING_LoadRankAnim(u8 *p, u8 setIndex, u8 player);
void STA_ACTING_LoadAnimMember(char *p, u8 setIndex, u8 mask);
void STA_ACTING_CreateText(u8 *p);
void STA_ACTING_UpdateText(u8 *p);
void STA_ACTING_PrintText(u8 *p, u16 index, u32 speed);
void STA_ACTING_ClearText(u8 *p);
void STA_ACTING_UpdateSelection(char *p);
void STA_ACTING_SetSelection(char *p, u8 player, int enable);
void STA_ACTING_MarkDirty(char *p);
void STA_ACTING_RankScores(u8 *p);
void STA_ACTING_InstallBgm(char *p, int bgmNo);
void STA_ACTING_StartSeq(char *p, int seqNo);
void STA_ACTING_StopSeq(char *p);
int STA_ACTING_ReplaceWaveData(char *p, u32 waveArcNo, u32 waveIndex, u32 srcWaveIndex);
void STA_ACTING_PlayBgm(char *p, int bgmNo);
void STA_ACTING_StopBgm(char *p);
void STA_ACTING_PlayRankSe(char *p);
void STA_ACTING_RequestAction(char *p,int value);
void STA_ACTING_ApplyAction(char *p, u32 player, int action);
int STA_ACTING_GetCurrentAction(char *p);
int STA_ACTING_GetActionByIndex(char *p,u32 player);
void STA_ACTING_ProcessRecords(char *p);
int STA_ACTING_AddScore(char *p, unsigned player, unsigned actionIndex);
void STA_ACTING_TickActionTimers(char *p);
void STA_ACTING_ScheduleActions(char *p, int mode, u8 slot);
void STA_ACTING_CreateAnimHandle(char *p);
void STA_ACTING_DeleteAnimHandle(char *p);
void STA_ACTING_PositionAnim(char *p, unsigned player);
void STA_ACTING_ShowButton(char *p);
void STA_ACTING_HideButton(char *p);
void *STA_ACTING_GetActorSystem(char *p);
void *STA_ACTING_GetActor(char *p,u32 player);
void *STA_ACTING_GetActObj(void *p);
u32 *STA_ACTING_GetSlot(void *p,u8 index);
void STA_ACTING_SetSlot(void *p,void *value,u32 index);
void *STA_ACTING_GetEffectSystem(void *p);
void *STA_ACTING_GetAnimSlot(void *p,u8 index);
void STA_ACTING_SetAnimSlot(void *p,void *value,u32 index);
void *STA_ACTING_GetCharSystem(void *p);
void *STA_ACTING_GetCharSlot(void *p,u8 index);
void STA_ACTING_SetCharSlot(void *p,void *value,u8 index);
void *STA_ACTING_GetAudience(void *p);
u16 STA_ACTING_GetCameraPos(void *p);
void STA_ACTING_SetCameraPos(void *p,u16 pos);
u16 STA_ACTING_GetCameraScrollX(u8 *p);
void STA_ACTING_SetCameraTarget(u8 *p,u16 target);
void *STA_ACTING_GetActorCount(u8 *p);
int STA_ACTING_GetSelection(char *p);
unsigned char STA_ACTING_GetRecordScore(char *p, unsigned int player);
unsigned char STA_ACTING_GetBonus(char *p, unsigned int player);
void STA_ACTING_SetCameraHoldScore(char *p, unsigned int hold);
/* END mkheaders: generated region */

#endif
