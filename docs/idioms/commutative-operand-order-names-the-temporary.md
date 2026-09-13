# A call result reaches a commutative operator's left slot only when a named local holds it

summary: `adds r2, r0, r7` against `adds r2, r7, r0` is the same one-byte tell
as the `cmp` case, and it generalises: written inline in either operand order,
this compiler puts the call result on the right of `+`, and only assigning it
to a local first moves it to the left.

Found in: `src/matched/unit_02008DAC.c` (0x02008DAC)

`docs/idioms/cmp-operand-order-names-the-temporary.md` records this for `cmp`,
where the asymmetry is easy to dismiss as a quirk of how a comparison is
lowered. It is not about comparison. The original here is

```
bl   sub_02008CB4
adds r2, r0, r7      /* the call result first, the argument second */
```

and both inline spellings of that addition produce the other order, one byte
different and nothing else in a 68-byte function:

```c
result = sub_02008CB4(obj, i) + delta;   /* adds r2, r7, r0 */
result = delta + sub_02008CB4(obj, i);   /* adds r2, r7, r0 */
```

Swapping the operands does not help, because the compiler has already decided
that the value still sitting in `r0` is the one to commute to the right. What
moves it is binding it:

```c
cur = sub_02008CB4(obj, i);
result = cur + delta;                    /* adds r2, r0, r7 */
```

No extra instruction, no stack slot, no register renumbering anywhere else in
the function: the local costs nothing and changes exactly that one byte.

So the rule to carry to the next commutative operator, `+`, `|`, `&`, `^` or
`*`: when a unit is one byte out at an operator one of whose operands is a call
result, do not go looking for a type or an evaluation order. Introduce the
temporary. And read it the other way too, since it is evidence about the
source: a matched function whose call result sits in the left slot was written
with a named local, and one whose result sits on the right was written inline.
