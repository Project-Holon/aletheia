# A small constant that arrives from a literal pool instead of a `movs` is not a constant at all

summary: mwccarm materialises any integer literal from 0 to 255 with `movs`,
so an argument of 0xBC that the original loads from a literal pool cannot be
written as a number in any type; it is an `R_ARM_ABS32` against a symbol whose
absolute value is small, which is what a linker-defined overlay id looks like
on this SDK.

Found in: `src/pending/unit_0200BA58.c` (0x0200BA58, 0x0200BA68)

Two eight-byte tail calls in `pkt_0200B938` read

```
0200BA58  01 48     ldr r0, [pc, #4]
0200BA5A  02 4b     ldr r3, [pc, #8]
0200BA5C  18 47     bx  r3
0200BA5E  c0 46     mov r8, r8
0200BA60  000000BC  .word
0200BA64  02034AC4  .word
```

Sixteen bytes for what looks like `return f(0xBC);`. That C compiles to twelve:

```
ldr  r3, [pc, #4]
movs r0, #0xbc
bx   r3
```

and the difference is not a near miss, it is a different kind of operand. The
Thumb `movs Rd, #imm8` reaches 0 to 255, and this front end uses it for every
literal in that range regardless of the declared parameter type: `u32`, `int`,
`void *`, `const char *`, `unsigned long` and `float` were all tried and all
six give the same twelve bytes. 0xD7, 0xA9 and 0x95 appear as `movs` elsewhere
in the same file, so the front end is not avoiding the high half of the range
either.

What does produce the pool word is a **relocation**:

```c
extern u8 ov188_id[];          /* declared at 0x000000BC in the symbols: block */

return func_02034AC4(ov188_id);
```

The compiler cannot fold an address it does not know, so it emits a pool word
and an `R_ARM_ABS32`, and the linker writes 0x000000BC into it. An address of
0xBC is not a location in the ROM; it is an absolute symbol, and 188 is a
plausible overlay number in a 237-overlay image, which is what
`FS_OVERLAY_ID()` expands to on this SDK.

The reverse reading, and it is worth having before spending an hour on
register allocation: **a literal pool word holding a value too small to be an
address is a symbol, not a number.** The function that loads it is short of a
declaration, not short of a source shape.

What this costs is attestation. 0x000000BC appears in no other literal pool in
the 3.9 MB image, so the `literal` class discards its only witness under the
honesty rule, and no cut helps because shrinking the range to the one function
keeps that function's own pool word inside it. Both functions reproduce every
concrete byte and stay at MATCH; they are parked in `src/pending/`.
