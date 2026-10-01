# `const` on a read-only source parameter rotates the parameter pair into place but hoists its loads past aliasing stores

summary: the source pointer's `const` can settle the parameter register pair
exactly as the image wants and *still* be wrong, because it also tells mwcc the
stores through the destination global cannot alias the source fields, so the
whole field-load block is hoisted above the stores. Read the first two
instructions, not the byte count, before believing the fix.

Found in: `src/pending/ov_sdk/ov009_func_021573C4.c` (0x021573C4, 536 B near
miss; not promoted).

The image holds the config parameter in r4, the destination context in r5, and
a zero in r6, with each config load interleaved with its destination store
(`ldr r1,[r4,#4] / cmp / ldrne r0,[r4,#8] / cmpne / strne r1,[r5,#0x14] ...`).
The unqualified spelling loses the tie: config r5, context r6, and the zero
claims r4, which hoists every later operand by one register (188 bytes).

Qualifying the parameter `const CPSConfig *config` immediately fixes the pair —
the compiled prologue becomes `mov r4, r0` / `ldr r5, [pc]`, matching the image
byte for byte — but the byte count jumps from 188 to 358. The `const` lets the
front end hoist the independent config loads (`ldr r2,[r4,#0x24]`,
`ldr r3,[r4,#0xc]`) above the destination stores, destroying the source order
the image has. `const` here buys the register tie and sells the schedule.

The general lesson for a source-into-destination field copy: a `const` source is
only the missing lever when the image's loads are already grouped above the
stores. If the image interleaves loads with stores, its source is *not* const —
the alias barrier is doing the interleaving — and the pair swap has some other
cause (here, a repeated-zero web reserving the low callee-saved register, see
`a-repeated-small-constant-takes-a-callee-saved-register.md`).
