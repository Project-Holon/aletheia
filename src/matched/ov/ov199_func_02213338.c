/*
 * function: WIFIBATTLEMATCH_SYS_DestroySlotCommand
 * address: 0x02213338
 * packet: pkt_ov199_02213338
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   func_020307B0 0x020307B0 arm
 *   BTL_SETUP_ClearWithSlots 0x02013930 thumb
 *   func_02034A5C 0x02034A5C arm
 *   WIFIBATTLEMATCH_SYS_SetStep 0x02213808 thumb ov199
 *   ov093_id 0x0000005D data a1
 */
#include "../include/Obj01819.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
extern void GFL_USE_CancelChangeAndStopBgm(void);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void BTL_SETUP_ClearWithSlots(struct Obj *p);
extern void func_02034A5C(int handle);
extern const char ov093_id[];
extern void WIFIBATTLEMATCH_SYS_SetStep(char *, int);
int WIFIBATTLEMATCH_SYS_DestroySlotCommand(char *p, char *q)
{
    GFL_USE_CancelChangeAndStopBgm();
    func_020307B0(((struct Obj01819 *)q)->f34);
    BTL_SETUP_ClearWithSlots((struct Obj *)q);
    func_020307B0(q);
    func_02034A5C((int)ov093_id);
    WIFIBATTLEMATCH_SYS_SetStep(p, 0);
    return 1;
}
