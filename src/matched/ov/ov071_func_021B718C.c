/*
 * function: MONOLITH_TOOL_DeleteTaskMenuRes
 * address:  0x021B718C
 * packet:   pkt_ov071_021B718C
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to APP_TASKMENU_RES_Delete.
 *
 * symbols:
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 */

struct TaskMenuState;
typedef unsigned int   u32;
void MONOLITH_TOOL_DeleteTaskMenuRes(void *p)
{
    u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
    APP_TASKMENU_RES_Delete(p);
}
