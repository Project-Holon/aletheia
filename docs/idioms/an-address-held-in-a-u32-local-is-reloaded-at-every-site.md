# An address held in a u32 local is reloaded from the pool at every site, not cached

summary: when the image loads one pool word into r0 before each of several calls (`ldr r0, [pc, #K]` three times, one literal) where 1.1p1 caches the address in a callee-saved register, assign `(u32)&sym` to a u32 local and cast it back at each call. 1.1p1 then rematerialises the address per site instead of value-numbering it once, and the register the cache would have taken stays with its original value.

Found in: src/matched/func_0201C7D0.c (0x0201C7D0)

The image passes the static scratch `g_0214655C` as the first argument of
three calls and reloads it every time from one pool word:

    ldr r0, [pc, #0x20]   ; &g_0214655C
    ...                   ; r1..r3, then str r4, [sp] (z) last
    bl sub_0201C808
    add r1, sp, #0x18
    ldrh r1, [r1, #4]
    ldr r0, [pc, #0x10]   ; same word
    bl sub_0201C8A4
    ldr r0, [pc, #8]      ; same word
    bl func_0201C8BC

Source that matches (dsi/1.1p1):

    u32 base;
    func_02045A90(s);
    base = (u32)&g_0214655C;
    sub_0201C808((struct Scratch *)base, w, x, y, z);
    sub_0201C8A4((struct Scratch *)base, v);
    func_0201C8BC((struct Scratch *)base, s);

Wrong spellings measured over eight waves:
- `&g_0214655C` at every site, or `(struct Scratch *)(u32)&g_0214655C` inline
  at a site: 1.1p1 caches the address in r4, schedules the outgoing `str z,
  [sp]` straight after the first call to free r4 (37 out);
- a second and third extern name at the same address: every instruction
  right, but three pool words (64 bytes against 56);
- ../2.0/sp2 reloads per site but forms the stacked u16 read off `add r1, sp,
  #8` (2 out), and no front end gave both traits.

The integer local is a web of its own, defined from a relocated constant,
which the allocator rematerialises at each use rather than keeping in a
callee-saved register; the inline cast is folded before value numbering and
changes nothing. The same spelling closes the two-site sibling
func_0201C7A4 under 1.1p1 (EXACT, 44 bytes), which had needed the sp2 pin.

Tell: one pool word loaded into r0 at several call sites under a 1.1p1 body
(the 1.1p1 stacked-halfword base, no ARMv4T return), where 1.1p1 compiles
`adds r0, r4, #0` copies from a cached r4. Related: the region-symbol form in
docs/idioms/a-region-symbol-cast-to-u32-keeps-the-bound-an-add.md.
