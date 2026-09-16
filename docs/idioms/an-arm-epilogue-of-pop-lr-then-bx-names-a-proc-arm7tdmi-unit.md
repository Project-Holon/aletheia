# An ARM epilogue of `pop {..., lr}` then `bx lr` names a `-proc arm7tdmi` translation unit

summary: the pinned `-proc arm946e` returns by popping straight into pc, so a
function that restores lr and then branches to it was built for ARMv4T; passing
`-proc arm7tdmi` is the whole difference and it costs four bytes per function.

Found in: `src/matched/unit_0205841C.c` (0x0205841C)

The project's pinned flag set is `-proc arm946e`, an ARMv5TE core, where
`ldmia sp!, {..., pc}` already interworks and mwcc uses it for every non-leaf
return:

```
02035C04  70 80 bd e8  pop {r4, r5, r6, pc}      /* func_02035BBC, arm946e */
```

The 3D skeleton and rig library at 0x0205429C..0x020584E0 does not look like
that. Every non-leaf function there ends:

```
02058464  10 40 bd e8  pop {r4, lr}
02058468  1e ff 2f e1  bx lr
```

On ARMv4T a pop into pc does not switch instruction set, so under
`-interworking` mwcc has to restore lr and branch through it. Compiling the
same C with `--flags "-O4,p -proc arm7tdmi"` turns the four-byte-short `pop
{r4, pc}` into exactly those two instructions and the function goes from `DIFF`
to `EXACT`. Nothing else in the body changes: register allocation, scheduling
and literal pools are identical between the two `-proc` values for this code.

The `flags:` line in the house header block is per file and
`manifest --verify` honours it, so a unit built this way is filed as

```
 * flags:    -O4,p -proc arm7tdmi
```

and needs no change to the project defaults.

Two cautions. First, do not reach for this on a single stuck function: it is a
property of a whole translation unit, and the tell is that *every* non-leaf
function in the address range shows the two-instruction return while leaf
functions (which push nothing) match under either value. Second, `-proc` is the
only thing this explains. The same unit also materialises the `FX_Mul` rounding
constant 0x800 into a register instead of using the `adds` immediate, refuses
to fold the high word of a 64-bit constant multiplier, and reserves an explicit
`sub sp, sp, #4` where mwcc 1.1p1 would push a spare caller-saved register for
alignment. Those three survive every `-proc`, every `-O` level, every `dsi`
compiler version and `-align8`, so some further build difference is still
unaccounted for; see `docs/notes/func_02056460.c.txt` and
`docs/notes/func_02057E68.c.txt` for the negative results.
