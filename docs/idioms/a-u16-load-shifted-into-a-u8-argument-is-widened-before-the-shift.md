# A halfword shifted into a byte argument is widened before the shift

summary: `ldrh; lsls #21; lsrs #24` feeding a `u8` argument is `(u32)halfword >> 3`; shifting the promoted signed halfword or narrowing it before the shift leaves extra instructions.

Found in: `src/matched/ov/ov128_func_021C9CCC.c` and `src/matched/ov/ov128_func_021C987C.c`.

The destination parameter is `u8`, as shown by its matched ARM9 callee. The
source is a `u16` load. This spelling reproduces the four-byte shift pair:

```c
extern void blit(unsigned char width, unsigned char height);
blit((unsigned int)q[0] >> 3, (unsigned int)q[1] >> 3);
```

The unsigned cast belongs before the shift. It avoids the signed integer
promotion of `q[0]`, and the conversion at the call folds into that shift.
The result retains eight bits after shifting, not five: `(q[0] >> 3) & 31`
is a different value and emits an arithmetic shift, mask, and narrowing pair.
In 021C9CCC that candidate compiled to 74 bytes versus the original 64.
`(u8)q[0] >> 3` also differs in value and leaves an initial narrowing pair
before the final pair; it compiled to 72 bytes. The widened spelling compiled
to 64 bytes and EXACT. Applying it to both dimensions in 021C987C gave EXACT
at 112 bytes on its first compile.

This refines the unsigned narrowing case in
`unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md`: both the
promotion before the shift and the callee's narrow argument type matter.
