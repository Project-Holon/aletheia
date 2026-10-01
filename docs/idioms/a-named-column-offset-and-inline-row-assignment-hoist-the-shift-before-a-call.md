# A named column offset and inline row assignment hoist the shift before a call

summary: when a Thumb row lookup shifts the column before calling the row-index helper, name the byte column offset before the call and assign the row pointer inside the indexed load; separate row-index and row-pointer statements let the shift sink below the call.

Found in: src/matched/ov/ov198_func_0220DC04.c (0x0220DC04), src/matched/ov/ov198_func_0220E088.c (0x0220E088), dsi/1.1p1 -O4,p Thumb.

The matched spelling retains the row pointer for a later call and the column offset for both the empty-slot store and that call:

```c
offset = i * 8;
value = ((u16 *)(rec = base + row_index(p, selected) * 76))[i * 4];
if (value == 0)
    *(u8 *)(p + offset + 0x1f7c) = 1;
else {
    draw(p, value, i + 1, table[i], 65535, 7, 0x3dc0);
    details(p, rec + offset, i + 1);
}
```

This emits `lsls r7,r4,#3` before the row-index call and spills `rec` after its first halfword load. Separate `index = row_index(...)`, `rec = base + index * 76`, and `value = *(u16 *)(rec + offset)` statements put the shift after the call, giving twelve differing bytes. Merely naming `offset` does not fix it; omitting the named offset while keeping the inline assignment also leaves those twelve bytes.

The word table must independently be `extern const int table[]`: a mutable declaration leaves six additional scheduling differences around the third stack argument (`lsls r6,r4,#2` trades places with `lsls r0,r0,#6; str r0,[sp,#8]`). With the named offset, inline row assignment, and const table, both functions are EXACT. A const context parameter regressed the earlier argument loads; int versus long column counters did not close the separate-statement form.
