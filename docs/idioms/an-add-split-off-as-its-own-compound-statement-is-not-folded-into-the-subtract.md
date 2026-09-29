# An add written as its own compound statement after `r = v - k;` is not folded into the subtract

summary: `subs r0, r0, #4; adds r0, #0xe` (two constants mwcc would normally
fold to one add) comes from `r = v - 4; r += 14;` with `r` a result local
returned after the switch; one expression `v - 4 + 14`, `14 + (v - 4)`, a
static inline helper and even `r = v; r -= 4; r += 14;` all fold to `adds r0,
#10`.

Found in: src/matched/ov/ov021_func_021BBD84.c (0x021BBD84)

The original is a five-way dense switch returning a byte from a table, with
two arms that subtract 4 and then add a different constant:

```
ldrb r0, [r2, r0]
subs r0, r0, #4
adds r0, #0xe          /* case 3 */
...
subs r0, r0, #4
adds r0, #0x14         /* case 4 */
```

The C that reproduces it:

```c
int r = 0;
switch (n) {
case 0: r = x; break;
case 1: r = d[y].b[x]; break;
case 2: r = x + 10; break;
case 3: r = d[y].b[x] - 4; r += 14; break;
case 4: r = d[y].b[x] - 4; r += 20; break;
}
return r;
```

What folds (all measured on this function): `return v - 4 + 14;` per arm,
`14 + (v - 4)`, a named temporary holding `v - 4` then `return t + 14`, a
`static inline` helper returning `v - 4`, and `r = v; r -= 4; r += 14;` inside
the same result-local switch. The unfolded pair needs the subtract to be part
of the assignment that loads the table byte and the add to be a separate
compound assignment. The same `int r = 0;` before the switch is also what
puts `movs r0, #0` ahead of the range check and gives each arm its own
`bx lr`; `return` in each arm drops the `movs` and moves every arm.
