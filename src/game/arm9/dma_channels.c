/*
 * file:     dma_channels.c
 * unit:     yes
 * function: DMA_UpdateChannels, DMA_ProgramChannel
 * address:  0x02050A70
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from particle.c by tools/splitfile.py.
 *
 * symbols:
 *   g_pDmaChannels     0x02146A84  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */
#include "billboard_act_shared_types.h"
#include "../sdk_ioreg.h"

/* ---- DMA channel bank (not billboard code, see misplaced.tsv) ---- */

/* Software copy of one DMA channel (16 bytes); the bank has four. */
typedef struct DmaChannel {
    u32 srcAddr;
    u32 dstAddr;
    u32 control;                /* packed: bit 1 irq, bit 5 width, 7-8 src, 9-10 dst, 11.. count */
    u32 dirty       : 1;        /* bit 0 of +0x0C */
    u32 programmed  : 1;        /* bit 1 */
    u32 reprogram   : 1;        /* bit 2 */
    u32             : 29;
} DmaChannel;

#define REG_DMA_CNT(ch) (*(volatile u32 *)(REG_DMA0CNT_ADDR + (ch) * 12))

#include "../sdk_os.h"
#include "os_system.h"


void DMA_UpdateChannels(void);

void DMA_ProgramChannel(u32 channel);

extern DmaChannel *g_pDmaChannels;

/*
 *           02050A70..02050B14 - BOTH unresolved sites are the `bl` to it,
 *           and this function holds the only two branches to 0x02050B14 in
 *           the whole image, so `label` has nothing to point at and no cut
 *           frees it.  It closes only when 0x02050B14 itself has a shard
 *           entry, and that body is the one-register allocator residue
 *           written up in docs/notes/pkt_02050A70.c.txt (44 differing bytes,
 *           no source reaches it).  Chain row.
 *
 *           All 164 concrete bytes reproduce, including the third site
 *           (g_pDmaChannels, literal x5).  The counter is `int`, not `u32`: the
 *           loop's back edge is `blt`.
 *
 * Sweep the four 16-byte slots of the global bank at 0x02146A84 and retire
 * the ones whose state bits say so: a slot whose bit 0 of +0x0C is set has it
 * cleared, and if it is still busy (bits 11.. of +0x08) its teardown routine
 * runs and the "torn down" bit (bit 1) is set; a slot whose bit 2 is set has
 * it cleared and the teardown routine runs.  The bank pointer is re-read
 * after every store (`ldr r0, [r5]`), which is what the repeated reads say:
 * the store can alias the global itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/DMA_UpdateChannels.c \
 *       --func DMA_UpdateChannels --addr 0x02050A70 --cc 1.1p1 --arm
 */
void DMA_UpdateChannels(void)
{
    int i;

    if (g_pDmaChannels == 0)
        return;

    for (i = 0; i < 4; i++) {
        if (g_pDmaChannels[i].dirty) {
            g_pDmaChannels[i].dirty = 0;
            if (g_pDmaChannels[i].control >> 11) {
                DMA_ProgramChannel(i);
                g_pDmaChannels[i].programmed = 1;
            }
        }
        if (g_pDmaChannels[i].reprogram) {
            g_pDmaChannels[i].reprogram = 0;
            DMA_ProgramChannel(i);
        }
    }
}

/*
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
void DMA_ProgramChannel(u32 channel)
{
    u32 state = OS_DisableInterrupts();
    u32 v = g_pDmaChannels[channel].control;

    REG_DMA_CNT(channel) =
        ((v << 30) >> 31) << 30 |
        ((v << 26) >> 31) << 26 |
        ((v << 23) >> 30) << 23 |
        ((v << 21) >> 30) << 21 |
        (v >> 11);

    OS_RestoreInterrupts(state);
}
