# unit_02176DEC (ov009)

3 part files remain (p01 .. p03, address order), each byte-exact.

Round 5 (r5 s05): old p01+p02+p03 (0x02176DEC..0x021770EC) are one part now. It holds the
canonical TransConn / TransInfo structs (g_021AB180 is a TransInfo pointer), the narrow
func_02176E90(unsigned char aid, ...) that fixed the DIFF at the old p02, and a typed
DWC_SendReliable call.

Next: old p04 (now p02, 0x021770EC..0x02177E64, 27 functions) reaches TransInfo through
raw offsets (sTransInfo macro cast to char **, connection + 0x1d) and through its own
DWCstTransportInfo / DWCstTransportConnection copies. Rewrite those functions with the
TransInfo and TransConn fields of p01 (sendCallback at 0x700, sendSplitMax at 0x720,
connKeepAliveTime at 0x724), use func_02177770 / func_02177788 / func_021777C0 /
func_02177E64 as the names of the functions it defines (its symbol rows give them second
names DWCs_GetTransConnection, DWCs_GetRecvState, DWCs_Send), then join with p01 and p03.
