# A pair copy with the destination pool load between the two loads is memcpy

summary: when an 8-byte copy between two globals loads the first source word, then the
destination's pool word, then the second source word (`ldr rX,[rS]; ldr rD,=dst; ldr rY,[rS,#4]`),
the source is `memcpy(dst, src, 8)`. mwcc's inline lowering of a constant-size memcpy gives that
order; struct assignments and scalar word copies put the destination pool load after both loads.

Found in: src/matched/ov/ov114_func_021C8D14.c (0x021C8D14), src/matched/ov/ov114_func_021C8770.c
(0x021C8770).

Shape: `ldr r1,=src; ldr r3,[r1]; ldr r5,=dst; ldr r2,[r1,#4]; str r3,[r5]; str r2,[r5,#4]`.

Wrong C: `*(Pair *)dst = *(Pair *)src;`, `dst[0] = src[0]; dst[1] = src[1];`, a u64 copy (becomes
ldm/stm), a Pair temporary, an inline getter or setter. All leave the destination pool load after
both source loads, or move the stores.

Right C:

```c
#include "../../matched/arm9_sdk/libc/string.h"
extern const unsigned d_src[];
extern unsigned d_dst[];
...
memcpy(d_dst, d_src, 8);
```

Note: this corrects a-pool-word-order-residue-is-a-list-scheduler-tie.md, which said no C shape
reaches this order for a pair copy. A memset of the same size does not give the equivalent order
for zero stores (tried on ov013 021B3018).

Source const or not: test both. In ov114 021C9530 the source had to be a non-const extern
(`u32 d_021D4090[]`); a const source hoisted the source pool load and gave 38 bytes off. The
two twins above match with a const source.
