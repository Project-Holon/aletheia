# unit_0219BA58 (ov009)

Round 3 (lane r3_ov03): the greedy merge with the call-argument harmonizer was re-run; the parts below are what is left. Every part verifies byte-exact on its own.

14 parts, each byte-exact. Each part declares its own partial view of the GameSpy QR2 and socket
types: struct qr2_implementation_s, qr2_buffer_s, qr2_t (different field subsets per part, for
example cc_callback, lastheartbeat), SOCInAddr and SOCSockAddrIn (different shapes). Also an
"illegal function definition" at the func_0219C154 part (machine-style definition). Next step:
one canonical type block (see src/game/ov009/unit_0219E9F4.c for the SBServerList approach).

Parts: unit_0219BA58_p01.c, unit_0219BA58_p02.c, unit_0219BA58_p03.c, unit_0219BA58_p04.c, unit_0219BA58_p05.c, unit_0219BA58_p06.c, unit_0219BA58_p07.c, unit_0219BA58_p08.c, unit_0219BA58_p09.c, unit_0219BA58_p10.c, unit_0219BA58_p11.c, unit_0219BA58_p12.c, unit_0219BA58_p13.c, unit_0219BA58_p14.c
