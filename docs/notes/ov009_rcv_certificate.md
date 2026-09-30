# ov009 0x02160A7C rcv_certificate — residue note

Row: `ov009 0x02160A7C rcv_certificate 544 B TwlWiFi_base/libssl.TWL.HYB.a (ssl.o)`.
Last row of the 15 "never attempted" overlay-SDK rows, the only one with no
prior body anywhere in the tree. Parked at
`src/pending/ov_sdk/ov009_func_02160A7C.c`.

## It is not a boundary problem

`python tools/sdkobj.py 0x02160A7C --region ov009` finds the vendor object in
`sdk/TwlWiFi_base/TwlWiFi/lib/ARM9-TS/Rom/libssl.TWL.HYB.a (ssl.o)` and reports
**0 concrete mismatches of 526 concrete bytes**: the object's code is byte
identical to the image, every `=` in the 544-byte listing. So the boundaries
are settled by the object, not by the listing (the ov009 listing emits
`0x02160A7C` as `.word`):

* 0x02160A7C..0x02160C9C, 544 bytes, ARM
* next label 0x02160C9C = `rcv_server_hello`, which ends at 0x02160D68 =
  `has_method` — the extent is confirmed from both sides.

The first instruction is `push {r0, r1, r2, r3}` (0xE92D000F), which the
ov009 listing is right to treat as data because the walk from a seed never
reachable it. It is real: MWCC's argument home for the addressable parameter
`s` (its home is `[sp, #0x44]`, which is exactly the saved `r1` after
`push {r0-r3}` + `push {r3-r10, lr}` + `sub sp, #0x18`).

## Field map (from the matched siblings)

`auth_cert` (0x0216090C, EXACT) and `rcv_server_hello` (0x02160C9C, EXACT)
give the connection layout that `rcv_certificate` also uses:

| offset | field | evidence |
|---|---|---|
| 0x348 | sha1 / md5 contexts | auth_cert |
| 0x455 | `state` | `strb r0, [sl, #0x455]` (9 on error, 3 on success) |
| 0x458 | `hash_type` | `str r5, [sl, #0x458]` with r5 = -1 |
| 0x45C | `f45c` | `str r5, [sl, #0x45c]`, -1 |
| 0x460/0x464 | `cert_start` / `cert_end` | auth_cert |
| 0x47C | `hash_len` | auth_cert |
| 0x480 | SOCLCaInfo slot | `add r1, sl, #0x480` before `validate_signature` |
| 0x594 | `f594` | compared against 0x33 |
| 0x5A0 | `f5A0` | gates the `auth_cert` block |
| 0x5AC/0x5AD/0x5AF | flags | zeroed each iteration |
| 0x5B0 | `dn[]` | auth_cert: `con->dn` |
| 0x6B0, 0x7B0 | flags / `fqdn` | zeroed each iteration |
| 0x800 | `char *` | `compare_fqdn(con->f800, con + 0x7B0)` |
| 0x804/0x808 | pointer / length of this certificate | |
| 0x80C | packed date | `((year+0x7d0)<<16) + (month<<8) + day` |
| 0x810 | callback | `blx r3` with `(result, con, level)` |

`RTC_GetDate` (0x02088864) fills a 16-byte `RTCDate {int year, month, day,
week;}` whose first three words are packed into 0x80C — the same `Y*10000 +
M*100 + D` shape `date2sec` (0x0216003C, EXACT) uses for its RTC pair.

## DWARF registers, for whoever picks this up

```
con                 r10 (sl)      s                  [fb+68] -> sp+0x44
level               r9  (sb)      parse_mode         r6  (shared with result0)
s2                  [fb+4]        this_certlen       r0 (dead by +0064)
remaining_certlen   r8            result             r7
result0             r6            date               [fb+8] (sp+8)
```

## Residue

First divergence **+0004**: image `push {r3, r4, r5, r6, r7, r8, sb, sl, fp,
lr}` | ours `push {r4, r5, r6, r7, r8, sb, sl, fp, lr}`, then +000C image
`ldr r4, [sp, #0x44]` | ours `ldr r1, [sp, #0x44]`.

The image keeps `s` in **r4** and `con` in **sl** from the first instruction
on, and its callee-saved push is 10 registers with `sub sp, #0x18`; ours is 9
registers with `sub sp, #0x1c` (same 80-byte frame, different split) and keeps
`s` in r1. The +48-byte size excess comes from the loop tail: the image
coalesces `parse_mode` and `result0` into r6 and tests `r6` once at
0x02160BDC/0x02160C58, while the C in the parked file keeps them separate.

The lever is a body-shape change, not a pin: declare `s` in a form MWCC homes
to a register it keeps live across the whole loop (the addressable-parameter
home at sp+0x44 is what forces the `push {r0-r3}`), and let `parse_mode` and
`result0` coalesce into one variable so the two tests collapse to the single
`and r6, r7, #0xff` / `cmp r6, #1` the image has.

Verified with:

```
python tools/match.py one --src src/pending/ov_sdk/ov009_func_02160A7C.c \
    --func func_02160A7C --addr 0x02160A7C --region ov009 --arm \
    --cc 1.1p1 --lang c99
```
