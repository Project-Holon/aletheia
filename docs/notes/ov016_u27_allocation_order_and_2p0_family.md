# Two method findings from lane U27 (ov016 SDK slice, 14 rows)

Lane U27 held 14 ov016 rows (the "larger ones", 464..996 bytes): 021B87F0, 021B9BF8, 021BA804
(thumb, .comment 3.0.0.126) and eleven arm rows stamped 4.0.0.1025. None closed. Two results are
about method rather than about a single row, so they go here instead of into a row header.

## 1. Rule 4b does not generalise to the ov016 4.0.0.1025 members: the 2.0 family is worse

Rule 4b's measured claim (a 1025-stamped row is closed by a `../2.0/*` pin) was re-measured on every
4.0.0.1025 row of this slice: all ten 2.0 packs (base, sp1, sp1p2, sp1p5, sp1p6, sp1p7, sp2, sp2p2,
sp2p3, sp2p4) crossed with the eleven rows, `-O4,p`, own region/ISA/lang, against the parked
`dsi/1.1p1`. Full log: `scratch/a2/laneU27/sweep2.txt`.

| row | dsi/1.1p1 | best `../2.0/*` | verdict |
|---|---|---|---|
| 021C84BC initGraphics | 508 / **38** | 532 / 410 (all packs) | 1.1p1 wins |
| 021C2610 drawInfo | 504 / **141** | 500 / 408 | 1.1p1 wins |
| 021D2450 ParentStateCallback | 792 / **99** | 796 / 652 | 1.1p1 wins |
| 021C1210 taskFramework | 596 / **416** | 636 / 526 | 1.1p1 wins |
| 021C9A94 isPush | 620 / **409** | 612 / 531 | 1.1p1 wins |
| 021C00A8 disp | 624 / **457** | 620 / 513 | equal at base, worse at sp* |
| 021BE844 disp | 652 / **465** | 652 / 523 | equal at base, worse at sp* |
| 021C73D0 input | 748 / **601** | 808 / 699 | 1.1p1 wins |
| 021D1208 DWCi_WINlInitEx | 784 / **567** | 800 / 564 | 1.1p1 wins the size, 2.0 the count |
| 021C7D80 drawMessage | 828 / **479** | 836 / 606 | 1.1p1 wins |
| 021BD8D8 DWCi_KBlInit | 876 / **519** | 896 / 707 | 1.1p1 wins |

No row reaches EXACT and no row's size lands on the image under any 2.0 pack; the parked 1.1p1 pin
is already the minimiser on 10 of the 11. The one row where a 2.0 pin puts the *size* exactly on the
image (021D2450, `../2.0/base` 796 = image 796) pays for it with 652 concrete bytes against 99.
Rule 4b's two cited rows are TwlDWC *members*, not `.o` files of this shape; the claim should not be
carried to an arbitrary 1025-stamped row without this table's kind of measurement.

## 2. A second unclosable class: the free-register order of two simultaneously-live temporaries

Two of the fourteen rows are size-exact and differ only in which physical register two values that
are live at the same time get. In both, the vendor object gives the **lower** register to the
value created **later**, and every front end we own gives it to the value created **earlier**:

* `ov016` 0x021B87F0 (`AOSSi_WLANConnect`, 464 bytes, 6 concrete): the empty `ssidLength` loop.
  Image `ldr r1,[pc]` / `movs r0,#0` / `ldrh r1,[r1,#0xa]` - the address temporary (created first)
  in r1 and the counter `i` (created second) in r0; ours is the same three instructions with r0/r1
  swapped, 5 concrete bytes, plus a 2-byte switch-table entry (case 19 → image `0x2C`, i.e. the
  local `b` at +F2; ours `0xB6`, i.e. the `b`'s final target at +17C, so the table entry is
  jump-threaded in ours and not in the image).
* `ov016` 0x021C84BC (`initGraphics`, 508 bytes, 38 concrete): after the last `DWCi_ARClReadEx` the
  image loads `MemSsl` into r2 and the `0x04001008` pool word into r1 (and only sinks
  `sub r2, r1, #0x1000` to just before its use); ours loads `MemSsl` into r1, the pool word into r2
  and hoists the sub. Same 13 sites, same instructions, register numbers exchanged.

Fifteen loop spellings (plain/while/increment-opaque/reversed operands/pointer local/pre-init,
signed and unsigned counter) and three store spellings (`void *` result, `MEMSSEL *` local) left both
byte sequences unchanged; the class is an allocator preference, not a body shape. Rows whose only
residue is such an exchange should be parked together with the 4.0.0.1025 callee-saved-shift rows
rather than re-spelled.

## 3. Thumb check, for the record

The three thumb members of the slice were compiled with `--thumb` throughout (021B9BF8 at
`../2.0/sp1p2` gives 652 of 660 bytes, matching `docs/notes/lane_t17_ov016_rows26_33.md`), so no
row in this lane was ever measured through an ARM invocation.
