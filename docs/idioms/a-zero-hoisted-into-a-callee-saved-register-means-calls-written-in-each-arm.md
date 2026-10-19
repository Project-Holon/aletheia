# A zero hoisted into a callee-saved register: write the calls in each arm

summary: A constant hoisted into a callee-saved register across a run of calls means the calls
follow an if/else join. Write the calls in each arm so the constant is built fresh at the store.

Seen in ov194 func_021F33C0 (wave D4, 2026-10-05).

## Symptom

The compiled code puts a constant (usually 0) into a callee-saved register
(`movs r5,#0`) before a run of calls, and a store after the calls uses it
(`strh r5,[r4,r0]`). The original materialises it fresh just before the store
(`movs r1,#0; strh r1,[r4,r0]`).

## Cause

mwcc gives one value to a constant that is used more than once in the same
basic block. When the calls (`f(n, 0); f(3, 0);`) and the store
(`p->cnt = 0;`) sit in one block after an if/else join, the zero is live
across the calls and goes to a callee-saved register.

## Fix

Write the calls in each arm of the if/else instead of after the join:

```c
if (*(u32 *)(p + 0x118)) {
    f(1, 0);
    f(2, 0);
    f(3, 0);
} else {
    f(1, 0);
    f(3, 0);
}
*(u16 *)(p + 0x10a) = 0;
```

Tail merging then builds the same shared join as a `n = 2 / n = 1; f(n, 0)`
form (`movs r0,#2; b join` / `movs r0,#1; join: movs r1,#0; bl f`), but
the join block now holds only the stores, so the zero is not hoisted.
