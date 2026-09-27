# sdk_overlays_2 lane report (2026-09-27)

Tree: AOSS_Init_old's subtree in ov016 (libdwcutil aoss.o, aosslink.o, apc.o), all ../2.0/sp1p2
(3.0.0.126 stamp), vendor names. 31 closed, all EXACT/EXACT* at the first measurement or after
one or two levers.

- pkt_ov016_021B62C0 (+22, now 60): aoss.o AstsRestartReq, SendMessage*, SetStaData, AstsSetInitReq,
  AstsSetSecureReq, GetWPAData, GetWEPData*, GetSecurityData, GetProductInfo*, AstsRestartRes*,
  AstsSetSecureRes, AstsSetInitRes, DecodePacket, RecvMessage, AOSS_seq_data_copy, AOSSi_Init;
  aosslink.o Get_WLLA_SSID_PARAM*, Set_WLLA_BSS_INFO, AOSSi_Disconnect, AOSSi_InitLocal,
  AOSSi_EndLocal, AOSSi_WLANGetBSSList.
- pkt_ov016_021B89DC (new, 9): apc.o APCi_Notify, APCi_MoveIdleState, APC_GetAPList*, APC_SearchStart,
  APC_SearchEnd, APC_Disconnect, APC_End, APC_Connect, APC_Init.
- Filed from tree_ov016's scratch (re-verified): pkt_ov016_021BADD8 (aeskw_xor64*, rijndaelKeySetupEnc/Dec,
  rijndaelEncrypt/Decrypt), pkt_ov016_021BBC8C (MD5Transform as ov016_func_021BBC8C_md5.c, MD5_memset*).

What closed things: declaring locals in the reverse of the DWARF order (new idiom
dwarf-lists-locals-in-reverse-declaration-order.md); explicit case labels for dense message-code tables;
case bodies in image order; SecurityInfo named by its own symbol where the object pools it directly.
New section objects: aosslink_bss 0x021DCE20, apc_bss 0x021DCF80.

Shards verified twice (0 rewritten); manifest --check clean.

Near misses (docs/notes/pkt_ov016_021B62C0.c.txt): AOSSi_WLANConnect 0x021B87F0 (register spill, wep_id not
constant-folded in the original), keywrap_decrypt 0x021BADD8 (6 bytes, one r2/r3 swap).

Remainder: AOSS_Init_old 0x021B62C0 (2584 B, every callee now matched except WLANConnect), AOSSi_WLANConnect,
keywrap_decrypt, keywrap_encrypt 0x021BAC20, the rest of atermset.o, and tree_ov016's vscan.txt: 89 open
addresses with no symbols_sdk row that match libdwcutil objects verbatim (58 have no recorded object, 15 are
sceneoptmovcompl, 9 are sceneoptinfo.o). libmatch recognition needs fixing for those.

Integrator: add aosslink.o, apc.o and atermset.o to the sp1p2 rows in FRONTEND-PINS.md; regenerate the idiom
index.
