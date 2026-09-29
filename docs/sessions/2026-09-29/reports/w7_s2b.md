# w7_s2b: overlay SDK lane (ov107 libmb, ov114 libnhttp)

All 18 assigned rows matched EXACT (dsi/1.1p1, -O4,p), each verified with
`manifest --verify --force --shard ovNNN/pkt_ovNNN_XXXXXXXX`. No near misses.

## Functions

| overlay | address | bytes | vendor symbol | verdict |
|---|---|---|---|---|
| ov107 | 0x021F6590 | 128 | MBi_InitTaskThread | EXACT |
| ov107 | 0x021F5B4C | 148 | MB_SetParentCommParam | EXACT |
| ov107 | 0x021F5BE0 | 204 | MBi_StartCommon | EXACT |
| ov107 | 0x021F61A4 | 232 | MBi_SendMP | EXACT |
| ov114 | 0x021BA7DC | 68 | NHTTPi_InitBgnEndInfo | EXACT |
| ov114 | 0x021BA88C | 252 | NHTTPi_Startup | EXACT |
| ov114 | 0x021BAC58 | 148 | NHTTPi_AddRequestPostDataAscii | EXACT |
| ov114 | 0x021BE6EC | 92 | NHTTP_AddRequestHeaderField | EXACT |
| ov114 | 0x021BE748 | 84 | NHTTP_AddPostDataAscii | EXACT |
| ov114 | 0x021BE79C | 96 | NHTTP_AddPostDataRaw | EXACT |
| ov114 | 0x021BE838 | 72 | NHTTP_GetHeaderAll | EXACT |
| ov114 | 0x021BE8E8 | 224 | NHTTP_SetBasicAuthorization | EXACT |
| ov114 | 0x021BEA20 | 68 | NHTTPi_GetStaticResource | EXACT |
| ov114 | 0x021BEAB8 | 208 | NHTTPi_ControlConnectionList | EXACT |
| ov114 | 0x021BEC74 | 144 | NHTTPi_PostSendCallback | EXACT |
| ov114 | 0x021BED04 | 140 | NHTTPi_BufferFullCallback | EXACT |
| ov114 | 0x021BED90 | 140 | NHTTPi_ReceivedCallback | EXACT |
| ov114 | 0x021BEE74 | 80 | NHTTPi_SetBodyBuffer | EXACT |

Total 2,498 bytes. Files: src/matched/ov_sdk/ovNNN_func_XXXXXXXX.c for each row above;
shards layout/matched/ovNNN/pkt_ovNNN_XXXXXXXX.json for each row above (18 of each).

## Levers found

- Two pool words for one address (ControlConnectionList): second extern name `g_021CF984_hdr` at the same address; the loop head is `connection_pp = &g_..._hdr; connection_p = g_021CF984; while (connection_p) { switch ...; if (ret_p) break; connection_pp = &(*connection_pp)->next; connection_p = *connection_pp; }`.
- Only ONE pool word when the image reloads it (MBi_StartCommon): a second extern there adds a second word and breaks the size; check the pool count in the image before duplicating.
- SetBasicAuthorization: `if (ok) {...} else { return -1; } return 0;` gives the shared return-0 tail; `if (ok) {...; return 0;} return -1;` does not.
- Startup: `bgn->buf = alloc(); stack_p = bgn->buf; if (stack_p == 0)` gives str then movs r2; a local assigned first gives movs then str.
- AddRequestPostDataAscii: locals `rc` then `length` (rc first).
- SendMP: no `c = work+0x500` local; writing every field as `*(unsigned short *)(g.work + 0x5NN)` lets the compiler CSE r3/r4 and fixes r5 = global; the two arms each carry their own `if (errcode == 2) work[0x50C] = 1; return errcode == 2 ? 0 : errcode;`. MBi_SetMPData is called with five arguments (cb, buf, size, u16, pollbitmap on the stack) although its DWARF lists four.
- Callback-result mask: `return -(f(...) == 0)` for the moveq/movne/rsb tail (AddPostDataAscii, AddRequestHeaderField).
- NHTTP levers from w6_s7 held: sysInfo passed to GetMutexInfoP only where the image has `mov r0, <sysInfo reg>` (GetHeaderAll, AddPostDataAscii); bare call elsewhere.
- ReceivedCallback is BufferFullCallback with callback code 3 instead of 2.

## Evidence notes

- MBi_ChildCallback (0x021F4EFC, open ov107 row, 2,464 B) is referenced as a function pointer by SendMP; the shard verify accepted it (sdk row exists).
- NHTTPi_Base64Encode (0x021BA714, open row) is a callee of SetBasicAuthorization; accepted.
- 0x021CE53C (":" literal read by SetBasicAuthorization) is declared `g_021CE53C data`, accepted as evidence.
- AddRequestPostDataAscii was matched before AddPostDataAscii so its callee is `matched`.

## Left for the next pass

Nothing from this lane's list. Remaining open rows in these objects (not in my list): NHTTPi_AddRequestPostDataBinary, MBi_SetTask (356), MBi_ChildCallback (2,464).
