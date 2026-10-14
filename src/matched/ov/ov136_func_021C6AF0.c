/*
 * function: MB_SEQ_StateMessageWait
 * address: 0x021C6AF0
 * packet: pkt_ov136_021C6AF0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 */
#include "../include/Obj06529.h"
#include "../include/Obj23609.h"
#include "../include/Obj23610.h"
#include "../include/Obj23611.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
u32 MB_SEQ_StateMessageWait(u8 *p)
{
    if (PRINTSYS_PrintStreamGetState(((struct Obj23609 *)(*(u8 * *)&((struct Obj06529 *)p)->f8))->f1C8) == 2) {
        if ((*(u8 **)(p + 8))[0x1dd] == 0) {
            PRINTSYS_PrintStreamDelete(((struct Obj23610 *)(*(u8 * *)&((struct Obj06529 *)p)->f8))->f1C8);
            return ((struct Obj06529 *)p)->f28;
        }
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            PRINTSYS_PrintStreamDelete(((struct Obj23611 *)(*(u8 * *)&((struct Obj06529 *)p)->f8))->f1C8);
            GFL_USE_PlaySeDefaultVolume(1352);
            return ((struct Obj06529 *)p)->f28;
        }
    }
    return 3;
}
