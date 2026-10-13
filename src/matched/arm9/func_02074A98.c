/*
 * function: NNS_SndArcLoadWaveArc
 * address:  0x02074A98
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_SndArcLoadWaveArc  0x02074E10  arm
 *
 * Sibling of NNS_SndArcLoadSeq: the identical wrapper over the other byte-stream
 * reader in the same unit.
 *
 * PER-FILE PIN (../2.0/sp2), same byte evidence and same tell as
 * NNS_SndArcLoadSeq (docs/FRONTEND-PINS.md, "kept constants"): the image
 * materialises 0xff / 1 / 0 at the call and the boolean from immediates
 * (44 bytes), `dsi/1.1p1` keeps 1 and 0 live in callee-saved r4/r5 and needs
 * 48 bytes (35 differing), `../2.0/sp2` reproduces the image exactly.
 * Needs a row in docs/FRONTEND-PINS.md; that file is outside this lane's
 * write set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_SndArcLoadWaveArc.c \
 *       --func NNS_SndArcLoadWaveArc --addr 0x02074A98 --arm --cc ../2.0/sp2
 */

typedef unsigned int u32;

extern u32 NNSi_SndArcLoadWaveArc(u32 a, u32 b, u32 c, u32 d, u32 *out);

u32 NNS_SndArcLoadWaveArc(u32 a, u32 b)
{
    return NNSi_SndArcLoadWaveArc(a, 0xff, b, 1, 0) == 0;
}
