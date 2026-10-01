# A global-base pointer colours above a plain loop index, and direct object access shifts it down one

summary: when a function caches the address of a global struct in a pointer
local and also runs an indexed loop whose counter is live across the loop's
call, the plain `int` loop index takes the lowest free callee-saved register
and the base pointer is coloured one register higher; spelling the global as an
object and accessing its fields directly (or a `#define` to `&obj`) frees the
index's register and moves the base down exactly one. Neither form reaches the
image when the image's base owns the very lowest register, because the index
still outranks it.

Found in: `src/pending/ov_sdk/ov009_func_02168AD4.c` (0x02168AD4,
DWCi_FriendProcess, dwc_friend.o, 668 B, 672 compiled, base off by two)

The global is a `FriendState` object in the sibling object
(`src/matched/ov_sdk/ov009_func_021692C4.c` declares
`extern FriendState s_bNeedCloseStatsConnection;`). Two spellings measured on
the same body, all 19 relocations resolving:

* pointer local cast from a `char[]` extern:
  `FriendState *state = (FriendState *)s_bNeedCloseStatsConnection;`
  -> base in **r6**, shared zero in r5 (matches the file as written);
* object extern + direct field access (`state->` rewritten to
  `s_bNeedCloseStatsConnection.`), or `#define state (&s_bNeedCloseStatsConnection)`:
  -> base in **r5**, shared zero in r6, concrete diff 397 -> 392/393.

The image wants base r4, zero r5. In both spellings the loop-1 index `i`
(declared `int`, live across `DWC_GetFriendDataType`) lands in r4 and pushes
the base up. Declaration order only ratchets the base *up* from there: with the
pointer local, `state` declared 1st -> r6, 3rd -> r7, 4th -> r8; the plain int
indices below it each take a lower register. `const`, `volatile`, `register`,
loop-scoped `for (int i...)`, the sibling's `i = 0; for (; ...; i++)` spelling,
`unsigned` counters, and reuse of `i` for the second loop all left the base at
r6/r5 (reuse moved it to r7, worse).

The practical rule: to pull a cached global-base pointer down, first try the
object-extern direct-field spelling (it buys one register), then look at which
plain loop index owns the register below it; declaration order will not put the
pointer under the index. If the image's base is the very lowest callee-saved
register, the index is the blocker, not the pointer's declaration.
