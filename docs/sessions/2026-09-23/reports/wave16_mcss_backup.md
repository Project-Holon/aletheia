# Wave 16, mcss.c / backup_system.c lane

EXACT 1 (220 bytes, 214 code), MATCH 0, DIFF 2 (notes appended with best-source markers).

- 0x020172D8 (mcss.c): 47 -> 0, EXACT. src/matched/func_020172D8.c. Lever: compound assignment on
  the read-modify-write, `a0[p] += 0x50;` / `a0[p] += 5;` in place of `a0[p] = (u8)(val + k)`. Same
  instructions, and the a0/k/b0 rotation goes. Flat before it: a third parameter, `a1 >>= 8`, function
  scope, enum n/v, an odd local. New idiom:
  docs/idioms/compound-assignment-on-a-loaded-byte-settles-a-register-rotation.md.
- 0x02016C60 (mcss.c): 61 -> 61. Enum type on each of 41 locals (best 61), second-pass locals at
  function scope in four positions (61/72/109/195), first-pass block scope (112), compound forms (61, or
  878 bytes), const record, f2c and task pointers (61), permuter through an 870-extent wrapper (hill
  800, anneal 1000 and 2000, --types): flat. sp2/sp2p2 878 bytes.
- 0x02031FE0 (backup_system.c, ARM): 9 -> 9. Levers not tried before, once each: const callee
  descriptors, cur/tbl, pa/pb (9); MI_CpuCopy16 / MI_CpuClear32 inlines and MATH_CalcCRC16CCITT
  table type (9); callee arity (all already right); else-first (not applicable); enum A/AB/i (9), B (40),
  k (1712 bytes); compound AB/pa (9, 10). Stopped. Treat as an allocation tie.

Seeds: none.
Shards verified: pkt_020172D8 (new, 1 entry EXACT), twice (0 rewritten on the second pass).
Files: src/matched/func_020172D8.c, layout/matched/arm9/pkt_020172D8.json, the idiom above, notes
pkt_020172D8.c.txt, pkt_02016C60.c.txt, pkt_02031FE0.c.txt (sections appended).
