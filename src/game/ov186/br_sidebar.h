#ifndef GAME_OV186_BR_SIDEBAR_H
#define GAME_OV186_BR_SIDEBAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_sidebar.c, prototypes copied from their definitions. */

struct BrSidebar;
struct Unit;
struct BrFade;
struct BrRes;
struct BrSidebarSlot;
struct BrSidebarConfig;

#include "../types.h"

struct BrSidebar *BR_SIDEBAR_Create(struct Unit *unit, struct BrFade *unused, struct BrRes *res, u16 heapId);
void BR_SIDEBAR_Destroy(struct BrSidebar *sidebar, struct BrRes *res);
void BR_SIDEBAR_Update(struct BrSidebar *sidebar);
void BR_SIDEBAR_StartBounce(struct BrSidebar *sidebar);
void BR_SIDEBAR_StartWobble(struct BrSidebar *sidebar);
void BR_SIDEBAR_StartSlide(struct BrSidebar *sidebar);
void BR_SIDEBAR_ResetPositions(struct BrSidebar *sidebar);
void BR_SIDEBAR_SetVisibleBySpace(struct BrSidebar *sidebar, int space, u32 visible);
void BR_SIDEBAR_InitSlot(struct BrSidebarSlot *slot, struct Unit *unit, struct BrRes *res, const struct BrSidebarConfig *config, u16 heapId);
void BR_SIDEBAR_DestroySlot(struct BrSidebarSlot *slot);
void BR_SIDEBAR_UpdateSlot(struct BrSidebarSlot *slot);
int BR_SIDEBAR_IsSlotActive(struct BrSidebarSlot *slot);
void BR_SIDEBAR_SetSlotVisible(struct BrSidebarSlot *slot, u32 visible);
void BR_SIDEBAR_SetSlotMode(struct BrSidebarSlot *slot, u32 mode);
void BR_SIDEBAR_ResetSlot(struct BrSidebarSlot *slot);
void BR_SIDEBAR_UpdateBounce(struct BrSidebarSlot *slot);
void BR_SIDEBAR_UpdateWobble(struct BrSidebarSlot *slot);
void BR_SIDEBAR_UpdateSlide(struct BrSidebarSlot *slot);
/* END mkheaders: generated region */

#endif
