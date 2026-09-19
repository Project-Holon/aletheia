# An assignment written inside a call's argument list pins the load in a callee-saved register

summary: mwccarm evaluates a call's arguments right to left, so when a value has
to be read twice and the second read has to survive an inner call, spelling that
second read as an assignment inside the outer call's argument list
(`f(a, g(), v = x)`) puts the load *before* the inner call and keeps the value in
r5; the same read written as its own statement lands too early, and the same read
written inline in both calls is rescheduled after the inner call and costs a
callee-saved register and six bytes.

Found in: `src/matched/func_0202F870.c` (0x0202F870)

Three near-identical blocks read one word of a record twice, once as a normal
argument and once as the third argument of a follow-up call that contains a
getter:

```
0202F8D8  ldr  r1, [sp, #8]      ; p2
0202F8DA  adds r0, r1, #0
0202F8DC  ldr  r1, [r1, #8]      ; p2[2] -- arg2 of func_020862F0
0202F8DE  adds r0, #0xc
0202F8E0  blx  func_020862F0
0202F8E4  ldr  r0, [sp, #8]
0202F8E6  ldr  r5, [r0, #8]      ; p2[2] again, HELD across the getter
0202F8E8  blx  func_0207DFB4     ; the getter inside the next call
0202F8EC  adds r1, r0, #0
0202F8EE  ldr  r0, [sp, #8]
0202F8F0  adds r2, r5, #0
0202F8F2  adds r0, #0xc
0202F8F4  blx  func_02082A60
```

The hold is what makes the frame `push {r3, r4, r5, lr}`; without it the
function is 202 bytes instead of 208 and the frame is `push {r4, lr}`.

The three spellings, measured:

```c
/* 202 bytes, r5 unused, load sinks below the getter */
func_020862F0(p2 + 3, p2[2]);
func_02082A60(p2 + 3, func_0207DFB4(), p2[2]);

/* 202 bytes, still no hold */
func_020862F0(p2 + 3, p2[2]);
v2 = p2[2];
func_02082A60(p2 + 3, func_0207DFB4(), v2);

/* 208 bytes, EXACT: the assignment is an argument, so it is evaluated
   before the getter call it sits to the right of */
func_020862F0(p2 + 3, p2[2]);
func_02082A60(p2 + 3, func_0207DFB4(), v2 = p2[2]);
```

Writing `v2 = p2[2];` as its own statement *before* the first call also holds r5
(the frame comes out right) but with the load one instruction early, which is a
152-byte diff rather than 6.

The practical rule: when a function is a handful of bytes short and the missing
bytes are a callee-saved register holding a value that a call sits between, do
not hunt for a declaration order or a `volatile`. Move the second read into the
argument list of the call that needs it, as an assignment.
