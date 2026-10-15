/*
 * unit:     no
 * function: NNSi_G2dCpuLoadOamMain
 * address:  0x02063068
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02082A60  0x02082A60  arm
 *
 * An OAM-address thunk: bias the caller's byte offset into an absolute
 * main-engine OAM address and tail-call the transfer routine at
 * 0x02082A60.  A tail call is a pool word and a `bx`, never a displacement
 * branch (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * It saves nothing, so disasm.py gives it no label and it prints as a run
 * of `.word`s (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * the attesting instruction is the vtable word at 0x020A81E4, which holds
 * this address.  Seeding 0x02063068 into layout/function_starts.txt is what
 * makes the listing agree; the byte comparison is EXACT either way.
 *
 * Its sub-engine twin at 0x02063054 (vtable word 0x020A81E8, biasing by
 * 0x07000400 instead) is byte-correct but two instructions out of order:
 * 0x07000400 is not an ARM rotated immediate, so it comes out as two
 * `add`s, and every spelling tried emits the first `add` before the `ldr`
 * of the tail-call target where the original loads the target first.  The
 * one-`add` form here has no such freedom and matches exactly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dCpuLoadOamMain.c \
 *       --func NNSi_G2dCpuLoadOamMain --addr 0x02063068 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void sub_02082A60(void *src, u32 dest);

void NNSi_G2dCpuLoadOamMain(void *src, u32 offset)
{
    sub_02082A60(src, offset + 0x07000000);
}
