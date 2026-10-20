#ifndef GAME_ARM9_MET_TRAINERS_SAVEDATA_H
#define GAME_ARM9_MET_TRAINERS_SAVEDATA_H

/* Public functions of met_trainers_savedata.c, prototypes copied from their definitions. */

struct MetTrainersSave;

#include "../types.h"

u32 MET_TRAINERS_GetSize(void);
void MET_TRAINERS_Init(void *block);
void *MET_TRAINERS_GetFromSave(void *saveData);
void MET_TRAINERS_Insert(struct MetTrainersSave *list, u32 value);
int MET_TRAINERS_Contains(struct MetTrainersSave *list, u32 value);
int MET_TRAINERS_TestBit(char *list, int bitIndex);
void MET_TRAINERS_SetBit(char *list, int bitIndex);

#endif
