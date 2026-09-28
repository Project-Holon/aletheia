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
 * function: sub_0200560C, sub_02005610, sub_02005624, sub_02005640,
 *           sub_02005654, sub_0200566C
 *
 * symbols:
 *   sub_02005610_Sys  0x020AA194  data
 *   func_02030D28     0x02030D28  arm
 *   func_02030DA8     0x02030DA8  arm
 *
 * Six functions on the one system record at 0x020AA194 that the whole of this
 * packet reaches its state through.  Three of the six carry no label, because
 * they save nothing: sub_0200560C is two bytes of `bx lr` padded to four, the
 * empty hook shape
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md records;
 * sub_02005610 is a tail call through a pool word; and sub_02005654 is a two
 * arm register-and-return.
 *
 * sub_02005640 calls the hook at +8 with the argument at +0 when the hook is
 * present, sub_02005654 installs the pair only when the slot is free, and
 * sub_0200566C clears both.  In all three the store to +8 comes before the
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

extern void  func_02030D28(void *heap);
extern void *func_02030DA8(void *heap, u32 a, u32 b, u32 c);

void sub_0200560C(void)
{
}

void sub_02005610(void)
{
    func_02030D28(sub_02005610_Sys.unk10->unk18);
}

void *sub_02005624(u32 a, u32 b, u32 c)
{
    return func_02030DA8(sub_02005610_Sys.unk10->unk18, a, b, c);
}

void sub_02005640(void)
{
    if (sub_02005610_Sys.unk08 != 0) {
        sub_02005610_Sys.unk08(sub_02005610_Sys.unk00);
    }
}

u32 sub_02005654(void (*fn)(void *), void *arg)
{
    if (sub_02005610_Sys.unk08 != 0) {
        return 0;
    }
    sub_02005610_Sys.unk08 = fn;
    sub_02005610_Sys.unk00 = arg;
    return 1;
}

void sub_0200566C(void)
{
    sub_02005610_Sys.unk08 = 0;
    sub_02005610_Sys.unk00 = 0;
}
