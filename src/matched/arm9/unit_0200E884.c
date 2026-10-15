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
 * function: MISC_SAVEDATA_SaveScratch16, MISC_SAVEDATA_LoadScratch16, MISC_SAVEDATA_GetBigBlockSize, MISC_SAVEDATA_ClearBigBlock,
 *           MISC_SAVEDATA_EmptyHook, MISC_SAVEDATA_GetScratchBase, MISC_SAVEDATA_GetFlags6200, MISC_SAVEDATA_SetFlags6200,
 *           MISC_SAVEDATA_GetMacSize, MISC_SAVEDATA_ClearMacArea, MISC_SAVEDATA_GetBlock41, MISC_SAVEDATA_InitMac
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   MIi_CpuCopy32 0x02082A90  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   OS_GetMacAddress 0x02087C6C  arm
 *
 * alias: twelve functions on the same big object as unit_0200E938.c, all
 * working the same field at +0x6200/+0x6204.  MISC_SAVEDATA_SaveScratch16 and MISC_SAVEDATA_LoadScratch16
 * are a copy-in/copy-out pair around a 0x10-byte scratch object obtained
 * from SAVE_CONTROL_GetBlock(id 0x40); MISC_SAVEDATA_GetBigBlockSize hands back the constant 0x6204,
 * which MISC_SAVEDATA_ClearBigBlock uses as the zero-fill size for the whole object;
 * MISC_SAVEDATA_EmptyHook is an empty hook; MISC_SAVEDATA_GetScratchBase hands out the address 0x6000
 * bytes into the object; MISC_SAVEDATA_GetFlags6200/MISC_SAVEDATA_SetFlags6200 are a plain word
 * getter/setter on the field at +0x6200; MISC_SAVEDATA_GetMacSize returns the constant
 * 0x5c, which MISC_SAVEDATA_ClearMacArea's tail call to MI_CpuFill8 also uses directly
 * (the same 0x5c constant this compiler would otherwise route through
 * MISC_SAVEDATA_GetMacSize, but the tail call inlines it); MISC_SAVEDATA_GetBlock41 tail calls
 * SAVE_CONTROL_GetBlock(sys, 0x41); MISC_SAVEDATA_InitMac zero-fills a separate 0x5a-byte
 * scratch object and hands it to OS_GetMacAddress.
 *
 * Four of the twelve carry no label in the generated listing: they are
 * two- and three-instruction leaves with no register-saving prologue, so
 * disasm.py's sweep never fires on them and the listing prints them as a
 * run of .word data between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * This file merges what used to be four single-function files
 * (MISC_SAVEDATA_SaveScratch16.c, MISC_SAVEDATA_LoadScratch16.c, MISC_SAVEDATA_GetBigBlockSize.c, MISC_SAVEDATA_InitMac.c) and
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

void MISC_SAVEDATA_SaveScratch16(void *sys, void *src)
{
    void *obj = SAVE_CONTROL_GetBlock(src, 0x40);
    MIi_CpuCopy32(sys, obj, 0x10);
}

void MISC_SAVEDATA_LoadScratch16(void *sys, void *dest)
{
    void *obj = SAVE_CONTROL_GetBlock(sys, 0x40);
    MIi_CpuCopy32(obj, dest, 0x10);
}

u32 MISC_SAVEDATA_GetBigBlockSize(void)
{
    return 0x6204;
}

void MISC_SAVEDATA_ClearBigBlock(void *dest)
{
    MI_CpuFill8(dest, 0, MISC_SAVEDATA_GetBigBlockSize());
}

void MISC_SAVEDATA_EmptyHook(void)
{
}

void *MISC_SAVEDATA_GetScratchBase(void *obj)
{
    return (u8 *)obj + 0x6000;
}

u32 MISC_SAVEDATA_GetFlags6200(const void *obj)
{
    return *(const u32 *)&((struct Obj17085 *)obj)->f6200;
}

void MISC_SAVEDATA_SetFlags6200(void *obj, u32 value)
{
    ((struct Obj17086 *)obj)->f6200 = value;
}

u32 MISC_SAVEDATA_GetMacSize(void)
{
    return 0x5c;
}

void MISC_SAVEDATA_ClearMacArea(void *dest)
{
    MI_CpuFill8(dest, 0, 0x5c);
}

void *MISC_SAVEDATA_GetBlock41(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, 0x41);
}

void MISC_SAVEDATA_InitMac(void *obj)
{
    MI_CpuFill8(obj, 0, 0x5a);
    OS_GetMacAddress(obj);
}
