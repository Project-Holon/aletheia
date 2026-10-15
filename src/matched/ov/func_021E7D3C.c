/*
 * function: BOX2_SEQ_StateExitToField
 * address:  0x021E7D3C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_PrintWordsetBB64  0x021EBB64  thumb  ov170
 *   BOX2_SEQ_ReturnAfterClear  0x021E8F50  thumb  ov170
 *
 * candidate BOX2_SEQ_StateExitToField: state machine step
 */
#include "../include/Obj00000.h"


extern void BOX2_SEQ_PrintWordsetBB64(unsigned char *p, unsigned v, int i);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
void BOX2_SEQ_StateExitToField(char *p)
{
    int v;
    BOX2_SEQ_PrintWordsetBB64((unsigned char *)((int)p), ((struct Obj00000 *)p)->f10, 0x18);
    v = *(int *)(*(int *)&((struct Obj00000 *)p)->f0 + 0x24);
    if (v == 3)
        ((struct Obj00000 *)p)->f28 = 0x3c;
    else
        ((struct Obj00000 *)p)->f28 = 0xe;
    BOX2_SEQ_ReturnAfterClear((char *)((int)p), 6);
}

