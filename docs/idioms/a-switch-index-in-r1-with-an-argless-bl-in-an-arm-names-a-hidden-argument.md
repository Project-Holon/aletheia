# A switch index in r1 with an argument-less `bl` in one arm names a hidden argument

summary: when a dense switch's dispatch (or a compare chain on the switch value)
runs in r1 although nothing visible reads r0 in the arms, look for a `bl` in some
arm with no argument setup before it: that callee takes whatever r0 held at the
switch (an incoming parameter, or the result of the last call before the switch),
and declaring it with that argument is what keeps r0 live and moves the index to
r1. Return type, locals, casts and `unsigned` on the switch value do not move it.

Found in: src/matched/ov/ov021_func_021BF76C.c (0x021BF76C),
src/matched/ov/ov021_func_021BF8EC.c (0x021BF8EC),
src/matched/ov/ov021_func_021C00C8.c (0x021C00C8),
src/matched/ov/ov021_func_021C2CF4.c (0x021C2CF4)

The originals, 0x021BF778..0x021BF794 and the case-4 arm:

```
bl   func_02188C58          ; h = ...(obj)
adds r6, r0, #0
ldr  r0, [sp]
bl   func_02188D38          ; d = ...(obj), left in r0
ldr  r1, [r4]               ; switch (*state): index in r1, not r0
cmp  r1, #5
adds r1, r1, r1
...
021BF7E0  bl func_021C6E48  ; case 4: no argument setup at all
```

Two lanes parked these at DIFF (8 bytes: the five dispatch instructions one
register letter off, plus the compare), having read
`a-void-return-frees-r0-for-the-switch-dispatch-index.md` and looked for an arm
that reads r0. None does visibly: `func_02188D38`'s result looked discarded, and
the case-4 callee was declared `int func_021C6E48(void)`. A matched function
elsewhere in ov021 (`ov021_func_021A7CE8.c`) calls it as `func_021C6E48(d)` with
`d = func_02188D38(obj)`. Writing the same here,

```c
d = func_02188D38(obj);
switch (*state) {
...
case 4: if (func_021C6E48(d) != 0) (*state)++; break;
```

makes `d` live in r0 through the dispatch (the allocator never needs to move it,
since the only use is as the first argument), and the index goes to r1. All
three state machines went EXACT with no other change.

0x021C2CF4 is the parameter form: `func_020124E8` in case 1 has no setup and r0
is untouched from entry, so it is `func_020124E8(task)`, the first parameter the
earlier C declared and never read. With the argument, the switch value loads
into r1 (`ldr r1, [r4, r2]`) and case 0's increment becomes `adds r0, r1, #1`
exactly as in the image.

Tried by earlier lanes, none of which moves the register: the callee declared
`void`, the dying result kept in an unused local, the switch value copied to a
local first, `(unsigned)` on the switch value, `+= 1` versus `= x + 1`.
