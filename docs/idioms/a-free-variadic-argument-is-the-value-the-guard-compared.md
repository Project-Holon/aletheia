# A variadic argument that costs no instruction is the value the guard compared

summary: an assertion call whose r3 is never written is not passing three
arguments with a leftover register, it is passing a fourth whose value the
guard's own `cmp` already left in r3; declare the variadic tail one argument
short and the value that should have gone to the stack lands in r3 instead.

Found in: `src/matched/func_02049250.c` (0x02049250), and the five siblings
0x0204932C, 0x020493D4, 0x0204944C, 0x020494F4, 0x02049578

The assert helper at 0x02034734 is `f(const char *file, u32 line, const char
*msg, ...)`. A bounds check in front of it looks like this:

```
+000C    ldrh r3, [r5, #0x4e]        ; the count
+0018    cmp  r3, r7                 ; count vs member
+001C    bhi  past_the_assert
+0020    ldr  r0, [pc, #0xa4]        ; file
+0024    ldr  r1, [pc, #0xa4]        ; line
+0028    ldr  r2, [pc, #0xa4]        ; msg
+002C    str  r7, [sp]               ; <- the member goes to the STACK
+0030    bl   #0x2034734
```

r3 is not written anywhere on the assert path, so it is tempting to read the
call as three arguments plus one variadic, with r3 a leftover in the sense of
`a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md`. That
reading is wrong, and it is wrong in a way that shows up as exactly one
instruction: with a single variadic argument mwcc puts the member in r3 and
emits `mov r3, r7`, and nothing reaches the stack at all.

The right reading is two variadic arguments. The first is the count, which the
guard's `ldrh` already parked in r3 and which the compiler is free to reuse
because nothing between the compare and the call clobbers it. The second is the
member, which is the fifth argument overall and therefore the first one to go
on the stack:

```c
if (arc->count <= member) {
    func_02034734(File, 613, Msg, arc->count, member);
}
```

## Rule

When a call's r3 is untouched and something *does* reach the outgoing stack
area, count backwards: the stack word is argument five, so argument four exists
and its value is whatever the surrounding code last left in r3. In a guarded
call that is almost always the operand the guard compared, and putting it back
in the source costs no instruction while leaving it out costs one.
