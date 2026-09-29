# Lane w7_s4b (overlay SDK, libsoc / libnhttp leftovers of w7_s4)

All 17 rows EXACT. Files under src/matched/ov_sdk/, shards under layout/matched/ovNNN/ (pkt_ovNNN_XXXXXXXX.json).
Status copied from `manifest --verify --force --shard`; a second pass over all 17 shards printed EXACT for each.

| Region | Address | Vendor symbol | Bytes | Verdict |
|---|---|---|---|---|
| ov009 | 0x0215F854 | SOC_Fcntl | 80 | EXACT |
| ov009 | 0x0215F7E8 | SOC_SetResolver | 108 | EXACT |
| ov009 | 0x0215FAD0 | SOC_InetAtoN | 88 | EXACT |
| ov009 | 0x0215FBCC | SOC_Poll | 180 | EXACT |
| ov009 | 0x0215F650 | SOC_GetHostByName | 196 | EXACT |
| ov009 | 0x0215D650 | SOCLi_BindCallBack | 120 | EXACT |
| ov009 | 0x0215ED60 | SOCL_CalmDown | 112 | EXACT |
| ov009 | 0x0215EBF0 | SOCL_Cleanup | 160 | EXACT |
| ov009 | 0x0215ECB8 | SOCL_CloseAll | 168 | EXACT |
| ov009 | 0x0215E980 | SOCLi_CloseCallBack | 156 | EXACT |
| ov009 | 0x0215EB14 | SOCLi_FreeCommandPipe | 160 | EXACT |
| ov009 | 0x0215EA1C | SOCLi_CleanupSocket | 248 | EXACT |
| ov009 | 0x0215CF14 | SOCLi_ExecCommandPacket | 116 | EXACT |
| ov009 | 0x0215CFC0 | SOCLi_CommandPacketHandler | 176 | EXACT |
| ov009 | 0x0215D124 | SOCLi_CreateSocketCallBack | 116 | EXACT |
| ov009 | 0x0215EFB0 | SOCL_GetStatus | 208 | EXACT |
| ov114 | 0x021BC924 | NHTTPi_SendHeaderList | 204 | EXACT |

Total 2,644 bytes. Files: src/matched/ov_sdk/ov009_func_{0215F854,0215F7E8,0215FAD0,0215FBCC,0215F650,0215D650,0215ED60,
0215EBF0,0215ECB8,0215E980,0215EB14,0215EA1C,0215CF14,0215CFC0,0215D124,0215EFB0}.c and ov114_func_021BC924.c.
Shards: layout/matched/ov009/pkt_ov009_<same addresses>.json and layout/matched/ov114/pkt_ov114_021BC924.json.
No pending files remain for these rows; no near misses. Callees that were open-sdk rows (0215EEE0, 0215EE98, 0215EDD0,
0215ECB8 etc.) attest as sdk through their catalog rows.

## Levers and notes

- Socket `state` (short at +0xac): SOCLi_BindCallBack and SOCL_GetStatus only match with `volatile short state`
  (per-arm ldrsh/orr/strh instead of a hoisted load, and one ldrsh per test). The vendor DWARF shows no volatile; both
  headers carry a `note:` line saying so. Other functions (CloseCallBack, CleanupSocket) match without it.
- Stream test (`mode == 0 || mode == 4`) needs a static inline returning `int r = 1; if (mode != 0 && mode != 4) r = 0;`
  (CloseCallBack, CleanupSocket, GetStatus).
- SOC_GetHostByName: function-scope statics do not attest (base relocates against `.bss`, refused). What works is one
  extern struct at 0x021AA4BC (hostip, 0x14 gap, addrList[2], hostent) as the store base, plus separate externs for the
  address-of pool words: `g_021AA4BC_ip` (second name for 0x021AA4BC, declared in the symbols block), g_021AA4D4,
  g_021AA4DC, g_021AA544. The 0x14 gap is other statics of soc.o (size-sorted .bss), modelled as an opaque gap.
- Poll: `status = status_mask & SOCL_GetStatus(fp->fd)` inside the call expression fixes the `ands` operand order;
  nfds test before fds test; `time - 523`.
- Tail merging: CleanupSocket must call FreeCommandPipe separately in each arm (no goto); the compiler merges the bl.
- CommandPacketHandler: second OS_ReceiveMessage is `(cpipe, 0, 0)`, not `&command`. ExecCommandPacket needs locals
  declared result, response, response_queue (stack order).
- CloseAll: one `||` chain with a single `return -26` tail.
- 0215F650 uses the header name func_0215F650 with generic externs; no vendor names appear in the C.
