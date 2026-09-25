# A negated-conjunction `if` is not the same codegen as returning the conjunction

summary: `return a && b && c;` if-converts the last operand's epilogue into
`addne sp` / `movne r0,#1` / `popne`, while `if (!(a && b && c)) return 0;
return 1;` emits a plain `bne` to a separate success epilogue. Same source
semantics, different bytes.

Found in: src/matched/func_021E2A5C.c (0x021E2A5C)

The function is a run of sixteen `gsXmlReadChild*` calls whose only failure
path is the shared `return 0` block at 0x021E2C18. The last call's original
code is:

```
... bl <last>
    cmp   r0, #0
    bne   0x021e2c24        ; mov r0,#1; add sp,#0x10c; pop
0x021e2c18:                 ; add sp,#0x10c; mov r0,#0; pop
```

The obvious C,

```c
return a && b && ... && p;
```

compiles to the same tests but if-converts the final operand into the
epilogue:

```
... bl <last>
    cmp   r0, #0
    addne sp, sp, #0x10c
    movne r0, #1
    popne {r4, r5, r6, r7, pc}
    mov   r0, #0
    add sp, sp, #0x10c
    pop   {r4, r5, r6, r7, pc}
```

72 bytes differ (the branch and the two epilogues are re-ordered and the
later literal-pool offsets shift). Writing the failure as an explicit early
return over the whole conjunction stops the if-conversion:

```c
if (!(a && b && ... && p))
    return 0;
return 1;
```

which yields the original `bne 0x021E2C24` and the two ordered epilogues.
A second variant, `if (!(a && ... && o)) return 0; return p != 0;`, if-converts
the trailing test into `movne r0,#1` / `moveq r0,#0` and also misses.

The tell is the same as
`guard-chain-sharing-one-exit-block-is-a-single-conjunction.md` (every
failure branch shares one block), but the presence of a branch rather than
predicated instructions on the *last* test says the source wrapped the whole
conjunction in a `!` and returned constants, not the conjunction itself.
