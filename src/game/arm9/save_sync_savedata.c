/*
 * file:     save_sync_savedata.c
 * unit:     yes
 * function: SAVE_SYNC_GetSize, SAVE_SYNC_Clear, SAVE_SYNC_Store, SAVE_SYNC_Load
 * address:  0x0200E874
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from misc_savedata_2.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   MIi_CpuCopy32 0x02082A90  arm
 *   OS_GetMacAddress 0x02087C6C  arm
 */
#include "misc_savedata_shared_types.h"
#include "greeting_savedata_shared_types.h"

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned long size);

extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

extern void  MIi_CpuCopy32(void *dest, const void *src, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

int SAVE_SYNC_GetSize(void);

void SAVE_SYNC_Clear(void *dst);

void SAVE_SYNC_Store(void *sys, void *src);

void SAVE_SYNC_Load(void *sys, void *dest);

/*
 * Size callback of save block 0x40 (0x10 bytes), the save sync block that
 * game_data keeps as gd->saveSyncBlock.  The function saves no registers, so
 * disasm.py printed it as part of a `.word` run
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 */
int SAVE_SYNC_GetSize(void)
{
    return 0x10;
}

void SAVE_SYNC_Clear(void *dst)
{
    MI_CpuFill8(dst, 0, 0x10);
}

/*
 * Copy the runtime save sync block into block 0x40 of the save (called by
 * game_data when saving); SAVE_SYNC_Load is the reverse copy.  Each copies
 * 0x10 bytes.
 */
void SAVE_SYNC_Store(void *src, void *saveData)
{
    void *obj = SAVE_CONTROL_GetBlock(saveData, 0x40);
    MIi_CpuCopy32(src, obj, 0x10);
}

void SAVE_SYNC_Load(void *src, void *dest)
{
    void *obj = SAVE_CONTROL_GetBlock(src, 0x40);
    MIi_CpuCopy32(obj, dest, 0x10);
}
