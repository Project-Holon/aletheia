# A ternary passed as a u8 argument is cast `(u8)`

summary: `lsls #24; lsrs #24` right after a two-branch merge (`b ? f(b) : 0x1f`)
before a `bl` is `(u8)(b ? f(b) : 0x1f)` when the callee's parameter is `u32`
(the same pair as the u16 idiom, at byte width).

Found in: `src/matched/ov/ov093_func_021C2BF0.c`, `ov093_func_021C2C50.c`.

See also `a-halfword-stored-raw-then-restored-is-a-one-halfword-struct-return.md`,
found alongside it.
