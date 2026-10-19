/*
 * file:     zukan_skin_savedata.c
 * unit:     yes
 * function: ZUKAN_SKIN_SAVE_GetSize, ZUKAN_SKIN_SAVE_Clear, ZUKAN_SKIN_SAVE_GetTiles, ZUKAN_SKIN_SAVE_GetPalette, ZUKAN_SKIN_SAVE_GetValidFlag, ZUKAN_SKIN_SAVE_SetValidFlag
 * address:  0x0200E8B0
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
 */
#include "misc_savedata_shared_types.h"

/* The 0x6204-byte Pokedex skin save block (extra save 7): 0x6000 bytes of
 * tile data and 0x200 bytes of palette, then the flag that says a skin was
 * downloaded. */
struct ZukanSkinSave {
    u8 data[0x6200];    /* +0x0000: tiles 0x6000, palette +0x6000 */
    u32 valid;          /* +0x6200 */
};

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned long size);

u32 ZUKAN_SKIN_SAVE_GetSize(void);

void ZUKAN_SKIN_SAVE_Clear(void *dest);

void ZUKAN_SKIN_SAVE_GetTiles(void);

void *ZUKAN_SKIN_SAVE_GetPalette(void *obj);

u32 ZUKAN_SKIN_SAVE_GetValidFlag(const void *obj);

void ZUKAN_SKIN_SAVE_SetValidFlag(void *obj, u32 value);

u32 ZUKAN_SKIN_SAVE_GetSize(void)
{
    return 0x6204;
}

void ZUKAN_SKIN_SAVE_Clear(void *dest)
{
    MI_CpuFill8(dest, 0, ZUKAN_SKIN_SAVE_GetSize());
}

void ZUKAN_SKIN_SAVE_GetTiles(void)
{
}

void *ZUKAN_SKIN_SAVE_GetPalette(void *saveData)
{
    return (u8 *)saveData + 0x6000;
}

u32 ZUKAN_SKIN_SAVE_GetValidFlag(const void *saveData)
{
    return *(const u32 *)&((struct ZukanSkinSave *)saveData)->valid;
}

void ZUKAN_SKIN_SAVE_SetValidFlag(void *saveData, u32 value)
{
    ((struct ZukanSkinSave *)saveData)->valid = value;
}
