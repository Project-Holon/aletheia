/*
 * function: MONOLITH_TOOL_STATS_Destroy
 * address: 0x021B8A38
 * packet: pkt_ov071_021B8A38
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_020315D4 0x020315D4 arm
 *   MONOLITH_TOOL_STATS_FreeCursor 0x021B8ED0 thumb ov071
 *   MONOLITH_TOOL_STATS_DeleteWindows 0x021B8BF4 thumb ov071
 *   MONOLITH_TOOL_STATS_FreeBackgrounds 0x021B8ABC thumb ov071
 */
#include "../include/Obj20739.h"
#include "../include/Obj20740.h"

typedef unsigned int   u32;
struct PrintSys;
struct Proc;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BG_SYS_SetSubVisiblePlanes(unsigned int);
extern void func_020315D4(struct Proc *p);
extern void MONOLITH_TOOL_STATS_FreeCursor(void *);
extern void MONOLITH_TOOL_STATS_DeleteWindows(void **);
extern void MONOLITH_TOOL_STATS_FreeBackgrounds(void);
int MONOLITH_TOOL_STATS_Destroy(void *a, void *b, char *c, void **d)
{
    if (PRINTSYS_QUE_IsFinished(((struct Obj20740 *)(*(char * *)&((struct Obj20739 *)c)->f4))->f8) == 0) return 0;
    BG_SYS_SetSubVisiblePlanes(8);
    MONOLITH_TOOL_STATS_FreeCursor(d);
    MONOLITH_TOOL_STATS_DeleteWindows(d);
    MONOLITH_TOOL_STATS_FreeBackgrounds();
    func_020315D4(a);
    return 1;
}
