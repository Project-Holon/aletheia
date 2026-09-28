# A soft-float add puts the constant first unless it is a compound assignment

summary: `t + 0.5f` compiles to `__fadd(0.5f, t)` and costs an extra `mov`;
only `t += 0.5f` keeps the running value in the first operand.

Found in: `src/matched/func_02011B8C.c` (0x02011B8C, three sites) and
`src/matched/func_0204CC6C.c` (0x0204CC6C, six sites)

A float add is a call to the runtime helper at 0x0209C95C (`_fadd`; the
subtract is 0x0209CB8C, `_fsub`), and mwccarm canonicalises the commutative
operands before it sets up the call: the constant always lands in r0 and the
computed value in r1.  When the computed value is already in r0, because it is
the return of the preceding call, that canonicalisation costs two instructions
instead of one:

```
t + 0.5f        ->   mov r1, r0            0.5f + t is identical
                     mov r0, #0x3f000000
                     bl  _fadd

t += 0.5f       ->   mov r1, #0x3f000000
                     bl  _fadd
```

Both shapes occur in the image, so the spelling is evidence.  func_02011B8C's
wrap loops are `h += 360.0f`; written `h = h + 360.0f` they no longer match.
func_0204CC6C's rounding helper has the other shape: its positive arm is the
expression `(f32)(v << 12) + 0.5f`, which compiles to `_fadd(0.5f, t)` with
the extra `mov r1, r0`.

Subtraction is not affected, because it is not commutative: `t - 0.5f`
compiles to `_fsub(t, 0.5f)` whether written as an expression or as `-=`.

Until 2026-09-28 the two helper addresses were filed with their names swapped,
and func_0204CC6C was matched as `0.5f - t` and `t += 0.5f`; the bytes are the
same, only the names and the arithmetic were wrong.  See
docs/notes/pkt_0209BDBC_runtime_library.c.txt.
