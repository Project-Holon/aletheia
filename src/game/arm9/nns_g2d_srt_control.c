/*
 * file:     nns_g2d_srt_control.c
 * unit:     yes
 * function: NNSi_G2dSrtcInitTable, NNSi_G2dSrtcSetTable, NNSi_G2dSrtcGetTable, NNS_G2dSetSRTTranslate, NNS_G2dSetSRTRotate, NNS_G2dSetSRTScale, NNSi_G2dSrtcInitControl, NNSi_G2dSrtcResetSrtData
 * address:  0x020640B0
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MIi_CpuClear16  0x02082A48  arm
 */
#include "nns_g2d_anim_types.h"


#include "mi_memory.h"
void NNSi_G2dSrtcInitTable(s32 *tbl);
void NNSi_G2dSrtcSetTable(s32 *tbl, u32 i, u32 v);
s32 NNSi_G2dSrtcGetTable(const s32 *tbl, u32 i);
void NNS_G2dSetSRTTranslate(SRTControl *obj, s16 x, s16 y);
void NNS_G2dSetSRTRotate(SRTControl *obj, u16 rotZ);
void NNS_G2dSetSRTScale(SRTControl *obj, u32 scaleX, u32 scaleY);
void NNSi_G2dSrtcInitControl(SRTControl *pSrtCtrl, u32 mode);
int NNSi_G2dSrtcResetSrtData(SRTControl *pSrtCtrl);

/*
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
 *   python tools/match.py tu --src src/matched/nns_g2d_srt_control_1.c \
 *       --addr 0x020640B0 --arm
 */
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

void NNS_G2dSetSRTTranslate(SRTControl *obj, s16 x, s16 y)
{
    if (obj->mode != 1) return;
    obj->dirtyFlags |= 8;
    obj->transX = x;
    obj->transY = y;
}

void NNS_G2dSetSRTRotate(SRTControl *obj, u16 rotZ)
{
    if (obj->mode != 1) return;
    obj->dirtyFlags |= 4;
    obj->rotZ = rotZ;
}

void NNS_G2dSetSRTScale(SRTControl *obj, u32 scaleX, u32 scaleY)
{
    if (obj->mode != 1) return;
    obj->dirtyFlags |= 2;
    obj->scaleX = scaleX;
    obj->scaleY = scaleY;
}

void NNSi_G2dSrtcInitControl(SRTControl *pSrtCtrl, u32 mode)
{
    pSrtCtrl->mode = mode;
    NNSi_G2dSrtcResetSrtData(pSrtCtrl);
}

int NNSi_G2dSrtcResetSrtData(SRTControl *pSrtCtrl)
{
    MIi_CpuClear16(0, &pSrtCtrl->scaleX, 0x18);
    pSrtCtrl->scaleX = 0x1000;
    pSrtCtrl->scaleY = 0x1000;
    return 0x1000;
}
