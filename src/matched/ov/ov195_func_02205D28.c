/*
 * function: SHINKA_DEMO_VIEW_Destroy
 * address: 0x02205D28
 * packet: pkt_ov195_02205D28
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   SHINKA_DEMO_VIEW_DeleteWork 0x022065C8 thumb ov195
 *   SHINKA_DEMO_VIEW_DeleteModels 0x0220623C thumb ov195
 *   SHINKA_DEMO_VIEW_ExitMcss 0x022060BC thumb ov195
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02911.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Owner Owner;
extern void SHINKA_DEMO_VIEW_DeleteWork(char *);
extern void SHINKA_DEMO_VIEW_DeleteModels(struct Owner *o);
extern void SHINKA_DEMO_VIEW_ExitMcss(char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void SHINKA_DEMO_VIEW_Destroy(char *p){SHINKA_DEMO_VIEW_DeleteWork(p);SHINKA_DEMO_VIEW_DeleteModels((Owner *)p);SHINKA_DEMO_VIEW_ExitMcss(p);if(((struct Obj02911 *)p)->f10)func_020307B0(((struct Obj02911 *)p)->f10);func_020307B0(p);}
