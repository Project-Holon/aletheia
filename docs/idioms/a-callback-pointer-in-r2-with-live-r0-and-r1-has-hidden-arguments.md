# A callback pointer in r2 with live r0 and r1 has hidden arguments

summary: when an indirect call loads its function pointer into r2 (or r3) and r0/r1 still hold
values set just before the `blx`, the callback takes those values as arguments. Declare the
pointer with the real parameter list and pass them. A `void (*)(void)` declaration makes mwcc
free r0/r1, so the constants and stores around the call colour and pool differently.

Found in: src/matched/ov/ov015_func_0217A334.c (0x0217A334), 0xF8 arm. The listing has
`blx r2` with r0 = the byte just stored to g_0217AAB0[1] and r1 = 0. The fix is
`void (*onDone)(u8, int)` called as `onDone(pk[1], 0)`. That closed 111 bytes in one change;
store orders, pragmas and inline helpers gave nothing.

Check first: for every indirect call, read which argument registers are written between the
last use and the `blx`.
