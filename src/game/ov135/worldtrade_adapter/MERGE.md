# worldtrade_adapter (ov135): 4 parts

w13b (2026-10-10): the canonical Work in worldtrade_types.h is applied to all four parts (each EXACT), so the
Work_vC8CC / Work_vCFD8 / Work_vD924 ... views no longer clash. Field names are canonical per offset
(type variants of one slot sit in anonymous unions). The pair merges were not tried yet; use
tools in scratchpad r14/w13b (loop.py, autofix.py) or go31.py. Old notes still apply for:
- p01 | p02: func_020185F0 arity (called with an argument in p02, declared with none in p01).
- p03 | p04: earlier merge compiled but was DIFF (callees from func_021FFB00 on 8 bytes late); locate the
  8-byte-longer function before that point.
