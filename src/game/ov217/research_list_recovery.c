/*
 * file:     research_list_recovery.c
 * unit:     yes
 * function: ListViewState_Create, ListViewState_Destroy, ListViewState_Reset, ListViewState_GetMode, ListViewState_GetScrollX, ListViewState_GetScrollY, ListViewState_SetMode, ListViewState_SetScrollX, ListViewState_SetScrollY
 * address:  0x021C0DC4
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
 *   ListViewState_Create  0x021C0DC4  thumb  ov217
 *   ListViewState_Reset  0x021C0DE4  thumb  ov217
 *   ListViewState_Destroy  0x021C0DDC  thumb  ov217
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ListViewState_GetMode 0x021C0DF0 thumb ov217
 *   ListViewState_GetScrollX 0x021C0DF4 thumb ov217
 *   ListViewState_GetScrollY 0x021C0DF8 thumb ov217
 *   ListViewState_SetScrollY 0x021C0E04 thumb ov217
 *   ListViewState_SetScrollX 0x021C0E00 thumb ov217
 *   ListViewState_SetMode 0x021C0DFC thumb ov217
 *   GFL_HEAP_Alloc  0x02030734  arm
 */
#include "research_shared_types.h"

/* Saved state of the research list view, 12 bytes. */
struct ListViewState {
    u8 mode;
    u32 scrollX;
    int scrollY;
};

#include "../arm9/gfl_heap_wrap.h"

struct ListViewState *ListViewState_Create(u32 heapId);
void ListViewState_Destroy(struct ListViewState *state);
void ListViewState_Reset(struct ListViewState *state);
u32 ListViewState_GetMode(struct ListViewState *state);
u32 ListViewState_GetScrollX(struct ListViewState *state);
u32 ListViewState_GetScrollY(struct ListViewState *state);
void ListViewState_SetMode(struct ListViewState *state, u8 mode);
void ListViewState_SetScrollX(struct ListViewState *state, u32 scrollX);
void ListViewState_SetScrollY(struct ListViewState *state, u32 scrollY);

/* Allocates a zero-filled state record. */
struct ListViewState *ListViewState_Create(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(struct ListViewState), 1, (const char *)0x21C4034, 32);
}

void ListViewState_Destroy(struct ListViewState *state)
{
    GFL_HEAP_Free(state);
}

/* Resets to mode 0, scroll X 0, scroll Y at its minimum -24. */
void ListViewState_Reset(struct ListViewState *state)
{
    state->mode = 0;
    state->scrollX = 0;
    state->scrollY = -0x18;
}

u32 ListViewState_GetMode(struct ListViewState *state)
{
    return state->mode;
}

u32 ListViewState_GetScrollX(struct ListViewState *state)
{
    return state->scrollX;
}

u32 ListViewState_GetScrollY(struct ListViewState *state)
{
    return state->scrollY;
}

void ListViewState_SetMode(struct ListViewState *state, u8 mode)
{
    state->mode = mode;
}

void ListViewState_SetScrollX(struct ListViewState *state, u32 scrollX)
{
    state->scrollX = scrollX;
}

void ListViewState_SetScrollY(struct ListViewState *state, u32 scrollY)
{
    state->scrollY = scrollY;
}
