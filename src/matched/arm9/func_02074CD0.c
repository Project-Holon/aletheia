/*
 * function: NNSi_SndArcLoadBank
 * address:  0x02074CD0
 * packet:   pkt_02074A34
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNS_SndArcGetBankInfo  0x020743EC  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   NNSi_SndArcLoadBankFile  0x02075014  arm
 *   NNS_SndArcGetWaveArcInfo  0x02074450  arm
 *   NNSi_SndArcLoadWaveArc  0x02074E10  arm
 *   NNSi_SndArcLoadBankWaves  0x02075404  arm
 *   SND_AssignWaveArc  0x0208A2BC  arm
 *
 * The third kind dispatcher: look up the group (error 4), load or look up its
 * bank (flag bit 2; error 8), then for each of the group's four halfword slots
 * that is not 0xffff resolve the entry (error 5), load its wave through
 * NNSi_SndArcLoadWaveArc (its own error code is returned as is), bind the sequence's
 * banks through NNSi_SndArcLoadBankWaves when header bit 24 and flag bit 4 are both set
 * (error 9), and finally assign the loaded wave archive to the bank slot.
 *
 * THE LAST LEVER (wave 12, from 2 bytes out): SND_AssignWaveArc takes THREE
 * arguments, not two.  Its own prologue saves r0, r1 AND r2 (`mov r4, r2` at
 * 0x0208A2C8), which is the SDK's SND_AssignWaveArc(bank, index, waveArc)
 * shape.  The image's `ldrne r2, [sp, #4]` at 0x02074DD0 was never a
 * scratch register choice: it loads `sub` straight into the third argument
 * register for the call, and the `cmpne r2, #0` guard reads it from there.
 * Every other lever (the union header, one-argument NNS_SndArcGetWaveArcInfo, the
 * NNSi_SndArcLoadWaveArc result returned as is, the int counter, the ../2.0/sp2 pin)
 * is documented in docs/notes/pkt_02074CD0.c.txt.
 *
 * With the three-argument callee the body is byte-exact under the project
 * default dsi/1.1p1 AND under ../2.0/sp2 / ../2.0/sp2p2 (all three checked),
 * so no front-end pin is recorded: the two-argument prototype was what made
 * 1.1p1 look wrong in the earlier notes.
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct { u32 f0; u16 slot[4]; } Grp;

union Hdr {
    unsigned w;
    struct { unsigned v : 24; unsigned flag : 1; unsigned rest : 7; } b;
};

extern void *NNS_SndArcGetBankInfo(int index);
extern u32   NNS_SndArcGetFileAddress(u32 a);
extern u32   NNSi_SndArcLoadBankFile(u32 a, u32 b, u32 c);
extern void *NNS_SndArcGetWaveArcInfo(int index);
extern u32   NNSi_SndArcLoadWaveArc(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern u32   NNSi_SndArcLoadBankWaves(u32 a, u32 b, u32 c, u32 d, u32 *heap);
extern void  SND_AssignWaveArc(u32 bank, u32 i, u32 waveArc);

u32 NNSi_SndArcLoadBank(u32 a, u32 flags, u32 c, u32 d, u32 *out)
{
    Grp *g;
    union Hdr *o;
    u32 bank;
    int i;
    u32 want;
    u32 sub;
    u32 r;

    g = NNS_SndArcGetBankInfo(a);
    if (g == 0) return 4;

    if (flags & 2) {
        bank = NNSi_SndArcLoadBankFile(g->f0, c, d);
        if (bank == 0) return 8;
    } else {
        bank = NNS_SndArcGetFileAddress(g->f0);
    }

    want = flags & 4;
    for (i = 0; i < 4; i++) {
        if (g->slot[i] != 0xffff) {
            o = NNS_SndArcGetWaveArcInfo(g->slot[i]);
            if (o == 0) return 5;
            r = NNSi_SndArcLoadWaveArc(g->slot[i], flags, c, d, &sub);
            if (r != 0) return r;
            if ((o->w >> 24) & 1 && want != 0) {
                if (NNSi_SndArcLoadBankWaves(sub, bank, (u32)i, o->b.v, (u32 *)c) == 0) return 9;
            }
            if (bank != 0 && sub != 0) {
                SND_AssignWaveArc(bank, (u32)i, sub);
            }
        }
    }
    if (out != 0) *out = bank;
    return 0;
}
