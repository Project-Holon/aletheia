/*
 * function: MONOLITH_TOOL_SUMMARY_Destroy
 * address: 0x021B8618
 * packet: pkt_ov071_021B8618
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   func_020315D4 0x020315D4 arm
 *   MONOLITH_TOOL_SUMMARY_DeleteWindows 0x021B8750 thumb ov071
 *   MONOLITH_TOOL_SUMMARY_FreeBackgrounds 0x021B869C thumb ov071
 *   MONOLITH_TOOL_SUMMARY_FreeLabel 0x021B878C thumb ov071
 */
#include "../include/Obj20733.h"
#include "../include/Obj20734.h"

typedef unsigned int   u32;
struct PrintSys;
struct Proc;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BG_SYS_SetMainVisiblePlanes(unsigned int);
extern void func_020315D4(struct Proc *p);
extern void MONOLITH_TOOL_SUMMARY_DeleteWindows(void **);
extern void MONOLITH_TOOL_SUMMARY_FreeBackgrounds(void);
extern void MONOLITH_TOOL_SUMMARY_FreeLabel(void *);
int MONOLITH_TOOL_SUMMARY_Destroy(void *a, void *b, char *c, void **d)
{
    if (PRINTSYS_QUE_IsFinished(((struct Obj20734 *)(*(char * *)&((struct Obj20733 *)c)->f4))->f8) == 0) return 0;
    BG_SYS_SetMainVisiblePlanes(8);
    MONOLITH_TOOL_SUMMARY_DeleteWindows(d);
    MONOLITH_TOOL_SUMMARY_FreeBackgrounds();
    MONOLITH_TOOL_SUMMARY_FreeLabel(d);
    func_020315D4(a);
    return 1;
}
