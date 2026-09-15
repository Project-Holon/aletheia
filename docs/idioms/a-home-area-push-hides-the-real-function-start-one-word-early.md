# A `push {r0,r1,r2,r3}` home area hides the real function start one word early

summary: when a function takes the address of a register parameter, its first
instruction is the argument home-area push and its second is the ordinary
callee-saved push; disasm.py labels the second one, so the listing's function
start is four bytes too high and `match.py one` at that label reports an extent
of 4 bytes.

Found in: `src/matched/func_0203F328.c` (0x0203F328, labelled 0x0203F32C)

[Address of a register parameter opens with `push {r0,r1,r2,r3}`](address-of-a-register-parameter-is-a-push-of-all-four.md)
says what the push is. This is what it does to the *listing*: the home-area
push saves no `lr`, so disasm.py's prologue heuristic skips it and puts the
`func_` label on the next instruction instead.

## The tell

Three things line up, and none of them is conclusive alone:

1. The labelled address opens with a normal `push {..., lr}` but the epilogue
   pops **`lr`**, not `pc`, and then adds a multiple of four to `sp` before a
   separate `bx lr`:

   ```
       0203F32C  push {r3, r4, r5, r6, r7, lr}
       ...
       0203F370  pop  {r3, r4, r5, r6, r7, lr}
       0203F374  add  sp, sp, #0x10
       0203F378  bx   lr
   ```

   A function whose frame it owns deallocates *before* popping and returns by
   popping `pc`. Deallocating after the pop means the thing being freed was
   pushed before the callee-saved registers.

2. The body computes an address `sp + N` where `N` is exactly the callee-saved
   push's size plus the home area's own offset (`add r4, sp, #0x20` here: 0x18
   of pushed registers plus 8 to reach the third argument's slot).

3. The word immediately before the label is `e92d000f`, `push {r0,r1,r2,r3}`,
   and reads as data or as a stray one-instruction "function" in the worklist.

## The confirming witness

When one exists, an ARM long-branch veneer settles it outright. At 0x0203F37C,
twelve bytes past this function's end, sits

```
    0203F37C  ldr ip, [pc]
    0203F380  bx  ip
    0203F384  .word 0x0203F328
```

The linker built that stub against the symbol, so the `.word` is the real
entry address, four bytes below the label disasm.py produced.

## What to do

Write the file at the real start, not at the label, and verify at that address:

```
python tools/match.py one --src src/matched/func_0203F328.c \
    --func func_0203F328 --addr 0x0203F328 --cc 1.1p1 --arm
```

The verdict comes back `EXACT*` with `listing says the original is 4 bytes,
compiled 84`: the star is the label's fault, not the C's. Verifying at the
label instead gives `SIZE` against a four-byte extent, which looks like a
hopeless function and is the reason this costs time.

Both addresses want reporting to the integrator: the real start seeded into
`layout/function_starts.txt`, and the label four bytes on removed from it.

## The C

Nothing exotic; taking the address of a by-value parameter is enough.

```c
void func_0203F328(u16 *p, u32 size, u32 seed)
{
    u32 i;
    u32 n = size >> 1;

    for (i = 0; i < n; i++) {
        p[i] ^= func_0203F388(&seed);   /* &seed forces the home area */
    }
}
```
