# A constant argument selected into a local if-converts where a call written in each arm does not

summary: `addr = cond ? WIN_A : WIN_B; G2x_SetBlendBrightness_(addr, ...)` is if-converted
into `ldr`/`ldrne` and comes out eight bytes short, and the same select written as the whole
call repeated in both arms keeps the `bne` / `ldr` / `b` / `ldr` join with one tail-merged
`bl`, which is what the object has; the two forms also allocate registers differently, so the
short one is not four bytes away from being a match.

Found in: `src/matched/ov_sdk/ov016_func_021D55A4.c` (0x021D55A4), sibling of the already
matched `src/matched/ov_sdk/ov016_func_021D566C.c` (taskFade)

`docs/idioms/a-factored-tail-lets-the-compiler-predicate-the-arms.md` records the general
lever -- a statement factored out behind an if/else gets predicated, the same statement
written into both arms gets branches and a cross-jumped tail. This is that lever applied to
a *call argument* that is a pool constant, which adds a second effect the general statement
does not mention.

The object selects a hardware register window on `lcd` and sets the blend brightness:

```
021D55FC  add r0, sp, #0          ; &BRIGHT
021D5600  cmp r1, #1
021D5604  mov r1, r2              ; plane
021D5608  ldrsb r2, [r0, r6]      ; BRIGHT[kind]
021D560C  bne  0x021D5618
021D5610  ldr  r0, [pc, #0x48]    ; 0x04001050, pool at 0x021D5660
021D5614  b    0x021D561C
021D5618  ldr  r0, [pc, #0x44]    ; 0x04000050, pool at 0x021D5664
021D561C  bl   0x0207D658         ; ONE call, both windows
```

Selecting the window into a local first is the obvious spelling, and every variant of it
(ternary, `if`/`else`, inverted condition, truthiness, a two-case `switch`) if-converts:

```
021D55FC  ldr  r0, [pc, #0x54]    ; 0x04001050 hoisted above the test
021D5600  cmp  r1, #1
...
021D5608  ldrne r0, [pc, #0x44]   ; 0x04000050
021D560C  bl   0x0207D658
```

That is 192 bytes against the object's 200, and the residue is not a register spelling. The
if-converted load takes r0 for the window, which pushes the address of the stack `BRIGHT[4]`
copy out of r0 and into r3 (`add r3, sp, #0` against the object's `add r0, sp, #0`), and the
early `movne` / `popne` guard around the `prm->flag` test ends up one slot later in the
allocation as well: the object holds `kind` in r6, `frame` in r5 and the parameter pointer in
r4, the predicated build holds them in r5, r4 and r7. 128 concrete bytes differ, and no
change to the local's type, the condition's polarity or the declaration order moves any of
them. `volatile` on the local does produce real branches and costs a stack slot (216 bytes).

Writing the call into both arms -- the same shape the matched taskFade at 0x021D566C already
carries for its own window select -- gives 200 bytes and 0 concrete bytes differ with all five
relocation sites resolved:

```c
if (lcd == 1)
    G2x_SetBlendBrightness_(0x04001050, plane, BRIGHT.b[kind]);
else
    G2x_SetBlendBrightness_(0x04000050, plane, BRIGHT.b[kind]);
```

Two rules, then. A `cmp` / `b<cond>` over a pool-word load in a merged call site means the
call was written in both arms, not that a local held the constant; and when an if-converted
predicate also moved which registers the rest of the function got, treat the size gap as the
real difference and re-spell the arms rather than tuning allocation, because the two spellings
differ in the allocator's input and no local-level edit reaches the other one.
