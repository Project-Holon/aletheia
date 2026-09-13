# An aggregate assignment of about 32 bytes or less is inlined as ldm/stm

summary: a run of `ldm rX!, {r0, r1}` / `stm rY!, {r0, r1}` pairs among
field-by-field moves says those bytes are one nested struct in the source.

Found in: `src/matched/unit_02008700.c`, `src/matched/unit_02008828.c`
(0x0200890C)

`obj->unk04 = src->unk20` on a 0x20-byte struct is four `ldm`/`stm` pairs and
no call. 28 bytes comes out as three pairs plus a trailing `ldr`/`str`. The
size used is the padded `sizeof`, not the sum of the declared members.

The practical consequence is the reverse reading. A run of

```
ldm r2!, {r0, r1}
stm r4!, {r0, r1}
```

sitting in the middle of otherwise field-by-field moves says that those
particular bytes are one nested struct in the source. Getting the grouping
wrong changes the whole function rather than one instruction, because the
compiler then moves every field separately.

Above roughly 32 bytes the compiler calls a memcpy-shaped helper instead, so
the threshold is worth checking against the actual output rather than assumed.
