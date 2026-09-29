# w7_s5b: overlay SDK, 256-399 B remainder (ov009 libsoc, ov107, ov114)

Compiler dsi/1.1p1 (4.0.0.1024 objects). Every shard verified with
`manifest --verify --force --shard ovNNN/pkt_ovNNN_XXXXXXXX`; header status copied from the output.

## Per function

| region | address    | vendor symbol         | bytes | verdict |
|--------|------------|-----------------------|-------|---------|
| ov009  | 0x0215D4AC | SOCL_Connect          | 332   | EXACT (matched) |
| ov009  | 0x0215E84C | SOCL_Close            | 308   | EXACT (matched) |
| ov009  | 0x0215F1D4 | SOCLi_CheckNConfig    | 264   | EXACT (matched) |
| ov009  | 0x0215DF08 | SOCLi_UdpRecvCallback | 284   | EXACT (matched) |
| ov009  | 0x0215D92C | SOCLi_CopyCPSBuffer   | 264   | near miss, pending |
| ov107  | 0x021F4140 | MBi_SendFixedBeacon   | 356   | near miss, pending (no change to w6_s7 draft) |
| ov114  | 0x021BD270 | NHTTPi_ThreadReqEnd   | 328   | near miss, pending (no change to w6_s7 draft) |

EXACT: 4 functions, 1,188 bytes (332+308+264+284). Near misses: 3 (264+356+328 B).

## Files and shards

- src/matched/ov_sdk/ov009_func_0215D4AC.c, layout/matched/ov009/pkt_ov009_0215D4AC.json
- src/matched/ov_sdk/ov009_func_0215E84C.c, layout/matched/ov009/pkt_ov009_0215E84C.json
- src/matched/ov_sdk/ov009_func_0215F1D4.c, layout/matched/ov009/pkt_ov009_0215F1D4.json
- src/matched/ov_sdk/ov009_func_0215DF08.c, layout/matched/ov009/pkt_ov009_0215DF08.json
- pending: src/pending/ov_sdk/ov009_func_0215D92C.c (new, no shard); ov107_func_021F4140.c and
  ov114_func_021BD270.c unchanged.

Callees still open-sdk rows (SOCLi_CloseCallBack 0x0215E980 as a pool-word function pointer in Close,
SOCLi_IsIPv4ValidDNSAddr 0x0215F0F0, SOCLi_ReadCPSBuffer 0x0215DA34) verified without an evidence complaint;
all carry the ov009 token. func_0215D92C (static in the vendor object) is left in pending.

## Levers found

- Reloading a field the original reloads every time (state at +0xac in SOCL_Connect): declare the field
  `volatile short state`; the tst/ldrsh pairs then match.
- Shared return: `goto invalid` into the `if (bcast) { invalid: return -0x1c; }` block reproduces the
  multicast/broadcast merge (`||` chain is not needed).
- Bool flag temp `int mode = 1; if (m != 0 && m != 4) mode = 0;` then `if (mode != 0) { main path }` with the
  other arm after it, gives `mov r1,#1 / cmpne / movne r1,#0` and the block order of Connect and Close.
- UdpRecvCallback: a `struct * volatile last` pointer field reproduces the second load of the queue tail
  (`ldr r0; cmp; ldrne r0; strne`) without touching the rest of the code.
- CheckNConfig: adjacent globals as plain externs (mask, my ip, gateway, dns[2] as one array) and one `||`
  chain for the gateway clear matched at the first compile.

## Near misses

- ov009 SOCLi_CopyCPSBuffer 0x0215D92C (264 B), ~9 attempts. Body, stack slots (my_port sp+6, his_port sp+4,
  his_ip sp+8, len sp+0xc) and all calls right; two residues: (1) the `recv_pipe->flag_fe == 0` update is
  if-converted (ldreq/addeq/streq) where the original branches (`bne`) over ldr/add/str; tried a recv_pipe
  local, goto form, volatile on the counter and on the flag, unsigned flag, explicit temp; (2) else arm:
  original `mov r5,#0; cmp; mvnne r5,#0x1b`, mine `subne r5,r5,#0x1c` (result = 0 then conditional) or
  `mvn / moveq` (ternary or if/else); `int result = 0` hoists the mov above the Disable call. The 0x40/0x50
  branch targets shift by 4 from these only.
- ov114 NHTTPi_ThreadReqEnd 0x021BD270: same 2-instruction residue as w6_s7 (socket temp r2 vs r0). Extra
  variants tried this pass, all unchanged: temp assigned inside the condition, keep-alive flag in a local,
  `int *` to the socket field, `unsigned` compare forms (change the compare and worsen it), `> -1`, bit test.
- ov107 MBi_SendFixedBeacon 0x021F4140: three new variants (no locals, `u8 *` lastAddr, size local), none
  change the early-block allocation (original gi in r4, cur in r0 with r3 base dead; mine gi r0, cur r3).
  Residue as in w6_s7; no new lever found.

## Next pass

The three near misses. Untried on CopyCPSBuffer: a second bool-style flag local for `flag_fe`, or the flag
read merged into the preceding `if (result ...)` condition.
