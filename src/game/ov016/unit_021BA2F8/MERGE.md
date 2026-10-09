# unit_021BA2F8 (ov016)

Round 7 (lane s10): 2 files, all verified (EXACT).

- `unit_021BA2F8_p01.c`: func_021BA2F8 .. AutoConfigThreadEx (compiler ../2.0/sp1p2, flags -O4,p -ipa file, isa thumb). Old p01 and p02 merged: one ATERMSET_DATA view of g_021DAB58 (bDebug), one WS11G_PROFILE_DATA view of g_021DD224 (WEP keys inside EncryptData at +0x30).
- `unit_021BA2F8_p02.c`: AutoConfigThread .. SendNotify (compiler ../2.0/sp1p2, flags -O4,p, isa thumb)

Boundary p01 | p02: real: p01 needs -ipa file, p02 (AutoConfigThread and later) is DIFF with it.
