# A struct-return frame word also stops cross-call constant derivation

summary: when mwcc keeps a constant in a callee-saved register and derives a
later constant from it with `adds rN, #delta` across calls (for example 0x272
from an earlier 0x1f8 argument), and the original builds the later constant
fresh (pool load or `movs; lsls`), look for a callee that returns a one-word
struct or union. Its return temporary gives the function a frame word, and
with that frame word mwcc does not derive constants across the calls. The same
change fixes the prologue (`push {r4-r6, lr}; sub sp, #8` instead of
`push {r3-r7, lr}`).

Found in: src/matched/ov/ov093_func_021D4D84.c (0x021D4D84)

The function allocates a 0x1f8-byte record, reads parameters with
func_02017E1C, clamps one value with `if (p->f12 > 0x272) p->f12 = 0;`, and
stores bytes at +0x140 and +0x143 after a call that took the argument 0x9e.
With `u32 func_021D7D18(int)` the compiler keeps 0x1f8 and 0x9e in r6 and
emits `adds r6, #0x7a` (0x272) and `adds r6, #0xa5` (0x143). That costs r7 and
shifts the whole body (214 bytes differ). The image loads 0x272 from the pool,
builds 0x140 as `movs #5; lsls #6` and 0x143 as `adds r0, r1, #3`.

Measured on dsi/1.1p1 -O4,p, Thumb:

- The derivation runs over an extended basic block: a real join between the
  base and the target stops it; a dead-end branch does not.
- It does not depend on the -O level (O2 to O4), the dsi compiler version, the
  argument types (u8, u16, int, enum, unprototyped), const or static const
  limits, inline wrappers, or any branch the front end can fold away.
- An enum-typed local with an unfolded shift (`sz << 2`) removes one base,
  but it schedules the `movs` too early. Do not use it.
- Declaring the callee with its real return type, `union Slot func_021D7D18(int)`
  (the record array element is the same union), gives EXACT with the plain
  source: no constant chain, and the frame word that the image has.

So: a "constant chain" residue plus a frame that is one word too small is one
problem, not two. Fix the struct return first.
