# A stack parameter load sunk to the end of the entry block is a narrow parameter

## Shape

The original loads a stack parameter into its callee-saved register among the entry copies of the
register parameters, before the first call's argument set-up:

```
adds r7, r1, #0
adds r6, r3, #0
ldr  r5, [sp, #0x18]     ; stack parameter y
ldr  r1, [pc, #..]       ; first call's arguments
adds r4, r2, #0
movs r3, #0
blx  ...
```

With an `int` parameter, mwcc emits the same instructions but sinks `ldr r5, [sp, #0x18]` to the last
slot before the call.

## Source

The parameter is `s16`, and the callee that later receives it takes `s16` (copy the prototype from a
matched caller). The listing shows no sign extension anywhere: mwcc trusts the caller's extension and
passes the value through to the s16 callee parameter.

```c
extern void func_0204B550(u32 handle, s16 v, int axis);
void func_02184680(int owner, u32 handle, int entry, s16 x, s16 y, int f, u32 g, u32 h, u32 i)
```

A narrow parameter alone, with the callee still declared `int`, recolours r5..r7 (worse); both
changes together give EXACT.

## Seen in

ov168 func_02184680 (wave D9r, 8 bytes to EXACT after eight lanes of entry-block tries).
See also a-spilled-parameter-reload-scheduled-after-an-unrelated-store-is-a-narrow-parameter.md.
