/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E8B8
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200E8B8, sub_0200E8CC, sub_0200E8D0, sub_0200E8D8,
 *           sub_0200E8E0, sub_0200E8E8, sub_0200E8EC, sub_0200E8F8
 *
 * symbols:
 *   sub_020071CC  0x020071CC  thumb
 *   MI_CpuFill8   0x02082BCC  arm
 *
 * alias: eight functions on a big object with a field at offset 0x6200.
 * sub_0200E8B8 zero-fills 0x6204 bytes at a caller-given pointer;
 * sub_0200E8CC is an empty hook, never filled in; sub_0200E8D0 hands out the
 * address 0x6000 bytes into the object; sub_0200E8D8/sub_0200E8E0 are a
 * plain word getter/setter on the field at +0x6200; sub_0200E8E8 returns the
 * constant 0x5c, which sub_0200E8EC's tail call to MI_CpuFill8 also uses
 * directly (the same 0x5c constant this compiler would otherwise route
 * through sub_0200E8E8, but the tail call inlines it); sub_0200E8F8 tail
 * calls sub_020071CC(sys, 0x41).  Four of the eight carry no label in the
 * generated listing: they are two- and three-instruction leaves with no
 * register-saving prologue, so disasm.py's sweep never fires on them and the
 * listing prints them as a run of .word data between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E8B8.c \
 *       --addr 0x0200E8B8 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *sub_020071CC(void *sys, u32 id);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);

extern u32 sub_0200E8B0(void);

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
    return *(const u32 *)((const u8 *)obj + 0x6200);
}

void sub_0200E8E0(void *obj, u32 value)
{
    *(u32 *)((u8 *)obj + 0x6200) = value;
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
    return sub_020071CC(sys, 0x41);
}
