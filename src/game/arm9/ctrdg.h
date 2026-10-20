#ifndef GAME_ARM9_CTRDG_H
#define GAME_ARM9_CTRDG_H

typedef struct CTRDGRomCycle CTRDGRomCycle;
typedef struct CTRDGLockByProc CTRDGLockByProc;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ctrdg.c, prototypes copied from their definitions. */

struct CTRDGRomCycle;
struct CTRDGLockByProc;
typedef struct CTRDGRomCycle CTRDGRomCycle;
typedef struct CTRDGLockByProc CTRDGLockByProc;

#include "../types.h"

BOOL CTRDG_IsExistedAtInit(void);
void CTRDGi_InitCommon(void);
BOOL CTRDG_IsExisting(void);
void CTRDGi_ChangeLatestAccessCycle(CTRDGRomCycle *r);
void CTRDGi_RestoreAccessCycle(CTRDGRomCycle *r);
void CTRDGi_LockByProcessor(u32 lockID, u32 *lockInfo);
void CTRDGi_UnlockByProcessor(u16 lockID, CTRDGLockByProc *info);
void CTRDGi_SendtoPxi(u32 data);
/* END mkheaders: generated region */

#endif
