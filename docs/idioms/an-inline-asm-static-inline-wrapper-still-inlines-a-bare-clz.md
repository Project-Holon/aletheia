# a `static inline` asm wrapper still inlines a bare `clz` — do not park the caller

summary: a `clz` in the caller of an SDK function does not mean the whole caller
is hand-written asm: a `static inline u32 clz32(u32 x) { asm { clz x, x } return
x; }` inlines to exactly `clz Rd, Rd`, so the surrounding C body can be ordinary
C. The "a clz means hand-written asm" rule is about the function whose BODY is a
`clz`, not about anything that computes one.

Found in: src/matched/ov_sdk/ov009_func_021671C0.c (0x021671C0)

`WcmWmcbScanEx`'s image has `ldrh r0,[r4,#0xa]; clz r0,r0; rsb r0,r0,#0x20;
lsl r0,r0,#0x10; lsr r0,r0,#0x10` feeding `WCMi_GetNextScanChannel`, i.e.
`(unsigned short)(32 - clz(channelList))`. A prior lane read
docs/idioms/a-clz-means-a-hand-written-asm-body-not-an-intrinsic.md and parked
the function as inexpressible. It is not: the same spelling already used in
src/matched/ov/ov013_func_021B11E8.c

```c
static inline unsigned long clz32(unsigned long x)
{
    asm { clz x, x }
    return x;
}
```

emits the single `clz r0, r0` in place (the argument is live in r0) and the
`rsb r0, r0, #0x20` falls out of `32 - clz32(...)`. The intrinsic-spelling hunt
the other idiom describes is still a dead end (`__cntlzw` et al. become a
`bx` to an ABS32); the inline-asm wrapper is the supported route. Only reach for
`asm void` for the whole function when the *body* is one instruction per line.
