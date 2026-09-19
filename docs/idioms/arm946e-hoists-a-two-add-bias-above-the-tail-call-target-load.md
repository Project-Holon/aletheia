# The `-proc` decides whether a two-add bias hoists above the tail-call target load

summary: two `add`s feeding a tail call's argument are scheduled *above* the
`ldr ip, =target` under `-proc arm946e` and *below* it under `-proc arm7tdmi`;
the image's order (`ldr` first) is the arm7tdmi one, so a row whose proc_hints
line reads arm946e can still close on a single `-proc` change.

Found in: `src/matched/sub_02063054.c` (0x02063054); same shape as
`src/matched/sub_02063068.c` (0x02063068)

The original is a 16-byte argument-bias thunk that tail-calls the transfer
routine at 0x02082A60 (a tail call is a pool word and a `bx`, never a
displacement branch - see `tail-call-is-a-pool-word-and-bx.md`):

```
02063054  08 c0 9f e5  ldr ip, [pc, #8]
02063058  01 1b 81 e2  add r1, r1, #0x400
0206305C  07 14 81 e2  add r1, r1, #0x7000000
02063060  1c ff 2f e1  bx ip
02063064  60 2a 08 02  .word 0x02082A60
```

0x07000400 is not an ARM rotated immediate, so the bias is necessarily two
`add`s, and under the project default `-proc arm946e` mwcc's list scheduler
fills the load-use slot with the first of them, giving the same four
instructions in the wrong order:

```
02063054  01 1b 81 e2  add r1, r1, #0x400      /* arm946e, DIFF, 8 bytes */
02063058  08 c0 9f e5  ldr ip, [pc, #8]
0206305C  07 14 81 e2  add r1, r1, #0x7000000
02063060  1c ff 2f e1  bx ip
```

Every spelling that reaches the same four instructions hoists it: the sum as a
single expression, the constants in the other order, the first `add` bound to a
named `u32` local, `|` instead of `+`, and a `u32 *` second parameter. There is
no C that suppresses it.

`--flags "-O4,p -proc arm7tdmi"` emits the image's order with everything else
unchanged - `EXACT*` (the `*` is the unlabelled follower 0x02063068, whose own
single-`add` body has no scheduling freedom and needs no proc change):

```
python tools/match.py one --src src/matched/sub_02063054.c \
    --func sub_02063054 --addr 0x02063054 --arm --flags "-O4,p -proc arm7tdmi"
```

Two things make this worth a file of its own. `layout/proc_hints.txt` reads
`arm946e` for this packet: the census classifies a unit from its epilogues
(`pop {...pc}` versus `pop {...,lr}; bx lr`, see
`an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md`), and a
tail-call thunk has neither, so it is counted with the default. And that other
idiom's claim that the two `-proc` values schedule identically holds for the
*pair of epilogues* it documents, not in general: here the proc changes only
the order of four instructions, nothing else in the body. A `-proc` is
therefore worth one probe on any row whose bias needs two instructions and
whose first instruction is an `ldr ip` of the callee.
