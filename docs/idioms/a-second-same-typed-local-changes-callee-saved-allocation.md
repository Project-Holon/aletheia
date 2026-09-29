# A second same-typed local can flip which of two callee-saved registers a live value gets

summary: When two values are live across the same call and both need a
callee-saved register, reusing one variable for the second value can make the
allocator give them `r5`/`r4` instead of `r4`/`r5`; declaring a *distinct*
same-typed local for the reload and using that instead reproduces the
original allocation. The instruction stream and byte count are identical, only
the registers differ, so the function reads as a whole-body `DIFF`.

Found in: `src/matched/ov_sdk/ov009_func_021773D8.c` (0x021773D8,
DWCi_TransportProcess, dwc_transport.o)

The send block reloads the connection object returned by
`DWCs_GetTransConnection(aid)` and also keeps a clamped `sendSize` value live
across `DWCs_GetOutgoingBufferFreeSize` and `DWCs_Send`. Writing both through
the one `transConnection` variable that the earlier timeout block already
assigned:

```c
transConnection = DWCs_GetTransConnection(aid);
...
transConnection = DWCs_GetTransConnection(aid);   /* same variable again */
sendSize = transConnection->requestSendSize - transConnection->sendingSize;
```

compiled the second pointer into `r5` and the size into `r4`. The original
uses `r4` for the pointer and `r5` for the size. Love them or hate them, the
27 relocations and every instruction matched; only those two registers were
swapped across the whole send block (~18 concrete byte sites).

Declaring a second pointer local and using it for the reload:

```c
struct DWCstTransportConnection *conn2;
...
conn2 = DWCs_GetTransConnection(aid);
sendSize = conn2->requestSendSize - conn2->sendingSize;
```

gives the pointer `r4` and the size `r5`, and the file verifies `EXACT`. The
new local does not add a push or a byte; it only changes the allocator's
free-register order after the earlier (dead) definition of `transConnection`.
Trying declaration-order permutations of `sendSize` and `transConnection`, and
reversing the clamp spelling, did not move it.
