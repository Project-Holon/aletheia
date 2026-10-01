# A scalar halfword stack argument avoids the aggregate partial store

summary: When a fifth halfword input is loaded with ldrh but stored to the outgoing stack with str, declaring it as a scalar u16 reproduces the full-word store; a two-byte bitfield aggregate emits an add-to-sp and strh instead.

Found in: src/matched/ov/ov217_func_021C2C70.c, src/matched/ov/ov217_func_021C2CB0.c, src/matched/ov/ov217_func_021C2D28.c.

These callers pass the color field at +0x12 to func_02021F64. Its existing ARM9 source declares a two-byte Rgb555 bitfield aggregate as the fifth input. The actual body reads only the low halfword of that stack slot. The original caller loads that field with ldrh and writes the outgoing slot with str.

```c
extern void func_02021F64(unsigned short *, unsigned short *,
                         unsigned int, int, unsigned short);
func_02021F64(src, dst, count, weight, *(unsigned short *)(p + 0x12));
```

Copying the aggregate fifth parameter emitted a stack-address calculation and strh, making the call setup two instructions longer. The scalar declaration reproduced the original stack word and exact bytes. The three scalar callers are ABI compatible with the callee's halfword load. Record that body and call-site evidence when using this declaration exception; leave the owned callee source unchanged. This is not a rule for aggregates the callee reads at a larger width.
