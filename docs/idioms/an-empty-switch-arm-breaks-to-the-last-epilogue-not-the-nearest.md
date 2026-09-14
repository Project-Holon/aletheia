# An empty switch arm's jump-table entry says whether the source wrote `break` or `return`

summary: an arm with no statements compiles to a table entry pointing straight
at an epilogue, and which epilogue it picks is the one-byte tell: `break` lands
on the function's *last* epilogue, the one the `default` body falls into, while
`return` lands on the *nearest* preceding one; everything else about the two
spellings is identical.

Found in: `src/matched/sub_02019308.c` (0x02019308)

`func_02019308` is a twelve-case setter whose last case stores nothing. Ten
arms are a single `str`/`strh`/`strb`, one is a call, and the twelfth is empty,
so its jump-table displacement has to name some epilogue. Written

```c
case 0xA7:
    sub_02008F3C((const struct Mail *)v, &p->unk9C);
    return;
case 0xA8:
    return;
```

the table's last entry is 0x005C and selects the `pop {r3, pc}` that ends case
0xA7's own body. Written

```c
case 0xA8:
    break;
default:
    func_02019388(p, id, v);
    break;
```

it is 0x0064 and selects the `pop {r3, pc}` after the forwarding call, which is
the last instruction of the function. The original is 0x0064, so the source
wrote `break`. Nothing else in the 128 bytes moves: same eleven bodies, same
eleven other displacements, same registers, one halfword apart.

The reason is that mwccarm emits the epilogue at the end of each arm that
reaches it and then lets an empty arm branch to whichever copy its own control
flow falls into; `return` is a jump to the function's return point that
cross-jumping then merges with the textually nearest copy, while `break` leaves
the switch and lands on the block after it.

The same function pins the placement of the `default` arm independently, and it
is the more expensive half to get wrong: written as a statement *after* the
switch rather than as a `default:` label inside it, the forwarding block is
laid out in front of all twelve case bodies instead of behind them, and every
one of the twelve displacements changes. `func_02018E34` in
`src/pending/sub_02018E34.c` is the mirror image, 176 entries with the
`default` body first, and there the label really is written first in the
source.
