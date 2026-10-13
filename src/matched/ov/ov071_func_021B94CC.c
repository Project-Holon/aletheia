/*
 * function: MONOLITH_TOOL_LIST_Exit
 * address:  0x021B94CC
 * packet:   pkt_ov071_021B94CC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MONOLITH_TOOL_LIST_FreeEntryBitmaps  0x021B9A18  thumb  ov071
 *   func_021B71FC  0x021B71FC  thumb  ov071
 *   func_021B718C  0x021B718C  thumb  ov071
 *   MONOLITH_TOOL_DeleteBackButton  0x021B9BA0  thumb  ov071
 *   MONOLITH_TOOL_DeleteRowGrids  0x021B9B3C  thumb  ov071
 *   MONOLITH_TOOL_DeleteMarker  0x021B9BC8  thumb  ov071
 *   MONOLITH_TOOL_DeleteScrollArrows  0x021B9C1C  thumb  ov071
 *   MONOLITH_TOOL_LIST_FreeBgChar  0x021B9694  thumb  ov071
 *   MONOLITH_TOOL_LIST_FreeWindows  0x021B9734  thumb  ov071
 *   MONOLITH_TOOL_LIST_FreeBackgrounds  0x021B95CC  thumb  ov071
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_020315D4  0x020315D4  arm
 */
#include "../include/Obj03177.h"
#include "../include/Obj20746.h"
#include "../include/Obj20747.h"

typedef unsigned int u32;

struct Node;
struct PrintSys;
struct Rec;
struct Rec3;
struct S020315D4;
struct U16Vec;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 a);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void MONOLITH_TOOL_LIST_FreeEntryBitmaps(char *p);
extern void func_021B71FC(void *a);
extern void func_021B718C(void *a);
extern void MONOLITH_TOOL_DeleteBackButton(void *a);
extern void MONOLITH_TOOL_DeleteRowGrids(char *p);
extern void MONOLITH_TOOL_DeleteMarker(char *p);
extern void MONOLITH_TOOL_DeleteScrollArrows(char *p);
extern void MONOLITH_TOOL_LIST_FreeBgChar(unsigned int *p);
extern void MONOLITH_TOOL_LIST_FreeWindows(char *p);
extern void MONOLITH_TOOL_LIST_FreeBackgrounds(void);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_020315D4(struct S020315D4 *p);

int MONOLITH_TOOL_LIST_Exit(void *a, void *b, char *c, char *d)
{
    if (PRINTSYS_QUE_IsFinished(((struct Obj20747 *)(*(char * *)&((struct Obj20746 *)c)->f4))->f8) == 0)
        return 0;
    BG_SYS_SetSubVisiblePlanes(8);
    func_02030EAC(((struct Obj03177 *)d)->f0);
    if (((struct Obj03177 *)d)->f294 != 0)
        PRINTSYS_PrintStreamDelete(((struct Obj03177 *)d)->f294);
    if (((struct Obj03177 *)d)->f290 != 0)
        STRBUF_Delete(((struct Obj03177 *)d)->f290);
    MONOLITH_TOOL_LIST_FreeEntryBitmaps(d);
    if (((struct Obj03177 *)d)->f310 != 0)
        func_021B71FC(((struct Obj03177 *)d)->f310);
    func_021B718C(((struct Obj03177 *)d)->f30C);
    MONOLITH_TOOL_DeleteBackButton(d);
    MONOLITH_TOOL_DeleteRowGrids(d);
    MONOLITH_TOOL_DeleteMarker(d);
    MONOLITH_TOOL_DeleteScrollArrows(d);
    MONOLITH_TOOL_LIST_FreeBgChar((unsigned int *)d);
    MONOLITH_TOOL_LIST_FreeWindows(d);
    MONOLITH_TOOL_LIST_FreeBackgrounds();
    MSGDATA_Delete(((struct Obj03177 *)d)->f20);
    func_020315D4(a);
    return 1;
}
