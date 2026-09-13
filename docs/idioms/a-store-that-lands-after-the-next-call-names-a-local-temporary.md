# A store into a field that lands after the next call means the source held the value in a local first

summary: `obj->f = alloc(); clear(obj->f);` stores before the second call and
`p = alloc(); clear(p); obj->f = p;` stores after it, and the two spellings
also disagree about which register is callee-saved and whether a shared
constant stays live across the call, so the one displaced `str` drags
seventeen bytes of register numbering with it.

Found in: the near miss at 0x02006CBC, described in the header of
`src/matched/unit_02006B20.c`

The constructor allocates a 0x2014-byte buffer, clears it, and hangs it off
the object. The original is

```
blx  func_02030734          /* the allocation */
ldr  r2, [pc, #0x40]        /* 0x2014, reloaded */
movs r1, #0
adds r5, r0, #0
blx  MI_CpuFill8
str  r5, [r4, #0x24]        /* the store, AFTER the clear */
```

Written the compact way, `obj->unk24 = func_02030734(...); MI_CpuFill8(obj->unk24, 0, 0x2014);`,
the compiler stores the result into the field immediately and reloads it for
the call, so the `str` moves three instructions earlier. That alone would be a
two-halfword diff. It is not: the source shape also decides the register
allocation of the whole tail, because

* the object and the buffer swap between `r4` and `r5` for the rest of the
  function, which moves every subsequent field access and the `movs rN, #1`
  that feeds a bitfield write, and
* the size constant is used twice, once as an argument to each call. With the
  temporary, the compiler reloads it from the literal pool before each call, so
  it costs nothing but a second `ldr rN, [pc, #k]` against the *same* pool
  word. Without it, register pressure drops far enough that the compiler parks
  0x2014 in a callee-saved register and spends `adds r1, r4, #0` and
  `adds r2, r4, #0` instead.

Seventeen bytes differ between the two, and all of them are register numbers
and the position of one `str`.

The general reading: when a call result is consumed by a second call and only
then stored, the source had a named local. The same evidence in a comparison
rather than an argument is
`docs/idioms/cmp-operand-order-names-the-temporary.md`; this is the store
form, and it is worth checking first when a function is byte-perfect up to an
allocation and scrambled after it. Two pool loads of one constant on either
side of a call are the corroborating tell, and they are not redundancy: `r1`
and `r2` are caller-saved, so a constant passed as an argument to two calls has
to be materialised twice unless something holds it.
