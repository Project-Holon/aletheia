/*
 * function: BOX2_SEQ_StateWaitPrint
 * address:  0x021E22B8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_StartWipeWhite  0x021E8F60  thumb  ov170
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb  arm9
 *
 * candidate BOX2_SEQ_StateWaitPrint: guard then dispatch
 */
#include "../include/Obj00000.h"


typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern int BOX2_SEQ_StartWipeWhite(void *p, int a);
int BOX2_SEQ_StateWaitPrint(int p)
{
    if (PRINTSYS_QUE_IsFinished((const struct PrintSys *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x8c))) == 0)
        return 0xc;
    BOX2_SEQ_StartWipeWhite((void *)p, *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA198));
}

