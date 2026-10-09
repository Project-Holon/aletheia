# unit_021F36C0 (ov039): remaining blockers

Two parts, both verify EXACT on their own (checked 2026-10-08, lane r2_16).
Merged here: old p02..p05 (one Work struct with named fields for the object returned by
func_021897BC, func_021BE674 takes (char *, int, u8, u8), func_02011428 and func_021BE4C4
prototypes unified, casts removed at the call sites).

## Boundary p01 | p02 (real gap, not a type problem)

p01 ends at 0x021F36FC and p02 starts at 0x021F3A34. The 0x338 bytes between them
(one push {r4-r7,lr} function at 0x021F36FC, pop at 0x021F39EC, plus a short tail) are not
covered by any verified function, so the merged text lays out p02 at the wrong address and
reads as DIFF. This boundary closes when the function(s) at 0x021F36FC..0x021F3A34 are matched.

## Also open

- src/game/ov039/unplaced/ov039_func_021F4A18.c is still a separate file. It follows p02 in
  address order; not merged here (outside this lane's TU list).
## Round 4 note (r4_ov11): draft of the 0x021F36FC function

The 0x338 bytes are one function, a task setup for the Work object (size 0x21F4):
func_02188D2C(a), func_02189764(a, 1, func_02188C84(a), 0x21F4), func_021BE760(h, d_021F4C18, 0),
twelve 12-byte struct copies into func_021BE480(h, 0, k) from d_021F4D60, 4D0C, 4D6C, 4D18, 4D24, 4D3C,
4D00, 4CD0, 4CDC, 4D30, 4D48, 4CE8, then a loop over 4 slots (calls to func_021BE700, 674, 6B0, 6B8, 6CC,
748 with j = i, i+4, i+8), then func_02030DA8(func_02188D30(a), func_021F3A34, a, n) stored at Work+0,
then a second loop over req/cur/slot (0x21E8/0x21EC/0x21F0) that starts at n = 3 (the last i of loop 1,
kept in r5), then sel = 0xff, idx = hold = -1, and func_02028A7C / func_02028B18 with sound 0x68A.
A draft in plain C gets the structure right but not the bytes (not injected). Open differences: the
original keeps the loop counter u8 i in r6, an int copy n in r5 (args 2 and 4 of func_021BE674/700/6B8/6CC,
not narrowed), and j = (u8)i once in r7; the draft makes the compiler merge n and i, or narrows the 4th
argument. Frame size also differs by one slot.

## Round 5 note (r5 g01): draft is 18 bytes off, only stack slot numbers differ

Best draft: scratchpad r5g01/ov039_func_021F36FC_best18.c (824 bytes, same size, same
instructions, all registers equal; 18 bytes differ, each one an sp offset). What fixed the
earlier residue (u8 i in r6, int n in r5, j once in r7, extra stack slot):

- There is no n variable in the first loop. The arguments 2 and 4 are literal 0: the compiler
  hoists the zero into r5 (copy of the zero that i starts with) and reuses it for the key
  argument of func_02030DA8 and as the counter of the second loop. Write literal 0 in the
  calls, and a separate int n only for the second loop: for (n = 0; n < 4; n++).
- i is u32 with i = (u8)(i + 1) (docs/idioms: a u8-stepped counter re-truncated at each narrow
  argument is a 32-bit counter), and a u8 j (j = i; j = i + 4; j = i + 8) gives the (u8)i pair
  once in r7.
- The pointer q + i (CSE shape ldr [sp,#0x1c]; adds r0,r0,r6; str r0,[sp,#0xc]) is a local
  u8 *p = (u8 *)q + i, read as p[0x10]; the third group reads f before j = i + 8.

Left: spill slot order. Original: x [8], p [0xc], f [0x10]/[0x14]. Draft: f [8]/[0xc], x [0x10],
p [0x14]. Declaration order of x, f, p did not move the slots; inlining x (ternary twice) made
it worse (339 lines). Needs the Work type with a task field at +0 and Save with int v[4] at +0.
Not injected (not EXACT).
