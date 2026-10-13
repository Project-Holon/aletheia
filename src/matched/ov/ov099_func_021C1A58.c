/*
 * function: WIFICLUB_OpenSlotPanel
 * address: 0x021C1A58
 * packet: pkt_ov099_021C1A58
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   d_021C377C 0x021C377C data a4
 *   WIFICLUB_OnSlotButtonEvent 0x021C1C9C thumb ov099
 *   func_0201EC64 0x0201EC64 thumb
 *   WIFICLUB_CreateSlotPanelWindows 0x021C1D1C thumb ov099
 *   WIFICLUB_EmptyHook 0x021C208C thumb ov099
 *   WIFICLUB_RedrawSlotPanels 0x021C2090 thumb ov099
 */
#include "../include/Obj10212.h"
typedef unsigned short u16;
extern void MI_CpuFill8(void *, int, int);
typedef unsigned int   u32;
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
typedef unsigned char  u8;
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern const int d_021C377C[];
extern void WIFICLUB_OnSlotButtonEvent(u32 a, int b, u32 p);
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern void WIFICLUB_CreateSlotPanelWindows(u8 *p, void *a, int heap);
extern void WIFICLUB_EmptyHook(char *);
extern void WIFICLUB_RedrawSlotPanels(char *);
void WIFICLUB_OpenSlotPanel(char *p, int a, int heap)
{
    MI_CpuFill8(p + 0x8b0, 0, 0xf4);
    BG_SYS_SetSubPlaneVisible(7, 1);
    BG_SYS_SetSubPlaneVisible(8, 0);
    ((struct Obj10212 *)p)->f8C8 = BUTTON_MAN_Create((u8 *)d_021C377C, (int)WIFICLUB_OnSlotButtonEvent, (int)p, heap);
    ((struct Obj10212 *)p)->f8B0 = func_0201EC64((u16)heap);
    WIFICLUB_CreateSlotPanelWindows((u8 *)p, (void *)a, heap);
    ((struct Obj10212 *)p)->f8F4 = 1;
    WIFICLUB_EmptyHook(p);
    WIFICLUB_RedrawSlotPanels(p);
}
