# Lane T2 -- ov009 open SDK rows 8..15 (2026-09-30)

Slice: `python scratch/a2/open_rows.py ov009 8 8`. Eight rows, 1,392 image bytes.

| # | address | bytes | name | verdict |
|---|---|---|---|---|
| 8 | 0x02195EC4 | 152 | gti2ConnectionError | **EXACT, filed** |
| 9 | 0x021700C8 | 160 | DWCi_EncodeBinaryMsgCommand | parked, 20 B residue |
| 10 | 0x0215E6B8 | 172 | SOCL_Shutdown | parked, 156 -> **164 B**, 80 B residue |
| 11 | 0x0217D280 | 172 | HexEncode16 | parked, 9 B residue (regalloc tie) |
| 12 | 0x02158524 | 180 | send_ping | parked, 46 B residue |
| 13 | 0x0215D070 | 180 | SOCL_CreateSocket | parked, +4 B |
| 14 | 0x0216980C | 180 | DWCi_GetFriendBuddyStatus | parked, +4 B |
| 15 | 0x021A174C | 184 | SBSendNatNegotiateCookieToServer | parked, -4 B |

## The one that closed: gti2ConnectionError (0x02195EC4, 152 B, EXACT)

Filed at `src/matched/ov_sdk/ov009_func_02195EC4.c`, shard
`layout/matched/ov009/pkt_ov009_02195EC4.json` (manifest --verify: 1 entry, EXACT).

The residue was entirely IF-CONVERSION. Every `return 1` in the function funnels
into ONE `mov r0, #1; pop` tail at 0x02195F54 in the image, reached by `bne` at
+0x48, `b` at +0x68 and `beq` at +0x70. 1.1p1 if-converted two of those sites
(`movne r4, #1` at +0x48, `moveq r0, #1` / `popeq` at +0x70), which cost the
`beq`'s four bytes and made the function 156 B against 152.

Two body-shape levers, no pin, no flag:

1. **Invert the outer guard.** `if (state == 7) return 1; gti2ConnectionClosed(); ...`
   becomes `if (state != 7) { gti2ConnectionClosed(); ... }`, so the `state == 7`
   exit and the low-state exit share the function's single trailing `return 1`
   instead of each materialising its own constant. This alone takes the file
   from 156 B / 44 concrete bytes to 152 B / 4.
2. **Make the last return reachable only through a label.**
   `if (gti2ConnectedCallback(...) == 0) return 0; goto ret1;` with `ret1:` on the
   function's last statement. This is the two bytes that remain: with the branch
   spelled any other way (`if (cb(...)) return 1; return 0;`, `if (cb(...) != 0) return 1;`,
   `int r = cb(...); if (r != 0) return 1;`) the compiler keeps `movne r4, #1`
   at +0x48 and the file sits at 152 B with 4 concrete bytes out.

## Residues, one line each

**9. 0x021700C8 DWCi_EncodeBinaryMsgCommand (160 B, size-exact, 20 concrete bytes).**
Image `ldr ip, [pc, #0x64]` / `lsl r0, r6, #2` / `ldrb r3, [ip]` | ours
`ldr r0, [pc, #0x64]` / `lsl r1, r6, #2` / `ldrb ip, [r0]`. The whole tail is the
same instruction sequence with a three-way register rotation: image holds the
`d_021A2188` base in **ip**, `len * 4` in **r0** and `0x5a` in **r1**; ours holds
the base in r0, `len * 4` in r1 and `0x5a` in r2. Nothing else differs; every
instruction is at the same offset. Measured and rejected: all six store orders of
the {id, 0x5a, command, len} header (`ctrl->len = len * 4` moved before the id
copy 46 out, after the id copy 25, 0x5a first 42, command before 0x5a 25), a
`len * 4` bound to a local used by both the copy and the field (152 B, 116 out),
and the parked file's eight other orderings. 88 pin x flag configs: `-O4,s`-class
all 160 B / 20 out or worse.

**10. 0x0215E6B8 SOCL_Shutdown (image 172 B; ours 164 B, 80 concrete bytes).**
Residue of row 10 is two islands and one if-conversion, all downstream of ONE
transposition: image `mov r4, r0` (s -> r4) / `ldr r5, [r4, #0xa4]` (send_pipe ->
r5) | ours `mov r5, r0` / `ldr r4, [r5, #0xa4]`; then `ldrsh r0, [r4, #0xac]` |
`ldrsh r0, [r5, #0xac]`, `ldr r0, [r5, #0x10c]` | `ldr r0, [r4, #0x10c]`, and the
image's `beq 0x0215E758` to the shared `mov r0, #0; pop` | ours `moveq r0, #0` /
`popeq`. Body work this lane did land (156 -> 164 B, 122 -> 80 concrete) is in the
parked file's header, with the four rejected spellings. **The vendor `.comment` is
4.0.0.1024, i.e. dsi/1.1p1: the front end is right, so this is a body residue and
not a pin question.**

