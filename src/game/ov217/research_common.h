#ifndef RESEARCH_COMMON_H
#define RESEARCH_COMMON_H

#include "research_clact.h"

struct Ctx;
struct Cfg;
struct PalAnmSlot;
struct PaletteAnime;

/* Touch hit rectangle, edges in pixels. */
struct TouchRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
};

/*
 * Object shared by the three research screens (top, list, graph): the CLACT
 * system, its resources and unit, one actor, the palette animation system and
 * the touch rectangles. 64 bytes, created by RESEARCH_COMMON_Create.
 */
struct ResearchCommon {
    u16 heapId;
    u16 pad2;                           /* alignment before the pointer */
    const struct Ctx *ctx;
    void *appResource;
    struct TouchRect touchRects[2];
    s32 resourceIds[3];                 /* character, palette, cell animation */
    struct ClactUnit *clactUnits[1];
    struct ClactActor *actor;
    void *palAnm;
    struct PaletteAnime *paletteAnime[1];
    u32 previousScreen;
    u32 currentScreen;
    u32 entryHandled;
    u32 inputFlag;
};

#endif
