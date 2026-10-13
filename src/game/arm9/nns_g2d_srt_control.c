/*
 * file:     nns_g2d_srt_control.c
 * unit:     yes
 * function: func_020640B0, func_020640DC, func_02064100, func_02064120, NNSi_G2dSrtcInitControl, NNSi_G2dSrtcResetSrtData
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

typedef struct {
    u32 state;
    u32 arg1;
    u32 arg2;
    u16 field0c;
    u16 field0e;
    u16 field10;
    u16 flags;
} Obj020640DC;

struct NNSG2dSRTControl {
    u32 mode;
    s32 scaleX;
    s32 scaleY;
    s16 transX;
    s16 transY;
    u16 rotZ;
    u16 dirtyFlags;
};

extern void MIi_CpuClear16(u32 data, void *dest, u32 size);
void func_020640B0(s32 *tbl);
void func_020640CC(s32 *tbl, u32 i, u32 v);
s32 func_020640D4(const s32 *tbl, u32 i);
void func_020640DC(Obj020640DC *obj, u16 a, u16 b);
void func_02064100(Obj020640DC *obj, u16 val);
void func_02064120(Obj020640DC *obj, u32 a1, u32 a2);
void NNSi_G2dSrtcInitControl(struct NNSG2dSRTControl *pSrtCtrl, u32 mode);
int NNSi_G2dSrtcResetSrtData(struct NNSG2dSRTControl *pSrtCtrl);



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
 *     func_020640DC(&slot->srt, (s16)node->x, (s16)node->y);
 *
 * i.e. the NMCR node's own signed (x, y) is written into the node's
 * translation verbatim.  There is no table indexed by species, form or
 * node id anywhere between the NMCR node record and this store, and no
 * second placement source: the only other writes to the same block are
 * the scale and rotation NNS_G2dSetAnimSequenceToMCAnimation pulls out of the node's NANR
 * frame record.
 *
 * func_020640B0 fills three words with -1 (a "no cell bound" sentinel for
 * the three-slot table func_020640CC / func_020640D4 index), which is the
 * same table, not a fourth placement lane.
 *
 * Only the three table leaves are in this file.  The three setters
 * themselves (func_020640DC translate, func_02064100 rotate,
 * func_02064120 scale) are byte-correct except that the original never
 * predicates the guarded block and every C spelling tried does; that near
 * miss and its evidence are in docs/notes/g2d_srt_setters.c.txt, and the
 * struct layout above is read off those three functions.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/nns_g2d_srt_control_1.c \
 *       --addr 0x020640B0 --arm
 */
void func_020640B0(s32 *tbl)
{
    int i;

    for (i = 0; i < 3; i++) {
        tbl[i] = -1;
    }
}



void func_020640CC(s32 *tbl, u32 i, u32 v)
{
    tbl[i] = v;
}



s32 func_020640D4(const s32 *tbl, u32 i)
{
    return tbl[i];
}



void func_020640DC(Obj020640DC *obj, u16 a, u16 b)
{
    if (obj->state != 1) return;
    obj->flags |= 8;
    obj->field0c = a;
    obj->field0e = b;
}



void func_02064100(Obj020640DC *obj, u16 val)
{
    if (obj->state != 1) return;
    obj->flags |= 4;
    obj->field10 = val;
}



void func_02064120(Obj020640DC *obj, u32 a1, u32 a2)
{
    if (obj->state != 1) return;
    obj->flags |= 2;
    obj->arg1 = a1;
    obj->arg2 = a2;
}



void NNSi_G2dSrtcInitControl(struct NNSG2dSRTControl *pSrtCtrl, u32 mode)
{
    pSrtCtrl->mode = mode;
    NNSi_G2dSrtcResetSrtData(pSrtCtrl);
}



int NNSi_G2dSrtcResetSrtData(struct NNSG2dSRTControl *pSrtCtrl)
{
    MIi_CpuClear16(0, &pSrtCtrl->scaleX, 0x18);
    pSrtCtrl->scaleX = 0x1000;
    pSrtCtrl->scaleY = 0x1000;
    return 0x1000;
}
