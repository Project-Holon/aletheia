# A terminal `switch` reached only through one `case` lays out earlier if you nest it there

summary: when an outer `switch` has one case whose body is followed by a second
`switch`, and every other outer case `return`s, writing the second `switch`
after the outer `switch` makes the compiler emit the other outer cases' blocks
first; moving the second `switch` *inside* that one case (it is semantically
identical, the trailing `break` becomes unreachable) puts it in the position
the image has, ahead of the remaining outer-case blocks.

Found in: src/matched/ov_sdk/ov009_func_021671C0.c (0x021671C0)

The image lays out, after the `errcode == 0` body:

```
0x...3B0  cmp r6, #2 ; ... wmResult switch
0x...408  bl WcmWmReset        (errcode case 1)
0x...410  mov r0, #0xb ; ...   (errcode 2/3/4/default)
```

but with the flat C

```c
switch (errcode) {
case 0: ...; break;
case 1: WcmWmReset(); return;
default: WCMi_SetPhase(0xb); WCMi_Notify(...); return;
}
switch (wmResult) { ... }
```

dsi/1.1p1 emits the two errcode tail blocks first and the `wmResult` switch
last (each `+0x28` bytes out, plus the switch's internal branch targets). Every
errcode other than 0 returns, so the second switch is only ever reached from
case 0; hoisting it into the case

```c
switch (errcode) {
case 0:
    ...;
    switch (wmResult) { ... }
    break;
case 1: WcmWmReset(); return;
default: WCMi_SetPhase(0xb); WCMi_Notify(...); return;
}
```

restores the image's block order exactly. The lever is the *source nesting*,
not the control flow — the `break` after the nested switch is unreachable and
costs nothing. Look for this whenever a function's only residual diff is a
rotated cluster of tail blocks whose instructions and relocation targets are
otherwise identical.
