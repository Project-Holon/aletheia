/*
 * docs/families/cluster_02083028.h -- shared declarations for the
 * pseudo-family pkt_02083028 (0x02083028, 0x020830C0, 0x02083250 in the ARM9
 * image).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Black-image addresses.
 *
 * WHAT IT IS.  TwlSDK libmi, mi_memory.o: the two hand-written block movers.
 * NONE OF THE THREE ADDRESSES IS A FUNCTION.  Each is an interior entry of a
 * single SDK `asm` function that layout/symbols_sdk.json (libmatch) already
 * matched over its WHOLE extent:
 *
 *   MI_CpuCopy  0x02082EA4, 752 bytes, 752 of 752 concrete -> ends 0x02083194
 *   MI_CpuMove  0x02083194, 788 bytes, 785 of 788 concrete -> ends 0x020834A8
 *               (the three wildcard bytes are its `bgt MI_CpuCopy` PC24)
 *
 *   0x02083028  MI_CpuCopy, forward kernel, shift 16/16     SDK bytes
 *   0x020830C0  MI_CpuCopy, forward kernel, shift 24/8      SDK bytes
 *   0x02083250  MI_CpuMove, aligned backward kernel           SDK bytes
 *
 * Disassembly, read once (match.py show):
 *   - MI_CpuCopy opens `cmp r2,#8 / bgt / rsb r3,r2,#8 / add pc,pc,r3,lsl#3`,
 *     a computed jump into an unrolled byte ladder, then dispatches on
 *     `src & 3`; 0x02082F48 is entered by `beq` at 0x02082F30, inside
 *     MI_CpuCopy, and every kernel leaves by a plain `b 0x0208314C` into the
 *     shared byte tail (listing lines 1852, 1907, 1962, 2017 of
 *     asm/arm9/src/027_02081B00.s).
 *   - MI_CpuMove is the same shape run backwards (`ldrb r3,[r0,#-1]!`), its
 *     kernels leave by `b 0x02083460` into its own shared tail.
 *   disasm.py labelled each kernel because it opens with
 *   `push {r4-r10, lr}`; the pop is `pop {r4-r10, lr}` (NOT pc) followed by a
 *   fall-through into the tail, so none of them returns.
 *
 * WHY THEY ARE OPEN AT ALL.  The worklist excludes an SDK symbol's START
 * address but splits its body at every traced `func_` label, so the interior
 * kernels surface as open game functions.  The fix is the integrator's: drop
 * the interior starts (0x02082F48 0x02082F90 0x02083028 0x020830C0
 * 0x02083250 0x02083298 0x02083334 0x020833D0) or let the SDK class cover a
 * libmatch symbol's full `size`.  No source is filed for them on purpose:
 * a fragment file would claim a function boundary the library does not have.
 * If the project wants these bytes in a shard, the honest unit is the whole
 * SDK function as one `asm` body at 0x02082EA4 / 0x02083194 (SDK addresses,
 * not this lane's territory).
 *
 * FRONT END.  Not applicable (hand-written asm).
 */

#ifndef CLUSTER_02083028_H
#define CLUSTER_02083028_H

typedef unsigned int u32;

/* TwlSDK prototypes (mi_memory.h). */
extern void MI_CpuCopy(const void *src, void *dest, u32 size);   /* 0x02082EA4 */
extern void MI_CpuMove(const void *src, void *dest, u32 size);   /* 0x02083194 */

#endif /* CLUSTER_02083028_H */
