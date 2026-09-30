# Lane T25 — ov009 open SDK rows 72-79 (slice `open_rows.py ov009 72 8`)

## The slice, identified

`python scratch/a2/open_rows.py ov009 72 8` is index-based over a list that is sorted **smallest
first** and that other lanes are shortening while it runs: at the start of this lane the slice
printed one row (index 72 = the largest, `0x0219091C`), minutes later index 71. The index range is
therefore not stable — the *addresses* are. They are fixed by the previous lane on this exact
slice, `docs/notes/lane_T15_ov009_open_sdk_rows.md` (same command, same range):

| addr | bytes | name | archive member | status this lane |
|---|---|---|---|---|
| 0x02163628 | 1652 | CPSi_sha1_block | libssl.TWL.HYB.a (sha1.o) | open, parked (colouring wall) |
| 0x02187D60 | 2264 | gpiProcessRecvBuddyStatusInfo | libdwcgsgp.TWL.HYB.a | **closed by T15** — filed, not an open row anymore |
| 0x0217AB78 | 3184 | DWCi_Netcheck_Thread | libdwcauth.TWL.HYB.a (dwc_netcheck.o) | open, partial body |
| 0x021870B8 | 3240 | gpiProcessRecvBuddyMessage | libdwcgsgp.TWL.HYB.a (gpibuddy.o) | open, near-complete (-28) |
| 0x0216D57C | 3908 | DWCi_MatchProcess | libdwcmatch.TWL.HYB.a (dwc_match.o) | open, partial body |
| 0x021702A0 | 4396 | DWCi_ProcessRecvMatchCommand | libdwcmatch.TWL.HYB.a (dwc_match.o) | open, partial body |
| 0x0219091C | 9460 | gpiProcessSearch | libdwcgsgp.TWL.HYB.a | **not this slice's row** — lane S10, `docs/notes/ov009_func_0219091C.md`; untouched |

## Measurements (pin `dsi/1.1p1`, `-O4,p`, `--arm --lang c99`, `--diff`)

| addr | image | ours | concrete bytes differ | first divergence (image \| ours) |
|---|---|---|---|---|
| 0x02163628 | 1652 | 1652 | 142 | +0010 `add r7, sp, #0x10` \| `add r8, sp, #0x10` |
| 0x021870B8 | 3240 | 3212 | 1908 | +001C pool distance only; first real +011C `mov fp, #1` \| `bgt` |
| 0x0217AB78 | 3184 | 1696 | 1511 | +0004 `sub sp, sp, #0x290` \| `sub sp, sp, #0x90` |
| 0x0216D57C | 3908 | 1028 | 841 | +0000 `push {r3,r4,r5,r6,r7,r8,sb,lr}` \| `push {r4,lr}` |
| 0x021702A0 | 4396 | 852 | 717 | +0000 `push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}` \| `push {r3,r4,r5,lr}` |

The three partial rows are ~20-55 % written: their frames are not the image's frames, so they are
reconstruction jobs against the vendor object, not diff-reading jobs.

## Residues, one line each

* **0x02163628 CPSi_sha1_block** — +0010 `add r7, sp, #0x10` | `add r8, sp, #0x10`. Size-exact,
  every instruction sequence has the image's shape, and the whole difference is one permutation of
  the same register file: image `a=r5 b=r6 w=r7 d=r8 e=r9 c=r10` (temps r4/r11/r12), ours
  `a=r5 b=r6 c=r7 w=r8 e=r9 d=r4` (temps r10/r11). No new spelling attempted here: T15 had already
  run all declaration orders from the DWARF order, all 120 orders of the five state loads, the
  rotate operand order and 4000 permuter compiles (best 116 B, via temporaries the vendor does not
  have) — the compiler axis is dead on this row by rule 4, and the body is already right.
* **0x021870B8 gpiProcessRecvBuddyMessage** — 3212 B, +011C `mov fp, #1` | `bgt` **and** +0708 the
  zero fill. Size 3240; the 28-byte deficit is exactly two front-end decisions, nothing else:
  1. the 28-byte `GPIBuddyStatus` fill. Image +0708: `mov r1,#7; strb sl,[r0]; strb sl,[r0,#1];
     strb sl,[r0,#2]; strb sl,[r0,#3]; add r0,r0,#4; subs r1,r1,#1; mov fp,#0; bne` = 8 instructions
     (32 B of code, 7×4 B of memory). Ours: `mov r2,#0x1c; mov r1,#0; bl memset` = 3 instructions
     (12 B) — note the T15 note's "7 four-byte iterations = 28 bytes" is the *memory* size, the code
     is 32 B against our 12 B. Eight hand spellings compiled this lane
     (`scratch/T25/{v2_dnbyte,v3_word7,v6_ptr4,v7_dn_pe,w1_dow7,w2_dow_sz,w3_whiledec,w4_szbyte_do}.c`,
     diffs in `scratch/T25/d_*.txt`): best is 3244 B (+4) with 1844 concrete bytes, the rest 3260+.
     The closest spelling (`char *bp; zi=7; do { bp[0..3]=0; bp+=4; } while (--zi != 0);`) gives
     9 instructions — 1.1p1 emits `sub` + `cmp` + `bgt` where the image fuses to `subs` + `bne`,
     and no spelling produces the image's in-loop `mov fp,#0`.
  2. the hoist: the vendor keeps the error constant 1 in fp (`mov fp,#1` at +011C) and rematerialises
     `&buffer` (`add rX, sp, #0x150`) per use; 1.1p1 does the opposite (fp = `&buffer`, `mov rX,#1`
     per arm). Both are instruction-neutral except the single `mov fp,#1`.
  Pin sweep already done by T15 (9 pins × 7 option sets, `scratch/laneT15/sweep_021870B8.txt`, all
  ≥3212) — not repeated.
