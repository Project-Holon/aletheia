/*
 * file:     actor_tool.c
 * unit:     yes
 * function: ACTOR_TOOL_Create, ACTOR_TOOL_Delete, ACTOR_TOOL_AllocRun, ACTOR_TOOL_FreeRun, ACTOR_TOOL_LoadChar, ACTOR_TOOL_LoadCharSimple, ACTOR_TOOL_LoadCharPalAnm, ACTOR_TOOL_LoadCharSimplePalAnm, ACTOR_TOOL_GetCharBlock, ACTOR_TOOL_FreeChar
 * address:  0x02025318
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from bmp_oam.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   g_020A7484     0x020A7484  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   PALANM_CopyHwPaletteToSlot   0x020216D4  thumb
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_GetPaletteVramAddress  0x0204AEF4  arm
 */
#include "actor_tool_shared_types.h"

/* Slot allocator for actor character/palette runs: two banks (main and sub
 * engine), 16 slots each; 0xFF marks a free slot, an allocated run is
 * stamped with its start index. */
struct ActorTool {
    u32 pad;
    u8  slotCount[2];
    u8  slot[2][16];
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *block);

extern s32 CLACT_RegisterPaletteEx(void *src, u32 resId, u32 bank, u32 vramOff, u16 reserved, u16 len, u16 flags);

extern int CLACT_RegisterPaletteCompressed(void *src, u32 resId, u32 bank, u32 vramOff, u16 flags);

extern void PALANM_CopyHwPaletteToSlot(void *palSlots, u32 bank, u32 off, u32 size);

extern void CLACT_ReleasePalette(u32 charOffset);

extern int CLACT_GetPaletteVramAddress(int charOffset, int bank);

struct ActorTool *ACTOR_TOOL_Create(u32 heapId, u8 bank0Count, u8 bank1Count);

void ACTOR_TOOL_Delete(struct ActorTool *tool);

int ACTOR_TOOL_AllocRun(struct ActorTool *tool, int len, u32 bank);

void ACTOR_TOOL_FreeRun(struct ActorTool *tool, u32 start, u32 bank);

s32 ACTOR_TOOL_LoadChar(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);

int ACTOR_TOOL_LoadCharSimple(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);

u32 ACTOR_TOOL_LoadCharPalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);

u32 ACTOR_TOOL_LoadCharSimplePalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);

unsigned int ACTOR_TOOL_GetCharBlock(int tool, int charOffset, int bank);

void ACTOR_TOOL_FreeChar(struct ActorTool *tool, u32 charOffset, u32 bank);

extern char  g_020A7484[];

struct ActorTool *ACTOR_TOOL_Create(u32 heapId, u8 bank0Count, u8 bank1Count)
{
    struct ActorTool *tool = GFL_HEAP_Alloc(heapId, 0x28, 1, g_020A7484, 0x51);
    int bank, slotIdx;

    tool->slotCount[0] = bank0Count;
    tool->slotCount[1] = bank1Count;
    for (bank = 0; bank < 2; bank++) {
        for (slotIdx = 0; slotIdx < 0x10; slotIdx++) {
            tool->slot[bank][slotIdx] = 0xff;
        }
    }
    return tool;
}

void ACTOR_TOOL_Delete(struct ActorTool *tool)
{
    GFL_HEAP_Free(tool);
}

/*
 * Allocate a run of len free (0xFF) slots in one bank and stamp every slot of
 * the run with its start index; returns the start, or 0.  ACTOR_TOOL_FreeRun
 * frees what this stamps.
 *
 * The scan loop's bound is written `j < i + len` in the loop condition, and
 * `end = i + len` is computed only after the scan, for the fill.  With `end`
 * assigned before the scan and used as its bound, the registers rotate
 * differently from the image.
 */
