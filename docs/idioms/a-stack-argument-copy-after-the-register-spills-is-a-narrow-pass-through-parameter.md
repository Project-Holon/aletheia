# A stack-argument copy after the register spills is a narrow pass-through parameter

Seen in wave D9r lane 157 (2026-10-05): ov172 func_021B9AB8 (closed EXACT after 13 lanes at 13 bytes).

## Symptom

The prologue spills a register parameter BEFORE the word copy of a stack parameter to its own home,
although r0 is free:

```
str r3, [sp, #4]        @ register parameter spill
ldr r0, [sp, #0x34]     @ stack parameter copy ...
str r2, [sp]            @ (second spill fills the load stall)
str r0, [sp, #0x34]     @ ... back to its own home
```

The draft gave `ldr r0, [sp, #0x34]` first and sank one register spill further down.

## Cause

The stack parameter (`value`) is used once: passed straight to a callee parameter. With `int value`
mwcc emits its entry copy first. With a narrow type (`u8`, `u16` or `short`) on BOTH the parameter
and the callee prototype, the copy moves after the register spill and the loop call still loads it
with a plain word `ldr` (no truncation pair, since the type matches).

## Fix

```c
extern void func_021B9B88(u8 *p, u8 x, u8 y, u8 value);
void func_021B9AB8(int a0, int a1, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, u8 value)
```

Narrowing only the parameter (callee left `int`) grows the frame (0x18) and is worse. Change both.
The same entry order is in ov127 func_021C5C8C, where the narrow `w` stack parameter goes straight
to a u8 callee parameter.
