# Lane S4 — the non-ov009 tie class (size-exact: allocation or scheduling)

Eight rows, all "size-exact: allocation or scheduling" with a handful of concrete
bytes. Two of the eight were load-destination-register rows (`ldr r2` vs `ldr r0`
on the same address); both are closed, and the mechanism turned out to be the
same and to be the useful finding of this lane.

## The one lever that paid: a load whose register is right for an argument

`ov114_func_021BA988` 140 B — **closed, EXACT**
(`src/matched/ov_sdk/ov114_func_021BA988.c`, shard `ov114/pkt_ov114_021BA988`).

The residue was `ldr r2, [r5, #0xc]` vs ours `ldr r0, [r5, #0xc]`, two bytes.
`bgnEndInfo_p->socket` was being used only as the guard of the last block, so the
allocator treated it as a plain scratch and took the lowest free register (r0,
free because the `NHTTPi_GetConnectionListLength()` result just above it is
discarded).  In the object it is in **r2 because it is also the third argument**
of the next call: `NHTTPi_SocClose` *is* `func_021B9CFC`, and the sibling
`NHTTPi_ThreadReqEnd` calls that same address as `func_021B9CFC(mutexInfo_p,
req_p, bgnEndInfo_p->socket)` — three arguments, the socket in r2.  Declaring the
callee with that signature and passing the field through

```c
extern int NHTTPi_SocClose(void *mutexInfo_p, struct _NHTTPReq *req_p, int socket);
...
NHTTPi_SocClose(0, 0, bgnEndInfo_p->socket);
```

makes the load land in r2 with the `cmp r2, #0` following it and nothing else
moves: 140 bytes, EXACT, first try after 2 tries of local/cast/dead-compare
spellings by the earlier lane.  Two named locals for the socket, `volatile`, and
every "use the length result" spelling had failed.

`ov114_func_021BD270` 328 B — **already closed, EXACT**
(`src/matched/ov_sdk/ov114_func_021BD270.c`, `NHTTPi_ThreadReqEnd`, shard
`ov114/pkt_ov114_021BD270` verifies EXACT).  Same two-byte shape, same cause, and
the filed file already has the three-argument call.  The residue index still
carries this row pointed at the older two-argument draft in
`src/pending/ov_sdk/ov114_func_021BD270.c`; **the index row is stale, the pending
file is a superseded spelling**, not work in flight.

Rule: before treating "the value loads into the wrong register but the address is
right" as an allocator wall, look one call *forward*.  A load that lands in r0
where the object has r2 (or r3) is often the callee's third argument — and the
callee's own prototype in the sibling file is the evidence.

## Residues (not closed)

- `ov114_func_021C98E0` 240 B, 4 instructions: image `+00A8 ldrb r0,[r8,#1]` |
  ours `ldrb r1,[r8,#1]`; the two loads and the two stores swap r0/r1 and nothing
  else differs.  20+ spellings (in-loop and function-scope temps, both
  declaration orders, both load orders, int temps, no temps, `*(s+1)`,
  self-assignments, `while`) all reproduce the swap; `match.py sweep` all compilers
  × flags is 4 bytes out; `permuter.py` anneal 400 compiles plateaued at 4.
- `ov114_func_021C9B64` 568 B, 6 instructions: image `+0084 ldr r3,[pc,#0x19c]` |
  ours `ldr ip,[pc,#0x19c]`; the 20-byte `*(Key20 *)tmpbuf = *(Key20
  *)g_021CF7AC.secretkey` byte copy has the source in r3 and the destination in ip
  in the object, the other way round here (the 8-byte copy loop earlier in the same
  function, source r3 / dest lr, matches).  Named pointer locals in both orders
  change nothing (the spellings that do change it also lose the post-indexed
  load/store pair).
- `ov016_func_021D3638` 120 B, 2 instructions: image `+0068 moveq r0,r5` |
  ours `movne r5,r4`; the object writes the 0/1 select straight into r0 with two
  predicated moves, ours copies r4 into the variable's home and returns it.  Every
  "fresh value" return spelling (`? 1 : 0`, `!= 0`, `!!`, `& 1`, `(u8)call`,
  if/else returns, named one/zero with the ternary) produces the predicated tail
  but flips the two constants to r4=0/r5=1 (13 rows); every spelling that keeps
  the constants in the object's r5=0/r4=1 keeps the copy-through-r5 tail.  Pin
  sweep: 9 compilers × 7 flag sets, all 5 bytes out; `permuter.py` 400 + 400
  compiles from the two arms of that trade-off, no improvement.
- `ov016_func_021CC0E8` (`button`) 288 B, 2 instructions: image `+00B8 add ip,
  r5,#1` | ours `mov r2,r4`; the argument setup of
  `DWCi_WINlInitEx(0x46, 0, 1, lang, idx + 1)` runs 5th (ip), 4th (ldrsb), 3rd
  (r2) in the object and 3rd, 4th, 5th here.  Named 5th-argument local, inlined
  `g_021DA724[DWCi_Language()]`, comma assignment of `lang`, cast arguments, and
  hoisting `idx + 1` above the sound call all keep the left-to-right order or
  make it worse.
- `ov172_func_021C0370` (`GetWord`) 80 B, 5 instructions: image `+0010 ldrb
  r3,[r0,r1]` | ours `ldrb r1,[r0,r1]`; the little-endian arm materialises
  `zext(word)` as a value of its own (`lsl r1,r0,#16 / lsr r1,r1,#16`) and ORs the
  shifted byte into it, ours folds the zero-extension into the ORR's shifted
  operand.  Eight arm-1 spellings (cast on `word`, cast on the byte, both casts,
  return-the-expression, `|=`, parenthesised variants) all fold it the same way;
  the big-endian arm with the folded form is byte-identical in both.
- `ov016_func_021B87F0` 464 B, 6 instructions: image `+00EA movs r4,r5` |
  ours `lsls r6,r6,#2`.  **Not touched**: the working tree already has this file
  modified by another writer, so per the brief it was left alone (verified
  read-only at its current state: 464/464 bytes, 6 rows, first at +00EA).

## Measured

~1,500 compiles: `permuter.py` 150 + 400 + 400 + 400, `match.py sweep` 63
configs, ~50 hand variants, the rest verification.  Wall clock ≈ 55 min.