int ACTOR_TOOL_AllocRun(struct ActorTool *tool, int len, u32 bank)
{
    int start, slotIdx, end;
    u32 bankSel = 1;
    u8 *bankSlots;

    if (bank == 0)
        bankSel = 0;
    start = 0;
    if (start < tool->slotCount[bankSel]) {
        do {
            if (tool->slot[bankSel][start] == 0xff) {
                for (slotIdx = start; slotIdx < start + len; slotIdx++) {
                    if (tool->slot[bankSel][slotIdx] != 0xff) {
                        start = slotIdx;
                        break;
                    }
                }
                end = start + len;
                if (slotIdx == end) {
                    for (slotIdx = start; slotIdx < end; slotIdx++) {
                        bankSlots = (u8 *)tool + (bankSel << 4);
                        bankSlots[slotIdx + 6] = (u8)start;
                    }
                    return start;
                }
            }
            start++;
        } while (start < tool->slotCount[bankSel]);
    }
    return 0;
}

/*
 * Free the run that ACTOR_TOOL_AllocRun stamped with index i in one bank: every
 * slot from i on that still holds i goes back to 0xFF.  The cursor is an int
 * while the index it starts from is the u32 parameter; that keeps the two
 * copies of the cursor in different registers, as in the image.
 */
void ACTOR_TOOL_FreeRun(struct ActorTool *tool, u32 start, u32 bank)
{
    u32 bankSel = 1;
    int slotIdx;

    if (bank == 0)
        bankSel = 0;
    for (slotIdx = start; tool->slot[bankSel][slotIdx] == start; slotIdx++)
        tool->slot[bankSel][slotIdx] = 0xff;
}

s32 ACTOR_TOOL_LoadChar(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags)
{
    u32 runStart = ACTOR_TOOL_AllocRun(tool, len, bank);

    return CLACT_RegisterPaletteEx(src, resId, bank, (runStart & 0x7ff) << 5, 0, (u16)len, (u16)flags);
}

int ACTOR_TOOL_LoadCharSimple(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags)
{
    u32 runStart = ACTOR_TOOL_AllocRun(tool, len, bank);

    return CLACT_RegisterPaletteCompressed(src, resId, bank, (runStart & 0x7ff) << 5, (u16)flags);
}

/*
 * Load a palette run with ACTOR_TOOL_LoadChar, then copy the loaded palette
 * into palSlots: the bank selects the engine's palette type (2 for bank 0,
 * 3 otherwise), the destination offset is the block index from
 * ACTOR_TOOL_GetCharBlock shifted up four, and the size is len shifted up
 * five.  Returns the char offset.
 */
u32 ACTOR_TOOL_LoadCharPalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags)
{
    u32 palBankType = 2;
    u32 charOffset;
    u32 charBlock;

    if (bank != 0) {
        palBankType = 3;
    }
    charOffset = ACTOR_TOOL_LoadChar(tool, src, resId, bank, len, flags);
    charBlock = ACTOR_TOOL_GetCharBlock((int)tool, charOffset, bank);
    PALANM_CopyHwPaletteToSlot(palSlots, palBankType, (u16)(charBlock << 4), len << 5);
    return charOffset;
}

/*
 * The wide-tile twin of ACTOR_TOOL_LoadCharPalAnm: identical body, but the tile builder
 * is ACTOR_TOOL_LoadCharSimple rather than ACTOR_TOOL_LoadChar.
 */
u32 ACTOR_TOOL_LoadCharSimplePalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags)
{
    u32 palBankType = 2;
    u32 charOffset;
    u32 charBlock;

    if (bank != 0) {
        palBankType = 3;
    }
    charOffset = ACTOR_TOOL_LoadCharSimple(tool, src, resId, bank, len, flags);
    charBlock = ACTOR_TOOL_GetCharBlock((int)tool, charOffset, bank);
    PALANM_CopyHwPaletteToSlot(palSlots, palBankType, (u16)(charBlock << 4), len << 5);
    return charOffset;
}

/* The first argument is not used by the body. */
unsigned int ACTOR_TOOL_GetCharBlock(int tool, int charOffset, int bank)
{
    int rawBlock = CLACT_GetPaletteVramAddress(charOffset, bank);

    return (unsigned int)rawBlock >> 5;
}

void ACTOR_TOOL_FreeChar(struct ActorTool *tool, u32 charOffset, u32 bank)
{
    u32 charBlock = ACTOR_TOOL_GetCharBlock((int)tool, charOffset, bank);

    ACTOR_TOOL_FreeRun(tool, charBlock, bank);
    CLACT_ReleasePalette(charOffset);
}
