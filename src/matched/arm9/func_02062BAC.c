/*
 * function: NNSi_G2dFixupOffsets
 * address:  0x02062BAC
 * packet:   pkt_02062B64
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The NNS G2D offset-fixup pass for one loaded block.  A block that has just
 * been read off the card stores its interior pointers as offsets from the
 * block's own start; this walks a (count, offset array) header and turns every
 * one of them into an absolute address, the array pointer itself first.  It is
 * a leaf with no relocation sites at all -- the only address it ever adds is
 * its own argument.
 *
 * Neighbour of src/matched/NNS_G2dFindBinaryBlock.c, which is the block-chain lookup
 * for the same NITRO file format; this is what the caller runs over the block
 * that lookup returns.
 *
 * FOUR THINGS THE BYTES FORCED, in the order they cost time:
 *
 *   1. THE ARRAY ELEMENT IS A POINTER, NOT A `u32`.  This is the whole
 *      residue at the end and it is worth stating plainly: the image adds the
 *      base with `add r2, r0, r2` -- the object pointer in the LEFT slot --
 *      and every spelling whose left operand is an integer gives
 *      `add r2, r2, r0` instead.  `x += (u32)t`, `x = (u32)t + x`, and the
 *      same two through a hoisted `u32 *e = &t->offsets[i]` are all identical
 *      and all wrong, because with a `u32` element the front end treats the
 *      cast object address as the addend and the loaded word as the
 *      accumulator.  Declaring the array as `u8 **` and writing
 *      `t->offsets[i] = (u8 *)t + (u32)t->offsets[i]` makes the object the
 *      POINTER operand of pointer-plus-integer, which this front end always
 *      issues left-first, and the byte falls out.  This is the pointer-typed
 *      companion to
 *      docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md
 *      and to docs/idioms/commutative-operand-order-names-the-temporary.md:
 *      operand order here names the TYPE, not the temporary.
 *
 *   2. The loop is a plain `while (t->count > i)`, not `if (n) do ... while`.
 *      The image re-reads the count with `ldrh r2, [r0]` at the BOTTOM of
 *      every iteration as well as testing it once at the top, which is what a
 *      `while` on a field (rather than on a local copy) costs; hoisting the
 *      count into a `u16 n` local loses the reload.
 *
 *   3. The top guard is `>` on the unsigned count, which is why the early exit
 *      is `cmp r1, #0 / bxls lr` and not `bxeq lr`.  Spelling it `if (n != 0)`
 *      gives the `eq` form -- one byte, and the first thing to check on this
 *      shape.
 *
 *   4. `i` is a `u16`: the `lsl r1, r1, #0x10` / `lsr ip, r1, #0x10` pair
 *      around the increment is the truncation, and the loop bound is compared
 *      against the pre-truncation value with `cmp r2, r1, lsr #16`.
 *
 * THE `../2.0/sp2` PIN.  dsi/1.1p1 with the final body is 14 concrete bytes
 * out and with the `u32` body 16; the permuter cannot close either
 * (`--explain` shows a three-way r0/r1/r2 reshuffle, `--mode hill --budget
 * 800 --types` exhausts 82 singles with no improvement, `--mode anneal
 * --budget 2000 --jobs 8 --types` never leaves the baseline).  ../1.2/sp2 is
 * 4 bytes out.  ../2.0/sp2 reproduces the image byte for byte.  The residue
 * 1.1p1 leaves is the prologue schedule -- it hoists the `ldrh` of the count
 * above the `add`/`str` of the array pointer and pushes the `mov ip, #0` down
 * past the compare -- which is the same scheduling family as the cluster's
 * other 2.0 rows.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dFixupOffsets.c \
 *       --func NNSi_G2dFixupOffsets --addr 0x02062BAC --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 72 = original 72, 0 relocation sites
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Tbl {
    u16   count;                /* 0x00  number of offsets, read with ldrh   */
    u16   pad02;
    u8  **offsets;              /* 0x04  itself an offset until fixed up     */
};

void NNSi_G2dFixupOffsets(struct Tbl *t)
{
    u16 i;

    t->offsets = (u8 **)((u8 *)t->offsets + (u32)t);
    i = 0;
    while (t->count > i) {
        t->offsets[i] = (u8 *)t + (u32)t->offsets[i];
        i = i + 1;
    }
}
