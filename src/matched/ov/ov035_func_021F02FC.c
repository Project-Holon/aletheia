/*
 * function: C_GEAR_POWER_ONOFF_OpenYesNoMenu
 * address:  0x021F02FC
 * packet:   pkt_ov035_021F02FC
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F0640    0x021F0640 data ov035 a4
 *   d_021F064C  0x021F064C  data
 *   d_021F064C  0x021F064C  data
 *   d_021F064C    0x021F064C data ov035 a4
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_OpenMenuFastDecide 0x0202784C thumb
 *   APP_TASKMENU_SetDisableKey 0x02027CD8 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj06146.h"

extern int d_021F0640[];
extern char d_021F064C[];
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int APP_TASKMENU_OpenMenuFastDecide(int a0, int a1);
extern int APP_TASKMENU_SetDisableKey(int a0, int a1);
extern void STRBUF_Delete(struct U16Vec *vec);

void C_GEAR_POWER_ONOFF_OpenYesNoMenu(char *p, int a1)
{
    int *d = d_021F0640;

    d[3] = a1;
    d[8] = (int)func_02045EC0((struct MsgBank *)(((struct Obj06146 *)p)->f38), 5);
    d[11] = (int)func_02045EC0((struct MsgBank *)(((struct Obj06146 *)p)->f38), 6);
    ((struct Obj06146 *)p)->f44 = APP_TASKMENU_OpenMenuFastDecide((int)d_021F064C, ((struct Obj06146 *)p)->f40);
    APP_TASKMENU_SetDisableKey(((struct Obj06146 *)p)->f44, 1);
    STRBUF_Delete((struct U16Vec *)d[8]);
    STRBUF_Delete((struct U16Vec *)d[11]);
}
