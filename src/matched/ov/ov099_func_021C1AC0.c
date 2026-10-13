/*
 * function: func_021C1AC0
 * address: 0x021C1AC0
 * packet: pkt_ov099_021C1AC0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1F74 0x021C1F74 thumb ov099
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   func_0201ED04 0x0201ED04 thumb
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
#include "../include/Obj00008.h"
extern int func_021C1A44(char *);
extern void func_021C1F74(char *);
extern void BUTTON_MAN_Delete(void *);
typedef unsigned int   u32;
struct WordSet;
extern u32 func_0201ED04(struct WordSet *p);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void func_021C1AC0(char *p)
{
    if (func_021C1A44(p)) {
        func_021C1F74(p);
        BUTTON_MAN_Delete(((struct Obj00008 *)p)->f8C8);
        ((struct Obj00008 *)p)->f8C8 = 0;
        func_0201ED04(((struct Obj00008 *)p)->f8B0);
        ((struct Obj00008 *)p)->f8B0 = 0;
        BG_SYS_SetSubPlaneVisible(1, 1);
        BG_SYS_SetSubPlaneVisible(14, 0);
    }
}
