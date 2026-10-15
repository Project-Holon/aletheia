/*
 * function: MONOLITH_TOOL_SLOT_SELECT_Exit
 * address:  0x021B7824
 * packet:   pkt_ov071_021B7824
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MONOLITH_TOOL_DeleteCursor  0x021B7068  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_FreeCursor  0x021B7BE4  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_FreeButtons  0x021B7B9C  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons  0x021B7AAC  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow  0x021B7994  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds  0x021B78D4  thumb  ov071
 *   func_020315D4  0x020315D4  arm
 */
#include "../include/Obj06184.h"
#include "../include/Obj20691.h"
#include "../include/Obj20692.h"

typedef unsigned int u32;

struct PrintSys;
struct Rec3;
struct Proc;
struct U16Vec;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 a);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void MONOLITH_TOOL_DeleteCursor(void *a);
extern void MONOLITH_TOOL_SLOT_SELECT_FreeCursor(void *a);
extern void MONOLITH_TOOL_SLOT_SELECT_FreeButtons(char *p);
extern void MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons(void **p);
extern void MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow(void *a);
extern void MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds(void);
extern void func_020315D4(struct Proc *p);

int MONOLITH_TOOL_SLOT_SELECT_Exit(void *a, void *b, char *c, char *d)
{
    if (PRINTSYS_QUE_IsFinished(((struct Obj20692 *)(*(char * *)&((struct Obj20691 *)c)->f4))->f8) == 0)
        return 0;
    BG_SYS_SetSubVisiblePlanes(8);
    if (((struct Obj06184 *)d)->f8 != 0)
        PRINTSYS_PrintStreamDelete(((struct Obj06184 *)d)->f8);
    if (((struct Obj06184 *)d)->f4 != 0)
        STRBUF_Delete(((struct Obj06184 *)d)->f4);
    MONOLITH_TOOL_DeleteCursor(((struct Obj06184 *)d)->f7C);
    MONOLITH_TOOL_SLOT_SELECT_FreeCursor(d);
    MONOLITH_TOOL_SLOT_SELECT_FreeButtons(d);
    MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons((void **)d);
    MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow(d);
    MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds();
    func_020315D4(a);
    return 1;
}
