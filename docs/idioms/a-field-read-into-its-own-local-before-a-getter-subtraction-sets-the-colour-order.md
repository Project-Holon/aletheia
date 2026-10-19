# A field read into its own local before a getter subtraction sets the colour order

summary: Reading the field into its own block local before `lo - getter()` swaps the two callee-
saved colours. The one-expression form calls the getter first and is worse.

## Shape

Everything matches except two long-lived values in each other's callee-saved registers. One of them
is a difference `field - getter()` that is wrapped by a later `if (r < 0) r += n;`:

```
lsls r0, r0, #0x1d
lsrs r5, r0, #0x1d      ; lo = e->lo (bitfield)
ldr  r0, [sp, #0x10]
bl   func_02012B58      ; getter
subs r5, r5, r0         ; r = lo - getter
bpl  ...
```

The image has the parameter in r4 and r in r5; `r = e->lo; r -= getter(ctx);` gives r4/r5 swapped.

## Source

Read the field into its own block local, then subtract:

```c
if (e != 0) {
    int lo = e->lo;
    r = lo - func_02012B58(ctx);
    if (r < 0)
        r += *(u8 *)((char *)e + 0x902);
}
```

The extra local coalesces with r (same register, no extra code) but changes the colouring order.
The one-expression form `r = e->lo - getter(ctx)` calls the getter first and is worse.
The matched sibling ov020 02185140 has the same shape (`r2 = r5 - func_02012B58(r4)`).

## Also in this function

A u16 parameter that is passed to a u16 callee parameter (the matched definition of func_02014184
takes `u16 id`) moves its stack reload below the argument sign extension, as in
a-spilled-parameter-reload-scheduled-after-an-unrelated-store-is-a-narrow-parameter.md.

## Seen in

ov020 func_02185588 (wave D9r lane42, EXACT after nine lanes left it at 18 bytes).
