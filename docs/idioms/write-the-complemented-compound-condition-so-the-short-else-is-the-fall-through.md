# Write the complemented compound condition so the short else is the fall-through

summary: when the image lays a short `else` arm *before* a long `if` body and
enters the body with a taken `bne` off a two-part (`&&`) test, write the source
as `if (!(A && B)) { short } else { long }` and put the callee result in a named
local before zeroing the returned value; the obvious `if (A && B) { long } else
{ short }` instead branches to a trailing else and moves the post-call zero.

Found in: `src/pending/ov_sdk/ov009_func_0216980C.c` (0x0216980C)

The function ends with `if (profileid > 0 && buddyIdx != -1) { ret = 0; if
(func_02185FD4(...) == 0) ret = 1; } else ret = 0;`. Spelled that way the
compiler lays the body out first and branches **to** the else:

```
006C cmp r6,#0
0070 ble else                 ; profileid <= 0
0074 ldr r1,[sp]
0078 cmn r1,#1
007C beq else                 ; buddyIdx == -1
0080 ... call ...             ; body
00A0 b end
00A4 else: mov r5,#0          ; else trails and its target is forward
```

The image instead puts the short else at the fall-through and takes the branch
**into** the body:

```
006C cmp r6,#0
0070 ble else
0074 ldr r1,[sp]
0078 cmn r1,#1
007C bne body                 ; buddyIdx != -1 enters the body
0080 else: mov r5,#0
0084 b end
0088 body: ... call ...
```

## The lever

Write the condition complemented so the short arm is the `if` and the long arm
the `else`:

```c
if (!(profileid > 0 && buddyIdx != -1)) {
    ret = 0;
} else {
    ret = 0;
    if (func_02185FD4(g_021AA860.ctl->connection, buddyIdx, status) == 0)
        ret = 1;
}
```

That alone put the short arm first and the `bne` in the right polarity. The
`ret = 0;` still scheduled *before* the `bl`; hoisting the call result into a
named local moved the zero to its image slot (after the `bl`, before the
`cmp`/`moveq` pair):

```c
} else {
    int res = func_02185FD4(g_021AA860.ctl->connection, buddyIdx, status);
    ret = 0;
    if (res == 0)
        ret = 1;
}
```

Together these cut a 51-byte diff to 21. The residue is a prologue scheduler
tie (the shared zero of `ret`/`buddyIdx` and its store around the base load),
not a spelling, and is left parked.

See also `docs/idioms/an-else-arm-is-predicated-and-placed-before-the-then-arm.md`
(same block-order observation for the predicated shape) and
`docs/idioms/a-branch-to-a-branch-after-a-two-part-test-is-a-nested-if.md`.
