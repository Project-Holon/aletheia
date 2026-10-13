/*
 * file:     nns_g2d_srt_control_2.c
 * unit:     yes
 * function: NNSi_G2dSrtcInitControl, NNSi_G2dSrtcResetSrtData
 * address:  0x02064140
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

struct NNSG2dSRTControl {
    u32 mode;
    s32 scaleX;
    s32 scaleY;
    s16 transX;
    s16 transY;
    u16 rotZ;
    u16 dirtyFlags;
};

extern void func_02082A48(u32 data, void *dest, u32 size);
int NNSi_G2dSrtcResetSrtData(struct NNSG2dSRTControl *pSrtCtrl);


void NNSi_G2dSrtcInitControl(struct NNSG2dSRTControl *pSrtCtrl, u32 mode)
{
    pSrtCtrl->mode = mode;
    NNSi_G2dSrtcResetSrtData(pSrtCtrl);
}


int NNSi_G2dSrtcResetSrtData(struct NNSG2dSRTControl *pSrtCtrl)
{
    func_02082A48(0, &pSrtCtrl->scaleX, 0x18);
    pSrtCtrl->scaleX = 0x1000;
    pSrtCtrl->scaleY = 0x1000;
    return 0x1000;
}
