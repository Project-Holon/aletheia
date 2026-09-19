/*
 * function: func_020528A8
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
 *   func_020528D0  0x020528D0  arm
 *   func_02052F58  0x02052F58  arm
 *
 * A twelve-byte tailcall thunk: forward r0 to 0x020528D0 and pass the
 * address of func_02052F58 as the second argument.  mwcc emits a tail call as
 * a pool word plus `bx ip`, and for two pool words the 1.2 front end issues
 * the callee load into ip first, then the argument load; 1.1p1 issues them in
 * the other order (the documented tail-call schedule gap,
 * docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write.md),
 * so this row needs the packet's 1.2 pin as well.
 *
 * The callback site resolves through the `matched` class once
 * src/matched/func_02052F58.c is in the manifest: this row is filed after
 * that entry, and it is the second half of the pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020528A8.c \
 *       --func func_020528A8 --addr 0x020528A8 --arm --cc ../1.2/sp2
 */

typedef unsigned int u32;

extern void func_020528D0(u32 a0, void *cb);
extern void func_02052F58(void);

void func_020528A8(u32 a0)
{
    func_020528D0(a0, (void *)func_02052F58);
}
