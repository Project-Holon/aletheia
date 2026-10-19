/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E884
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: SAVE_SYNC_Store, SAVE_SYNC_Load, ZUKAN_SKIN_SAVE_GetSize, ZUKAN_SKIN_SAVE_Clear,
 *           ZUKAN_SKIN_SAVE_GetTiles, ZUKAN_SKIN_SAVE_GetPalette, ZUKAN_SKIN_SAVE_GetValidFlag, ZUKAN_SKIN_SAVE_SetValidFlag,
 *           TRIAL_HOUSE_SAVE_GetSize, TRIAL_HOUSE_SAVE_Clear, TRIAL_HOUSE_SAVE_GetFromSave, LIVEBATTLEMATCH_SAVE_InitRecord
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   MIi_CpuCopy32 0x02082A90  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   OS_GetMacAddress 0x02087C6C  arm
 *
 * alias: twelve functions on the same big object as unit_0200E938.c, all
 * working the same field at +0x6200/+0x6204.  SAVE_SYNC_Store and SAVE_SYNC_Load
 * are a copy-in/copy-out pair around a 0x10-byte scratch object obtained
 * from SAVE_CONTROL_GetBlock(id 0x40); ZUKAN_SKIN_SAVE_GetSize hands back the constant 0x6204,
 * which ZUKAN_SKIN_SAVE_Clear uses as the zero-fill size for the whole object;
 * ZUKAN_SKIN_SAVE_GetTiles is an empty hook; ZUKAN_SKIN_SAVE_GetPalette hands out the address 0x6000
 * bytes into the object; ZUKAN_SKIN_SAVE_GetValidFlag/ZUKAN_SKIN_SAVE_SetValidFlag are a plain word
 * getter/setter on the field at +0x6200; TRIAL_HOUSE_SAVE_GetSize returns the constant
 * 0x5c, which TRIAL_HOUSE_SAVE_Clear's tail call to MI_CpuFill8 also uses directly
 * (the same 0x5c constant this compiler would otherwise route through
 * TRIAL_HOUSE_SAVE_GetSize, but the tail call inlines it); TRIAL_HOUSE_SAVE_GetFromSave tail calls
 * SAVE_CONTROL_GetBlock(sys, 0x41); LIVEBATTLEMATCH_SAVE_InitRecord zero-fills a separate 0x5a-byte
 * scratch object and hands it to OS_GetMacAddress.
 *
 * Four of the twelve carry no label in the generated listing: they are
 * two- and three-instruction leaves with no register-saving prologue, so
 * disasm.py's sweep never fires on them and the listing prints them as a
 * run of .word data between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * This file merges what used to be four single-function files
 * (SAVE_SYNC_Store.c, SAVE_SYNC_Load.c, ZUKAN_SKIN_SAVE_GetSize.c, LIVEBATTLEMATCH_SAVE_InitRecord.c) and
 * unit_0200E8B8.c: the five are contiguous in the image with no gap and no
 * intervening matched/sdk address, and the whole 0x0200E884..0x0200E918
 * range still reproduces EXACT as a single translation unit.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E884.c \
 *       --addr 0x0200E884 --thumb
 */
#include "../include/Obj17085.h"
#include "../include/Obj17086.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub020071CCCtrl;
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);
extern void  MIi_CpuCopy32(void *dest, const void *src, u32 size);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void  OS_GetMacAddress(void *obj);

void SAVE_SYNC_Store(void *sys, void *src)
{
    void *obj = SAVE_CONTROL_GetBlock(src, 0x40);
    MIi_CpuCopy32(sys, obj, 0x10);
}

void SAVE_SYNC_Load(void *sys, void *dest)
{
    void *obj = SAVE_CONTROL_GetBlock(sys, 0x40);
    MIi_CpuCopy32(obj, dest, 0x10);
}

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

void *ZUKAN_SKIN_SAVE_GetPalette(void *obj)
{
    return (u8 *)obj + 0x6000;
}

u32 ZUKAN_SKIN_SAVE_GetValidFlag(const void *obj)
{
    return *(const u32 *)&((struct Obj17085 *)obj)->f6200;
}

void ZUKAN_SKIN_SAVE_SetValidFlag(void *obj, u32 value)
{
    ((struct Obj17086 *)obj)->f6200 = value;
}

u32 TRIAL_HOUSE_SAVE_GetSize(void)
{
    return 0x5c;
}

void TRIAL_HOUSE_SAVE_Clear(void *dest)
{
    MI_CpuFill8(dest, 0, 0x5c);
}

void *TRIAL_HOUSE_SAVE_GetFromSave(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, 0x41);
}

void LIVEBATTLEMATCH_SAVE_InitRecord(void *obj)
{
    MI_CpuFill8(obj, 0, 0x5a);
    OS_GetMacAddress(obj);
}
