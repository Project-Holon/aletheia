/*
 * file:     percentage.c
 * unit:     yes
 * function: PERCENTAGE_Create, PERCENTAGE_Destroy, PERCENTAGE_SetPosition, PERCENTAGE_SetValue, PERCENTAGE_SetVisible, PERCENTAGE_SetVisibleImpl, PERCENTAGE_Layout, PERCENTAGE_StoreValue, PERCENTAGE_StorePosition, PERCENTAGE_GetOnesDigit, PERCENTAGE_GetTensDigit, PERCENTAGE_GetHundredsDigit, PERCENTAGE_GetOnesPosition, PERCENTAGE_GetTensPosition, PERCENTAGE_GetHundredsPosition, PERCENTAGE_Alloc, PERCENTAGE_Free, PERCENTAGE_ClearFields, PERCENTAGE_Setup, PERCENTAGE_Exit, PERCENTAGE_StoreUnit, PERCENTAGE_CreateActors, PERCENTAGE_DeleteActors, PERCENTAGE_StoreTemplate
 * address:  0x021C26E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, PALETTE_ANIME_ReleaseOriginal.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   PERCENTAGE_SetValue 0x021C272C thumb ov217
 *   PERCENTAGE_SetPosition 0x021C271C thumb ov217
 *   PERCENTAGE_SetVisible 0x021C2740 thumb ov217
 *   PERCENTAGE_Create 0x021C26E8 thumb ov217
 *   PERCENTAGE_Destroy  0x021C270C  thumb  ov217
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_StopActorAnim  0x0204B974  arm  arm9
 */
#include "research_clact.h"

/* Actor description for the number display, copied into the object. */
struct PercentageTemplate {
    int charIndex;
    int paletteIndex;
    int cellAnimIndex;
    u16 priority;
    u16 digitAnimSeq;
    u16 signAnimSeq;
    u16 pad;
};

/* Three-digit number drawn with four actors (sign, hundreds, tens, ones), 52 bytes. */
struct Percentage {
    u16 heapId;
    u8 value;
    u8 pad3;
    u32 x;
    u32 y;
    struct ClactUnit *unit;
    struct ClactActor *actors[4];   /* sign, hundreds, tens, ones */
    struct PercentageTemplate tmpl;
};

#include "../arm9/gfl_heap_wrap.h"
struct Actor;
#include "../arm9/clact.h"

u32 PERCENTAGE_Create(u32 heapId, const struct PercentageTemplate *tmpl, struct ClactUnit *unit);
u32 PERCENTAGE_Destroy(struct Percentage *pct);
void PERCENTAGE_SetPosition(struct Percentage *pct, u32 x, u32 y);
void PERCENTAGE_SetValue(struct Percentage *pct, u32 value);
void PERCENTAGE_SetVisible(struct Percentage *pct, unsigned int visible);
void PERCENTAGE_SetVisibleImpl(struct Percentage *pct, unsigned int visible);
void PERCENTAGE_Layout(struct Percentage *pct);
void PERCENTAGE_StoreValue(struct Percentage *pct, u8 value);
void PERCENTAGE_StorePosition(struct Percentage *pct, u32 x, u32 y);
u8 PERCENTAGE_GetOnesDigit(struct Percentage *pct);
u8 PERCENTAGE_GetTensDigit(struct Percentage *pct);
u8 PERCENTAGE_GetHundredsDigit(struct Percentage *pct);
void PERCENTAGE_GetOnesPosition(const struct Percentage *pct, s16 *x, s16 *y);
void PERCENTAGE_GetTensPosition(const struct Percentage *pct, s16 *x, s16 *y);
void PERCENTAGE_GetHundredsPosition(const struct Percentage *pct, s16 *x, s16 *y);
struct Percentage *PERCENTAGE_Alloc(u32 heapId);
u32 PERCENTAGE_Free(struct Percentage *pct);
void PERCENTAGE_ClearFields(struct Percentage *pct, u32 heapId);
void PERCENTAGE_Setup(struct Percentage *pct, const struct PercentageTemplate *tmpl, struct ClactUnit *unit);
void PERCENTAGE_Exit(struct Percentage *pct);
void PERCENTAGE_StoreUnit(struct Percentage *pct, struct ClactUnit *unit);
void PERCENTAGE_CreateActors(struct Percentage *pct);
void PERCENTAGE_DeleteActors(struct Percentage *pct);
void PERCENTAGE_StoreTemplate(struct Percentage *pct, const struct PercentageTemplate *tmpl);

