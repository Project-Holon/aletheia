# A signed byte sentinel reuses a live small constant with subtract

summary: a store of -1 to an s8 field lets mwcc derive the full signed value by subtracting from a nearby live small constant; spelling the destination u8 instead emits movs #255 and can change the constant's scratch register.

Found in: `src/matched/ov/ov093_func_021E11DC.c` and `src/matched/ov/ov093_func_021E072C.c`.

In func_021E11DC, a record stores 1 at byte +15, loads a separate stack byte into r0 and stores it at word +4, then sets byte +12 to the none sentinel. The original retains the 1 in r2 and uses `subs r0,r2,#2` for the sentinel. `r[12] = -1` with r an unsigned-byte pointer emits `movs r0,#255`, moves the earlier 1 into r0, and leaves four concrete bytes wrong. Changing only the store to `*(s8 *)(r + 12) = -1` gives EXACT* for the lead; its lead/follower unit is EXACT.

In func_021E072C, word +4 is assigned 7 immediately before the byte +12 sentinel. The signed store compiles to `subs r0,#8`, matching the original. A scratch variant changing only that lvalue to u8 compiles to `movs r0,#255`, with two concrete bytes different at +0x3A. The signed lead/follower unit is EXACT.

```c
*(int *)(r + 4) = 7;
*(s8 *)(r + 12) = -1;
```

Both spellings store the same low byte, but their intermediate constant nodes differ: the signed destination asks for -1, while the unsigned destination asks for 255. Keep the field signed when the original derives a negative sentinel from a live positive constant; a cast of the right-hand side alone is converted back to 255 by an unsigned lvalue.