* **0x0217AB78 DWCi_Netcheck_Thread** — +0004 `sub sp, sp, #0x290` | `sub sp, sp, #0x90`;
  1696 of 3184 B written, 1511 concrete bytes differ, 422 mismatching lines. The parked body is a
  call-sequence sketch with raw struct offsets (`work->f3c = (char *)work->fstate;` etc.), not a
  reconstruction.
* **0x0216D57C DWCi_MatchProcess** — +0000 `push {r3,r4,r5,r6,r7,r8,sb,lr}` | `push {r4,lr}`;
  1028 of 3908 B, 841 concrete bytes, 241 rows. The image's first three body instructions are
  `mov r5,r0; mov r4,#1; mov r7,#0` (no call at entry) where the parked body calls
  `DWCi_GetMatchCnt` first, so the head is a wrong guess, not a near miss.
* **0x021702A0 DWCi_ProcessRecvMatchCommand** — +0000
  `push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}` | `push {r3,r4,r5,lr}`; 852 of 4396 B, 717 concrete bytes,
  204 rows. Same verdict.

## Vendor-object material for the three reconstructions

`python tools/sdkobj.py <addr> --region ov009`, dumps kept at `scratch/T25/obj_<addr>.txt` (the
archive member, `.comment` stamp, prototype, every local with its allocated register, the call and
data target tables with image addresses, and the object-vs-image listing). The object stamps are
`4.0.0.1024`/`4.0.0.1025`, which no tree in `tools/mwccarm` writes.

* **0x0217AB78** `static void DWCi_Netcheck_Thread(void)`, frame 0x290:
  `DWCCalInfo calinfo [fb+56]`, `int wait_sec r11`, `int wait_len r10`, `char *wait r9`,
  `int data_len r11`, `char *data r8`, `int url_len [fb+8]`, `char *url r7`, `char retcode[4] [fb+32]`,
  `char *bodywayport r10`, `char *body302 r11`, `void (*free)(ulong,void*,long) r6`,
  `void *(*alloc)(ulong,long) r5`, `DWCAuthResult authresult [fb+204]`,
  `tagDWCWiFiInfo DWC_netcheck_wifiinfo [fb+36]`, `int httpretcodei r10`, `char *httpretcode r0`.
  26 call targets (`DWC_Http_*`, `DWC_Auth_*`, `OS_Sleep/JoinThread/IsThreadTerminated/
  GetThreadPriority`, `strncpy/strcmp/atoi/strlen`, `DWCi_Netcheck_SetError`, `DWCi_BM_GetWiFiInfo`)
  and the data targets `DWChttp 0x021ACE5C`, `DWCnetcheckhttpparam 0x021ACE8C`,
  `DWCnetcheckauthparam 0x021ACEA8`, `DWCauthhttpparam 0x021A2358`, `errno 0x02153FAC`,
  `OSi_ThreadInfo 0x02150FEC`, `_ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0 0x021A26D4` and the
  string pool 0x021A2700..0x021A2774.
* **0x0216D57C** `void DWCi_MatchProcess(int fullSpec)`, `fullSpec r5`, `DWCstNodeInfo *pNodeInfo r6`,
  `GTI2Connection *connection r0`, `int i r5`, `DWCstNodeInfo *info r0`, `unsigned long noResponseHosts r6`,
  `DWCstMatchControl *mc r5`, `unsigned char idx r0`, `DWCstNodeInfo *node r6`, `enum sbError r0`,
  `int result r0`, `unsigned long sbInterval r5` (each is a distinct live range of the same DWARF name).
* **0x021702A0** `static int DWCi_ProcessRecvMatchCommand(unsigned char command, int srcPid,
  unsigned long srcIP, unsigned short srcPort, unsigned long *data, int len)` with
  `command r9 srcPid r8 srcIP r10 srcPort r11 data r7 len r6`, and
  `unsigned long senddata[1] [fb+16]`, `DWCstNodeInfo peerNodeInfo [fb+28]` and `[fb+68]`,
  `SOCSockAddrIn remoteaddr [fb+20]`, plus `AID r0 suspend r8 fromSV r5 idx r0 bAck r0
  beforeCloseState r8 pNodeInfo r0 tmpNode r6 nodeInfo r0 error r0 sbError r0 data_idx r5
  pMyNodeInfo r0 meshReserve r0 peerConnectGroupID r1`.
* **0x02163628** for completeness: `static void CPSi_sha1_block(CPSSha1Ctx *ctx, unsigned char *m)`,
  `ctx [fb+0] m r0 j r1 i r0 e r9 d r8 c r10 b r6 a r5 w[16] [fb+16]` — i.e. the vendor's colours are
  the ones quoted above.

## Scratch

`scratch/T25/`: `seqdiff.py` (normalises pool distances and branch targets before aligning a
`--diff` listing; separates insert/delete from register substitution — useful on the big DWC rows),
`d_*.txt` (per-row diffs), `obj_*.txt` (sdkobj dumps), the eight fill variants `v*/w*.c`.
