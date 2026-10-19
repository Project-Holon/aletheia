# A spilled pointer plus a constant argument: store the sum in the local

summary: When a spilled pointer is passed as `ptr + const`, store the sum in the local where the
call result arrives. This gives the original r2/r3 choice.

Shape in the listing (ov172 func_021B9044, wave D3):

```
ldr r3, [sp, #0x10]     ; spilled local
movs r2, #2
lsls r2, r2, #0xa       ; 0x800
adds r2, r3, r2         ; argument = local + 0x800, constant in the target register
```

A draft that keeps the raw call result in the local and writes `base + 0x800`
at the call gets the same instructions with r2/r3 swapped
(`ldr r2, [sp]; ... adds r2, r2, r3`).

Fix: assign the sum to the local where the call result arrives,
`short *tbl = (short *)(f(p) + 0x800);`, and pass `tbl`. The compiler still
spills the raw result and rebuilds the sum at the call, but now with the
original register choice.

Related: locals narrower than 4 bytes (u8, u16) take the lowest spill slots
regardless of declaration order. If the original has a u8/u16 value above a
pointer or int, declare it `int` and keep the narrowing as an explicit cast at
the assignment (`int h = (u16)(...)`), as in ov172 func_021B71B8.
