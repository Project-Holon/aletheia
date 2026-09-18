# A range test on a byte is written as the add of the complement, not as a sub

summary: `(u8)(v - 1) <= 3` and its neighbours compile to `sub r0, r0, #1` followed by `and r0, r0, #0xff` in one spelling and to `add r0, r0, #0xff` / `add r0, r0, #0xfd` in the original, so the constant in the source is the two's-complement add of the value the test subtracts; when the diff is a single `sub`/`add` swap with the `and` unchanged, respell the literal as `+ (256 - n)`.

Found in: src/matched/func_020392EC.c (0x020392EC), func_0203BDEC.c (0x0203BDEC)

The original of the state-byte range test is

```
ldrb r0, [r0, #0x65]
add  r0, r0, #0xff
and  r0, r0, #0xff
cmp  r0, #3
movls r0, #1
```

which is `(u8)(v - 1) <= 3`.  Written that way the compiler emits

```
sub  r0, r0, #1
and  r0, r0, #0xff
```

Two instructions either way, same semantics, four bytes of diff.  The
spelling that reproduces the original is the addition of the complement,

```c
if (g_021469D0 != 0 && (u8)(p[0x65] + 0xFF) <= 3)   /* v - 1 */
```

and `func_0203BDEC` is the same for a threshold of three, where the original's
`add r1, r1, #0xfd` / `and r1, r1, #0xff` / `cmp r1, #1` is
`(u8)(p[0x65] + 0xFD) <= 1`.

The tell is exact: a `sub`/`add` swap with the `and` mask immediate *unchanged*
(it stays 0xff, not 0x100 - n) is this idiom and nothing else.  Note the
compiler's choice is not consistent by constant - `- 1` alone produces the
`sub` form while `- 3` produces the `add` form - so try the complement spelling
whenever the only residue in a byte range test is that one instruction.
