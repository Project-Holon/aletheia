# unit_02199394 (ov009)

Round 4 (lane r4_ov03): 5 parts -> 2. Canonical _NATNegotiator (size 0x54, named fields by offset), NatnegGlobals at 0x021AE698 (negotiateList, overrides, ips, natify fields) and a byte-array SOCSockAddrIn are shared by all parts. Every part verifies EXACT.

Parts: unit_02199394_p01.c (func_02199394, func_021994F0), unit_02199394_p02.c (func_021995E4 .. func_02199BE4).

Blocker p01|p02: NatNegPacket has one view per function. Offsets: magic 0, version 6, packettype 7, cookie 8, then a union at 0xC:
- init: porttype 0xC, clientindex 0xD, usegameport 0xE, localip[4] 0xF, localport[2] 0x13, gamename[64] 0x15
- connect: ipaddr 0xC, port 0x10, gotyourdata 0x12, finished 0x13
- report: clientindex 0xD, negResult 0xE, natType 0x10, mappingScheme 0x14, gamename[0x32] 0x18
Locals of this type are 0x4C bytes in every function; a union with gamename[64] would be 0x58, so the canonical block needs the real packed layout (GameSpy packs these packets). Also strlen() and func_0217D254 have two prototypes (K&R vs typed).

SOCSockAddrIn here is {len, family, port[2], addr[4]}: func_021994F0 copies it with byte loads and stores; a u16/u32 view copies with ldr and does not match. unit_02199D1C uses the u16/u32 view.