**11. 0x0217D280 HexEncode16 (172 B, size-exact, 9 concrete bytes).**
`add r6, sb, #0x29` | `add r7, sb, #0x29` -- a pure register-colouring tie between
`aTextOutStream` (image r6) and `aChar` (image r7); every other byte of all 172
matches, including the branchless ctype ternary. The object's DWARF lists
`aChar, aWriteBit, aTextOutStream`, whose reverse is the declaration order
already in the file, and that order is the best of the six (TWC 9, CTW/TCW 11,
WTC/WCT/CWT 14). Rejected this lane: `register` on the pointer, `aChar = 0`,
`unsigned int aChar` with an `(unsigned char *)` load, a fourth padding local,
`aWriteBit = theInLen % 2`, `&theOutStream[41]`, a `goto` fork on the ctype test
(12 out), and a `char *aTextOutStream;` assigned inside the loop (23 out). 88
pin x flag configs: every version at `-O4,p` is 172 B / 9 out, all others worse.

**12. 0x02158524 send_ping (180 B, size-exact, 46 concrete bytes).**
Image `ldr r2, [pc, #0x90]` / `strh r4, [r5, #0x22]` | ours `strh r4, [r5, #0x22]` /
`ldr r2, [pc, #0x8c]`. The two pool bases (netvars `g_021A826C`, then
`g_02150FEC`) are hoisted above the first `strh` in the image and below it in ours,
which then carries through the `soc`/`icmp` pair (image soc r6 / icmp r5, ours the
reverse). Body work this lane: 30+ statement orders and chained-assignment forms
were already measured by w2_s1 and the file records them; 88 further pin x flag
configs give 180 B / 46 out at `-O4,p` and never better.

**13. 0x0215D070 SOCL_CreateSocket (image 180 B; ours 184 B, 4 bytes long).**
The `flag` boolean at +0x58: image emits the single `movne r1, r5` (r5 already
holds 1 from the command-flag argument) | ours `moveq r5, r1` / `mov r1, r5`
because `flag = (socket->field_ac & 1) != 0` materialises its own constant.
Everything else in the 184 bytes is the image, shifted by four from +0x58 on.
Rejected upstream: `flag = 1` in nested and `&&` forms (both shrink to 164) and
the ternary (no change). 88 pin x flag configs: `-O4,p` 184 / 78, `-O4,s`-class
worse; `../1.2/sp3` is 180 B but 72 out (the four bytes come off a different
instruction, so that is not this row's shape).

**14. 0x0216980C DWCi_GetFriendBuddyStatus (image 180 B; ours 184 B, 4 bytes long).**
Image `ldr r4, [pc, #0xa4]` / `mov r5, #0` | ours `mov r5, #0` / `ldr r4, [pc, #0xa4]`
-- the pool load of `g_021AA860` and the zero are scheduled in the opposite order in
the head, and the same flip reappears at the tail (`mov r5, #0` / `cmp r0, #0` /
`moveq r5, #1` | `mov r4, #0` / `cmp r0, #0` / `moveq r4, #1` / `b`), plus the
`ble` at +0x4C landing one word apart (`0x2169878` | `0x216987C`). 24 words differ.
88 pin x flag configs: `-O4,p` is 184 / 86 and nothing reaches 180.

**15. 0x021A174C SBSendNatNegotiateCookieToServer (image 184 B; ours 180 B, 4 bytes short).**
Image `ldr r5, [sp, #0x44]` / `mov r7, #0xfd` / `lsr r4, r5, #0x18` | ours
`ldr r4, [sp, #0x44]` / `mov sl, #0xfd` / `lsr r5, r4, #0x18`. The cookie is in r5
in the image with the swap temps in r4/r8/r3/r6 and the six `0xfd 0xfc 0x1e 0x66
0x6a 0xb2` bytes written one-at-a-time through a pointer in ip; ours holds the
cookie in r4 and spends `strb r5, [sp, #0xa]`-style stack stores, four bytes short
at the tail. Rejected upstream: interleaved stores, pointer-increment stores, and
a 10-byte array initialiser (which becomes an `ldr`/`str` copy loop). 88 pin x flag
configs: `-O4,p` 180 / 112, everything else worse.

## Wall clock

~80 min of the 85-minute budget: 1 row filed EXACT (152 B), 1 row moved 8 bytes
closer with a sharper named residue (SOCL_Shutdown), 6 parked with the residue
above. Roughly 250 compiles: 8 x 88 pin/flag configurations, a 48-compile
cross-front-end matrix (1.1p1, 1.1, ../2.0/sp2, ../2.0/sp1p2, ../2.0/sp2p2,
../1.2/sp2, ../1.2/sp3), and ~60 body spellings.
