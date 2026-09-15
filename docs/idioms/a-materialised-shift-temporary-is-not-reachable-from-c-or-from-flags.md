# A shifted temporary the original keeps in a register is not reachable from the C, and no compiler flag moves it

summary: when the only residue is a standalone `lsl` that mwccarm folds into a
shifter operand, or the same instructions in a different slot, or two registers
swapped, the decision is made below the source text; the whole documented flag
matrix (every optimisation level, every `-opt` keyword, `-inline`, `-ipa`,
`-char`, `-enum`, `-sdatathreshold`, all nine `dsi` builds) is byte-identical to
`-O4,p`, so stop spending budget on further source spellings.

Found in: docs/notes/sub_02045EC0.c.txt (0x02045EC0),
docs/notes/sub_02040618.c.txt (0x02040618),
docs/notes/sub_0204DD08.c.txt (0x0204DD08)

## The class

Three high fan-in functions, each closed down to a residue of one decision:

* 0x02045EC0: `lsl r0, r4, #3` sits three slots later in the original than in
  every compile. Same instructions, same registers, different order.
* 0x02040618: the element pointer takes r1 and the first load r0 in the
  original, and the mirror of that in every compile. Same instructions, same
  order, two registers swapped.
* 0x0204DD08: the original materialises `head * 32` with a standalone
  `lsl r0, r3, #5` and feeds both `add r1, r1, r0` and `sub r0, r1, r0` from
  it, while the guard's own `cmp r1, r3, lsl #5` re-folds the shift from the
  source register. Every compile folds the shift into the add and the sub as
  well and emits no `lsl` at all.

## The flag matrix, and why it is closed

Compiled against the image with `tools/match.py one`, per function, all of:

```
-O4,p  -O4,s  -O4  -O3  -O2  -O1
-O4,p -inline off|on|all|auto|noauto|level=0|nobottomup
-O4,p -ipa file|function
-O4,p -char unsigned          -O4,p -enum min
-O4,p -sdatathreshold 0|8
-O4,p -opt nocse|nodeadcode|nodeadstore|nolifetimes|noloopinvariants
      |nopropagation|nostrength|nodead
```

Every `-opt` sub-keyword produces output byte-identical to plain `-O4,p`. That
is not a coincidence, it is documented in the front end's own help text:

```
Note that all options besides '-opt off|on|all|space|speed|level=...' are
for backwards compatibility; other optimization options may be superceded
by use of '-opt level=xxx'.
```

`-O4,p` *is* `-opt speed,level=4`, so every individual optimiser knob is dead
at our level, in the comma form (`-opt speed,level=4,nocse`) as well as the
separate form. There is also no `-opt noschedule` and no `-opt nopeephole` in
this front end at all: those spellings are accepted with a usage *warning* and
ignored, so a note claiming "scheduling disabled, no change" from them is
measuring nothing. The only optimiser axes that exist are the level and the
speed/space bias.

`-sdata`/`-sdata2` do not exist either; the spelling is `-sdatathreshold`, and
it changes nothing here.

Compiler builds: all nine `tools/mwccarm/mwccarm/dsi` builds (1.1, 1.1p1, 1.2,
1.2p1, 1.2p2, 1.3, 1.3p1, 1.6sp1, 1.6sp2) emit byte-identical code for all
three functions. The older non-TWL lines under `tools/mwccarm/mwccarm/1.2` and
`.../2.0` are all strictly worse (for 0x02040618: 600 and 496 bytes against the
image's 464). The pinned `dsi/1.1p1` is not merely calibrated, it is
indistinguishable from its neighbours on this code.

## The one axis that does move it: `-proc`

`-proc` selects the scheduling model, and it is the only flag that touches the
residue. For 0x02045EC0, with everything else held at `-O4,p`:

```
-proc arm946e|arm966e|arm926ej|arm9ej|v5te   lsl three slots early (our result)
-proc arm9tdmi                               same, plus a non-interworking tail
-proc arm7tdmi / v4t                         lsl lands in the original's slot,
                                             but in r1, and the two loads above
                                             it swap
-proc v5t / arm1026ej / XScale               the whole window is reordered
```

The instructions and their registers are constant across those models and only
the issue order changes, which is the proof that this residue is the
*scheduler*. It also means scheduling is reachable only through `-proc`, and
`-proc arm946e` is the hardware, so the axis is not actually free: no model
reproduces the image, and picking one that did for a single function would be
a lie about the machine.

## The two diagnostics, and what they rule out

On 0x0204DD08, to decide whether the missing `lsl` is the scheduler or the
register allocator:

* `volatile u32 span = head * 32;` does not produce a register-resident
  temporary. It produces a *stack slot*: the prologue grows from `sub sp,sp,#0xc`
  to `#0x10` and the value is stored and reloaded. So `volatile` cannot answer
  the question, and it also says there is no C-level position between "folded
  into the consumer" and "spilled to memory".
* a CodeWarrior `asm { mov span, head, lsl #5 }` block does force the register,
  and reallocates the entire function around it (488 bytes against 480, every
  callee-saved register renamed). So the barrier cannot be used to isolate the
  residue either.

Neither is acceptable in shipped C, and neither leaves the rest of the function
intact, which is the whole reason the class is closed: the fold happens during
instruction selection, before anything the source can name still exists.

## The verdict to carry forward

Per residue shape:

* same instructions, same registers, different slot: **scheduler**, reachable
  only through `-proc`, therefore not reachable at all.
* same instructions, same order, registers swapped: **allocator**, reachable
  through nothing in the matrix.
* a data-processing instruction present in the original and absent in the
  compile, with its value folded into the consumers' shifter operands:
  **instruction selection**, and the only lever is giving the value a consumer
  that cannot take a shifter operand (a `str`, a call argument, a multiply).
  That is a statement about the original's *semantics*: go looking for a
  missing third use of the value, not for a different way to spell the two uses
  you already have.

None of these is a cue to change flags. Per-TU flags are not the answer for
this class, and the harness does not need a new axis.
