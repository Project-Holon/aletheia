# A local that is only read back through masks has no width evidence in the diff, and its declared width still decides its register

summary: when every read of a scalar local goes through a mask or a cast that
truncates anyway, the declared type of the local produces no instruction of its
own, so nothing in the disassembly names it; but mwccarm still ranks the value
differently in the colouring, so getting it wrong is a register-allocation diff
with no visible cause. Search the width, do not read it.

Found in: `src/matched/sub_0201D37C.c`'s neighbours and, as the closing lever,
`docs/notes/sub_0201C4E4.c.txt` (0x0201C4E4) and
`docs/notes/pkt_0201C8BC.c.txt` (0x0201C8BC), both on 2026-09-21.

Two functions in the printsys.c family sat at a documented, repeatedly
re-measured DIFF for three waves each, and both closed on one word.

`func_0201C4E4` packs the caller's text colour into a 5-5-5 halfword, keeps it
across the whole scheduler loop, and unpacks it again at the end:

```c
saved = (u16)(((col[2] & 0x1F) << 10) | ((col[1] & 0x1F) << 5) | ...);
...
func_0201DD78((u8)((saved >> 10) & 0x1F), (u8)((saved >> 5) & 0x1F),
              (u8)(saved & 0x1F));
```

Every write truncates with an explicit `(u16)` and every read masks with
`0x1F`, so `s32 saved` and `u16 saved` compute the identical value and neither
emits a conversion the other does not. The disassembly cannot tell them apart.
They are nonetheless 13 bytes apart: with `s32` the compiler interleaves the
two record loads into the packing sequence, with `u16` it finishes the packing
and stores it first, because the narrower value must be truncated before it can
be spilled to its halfword home. 25 concrete bytes out becomes 12.

`func_0201C8BC` splits a 5-5-5 halfword the other way:

```c
hi  = (u8)((v >> 10) & 0x1F);
mid = (u8)((v >>  5) & 0x1F);
lo  = (u8)( v        & 0x1F);
func_0201DE18(hi, mid, lo);
```

The `(u8)` casts already truncate, so `u8 hi` and `int hi` again emit the same
instructions. Declaring `hi` and `mid` as `int` rather than `u8` takes the
function from 36 concrete bytes out to 17: the note had recorded the residue as
"a pure allocator tie" after measuring source order, reverse order, a shared
`u16 v` against three inlined reads, every permutation of the three names, and
`int v` against `u16 v` — every axis except the width of the destinations.
`lo` is indifferent either way, which fits: it is the one whose value never
needed a home of its own.

Why the allocator cares at all: mwccarm's spill cost is
`flow_weight * (2 * uses + definitions)` and values take the lowest legal
colour in simplify order, so a value's width changes where its home is, whether
a truncation has to happen before a spill, and hence the order values are
created in the optimised IR. None of that is visible as an instruction.

**The practical rule.** When a residue is a register or slot permutation with
the right instruction multiset, and the usual levers (declaration order,
statement order, operand order, binding subexpressions to locals) all land on
exactly the same byte count, stop searching order and search *type*. Every
scalar local whose every read is masked or cast is a free variable:
`u8`/`u16`/`u32`/`int`/`s16` are all candidates and the diff will not hint at
which. `tools/permuter.py --types` generates exactly this mutation
(`type:l(name:from->to)`) and found both of the cases above in a single
800-compile hill run each, after two hand passes apiece had missed them — a
human reading the disassembly cannot see the axis, which is precisely why it
is worth spending a tool run on.
