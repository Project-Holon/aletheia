/*
 * function: func_021DCF30
 * address:  0x021DCF30
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   STRBUF_Delete  0x02045808  arm  arm9
 *
 * lane O46
 */
#include "../include/Obj00000.h"


struct TaskMenuState;
struct U16Vec;
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021DCF30(char *p)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x19C)));
    STRBUF_Delete((struct U16Vec *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x190)));
    STRBUF_Delete((struct U16Vec *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x184)));
}
