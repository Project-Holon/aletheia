/*
 * function: MONOLITH_TOOL_TITLE_Exit
 * address: 0x021B7D34
 * packet: pkt_ov071_021B7D34
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   MONOLITH_TOOL_TITLE_FreeSlotIcons 0x021B7E24 thumb ov071
 *   MONOLITH_TOOL_FreeLabel 0x021B6EEC thumb ov071
 *   MONOLITH_TOOL_TITLE_FreeBackgrounds 0x021B7D98 thumb ov071
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj20709.h"
#include "../include/Obj20710.h"

typedef unsigned int   u32;
struct PrintSys;
struct Proc;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BG_SYS_SetMainVisiblePlanes(unsigned);
extern void MONOLITH_TOOL_TITLE_FreeSlotIcons(void **);
extern void MONOLITH_TOOL_FreeLabel(void **p);
extern void MONOLITH_TOOL_TITLE_FreeBackgrounds(void);
extern void func_020315D4(struct Proc *p);
int MONOLITH_TOOL_TITLE_Exit(void *a,int b,char *c,void **d) { if(PRINTSYS_QUE_IsFinished(((struct Obj20710 *)(*(char * *)&((struct Obj20709 *)c)->f4))->f8)==0) return 0; BG_SYS_SetMainVisiblePlanes(8); MONOLITH_TOOL_TITLE_FreeSlotIcons(d); MONOLITH_TOOL_FreeLabel(d); MONOLITH_TOOL_TITLE_FreeBackgrounds(); func_020315D4(a); return 1; }
