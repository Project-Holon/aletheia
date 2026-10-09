# unit_021B824C (ov016)

Round 5 (lane s13): 2 files, all verified by tools/match.py.

- `unit_021B824C_p01.c`: AOSS_Recvfrom (compiler 1.1p1, flags -O4,p, isa thumb)
- `unit_021B824C_p02.c`: AOSS_Select, func_021B82B4 (compiler ../2.0/sp1p2, flags -O4,p, isa thumb)

Boundaries:
- `p01` | `p02`: real: AOSS_Recvfrom is DIFF under ../2.0/sp1p2 and AOSS_Select is DIFF under 1.1p1.
- Round 5: func_021B82B4 (old p03) builds EXACT under ../2.0/sp1p2 and was merged into p02.
