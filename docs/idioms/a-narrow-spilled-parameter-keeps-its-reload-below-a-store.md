# A narrow spilled parameter keeps its reload below the preceding store

summary: when a parameter is spilled at entry (`str rN, [sp]`) and reloaded
later as a call argument, an `int`/`u32` parameter's reload is hoisted above
the store just before it; declaring the parameter `u8`/`u16` keeps the reload
after that store, as the original has it. A two-instruction swap next to a
`ldr r0, [sp]` reload is the tell.

Found in: `src/matched/ov/ov020_func_02187808.c` (0x02187808),
`src/matched/ov/ov019_func_0217AE40.c` (0x0217AE40)

`func_02187808` spills its second parameter at entry and reloads it for a
call after a run of field stores:

```
str   r1, [sp]            /* a1 spilled at entry */
...
str   r7, [r4, #0x10]
strb  r6, [r4, #0x14]     /* w->f14 = a2 */
ldr   r0, [sp]            /* reload a1 */
bl    func_0202E8B8
strb  r0, [r4, #0x15]
```

With `int a1` every byte is right except that the compiler emits
`ldr r0, [sp]` before `strb r6, [r4, #0x14]`. Declaring `u8 a1` puts the
reload back after the store and the function is EXACT; nothing else changes,
because the callee takes the value in a register either way and a narrow
parameter costs no extension here.

`func_0217AE40` is the same shape with a `u16`: its third parameter goes to
`[sp]` at entry and is reloaded for `func_02025C74` after `strh r5, [r6]`.
As `u32 c` the reload is scheduled first; as `u16 c` it lands after the
`strh`, and the 148-byte function, parked earlier as a two-instruction DIFF
after nine other attempts (pointer, union and struct views of the local,
statement order), is EXACT.

When a spilled-parameter reload sits one slot too early, try the narrow
types before touching statement order.
