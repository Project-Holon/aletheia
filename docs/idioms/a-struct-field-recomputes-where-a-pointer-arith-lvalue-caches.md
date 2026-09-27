# A struct-pointer field recomputes a base that a pointer-arith lvalue caches across a call

summary: when one connection pointer is read at several fields whose offsets
are past the Thumb load reach, `*(T *)(p + K)` makes 1.1p1 materialise the whole
`p + K` address and keep it in a stack slot across an intervening call, spilling
a loop value and growing the frame; reading the same fields through a struct
pointer (`p->field`) makes it recompute the base per access from the parameter
register, matching an original that recomputes too.

Found in: src/pending/ov096_func_02188D5C.c (0x02188D5C)

func_02188D5C takes the connection as a word-sized parameter. Written as
`int b` with `*(int *)(b + 0xb4)`, `*(int *)(b + 0xbc)` and friends, the second
`b + 0xb4` access (inside the loop, after a call to func_021D54C0) made the
front end cache `b + 0xb4` in a stack slot, so the first func_0201134C result
spilled and r6 became the base scratch: frame 0x18, 168 bytes against 164.

```
push {r3, r4, r5, r6, r7, lr}
sub sp, #0x18
...
str r0, [sp, #0x14]        ; b+0xb4 cached across func_021D54C0
...
ldr r0, [sp, #0x14]
```

Typing the parameter as a struct pointer and reading `b->fb4`, `b->fbc`,
`b->fc0`, `b->f38`, `b->f2`, `b->f1`, `b->fc4` (padding to the same offsets)
recomputes the base each time; the t web stays in r6, r stays in r7, the frame
is the original 0x10, and the body is byte-identical except for one scheduling
swap at +0x72. The lever is the lvalue shape, not the declaration order: swapping
the two loop-carried declarations changed nothing, and neither did block versus
function scope for the item local.

Tell: a frame four or eight bytes too big, one callee-saved local spilled, and
an `adds rN, base, #...` address cached in a stack slot in the same function,
where the C reads the same far field by pointer arithmetic at two call sites.
