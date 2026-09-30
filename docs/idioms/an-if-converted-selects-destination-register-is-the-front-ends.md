# The destination register of an if-converted select is the front end's, not the C's

summary: `cmp rC, #0; moveq r0, rZero; movne r0, rOne` and `cmp rC, #0;
movne r5, rOne; mov r0, r5` are the same 0/1 select over constants already
live in `r4 = 1` and `r5 = 0`; the vendor build writes both predicated moves
straight into `r0`, 1.1p1 coalesces the result onto the live zero constant and
copies to `r0`, and no ternary / if/else / enum-constant / dying-local /
return-type spelling changes the destination without also flipping which
constant lands in r4 and r5.

Found in: `src/pending/ov_sdk/ov016_func_021D3638.c` (0x021D3638,
DWCi_MOV_WH_Initialize), an ARM `ov016` SDK leaf, 120 bytes.

The function clears nine `Wh` fields and returns the boolean result of a call.
The object's tail is:

```
bl   DWCi_MOV_WH_StateInInitialize   ; 0x021D36D0
cmp  r0, #0
moveq r0, r5          ; r5 = 0, the constant the field stores used
movne r0, r4          ; r4 = 1, the constant the f52 store used
pop  {r3, r4, r5, pc}
```

Everything before `+0x68` is byte for byte, including the r4 = 1 / r5 = 0
colouring (the object sets `mov r5, #0` first, then `mov r4, #1`). 1.1p1 emits
the same compare and the same operands but makes the select's destination the
live zero register, adding a return copy:

```
cmp  r0, #0
movne r5, r4
mov  r0, r5
```

Five concrete bytes, two instructions, and the only difference is which
register the if-conversion writes.

Twenty-plus spellings were measured on the same function, all under
`dsi/1.1p1 -O4,p --arm --lang c99`. They fall into exactly two classes:

* **keep `r5 = 0` / `r4 = 1`, coalesce the select into r5** (5 bytes): the
  whole `? 1 : 0` / `!= 0` / `!!` family, `int r = 0; if (c) r = 1; return r;`,
  `int r; r = 0; if (c) r = 1; return r;`, `int r = 0; if (c) r = B_TRUE;
  return r;` with enum constants, a `Bool`-typed local, and `static` on the
  function.
* **flip the constants to `r4 = 0` / `r5 = 1`** (15 bytes, the `strh`/`str` of
  zero move to r4): every direct `return c ? 1 : 0;`, every `if`/`else` return
  or assignment in either arm order, the initialise-to-1-then-clear family, the
  `int r = c ? 1 : 0;` declaration-initialiser, and `int r = call; ...`.

The reason is visible in the source shape that stays in the first class:
`int r = 0;` merges `r`'s zero with the zero constant the field stores already
hold, so on the false path `r` *is* `r5` and the allocator coalesces the
if-converted value onto it; the return then needs the `mov r0, r5`. Any
spelling that gives `r` a different zero web (an enum zero, a later
assignment, a local that starts from the call result) instead flips the whole
constant colouring, because the 0 and 1 are then re-dealt. The vendor build's
allocator kept the select's destination `r0` (the return register) distinct
from the false operand, so it emitted two predicated writes into `r0` with no
copy; 1.1p1's if-conversion does not.

Tell: an if-converted 0/1 select whose two predicated moves both target the
return register, against a byte-identical build whose select targets one of the
constant registers plus a final copy. Before hunting a statement shape, read it
as the front-end's destination choice; no local, type, order or rotation moves
it, and the two classes above are exhaustive for the shapes tried.
