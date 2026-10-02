# A byte kept live into a call argument register pushes its sign extension to a fresh register

summary: when a loaded byte is sign-extended into a different register
(`ldrb r2, [..]; ...; lsls r3, r2, #24; asrs r3, r3, #24`) and nothing visible
reads r2 afterwards, look for a later call that takes the byte as an argument
in that same register. The value is already where the call wants it, so no
`movs` appears, but the extra use keeps the byte live across the extension.
That interference forces the extension, and the sum built from it, into a
fresh register. Without the use, the extension happens in place, or the
colouring rotates.

Found in: `src/matched/ov/ov021_func_021B810C.c` (0x021B810C, ov021, Thumb)

```
ldrh  r2, [r5, #0x30]
ldr   r0, =d_021DE298
ldrh  r6, [r5]
ldrb  r2, [r0, r2]        ; d, stays in r2 until the call
movs  r0, #0x2d
ldrsb r0, [r5, r0]
lsls  r3, r2, #0x18
asrs  r3, r3, #0x18
adds  r3, r0, r3
...
strb  r3, [r0]            ; o->f2D += (s8)d
cmp   r6, #1
bne   ...
adds  r0, r5, #0
bl    func_021B88DC       ; (o, k, d): r1 = k, r2 = d
```

Four rounds (about 190 compiles) treated this as a pure f2D-update problem,
with the call written as `func_021B88DC(o, k)`. The update alone has two
stable colourings, and neither has the fresh r3. A self-narrowing
`d = (u8)d;` statement keeps the ldrb and gets the image's schedule (ldrb,
f2D load, then the extension), but leaves the registers rotated (r3/r2/r0
instead of r2/r0/r3). The deciding test was a throwaway `if (d == 0) res = 0;`
after the update. It reproduced every register in the window, leaving only a
dead `cmp r2, #0`. That showed the byte had to stay live, and the matched
callee's prototype `int func_021B88DC(Ov021Mover *p, int dir, int d)` showed
where it goes.

The fix is the third argument, with the callee's int prototype and an int
`res` (a u8 `res` over an int return adds a truncation). With the call
corrected, the self-narrowing statement is not needed. Declare the table
`const u8` and keep the plain `o->f2D += (s8)d;`.
