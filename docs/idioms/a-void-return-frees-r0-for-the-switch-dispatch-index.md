# The register a dense switch computes its jump-table index in names the function's return type

summary: the five-instruction dispatch of a PC-relative switch table takes r0
when the switch value's register is dead afterwards and r1 when it is not, and
in a function whose every arm is a single tail call the only thing that decides
that is whether the function returns the callee's result or returns `void`; six
bytes across five instructions, with the rest of the function byte for byte
right either way.

Found in: `src/matched/unit_0202C5F0.c` (0x0202C5F0), against
`src/matched/sub_0202C6C4.c` (0x0202C6C4) and
`src/matched/unit_0202C72C.c` (0x0202C72C)

`docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md` reads the table
and the case list. This is the register the preamble runs in, which is a
separate question and is not free:

```
0202C5F8  cmp  r0, #3
0202C5FA  bhi  .default
0202C5FC  adds r0, r0, r0       /* the original: r0 throughout */
0202C5FE  add  r0, pc
0202C600  ldrh r0, [r0, #6]
0202C602  lsls r0, r0, #0x10
0202C604  asrs r0, r0, #0x10
0202C606  add  pc, r0
```

The switch value arrives in r0, because it is the result of a call. mwccarm
folds the index computation back into r0 only when r0 is free for the whole of
the arm bodies that follow; otherwise it copies the value into r1 first and the
same five instructions come out one register letter different, `adds r1, r0, r0`
onwards. Six concrete bytes, identical control flow, identical everything else.

In a dispatcher whose arms are each one call on the same object, the return type
is what decides it:

```c
/* r1: the callee's result is live out of every arm */
u32 sub_0202C5F0(void *p)
{
    switch (sub_0202C6B8(p)) {
    case 0: return sub_0202C630(p);
    ...
    }
}

/* r0: nothing is live out, so r0 is dead across the table computation */
void sub_0202C5F0(void *p)
{
    switch (sub_0202C6B8(p)) {
    case 0: sub_0202C630(p); break;
    ...
    }
}
```

Both compile to the same 64 bytes bar those six, the same four `adds r0, r4, #0`
/ `bl` / `pop {r4, pc}` arms and the same table. The `void` form is the original.

What does **not** move it, all tried and all byte-for-byte identical to the
`u32` form: hoisting the switch value into a named local, renaming it, marking
it `register`, casting it to `int`, adding an empty `default:` arm, reversing
the case order, and adding a trailing `return`. The `return` type is the whole
of it, and the two stub callees at 0x0202C630 and 0x0202C634 have to be `void`
as well or their declarations put the value back.

The two neighbouring switches in the same family are the control. `sub_0202C6C4`
and `sub_0202C72C` both answer with a value, and both use r0, because their arms
compute into r0 as the last thing they do rather than carrying a callee's result
through; a function that returns something is not automatically the r1 case. The
discriminator is liveness at the dispatch, and the return type is only the
cheapest way to change it.

The practical rule: when a switch dispatcher is byte for byte right except for
one register letter repeated five times, do not look at the switch. Look at what
the arms do with their results.
