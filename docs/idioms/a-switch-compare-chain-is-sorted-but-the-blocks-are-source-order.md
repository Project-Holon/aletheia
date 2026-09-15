# A switch compare chain is sorted by case value, but the blocks stay in source order

summary: for a switch too sparse for a jump table, the `cmp`/`beq` chain is
emitted in ascending case order no matter how the source orders the arms, so
only the block layout tells you the source order; and `case 0:` falling into
`default:` is what produces the leading compare against zero.

Found in: docs/notes/func_0203FCA0.c.txt (0x0203FCA0)

The inner switch of the BG-layer initialiser dispatches three layer types with
a compare chain rather than a table:

```
    0203FDCC  cmp r4, #0
    0203FDD0  beq #0x203fde4        <- the type 0 / default block, immediately below
    0203FDD4  cmp r4, #1
    0203FDD8  beq #0x203fe14
    0203FDDC  cmp r4, #2
    0203FDE0  beq #0x203fe3c
    0203FDE4  ...                   <- fall-through lands in the first block
```

Two things are easy to get wrong here.

The compare order is not evidence of source order. Writing the arms as
`case 1`, `case 2`, `case 0/default` compiles to the identical chain
`cmp #0 / cmp #1 / cmp #2`; only the three branch targets change, because the
blocks are laid out in the order the source wrote them. So when you are
reconstructing a compare-chain switch, read the block addresses, not the
compare sequence. Getting this backwards costs you nothing in size, which is
what makes it expensive: the function stays the right length and only the
branch displacements move.

The leading `cmp #0` is the tell for how the zero arm is spelled. Three
spellings produce three different dispatches for the same behaviour:

| source | dispatch |
| --- | --- |
| `case 0:` then `default:` on the same block | `cmp #0 / cmp #1 / cmp #2`, fall-through into that block |
| `default:` alone | `cmp #1 / cmp #2`, fall-through into that block; no compare against zero |
| `case 0:` with no `default:` anywhere | `cmp #0 / cmp #1 / cmp #2 / b`, an extra unconditional branch past the arms |

Only the first reproduces a six-instruction chain whose fall-through is the
zero arm itself. If the original has one more or one fewer instruction than
you expect right at the dispatch, this is where to look before you touch the
arms.

A consequence worth knowing when the arms end alike: the cross-jumper that
merges identical block tails runs strictly forward, from an earlier block into
a later one. Put the shared-looking arm first and its trailing store is folded
into a later arm's store; put it last and nothing merges into it. That is a
layout effect, not a source effect, and it is the reason a switch can come out
one instruction short per arm with the C otherwise exactly right.
