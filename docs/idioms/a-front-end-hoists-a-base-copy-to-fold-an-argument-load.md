# A front end hoists a copy of a global base to fold a field load used as a call argument

summary: when a call's later argument is a global-array field load
(`func(x, KEYSTR(i))`), one front end addresses the load off a scratch copy of
the array base (`mov r0, base; ldr r1, [r0, i]`) and only then moves the first
argument into r0, while the image addresses straight off the callee-saved base
(`ldr r1, [base, i]`) and writes the first argument first. Binding the load to a
named local, reordering the store/call, and taking an element pointer are all
inert: the extra `mov` is the front end's choice of address register and no
source spelling reaches it.

Found in: `src/pending/ov_sdk/ov009_func_0216CA04.c` (0x0216CA04, ov009,
DWC_AddMatchKeyString, libdwcmatch.TWL.HYB.a dwc_match.o).

Under `--cc ../2.0/base` the whole function lines up instruction for
instruction except the tail. Image:

```
ldr  r1, [pc, #0x28]
mov  r0, r7            ; r0 = keyID (first arg)
str  r5, [r1, r4]      ; KEYVAL(index) = valueSrc
ldr  r1, [r8, r4]      ; r1 = KEYSTR(index) -- straight off the base r8
bl   func_0219D158
mov  r0, r7            ; return keyID
```

Ours inserts a copy of the base and folds the load onto it:

```
ldr  r1, [pc, #0x2c]
mov  r0, r8            ; r0 = base        <-- extra instruction
str  r5, [r1, r4]
ldr  r1, [r0, r4]      ; r1 = KEYSTR(index) off the scratch
mov  r0, r7            ; r0 = keyID, now one slot late
bl   func_0219D158
mov  r0, r7
```

The residue is exactly one 4-byte `mov` (42 concrete diffs, every one a pool
displacement that moved with it; 304 B vs the image's 300). Replacing the load
argument with a non-load value collapses it to 7 diffs, confirming the whole gap
is the addressing register, not the schedule.

Levers measured inert (all 304 / 42): the call spelled with
`g_021AAA40[index].keyString`; a `char *ks` local assigned after the store; a
`char *ks = KEYSTR(index)` hoisted above the store; element-pointer locals for
the store and for both store and call; a `char *v` temp for valueSrc; a
`char **pv` for the value store and a `(volatile char **)` one; two nested
blocks; `(char *)` casts on the store and the load; a `u8 k = keyID` local;
`KEYSTR(keyID - 0x64)`; the call before the store; the comma operator;
`(char *)valueSrc`. The twin `DWC_AddMatchKeyInt` (0x0216C8DC, same object)
parks on the same class of residue, so this is the object's front end, not the
body.

Distinguish from `vendor-front-end-parameter-register-set-cannot-be-forced.md`
(parameter homing differs, no extra instruction) and
`a-vendor-front-end-homed-parameter-cannot-be-forced-by-source.md` (a frame
spill / extra live pointer): here the instruction count differs by one and the
extra instruction is a base copy that only exists to fold the argument load.
Park the row and log the +00FC `mov`.
