# A loop entered by a branch to its bottom test, with an unfolded constant first test, has a `? 1 : 0` condition

summary: under 1.1p1 -O4,p a `for`/`while` whose condition is a plain relational
test is rotated (the first test is peeled, or folded away when the start value is
a constant); written as `(cond) ? 1 : 0` the loop keeps the unrotated shape: a `b`
straight to the bottom `cmp`/`b<cc>` pair, even for `for (i = 0; ...)`. Try this
before reaching for inline asm, which gives the same loop shape but also changes
constant handling elsewhere in the function.

Found in: src/matched/arm9_sdk/func_020898A8.c (0x020898A8, SND_CommandInit),
src/matched/arm9_sdk/func_0208E038.c (0x0208E038, WmInitCore), and
src/matched/arm9_sdk/func_02075ED4.c (0x02075ED4, CARDi_LockResource, card lane)

## The tell

A counted loop with a constant start and bound that the compiler did not peel:

```
mov  ip, #0
...
b    test               ; enters at the test although i = 0 < 255 is known
loop:
...
add  ...
test:
cmp  ip, #0xff
blt  loop
```

The same shape shows on a `while` with a non-constant condition
(`CARDi_LockResource`: `b` to `ldr/cmp/bne`, where a plain `while` puts a peeled
test in front of the loop instead).

## What the plain spellings do

`for (i = 0; i < 255; i++)`, `while (i < 255)`, `goto` loops and every opt pragma
tried give the rotated form: no leading `b`, and the entry test is either peeled
in front of the loop or dropped because `0 < 255` folds. `for (;;)` with a `break`
gives a top-tested loop. `-O2` gives the unrotated form, but the other functions
in the same objects only match at `-O4,p`.

## The fix

```c
for (i = 0; (i < 256 - 1) ? 1 : 0; i++) {
    sCommandArray[i].next = &sCommandArray[i + 1];
}
```

The ternary reaches the back end as a plain `cmp`/`blt`, so it costs no bytes.
The loop-rotation pass does not treat it as a simple relational condition, so
the loop keeps the shape it was written in.

## Inline asm gives the same loop shape, but it is not the explanation here

The vendor objects do have functions with this shape that contain inline asm.
In the compiled C functions of the ARM9 TWL.HYB libraries that hold an inlined
`clz` (the math header's count-leading-zeros helper, e.g. DSPi_MapProcessSlotDefault,
DSP_AttachProcessMemory, MATHi_FFT, MI_InitCache in dsp_process.o, fft.o,
mi_cache.o), most loops are entered this way. A few loops in DSPi_FileIOProc and
libwbt have no entry branch; those were not examined. Any asm statement puts mwcc in a mode that
keeps the unrotated loop, and a zero-byte `asm { .align 4 }` reproduces
WmInitCore and SND_CommandInit. But that mode also stops constant folding
(`if (0)` inside an inlined helper stays as `movs`/`movne`, and a loop counter's
zero can come from a pool word), and neither function has an asm instruction, a
DWARF trace of an inlined helper, or a line-table row outside its own `.c`. The
ternary closes both with ordinary C, so file it that way. Use the asm reading
only when the body also shows an asm instruction (`clz`, `mrs`, `msr`, `mcr`).

Other ARM9 SDK functions with the same sign and no asm instruction, useful as
checks if they come up: CTRDGi_InitModuleInfo, VIB_StartPulse (libctrdg),
MBi_SendVolatBeacon (libmb), CARD_InitRomHashContext (libcard),
Yos_JpegEncoderHuffmanEncoderBuildTable (libssp).
