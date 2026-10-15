/*
 * function: SHINKA_DEMO_VIEW_DeleteWork
 * address: 0x022065C8
 * packet: pkt_ov195_022065C8
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   SHINKA_DEMO_VIEW_FreeQuad 0x02208514 thumb ov195
 *   SHINKA_DEMO_VIEW_DeleteGrid 0x02206A3C thumb ov195
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02911.h"
#include "../include/Obj10824.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern unsigned int G3D_CAMERA_Delete(void *ptr);
extern void SHINKA_DEMO_VIEW_FreeQuad(void *,int);
extern void SHINKA_DEMO_VIEW_DeleteGrid(char *,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void SHINKA_DEMO_VIEW_DeleteWork(char *p){char *q;u8 i;q=*(char * *)&((struct Obj02911 *)p)->f58;G3D_CAMERA_Delete((void *)(((struct Obj10824 *)q)->f4));if(((struct Obj10824 *)q)->f10)SHINKA_DEMO_VIEW_FreeQuad(((struct Obj10824 *)q)->f10,((struct Obj02911 *)p)->f0);for(i=0;i<2;i++){if(*(char **)(q+i*4+8))SHINKA_DEMO_VIEW_DeleteGrid(*(char **)(q+i*4+8),((struct Obj02911 *)p)->f0);}func_020307B0(q);}
