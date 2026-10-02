# An enum scalar constructor preserves bitfield masks without an aggregate frame

summary: A zero-initialized enum scalar updated with explicit masks keeps the redundant bitfield operations while avoiding the unused frame emitted for a local aggregate or an address-taken scalar.

Found in: src/matched/ov/ov093_func_021D8358.c (0x021D8358), src/matched/ov/ov093_func_021D83C4.c (0x021D83C4), src/matched/ov/ov093_func_021D83FC.c (0x021D83FC).

These word constructors begin with zero, clear a low four-bit field, and OR a constant into it. They then clear and insert the other observed fields before storing the complete word. The clear of the zero value remains in the image.

A local bitfield struct initialized with `{0}`, a union initialized through its word, and a scalar accessed through a bitfield pointer all retained the operations but also emitted a dead four-byte frame and its stack alignment push. An enum scalar preserves the operations without taking a local address:

```c
typedef enum { ZERO = 0 } Bits;
Bits t = ZERO;
t &= ~15;
t |= 6;
t &= ~0x70;
t |= (sub & 7) << 4;
*out = t;
```

With dsi/1.1p1, -O4,p, Thumb c99, this changes 021D83FC from DIFF/32 to EXACT*/24 bytes and 021D83C4 from DIFF/36 to EXACT/28 bytes. At 021D8358 it removes the frame (64 to 60 bytes); the final eight-bit insert must use `(val & 255) << 23` to reproduce the combined shift pair. An explicit `(u8)val << 23` adds an intermediate right shift.

This extends the enum constant-folding idiom to complete word constructors. The initial zero and every mask must be supported by the original word operations; it does not justify initializing unknown fields.
