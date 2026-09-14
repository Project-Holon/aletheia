# A shared early-return block across several calls only appears when they are one source-level `||`/`&&`, not an equivalent sequence of ifs

summary: `if (a || b || c) return 0;` tail-merges the early return for every
operand but the last into one shared block; the algebraically equivalent
`if (a) return 0; if (b) return 0; if (c) return 0;` does not merge at all,
and grouping only some of the operands into a smaller `||` still leaves the
last operand of that smaller group with the odd-one-out codegen.

Found in: src/matched/unit_02013CC8.c (0x02013D34), src/matched/unit_02013DF0.c (0x02013E04)

Both functions call several boolean-returning externs and return early once
one of them is true (or, for 0x02013E04, once none of them is). The original
bytes show a `bne`/`beq` from every call but the last branching to one shared
copy of `movs r0, #0/1; pop {...}`, while the last call's own comparison
result stands directly for the whole expression instead of branching past a
shared block.

Trying this as a flat sequence of `if (x) return v;` statements gives every
comparison its own copy of the return, `->` wrong size and no shared block at
all. Trying it as two smaller groups (say the first three operands in one
`||`, the last two as separate `if`s) reproduces the merge for the first
group but puts the *new* group boundary's last member in the odd position,
not the original's last operand. The only phrasing that reproduces the
original is a single `||` (or `&&`) expression spanning every operand that
is supposed to share the block, in the same order the original calls them.

The general rule: whichever operand is syntactically last in one `||`/`&&`
expression gets the short-circuit "its result is the expression's result"
codegen; every earlier operand in that same expression shares one tail-merged
branch target. Reproducing a chain of early-returns-on-any-match therefore
means finding the right grouping first, not assuming the whole chain is
either one expression or none.
