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
 * function: sub_0200E884, sub_0200E89C, sub_0200E8B0, sub_0200E8B8,
 *           sub_0200E8CC, sub_0200E8D0, sub_0200E8D8, sub_0200E8E0,
 *           sub_0200E8E8, sub_0200E8EC, sub_0200E8F8, sub_0200E904
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   func_02082A90 0x02082A90  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   func_02087C6C 0x02087C6C  arm
 *
 * alias: twelve functions on the same big object as unit_0200E938.c, all
 * working the same field at +0x6200/+0x6204.  sub_0200E884 and sub_0200E89C
 * are a copy-in/copy-out pair around a 0x10-byte scratch object obtained
 * from SAVE_CONTROL_GetBlock(id 0x40); sub_0200E8B0 hands back the constant 0x6204,
 * which sub_0200E8B8 uses as the zero-fill size for the whole object;
 * sub_0200E8CC is an empty hook; sub_0200E8D0 hands out the address 0x6000
 * bytes into the object; sub_0200E8D8/sub_0200E8E0 are a plain word
 * getter/setter on the field at +0x6200; sub_0200E8E8 returns the constant
 * 0x5c, which sub_0200E8EC's tail call to MI_CpuFill8 also uses directly
 * (the same 0x5c constant this compiler would otherwise route through
 * sub_0200E8E8, but the tail call inlines it); sub_0200E8F8 tail calls
 * SAVE_CONTROL_GetBlock(sys, 0x41); sub_0200E904 zero-fills a separate 0x5a-byte
 * scratch object and hands it to func_02087C6C.
 *
 * Four of the twelve carry no label in the generated listing: they are
 * two- and three-instruction leaves with no register-saving prologue, so
 * disasm.py's sweep never fires on them and the listing prints them as a
 * run of .word data between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * This file merges what used to be four single-function files
 * (sub_0200E884.c, sub_0200E89C.c, sub_0200E8B0.c, sub_0200E904.c) and
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
extern void  func_02082A90(void *dest, const void *src, u32 size);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void  func_02087C6C(void *obj);

void sub_0200E884(void *sys, void *src)
{
    void *obj = SAVE_CONTROL_GetBlock(src, 0x40);
    func_02082A90(sys, obj, 0x10);
}

void sub_0200E89C(void *sys, void *dest)
{
    void *obj = SAVE_CONTROL_GetBlock(sys, 0x40);
    func_02082A90(obj, dest, 0x10);
}

u32 sub_0200E8B0(void)
{
    return 0x6204;
}

void sub_0200E8B8(void *dest)
{
    MI_CpuFill8(dest, 0, sub_0200E8B0());
}

void sub_0200E8CC(void)
{
}

void *sub_0200E8D0(void *obj)
{
    return (u8 *)obj + 0x6000;
}

u32 sub_0200E8D8(const void *obj)
{
    return *(const u32 *)&((struct Obj17085 *)obj)->f6200;
}

void sub_0200E8E0(void *obj, u32 value)
{
    ((struct Obj17086 *)obj)->f6200 = value;
}

u32 sub_0200E8E8(void)
{
    return 0x5c;
}

void sub_0200E8EC(void *dest)
{
    MI_CpuFill8(dest, 0, 0x5c);
}

void *sub_0200E8F8(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, 0x41);
}

void sub_0200E904(void *obj)
{
    MI_CpuFill8(obj, 0, 0x5a);
    func_02087C6C(obj);
}
