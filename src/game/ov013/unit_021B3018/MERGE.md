# unit_021B3018 (ov013)

5 parts (from 3 plus 6 folder members). Left: d_021B3C50, d_021B4C48, d_021B60CC declared two ways; G.h include path cannot be opened in merged output (header name demangling in the merge tool); p02+p03 give code DIFF.

Round 3 (r3_ov04): p02|p03 is a 460-byte uncovered block 0x021B3084..0x021B3250 (unmatched functions).

Round 4 (r4_ov05): p02|p03 stays: 0x021B3084..0x021B3250 is 460 bytes of unmatched functions (the merge also stops on a VadCfg struct passed as void *). Other boundaries: p01|p02 not a struct/union errors (lines 53, 54); p03|p04 struct G_021B4C48 indexed like an array; p04|p05 struct G_021B60CC indexed like an array.
