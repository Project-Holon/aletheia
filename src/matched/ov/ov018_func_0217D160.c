/*
 * function: INTRUDE_SUBDISP_Exit
 * address:  0x0217D160
 * packet:   pkt_ov018_0217D160
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOff  0x02037190  arm
 *   INTRUDE_SUBDISP_DeleteButtonBmpOam  0x0217DE44  thumb  ov018
 *   INTRUDE_SUBDISP_ClactActorDelete  0x0217DA90  thumb  ov018
 *   INTRUDE_SUBDISP_ClactResourceUnload  0x0217DA18  thumb  ov018
 *   INTRUDE_SUBDISP_BmpWinExit  0x0217D904  thumb  ov018
 *   INTRUDE_SUBDISP_BgExit  0x0217D870  thumb  ov018
 *   INTRUDE_SUBDISP_SystemExit  0x0217D6C8  thumb  ov018
 */
#include "../include/Obj00703.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct Node;
extern void func_02030EAC(struct Node *n);
extern void MIi_CpuClear16();
extern u32 func_020307B0(void *p);
extern void GFL_NET_WM_ICON_EasyObjWindowOff();
extern void INTRUDE_SUBDISP_DeleteButtonBmpOam(void **p);
extern void INTRUDE_SUBDISP_ClactActorDelete(void **p);
extern void INTRUDE_SUBDISP_ClactResourceUnload(u32 *p);
extern void INTRUDE_SUBDISP_BmpWinExit(char *p);
extern void INTRUDE_SUBDISP_BgExit();
extern void INTRUDE_SUBDISP_SystemExit(int *p);

void INTRUDE_SUBDISP_Exit(int a0)
{
    func_02030EAC((struct Node *)(((struct Obj00703 *)a0)->f34));
    MIi_CpuClear16(0, 0x05000400, 2);
    INTRUDE_SUBDISP_DeleteButtonBmpOam((void **)a0);
    INTRUDE_SUBDISP_ClactActorDelete((void **)a0);
    INTRUDE_SUBDISP_ClactResourceUnload((u32 *)a0);
    INTRUDE_SUBDISP_BmpWinExit((char *)a0);
    INTRUDE_SUBDISP_BgExit(a0);
    INTRUDE_SUBDISP_SystemExit((int *)a0);
    func_020307B0((void *)a0);
    GFL_NET_WM_ICON_EasyObjWindowOff();
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    *(volatile u16 *)0x04001050 = 0;
}
