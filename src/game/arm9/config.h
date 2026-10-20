#ifndef GAME_ARM9_CONFIG_H
#define GAME_ARM9_CONFIG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of config.c, prototypes copied from their definitions. */

struct Config;

#include "../types.h"

void CONFIG_InitKeyControlTable(void);
void *CONFIG_Create(int heap_id);
void CONFIG_Copy(const struct Config *src, struct Config *dest);
void CONFIG_Init(struct Config *config);
unsigned int CONFIG_GetTextSpeed(const struct Config *config);
void CONFIG_SetTextSpeed(struct Config *config, unsigned int value);
unsigned int CONFIG_GetSoundMode(const struct Config *config);
void CONFIG_SetSoundMode(struct Config *config, unsigned int value);
unsigned int CONFIG_GetBattleScene(const struct Config *config);
void CONFIG_SetBattleScene(struct Config *config, unsigned int value);
unsigned int CONFIG_GetBattleStyle(const struct Config *config);
void CONFIG_SetBattleStyle(struct Config *config, unsigned int value);
int CONFIG_GetTextLanguage(const struct Config *config);
void CONFIG_SetTextLanguage(struct Config *config, unsigned int value);
void CONFIG_ApplyTextLanguage(const struct Config *config);
int CONFIG_GetButtonMode(const struct Config *config);
void CONFIG_SetButtonMode(struct Config *config, unsigned int value);
unsigned int CONFIG_GetBattleFlag(const struct Config *config);
void CONFIG_SetBattleFlag(struct Config *config, int enabled);
int MYSTATUS_GetSize(void);
/* END mkheaders: generated region */

#endif
