# A spilled flag stored after the argument load is a narrow local

summary: when a 0/1 local spills and the image loads the next call's first
argument before the spill store (`ldr r0, [r4, #N]; movs r1, #0; str r1,
[sp]; movs r1, #0; bl`), declare the local `u8` (or another narrow type). A
word spill of a narrow variable is in the unknown-memory set G, so the store
gets a memory edge from the pointer load and waits for it. An `int` spill gets
a fresh alias object outside every set, and the post scheduler is free to put
the constant and the store first.

Found in: `src/game/ov176/livebattlematch_flow.c` (LIVEBATTLEMATCH_FLOW_Card,
case 3, Japanese target, dsi/1.1p1, Thumb).

## Shape

```c
case 3: {
    int b;
    u8 index = (unsigned int)LIVEBATTLEMATCH_SAVE_GetCounter(p->saveBlock, 0);
    u8 a = 0;
    ...
    LIVEBATTLEMATCH_SAVE_AddCounter(p->saveBlock, 1, a);
```

The Japanese build spills `a` (the default case calls a 4-argument panic, so
no callee-saved register is free). With `int a = 0;` first, the spill temp is
`r0` and the store comes before the load. With `int a` declared after the
call, the temp is `r1`, but the scheduler still issues `movs r1, #0; str r1`
first (release count 1 against 0 for the load). With `u8 a` after the call,
the store depends on the `p->saveBlock` load and the order matches.

The English build keeps `a` in `r7` (no spill), so the narrow type changes
nothing there. Only constants are assigned, so no extension code appears.

## How to check

`python tools/mwccdbg/mwccdbg.py sched FILE --func F --extra "..."`: the spill
store's alias object is a set (G) for a narrow local and an exact object for
an int. `sched-replay --add LOAD:STORE:0` predicts the order first.
