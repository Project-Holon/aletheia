# A second spelling of an item address in the if body makes the base a late temp

Seen in ov020 0x02186470 (wave D9r, lane 166). Fifteen lanes left it at 12 to 15 bytes.

## Symptom

A loop walks records of 0x18 bytes at `base + 8`. Two long-lived values swap r4 and r5:
the items base and the per-iteration offset `i * 0x18`, and with them the parameter and a
call result that share their colours. The preheader order is right, or one instruction off.

## Cause

A user local `items = base + 8` is coloured after the compiler's offset temp, so the offset
takes r4. A compiler temp for `base + 8` (from LICM) is coloured before it. The original
used both forms: the tests read through the local, and the if body spells the address again.

## Fix

```c
items = base + 8;
for (; i < 10; i++) {
    if (f(items + i * 0x18) != 0 && g(items + i * 0x18) != 0 && h(key) == 0) {
        k(q, base + 8 + i * 0x18);
        m(base + 8 + i * 0x18);
    }
}
```

The same mix is in the matched siblings ov010 02161DC4 (`a + i * 0x18` in the test,
`p + 8 + i * 0x18` in the return) and ov020 021862A8. Look for it when a twin in the same
code family mixes a list local with the raw `p + K + i * size` form.
