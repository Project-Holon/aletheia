# A spilled constant high word is a u32 copied into a separate u64 before the call

summary: when the original stores a 64-bit value to an 8-byte stack pair whose high word is a
spilled constant, and a `u64` local permutes the prologue registers, the source keeps a `u32`
and copies it into a separate `u64` local just before the call that takes it.

Found in: src/matched/ov/ov121_func_021DD24C.c (0x021DD24C); twin src/matched/ov/ov010_func_02157E9C.c

Shape in the listing: a 4-aligned 8-byte pair (low word at sp+0x14, high word at sp+0x18) written
just before a call; the high word is a constant zero spilled to its slot, not a computed value.

Wrong C: `u64 id = ...;` used throughout. The 64-bit value lives in a register pair for the whole
function, other locals spill instead, and the prologue registers permute.

Right C:

```c
u32 id;
u64 id64;
...
id = ...;            /* used as 32 bits everywhere */
...
id64 = id;           /* separate copy just before the call */
func_02017588(..., id64, ...);
```

The copy's high word is the constant 0, spilled to its slot; the u32 keeps the 32-bit uses in
one register. Look for a matched twin of the routine first: the ov010 gift builder had this exact
form.
