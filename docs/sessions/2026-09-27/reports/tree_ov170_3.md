# tree_ov170_3 report

## Seeds (layout/function_starts.txt, three lines)

- I added 0x02026124, 0x0202614C and 0x0202616C, then ran `disasm.py arm9 --split` and `worklist.py --refresh`.
- They are filed as one EXACT unit: src/matched/unit_02026124.c (pkt_02026124). What closed it: the bit clear is `& ((1 << b) ^ 0xFFFFFFFF)` and the bit set is a guarded `^=`.
- ARM9 is back to open 0 (100 percent).
- ov170 021DF484 and 021EA0BC were promoted to EXACT.

## Trees

| function | verdict | what closed it |
|---|---|---|
| ov119 021E049C (root) | MATCH | see "Seeds needed" below; closed by the GFL_STD_MemCopy inline wrapper and two extern `__FILE__` strings |
| ov119 021E0138, 021E01A0, 021E0410 | EXACT | first drafts |
| ov119 021E0200 | MATCH | blocked on 0x02012F14 |
| ov119 021DBE70 | EXACT | declarations separated from their initialisers (swept 536 of 720 declaration orders) |
| ov170 021E376C (root, 996 B) | EXACT | template 021E2650; `(int)r + 0x1E` stops a CSE |
| ov170 021E4A64 (900 B), 021E557C (860 B) | EXACT | template 021E376C |
| ov170 021E9EC0, 021E9F3C, 021E9FA8 | EXACT | nibble bitfield at +0x1C |
| ov170 021EE8A8, 021EEDE0, 021EE474, 021EA020 | EXACT | twin templates |

Every shard was verified twice, and the second pass rewrote nothing. `manifest --check` is clean.

## Files

- src/matched: unit_02026124.c, ov119_func_{021E0138,021E01A0,021E0410,021DBE70}.c, and ov170_func_{021DF484,021EA0BC,021E376C,021E4A64,021E557C,021E9EC0,021E9F3C,021E9FA8,021EE8A8,021EEDE0,021EE474,021EA020}.c.
- src/pending: ov119_func_021E049C.c, ov119_func_021E0200.c.
- New idioms:
  - an-inline-wrappers-arguments-are-evaluated-last-to-first
  - block-locals-declared-without-initialisers-colour-differently
- Note updated: docs/notes/pkt_ov119_021DBE70.c.txt.

## Seeds needed (integrator)

Both are unlabelled ARM9 Thumb tail-call thunks:
- 0x02009020: `movs r1,#0x14` then a tail call to func_02009074. Witness: bl at ov119 0x021E062E.
- 0x02012F14: `ldr r0,[r0]` then a tail call to func_02009EC8. Witnesses: bl at ov119 0x021E0226, 0x021E06D0, 0x021E080C.

Seeding both promotes 021E049C and 021E0200 to EXACT.

## Next lane (ov170)

- 021E6EC0: open callees 021EA598, 021EA66C, 021EEB40.
- 021E65E4: open callees 021EA39C, 021EA458, 021EA514. Probably the same menu family, so try 021E376C as the template.
- 021E0ABC and 021E1628: they share the open callees 021DDE80, 021E0FB0, 021EA878, 021ED108.
- 021EB378: no open callees.
