# A goto into a shared multiply block is the multiply written in each arm

Shape: two arms load a different constant into one register (`movs r4,#0x55` and
`movs r4,#0xa; b L`) and branch to one shared multiply block. Drafts model this as
`m = 0x55; L: d = m * v;` with `m = 0xa; goto L;` in the other arm. That compiles to the
right block layout but the wrong register colours (the loaded value and the factor swap).

Source form that matches: write the whole multiply in each arm with a literal factor,
literal first: `d0 = (u16)(0x55 * W(0xC330));` and `d0 = (u16)(0xa * W(0xC330));`.
mwcc cross-jumps the identical tails after the `movs`, so the shared block appears, and
the colouring follows the per-arm code. The operand order (`K * v`, not `v * K`) also
matters: it moved the residue from 357 to 114 bytes on its own.

Closed: ov219 0x02185934 (wD9r lane81), after nine lanes of colouring tries.
