# Wave 19 lane dying_local (19O)

Lever under test: writing the mismatched value into a local that dies just
before it (docs/idioms/a-result-computed-in-a-dying-local-takes-that-locals-register.md).
Nothing closed and nothing moved. 31 measurements. The permuter was not run
because no function moved.

| address | before -> after | measured | reading |
|---|---|---|---|
| 0x0206F4C8 | 2 -> 2 | 10 | The `adds` operand order comes from mwcc canonicalising the unnamed 64-bit sum. It is not a register choice. b in t/k/f: 2. a in t/k: 5. With the product named, a is sign-extended in place and b lands in lr: 27-29. |
| 0x02071104 | 6 -> 6 | 7 | A local reused across both halves gets one register (web) for both, so it cannot put scaleT in r4 only in the second half: 6-28. |
| 0x02069BA0 | 6 -> 6 | 6 | Refill byte, the constant 8 and the shortfall, each put into have/mask/acc: all 6. The pair is two argument-setup moves before the call. |
| 0x0202350C | 12 -> 12 | 3 | No local dies at +0x20. Made-to-die argument locals (&f10, &f20, cfg+4) reused for kb and a4: 18 (the +0x20 window is unchanged, plus 6 at the argument setup). This is load/store scheduling. |
| 0x0202627C | 10 -> 10 | 5 | There is no loop variable. Flag bit into rec and cb into sub together: 10 (23 in image read order). The flag byte is the bitfield's RMW temporary. Making it an explicit byte local gives 272 bytes. |

Finding: the dying-local lever works only when the mismatched value is a
fresh temporary that gets its own web. It does not help with operand
canonicalisation, argument-move order, load/store hoisting, or bitfield
RMW temporaries. It also does not help when the reused local would span two
regions that need different registers.

Files written: new wave-19 dying_local sections in
docs/notes/pkt_0206F4C8.c.txt, docs/notes/pkt_02071104.c.txt,
docs/notes/func_02069BA0.c.txt, docs/notes/func_0202350C.c.txt and
docs/notes/pkt_0202627C.c.txt. Best sources are unchanged. Nothing was filed
in src/, no shards were verified, and there is no new idiom.

Seeds: none noticed. Integrator: nothing to do beyond staging the five note
files and this report.
