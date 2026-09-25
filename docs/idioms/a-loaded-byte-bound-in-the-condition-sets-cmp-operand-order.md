# A loaded byte bound inside a loop condition is what puts it in `cmp`'s first slot

summary: when a byte fetched from memory is compared against a register
delimiter, every inline spelling emits `cmp <register>, <byte>`; binding the
load to a named local **inside the condition** (`(c = p[i]) != '\0'`) is the
only spelling that emits `cmp <byte>, <register>`.

Found in: `src/matched/ov009_func_02193418.c` (0x02193418, gpiValueForKey)

The original loop scans the value text after the key and stops at NUL or at
the delimiter `key[0]`:

```
0219344C  sub   r0, r7, #1        ; valueLen - 1
02193450  b     0219345C
02193454  strb  r2, [r4, r3]      ; value[i] = c
02193458  add   r3, r3, #1
0219345C  cmp   r3, r0            ; i < valueLen - 1
02193460  bge   02193478
02193464  ldrsb r2, [r1, r3]      ; c = p[i]
02193468  cmp   r2, #0
0219346C  beq   02193478
02193470  cmp   r2, r6            ; <-- c first, delimiter (r6) second
02193474  bne   02193454
```

`r6` holds `key[0]`, read once at function entry. The obvious C,

```c
char keychar = key[0];
i = 0;
while ((i < valueLen - 1) && (p[i] != '\0') && (p[i] != keychar)) {
    value[i] = p[i];
    i++;
}
```

compiles to byte-identical code except at 0x02193470, where this front end
emits the mirrored `cmp r6, r2` (one halfword different).  Swapping the
operands in the source (`keychar != p[i]`) changes nothing: the compiler
canonicalises the comparison and keeps the register delimiter in the first
slot.

Binding the loaded byte to a named local is what flips it, and the binding
has to happen **inside the condition** so that the surrounding `while`
structure (bound test first, then the two byte tests) is preserved:

```c
char c;
i = 0;
while ((i < valueLen - 1) && ((c = p[i]) != '\0') && (c != keychar)) {
    value[i] = c;
    i++;
}
```

That is EXACT.  Splitting the test into `if (c == '\0') break;
if (c == keychar) break;` inside the loop body does *not* work: this compiler
then fuses the two tests into `cmpne` and inverts the loop to a bottom-tested
do-while, moving the bound check and changing several instructions.  This is
the sibling of
[cmp-operand-order-names-the-temporary](cmp-operand-order-names-the-temporary.md);
the difference is that there the operand is a call result and a plain local
assignment flips it, while here the operand is a freshly loaded byte and only
an assignment embedded in the condition flips it without disturbing the loop.
