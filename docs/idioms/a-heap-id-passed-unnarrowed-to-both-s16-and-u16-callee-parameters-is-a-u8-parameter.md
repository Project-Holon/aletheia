# A heap id passed unnarrowed to both an s16 and a u16 callee parameter is a u8 parameter

summary: when one parameter is forwarded with no `lsls`/`lsr|asr` pair to
callees whose matched prototypes take it as `s16` in one call and `u16` in
another, declare your own parameter `u8`. A `u8` value converts to both with no
code. `u16` sign-extends for the `s16` call, `s16` zero-extends for the `u16`
call, and `u32` truncates for both.

Found in: `src/matched/ov/ov204_func_021BDFA4.c`,
`src/matched/ov/ov204_func_021BE03C.c`

Both functions set up the 3D engine and a camera:
`func_02046440(..., u16 fifoSize, s16 heap, setup)`, then
`func_02048A24(..., Vec3 *, u16 heap)`, then `func_02048BC4(set, u32 heap)`.
The original keeps the incoming heap in r4 and stores it as a word to
`[sp, #4]` and `[sp, #0x1c]`, then moves it into r1, without narrowing it
anywhere:

```
adds r4, r1, #0
str  r4, [sp, #4]        /* 02046440's s16 heap */
...
str  r4, [sp, #0x1c]     /* 02048A24's u16 heap */
...
adds r1, r4, #0          /* 02048BC4's u32 heap */
```

With the callees' exact prototypes and the own parameter at each width
(dsi/1.1p1 -O4,p):

| own `heap` | result |
| --- | --- |
| `u32` | 160 bytes: a narrowing pair before each 16-bit call |
| `u16` | 156 bytes: `lsls #16; asrs #16` before the `s16` store |
| `s16` | 156 bytes: `lsls #16; lsrs #16` before the `u16` store |
| `u8` | EXACT |

Earlier lanes got this shape to match by widening the callees' heap
parameters to `unsigned` (matched twins `ov182_func_021B9B20.c` and
`ov208_func_021BD0AC.c` declare 02046440's heap `u16`/`u32`). That copies a
prototype that differs from the callee's own definition. A `u8` own
parameter keeps every callee prototype exact. Before using this spelling,
check that the callees really disagree on signedness. If they all take
`u16`, a `u16` parameter already matches.
