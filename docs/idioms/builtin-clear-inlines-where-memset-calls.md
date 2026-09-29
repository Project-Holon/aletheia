# __builtin__clear inlines an aggregate zero where memset compiles to a call

summary: An aggregate zero that appears as an inlined stm/str run in the object is `__builtin__clear(p, size)`, not `memset(p, 0, size)`; every dsi 1.1p1 build turns the named `memset` into a `bl` to 0x020923B0.

Found in: src/matched/ov_sdk/ov009_func_0218BDB8.c (0x0218BDB8); also src/pending/ov_sdk/ov009_func_0218DD88.c (0x0218DD88)

`gpiProcessGetInfo` zeroes its 240-byte local `GPIInfoCache infoCache` with a
counter loop in the object:

```
mov r0, #0
mov r1, r0
mov r2, r0
mov r3, r0
mov r4, #7
loop:
stm r7!, {r0, r1, r2, r3}
stm r7!, {r0, r1, r2, r3}
subs r4, r4, #1
bne loop
stm r7!, {r0, r1, r2, r3}
```

Writing `memset(&infoCache, 0, sizeof(infoCache))` compiles instead to a
`bl memset` (0x020923B0), which is 28 bytes short of the original and leaves the
whole tail of the function shifted. Writing
`__builtin__clear(&infoCache, sizeof(infoCache))` reproduces the loop exactly.

The same split is visible in `gpiFailedOpCallback`: the 16-byte
`GPProfileSearchResponseArg` clears inline, an object whose clear runs to a
`memset` call is the 0x204 `GPGetInfoResponseArg` case. So decide per site from
the object: `__builtin__clear` for the inlined run, a real (declared) `memset`
where the object actually branches to 0x020923B0 — `gpiProcessConnect` does that
for its 0x20 `GPConnectResponseArg`.
