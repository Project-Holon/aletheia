#ifndef GAME_ARM9_FS_OVERLAY_H
#define GAME_ARM9_FS_OVERLAY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fs_overlay.c, prototypes copied from their definitions. */

struct FSOverlayInfo;
typedef struct FSOverlayInfo FSOverlayInfo;

#include "../types.h"
#include "../sdk_fs.h"

void FSi_InitOverlay(void);
u32 FSi_GetOverlayBinarySize(FSOverlayInfo *p);
void FS_ClearOverlayImage(FSOverlayInfo *p_ovi);
FSFileID FS_GetOverlayFileID(FSOverlayInfo *p_ovi);
BOOL FS_LoadOverlayInfo(FSOverlayInfo *p_ovi, u32 target, u32 id);
BOOL FS_LoadOverlayImage(FSOverlayInfo *p_ovi);
BOOL FSi_CompareDigest(const u8 *spec_digest, void *src, int len, BOOL table_mode);
void FS_StartOverlay(FSOverlayInfo *p_ovi);
void FS_EndOverlay(FSOverlayInfo *p_ovi);
BOOL FS_UnloadOverlayImage(FSOverlayInfo *p_ovi);
BOOL FS_LoadOverlay(int target, u32 id);
int FS_UnloadOverlay(int target, u32 id);
/* END mkheaders: generated region */

typedef struct FSOverlayInfo FSOverlayInfo;

#endif
