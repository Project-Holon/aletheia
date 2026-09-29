# A shift recomputed from a spilled value at each use differs by a cast between the uses

summary: when the image keeps a value raw in a stack slot and re-shifts it
(`ldr rN,[sp]; lsls rN,rN,#k`) at every use while mwcc CSEs the shift into a
saved temporary (an extra slot or register, a different frame), spell one use
through a cast, `(u32)x << k` or `(u32)i * 16`, and the others plain: the two
are different expressions to 1.1p1's CSE, so neither is cached.

Found in: `src/matched/ov/ov021_func_021B9C28.c` (0x021B9C28),
`src/matched/ov/ov021_func_021BE418.c` (0x021BE418)

## func_021B9C28

Two accessor results `t1`, `t2` are used as `t1 << 12` / `t2 << 12` twice,
once for a ratio call and once inside an FX multiply-divide. The image:

```
str  r0, [sp]          ; t1
...
str  r0, [sp, #4]      ; t2
ldr  r0, [sp]
ldr  r1, [sp, #4]
lsls r0, r0, #0xc
lsls r1, r1, #0xc
blx  func_0207C768
...
ldr  r2, [sp]          ; t1 again, shifted again
lsls r2, r2, #0xc
```

With both uses spelled `t1 << 12`, mwcc stores the shifted value instead
and the frame grows by a slot (308 vs 312 bytes, 223 bytes off). Earlier
lanes tried `int t[2]`, a struct, inline ToFx helpers, `* 0x1000` mixed with
`<< 12` and narrow locals; only `volatile` locals came near. Writing the
first call as `func_0207C768((u32)t1 << 12, (u32)t2 << 12)` and leaving the
second use plain is EXACT (casting the second use instead works too).

## func_021BE418

Index `i` (a `u16` parameter) gives `i << 4` for a slot test, an entry
pointer and the final store (one CSE kept in r7), and three more field reads
after the loop that the image recomputes from the spilled `i` into r4 as
`p + r4` per field. `i << 4` everywhere CSEs the tail too and no spill
happens; `(u32)i * 16` in the tail (`p + 0x10 + (u32)i * 16`) and `i << 4`
elsewhere is EXACT. With a `u32` parameter, `i * 16` against `i << 4` was
enough to split the CSE, but the home-store placement then needed the `u16`,
under which only the cast keeps them apart.

## When to reach for it

A value reloaded from its stack slot and shifted again at a second use, with
the compiled version holding the shifted value instead, is this. Put the
cast on one group of uses; if the register or slot assignment is still off,
move it to the other group.
