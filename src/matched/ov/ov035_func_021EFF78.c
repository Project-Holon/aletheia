/*
 * function: C_GEAR_POWER_ONOFF_InitScreen
 * address:  0x021EFF78
 * packet:   pkt_ov035_021EFF78
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_InitScreen 0x021EFF78 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_02045B38 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   C_GEAR_POWER_ONOFF_InitBgs 0x021F000C thumb ov035
 *   C_GEAR_POWER_ONOFF_CreateTaskMenuRes 0x021F0140 thumb ov035
 *   C_GEAR_POWER_ONOFF_InitWindows 0x021F0168 thumb ov035
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   FIELD_SUBSCREEN_LoadBackdrop 0x021A12D4 thumb ov021
 */
#include "../include/Obj04315.h"

struct GfFont;
struct MsgBank;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, unsigned int heapId);
extern void GF_FONT_SetDefaultTextColor(void);
extern struct MsgBank *func_02045B38(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);
extern unsigned int PRINTSYS_QUE_Create(void *p);
typedef unsigned int   u32;
extern void C_GEAR_POWER_ONOFF_InitBgs(char *p, u32 heap);
extern void C_GEAR_POWER_ONOFF_CreateTaskMenuRes(void *, int);
extern void C_GEAR_POWER_ONOFF_InitWindows(int *p, int a1);
extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);
extern void FIELD_SUBSCREEN_LoadBackdrop(u32 *p, u32 x);

void C_GEAR_POWER_ONOFF_InitScreen(char *p, void *a1)
{
    *(int *)&((struct Obj04315 *)p)->f34 = (int)GF_FONT_Create(0x17, 0, 0, 0, (unsigned int)a1);
    GF_FONT_SetDefaultTextColor();
    ((struct Obj04315 *)p)->f38 = (int)func_02045B38(0, 2, 0x16, (unsigned int)a1);
    *(int *)&((struct Obj04315 *)p)->f3C = PRINTSYS_QUE_Create(a1);
    C_GEAR_POWER_ONOFF_InitBgs(p, (u32)a1);
    C_GEAR_POWER_ONOFF_CreateTaskMenuRes(p, (int)a1);
    C_GEAR_POWER_ONOFF_InitWindows((int *)p, (int)a1);
    GFL_NET_RefreshWmIconAtTopRight(0, (u32)a1);
    FIELD_SUBSCREEN_LoadBackdrop((u32 *)(((struct Obj04315 *)p)->fC), (int)a1);
}
