# A call result compared against memory only reaches `cmp`'s left slot when a named local holds it

summary: `cmp r0, r1` against `cmp r1, r0` is the one-byte tell that the
function result was assigned to a local before the comparison; written inline
on either side of the `!=`, this compiler always puts the memory operand
first.

Found in: src/matched/unit_02005F38.c (0x02005FBC)

The original is

```
bl   func_020058D0
ldr  r1, [r4, #0x28]
cmp  r0, r1
beq  ...
```

Every inline spelling of that comparison produces the same two loads and the
*other* operand order, `cmp r1, r0`, one byte different and nothing else:

```c
if (sub_020058D0() != state.unk28)      /* 4281  cmp r1, r0 */
if (state.unk28 != sub_020058D0())      /* 4281 */
if (!(sub_020058D0() == state.unk28))   /* 4281 */
```

Binding the result to a local first is what flips it:

```c
u32 id;

id = sub_020058D0();
if (id != state.unk28)                  /* 4288  cmp r0, r1 */
```

The generated code is otherwise identical: same call, same `ldr`, same
branch, no extra move, and the local never reaches the stack. So the byte
is evidence about the source's *shape* rather than its meaning, and it is
the only evidence there is: a comparison is symmetric, so nothing else in
the function distinguishes the two spellings.

The second operand's type does not matter. The same sweep over `u16`, `u32`,
`int`, `short` and `signed char` return types crossed with `u32`, `int` and
pointer field types moves the other 161 bytes of the unit around and never
moves this one; only the presence of the named local does.

Two practical consequences. When a unit is one byte out at a `cmp` and the
value is a call result, do not go looking for a type: introduce the
temporary. And when a matched function does have the temporary, that is a
real and reproducible statement about how the original was written, not a
stylistic choice of the decompiler's.
