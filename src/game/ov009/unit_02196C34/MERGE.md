# unit_02196C34 (ov009)

Round 3 (lane r3_ov03): the greedy merge with the call-argument harmonizer was re-run; the parts below are what is left. Every part verifies byte-exact on its own.

Ten parts left (was 11). Boundaries stop on GTI2Connection / GTI2Socket redefinitions with different member subsets (socket, buffer, peer, lastSend, field_44) and on Sock / GT2ConnectionCallbacks being undefined in one part.

Shared GameSpy gt2 transport objects (same layout in unit_02194EC4, unit_02195E80,
unit_02196C34): each part declares its own partial view of struct Conn / GTI2Connection and
Sock / GTI2Socket. Offsets seen in unit_02194EC4 (they agree across the views):
GTI2Socket: socket 0, ip 4, port 8, connections 0xC, closedConnections 0x10, close 0x14,
error 0x18, callbackLevel 0x1C, connectAttemptCallback 0x20, socketErrorCallback 0x24,
sendDump 0x28, recvDump 0x2C (size 0x30).
GTI2Connection: socket 8, state 0xC, result 0x18, level 0x24, callbacks (connected 0x28,
received 0x2C, closed 0x30, ping 0x34), filters at 0x98 (p05 view) and 0x9C (p06 view), size 0xA0.
The next step is one canonical struct per object with those fields, applied to every part
(ol041/unif41.py recurses forever on the self-referential Conn/Sock members: write the block
by hand, then run the greedy merge again). Also func_02184208 and func_02197FDC have different
prototypes per part (void *filters vs typed array, Sock * vs Sock_02195340 *).

Parts: unit_02196C34_p01.c, unit_02196C34_p02.c, unit_02196C34_p03.c, unit_02196C34_p04.c, unit_02196C34_p05.c, unit_02196C34_p06.c, unit_02196C34_p07.c, unit_02196C34_p08.c, unit_02196C34_p09.c, unit_02196C34_p10.c

Round 4 (lane r4_ov03): unit_02194EC4 is now one file with the canonical GTI2Socket / GTI2Connection block (see unit_02194EC4.c). Copy that block here. Extra offsets seen in this TU: GTI2Socket protocolType 0x40, protocolOffset 0x44 (headerBase, overhead, magicOffset). GTI2Connection full view is struct GTI2Connection_02196658 in unit_02195E80_p05 (ip 0, port 4, socket 8, state 0xC, initiated 0x10, freeAtAcceptReject 0x14, connectionResult 0x18, startTime 0x1C, timeout 0x20, callbackLevel 0x24, callbacks 0x28, initialMessage 0x38, initialMessageLen 0x3C, data 0x40, incomingBuffer 0x44, outgoingBuffer 0x50, incomingBufferMessages 0x5C, outgoingBufferMessages 0x60, serialNumber 0x64, expectedSerialNumber 0x66, response 0x68, lastSend 0x88, challengeTime 0x8C, pendingAck 0x90, pendingAckTime 0x94, sendFilters 0x98, receiveFilters 0x9C). Use it as the base, rename per-part field_NN views to it.
