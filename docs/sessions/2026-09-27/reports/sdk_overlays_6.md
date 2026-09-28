# sdk_overlays_6 lane report (2026-09-28)

Worked only from vendor objects (sdkobj.py, DWARF) and `match.py show`; nothing under sdk/ opened.
All dsi/1.1p1 -O4,p c99 (objects stamped 4.0.0.1025). Permuter seeds 9801 to 9804.

**keyboard.o** (shard pkt_ov016_021BD8D8, 22 EXACT of 25): every function except the three below.
Levers: `(unsigned long *)&x` casts into an inlined G2_GetOBJPosition keep the 8-byte frame (taskStart0..4,
taskEnd0..4); `unsigned char` for DWARF `char` (the object was built char unsigned); call-then-goto into a
shared tail (touch); canv is `[3][4]` and MOVE_TBL `[53][4]` (the dump prints DWARF dimensions reversed).
Near misses in src/pending, notes in docs/notes/pkt_ov016_021BD8D8.c.txt: disp 0x021BE844 (prologue copy
scheduling), taskEnd5 0x021BF2B0 (per-loop &MemKb reload), DWCi_KBlInit 0x021BD8D8 (zero coalescing).

**scenesetaplist.o** (23 of 23 EXACT): shard pkt_ov016_021C50D4 (22, including draw 0x021C57E4, the wave-10
MATCH, now EXACT because DWCi_SBlGet resolves through the sdk class) and pkt_ov016_021C86F8 (procInit: the
symbols_sdk row says scenesetaplist.o, but it is scenesetlist.o's own copy chaining to 0x021C8760).
Levers: CELL_LV as its own vendor symbol in a loop, G2_SetOBJPosition as mask | y | x, declaration orders.

**scenesetlist.o**: setOffset 0x021C98E4 closed EXACT (shard pkt_ov016_021C98E4) with the cast lever.

All four shards verified twice (0 rewritten on the second pass); manifest --check clean.

**New idioms (5):** an-int-local-passed-through-a-u32-pointer-cast-keeps-its-stack-slot,
a-call-before-a-goto-into-the-shared-tail-is-cross-jumped-to-its-bl,
ldrb-on-a-dwarf-char-means-the-object-was-built-char-unsigned,
an-indexed-array-inside-a-section-struct-needs-its-own-symbol-in-a-loop, g2-set-obj-position-is-mask-then-y-then-x.

**Remainder:** ScanAP 0x021B9BF8 and CheckAccessPoint 0x021B9A2C (not started), initGraphics 0x021C84BC and
isPush 0x021C9A94 (not revisited), the three keyboard.o near misses.

**Integrator:**
- Stage 46 src/matched/ov016_func_*.c, 3 src/pending files, 4 shards, the notes, 5 idiom files; git mv of
  draw (021C57E4) and setOffset (021C98E4) from src/pending is already staged.
- Regenerate the idiom index.
- Shape: dispObj (ov016_func_021C9610.c) is EXACT with the mask-first G2_SetOBJPosition too; normalise it.
- No new seeds (every address is an SDK row).