/* Allocates the object, clears it and creates its four actors. */
u32 PERCENTAGE_Create(u32 heapId, const struct PercentageTemplate *tmpl, struct ClactUnit *unit)
{
    struct Percentage *pct = PERCENTAGE_Alloc(heapId);
    PERCENTAGE_ClearFields(pct, heapId);
    PERCENTAGE_Setup(pct, tmpl, unit);
    return (u32)pct;
}

/* Deletes the actors, then frees the object. */
u32 PERCENTAGE_Destroy(struct Percentage *pct)
{
    PERCENTAGE_Exit(pct);
    return PERCENTAGE_Free(pct);
}

/* Moves the display to (x, y). */
void PERCENTAGE_SetPosition(struct Percentage *pct, u32 x, u32 y)
{
    PERCENTAGE_StorePosition(pct, x, y);
    PERCENTAGE_Layout(pct);
}

/* Sets the displayed number (0..255) and refreshes the actors. */
void PERCENTAGE_SetValue(struct Percentage *pct, u32 value)
{
    PERCENTAGE_StoreValue(pct, (u8)value);
    PERCENTAGE_Layout(pct);
}

/* Veneer: shows or hides the display. */
void PERCENTAGE_SetVisible(struct Percentage *pct, unsigned int visible)
{
    PERCENTAGE_SetVisibleImpl(pct, visible);
}

/*
 * Draws the sign always, the hundreds digit when the value has one, the
 * tens digit when the value has a hundreds or tens digit, and the ones digit always.
 */
void PERCENTAGE_SetVisibleImpl(struct Percentage *pct, unsigned int visible)
{
    CLACT_SetActorDrawEnable((struct ClactActor *)pct->actors[0], visible);
    if (PERCENTAGE_GetHundredsDigit(pct) != 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)pct->actors[1], visible);
    }
    if (PERCENTAGE_GetHundredsDigit(pct) != 0 || PERCENTAGE_GetTensDigit(pct) != 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)pct->actors[2], visible);
    }
    CLACT_SetActorDrawEnable((struct ClactActor *)pct->actors[3], visible);
}

/* Places every actor and sets the digit animation frames; all actors start hidden. */
void PERCENTAGE_Layout(struct Percentage *pct)
{
    u32 hidden = 0;
    struct ClactActor *actor = pct->actors[0];
    struct PercentageTemplate *tmpl = &pct->tmpl;
    struct ResearchClactSurfacePos pos;

    pos.x = pct->x;
    pos.y = pct->y;

    CLACT_AddActorSurfacePos((struct ClactActor *)actor, (const struct ClactVec2 *)&pos, tmpl->priority);
    CLACT_SetActorAnimSeq((struct ClactActor *)actor, tmpl->signAnimSeq);

    CLACT_SetActorAnimFrame((struct ClactActor *)actor, 0);
    CLACT_StopActorAnim((struct ClactActor *)actor);
    CLACT_SetActorDrawEnable((struct ClactActor *)actor, 0);

    actor = pct->actors[1];
    PERCENTAGE_GetHundredsPosition(pct, &pos.x, &pos.y);
    CLACT_AddActorSurfacePos((struct ClactActor *)actor, (const struct ClactVec2 *)&pos, tmpl->priority);
    CLACT_SetActorAnimSeq((struct ClactActor *)actor, tmpl->digitAnimSeq);
    CLACT_SetActorAnimFrame((struct ClactActor *)actor, PERCENTAGE_GetHundredsDigit(pct) << 12);
    CLACT_StopActorAnim((struct ClactActor *)actor);
    CLACT_SetActorDrawEnable((struct ClactActor *)actor, 0);

    actor = pct->actors[2];
    PERCENTAGE_GetTensPosition(pct, &pos.x, &pos.y);
    CLACT_AddActorSurfacePos((struct ClactActor *)actor, (const struct ClactVec2 *)&pos, tmpl->priority);
    CLACT_SetActorAnimSeq((struct ClactActor *)actor, tmpl->digitAnimSeq);
    CLACT_SetActorAnimFrame((struct ClactActor *)actor, PERCENTAGE_GetTensDigit(pct) << 12);
    CLACT_StopActorAnim((struct ClactActor *)actor);
    CLACT_SetActorDrawEnable((struct ClactActor *)actor, 0);

    actor = pct->actors[3];
    PERCENTAGE_GetOnesPosition(pct, &pos.x, &pos.y);
    CLACT_AddActorSurfacePos((struct ClactActor *)actor, (const struct ClactVec2 *)&pos, tmpl->priority);
    CLACT_SetActorAnimSeq((struct ClactActor *)actor, tmpl->digitAnimSeq);
    CLACT_SetActorAnimFrame((struct ClactActor *)actor, PERCENTAGE_GetOnesDigit(pct) << 12);
    CLACT_StopActorAnim((struct ClactActor *)actor);
    CLACT_SetActorDrawEnable((struct ClactActor *)actor, hidden);
}

