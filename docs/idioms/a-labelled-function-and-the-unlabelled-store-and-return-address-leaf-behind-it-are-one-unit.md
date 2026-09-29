# A labelled function and the unlabelled `*p = k; return &d;` leaf behind it are one unit

summary: an overlay extent that ends in `movs r1,#k; str r1,[r0]; ldr r0,[pc]; bx lr` plus a pool word is a second, unlabelled leaf (`int *f(int *p) { *p = k; return &d_X; }`); `tu` over the whole extent, with the leaf named on the `function:` line, gives EXACT and the leaf's data pool word resolves as sole-ref.

Found in: `src/matched/ov/ov093_func_021DE598.c`, `ov093_func_021DE5DC.c`,
`ov093_func_021DE79C.c`, `ov093_func_021E2A80.c`, `ov093_func_021E2700.c`,
`ov093_func_021E300C.c`, `ov093_func_021E39C0.c`, `ov093_func_021E556C.c`,
`ov093_func_021E6220.c`, `ov093_func_021E7164.c` (about sixty ov093 units in all,
0x021DE598-0x021E7B8C)

`show` for each such ov093 handler prints the function plus eight to twelve
bytes that look like data after the `pop`. They are a 4-aligned Thumb leaf (a
two-byte `movs r0,r0` pad precedes it when the function's own pool or size
leaves the address unaligned) whose pool word is a data address. Write it as
an `int *` function with `extern int d_<ADDR>;`, list both functions on
`function:` lines of a `unit: yes` file named for the handler, and run `tu`,
not `one`. `one` on the handler alone prints EXACT* and leaves the leaf
unmatched.

When `tu` calls the leaf's data hint contested, drop the `ovNNN` token and
keep `data a4`.

A variant ends the extent in a forwarder (`push {r3, lr}; bl; pop {r3, pc}`,
0x021E3544 in `ov093_func_021E34FC.c`): it is a four-parameter function that
passes all four, as `a-tail-call-cannot-pass-a-fourth-argument.md` says.
