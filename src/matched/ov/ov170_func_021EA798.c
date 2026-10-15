/*
 * function: BOX2_SEQ_DrawListSlot
 * address:  0x021EA798
 * packet:   pkt_ov170_021EA798
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_IsWrappedDistance 0x021DD210 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_MAIN_GetBoxFormId 0x021DEDCC thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_IsSeqStep 0x021E0128 thumb
 *   BOX2_MAIN_IsSeqIdle 0x021E00C4 thumb
 */
#include "../include/Obj00000.h"

extern int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_SEQ_LoadMonIcon(char **p, int box);
extern int BOX2_MAIN_GetBoxFormId(char *p, int box);
extern void BOX2_MAIN_SetBoxScroll(char *p, void *a, int dir);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsSeqStep(char *p);
extern int BOX2_MAIN_IsSeqIdle(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_SEQ_DrawListSlot(unsigned char *p, int sel)
{
    int (*cb)(unsigned char *);
    int r = BOX2_MAIN_IsWrappedDistance(p, p[0x14], *(unsigned char *)(WORK(p) + 0xA17F));
    p[0x14] = *(unsigned char *)(WORK(p) + 0xA17F);
    BOX2_SEQ_LoadMonIcon((char **)p, p[0x14]);
    BOX2_MAIN_SetBoxScroll((char *)p, (void *)BOX2_MAIN_GetBoxFormId((char *)p, p[0x14]), r);
    if (r == 1)
        cb = (int (*)(unsigned char *))BOX2_MAIN_IsSeqStep;
    else
        cb = (int (*)(unsigned char *))BOX2_MAIN_IsSeqIdle;
    switch (sel) {
    case 0:
        ((struct Obj00000 *)p)->f28 = 0x15;
        break;
    case 1:
        ((struct Obj00000 *)p)->f28 = 0x63;
        break;
    }
    GFL_USE_PlaySeDefaultVolume(0x548);
    return BOX2_SEQ_SetSeqThird((char *)p, (int)cb, ((struct Obj00000 *)p)->f28);
}
