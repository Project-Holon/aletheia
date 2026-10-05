# A store then reload of a spilled local is a later compound assignment

## Shape

A call result is spilled and reloaded at once, before its first use:

```
bl    func_021D78AC
lsls  r0, r0, #0x10
lsrs  r0, r0, #0x10
str   r0, [sp]        ; spill r
ldr   r0, [sp]        ; reload at the first use
subs  r1, r4, r6
cmp   r0, r1
```

The plain source forwards r0 into the compare and drops the `ldr`.

## Source

The local is redefined later with a compound assignment, and the next test reads the new value:

```c
r = func_021D78AC(256);
if (r < x - y && func_021BD080(p, a) == 0) return 2;
r -= x - y;
if (r < x - y) return 3;
```

The one-expression form `if ((u16)(r - (u16)(x - y)) < x - y)` keeps one live range and forwards r0.
The redefinition splits the live range of r, so the first range is a pure spill with a reload at its use.

## Seen in

ov093 func_021BCFAC (wave D9r). Earlier lanes only reached this with a no-op cast `(int)(u32)r`, which is a stand-in.
