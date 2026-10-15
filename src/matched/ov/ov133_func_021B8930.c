/*
 * function: DUP_FITTING_SelectFrame
 * address: 0x021B8930
 * packet: pkt_ov133_021B8930
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Assign mode = 8 after the sort call; the compiler hoists its saved-register assignment between the r0 and r1 argument setups.
 * checks: 1 8BB4/9D54/765C arities verified; 2 matched/pending ov133 callers agree; 3 unsigned-long phase and long mode both DIFF4; 4 early-return/assignment-argument/volatile idioms tested; 5 fresh idiom listing and neighbours reread, stack pair already matches; permuter 300 baseline DIFF4 unchanged; next lever would be inline wrapper argument binding.
 * volatile: 0x021B89AC stores A4; 0x021B89B0 rereads that word for DUP_FITTING_SetTextHelp.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   DUP_FITTING_FindNearestFrame 0x021B8BB4 thumb ov133
 *   MUSICAL_MCSS_GetIndex 0x021F50F4 thumb ov112
 *   DUP_FITTING_SortFrames 0x021B9028 thumb ov133
 *   DUP_FITTING_SetTextHelp 0x021B9D54 thumb ov133
 *   DUP_FITTING_SetModelTransform 0x021B765C thumb ov133
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int DUP_FITTING_FindNearestFrame(u8 *, void *, const int *, u16 *);
extern int MUSICAL_MCSS_GetIndex(unsigned);
extern void DUP_FITTING_SortFrames(u8 *, int, u16);
extern void DUP_FITTING_SetTextHelp(u8 *, int);
extern void *DUP_FITTING_SetModelTransform(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int DUP_FITTING_SelectFrame(u8 *p)
{
    int pos[2];
    u16 limit = 16;
    u16 start;
    u32 phase;
    int mode = 0;
    int index;
    phase = ((struct Obj00004 *)p)->f1834 + 0x19249;
    if (phase >= ((struct Obj00004 *)p)->fA8 * 4681u)
        start = (phase - ((struct Obj00004 *)p)->fA8 * 4681u) / 4681u;
    else start = phase / 4681u;
    pos[0] = ((struct Obj00004 *)p)->f1C - 128;
    pos[1] = *(int *)&((struct Obj00004 *)p)->f20 - 112;
    index = DUP_FITTING_FindNearestFrame(p, 0, pos, &limit);
    if (index != 10) {
    mode = MUSICAL_MCSS_GetIndex(index);
    if (mode == 7) mode = 6;
    if (mode == ((struct Obj00004 *)p)->fA4) {
        DUP_FITTING_SortFrames(p, 8, start);
        mode = 8;
    } else DUP_FITTING_SortFrames(p, mode, start);
    ((struct Obj00004 *)p)->fA4 = mode;
    DUP_FITTING_SetTextHelp(p, *(volatile int *)&((struct Obj00004 *)p)->fA4);
    ((struct Obj00004 *)p)->f98 = 1;
    *(int *)&((struct Obj00004 *)p)->f9C = 0;
    ((struct Obj00004 *)p)->fA0 = ((struct Obj00004 *)p)->f182C % 4681 + 65536;
    if (((struct Obj00004 *)p)->fA0 >= 65536 && ((struct Obj00004 *)p)->fA0 <= 65538)
        ((struct Obj00004 *)p)->fA0 += 4681;
    DUP_FITTING_SetModelTransform(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    GFL_USE_PlaySeDefaultVolume(1576);
    return 1;
    }
    return mode;
}
