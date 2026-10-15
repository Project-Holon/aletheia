/*
 * function: DMA_ProgramChannel
 * address:  0x02050B14
 * packet:   pkt_02050A70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_pDmaChannels            0x02146A84  data
 *
 * CLOSES the two-wave wall written up at the top of docs/notes/pkt_02050A70.c.txt
 * (44 differing bytes, diagnosed there as a one-register allocator shift with
 * "no source shape that reaches it").  The diagnosis was wrong: the residue was
 * a WRONG RECORD STRIDE, not an allocation tie.  The note's reconstruction read
 * the field as `g_pDmaChannels[idx].unk_08` over 16-byte records but spelled the
 * index arithmetic so that the compiler emitted a multiply; the image emits
 * `add r1, r3, r4, lsl #4` -- a shift, because 16 is a power of two -- and
 * `mul r2, r4, r1` ONLY for the SECOND, independent 12-byte stride of the I/O
 * register address (0x040000B8 + idx * 12).  Declaring the record struct as
 * four plain u32 words (16 bytes) and subscripting it normally gives the shift,
 * and every register then falls out identical: the whole 44-byte residue was
 * downstream of that one address computation.
 *
 * Read the 3D engine's per-engine configuration word out of the slot bank and
 * repack it into the display register at 0x040000B8 + idx*12: dest bit 30 from
 * source bit 1, dest bit 26 from source bit 5, dest 23:24 from source 7:8,
 * dest 21:22 from source 9:10 and dest 0:20 from source 11:31, under an
 * interrupt-disabled critical section.
 *
 * The OR-chain ORDER is load-bearing and is the note's one surviving finding:
 * the bit-30 term is written FIRST and the bit-26 term SECOND, because the
 * compiler fully materialises the second operand of a commutative chain
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md)
 * and the image materialises the bit-26 term (`lsl #0x1a; lsr #0x1f; lsl #0x1a`)
 * while folding the other three placements into the ORs' shifter operands.
 * Written in descending destination order the four extracts come out mirrored.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DMA_ProgramChannel.c \
 *       --func DMA_ProgramChannel --addr 0x02050B14 --cc 1.1p1 --arm
 *   EXACT, 108 bytes, 3 relocation sites, all resolved.
 */

#include "../include/G_02146A84.h"

typedef unsigned int u32;

extern struct G_02146A84 *g_pDmaChannels;
extern u32  OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 s);

void DMA_ProgramChannel(u32 idx)
{
    u32 s = OS_DisableInterrupts();
    u32 v = g_pDmaChannels[idx].unk08;

    *(volatile u32 *)(0x040000B8 + idx * 12) =
        ((v << 30) >> 31) << 30 |
        ((v << 26) >> 31) << 26 |
        ((v << 23) >> 30) << 23 |
        ((v << 21) >> 30) << 21 |
        (v >> 11);

    OS_RestoreInterrupts(s);
}
