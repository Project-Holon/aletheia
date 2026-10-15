/*
 * unit:     yes
 * function: NNSi_G2dSrtcInitTable
 * address:  0x020640B0
 * packet:   pkt_02063640
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The per-node SRT control block of the NNS G2D cell-animation module, and
 * the three setters the multi-cell node walk at NNSi_G2dSetMCDataToMCInstanceImpl drives.
 *
 * The block is 0x14 bytes:
 *   +0x00  u32  mode      (1 = SRT enabled; every setter below is a no-op
 *                          when it is anything else)
 *   +0x04  s32  scale x   (fx32)
 *   +0x08  s32  scale y   (fx32)
 *   +0x0C  s16  translate x
 *   +0x0E  s16  translate y
 *   +0x10  u16  rotation
 *   +0x12  u16  dirty flags: bit1 scale, bit2 rotation, bit3 translation
 *
 * This is the layer the `a/0/0/4` rig question lands on.  NNSi_G2dSetMCDataToMCInstanceImpl's
 * node loop ends with
 *
 *     slot = nodeStates + i * 0x28;
 *     slot->enabled = 1;
 *     NNS_G2dSetSRTTranslate(&slot->srt, (s16)node->x, (s16)node->y);
 *
 * i.e. the NMCR node's own signed (x, y) is written into the node's
 * translation verbatim.  There is no table indexed by species, form or
 * node id anywhere between the NMCR node record and this store, and no
 * second placement source: the only other writes to the same block are
 * the scale and rotation NNS_G2dSetAnimSequenceToMCAnimation pulls out of the node's NANR
 * frame record.
 *
 * NNSi_G2dSrtcInitTable fills three words with -1 (a "no cell bound" sentinel for
 * the three-slot table NNSi_G2dSrtcSetTable / NNSi_G2dSrtcGetTable index), which is the
 * same table, not a fourth placement lane.
 *
 * Only the three table leaves are in this file.  The three setters
 * themselves (NNS_G2dSetSRTTranslate translate, NNS_G2dSetSRTRotate rotate,
 * NNS_G2dSetSRTScale scale) are byte-correct except that the original never
 * predicates the guarded block and every C spelling tried does; that near
 * miss and its evidence are in docs/notes/g2d_srt_setters.c.txt, and the
 * struct layout above is read off those three functions.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020640B0.c \
 *       --addr 0x020640B0 --arm
 */

typedef signed short   s16;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Srt {
    u32 mode;
    s32 scaleX;
    s32 scaleY;
    s16 tx;
    s16 ty;
    u16 rot;
    u16 dirty;
};

void NNSi_G2dSrtcInitTable(s32 *tbl)
{
    int i;

    for (i = 0; i < 3; i++) {
        tbl[i] = -1;
    }
}

void NNSi_G2dSrtcSetTable(s32 *tbl, u32 i, u32 v)
{
    tbl[i] = v;
}

s32 NNSi_G2dSrtcGetTable(const s32 *tbl, u32 i)
{
    return tbl[i];
}
