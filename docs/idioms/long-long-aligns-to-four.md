# long long aligns to four inside a struct, so a u64 field can sit at a 4-aligned offset

summary: this front end gives `long long` an alignment of four, not eight, so a
pair of words at an offset like +0x24 or +0x624 is one `u64` field and a
two-`str` sequence is one assignment rather than two.

Found in: `src/matched/unit_020089A8.c` (0x02008A44),
`src/matched/unit_02008B4C.c` (0x02008B9C)

`sizeof(struct { u32 a; u64 b; })` is **twelve** under `dsi/1.1p1`, not sixteen.
That is worth knowing before declaring any struct, because the obvious AAPCS
assumption inserts four bytes of padding that are not in the original and every
field after the `u64` then lands at the wrong offset.

The consequence for reading the disassembly is that a pair of adjacent words at
an offset that is 4 mod 8 can still be one 64-bit field. The getter at
0x02008A44 is the clean case:

```
ldr  r1, [pc, #8]      /* 0x624 */
ldr  r2, [r0, r1]
adds r1, r1, #4
ldr  r1, [r0, r1]
adds r0, r2, #0
bx   lr
```

Four instructions plus a move, and the move is the tell: `r0` is still the
object pointer when the low half is loaded, so the low half goes to a scratch
register and only reaches `r0` once the second load is done. That is

```c
u64 sub_02008A44(const struct Obj *obj)
{
    return obj->unk624;          /* u64 unk624; at offset 0x624 */
}
```

Written as two `u32` fields recombined by hand,
`obj->unk624 | ((u64)obj->unk628 << 32)`, the compiler materialises a zero for
the high half of the first operand and emits an `orrs` pair: 28 bytes instead of
16.

The same field also explains `s->unk24 = RTC_ConvertDateTimeToSecond(...)` in
`sub_02008B9C` compiling to two plain `str`s at +0x24 and +0x28 with no
alignment fuss at all.

A struct that stores the halves separately and reads them as one is a `union` of
the `u64` and a two-`u32` struct; `sub_02008A34` and `sub_02008A44` in
`unit_020089A8.c` are that pair, and the union costs nothing in the output.
