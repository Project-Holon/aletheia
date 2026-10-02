# A const source pointer hoists the last load of a struct copy into an address-taken local

summary: `Rect4 old = *r;` (four u16 fields) into a local whose address is later
passed to a call compiles in source order, `ldrh; strh` x4. When the original
pairs the last two loads (`ldrh r3,[r0,#4]; ldrh r0,[r0,#6]; strh r3; strh r0`),
declare the source parameter `const Rect4 *r`. `__restrict` on r (or on a
helper's destination) does not do it when the destination is a local; that
lever only works when the destination is itself a `__restrict` parameter
(see a-restrict-table-parameter-hoists-a-load-above-a-store-only-at-a-different-offset.md).
Give the callee that receives r a `const` parameter rather than casting.

Found in: `src/matched/ov/ov021_func_021B7CD8.c` (0x021B7CD8, ov021)
