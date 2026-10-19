# The block constant in a callee-saved register follows the order of the stores

summary: Which constant of a block gets the callee-saved register depends on the order of the
stores that use it. A store that needs an address temp weighs more. Reorder the literal stores.

Seen in wave D8 lane 06 (2026-10-05): ov168 func_02184398 and ov172 func_021B8CC8, both closed EXACT.

## Symptom

mwcc keeps one constant of a basic block in a callee-saved register and builds
the other constants with movs, or derives them from that register with
`adds`/`subs`. The image holds constant A in the register (for example 0x120 in
r6, or 1 in r7). The build holds constant B there, or keeps no constant at all.
The rest of the function then shifts: other values change registers, the frame
size changes, spill slots move.

## What decides it

The order of the statements that use the constants, not only the number of
uses. A store that needs an address temp (an offset that is too large for the
immediate field) has a different weight from a store with a direct offset. The
position of that store relative to the other constant stores changes which
constant gets the register.

Do not use an enum-typed or volatile local to keep the constant. Reorder the
plain literal statements to match the image. Look at the image for the order of
the stores, and keep in mind that the scheduler can move stores.

## Cases

- ov168 02184398: `Alloc(heap, 0x120); memset(buf, 0, 0x120);` then the field
  stores. The image keeps 0x120 in r6 and writes 0x100 as `subs r6,#0x20`.
  With the `p+8 = 0x100` store written last, 1 wins and the build writes 0x100 as
  `adds r0,#0xff` (108 bytes, the wrong size). With the 0x100 store written right
  after the aligned-pointer store (+4), 0x120 wins and the function is EXACT.
  Earlier lanes needed `enum { SZ = 0x120 } size;` to keep 0x120 (a stand-in).
- ov172 021B8CC8: the join block has many zero stores and several uses of 1.
  The image keeps 1 in r7. The stores `p+0xA4 = 0; p+0 = 0; p+8 = 0;` (the 0xA4
  store needs `adds r1,#0xa4`) gave 0 the register and a 417-byte residue.
  Written as `p+0 = 0; p+8 = 0; p+0xA4 = 0;` (address-temp store last), 1 wins
  r7, and the scheduler restores the image order (0xA4 first). EXACT.

## How to search

List the stores of the block in the image order. Move the store that needs an
address temp (or the store of the constant that should derive another constant)
to the end of its group, or next to the store whose constant should win, and
test each position. Check that the scheduler restores the image order.
