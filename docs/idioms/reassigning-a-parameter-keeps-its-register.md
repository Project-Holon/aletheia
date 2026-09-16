# Writing a derived value back into the parameter keeps the parameter's register; a fresh local rotates the whole allocation

summary: when a function computes something from an argument and then uses only
the result, storing it back into the parameter and binding it to a new local
generate the same instructions in the same order but different callee-saved
registers, because a fresh local is a new virtual register that is allocated
after the parameters rather than coalesced onto one.

Found in: `src/matched/func_0203FB44.c` (0x0203FB44)

`func_0203FB44` converts a byte offset into arena units and then passes that
unit index to `func_0203422C` from both arms of a switch. The original keeps
the value in r7, the register the second argument arrived in, and puts the
state pointer in r5 and the third argument in r6:

```
0203FB44  push {r4, r5, r6, r7, r8, lr}
0203FB4C  and r0, r8, #0xff
0203FB50  mov r7, r1          /* offset */
0203FB54  mov r6, r2          /* size   */
...
0203FB64  ldr r5, [r1]        /* the state pointer */
0203FB78  bl #0x209c2b0
0203FB7C  mov r7, r0          /* the quotient lands back in offset's register */
```

The natural C, with a new name for the derived value, is byte-for-byte the
same instruction sequence and fourteen bytes wrong:

```c
u32 unit  = sub_020416B8((u8)layer);
struct BgSys *p = g_02146A44;
u32 start = (p->unk_170[layer] + offset * unit) / unit;   /* wrong */
```

It produces `mov r5, r1` / `mov r7, r2` / `ldr r6, [r1]`, a three-way rotation
of r5, r6 and r7 against the original, with every instruction otherwise
identical. The fix is not a declaration reorder (all orderings give the same
rotation) but dropping the new name:

```c
offset = (p->unk_170[layer] + offset * unit) / unit;      /* EXACT */
```

## When to reach for it

The tell is a diff where the instruction stream lines up exactly and only two
or three callee-saved registers are permuted, with one of them being a
register a parameter was `mov`ed into in the prologue. That says the original
never created a second value: it overwrote the parameter. Look for a
parameter that is read once, early, and never used again afterwards under its
own meaning; that is the one the original reassigned.

The reverse reading also holds: if a value that *is* still used under its
original meaning later in the function shares a register with a derived one,
the derived one is a genuine new local, and reassigning the parameter will not
compile.
