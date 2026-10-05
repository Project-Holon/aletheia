# A stack reload kept after an unrelated store is a `short` parameter

Shape: a parameter spilled at entry (`str r1,[sp,#0x14]`) and reloaded for each call. At one call the
image keeps the reload after an unrelated outgoing-argument store (`str r6,[sp]; ldr r0,[sp,#0x14]`),
and ours hoists the reload above that store. Probes show that a real memory load gives the image
order, but no address-taking form does without a frame change.

Fix: declare the parameter `short` (s16). The value is passed unchanged to callees with `int`/`u32`
parameters, and a u16 cast at one callee gives the only `lsls/lsrs #0x10` pair in the image. A
`u32` or `u16` parameter does not give the order (u16 removes the one truncation; u32 hoists the
reload).

Closed: ov116 021D7D0C (wave D9r, after 10 bytes in waves D3 to D9r).

Check: if the image truncates a heap id (or other id) with `lsls/lsrs #0x10` at only one call and
passes it unchanged to all others, try the parameter as `short`.
