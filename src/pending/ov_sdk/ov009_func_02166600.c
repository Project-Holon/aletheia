/*
 * function: func_02166600
 * address:  0x02166600
 * packet:   pkt_ov009_02166600
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (near miss: copyDest assignment hoisted above the compares, registers shifted)
 * blocker:  1.1p1 store-motion hoists the shared case-1/default `copyDest = sendBuf`
 *           (`mov r6,r1`) above both compares and drops the image's fall-through `b`.
 *           The image keeps the block after the chain as the fall-through of the
 *           `cmp r0,#2 / beq case2` (cmp r0,#1 / beq <that block> / cmp r0,#2 /
 *           beq <case 2> / mov r6,r1 / b <join>).  Not a body-shape gap: with the
 *           default arm removed (copyDest left unset) the register allocation and
 *           byte-swap come out exactly right at 132 B, the only residue being the
 *           extra `b <join>` the compiler inserts for the now-unassigned unknown
 *           path; restoring the default store re-triggers the hoist.
 * u21: the defining object cpsif.o is .comment 4.0.0.1024 -> dsi/1.1p1. The image lowers
 *      `case 1:` + `default:` as cmp r0,#1 / beq <default body> / cmp r0,#2 / beq <case 2>, with the
 *      default body as the fall-through and a single `mov r6,r1`; 1.1p1 hoists that store above both
 *      compares, which is the whole 8-byte shortfall (120 vs 128). First divergence +000C
 *      image `cmp r0, #1` | ours `mov r6, r1`. Every switch spelling (case order, default alone,
 *      default first) hoists the store.
 * u1: re-measured, unchanged at 120 B vs 128 B.
 * wave7 (lane02): settled byte-swap spelling ((len & 0xff) << 8) | ((len & 0xff00) >> 8)
 *        reaches 124/128; the concrete residue is unchanged at 94 bytes.  1.1p1 still hoists
 *        the shared case-1/default `mov r6,r1` above both compares and drops the image's
 *        trailing `b`.  Every switch ordering (case/default permutations and if-chains) and
 *        the pin are invariant, so this is a canonicalisation wall, not a body-shape gap.
 * w9_nm: the object tests deviceId == 1 first, then == 2, then falls into the default mov r6,r1 without hoisting it; every switch spelling hoists mov r6,r1 above the compares (case 1 split from default, default alone, assignment before the switch, default last).
 * wave8: exhaustively re-probed the split.  Separate case-1/default arms (cross-jump
 *        candidate), if/else-if/else with the assignment duplicated in both arms,
 *        default-before-case-2 / default-after-case-2 / case-2-first source orders, an
 *        aliasing local for one arm, a void* cast on one arm, and a use of the old
 *        copyDest before the default store all compile to the SAME hoisted 124 B / 94
 *        concrete bytes.  The no-default control confirms the fix is a control-flow
 *        (store-motion) lever, not register colouring.
 * wave8b: one-trip `for(;;) { switch } break;` wrapper, `if (id == 1 || id != 2)`
 *        chain, and a cast on the stored value all still hoist to 124 B.  The arm's
 *        value is a live-parameter register copy, so it rematerialises at entry where
 *        a pool load (see two-cases-with-one-body) would not.  Filed
 *        docs/idioms/a-shared-register-copy-arm-is-hoisted-above-the-compare-chain.md.
 * wave8c: explicit `goto shared` from both `case 1` and `default` (120 B), a plain
 *        if/else-if/else with the store duplicated (124 B), and `case 2:`+`default:`
 *        only (116 B) all still hoist/shorten. Reconfirmed the pre-set `mov r6,r1`
 *        is a value-level PRE of a rematerialisable parameter copy, unreachable from
 *        any control-flow spelling. Parked.
 *
 * sdk:      WCMi_MergeToBuffer (libwcm.TWL.HYB.a cpsif.o)
 *
 * symbols:
 *   MI_CpuCopy  0x02082EA4  arm
 *
 * Merges a frame header and body into the send buffer; device 2 prefixes a byte-swapped length word.
 */

extern void MI_CpuCopy(void *src, void *dst, unsigned long size);

unsigned long func_02166600(unsigned char deviceId, unsigned short *sendBuf, void *header, unsigned long headerLen, void *body, unsigned long bodyLen)
{
    void *copyDest;
    unsigned long totalLen;
    totalLen = headerLen + bodyLen;
    switch (deviceId) {
    case 1:
    default:
        copyDest = sendBuf;
        break;
    case 2: {
        unsigned short len = (unsigned short)totalLen;
        sendBuf[6] = (unsigned short)(((len & 0xff) << 8) | ((len & 0xff00) >> 8));
        copyDest = sendBuf + 7;
        totalLen += 0xE;
        break;
    }
    }
    MI_CpuCopy(header, copyDest, headerLen);
    if (body != 0 && bodyLen != 0) {
        MI_CpuCopy(body, (unsigned char *)copyDest + headerLen, bodyLen);
    }
    return totalLen;
}
