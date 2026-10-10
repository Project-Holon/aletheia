# zukan_detail_graphic (ov208): 13 parts (was 14)

w11d (2026-10-10): old p07+p08 merged (greedy driver with the harmonizer, EXACT). Remaining boundaries, none proven real:
- p01|p02: func_021BD0AC is called with char * where the declaration takes unsigned int **.
- p02|p03: Ov208Mgr_021BD03C against Ov208Mgr_021BD404 (same object, two views); func_021BD404 and func_02082BCC prototypes.
- p03|p04: void * passed to an unsigned int parameter (func_0204AC18, func_0204A6C8).
- p04|p05, p05|p06: struct Ov208ActList and Ov208ActDesc_* views differ per part (needs one canonical struct).
- p06|p07: func_021BE9C8 is defined without parameters in one part and called with the manager in the other.
- p07|p08 (old 8|9), p08|p09, p09|p10: func_021BF63C, func_021BC3C0, func_021BDC48 prototypes (void * against int).
- p10|p11, p11|p12 (old 11|12, 12|13): func_0204B878 takes struct Obj * in one part and unsigned int in the other.
- p12|p13 (old 13|14): s16_/s32_ alias typedefs differ; func_0207D63C takes volatile void * against void *.
Next step: one canonical Ov208Mgr and Ov208Scene by offset (r209/canon195.py), then setproto.py for the shared externs.
