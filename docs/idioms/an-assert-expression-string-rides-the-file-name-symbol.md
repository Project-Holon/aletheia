# A GF_ASSERT expression string is an offset into the file-name symbol, not a symbol of its own

summary: the one-character `"0"` that `GF_ASSERT(0)` passes as its third
argument is usually pooled by exactly one function and is too short for the
`string` class, so declaring the translation unit's string area as one object
whose second member starts just past the file name puts both relocations on the
file-name address, which has witnesses everywhere.

Found in: src/matched/sub_0204C8E4.c (0x0204C8E4)

`GF_ASSERT(0)` compiles to `GF_AssertFail(__FILE__, __LINE__, "0")`, three
arguments from three pool words:

```
  ldr r0, [pc, #0x10]      ; 0x020A7F74  "calct.c"
  ldr r1, [pc, #0x10]      ; 5204
  ldr r2, [pc, #0x10]      ; 0x020A7F7C  "0"
  bl  #0x2034714
```

The file-name string is shared by every assertion in its translation unit, so it
is pooled dozens or hundreds of times image-wide and resolves `literal` at once.
The expression string is not: `"0"` is emitted once per translation unit, and a
translation unit with a single `GF_ASSERT(0)` in it pools that address exactly
once, inside the very function being compared. `literal` then has nothing
outside the range, and the `string` class does not rescue it either, because the
run is one character long, under `MIN_STRING_CHARS`. Declared as its own symbol
the site can only ever be `MATCH`.

It is not its own symbol. The two strings are consecutive members of the same
translation unit's string area, and the file name's length is readable from the
image outside the compared range:

```c
struct AssertStrings {
    char file[8];       /* "calct.c" plus its terminator */
    char expr0[4];      /* "0" plus padding to the next word */
};
extern const struct AssertStrings s_FileName;   /* 0x020A7F74 */

    GF_AssertFail(s_FileName.file, 5204, s_FileName.expr0);
```

Both pool words are unchanged; both relocations now name 0x020A7F74, which has
92 witnesses, and the `+8` comes from the declared type rather than from the
bytes under test. This is the same manoeuvre as
`pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md`,
applied to the string area instead of a data table.

The member sizes must be the real ones: `file[8]` is the file name's length
including its NUL, and the next member starts wherever the compiler's own
alignment put it. Get either wrong and the pool word comes out at the wrong
address, which shows up as a `DIFF` on that word and not as a bad witness.
