#ifndef GAME_ARM9_ISS_ROAD_SYS_H
#define GAME_ARM9_ISS_ROAD_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_road_sys.c, prototypes copied from their definitions. */

struct IssRoadSys;
struct Location;
typedef struct IssRoadSys IssRoadSys;

#include "../types.h"

IssRoadSys *ISS_ROAD_SYS_Create(struct Location *player, u32 heapId);
void ISS_ROAD_SYS_Delete(void *road);
void ISS_ROAD_SYS_Update(IssRoadSys *road);
void ISS_ROAD_SYS_Start(IssRoadSys *road);
void ISS_ROAD_SYS_Stop(IssRoadSys *road);
void ISS_ROAD_SYS_Activate(IssRoadSys *road);
void ISS_ROAD_SYS_Deactivate(IssRoadSys *road);
void ISS_ROAD_SYS_UpdateVolume(IssRoadSys *road);
u32 ISS_ROAD_SYS_HasPlayerMoved(IssRoadSys *road);
void ISS_ROAD_SYS_FadeIn(IssRoadSys *road);
void ISS_ROAD_SYS_FadeOut(IssRoadSys *road);
void ISS_ROAD_SYS_ApplyVolume(IssRoadSys *road);
/* END mkheaders: generated region */

typedef struct IssRoadSys IssRoadSys;

#endif
