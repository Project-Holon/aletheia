# Lane T1: ov009 open SDK rows 0-7 (smallest first)

Slice: `python scratch/a2/open_rows.py ov009 0 8`.  2 of 8 closed, 6 parked.

## Closed

| address | bytes | name | lever |
| --- | --- | --- | --- |
| 0x0215E2C0 | 36 | SOCLi_GetWriteBufferFreeSize | the pipe cursors are **`vu16`**, not `u16` |
| 0x0215E588 | 152 | SOCLi_GetOptimumSendBufLen | hoist `g_021AA450.bufSize` into a local before the min compares |

Both now EXACT under dsi/1.1p1 -O4,p; shards `ov009/pkt_ov009_0215E2C0.json`,
`ov009/pkt_ov009_0215E588.json` written through `manifest --verify`.

### The two rules that paid

1. `sdk/TwlDWC/include/nitroWiFi/socl.h` is the vendor header and it is
   authoritative about qualifiers.  `SOCLiSocketRingBuffer` declares
   `vu16 in; vu16 out;`.  With plain `u16` the front end folds both loads into
   the subtraction and emits them minuend-first (`ldrh r1,[r0,#2]`); with
   volatile they keep source order (in at +0x100 into r1, out at +0x102 into
   r0) and the size word at +0xf8 (`CPSSocBuf.size`, *not* volatile) floats
   below them.  Two bytes of the 36 were the whole row.  Grep the vendor
   headers for a row that is size-exact with only register operands swapped.
2. `tools/sdkobj.py <addr> --region ov009 --brief` prints the defining object's
   DWARF *and* its `.comment` stamp.  Read both before drafting: the stamp says
   whether the front end is even available (below), and the DWARF local list
   (declare it in the reverse of the printed order) fixes the accumulator
   register.  For 0x0215E588 the printed order `count, enabled, temp, soc` plus
   a `bufSize`-shaped local is what reproduces r3 = winSize, r2 = mss, r1 =
   bufSize; using `temp` as the running minimum instead forces it into r6 and
   costs the frame.

## Parked, with residue

Every one of these is `dsi/1.1p1 -O4,p` unless stated.

| address | bytes | name | first differing instruction (image | ours) | residue |
| --- | --- | --- | --- | --- |
| 0x0217D8E0 | 36 | gsLargeIntDiv | +0004 `mov lr, r1` \| `str r3, [sp]` | 32/36: the image keeps the two incoming args across the `ldr r1,[r0],#4` in **lr/ip** (`mov lr,r1; mov ip,r2; str r3,[sp]`); 1.1p1 stores the 5th arg first and saves into ip/r3.  gslargeint.o is stamped 4.0.0.1025 -- no tools/mwccarm build writes it (all 9 dsi front ends x 6 opt levels give the same 32 bytes), so the shuffler that chose lr is not in this tree.  Capped on the front end, not on the body |
| 0x021990A0 | 52 | GetClientUniqueID | +0020 `mvn r1, #0x80000000` \| `sub r1, r0, #0x80000002` | natneg.o is also stamped 4.0.0.1025.  The value is right (0x7fffffff); ours builds it off the live r0 = 1 (sub) instead of `mvn`.  Same capped front end |
| 0x02167E20 | 104 | WcmWmcbSetDCFDataAsync | +003C `cmp r0, #0` \| `ldr r6, [r4, #0x2c]` | 100/104: the one-instruction then-arm `wcmResult = -5` is if-converted to `subne r5,r5,#5`; the image keeps a real `mov r5,#0 / cmp / beq / mvn r5,#4`.  Stamp 4.0.0.1024 = dsi/1.1p1, so the front end is right and the arm shape is not.  DWARF locals are `cb, wcmiw, wcmResult, sendCallback` (reverse of the printed order); adding the `cb` alias does not stop the if-conversion |
| 0x02163E40 | 120 | CPSi_rc4_init | +0010 `add r4, r0, #2` \| `add lr, r0, #2` | 120/120, 21 bytes: the whole function is one mirrored pair.  The image keeps the table pointer `m` in **r4** (from the first, pre-key loop) and the byte `m_i` in lr, with the k-zero temp in r0 and the chain in r3; ours is the exact swap.  DWARF order `i, m, j, k, m_i` (reverse-printed) does not move it, and splitting the declarations moves it the wrong way (`add r6, r0, #2`, then 27 bytes out).  Stamp 4.0.0.1024, front end correct |
| 0x02166600 | 128 | WCMi_MergeToBuffer | +000C `cmp r0, #1` \| `mov r6, r1` | best 124/128.  The byte-swap spelling is settled: `(unsigned short)(((len & 0xff) << 8) \| ((len & 0xff00) >> 8))` with the u16 `len` local gets the image's `lsl 24 / lsr 16 / and 0xff00 / orr ..., lsr #8` shape (a `(len << 8) \| (len >> 8)` spelling is 116 B).  What is left is the shared `case 1: default: copyDest = sendBuf;` arm: every spelling hoists `mov r6,r1` above the two compares and drops the trailing `b`, where the image keeps a real `mov r6,r1; b` block after them -- one instruction, 4 bytes |
| 0x0215F0F0 | 148 | SOCLi_IsIPv4ValidDNSAddr | +0000 `push {r4, lr}` \| `push {r3, r4, r5, lr}` | 152/148.  DWARF has **no locals at all** (three `unsigned long` params), so the parked `ret / notloop / valid` locals are a mis-draft: the image's ip (ret), r4 (valid) and lr (notloop) are compiler temporaries and the callee-saved r4 exists only because the three flag chains are if-converted (`movne r4,#1`, `movne lr,#1`, `movne ip,#1`).  Ours needs a fifth register for the `ands` temp in the isA part of the conjunction and if-converts a `moveq r3, ip`; the isA/isB helpers want to stay two separate tests (image: `tst r0,r3` with the branch to the isB block) rather than one combined boolean |

## Budget

Wall clock ~80 min of the 85 allowed.  Pin sweeps were run on 0x0215E2C0 and
0x0217D8E0 before the hold order came through (9 dsi front ends x 6 opt levels
each, 54 configs apiece, zero movement); everything after that was
body-shape work driven by DWARF and the vendor headers.
