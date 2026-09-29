# A returned halfword stored raw with a second strh is a one-halfword struct return

summary: `bl` then `strh r0,[sp+N]` with no `lsls/asrs`, then a reload and a
second `strh` at N+2, is the result of a callee declared to return a
one-halfword struct (`typedef struct { u16 v; } W; W v = f(x);`), even when
its own file says `s16`.

Found in: `src/matched/ov/ov093_func_021C3184.c` (one function so far; there
a `const u16 *q` also made the `ldrh r3,[q]` argument load schedule first,
and 4-byte struct arguments go by value: `ldr r1,[sp,#x]; add r0,sp,#4;
str r1,[r0]`).

Other spellings that gave the same wrong code: an `s16` local with
`*(W *)&v`, a `W` copied from another `W`, and an assignment expression as
the argument; all of them drop the second `strh` as dead.

See also `a-byte-assembled-word-in-r0-is-a-small-struct-returned-by-value.md`
and `a-ternary-passed-to-a-u8-parameter-is-cast-u8.md`.
