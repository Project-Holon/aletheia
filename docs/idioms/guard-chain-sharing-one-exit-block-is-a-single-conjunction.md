# A run of guards that all branch to one exit block is a single `&&`, not a run of early returns

summary: this compiler gives every `if (c) return v;` its own copy of the
epilogue and only tail-merges the failure path when the tests are one
conjunction, so counting the epilogues in the original says whether the source
wrote a chain of early returns or a single `if (a && b && c)`.

Found in: the near miss at 0x02006C2C, described in the header of
`src/matched/unit_02006B20.c`

Three guards written the obvious decompiler way,

```c
if (species != 441)              return 0;
if (form != 0)                   return 0;
if (func_02007B50(*p) != 1)      return 0;
body;
return 1;
```

compile to three separate `beq`-over-an-epilogue sequences, each four
instructions (`add sp, #n`, `movs r0, #0`, `pop`), and the function comes out
twelve bytes too long with every later instruction displaced. mwccarm does not
cross-jump them at `-O4,p`; it only emits one failure block when the control
flow already has one, which a conjunction does:

```c
if (species == 441 && form == 0 && func_02007B50(*p) == 1) {
    body;
    return 1;
}
return 0;
```

Then each test is a bare two-instruction `cmp` / `bne .fail` and `.fail` is one
copy of `movs r0, #0; add sp, #n; pop` at the bottom.

The reverse reading is the useful one, and it is mechanical:

* **several conditional branches to one address at the end of the function**
  means one `if` with `&&`, and the number of branches is the number of
  conjuncts;
* **a conditional branch that jumps over an inline epilogue** is its own
  statement, an early return the source wrote separately.

The two shapes can sit in the same function and in 0x02006C2C they do: the
first guard, a null check on a pointer parameter, jumps over its own inline
`add sp, #0xc; movs r0, #0; pop`, and the three that follow it all branch to a
shared tail. So the source is one early return followed by one three-way
conjunction, and the operand order inside the epilogue differs between the two
copies (`add sp` before `movs` in the inline one, after it in the merged one),
which is a second, independent tell that they came from different statements.
