# A negative return is `mvn #(N-1)`, not `mvn #N`

summary: `mvn rX, #K` is a bitwise NOT, so the C constant is `-(K + 1)`;
writing the disassembler's `#K` verbatim as `-K` is off by one.

Found in: src/matched/func_0215CEB0.c (0x0215CEB0)

The original ends:

```
    mov r0, #0
    cmp r4, #0
    mvneq r0, #0x29
    pop {r3, r4, r5, pc}
```

`mvn r0, #0x29` is `r0 = ~0x29 = 0xFFFFFFD6 = -0x2A`. The tempting reading is
`return r4 ? 0 : -0x29;`, which this compiler encodes as `mvn r0, #0x28` (since
`~0x28 = -0x29`) and disagrees with the original at one byte. The C that
reproduces the original is `return r4 ? 0 : -0x2A;`.

The rule is `mvn #K` ⇔ `~K` ⇔ `-(K + 1)`: the immediate is the one's
complement of the result, not the negated magnitude. `mvneq`/`mvnne` in an
otherwise obvious "return 0 or a small negative error code" tail is the usual
place this bites.
