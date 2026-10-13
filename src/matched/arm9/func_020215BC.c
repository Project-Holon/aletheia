/*
 * unit:     no
 * function: PALANM_CopyToSlot
 * address:  0x020215BC
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *
 * Copy the same source halfwords into both buffers of one palette-animation
 * slot at the same halfword offset.  The offset is scaled once (`lsls r4,
 * r3, #1`) and reused for both destinations, which is the `u16 *` pointer
 * arithmetic rather than a byte offset the caller already doubled.
 *
 * The fifth argument is a `u16` on the stack, read with `ldrh` at [sp,#0x18]
 * behind six pushed registers, and widened into the copier's `u32` length.
 *
 * EXACT*: the next function at 0x020215EC follows immediately with no label gap in the walk.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_CopyToSlot.c \
 *       --func PALANM_CopyToSlot --addr 0x020215BC --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct PalAnmSlot {
    u16 *unk_00;
    u16 *unk_04;
    u32  size;
    u32  unk_0c;
    u32  unk_10;
};

extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);

void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx,
                   u32 off, u16 size)
{
    MIi_CpuCopy16(src, slots[idx].unk_00 + off, size);
    MIi_CpuCopy16(src, slots[idx].unk_04 + off, size);
}
