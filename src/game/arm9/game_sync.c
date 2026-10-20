/*
 * file:     game_sync.c
 * unit:     yes
 * function: GAME_SYNC_GetBlock, GAME_SYNC_GetBlockSize, GAME_SYNC_ClearBlock
 * address:  0x02009448
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wifilist.c by tools/splitfile.py.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   SAVE_CONTROL_GetBlock    0x020071CC  thumb
 */
#include "game_sync_shared_types.h"

#define GAME_SYNC_BLOCK_ID 0x23

/* Save block 0x23 (0x1338 bytes). This file only sizes, fetches and clears it. */
struct GameSyncData {
    u8 data[0x1338];
};

#include "save_control.h"

#include "mi_memory.h"

struct GameSyncData *GAME_SYNC_GetBlock(struct SaveControl *saveControl);

u32 GAME_SYNC_GetBlockSize(void);

void GAME_SYNC_ClearBlock(struct GameSyncData *data);

static inline void MI_CpuClear32(void *dest, u32 size)
{
    MIi_CpuClear32(0, dest, size);
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the whole of the save block with id 0x23, 0x1338 bytes: the getter,
 * the size and a constructor that clears it and does nothing else.  Three
 * functions, forty bytes, and not one of them carries a label.
 *
 * GAME_SYNC_GetBlockSize is `ldr r0, [pc, #0]; bx lr` over its own pool word: 0x1338 is
 * past every Thumb immediate and past `movs` plus one `lsls`, so the constant
 * costs a word.  GAME_SYNC_ClearBlock loads the same constant into its own pool rather
 * than calling GAME_SYNC_GetBlockSize, so the source spells the size out in both, which
 * is what `sizeof` does.
 *
 * `MI_CpuClear32` is the SDK header's inline wrapper over MIi_CpuClear32 with
 * a zero fill value, and it is the last statement of a void function, so it
 * comes out as the pool word and `bx` of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md rather than as a `blx`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009448.c \
 *       --addr 0x02009448 --thumb
 */
struct GameSyncData *GAME_SYNC_GetBlock(struct SaveControl *saveControl)
{
    return SAVE_CONTROL_GetBlock(saveControl, GAME_SYNC_BLOCK_ID);
}

u32 GAME_SYNC_GetBlockSize(void)
{
    return sizeof(struct GameSyncData);
}

void GAME_SYNC_ClearBlock(struct GameSyncData *data)
{
    MI_CpuClear32(data, sizeof(struct GameSyncData));
}
