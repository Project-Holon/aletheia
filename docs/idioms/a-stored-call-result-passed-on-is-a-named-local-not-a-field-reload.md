# A call result stored then passed on stays live through a named local

summary: When a call result is stored through a raw offset and then passed to another call, reading the field again can emit a fresh load. Keep the result in a named local when the original passes it without reloading, including across a switch whose default consumes it.

Found in: src/matched/ov/ov100_func_021BA3A4.c (0x021BA3A4), src/matched/ov/ov100_func_021BA1D0.c (0x021BA1D0).

At 0x021BA3E2 the constructor returns in r0. The original stores that result
at the object's +0x27c offset, then calls func_02045374 with r0 unchanged.
The spelling

```c
*(int *)(a + 0x27c) = func_020450F0(5, 1, 1, 30, 5, 13, 0);
func_02045374(*(int *)(a + 0x27c));
```

emits an extra address copy and load: 178 compiled bytes, DIFF. Binding the
result to `int v`, storing `v`, and calling `func_02045374(v)` produces the
174-byte EXACT* function; two trailing original bytes are zero padding.

At 0x021BA24E the menu constructor likewise returns in r0. The original
stores it at +0xcc0, dispatches three special cases using r1, and passes
the still-live r0 to func_02027CD8 in the default arm. Reading +0xcc0 again
adds address setup and a load, and frees r0 for the switch index. The matching
spelling is `v = func_02027778(...); *(int *)(a + 0xcc0) = v;` followed by
`func_02027CD8(v, 1)` in the default arm. This function also needed the first
allocator to consume the already-loaded template heap field; that separate
change removes an earlier halfword reload.

This differs from delaying a store until after the second call: both original
functions store before the next call. The local prevents a redundant field
read while preserving that store order.
