# A callback that only a data table names is filed as data, not as a veneer

summary: a short Thumb tail call (`ldr r3, =callee; movs r1, #0; bx r3`, or
`ldr r3, =callee; bx r3` with no argument setup) that only a vtable or callback
table names has no push and no caller, so the listing shows it as `.word` lines
and the data registry files it as data.  It is ordinary C, not a linker veneer:
seed it in `layout/function_starts.txt` and write the one-line function.

Found in: src/game/ov198/b_plist_main.c (0x02211A54, 0x02211A60, 0x02211A6C),
src/game/ov067/frame_list.c (0x021B941C).

The CursorVtbl `d_022122A0` of ov198 holds four Thumb entries: 0x02211A41
(B_PLIST_MAIN_ShowCursor, traced because it has a push) and 0x02211A55,
0x02211A6D, 0x02211A61.  The last three are mwcc tail calls:

```c
void B_PLIST_MAIN_HideCursor(u8 *p)          { B_PLIST_MAIN_SetActorsVisible(p, 0); }
void B_PLIST_MAIN_HideCursorOnTouch(u8 *p)   { B_PLIST_MAIN_SetActorsVisible(p, 0); }
void B_PLIST_MAIN_MoveCursor(u8 *p, u32 idx) { B_PLIST_MAIN_LayoutCursorActors(p, idx); }
```

All three are EXACT at `-O4,p` with the callees defined earlier in the same
file.  A Thumb tail call to any function goes through a pool word and `bx r3`
(see a-pooled-tail-call-target-needs-a-thumb-region-symbols-hint.md), so the
pool word naming a same-file function is normal compiler output.  A linker
veneer looks different: it has no argument setup and the linker places it
after the code of the overlay, never between the functions of one file.  The
`ldr r3, =callee; bx r3` form at 0x02211A6C sits between the two other
callbacks and the `.rodata` of the next file, so it is the compiled body of a
forwarding function whose arguments are already in r0 and r1.

How it shows up: `python tools/codeasdata.py` lists a pointer word whose odd
value lands in a registry data object that reads as Thumb code
(`thumb-in-data`), or a function of layout/function_addrs.tsv that starts
inside a data tail (`func-in-data`).  The fix is a `function_starts.txt` seed
with the table site as evidence, the listing regenerated, the function written,
and the region of layout/data_objects.json rebuilt with tools/datareg.py.
