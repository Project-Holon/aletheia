# unit_021BA2F8 (ov016)

Round 5 (lane s13): 3 files, all verified by tools/match.py.

- `unit_021BA2F8_p01.c`: func_021BA2F8 .. func_021BA67C (compiler ../2.0/sp1p2, flags -O4,p -ipa file, isa thumb)
- `unit_021BA2F8_p02.c`: AutoConfigThreadEx (compiler ../2.0/sp1p2, flags -O4,p -ipa file, isa thumb)
- `unit_021BA2F8_p03.c`: AutoConfigThread .. SendNotify (compiler ../2.0/sp1p2, flags -O4,p, isa thumb)

Boundaries:
- `p01` | `p02`: blocker: p02 (AutoConfigThreadEx) uses the #include G_ATERMSET_*.h views and `struct ATERMSET_BSS g_021DCFD0` / `g_021DAB58` names; p01 uses atermset_bss. Needs one canonical ATERMSET_BSS/ATERMSET_DATA and one global name.
- `p02` | `p03`: real: p02 needs -ipa file, p03 (AutoConfigThread and later) is DIFF with it.
- Round 5: the 1.1p1 parts (old p04, p06, p08, p10) build EXACT under ../2.0/sp1p2 and merged with their neighbours into p03. The ATERMSET_BSS views of those parts were unified (apci_user_callback added).
