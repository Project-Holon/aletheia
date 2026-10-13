/*
 * function: NNSi_SndArcLoadWaveArc
 * address:  0x02074E10
 * packet:   pkt_02074A34
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNS_SndArcGetWaveArcInfo  0x02074450  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   NNSi_SndArcLoadWaveArcFile  0x02075080  arm
 *   NNSi_SndArcLoadWaveArcTable  0x020750EC  arm
 *
 * The 0x02074BEC/0x02074C70 sibling for the third handler slot: resolve the
 * object (NNS_SndArcGetWaveArcInfo), read its 32-bit header word, and dispatch on the
 * caller's flag bits.  With flag bit 2 set the 24-bit low field of the header
 * is handed to one of two loaders chosen by header bit 24, and a zero result
 * is the error code 9; without it the field goes to the plain lookup
 * NNS_SndArcGetFileAddress and no error check applies (the image's `bl 0x207466c` at
 * 0x02074E84 lands at 0x02074E88, PAST the `cmp r0,#0` / `mov r0,#9`).
 *
 * TWO LEVERS, both required and both previously measured against the wrong
 * front end in docs/notes/pkt_02074CD0.c.txt / docs/notes/pkt_0207533C.c.txt:
 *
 *  - THE HEADER IS READ THROUGH TWO VIEWS OF ONE WORD, so it must be a UNION.
 *    The value is a 24-bit BITFIELD (`o->b.v`): that and only that emits the
 *    image's `lsl r0,r0,#8` / `lsr r0,r0,#8` pair straddling the branch at
 *    0x02074E44/0x02074E54, per
 *    docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md; spelling it
 *    `(w << 8) >> 8` folds to `bic r0, r0, #0xff000000`.  The FLAG is a plain
 *    word read `(o->w >> 24) & 1`, which is the image's `lsr r1,r0,#0x18` /
 *    `tst r1,#1` at 0x02074E3C; taking it from the same bitfield view as a
 *    1-bit member gives `lsl r1,r0,#7` / `lsrs r1,r1,#0x1f` instead (the two
 *    bytes that were still out before the union).  The union is what lets the
 *    two views share the single `ldr r0,[r0]` at 0x02074E34; two separate
 *    pointers cost the whole function, as the note records.
 *
 *  - PIN ../2.0/sp2, the "kept constants" tell of docs/FRONTEND-PINS.md, the
 *    same pin the rest of this cluster carries (NNS_SndArcLoadSeq, NNS_SndArcLoadWaveArc,
 *    NNS_SndArcLoadSeqEx, NNSi_SndArcLoadGroup).  The image computes the SECOND and THIRD
 *    call arguments separately inside EACH arm -- `mov r2, r4` / `lsr r0,r0,#8`
 *    at 0x02074E50/0x02074E54 and again at 0x02074E60/0x02074E64 -- and only
 *    the first argument's `mov r1, r5` is hoisted above the branch.  1.1p1
 *    -O4,p hoists all three and cross-jumps the two arms onto one call
 *    sequence, giving 132 bytes against the original's 140 with 67 concrete
 *    bytes out; no source spelling of the two arms moves it, which is what
 *    docs/notes/pkt_02074CD0.c.txt spent its pass measuring.  Under the pin
 *    the SAME C is 140 bytes, 0 mismatches.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_SndArcLoadWaveArc.c \
 *       --func NNSi_SndArcLoadWaveArc --addr 0x02074E10 --arm --cc ../2.0/sp2
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

union Hdr {
    unsigned w;
    struct { unsigned v : 24; unsigned flag : 1; unsigned rest : 7; } b;
};

extern void *NNS_SndArcGetWaveArcInfo(int index);
extern u32 NNS_SndArcGetFileAddress(u32 a);
extern u32 NNSi_SndArcLoadWaveArcFile(u32 a, u32 b, u32 c);
extern u32 NNSi_SndArcLoadWaveArcTable(u32 idx, u32 *heap, int flag);

u32 NNSi_SndArcLoadWaveArc(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    union Hdr *o;
    u32 r;

    o = NNS_SndArcGetWaveArcInfo(a);
    if (o == 0) return 5;
    if (b & 4) {
        if ((o->w >> 24) & 1) r = NNSi_SndArcLoadWaveArcTable(o->b.v, (u32 *)c, d);
        else                  r = NNSi_SndArcLoadWaveArcFile(o->b.v, c, d);
        if (r == 0) return 9;
    } else {
        r = NNS_SndArcGetFileAddress(o->b.v);
    }
    if (out != 0) *out = r;
    return 0;
}
