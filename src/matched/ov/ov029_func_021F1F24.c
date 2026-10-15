/*
 * function: C_GEAR_FreeGraphics
 * address:  0x021F1F24
 * packet:   pkt_ov029_021F1F24
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   C_GEAR_DeleteActors  0x021F1E98  thumb  ov029
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   func_02040588  0x02040588  arm
 */
#include "../include/Obj07621.h"

struct Bank;
extern void BUTTON_MAN_Delete(void *p);
typedef unsigned int   u32;
extern void C_GEAR_DeleteActors(char *p);
extern void CLACT_DeleteRenderer(int);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);

void C_GEAR_FreeGraphics(char *p)
{
    if (((struct Obj07621 *)p)->f10)
        BUTTON_MAN_Delete((void *)(((struct Obj07621 *)p)->f10));
    C_GEAR_DeleteActors(p);
    CLACT_DeleteRenderer(((struct Obj07621 *)p)->f38);
    CLACT_DeleteUnit((struct Bank *)(((struct Obj07621 *)p)->f34));
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
}
