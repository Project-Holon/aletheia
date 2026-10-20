#ifndef GAME_OV019_UNION_EFF_H
#define GAME_OV019_UNION_EFF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_eff.c, prototypes copied from their definitions. */

struct UnionEffWork;
struct UnionEffAnimGroup;
struct UnionEffObj;
struct UnionEffDrawStatus;
struct UnionEffIconGroup;
typedef struct UnionEffWork UnionEffWork;
typedef struct UnionEffAnimGroup UnionEffAnimGroup;
typedef struct UnionEffObj UnionEffObj;
typedef struct UnionEffDrawStatus UnionEffDrawStatus;
typedef struct UnionEffIconGroup UnionEffIconGroup;

#include "../types.h"

UnionEffWork *UNION_EFF_Create(u16 heapId);
void UNION_EFF_Delete(UnionEffWork *work);
void UNION_EFF_Main(UnionEffWork *work);
void UNION_EFF_Draw(UnionEffWork *work);
void UNION_EFF_AddAnimEffect(UnionEffWork *work, void *mmdl);
void UNION_EFF_AddIcon(UnionEffWork *work, void *mmdl, u32 iconKind);
void UNION_EFF_DeleteIcon(UnionEffWork *work, void *mmdl);
void UNION_EFF_InitAnimGroup(UnionEffAnimGroup *anim, u32 heapId);
void UNION_EFF_ExitAnimGroup(UnionEffAnimGroup *anim);
void UNION_EFF_AddAnimObj(UnionEffAnimGroup *anim, void *mmdl);
void UNION_EFF_CreateAnimObj(UnionEffAnimGroup *anim, UnionEffObj *obj, void *mmdl, u16 serial);
void UNION_EFF_DeleteAnimObj(UnionEffObj *obj);
void UNION_EFF_UpdateAnimObj(UnionEffObj *obj);
void UNION_EFF_DrawAnimObj(UnionEffObj *obj, UnionEffDrawStatus *status);
void UNION_EFF_DeleteAnimGroupObjs(UnionEffAnimGroup *anim);
void UNION_EFF_UpdateAnimGroup(UnionEffAnimGroup *anim);
void UNION_EFF_DrawAnimGroup(UnionEffAnimGroup *anim);
UnionEffObj *UNION_EFF_GetFreeAnimObj(UnionEffObj *objs);
void UNION_EFF_InitIconGroup(UnionEffIconGroup *icon, u32 heapId);
void UNION_EFF_ExitIconGroup(UnionEffIconGroup *icon);
void UNION_EFF_AddIconObj(UnionEffIconGroup *icon, void *mmdl, u32 iconKind);
void UNION_EFF_CreateIconObj(UnionEffIconGroup *icon, UnionEffObj *obj, void *mmdl, u16 serial, int iconKind);
void UNION_EFF_DeleteIconObj(UnionEffObj *obj);
void UNION_EFF_UpdateIconObj(UnionEffObj *obj);
void UNION_EFF_DrawIconObj(UnionEffObj *obj, UnionEffDrawStatus *status);
void UNION_EFF_DeleteIconGroupObjs(UnionEffIconGroup *icon);
void UNION_EFF_UpdateIconGroup(UnionEffIconGroup *icon);
void UNION_EFF_DrawIconGroup(UnionEffIconGroup *icon);
UnionEffObj *UNION_EFF_GetFreeIconObj(UnionEffObj *objs);
/* END mkheaders: generated region */

#endif
