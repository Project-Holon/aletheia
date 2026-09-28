# sdk_overlays_3 lane report (2026-09-28)

Relaunched after the cut. All ../2.0/sp1p2 (3.0.0.126 stamp), vendor names, every shard verified twice (0 rewritten on the second pass).

**Salvaged** (pkt_ov016_021B62C0): AOSS_Disconnect 0x021B81EC (EXACT*, re-verified). AOSS_Init_old 0x021B62C0 moved from src/pending to src/matched, now **EXACT**. Two things closed it: the dead `bne` pair in both WLANConnect retry loops (new idiom a-dead-repeated-branch-is-a-nested-retest.md), and retry1's initialiser @8259, declared as aoss_rodata 0x021D77C4.

**New, atermset.o** (root AutoConfigThreadEx, new shard pkt_ov016_021BA804, 32 EXACT/EXACT*): soAlloc, soFree, AtermApc_InitEventBuf/GetEvent/callback, APCi_Notify, APCi_MoveIdleState, APC_SearchStart/Disconnect/End/Connect/Init (ported from apc.o's copies, plus notices 8/9 and a 0x60 WEP buffer), InitAtermApcNetwork's siblings FreeAtermApcNetwork and DisconnectAP, SendFrameViaInterface, SendBroadcast, GetFrameData, GetElementData, GetFirstElement, SetElementData, SetSingleElement, IsSearchCommand, GetCommandElement, SetSearchRes, AsciiToHex, AutoConfigThread, GetTickCount, PutHex, PutMac, SendNotify, ATERMi_ApConfigGetState, ATERMi_ApConfigEnd. pkt_ov016_021BBC8C gains 4: MY_MD5Update, MY_MD5Final, Encode, MD5_memcpy. The statics are declared as atermset_bss 0x021DCFD0 and atermset_data 0x021DAB58. Pooled arrays are declared separately.

**Pending:** ConnectAP 0x021B98A4 is MATCH, blocked by alarmCallback.

**Near misses** (docs/notes/pkt_ov016_021BA804.c.txt and pkt_ov016_021B62C0.c.txt): SetFrameData, InitAtermApcNetwork, ATERMi_ApConfigStart (inline 232-byte zero fill), GetMacEncKey, keywrap_decrypt (6), keywrap_encrypt (15 lines; permuter seeds 7701/7702), AOSSi_WLANConnect.

**Next lane:** CheckAccessPoint 0x021B9A2C, ScanAP 0x021B9BF8, GetWLanSetElement 0x021BA3F4, StoreNetParam 0x021BA67C, AutoConfigThreadEx 0x021BA804. Then libdwcutil by open count: dwc_mov_wh.o 33, scenesetlist.o 31, keyboard.o 25, scenesetaplist.o 23.

**Seeds** (unlabelled atermset.o statics): 0x021B979C alarmCallback (ABS32 at ConnectAP+0x118), 0x021B96A8 APC_GetState and 0x021B9EE0 SendFrame (both called from AutoConfigThreadEx).

**Integrator:**
- Shards committed in b9a8c434 and 9602452b reference about 38 ov016 sources that were never committed (for example ov016_func_021B6D8C.c and 021B8678.c). Stage them.
- I deleted the tracked asm placeholder src/pending/ov016_func_021BC804.c; SendNotify is now C.
- Add atermset.o to the sp1p2 rows in FRONTEND-PINS.md, and regenerate the idiom index.
