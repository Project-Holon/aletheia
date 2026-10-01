# A `pos = 0; buf[pos++] = ...` accumulation settles a whole callee-saved rotation

summary: when the entire callee-saved register file is rotated one slot and the
body is otherwise instruction-for-instruction correct, and every declaration
order, scope and front-end lever has been measured inert, the lever can be the
*shape* of the byte writes: writing a header as constant indices plus a folded
`pos = 7` lets the allocator colour a live local late, while the vendor's
`int pos = 0; buf[pos] = ...; pos++;` accumulation colours it early and rotates
every callee-saved home back into place.

Found in: `src/matched/ov_sdk/ov009_func_0219D5C4.c` (0x0219D5C4, ov009,
`QEStartQuery`, libdwcgsserverbrowsing.TWL.HYB.a(sb_queryengine.o), ARM).

The image homes `querySuccess` in `r4` ahead of the two parameters (`server`
r5, `engine` r6), with two zero constants in r7/r8 and `queryBuffer` in sb. The
build homed the parameters first (`server` r4, `engine` r5) and pushed
`querySuccess` to sb: 140 concrete bytes over 78 sites, a pure one-slot
rotation. The sdkobj DWARF pinned the intended homes and the GameSpy upstream
was available, but the declarations alone were inert. What moved it was
transcribing the vendor's QR2 header writes literally:

```c
/* inert: 140 B */
queryBuffer[0] = 0xfe;
queryBuffer[1] = 0xfd;
queryBuffer[2] = 0;
__memcpy(&queryBuffer[3], server->challenge, 4);
challengeNBO = ...;
pos = 7;
if (challengeNBO != 0) { __memcpy(&queryBuffer[pos], &challengeNBO, 4); pos += 4; }

/* EXACT: 0 B */
challengeNBO = ...;                 /* computed before the writes */
pos = 0;
queryBuffer[pos] = 0xfe; pos++;
queryBuffer[pos] = 0xfd; pos++;
queryBuffer[pos] = 0;   pos++;
__memcpy(&queryBuffer[pos], server->challenge, 4);   /* pos is 3 here */
pos += 4;
if (challengeNBO != 0) { __memcpy(&queryBuffer[pos], &challengeNBO, 4); pos += 4; }
```

The accumulation alone took the residue from 140 bytes to 8; moving the
`challengeNBO` expression *above* the writes removed the last 8, which were a
store-scheduling difference (`str challengeNBO` before the final two memcpy
bytes in the image, after them otherwise).

Two things worth naming. First, this is not declaration order and not scope:
the two candidate locals keep the same function-scope declarations. The
accumulator's *definition points* are what the allocator orders by, and a
folded constant has no definition point to order. Second, it is the callee-saved
counterpart of `statement-order-of-scratch-temporaries-decides-their-registers.md`
(scratch half) and `declaration-order-decides-which-register-a-local-gets.md`
(long-live-range half): when a rotation survives every declaration permutation,
try rebuilding the accumulator from its zero exactly as the vendor wrote it.

Related: `a-no-code-self-assignment-reorders-the-register-colouring.md` is the
fallback when the source shape is already right and only the allocator tie
remains; here the source shape itself was the lever, so try the accumulation
first.
