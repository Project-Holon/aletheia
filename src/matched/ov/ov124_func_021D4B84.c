/*
 * function: CG_HELP_ProcExit
 * address: 0x021D4B84
 * packet: pkt_ov124_021D4B84
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CG_HELP_Teardown 0x021D4280 thumb ov124
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj00991.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S020315D4;
extern void CG_HELP_Teardown(char *);
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *);
extern void GFL_HEAP_DeleteChecked(u32);
int CG_HELP_ProcExit(struct S020315D4 *task,int b,int keep,char *p) {CG_HELP_Teardown(p);if(keep==0){func_020307B0(**(void ** *)&((struct Obj00991 *)p)->f4);func_020307B0(((struct Obj00991 *)p)->f4);}func_020315D4(task);GFL_HEAP_DeleteChecked(0x8a);return 1;}
