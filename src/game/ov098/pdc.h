#ifndef GAME_OV098_PDC_H
#define GAME_OV098_PDC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pdc.c, prototypes copied from their definitions. */

struct PdcArgs;
struct GameData;
struct PokemonParam;
struct MyStatus;
struct MyItem;
struct Config;
struct PokedexSave;
struct Proc;
struct PdcProc;

#include "../types.h"

struct PdcArgs *PDC_CreateArgs(struct GameData *gameData, struct PokemonParam *mon, void *scene, struct MyStatus *myStatus, struct MyItem *myItem, struct Config *config, struct PokedexSave *pokedexSave, u16 heapId);
struct GameData *PDC_GetGameData(struct PdcArgs *args);
struct PokemonParam *PDC_GetMon(struct PdcArgs *args);
void *PDC_GetScene(struct PdcArgs *args);
struct MyStatus *PDC_GetMyStatus(struct PdcArgs *args);
struct MyItem *PDC_GetMyItem(struct PdcArgs *args);
struct Config *PDC_GetConfig(struct PdcArgs *args);
struct PokedexSave *PDC_GetPokedexSave(struct PdcArgs *args);
int PDC_GetResult(struct PdcArgs *args);
int PDC_ProcInit(struct Proc *proc, int seq, struct PdcArgs *args);
int PDC_ProcMain(struct Proc *proc, int seq, int unused, struct PdcProc *work);
int PDC_ProcExit(struct Proc *proc, int seq, int unused, struct PdcProc *work);
/* END mkheaders: generated region */

#endif
