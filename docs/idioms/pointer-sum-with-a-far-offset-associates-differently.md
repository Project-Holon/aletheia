# A far constant added after a base-plus-index sum names a pointer local

summary: `base[idx + 0x157]` makes the compiler bind the far offset to the
index register and sum `base + (idx + 0x157)`; the original that sums
`(base + idx) + 0x157` instead had the base-plus-index sum in a named pointer
local before the far offset was added.

Found in: `src/matched/ov093_func_021D69A0.c` (0x021D69A0)

An out-of-reach byte offset on an already-summed pointer costs a literal-pool
constant either way, but the register it lands in, and the order of the two
adds, tells you whether the sum was a named local.  Original:

```
021D69A0  adds r1, r0, r1       ; r1 = base + idx
021D69A2  ldr  r0, [pc, #4]     ; r0 = 0x157
021D69A4  strb r2, [r1, r0]     ; (base+idx)[0x157] = val
```

The literal C `base[idx + 0x157]` reassociates the integer sum, so the index
and the constant fuse and the base is the one that survives as the store
base register:

```
compiled  ldr  r3, [pc, #4]     ; r3 = 0x157
          adds r1, r1, r3       ; r1 = idx + 0x157
          strb r2, [r0, r1]     ; base[idx + 0x157]
```

The two are five concrete bytes apart.  Binding the base-plus-index sum to a
local first pins the order and reproduces the original:

```c
void func_021D69A0(unsigned char *base, int idx, unsigned char val)
{
    unsigned char *p = base + idx;

    p[0x157] = val;
}
```

The same local fixes the loading twin `func_021D69AC` (same shape with
`ldrb`), so it is worth trying before reaching for a different operand type:
the difference is association, not signedness or reach.
