# Lane T15 — ov009 open SDK rows 72-79 (slice `open_rows.py ov009 72 8`)

Slice as printed: rows 72..78 (the slice's 8th row does not exist; ov009 has 79 open rows, indexed 0..78).
`python scratch/a2/open_rows.py ov009 72 8` lists:
0x02163628, 0x02187D60, 0x0217AB78, 0x021870B8, 0x0216D57C, 0x021702A0, 0x0219091C.

## Closed: 0x02187D60 gpiProcessRecvBuddyStatusInfo — 2264/2264, EXACT

* `src/matched/ov_sdk/ov009_func_02187D60.c`, pin `dsi/1.1p1`, `-O4,p`, `--lang c99`,
  compiled 2264 bytes, 103/103 relocations resolved.
* Shard: `layout/matched/ov009/pkt_ov009_02187D60.json`
  (`python tools/match.py manifest --verify --shard ov009/pkt_ov009_02187D60` → 1 entry, EXACT).
* The row was at 2260/2264 (-4) when this lane started (lane S6 had taken the previous
  -60 to -4). The last four bytes are the callback arm's exit: written as
  `rc = gpiAddCallback(...); if (rc != 0) return rc;` the arm falls into the function's
  shared `mov r0,#0` exit instead of duplicating the epilogue, which is exactly the
  image's `cmp r0,#0; addne sp,#0x14; addne sp,#0x400; popne` before the shared exit.
  A plain `return gpiAddCallback(...);` emits the epilogue in place (7 instructions vs the
  image's 8) — that single instruction was the whole remaining difference.
* Variant test harness kept at `scratch/laneT15/trytail.py` (5 tail shapes; only the
  assign-and-test form is right).
* Note: `src/pending/ov_sdk/ov009_func_02187D60.c` is still on disk and still modified in
  the working tree (lane S6 was editing it, see `git status`). It is now superseded; this
  lane did not touch it (no deletions), so an integrator should drop the pending copy.

## Vendor objects are in the tree — the best reference for every open DWC row

`python tools/sdkobj.py <addr> --region ov009` prints, per row: the archive member, the
`.comment` compiler stamp, the DWARF prototype + every parameter/local with its allocated
register, the full relocation list with C names and image addresses, the `symbols:` lines a
house header wants, and an object-vs-image instruction listing. It also maps the stamp to a
local pin when one exists. All five parked rows below are `4.0.0.1025` (or `4.0.0.1024`),
which `tools/mwccarm` does not contain (only 1.1 … 1.6sp2, 2.0, dsi/*).

| address | function | archive member | vendor stamp → pin |
|---|---|---|---|
| 0x02163628 | CPSi_sha1_block | TwlWiFi_base …/libssl.TWL.HYB.a (sha1.o) | 4.0.0.1024 → **dsi/1.1p1** |
| 0x021870B8 | gpiProcessRecvBuddyMessage | gamespy …/libdwcgsgp.TWL.HYB.a (gpibuddy.o) | 4.0.0.1025 → none |
| 0x0217AB78 | DWCi_Netcheck_Thread | TwlDWC …/libdwcauth.TWL.HYB.a (dwc_netcheck.o) | 4.0.0.1025 → none |
| 0x0216D57C | DWCi_MatchProcess | TwlDWC …/libdwcmatch.TWL.HYB.a (dwc_match.o) | 4.0.0.1025 → none |
| 0x021702A0 | DWCi_ProcessRecvMatchCommand | TwlDWC …/libdwcmatch.TWL.HYB.a (dwc_match.o) | 4.0.0.1025 → none |

## Parked rows (named residue)

### 0x02163628 CPSi_sha1_block — 1652/1652 size-exact, 142 concrete bytes, allocator only
Pin is right: `sdkobj` maps the object's stamp 4.0.0.1024 to **dsi/1.1p1**, and the DWARF
gives the vendor's allocation — `a r5, b r6, c r10, d r8, e r9, i r0, j r1, w[16] at fb+16`.
Full pin sweep (`tools/match.py sweep`, 9 compilers × 7 option sets, `scratch/laneT15/sweep_02163628.txt`):
best is 1.1/1.1p1 `-O4,p` at 142 concrete bytes, size-exact everywhere; every other
configuration is worse (1176+). First divergence +0010 image `add r7, sp, #0x10` |
ours `add r8, sp, #0x10`: the image keeps `&w` in r7 and c in r10, ours keeps `&w` in r8 and
c in r7. Five declaration orders taken from the DWARF variable order (`j, i, e, d, c, b, a, w`
and reverses) were compiled (`scratch/laneT15/s1_*.c`): the assignment does not move, 89
mismatching lines / 142 bytes either way. Third re-spelling is not the lever; the row is
capped on register allocation.

### 0x021870B8 gpiProcessRecvBuddyMessage — 3212/3240 (-28), 1908 concrete bytes
`scratch/laneT15/sweep_021870B8.txt`: all 9 pins × 7 option sets give 3212 bytes and ≥1908
concrete bytes; 1.6sp1/1.6sp2 are worse (1953). First divergence +011C image `mov fp, #1` |
ours `bgt #0x218720C` (the image hoists the error constant 1 into fp right after the date
parse and rematerialises `&buffer`; 1.1p1 hoists `&buffer`). The -28 bytes is the
`profile->buddyStatus` zero fill: image +0708 `mov r1, #7; strb sl,[r0]; strb sl,[r0,#1];
strb sl,[r0,#2]; strb sl,[r0,#3]; add r0,r0,#4; subs r1,r1,#1; bne` (7 four-byte
iterations = 28 bytes) | ours `bl memset` (0x020923B0). Tried this lane, from a scratch
copy: a hand `for (zi = 0; zi < sizeof(GPIBuddyStatus); zi += 4)` with four `zp[k] = 0`
(`scratch/laneT15/z_loop4.c`) gives 3244 bytes and moves the first divergence EARLIER to
+000C (`&buffer` moves r7→r4, so freeing the memset call re-allocates the function); the
plain byte loop (`z_bytelp.c`) gives 3232. Neither reproduces the image's unrolled fill, so
the fill is 4.0.0.1025's own expansion, not a hand loop. Capped on the compiler version.

### 0x0217AB78 DWCi_Netcheck_Thread — 1696/3184, partial body
`scratch/laneT15/0217AB78.diff`: +0004 image `sub sp, sp, #0x290` | ours `sub sp, sp, #0x90`
(1696 compiled vs 3184), so the parked body is a partial, not a near miss: 422 mismatching
lines. The vendor prototype and every local are available from `sdkobj`:
`static void DWCi_Netcheck_Thread(void)` with `DWCCalInfo calinfo [fb+56]`, `int wait_sec r11`,
`int wait_len r10`, `char *wait r9`, `int data_len r11`, `char *data r8`, `int url_len [fb+8]`,
`char *url r7`, `char[4] retcode [fb+32]`, `char *bodywayport r10`, `char *body302 r11`,
`free r6`, `alloc r5`, `DWCAuthResult authresult [fb+204]`, `DWCWiFiInfo DWC_netcheck_wifiinfo [fb+36]`,
`int httpretcodei r10`, `char *httpretcode r0`; 26 call targets and 6 data targets are listed
by `sdkobj` with their image addresses. Reconstruct against that table, not from the current body.

### 0x0216D57C DWCi_MatchProcess — 1028/3908, partial body
`scratch/laneT15/0216D57C.diff`: +0000 image `push {r3, r4, r5, r6, r7, r8, sb, lr}` | ours
`push {r4, lr}` (1028 compiled vs 3908), 241 mismatching lines. The parked header already
says "partial reconstruction"; the per-case guards and argument expressions are absent.
`sdkobj` gives `void DWCi_MatchProcess(int fullSpec)` with locals `fullSpec r5`,
`DWCstNodeInfo *pNodeInfo r6`, `GTI2Connection *connection r0`, `int i r5`, `DWCstNodeInfo *info r0`.

### 0x021702A0 DWCi_ProcessRecvMatchCommand — 852/4396, partial body
`scratch/laneT15/021702A0.diff`: +0000 image `push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}` |
ours `push {r3, r4, r5, lr}` (852 compiled vs 4396), 204 mismatching lines. `sdkobj` gives the
prototype `static int DWCi_ProcessRecvMatchCommand(unsigned char command, int srcPid,
unsigned long srcIP, unsigned short srcPort, unsigned long *data, int len)` with
`command r9, srcPid r8, srcIP r10, srcPort r11, data r7`.

## Not this lane's row

0x0219091C `gpiProcessSearch` (9460 bytes) belongs to lane S10
(`docs/notes/ov009_func_0219091C.md`); its parked source is modified in the working tree.
Left untouched.

## Scratch

`scratch/laneT15/`: `arseek.py` (archive member extractor), `dwline.py` (DWARF-2 line
program dumper, unfinished — the file-table parse for v2 works, the address/line decoding
does not; the register tables from `tools/sdkobj.py` are what is actually needed),
`trytail.py` (0x02187D60 tail variants), `s1_*.c`, `z_*.c`, `*.diff`, `sweep_*.txt`.
