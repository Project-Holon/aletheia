# A top-tested while loop is inverted; `for(;;)` with an explicit break is not

summary: `while (cond)` is rotated into `if (cond) do { } while (cond)`, so a
faithful byte match needs the un-invertible `for (;;) { c = ...; if (!cond)
break; ... }` form instead.

Found in: src/matched/func_0220B094.c (0x0220B094)

The original at `0x0220B094` opens a walk over a byte table with the test at
the top and an unconditional branch back at the bottom:

```
push {r4, r5, r6, lr}
adds r5, r0, #0
adds r6, r1, #0
movs r4, #0
loop:
ldrb r0, [r6, r4]
cmp  r0, #0xff
beq  end
lsls r0, r0, #3
adds r0, r5, r0
bl   ...
adds r4, r4, #1
b    loop
end:
pop  {r4, r5, r6, pc}
```

Written the obvious way,

```c
int i = 0;
while (q[i] != 0xff) {
    f(p + (q[i] << 3));
    i++;
}
```

`-O4,p` performs loop inversion: it hoists the first test, then emits the body
as a `do`/`while` whose back edge is a conditional branch, so the exit test
moves to the bottom and the two parameter moves swap registers.  Binding the
load to a local (`unsigned char c = q[i];`) does not stop the rotation.

The un-rotated shape comes from a loop the front end cannot invert, an
explicit break inside an unconditional loop:

```c
int i = 0;
for (;;) {
    unsigned char c = q[i];
    if (c == 0xff)
        break;
    f(p + (c << 3));
    i++;
}
```

This reproduces the test-at-top plus `b loop` exactly.  Reach for it whenever a
near-miss diff shows your `while` compiled to a pre-test plus a bottom
conditional back edge while the original branches backward unconditionally.
