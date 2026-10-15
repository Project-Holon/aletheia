/*
 * function: CTVT_CALL_ExitDisplay
 * address:  0x021BD7D0
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Masks the display control word down to 0xffff1fff, hands the +0x1ac handle to
 * the two release probes and then drops priorities 7,6,5,4,1,0.
 *
 * symbols:
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   func_020403F4  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24105.h"

typedef unsigned int u32;

struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(u32 p);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);

void CTVT_CALL_ExitDisplay(void *a0)
{
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    CLACT_ExitSystem(CLACT_DeleteUnit((struct Bank *)(((struct Obj24105 *)a0)->f1AC)));
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(1);
    func_020403F4(0);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}
