# A bitfield's base type shows up as a redundant truncation of the stored value

summary: a `u8`-based bitfield narrows the incoming value to eight bits before
shifting it into place, even when the shift pair would discard those bits
anyway; a `u32`-based bitfield of the same width and position does not, so one
otherwise pointless `and rX, rX, #0xff` names the declared base type.

Found in: `src/matched/unit_0204B22C.c` (0x0204B22C) and
`src/matched/unit_0204B570.c` (0x0204B570)

Two setters, both writing a small unsigned bitfield from a `u32` parameter,
both in the same translation unit, differ by exactly one instruction that does
nothing.

0x0204B22C writes a four-bit field at bits 4..7 of a byte:

```
ldrb r2, [r0, #0xe]
and  r1, r1, #0xff          <- the tell
lsl  r1, r1, #0x1c
bic  r2, r2, #0xf0
orr  r1, r2, r1, lsr #24
strb r1, [r0, #0xe]
```

0x0204B570 writes a two-bit field at bits 18..19 of a word:

```
ldr  r3, [r0, #0x60]
lsl  r1, r1, #0x1e          <- no truncation before it
bic  r3, r3, #0xc0000
orr  r2, r3, r1, lsr #12
str  r2, [r0, #0x60]
```

The `and` in the first is dead: `lsl #0x1c` already discards everything above
bit 3. It is there because the assignment to a bitfield whose declared base
type is `u8` is two conversions, first to the base type and then into the
field, and the front end emits the first before it knows the second will make
it redundant. With a `u32` base type there is no first conversion and no
`and`.

So:

```c
struct S { u8  lo : 4; u8  hi : 4; };   /* gives the and */
struct S { u32 lo : 4; u32 hi : 4; };   /* does not */
```

The same one instruction also distinguishes the parameter's type when the base
type is already known: a `u8` parameter assigned to a `u8` bitfield emits no
`and` either, because mwccarm treats a narrow parameter as arriving already
narrowed. Only the `u8` field plus wider source combination produces it.

Reading it backwards: a redundant truncation in front of the shift says the
field's base type is narrower than the value being stored, and the width of the
truncation mask (`#0xff`, `#0xffff`) is the base type. No truncation says the
base type is at least as wide as the source. That is the only place the base
type of a bitfield is observable, since the load, the `bic` mask and the shift
amounts are all decided by the field's offset and width, not by its base type.
