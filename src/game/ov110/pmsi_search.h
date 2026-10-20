#ifndef GAME_OV110_PMSI_SEARCH_H
#define GAME_OV110_PMSI_SEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pmsi_search.c, prototypes copied from their definitions. */

struct PmsiSearch;
struct PmsInputData;
struct U16Vec;

#include "../types.h"

struct PmsiSearch *PMSI_SEARCH_Create(void *owner, struct PmsInputData *wordData, u16 heap);
void PMSI_SEARCH_Delete(struct PmsiSearch *s);
void PMSI_SEARCH_PushKey(struct PmsiSearch *s, int key);
int PMSI_SEARCH_PopKey(struct PmsiSearch *s);
u8 PMSI_SEARCH_GetInputCount(struct PmsiSearch *s);
void PMSI_SEARCH_ClearInput(struct PmsiSearch *s);
void PMSI_SEARCH_BuildInputText(struct PmsiSearch *s, struct U16Vec *out);
int PMSI_SEARCH_Run(struct PmsiSearch *s);
u8 PMSI_SEARCH_HasResults(struct PmsiSearch *s);
void PMSI_SEARCH_GetResultString(struct PmsiSearch *s, u8 resultIndex, int dest);
u16 PMSI_SEARCH_GetResultWordId(struct PmsiSearch *s, u32 resultIndex);
int PMSI_SEARCH_GetKeyCount(void);
void PMSI_SEARCH_GetKeyLabel(u32 i, struct U16Vec *dst);
u16 PMSI_SEARCH_GetKeyChar(u32 i);
void PMSI_SEARCH_GetKeyPosition(u32 i, int *column, int *row);
u8 PMSI_SEARCH_GetKeyUp(u32 i);
u8 PMSI_SEARCH_GetKeyDown(u32 i);
u8 PMSI_SEARCH_GetKeyLeft(u32 i);
int PMSI_SEARCH_GetKeyRight(int i);
u8 PMSI_SEARCH_GetKeyKind(u32 i);
/* END mkheaders: generated region */

#endif
