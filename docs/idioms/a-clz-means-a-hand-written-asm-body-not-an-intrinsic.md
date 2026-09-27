# A `clz` in SDK output means a hand-written `asm` body, not an intrinsic

summary: dsi/1.1p1 maps no spelling of a count-leading-zeros intrinsic to the
ARM `clz` instruction and never synthesises one from a loop, so a `clz` in an
SDK object means the source was an `asm` function; calibrate the DWARF line
table against a known `asm` file before deciding.

Found in: src/matched/func_01FF80F0.c (0x01FF80F0)

`OS_IrqHandler` in `libos.TWL.HYB.a` selects the lowest pending interrupt with

```
clz     r0, r1
bics    r1, r1, r3, lsr r0
bne     loop
```

which is exactly what a `while (m) { n = clz(m); m &= ~(0x80000000 >> n); }`
loop would be if the compiler had a clz. It does not. `__builtin_clz`,
`__builtin_clzl`, `__builtin_clzll`, `__builtin_clz32`, `__builtin_clzg`,
`__builtin_countl_zero`, `__builtin_cntlzw`, `__builtin_lzcnt`, `__builtin_ffs`,
`__builtin_ctz`, `__builtin_popcount`, `__clz`, `__CLZ`, `_clz`, `__cntlzw`,
`__lzcnt`, `__msl_clz` and `CountLeadingZeros` all compile under dsi/1.1p1 to
an ordinary call: `ldr ip, [pc]; bx ip` with an `R_ARM_ABS32` to the name, which
is what an undeclared function looks like. The obvious C loops (count while the
top bit is clear and shift, or keep a counter and `tst` it) each compile to
their own literal loop: no clz, sometimes not even a `bics`.

So do not spend the budget on intrinsic spellings. Two things decide it
instead:

- The SDK writes `asm` functions when it wants an instruction, and
  `sdk/TwlSDK/build/libraries/os/common/src/os_spinLock.c:833` is
  `asm s32 OS_GetLockID(void)` with a literal `clz r2, r1` in the body (with an
  `#else` ARM7 shift loop beside it). Two `clz` sites in one library file is a
  hand-asm habit, not an optimizer.
- Metrowerks tracks inline-asm lines exactly. In `os_context.c` the
  `--dwarf=decodedline` entries for `asm BOOL OS_LoadContext` land on
  164, 165, 169, 173, 174, 175, 181, 187, 191, 193, 194, 195, 199, 206, which
  are those instructions' own source lines. That makes a line table
  trustworthy as a statement-level map even where the body is asm, and it is
  how the gaps here read as comments between one-instruction-per-line asm
  rather than as C.

The C version is not merely awkward, it is inexpressible: the epilogue is
`ldr lr, =OS_IrqHandler_ThreadSwitch; bx r0`, i.e. the handler's *return*
address is a named function, which no C call can say. Write the body as

```c
asm void func_01FF80F0(void)
{
    ...
    ldr     lr, =func_01FF8148
    bx      r0
}
```

and the pool words come out as real `R_ARM_ABS32` relocations, so `d_02FE0020`
attests itself as a `literal` (two other pools name it, e.g. 0x02084810) and
`func_01FF8148` as an `sdk` symbol. Hardcoding `dcd 0x02FE0020` instead also
compiles to the same 88 bytes, but it puts the two addresses in the file as
bare constants and leaves the shard with nothing to record.
