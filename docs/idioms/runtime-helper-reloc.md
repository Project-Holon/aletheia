# A compiler runtime helper is a named relocation

summary: integer division calls `_u32_div_f`, which mwccarm leaves as an
ordinary undefined reference, so it is pinned in the `symbols:` block like any
other extern.

Found in: `src/matched/unit_0200857C.c` (0x020085D4)

`a / b` on `u32` does not compile to an instruction. It compiles to a call to
the compiler's own runtime helper, and mwccarm leaves that as an undefined
reference carrying exactly the name `_u32_div_f`, so a `symbols:` line

```
_u32_div_f 0x0209C2B0 arm
```

resolves it. Nothing in the C source mentions that name; it appears only in the
object's relocation table.

The address is attested as a `label` by 57 callers elsewhere in the image, so
this is an ordinary attested lookup and not a special case in the harness.
Without the line the four calls in `sub_020085D4` are wildcards and the whole
unit caps at `MATCH`; with it the unit is `EXACT`.

Any function doing unsigned integer division needs this line. Signed `/` and
`%` call `_s32_div_f` (0x0209C0A4), which resolves by its `label` with no line.
