# Materialising a doubled loop index into the *other* loop's counter variable fixes both the `cmp` operand order and the register rotation

summary: a 2-byte `cmp` operand-order residue and an 11-byte r4/r6 rotation
in the same function are one problem, not two. The fix is a local holding
`i * 2`, spelled with the SAME variable the next loop uses as its inner
counter. Introducing the temporary in a spare variable gets you half the
bytes; giving it the reused variable's name gets all of them.

Found in: src/matched/ov_sdk/ov009_func_02164358.c (0x02164358, CPSi_big_sqr,
libssl.TWL.HYB.a(biginteger.o))

The known-bad shape kept both loops' counters as their own variables, and a
fifth `k` for the outer of the pair-nest:

```c
for (i = 0; i < digits_a; i++) {
    if (i * 2 >= digits) break;
    tmp = a[i] * a[i];
    c[i * 2] = (unsigned short)tmp;
    if (i * 2 == digits - 1) break;              /* cmp r2, r1  -- want r1, r2 */
    c[i * 2 + 1] = (unsigned short)(tmp >> 16);
}
for (k = 0; k < digits_a; k++) {
    for (j = k + 1; j < digits_a && k + j < digits; j++) { ... }
}
```

13 bytes out, in two independent-looking clusters: the equality at `+0064`
(`cmp r2, r1` against `cmp r1, r2`, 2 bytes) and the second nest, where the
image has sum / outer / inner in r4 / r5 / r6 and this has outer / sum /
inner in r4 / r5 / r6 (11 bytes, 6 instructions).

None of the 24 declaration orders or 27 role assignments from a prior pass
moved either cluster, and neither did the `==`/`>=` family: `i * 2 >=
digits - 1` fixes the `cmp` but emits `bge` where the image has `beq`, and
every `>=`/`<=`/`+1 ==`/`- 1 ==` spelling trades one for the other, so
12 was the floor reachable by spelling the guard.

Binding the doubled index to a local is what fixes the compare, and which
local you pick decides the rest:

```c
for (i = 0; i < digits_a; i++) {
    j = i * 2;                                   /* the temporary, in j */
    if (j >= digits) break;
    tmp = a[i] * a[i];
    c[j] = (unsigned short)tmp;
    if (j == digits - 1) break;                  /* cmp r1, r2 */
    c[j + 1] = (unsigned short)(tmp >> 16);
}
```

Loop 1 now compiles 1:1, `cmp r1, r2` and `beq` included, and the temporary
costs nothing: it lands in a caller-saved register (`lsl r1, r4, #1`) and is
dead before the nest starts. It is the same mechanism as
`cmp-operand-order-names-the-temporary` -- an equality against a call result
reaches the left slot only through a named local -- except the operand is
loop-invariant, so the value has to be *lifted into a local that survives to
be compared* rather than merely assigned.

Kept this way the 5-local version is 12 bytes, still rotating the nest.
The rotation is the other half of the same sentence: `j` is now live in
loop 1 and again in loop 2, so its two live ranges belong to one allocator
value, and dropping the separate `k` lets `i` be both loops' outer counter.
That gives the image's colouring -- loop 1 counter r4, outer counter r5,
inner counter r6, the unnamed `i + j` r4-in-nest, product r7 -- and 300/300,
0 concrete bytes, 4/4 relocations resolved.

```c
for (i = 0; i < digits_a; i++) {
    j = i * 2;
    ...
}
for (i = 0; i < digits_a; i++) {
    for (j = i + 1; j < digits_a && i + j < digits; j++) { ... }
}
```

Which is also the only shape whose local set matches the DWARF: four
variables, `tmp`, `digits_a`, `j`, `i` -- the unnamed sum is not a variable,
and the first loop's doubled index is not a fifth one. 48 of 96 declaration
orders over that shape are EXACT, so when you find one, take the declaration
order that lists the variables the way the DWARF does (here `i`, `j`,
`digits_a`, `tmp`, matching the debug info's reverse order) and do not go
looking for more evidence in the bytes that are already hard.

The general lesson: when a same-size residue splits into a `cmp`-order byte
cluster and a loop-counter rotation, suspect one missing local rather than
two bad spellings, and try the reused counter's name for it first. A spare
name gets you the compare and leaves the rotation behind, which reads like
a second, unrelated bug.
