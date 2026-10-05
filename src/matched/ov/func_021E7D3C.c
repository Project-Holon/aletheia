/*
 * function: func_021E7D3C
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
 *   func_021EBB64  0x021EBB64  thumb  ov170
 *   func_021E8F50  0x021E8F50  thumb  ov170
 *
 * candidate func_021E7D3C: state machine step
 */
#include "../include/Obj00000.h"


extern void func_021EBB64(unsigned char *p, unsigned v, int i);
extern int func_021E8F50(char *p, int v);
void func_021E7D3C(char *p)
{
    int v;
    func_021EBB64((unsigned char *)((int)p), ((struct Obj00000 *)p)->f10, 0x18);
    v = *(int *)(*(int *)&((struct Obj00000 *)p)->f0 + 0x24);
    if (v == 3)
        ((struct Obj00000 *)p)->f28 = 0x3c;
    else
        ((struct Obj00000 *)p)->f28 = 0xe;
    func_021E8F50((char *)((int)p), 6);
}

