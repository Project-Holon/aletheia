# Array bases spelled as pointer locals reopen a declaration-order search that was flat

summary: a base-plus-offset array address kept as a u32 offset local and added at each use can
compile to the same bytes as a pointer local computed once, yet leave a register tie that no
declaration order closes; respelling it as the pointer local (the NitroSystem pArrayXxx shape)
and re-sampling declaration orders can close it.

Found in: src/matched/func_0206FC5C.c (0x0206FC5C)

func_0206FC5C (the NNS g3d rotation lerp sampler) passes two key arrays to func_0206FFA0 at
three call sites, each as the header address plus an offset read from the header.  The image
forms `add r1, sb, r4` at every call site, which reads naturally as an offset local `oa = h->f0c`
added at each call.  That spelling was 836 bytes against 836 with 8 concrete bytes out (the data
cursor p and oa in each other's registers) and stayed at 8 over more than 650 declaration orders
and several permuter anneals in waves 9 to 16.

Spelled the way NitroSystem writes these arrays, `s16 *oa = (s16 *)((u8 *)h + h->f0c);` once at
the top, the compiler still re-forms the address at each call site, so the instruction stream is
unchanged, but the register assignment moves (39 out with the old order).  A 200-order sample of
the ten scalar declarations of that form then finds several EXACT orders.  When a same-size tie
survives an exhaustive order search, change the declared type or shape of the tied value (offset
versus pointer, index versus element pointer) and search again rather than re-running the same
space.
