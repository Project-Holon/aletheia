/*
 * file:     cgear_save.c
 * unit:     yes
 * function: CGEAR_SAVE_GetSize, CGEAR_SAVE_Init, CGEAR_SAVE_SetObtained, CGEAR_SAVE_GetObtained, CGEAR_SAVE_SetPowerSetting, CGEAR_SAVE_GetPowerSetting, CGEAR_SAVE_SetGsyncState, CGEAR_SAVE_GetGsyncState, CGEAR_SAVE_SetGsyncId, CGEAR_SAVE_GetGsyncId, CGEAR_SAVE_GetPanelValue, CGEAR_SAVE_GetPanelFlag
 * address:  0x020090B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mail.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CGEAR_SAVE_DefaultPanels      0x020A7174  data
 */
#include "trcard_sign_shared_types.h"

/* ---- Save block with the C-Gear settings (0x2C) ---- */
struct CGearSave {
    u8  panel[9][4];                /* low nibble: value, bit 7: flag */
    u16 gsyncId;
    u8  gsyncState;
    u8  isObtained;
    u8  powerSetting;
    u8  reserved[3];
};

#include "mi_memory.h"


extern const u8 CGEAR_SAVE_DefaultPanels[0x24];

/*
 * C-Gear settings block, 0x2C bytes, in the next original file.  The
 * constructor clears the object and copies 0x24 bytes of initial panel state
 * over it from 0x020A7174.
 *
 * Six of the eight scalar accessors cost an extra adds r0, #imm before the
 * load or store, because ldrb and strb reach only +31 and the fields are at
 * +0x26..+0x28; the two u16 accessors at +0x24 need none (ldrh reaches +62;
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 */
u32 CGEAR_SAVE_GetSize(void)
{
    return sizeof(struct CGearSave);
}

void CGEAR_SAVE_Init(struct CGearSave *save)
{
    MI_CpuFill8(save, 0, CGEAR_SAVE_GetSize());
    MI_CpuCopy8(CGEAR_SAVE_DefaultPanels, save, 0x24);
}

void CGEAR_SAVE_SetObtained(struct CGearSave *save, u8 isObtained)
{
    save->isObtained = isObtained;
}

u8 CGEAR_SAVE_GetObtained(const struct CGearSave *save)
{
    return save->isObtained;
}

void CGEAR_SAVE_SetPowerSetting(struct CGearSave *save, u8 powerSetting)
{
    save->powerSetting = powerSetting;
}

u8 CGEAR_SAVE_GetPowerSetting(const struct CGearSave *save)
{
    return save->powerSetting;
}

void CGEAR_SAVE_SetGsyncState(struct CGearSave *save, u8 gsyncState)
{
    save->gsyncState = gsyncState;
}

u8 CGEAR_SAVE_GetGsyncState(const struct CGearSave *save)
{
    return save->gsyncState;
}

void CGEAR_SAVE_SetGsyncId(struct CGearSave *save, u16 gsyncId)
{
    save->gsyncId = gsyncId;
}

u16 CGEAR_SAVE_GetGsyncId(const struct CGearSave *save)
{
    return save->gsyncId;
}

u32 CGEAR_SAVE_GetPanelValue(const struct CGearSave *save, int row, int col)
{
    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    return save->panel[row][col] & 0xF;
}

int CGEAR_SAVE_GetPanelFlag(const struct CGearSave *save, int row, int col)
{
    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    if ((save->panel[row][col] & 0x80) != 0) {
        return 1;
    }
    return 0;
}
