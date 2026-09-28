# sdk_overlays_4 lane report (2026-09-28)

Tree: the rest of atermset.o in ov016 under AutoConfigThreadEx (all ../2.0/sp1p2, -O4,p, vendor names).
Worked only from vendor objects via sdkobj.py; nothing under sdk/ opened.

**Closed (5 new, 1 promoted)**
- pkt_ov016_021BA804 (now 36): alarmCallback 0x021B979C EXACT (tail call AtermApc_callback((int)event, 0);
  the callback's unused second parameter is dropped from DWARF), APC_GetState 0x021B96A8 EXACT,
  SendFrame 0x021B9EE0 EXACT (DWARF drops an unused second parameter; the body moves r2/r3 down).
  ConnectAP 0x021B98A4 re-verified EXACT once alarmCallback was in, moved src/pending -> src/matched
  (git mv staged it).
- pkt_ov016_021BBC8C (now 7): MD5Encode 0x021BC55C EXACT*.

Both shards verified twice (second pass 0 rewritten); manifest --check clean.

**Flag check:** atermset.o is -O4,p (rijndaelKeySetupDec and Encode go DIFF at -O3,p).

**Near misses** (docs/notes/pkt_ov016_021BA804.c.txt, dated sdk_overlays_4):
- CheckAccessPoint 0x021B9A2C: the original hoists two loads out of a loop across strlen/memcmp calls.
  Adding two locals the DWARF does not list gets it to 56 bytes; the DWARF-faithful draft is 420 off.
- ScanAP 0x021B9BF8: 652 of 660 bytes. Closed so far: dense 0..19 event switch, one-statement
  BssListSize, retv = -1 first, MACADDR struct copy. Still open: the found block's 6-byte gAPMac copy,
  and the n counter the original keeps alive.

**Remainder for the next lane:** ScanAP, CheckAccessPoint, GetWLanSetElement 0x021BA3F4
(needs _WS_11G_ENCRYPT_DATA: keys of 0x28 at EncryptData+0x30, a 0x48 buffer at +0xD0),
StoreNetParam 0x021BA67C, then AutoConfigThreadEx 0x021BA804. Earlier near misses (SetFrameData,
GetMacEncKey, ...) block the root too. Then libdwcutil by open count: dwc_mov_wh.o 33,
scenesetlist.o 31, keyboard.o 25, scenesetaplist.o 23 (none started).

**Seeds** (starts with no label, now matched): 0x021B979C alarmCallback (ABS32 at ConnectAP+0x118
and ScanAP's pool), 0x021B96A8 APC_GetState and 0x021B9EE0 SendFrame (THM_CALLs from AutoConfigThreadEx).

**Integrator:** add the three seeds to function_starts.txt; stage the four new src/matched files.
