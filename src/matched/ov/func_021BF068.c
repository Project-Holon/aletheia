/*
 * function: func_021BF068
 * address:  0x021BF068
 * packet:   pkt_021BF068
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203C3EC  0x0203C3EC  arm
 *
 * Channel-id predicate: true when func_0203C3EC() answers 3, 4 or 5.
 * `push {r3, lr}; blx; cmp r0, #3; beq; cmp r0, #4; beq; cmp r0, #5; bne;
 * movs r0, #1; pop; movs r0, #0; pop`.
 *
 * Now EXACT*.  The old blocker (0x0203C3EC had no witness) is gone: it was
 * matched in arm9 (src/matched/func_0203C3EC.c, shard pkt_0203C3EC), so
 * `attest_matched` resolves the BLX field.  The remaining residue was codegen:
 * the old `v == 3 || v == 4 || v == 5` source folded to a range test, and a
 * chain of separate `if`s oriented the true arm last.  A bare `switch (v)`
 * with fallthrough case labels 3/4/5 lays the true arm out first, exactly as
 * the original does; the 26 bytes all agree.  The inferred extent ran to 28
 * because the next function (0x021BF082) has no func_ label.
 */

typedef int BOOL;

extern int func_0203C3EC(void);

BOOL func_021BF068(char *a0)
{
    int v = func_0203C3EC();

    switch (v) {
    case 3:
    case 4:
    case 5:
        return 1;
    }
    return 0;
}
