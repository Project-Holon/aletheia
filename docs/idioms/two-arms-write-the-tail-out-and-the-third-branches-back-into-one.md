# Two arms write the shared tail out and the third branches backward into one of them

summary: a BACKWARD branch from a late block into the middle of an earlier
one says the source has the shared statements written out in some arms and
an explicit `goto` into one of those copies from another. Writing them once
behind a label lets the compiler cross-jump every arm into a single block
and moves every branch target after it.

Found in: `src/matched/func_02026A60.c` best source
(`docs/notes/func_02026A60.c.txt`, 0x02026A60)

`docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md` records the
all-or-nothing case: every arm repeats the statements and the compiler
cross-jumps them. This is the mixed case, and it is the one that is easy to
misread as a register-allocation problem, because getting it wrong shifts
every subsequent branch target and the diff then looks like a general
reshuffle.

func_02026A60 has three scan loops, each ending in the same two statements
(`hit = 1; goto tail;`). The original spends TWO copies:

```
+0074   movs r0, #1         /* loop 1's hit */
+0076   mov  ip, r0
+0078   b    #0x2026b54     /* -> tail */
...
+00B0   movs r0, #1         /* loop 2's hit, its own copy */
+00B2   mov  ip, r0
+00B4   b    #0x2026b1c
...
+00EC   b    #0x2026ad4     /* loop 3's hit: BACKWARD, into loop 1's copy */
```

Written the obvious way -- one `hit = 1; goto tail;` reached from all three
arms -- the compiler merges all three into one block. The function is then
the right instructions in the right registers and 301 of 404 bytes differ,
purely from the displacement shift.

The source shape that reproduces it puts a label INSIDE the first arm's hit
block, so that arm both writes the statements out and provides the target:

```c
if (lo <= hi) {
    for (...) {
        ...
found:  hit = 1;
        goto tail;
    }
    goto tail;
}
for (...) {                 /* loop 2: its own copy of the statements */
    ...
    hit = 1;
    goto second;
}
second:
...
for (...) {
    ...
    goto found;             /* loop 3: shares loop 1's copy */
}
tail:
```

Reading it back: count the copies of the shared tail in the original and
note which blocks reach it by a FORWARD `b` and which by a BACKWARD one. A
forward branch is an arm that has its own copy branching past the others; a
backward branch into an earlier block is an arm that has no copy and whose
source said `goto` to a label sitting inside that earlier block. The number
of copies is the number of arms that wrote the statements out.

A second, smaller tell rides along in the same function: an `ip` (r12) home
for a whole-function flag is not evidence of an address-taken or `volatile`
local. It falls out of the arm structure on its own -- once the arms stop
sharing, the flag has more definition points, its spill cost changes and the
allocator gives it a high register. Trying to force `ip` with `volatile` or
`&flag` before fixing the arms only adds a memory home and makes the diff
worse.
