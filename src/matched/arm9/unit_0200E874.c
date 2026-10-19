/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E874
 * packet:   pkt_0200E7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: SAVE_SYNC_GetSize, SAVE_SYNC_Clear
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *
 * The twelve bytes after MISC_SAVEDATA_FillMonEntry: two unlabelled leaves that save
 * nothing at all, so their bytes print as part of the same `.word` run as
 * the pool word in front of them (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The first is a size
 * getter returning 0x10, the second is a tail call to the SDK's
 * MI_CpuFill8 (arm: the pool word is even, so `bx r3` switches to ARM) that
 * clears 0x10 bytes from whatever pointer it is handed.
 */

typedef unsigned int u32;

extern void MI_CpuFill8(void *dst, int value, u32 size);

int SAVE_SYNC_GetSize(void)
{
    return 0x10;
}

void SAVE_SYNC_Clear(void *dst)
{
    MI_CpuFill8(dst, 0, 0x10);
}
