# A global re-read for a later argument is a volatile pointer cast (idiom, lane U6)

summary: when the image re-reads a global *pointer variable* that it has already loaded
once a few instructions earlier, and ours CSEs the two reads into one register across an
intervening store, read the second one through `*(T *volatile *)&g`; the re-read comes back
and nothing else in the function moves.

Found in: `src/matched/ov_sdk/ov016_func_021D0B44.c` (0x021D0B44, 372 B, EXACT), SDK
member `DWCi_USBAPlBegin` (libdwcutil.TWL.HYB.a usbap.o), object stamped 4.0.0.1025.

The shape. The image loads the global pointer once for the store target, stores through it,
and then loads it *again* for the next call:

```
002C ldr r3, [r5]            ; g_021DE654
0030 mov r2, #3
0034 add r3, r3, #0x1000
0038 str r0, [r3, #0xb88]    ; ->start
003C str r1, [r3, #0xb8c]
0040 ldr r0, [r5]            ; re-read for the call
0044 ldr r1, [pc, #0x114]
0048 bl WM_Initialize
```

With a plain `WM_Initialize(g_021DE654, ...)` mwcc 1.1p1 keeps the first load in a
callee-saved register and passes it on (`mov r0, r4`), so the diff is 4 lines / 9 bytes and
the sizes are equal (372). The store in between is through a pointer *derived from the
global's value*, which is exactly what makes the vendor's build conservative and ours not.

The lever: spell the second read as a volatile access to the pointer variable.

```c
rs = WM_Initialize(*(MemUsbT *volatile *)&g_021DE654, func_021D0DE0, 3);
```

That emits `ldr r0, [r5]`, forces the reload, and the whole function goes EXACT; the
symbols line and the relocation list are unchanged (one pool word, one data symbol).

Flat before this (nine variants): array-of-one global `g[1]` with `g[0]`, `->wmBuf`
(offset 0 member), `(void *)` cast, `&g->wmBuf[0]`, a block-local copy of the pointer,
merging `tick` into the store, `tick = tick;`, declaration reorders, and both
`../2.0/base` and `../2.0/sp1p2` (392 B, still `mov r0, r4`).

Related: `docs/idioms/a-global-reread-across-an-extern-call-cannot-be-cached.md` covers the
re-read across a *call*; this one is the re-read across a *store through the loaded value*,
which is the tell that the diff is a permutation around two stores.
