#ifndef GAME_OV215_EGG_DEMO_VIEW_H
#define GAME_OV215_EGG_DEMO_VIEW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of egg_demo_view.c, prototypes copied from their definitions. */

void EGG_DEMO_VIEW_FreeRecords(void *work);
char *EGG_DEMO_VIEW_Create(unsigned heap,void *mon);
void EGG_DEMO_VIEW_Delete(char *work);
void EGG_DEMO_VIEW_Update(char *work);
void EGG_DEMO_VIEW_Draw(char *work);
void EGG_DEMO_VIEW_SetActive(char *work);
int EGG_DEMO_VIEW_GetActive(char *work);
void EGG_DEMO_VIEW_SetSpecies(char *work, void *species);
int EGG_DEMO_VIEW_IsFadeDone(char *work);
void EGG_DEMO_VIEW_ResetAnimState(char *work);
int EGG_DEMO_VIEW_IsFinished(char *work);
void EGG_DEMO_VIEW_Noop(void);
void EGG_DEMO_VIEW_InitMcss(char *work);
void EGG_DEMO_VIEW_DeleteMcss(char *work);
void EGG_DEMO_VIEW_AddPokeMcss(char *work);
void EGG_DEMO_VIEW_DeletePokeMcss(char *work);
void EGG_DEMO_VIEW_HidePokeMcss(char *work);
void EGG_DEMO_VIEW_PlayAnim(char *work,unsigned flag,int enable);
int EGG_DEMO_VIEW_OnAnimStop(char *work);
void EGG_DEMO_VIEW_UpdateAlpha(char *work);
void EGG_DEMO_VIEW_StartFadeOut(char *work);
int EGG_DEMO_VIEW_IsFadeOutDone(char *work);
void EGG_DEMO_VIEW_StartFadeIn(char *work);
char *EGG_DEMO_VIEW_CreateParticles(unsigned heap,unsigned count,const void *table);
void EGG_DEMO_VIEW_DeleteParticles(char *work);
void EGG_DEMO_VIEW_UpdateParticles(char *work);
void EGG_DEMO_VIEW_MainParticles(char *work);
void EGG_DEMO_VIEW_StartParticles(char *work);
void EGG_DEMO_VIEW_InitModel(char *work);
void EGG_DEMO_VIEW_DeleteModel(char *work);
void EGG_DEMO_VIEW_DrawModels(char *work);
void EGG_DEMO_VIEW_AddModel(char *work);
void EGG_DEMO_VIEW_RemoveModel(char *work);
void EGG_DEMO_VIEW_UpdateModel(char *work);
void EGG_DEMO_VIEW_StartModelAnim(char *work);
int EGG_DEMO_VIEW_IsModelAnimDone(char *work);
void EGG_DEMO_VIEW_EndModelAnim(char *work);
/* END mkheaders: generated region */

#endif
