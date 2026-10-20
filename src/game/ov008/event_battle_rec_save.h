#ifndef GAME_OV008_EVENT_BATTLE_REC_SAVE_H
#define GAME_OV008_EVENT_BATTLE_REC_SAVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_battle_rec_save.c, prototypes copied from their definitions. */

int EVENT_BATTLE_REC_SAVE_ProcInit(void *procsysOwner);
int EVENT_BATTLE_REC_SAVE_ProcExit(void *procWork, int unused, char *taskWork, int *procsys);
void *EVENT_BATTLE_REC_SAVE_Start(void *gameSystem, const int *args);
void *EVENT_BATTLE_REC_SAVE_CreateEvent(void *gameSystem, int info, int slots, int flag);
int EVENT_BATTLE_REC_SAVE_EventMain(int unused, int *stage, int *work);
/* END mkheaders: generated region */

#endif
