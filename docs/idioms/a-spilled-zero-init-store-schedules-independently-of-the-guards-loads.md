# A spilled zero-init local's store schedules independently of the guard's loads

summary: when a zero-initialised local whose address is taken is spilled to the
frame, the position of its `str r5,[sp]` among the guard's base/field loads and
parameter copies is a front-end list-scheduling tie, not a source-order
property; 24 measured shapes (declaration order, assignment order, copy-of-first
zero, named parameter locals, late assignment, `volatile`, uninitialised
neighbour) all leave the identical residue.

Found in: `src/pending/ov_sdk/ov009_func_0216980C.c` (0x0216980C, DIFF, 180
bytes, 21 concrete bytes). Also the same shape as the `func_02061460` residue
in `docs/idioms/a-second-zero-must-be-spelled-as-a-copy-of-the-first.md`.

## The diff

The whole residue is one six-instruction prologue block; every other byte,
both arms, all six relocations and the size are exact:

```
original                                     compiled
push {r3, r4, r5, r6, r7, lr}               push {r3, r4, r5, r6, r7, lr}
ldr  r4, [pc, #0xa4]          <- base       mov  r5, #0
mov  r5, #0                                 ldr  r4, [pc, #0xa0]
ldr  r2, [r4, #0xc]           <- field      str  r5, [sp]
mov  r6, r0                                 ldr  r2, [r4, #0xc]
mov  r7, r1                                 mov  r6, r0
str  r5, [sp]                 <- spill      mov  r7, r1
cmp  r2, #0                                 cmp  r2, #0
```

The store to the frame slot is the home store of `int buddyIdx`, which is
spilled only because its address is passed to a callee. Its value is the shared
zero of `unsigned char ret` and `buddyIdx`.

## Why source cannot move it

The store is pure bookkeeping: `r5` already holds the constant and nothing
downstream depends on the store's result. mwccarm's scheduler is therefore free
to place it anywhere the value is live, and it ties the base load, the zero, the
field load, the two callee-saved parameter copies and the store in an order the
DAG does not pin. The original put the store last among the copies; this front
end puts it immediately after the `mov r5,#0`. Both are legal.

This is the local-store mirror of
`docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md`'s
"What it is not": that note already records that an outgoing stack argument's
store time is a property of the call-setup schedule, not of the source; the same
holds for a spilled local's initial store.

## Measured shapes (all leave the 21-byte residue)

- `unsigned char ret = 0; int buddyIdx = 0;` (baseline) and swapped order;
- `int buddyIdx = ret;` / `int buddyIdx = ret` with `ret` first — the
  copy-of-first-zero lever of the sibling idiom, which does close a *loop
  index* but not a store-only value;
- `ret = 0; buddyIdx = 0;` and `buddyIdx = 0; ret = 0;` as separate statements
  (these move the residue but never remove it: 33 and 30 bytes);
- assigning `buddyIdx` after the guard's field read (50 bytes) or inside the
  `profileid > 0` arm (35 bytes, 176 bytes) — size or branch layout changes;
- `void *fd = friendData; BuddyStatus *st = status;` named parameter locals,
  before and after the zero locals (21 bytes each);
- `extern const FriendGlobal` / a named `ctl` local — size changes;
- `volatile`/`u16` `buddyIdx` — the `int *` prototype of the callee refuses the
  address without a cast (CCERR), and with a cast it is 184 bytes / 67.

The lever that does work is elsewhere: the else/call arm of the same function
closed with `docs/idioms/write-the-complemented-compound-condition-so-the-short-else-is-the-fall-through.md`.
