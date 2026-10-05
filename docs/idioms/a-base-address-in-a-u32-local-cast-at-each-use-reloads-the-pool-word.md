# A global struct base held in a u32 local and cast at each use reloads the pool word per access

summary: when the image loads the same pool word (`ldr rN,[pc,#K]`, one literal) before every field read of one extern struct, and every direct spelling (`extern struct`, array, volatile, literal address, aligned extern) shares one base register, write `u32 gb = (u32)&d_X;` at the top and `#define G ((const struct T *)gb)`, then read `G->field` at each use. The compiler then rematerialises the address per site.

Found in: `src/matched/ov/ov217_func_021BD178.c`, `ov217_func_021BD274.c`, `ov217_func_021C05B0.c`

This is the same lever as `an-address-held-in-a-u32-local-is-reloaded-at-every-site.md`, applied to a struct whose fields are read in separate statements (heap arguments, a colour word, a message lookup, a draw call). Declare the u32 local after the table copy and before the first use.

After the loads match, check the rest of the shape against the twin: the colour word `(f1e & 0x1f) | ((f1c & 0x1f) << 10) | ((f1d & 0x1f) << 5)` must be written `a | (c | b)` (orrs r1,r2 first, then orrs r0,r1), and the blit loops use `i` outer with `int y = i * 8;` inside, tab indexed `tab.r[i].w[j]`.