/* Stores the value. */
void PERCENTAGE_StoreValue(struct Percentage *pct, u8 value)
{
    pct->value = value;
}

/* Stores the position. */
void PERCENTAGE_StorePosition(struct Percentage *pct, u32 x, u32 y)
{
    pct->x = x;
    pct->y = y;
}

/* Returns the ones digit. */
u8 PERCENTAGE_GetOnesDigit(struct Percentage *pct)
{
    return (u8)(pct->value % 10);
}

/* Returns the tens digit. */
u8 PERCENTAGE_GetTensDigit(struct Percentage *pct)
{
    int rest = pct->value % 100;
    return (u8)(rest / 10);
}

/* Returns the hundreds digit. */
u8 PERCENTAGE_GetHundredsDigit(struct Percentage *pct)
{
    return (u8)(pct->value / 100);
}

/* Position of the ones digit: 20 pixels right of the base, 8 above. */
void PERCENTAGE_GetOnesPosition(const struct Percentage *pct, s16 *x, s16 *y)
{
    *x = pct->x + 0x14;
    *y = pct->y - 8;
}

/* Position of the tens digit: 15 pixels right of the base, 8 above. */
void PERCENTAGE_GetTensPosition(const struct Percentage *pct, s16 *x, s16 *y)
{
    *x = pct->x + 0xF;
    *y = pct->y - 8;
}

/* Position of the hundreds digit: 10 pixels right of the base, 8 above. */
void PERCENTAGE_GetHundredsPosition(const struct Percentage *pct, s16 *x, s16 *y)
{
    *x = pct->x + 0xA;
    *y = pct->y - 8;
}

/* Allocates the 52-byte object. */
struct Percentage *PERCENTAGE_Alloc(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, 52, 0, (const char *)0x21C407C, 420);
}

/* Frees the object. */
u32 PERCENTAGE_Free(struct Percentage *pct)
{
    return GFL_HEAP_Free(pct);
}

/* Clears the value, unit and actor pointers and records the heap id. */
void PERCENTAGE_ClearFields(struct Percentage *pct, u32 heapId)
{
    int i;
    pct->heapId = heapId;
    pct->value = 0;
    pct->unit = 0;
    for (i = 0; i < 4; i++)
        pct->actors[i] = 0;
}

/* Stores the unit and template, then creates the actors. */
void PERCENTAGE_Setup(struct Percentage *pct, const struct PercentageTemplate *tmpl, struct ClactUnit *unit)
{
    PERCENTAGE_StoreUnit(pct, unit);
    PERCENTAGE_StoreTemplate(pct, tmpl);
    PERCENTAGE_CreateActors(pct);
}

/* Veneer: deletes the actors. */
void PERCENTAGE_Exit(struct Percentage *pct)
{
    PERCENTAGE_DeleteActors(pct);
}

/* Stores the CLACT unit that owns the actors. */
void PERCENTAGE_StoreUnit(struct Percentage *pct, struct ClactUnit *unit)
{
    pct->unit = unit;
}

/* Creates the four actors at the origin. */
void PERCENTAGE_CreateActors(struct Percentage *pct)
{
    struct ActorHeader header;
    struct PercentageTemplate *tmpl = &pct->tmpl;
    int i;

    header.x = 0;
    header.y = 0;
    header.z = 0;
    header.animNo = 0;
    header.bgPriority = 0;
    for (i = 0; i < 4; i++) {
        pct->actors[i] = CLACT_CreateActor((struct Unit *)pct->unit, tmpl->charIndex, tmpl->paletteIndex, tmpl->cellAnimIndex, (const struct ActorInitParam *)&header,
                                           tmpl->priority,
                                           pct->heapId);
    }
}

/* Deletes the four actors. */
void PERCENTAGE_DeleteActors(struct Percentage *pct)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteActor((struct ClactActor *)pct->actors[i]);
}

/* Copies the 20-byte template into the object. */
void PERCENTAGE_StoreTemplate(struct Percentage *pct, const struct PercentageTemplate *tmpl)
{
    pct->tmpl = *tmpl;
}
