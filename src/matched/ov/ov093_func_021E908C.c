/*
 * function: func_021E908C
 * address:  0x021E908C
 * packet:   pkt_ov093_021E908C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCBL_Main  0x020310C4  arm
 *   func_021F78E4  0x021F78E4  thumb  ov094
 */
#include "../include/Obj21551.h"
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void func_021F78E4(void);

void func_021E908C(char *p)
{
    TCBL_Main(((struct Obj21551 *)p)->f178);
    func_021F78E4();
}
