# unit_0272E9E8.c (twl)

Parts: p01 0272E9E8, p02 0272EBDC, p03 0272F804, p04 0272FB10, p05 0272FD40.

An empty `asm void f(void) {}` stand-in lays out 0 bytes, so the status of its file says EXACT or EXACT* without any code being compared. Merging a part that holds such a stand-in with the next part moves the next part's code and the merged TU is DIFF. The boundary stays until the stand-in is written as real C (or asm with a body) that lays out the original bytes.

Empty stand-ins (address, bytes):
- p01: func_0272EA04 (112), func_0272EA74 (452)
- p02: func_0272EC38 (276), func_0272ED4C (224), func_0272EE2C (108), func_0272EE98 (280), func_0272EFB0 (268), func_0272F0BC (684), func_0272F368 (520), func_0272F570 (464), func_0272F740 (360)
- p03: func_0272F8A8 (284), func_0272F9C4 (1168)
- p05: func_0272FE54 (160), func_0272FEF4 (212), func_0272FFC8 (200)

Other blockers found when the stand-ins are ignored (fix with the stand-ins):
- p01|p02: func_0272F740 is called with one argument (void *) but defined with none.
- p03|p04: func_0272F8A8 is called with nine arguments but defined with none.
- p04|p05: func_02087988 and func_0208799C prototypes differ, and data_02732EFC is declared as a struct in p04 and as an array in p05.

