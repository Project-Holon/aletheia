# sdk_overlays lane report (2026-09-27)

Library with the most open overlay SDK bytes: libdwcutil (117 KB, ov016). Root: AOSS_Init_old
0x021B62C0 (2584 B, aoss.o, Thumb), real. Tree: aoss.o, 38 functions closed bottom-up, all EXACT/EXACT*,
root not attempted. All in shard pkt_ov016_021B62C0, files src/matched/ov016_func_<ADDR>.c, real vendor
names.

Closed: AOSS_Memcmp, AOSS_Htonl/Ntohl, AOSS_Htons/Ntohs*, aoss_IP_sta, aoss_release, aoss_set_error,
aoss_get_error, AOSS_Memset, aoss_data_init, aoss_check_str*, aoss_get_bin, make_crc_table, update_crc*,
crc, MakeKey, AddKey, Rotate*, arcfour_byte*, RC4encrypt, RC4init*, CryptSeqNo*, EncodeRC4, DecodeRC4,
AOSS_Rand, CheckSeqID, CheckRecvSeqID, SetPacketHeader*, SendPacketUDP, PacketDataSet,
AOSS_StatusExclusion, MakeSendSeqID, AOSS_set_APInfo, checkAP, GetBssidData, AOSS_Select,
AOSS_SetIPAddr (* = EXACT*). Most were first drafts from the object's DWARF (types, locals and their
registers). The levers that closed the rest were declaration order (checkAP), a named local (RC4encrypt's
`state`), statement split (AOSS_Rand), and grouping `ptr + (num - 1)` (aoss_get_bin).

Pin: aoss.o, aosslink.o, apc.o and atermset.o (25 KB of open rows) carry `.comment` "Metrowerks C/C++ for
ARM 3.0.0.126", which is exactly 2.0/sp1p2. I filed them `compiler: ../2.0/sp1p2`. The byte tell is
aoss_release: the image reloads the .bss pool word before each access and is 44 B. 1.1p1 keeps the
base in a register (40 B, 31 bytes out). 2.0/sp1p2 gives 0 mismatches. Other stamps are 1024 (TwlSDK,
TwlWiFi) = 1.1p1 and 1025 (TwlDWC), for which we have no build. Statics are addressed section-relative,
so .bss/.data are declared as one object each (`aoss_bss` 0x021DC040, `aoss_data` 0x021DAAB4).

Integrator: add the sp1p2 rows to docs/FRONTEND-PINS.md. Also note that DWARF leaves out unused parameters
(make_crc_table, AOSS_Select).

Next (aoss.o, open): AOSS_Init_old 0x021B62C0, AOSS_seq_data_copy 0x021B6D8C, RecvMessage 0x021B70C4,
AstsSetInitRes 0x021B7164, AstsSetSecureRes 0x021B7240, AstsRestartRes 0x021B7318, DecodePacket
0x021B73BC, GetProductInfo 0x021B7540, GetWEPData 0x021B7620, GetWPAData 0x021B7774, GetSecurityData
0x021B785C, SendMessage 0x021B797C, AstsSetInitReq 0x021B79D0, AstsSetSecureReq 0x021B7B14,
AstsRestartReq 0x021B7BF0, SetStaData 0x021B7C5C. Also aosslink.o and apc.o (AOSSi_WLANConnect,
AOSSi_WLANGetBSSList, APC_*).
