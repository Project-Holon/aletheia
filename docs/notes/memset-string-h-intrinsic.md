# memset is an intrinsic only through a header named `string.h`

**Finding (lane U35, 2026-09-30).** mwccarm inlines `memset` with a constant size as a
rolled block-fill **only when the declaration comes from a header named `string.h`**
(the same rule `src/matched/arm9_sdk/libc/string.h` already documents for `strcpy`;
`memset` was not mentioned there).  A prototype written in the `.c` file itself always
produces `bl memset` plus a PC24 relocation.

This is a declaration-site artifact, not a front-end difference, so a row whose object
inlines a fill is **not** a cap on `dsi/1.1p1`:

| row | before | after |
|---|---|---|
| ov009 0x0217E078 `gsLargeIntPowerMod` | 1092/1164, `bl memset` x6 | **EXACT 1164** |
| ov009 0x021870B8 `gpiProcessRecvBuddyMessage` | 3212/3240, `bl memset` for the 28-byte fill | 3240/3240, 708 bytes out |

The 0x021870B8 header had recorded this as a "1025 vs 1.1p1" residue, and the wave brief
carried it as a verified cap.  Both are wrong: the object's six / one fills come from the
vendor including `<string.h>`, not from a build we lack.

**How to apply it.**  `#include "../../matched/arm9_sdk/libc/string.h"` (or the path
relative to your source) and *delete* the local `extern void *memset(...)`; a duplicate
prototype from the same file is what pins the call.  `memcpy` is safe: with a 0x104-byte
constant size the object still emits a call and the harness still resolves it, so one
header serves both — check the row's own relocation list before and after, because a
`memcpy` that *should* stay a call must not lose its site.

The same header also tells the front end that `strlen` writes no memory, which changes
which values stay in callee-saved registers.
