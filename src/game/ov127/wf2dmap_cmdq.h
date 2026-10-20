#ifndef GAME_OV127_WF2DMAP_CMDQ_H
#define GAME_OV127_WF2DMAP_CMDQ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wf2dmap_cmdq.c, prototypes copied from their definitions. */

struct Wf2dmapCmdStore;
struct Wf2dmapCmdRing;
struct Wf2dmapCmdPos;
typedef struct Wf2dmapCmdStore Wf2dmapCmdStore;
typedef struct Wf2dmapCmdRing Wf2dmapCmdRing;
typedef struct Wf2dmapCmdPos Wf2dmapCmdPos;

#include "../types.h"

Wf2dmapCmdStore *WF2DMAP_CMDQ_CreateStore(int n, int heap);
void WF2DMAP_CMDQ_DeleteStore(u8 *p);
void WF2DMAP_CMDQ_Push(Wf2dmapCmdRing *p, const Wf2dmapCmdPos *q);
int WF2DMAP_CMDQ_Pop(Wf2dmapCmdRing *a, Wf2dmapCmdPos *out);
/* END mkheaders: generated region */

#endif
