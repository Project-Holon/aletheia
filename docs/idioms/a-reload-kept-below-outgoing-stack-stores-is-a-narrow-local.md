# A reload kept below the outgoing stack stores is a narrow local

summary: when the image reloads a spilled local after the outgoing stack-argument stores of a call
(`str r6,[sp]; ... str r0,[sp,#8]; ldr r2,[sp,#K]; adds r2,r7,r2`) and the build hoists that reload
(and its add chain) above the stores, declare the local narrow (u8, u16, s16 or signed char). mwcc
hoists the reload of a spilled `u32`/`int` local but keeps the reload of a spilled narrow local in
place.

Found in: src/matched/ov/ov097_func_021F6D70.c (0x021F6D70, ov097, Thumb), wave D9r. Same residue
as ov198 0220C16C (still a draft) and as ov116 021D7D0C (closed with a `short` parameter).

The tell that the local is narrow but the draft used u32: the width is masked with
`lsls/lsrs #0x18` before its spill store, and is then shifted with `lsrs`. A plain `u8 w8;` with
`w8 >> 1` gives `asrs` (u8 promotes to int), so the image widened the value to an unsigned type
before the shift:

```c
u8 w8;
...
w8 = func_0201D304(t1, *(u32 *)(p + 0x10), 0);
r7 = 0x5c - ((u32)w8 >> 1);                 /* lsrs; an inline helper with a u32 parameter is the same */
...
func_0201C724(f3, y, (s16)(r7 + w8), 0x20, buf, *(u32 *)(p + 0x10), 0x3dc0);
```

Caveat: the narrow local must keep its normal spill slot. A narrow local whose only early use is
a signed shift (`w8 >> 1` as asrs) moves to the lowest slot and its reload is hoisted again.

How it was found: use an existing narrow local of the same function (the s16 x of an earlier block)
as the operand at the residue site. If that gives the image order and a u32 copy does not, the
type of the spilled value is the lever.
