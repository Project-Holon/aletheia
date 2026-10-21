#ifndef GAME_OV196_B_APP_TOOL_H
#define GAME_OV196_B_APP_TOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of b_app_tool.c, prototypes copied from their definitions. */

struct BAppToolEntry;
struct PrintSys;
typedef struct BAppToolEntry BAppToolEntry;

#include "../types.h"

u8 *B_APP_TOOL_Create(u16 heapId);
void B_APP_TOOL_Delete(void *p);
void B_APP_TOOL_CreateActors(char *p, struct Unit *owner, int charRes, int palRes, int cellRes);
void B_APP_TOOL_DeleteActors(u8 *p);
void B_APP_TOOL_SetActorsVisible(char *p, void *visible);
void B_APP_TOOL_LayoutActors(int *actors, u8 *rect);
void B_APP_TOOL_ShowWindow(void **p);
void B_APP_TOOL_ShowWindows(char *windows, unsigned char *order);
void B_APP_TOOL_Update(BAppToolEntry *p, struct PrintSys *printSys, unsigned n);
/* END mkheaders: generated region */

#endif
