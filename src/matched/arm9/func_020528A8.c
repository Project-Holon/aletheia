/*
 * function: SPL_EMITTER_AllocPlttVramDefault
 * address:  0x020528A8
 * packet:   pkt_020526A8
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SPL_EMITTER_AllocPlttVramList  0x020528D0  arm
 *   SPL_EMITTER_AllocPlttVram  0x02052F58  arm
 *
 * A twelve-byte tailcall thunk: forward r0 to 0x020528D0 and pass the
 * address of SPL_EMITTER_AllocPlttVram as the second argument.  mwcc emits a tail call as
 * a pool word plus `bx ip`, and for two pool words the 1.2 front end issues
 * the callee load into ip first, then the argument load; 1.1p1 issues them in
 * the other order (the documented tail-call schedule gap,
 * docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write.md),
 * so this row needs the packet's 1.2 pin as well.
 *
 * The callback site resolves through the `matched` class once
 * src/matched/SPL_EMITTER_AllocPlttVram.c is in the manifest: this row is filed after
 * that entry, and it is the second half of the pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocPlttVramDefault.c \
 *       --func SPL_EMITTER_AllocPlttVramDefault --addr 0x020528A8 --arm --cc ../1.2/sp2
 */

typedef unsigned int u32;

extern void SPL_EMITTER_AllocPlttVramList(u32 a0, void *cb);
extern int SPL_EMITTER_AllocPlttVram(u32 a0, u32 a1);

void SPL_EMITTER_AllocPlttVramDefault(u32 a0)
{
    SPL_EMITTER_AllocPlttVramList(a0, (void *)SPL_EMITTER_AllocPlttVram);
}
