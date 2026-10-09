# unit_02199D1C (ov009)

Round 4 (lane r4_ov03): 7 parts -> 2. Canonical _NATNegotiator (size 0x54) and NatnegGlobals (0x021AE698) applied; every part verifies EXACT.

Parts: unit_02199D1C_p01.c (func_02199D1C .. func_0219A7AC), unit_02199D1C_p02.c (func_0219A968 .. func_0219AB8C).

Blocker p01|p02: struct _NatNegPacket is defined with different member subsets (offset table in unit_02199394/MERGE.md). p02 also keeps per-part renamed NatNegPacket_02199D1C and SOCSockAddrIn_02199D1C copies (temporary renames, to be replaced by the canonical packet block).
