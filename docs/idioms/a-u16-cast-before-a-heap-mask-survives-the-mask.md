# A u16 cast before a heap mask survives the mask

summary: `(u16)(((u16)heap & 0x7FFF) | 0x8000)` preserves a shift pair before the mask and another after the OR; omitting the inner cast removes the first pair even though the mask clears all upper bits.

Found in: `src/matched/ov/ov136_func_021C3D44.c`, `src/matched/ov/ov136_func_021C3DA4.c`, and `src/matched/ov/ov136_func_021C3CC0.c`.

The heap parameter remains unsigned int because later allocation calls truncate it again. The allocation flag expression narrows the parameter before masking, then narrows the flagged result:

```c
func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), size, 0, file, line);
```

For 021C3D44 and 021C3DA4, the expression without the inner cast produced 92 and 88 bytes respectively, four bytes short, with shifted scheduling and pool offsets. Adding only the inner cast produced EXACT at 96 and 92 bytes. 021C3CC0 used the same expression and was EXACT on its first run.
