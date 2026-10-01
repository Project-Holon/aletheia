# A pointer cast on a struct-array member keeps the hoisted array base and the mla form

summary: a sub-word field read out of `obj.arr[i]` where the field is not at offset 0
can be folded to `base + i*stride + off` addressed off the object base, which shrinks
the function and recolours everything; writing the base through an explicit pointer
type (`((Elem *)obj.arr)[i].field`) keeps the array base hoisted into its own register
and emits the `mla rD, rI, rStride, rBase` form. The two spellings are semantically
identical, so only the object listing shows the difference.

Found in: `src/pending/ov_sdk/ov175_func_021E11F0.c` (0x021E11F0,
DWC_GdbCancelRequest, dwc_gdb.o, ov175)

The switch has a case that logs and frees `obj.work[obj.current_work].ghttp2.request`.
`DWCiGdbWork` is a union whose `ghttp2.request` sits at offset 4, while every other arm
reads a field at offset 0. With the member written plainly:

```c
...func_021C22D4(g_021E5334.work[g_021E5334.current_work].ghttp2.request)...;
```

the compiler addresses the field as `E + i*0x38 + 4` off the object base and the whole
function drops to 328 bytes (8 short), so no layout can match. Three prior lanes and a
permuter anneal never recovered the original 336-byte listing from this spelling.

Writing the base through the element pointer instead:

```c
...func_021C22D4(((DWCiGdbWork *)g_021E5334.work)[g_021E5334.current_work].ghttp2.request)...;
```

pins `&obj.work[0]` (0x021E534C) into its own callee-saved register at entry, emits
`ldr rI,[E,#0x14]; mla rD,rI,#0x38,rBase; ldr r0,[rD,#4]`, and restores the 336-byte
stream (still 22 byte colouring residue, but instruction-and-size exact). The cast is
on the *base*, not the index, so the index stays a plain subscript; casting every
occurrence of the member is neutral (the offset-0 arms already fold to an indexed load).

Rule: when a function is byte-short and a union/struct-array member with a non-zero
inner field is involved, check whether the vendor source took the address of the array
through an element pointer rather than subscripting the struct member directly. The
plain subscript lets the compiler fold the array base away; the pointer cast forces the
hoist. Cross-check against `a-char-cast-on-the-base-pins-the-base-plus-index-sum.md`,
which is the same lever for a scalar `char` base.
