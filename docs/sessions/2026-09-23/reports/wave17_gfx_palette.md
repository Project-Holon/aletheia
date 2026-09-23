# Wave 17, lane gfx_palette

Per address (bytes out, before -> after):

- double3Ddisp 0x0204E914: 15 -> 0, EXACT. Lever: in the inner loop, take the element's address (`oam = &g_02146A80->oam[k]; oam->f.attr01 = ..; oam->f.attr2 = ..;`), not member accesses on an indexed base. Filed src/matched/func_0204E914.c, packet pkt_0204E914.
- palanm 0x02021848 / 0x0202173C: 33 -> 33. Tried 12 spellings: struct parameter, local struct, local array, address-taken local, float, register, rebinding p and a, element pointer. Even a real address-taken local is scheduled as a load-delay filler, so this is not an aliasing order.
- mcss 0x02016C60: 61 -> 61 (record-pointer header rewrite 66, reversed and sorted declarations 195/176, element-pointer nibble stores 61).
- backup_system 0x02031FE0: 9 -> 9 (u16 CRC accumulator, extra live pointers, u16 size, named tbl[i], assign-in-expression 22). The function is ARM.
- g3d_util 0x02048744: 14 -> 14 (8 declaration, position and type variants).
- gf_standard 0x0203F0A8: 16 -> 16. The mag01 table is part of the heap state block, so the local-static lever cannot apply. The inline accessor measured 67 and the while loop 106.
- GetCharIndex1D 0x020681E4: 10 -> 10. The library body under 1.1p1 is 228 bytes (target 248), and the wave-11 source under 1.1p1 is 240. The ../2.0/sp2 pin stands.
- __ieee754_rem_pio2 0x02098B44: still DIFF. Split word stores through a temporary still merge to stm and add 8 bytes of frame (1764).

Every measurement is recorded in the matching docs/notes file under a wave 17 heading.

Files written: src/matched/func_0204E914.c; docs/idioms/an-element-pointer-reuses-the-dying-base-register-an-indexed-base-does-not.md; appended to docs/notes/func_0202173C, pkt_02016C60, pkt_02031FE0, pkt_02048330, func_0203F0A8, pkt_02067FE4, pkt_02098B44 and func_0204E914 (.c.txt).

Shards verified: pkt_0204E914 (first pass 1 rewritten, second 0 rewritten, EXACT).

Seeds: none new.

Integrator:
- Regenerate the idiom index (`idioms --check` reports it stale).
- The listing extent at 0x02021848 and 0x0202173C is still 2 bytes; the listings were not regenerated.
- tools/match.py was briefly unreadable during this run (null bytes, someone editing it) and then recovered. Check that edit.
- The permuter was not run this wave.
