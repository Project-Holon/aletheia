/*
 * function: NNSi_G3dAnmCalcNsBtp
 * address:  0x02070B64
 * packet:   pkt_0207010C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNSi_G3dTexPatAnmGetFrameValue  0x0206EA58  arm
 *   NNSi_G3dGetTexPatAnmTexNameByIdx  0x0206EA00  arm
 *   NNSi_G3dGetTexPatAnmPlttNameByIdx  0x0206EA2C  arm
 *   NNSi_G3dAnmSetTexParam  0x02070A24  arm
 *   NNSi_G3dAnmSetPlttParam  0x02070AFC  arm
 *
 * BYTE-CORRECT: 116 bytes, every concrete byte identical to the image.
 * Verdict MATCH* under `--cc ../2.0/sp2 --arm`.
 *
 * Blocked on evidence class `label`, on ALL FIVE PC24 sites at once: this
 * function is the ONLY branch anywhere in the image (arm9 and every overlay)
 * to each of NNSi_G3dTexPatAnmGetFrameValue, NNSi_G3dGetTexPatAnmTexNameByIdx, NNSi_G3dGetTexPatAnmPlttNameByIdx, NNSi_G3dAnmSetTexParam and
 * NNSi_G3dAnmSetPlttParam, so every witness for every site lies inside the compared
 * range and `label` refuses all five.  `--suggest-split` cannot help: there is
 * only one function here to cut, and the report would name each site as
 * having no outside witness at all.  It unblocks the moment any one of the
 * five callees reaches EXACT in a manifest, which then attests it `matched`
 * (NNSi_G3dAnmSetTexParam and NNSi_G3dAnmSetPlttParam are both in this packet and both still
 * open; NNSi_G3dAnmSetPlttParam has a note at docs/notes/NNSi_G3dAnmSetPlttParam.c.txt).
 *
 * The `*` is the unlabelled follower at 0x02070BD8, not a byte difference:
 * show --addr 0x02070B64 reports a 192-byte extent because the leaf at
 * 0x02070BD8 saves no lr and so carries no auto-label.  That follower is now
 * filed EXACT as src/matched/NNSi_G3dAnmObjInitNsBva.c; seeding 0x02070BD8 into
 * layout/function_starts.txt would drop the star.
 *
 * Two spelling notes that cost real time:
 *   - the two narrowings passed to NNSi_G3dTexPatAnmGetFrameValue are u32 shift pairs, NOT u16
 *     casts: `(t << 16) >> 16` and `(n->f0 << 4) >> 16` give the image's
 *     `lsl r1,#0x10 / lsl r2,r3,#4 / lsr r1,#0x10 / lsr r2,#0x10`, while
 *     declaring the parameters u16 and casting adds a second `lsl/lsr` pair on
 *     the second argument (+8 bytes).
 *   - `h` must be declared AFTER the pointer that receives the first call's
 *     result, which is what puts n in r6, h in r5 and the record in r4;
 *     declared first, n lands in r4 and h in r6 and every mov shifts.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *NNSi_G3dTexPatAnmGetFrameValue(u16 *p, u32 arg, u32 v);
struct NNSG3dResName;
struct NNSG3dResTexPatAnm;
extern const struct NNSG3dResName *NNSi_G3dGetTexPatAnmTexNameByIdx(const struct NNSG3dResTexPatAnm *pPatAnm, u8 texIdx);
extern const struct NNSG3dResName *NNSi_G3dGetTexPatAnmPlttNameByIdx(const struct NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx);
extern void  NNSi_G3dAnmSetTexParam(void *p, u32 v, void *ctx);
struct Dst70AFC;
struct Obj70AFC;
extern void NNSi_G3dAnmSetPlttParam(struct Obj70AFC *obj, void *name, struct Dst70AFC *dst);

struct N {
    u32   f0;
    u32   f4;
    void *f8;
    u32   fc;
    u32   f10;
    void *f14;
};

void NNSi_G3dAnmCalcNsBtp(void *ctx, struct N *n, u32 t)
{
    void *h;
    u8   *r;

    h = n->f8;
    r = (u8 *)NNSi_G3dTexPatAnmGetFrameValue(h, (t << 16) >> 16, (n->f0 << 4) >> 16);
    NNSi_G3dAnmSetTexParam(n->f14, (u32)NNSi_G3dGetTexPatAnmTexNameByIdx(h, r[2]), ctx);
    if (r[3] == 0xff)
        return;
    NNSi_G3dAnmSetPlttParam(n->f14, (void *)((u32)NNSi_G3dGetTexPatAnmPlttNameByIdx(h, r[3])), ctx);
}
