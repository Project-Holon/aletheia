/*
 * file:     nns_g3d_anm_texpat_2.c
 * unit:     yes
 * function: NNSi_G3dTexPatAnmGetFrameValue, NNSi_G3dTexPatAnmGetTrackByIdx
 * address:  0x0206EA58
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

/* One texture/palette pattern animation track (NNSG3dResTexPatAnm data). */
typedef struct {
    u16 numFrameValue;
    u16 unused02;
    s16 ratioDataFrame;
    u16 ofsFrameValue;
} TexPatAnmTrack;

/* The pattern animation block: its dictionary starts at +12. */
typedef struct {
    u8  unused00[0x12];
    u16 ofsEntry;
} TexPatAnmBlock;

u16 *NNSi_G3dTexPatAnmGetFrameValue(u16 *pPatAnm, u32 trackIdx, u32 frame);
unsigned char *NNSi_G3dTexPatAnmGetTrackByIdx(void *pPatAnm, u32 trackIdx);

/*
 * NNSi_G3dTexPatAnmGetFrameValue shape. Bucket search in a texture pattern
 * animation track: the signed halfword at +4 of the track
 * NNSi_G3dTexPatAnmGetTrackByIdx returns scales the key, the result is a fixed-point index, and
 * the two walks that follow step it down over entries >= v and then up over
 * entries <= v, returning the entry address.
 *
 * The entry stride is four *bytes* and is spelled through a byte pointer, and
 * the two walks are one `while` each: the emitted shape is the rotated form
 * the compiler produces for a conjunction whose second term loads.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G3dTexPatAnmGetFrameValue.c \
 *       --func NNSi_G3dTexPatAnmGetFrameValue --addr 0x0206EA58 --cc 1.1p1 --arm
 */
u16 *NNSi_G3dTexPatAnmGetFrameValue(u16 *pPatAnm, u32 trackIdx, u32 frame)
{
    u8 *pTrack = NNSi_G3dTexPatAnmGetTrackByIdx(pPatAnm, trackIdx);
    s16 ratio = ((TexPatAnmTrack *)pTrack)->ratioDataFrame;
    u8 *pFrameValues = (u8 *)pPatAnm + ((TexPatAnmTrack *)pTrack)->ofsFrameValue;
    u32 valueIdx = (u32)(ratio * frame) >> 12;

    while (valueIdx != 0 && *(u16 *)(pFrameValues + valueIdx * 4) >= frame)
        valueIdx--;
    while (valueIdx + 1 < ((TexPatAnmTrack *)pTrack)->numFrameValue && *(u16 *)(pFrameValues + 4 + valueIdx * 4) <= frame)
        valueIdx++;
    return (u16 *)(pFrameValues + valueIdx * 4);
}


/*
 * The null test is on the *computed* pointer, not on `pPatAnm`: the original opens
 * with `adds r3, r0, #12` and branches on its zero flag.  The field reads for
 * the bound and the offset stay pPatAnm-relative (+13, +18) while the indexed
 * halfword goes through the computed base - that mix of spellings is what
 * reproduces the register use, not a local `q` for all three.
 *
 * The two guards must be `goto`s, not `return 0`s: as returns, mwccarm
 * predicates the body (see docs/idioms/a-factored-tail-lets-the-compiler-predicate-the-arms.md);
 * as gotos the original's `beq`/`bcs` branches survive.
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G3dTexPatAnmGetTrackByIdx.c \
 *       --func NNSi_G3dTexPatAnmGetTrackByIdx --addr 0x0206EACC --cc 1.1p1 --arm
 */
unsigned char *NNSi_G3dTexPatAnmGetTrackByIdx(void *pPatAnm, u32 trackIdx)
{
    unsigned char *pDict = (unsigned char *)pPatAnm + 12;
    u16 ofsEntry;
    u16 sizeUnit;

    if (pDict == 0)
        goto fail;
    if (trackIdx >= *((unsigned char *)pPatAnm + 13))
        goto fail;
    ofsEntry = ((TexPatAnmBlock *)pPatAnm)->ofsEntry;
    sizeUnit = *(u16 *)(pDict + ofsEntry);
    return pDict + ofsEntry + 4 + sizeUnit * trackIdx;
fail:
    return 0;
}
