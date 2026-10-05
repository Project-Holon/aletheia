# A `b` from one case onto the next case block is a repeated case body

summary: a switch arm that ends with `b .+2` onto the block of the following case (looks like a
fallthrough with an extra branch) is the second case's whole body, plus its `break`, written again
at the end of the first case. Cross-jumping replaces the copy with a branch to the survivor and keeps
the branch even when the survivor is laid out next.

Found in: src/matched/ov/ov177_func_021E8754.c (0x021E8754)

Original: dispatch `cmp 0; beq A; cmp 1; beq B; cmp 2; bne end`, then the case 2 block, then
`b .+2` (0xE7FF), then A (case 0), then B. Plain fallthrough `case 2: X; case 0: A` omits the
branch (2 bytes short). A `goto` to a label at case 0, a guarded `if (mode == 2)` inside a shared
`case 0: case 2:`, and an if/else chain did not give it. `case 2: X; A; break; case 0: A; break;`
gives EXACT.

Related: an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md
