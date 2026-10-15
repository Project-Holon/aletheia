/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x0200560C
 * packet:   pkt_020051D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_NoOpFrameHook, GFL_USE_RunHBlankTasks, GFL_USE_AddHBlankTask, GFL_USE_CallVBlankHook,
 *           GFL_USE_SetVBlankHook, GFL_USE_ClearVBlankHook
 *
 * symbols:
 *   sub_02005610_Sys  0x020AA194  data
 *   TCB_Main     0x02030D28  arm
 *   func_02030DA8     0x02030DA8  arm
 *
 * Six functions on the one system record at 0x020AA194 that the whole of this
 * packet reaches its state through.  Three of the six carry no label, because
 * they save nothing: GFL_USE_NoOpFrameHook is two bytes of `bx lr` padded to four, the
 * empty hook shape
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md records;
 * GFL_USE_RunHBlankTasks is a tail call through a pool word; and GFL_USE_SetVBlankHook is a two
 * arm register-and-return.
 *
 * GFL_USE_CallVBlankHook calls the hook at +8 with the argument at +0 when the hook is
 * present, GFL_USE_SetVBlankHook installs the pair only when the slot is free, and
 * GFL_USE_ClearVBlankHook clears both.  In all three the store to +8 comes before the
 * store to +0, which is the source order.
 *
 * The record's +0x10 is the object src/matched/unit_020056A0.c calls its
 * heaps; the two files name it separately because each pins its own address
 * block.  The range stops at 0x0200567C because sub_0200567C is held open by
 * one unresolved call site; see the near miss register in the header of
 * src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200560C.c \
 *       --addr 0x0200560C --thumb
 */

typedef unsigned int u32;

struct Sub02005610Heaps {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    u32   unk0C;
    u32   unk10;
    u32   unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

struct Sub02005610Sys {
    void *unk00;
    u32   unk04;
    void (*unk08)(void *);
    u32   unk0C;
    struct Sub02005610Heaps *unk10;
    void *unk14;
};

extern struct Sub02005610Sys sub_02005610_Sys;

struct Ctx;
struct Node;
extern void TCB_Main(struct Ctx *c);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);

void GFL_USE_NoOpFrameHook(void)
{
}

void GFL_USE_RunHBlankTasks(void)
{
    TCB_Main(sub_02005610_Sys.unk10->unk18);
}

void *GFL_USE_AddHBlankTask(u32 a, u32 b, u32 c)
{
    return func_02030DA8(sub_02005610_Sys.unk10->unk18, a, b, c);
}

void GFL_USE_CallVBlankHook(void)
{
    if (sub_02005610_Sys.unk08 != 0) {
        sub_02005610_Sys.unk08(sub_02005610_Sys.unk00);
    }
}

u32 GFL_USE_SetVBlankHook(void (*fn)(void *), void *arg)
{
    if (sub_02005610_Sys.unk08 != 0) {
        return 0;
    }
    sub_02005610_Sys.unk08 = fn;
    sub_02005610_Sys.unk00 = arg;
    return 1;
}

void GFL_USE_ClearVBlankHook(void)
{
    sub_02005610_Sys.unk08 = 0;
    sub_02005610_Sys.unk00 = 0;
}
