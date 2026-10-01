# A walker pointer absent from the DWARF is a reused parameter, not a local

summary: when the DWARF local list for a function has no walking-pointer
variable even though the C body needs one, the original source reused an
incoming parameter (or an already-declared local) as the pointer; inventing a
separate pointer local adds a live value, forces an extra callee-saved register
into the prologue (`push {r3, ...}`) and spills a constant, and the whole
function comes out several bytes long.

Found in: `src/pending/ov_sdk/ov172_func_021C0440.c` (`GetAPP1`, 0x021C0440)

`GetAPP1` has a `p` pointer that walks three IFDs. The defining object's DWARF
lists only `AppLen, len, Endian, tag, type, count, ValueOffset, next, exif,
maker, inter, thumb` -- no `p`. The object prologue is
`push {r4,r5,r6,r7,r8,sb,sl,fp,lr}` / `sub sp,#0x24`, keeps the `0xffff`
sentinel in `r4`, and has `cur` in `r8`. The C spelling with a `u32 p;` local
compiled to `push {r3,...}` / `sub sp,#0x28` with `cur` in `r4` and the
sentinel spilled and reloaded (`str r4,[sp,#0xc]; ldr r1,[sp,#0xc]`): the
extra live local consumed the register the allocator needed.

Replacing every `p` with `cur` -- the parameter -- and deleting `p` reproduces
the object prologue byte for byte. The same function also had a select
temporary (`w`) that appears nowhere in the DWARF; inlining the
`(count <= 4) ? (cur - count) : ValueOffset` select directly into the field
assignment removed it. Both are the same tell: **an obvious source temporary
that the DWARF does not name is not a real variable**. Read the DWARF local
list as an upper bound on your named locals; a walker or a select temp that is
absent means the value was reused from an existing name.

## See also

- `declaration-order-decides-which-register-a-local-gets.md`
- `reusing-a-loop-variable-across-phases-changes-the-allocation.md`
- `a-constant-loaded-at-entry-into-a-callee-saved-register-is-a-declaration-initialiser.md`
