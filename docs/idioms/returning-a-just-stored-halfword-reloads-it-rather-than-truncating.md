# Returning a just-stored halfword reloads it rather than truncating

summary: a function that increments a `u16` in memory and returns the new value
ends `ldrh / add / strh / ldrh`, reading its own store back, because one `ldrh`
is cheaper than the `lsl`/`lsr` pair that truncating the value already in a
register would cost; the trailing load is not evidence of `volatile` and not a
missed optimisation.

Found in: `src/matched/sub_02033264.c` (0x02033264), `src/matched/sub_020332A4.c` (0x020332A4)

Both of savedata.c's little record helpers end the same way. The counter bump
at 0x02033264 is

```
02033290  ldrh r0, [r2, r1]
02033294  add  r0, r0, #1
02033298  strh r0, [r2, r1]
0203329c  ldrh r0, [r2, r1]       /* the value that was just stored */
020332a0  pop  {r4, r5, r6, pc}
```

and the CRC writer at 0x020332A4 does it with a call result instead of an
increment:

```
020332ec  strh r0, [r5, #2]
020332f0  ldrh r0, [r5, #2]
020332f4  pop  {r4, r5, r6, pc}
```

The C in both cases is the plain thing, no `volatile` anywhere:

```c
*q = *q + 1;
return *q;
```

The reload looks redundant because it is redundant, in the sense that the
compiler knows the value. What it does not have is that value *narrowed*: the
adder produced a 32-bit result and the return type is `u16`, so it either
reloads (one instruction, four bytes) or truncates with `lsl r0, r0, #16` and
`lsr r0, r0, #16` (two instructions, eight bytes). It reloads.

This matters twice. Reading the original, a trailing `ldrh` of an address the
function just wrote is not a reason to reach for `volatile`; adding it changes
nothing here and costs elsewhere in the same file. Writing the C, spelling the
return as `return *q;` is what produces the reload, whereas holding the value
in a local first,

```c
u16 v = *q + 1;
*q = v;
return v;
```

gives the shift pair instead, and the function grows from 64 bytes to 68: the
reload disappears but two instructions take its place, because `v` has to be
narrowed at the assignment and the narrowed register is then what both the
store and the return use.

```
02033290  ldrh r0, [r2, r1]
02033294  add  r0, r0, #1
02033298  lsl  r0, r0, #0x10       /* the (u16) conversion, written out */
0203329c  lsr  r0, r0, #0x10
020332a0  strh r0, [r2, r1]
020332a4  pop  {r4, r5, r6, pc}
```
