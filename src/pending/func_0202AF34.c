/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_0202AF34
 * address:  0x0202AF34
 * packet:   pkt_0202AF34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * A bare tail-call thunk to func_0202AF74 (ldr r3, pool; bx r3; .word
 * 0x0202AF75).  Blocked at MATCH on `literal`: the pointer word 0x0202AF75
 * appears in exactly one literal pool image-wide, this thunk's own at
 * 0x0202AF38, so the ABS32 site has no outside witness.  There is no branch
 * to 0x0202AF74 anywhere else in the image either, so the `label` class is
 * empty too.  Closes when func_0202AF74 acquires a manifest entry that is
 * not this file's own (a second reader of the thunk, or a matched
 * func_0202AF74 elsewhere).
 */
