#ifndef GAME_ARM9_NNS_G2D_OAM_MANAGER_H
#define GAME_ARM9_NNS_G2D_OAM_MANAGER_H

typedef struct NNSG2dOamManagerInstance NNSG2dOamManagerInstance;
typedef struct VramResourceSel VramResourceSel;
typedef struct VramHandleSel VramHandleSel;
typedef struct VramResourceList VramResourceList;
typedef struct VramResourceIndices VramResourceIndices;
typedef struct VramHandleList VramHandleList;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g2d_oam_manager.c, prototypes copied from their definitions. */

struct Span;
struct OamWindow;
struct NNSG2dOamManagerInstance;
struct VramResource;
struct VramHandle;
struct VramResourceSel;
struct VramHandleSel;
struct VramResourceList;
struct VramResourceIndices;
struct VramHandleList;
typedef struct NNSG2dOamManagerInstance NNSG2dOamManagerInstance;
typedef struct VramResourceSel VramResourceSel;
typedef struct VramHandleSel VramHandleSel;
typedef struct VramResourceList VramResourceList;
typedef struct VramResourceIndices VramResourceIndices;
typedef struct VramHandleList VramHandleList;

#include "../types.h"
#include "../sdk_gx.h"
#include "../sdk_fx.h"

void NNSi_G2dCpuLoadOamSub(void *src, u32 offset, u32 size);
void NNSi_G2dCpuLoadOamMain(void *src, u32 offset, u32 size);
void NNS_G2dInitOamManagerModule(void);
u32 NNSi_G2dReserveOamManagerSpan(struct Span *s, u16 first, int count, int which);
u32 NNSi_G2dEntryOamManagerOam(struct OamWindow *win, GXOamAttr *src, u32 mode);
u16 NNS_G2dEntryOamManagerAffine(NNSG2dOamManagerInstance *pMan, const MtxFx22 *mtx);
void NNS_G2dApplyOamManagerToHW(NNSG2dOamManagerInstance *pMan, u32 bound);
void NNS_G2dResetOamManagerBuffer(NNSG2dOamManagerInstance *pMan);
int NNSi_G2dGetVramHandle(unsigned short *p, int i);
void NNSi_G2dInitVramHandle(u32 *p);
void NNSi_G2dSetVramHandle(int *p, int i, int v);
int NNSi_G2dGetVramHandleValue(int *p, int i);
int NNSi_G2dIsVramHandleSet(const u32 *p, u32 i);
void NNSi_G2dInitVramHandleEx(u32 *p);
void NNSi_G2dSetVramHandleEx(char *p, int i, int v);
int NNSi_G2dGetVramHandleEx(char *p, int i);
int NNSi_G2dIsVramHandleSetEx(char *p, int i);
void NNSi_G2dLoadVramResourceMain(struct VramResource *r, u32 dst, int mode, struct VramHandle *out);
void NNSi_G2dLoadVramResourceSub(struct VramResource *r, u32 dst, int mode, struct VramHandle *out);
void NNSi_G2dSetupVramResource(struct VramResource *r, u32 dst, int mode, struct VramHandle *out);
void NNSi_G2dLoadVramResourceBySel(VramResourceSel *self, u32 offset, int sel, VramHandleSel *out);
void NNSi_G2dLoadVramResourceList(VramResourceList *self, VramResourceIndices *list, u32 base, int sel, VramHandleList *out);
/* END mkheaders: generated region */

#endif
