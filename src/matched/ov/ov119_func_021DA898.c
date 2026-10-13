/*
 * function: func_021DA898
 * address: 0x021DA898
 * packet: pkt_ov119_021DA898
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DBA80 0x021DBA80 thumb ov119
 *   func_021DBAF8 0x021DBAF8 thumb ov119
 *   func_021DC370 0x021DC370 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
extern int func_021D8AA8(void *);
extern void func_021DBA80(char *p);
extern void func_021DBAF8(char *p);
extern void func_021DC370(char *p);
extern void func_021D8E84(void *,int);
typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
void func_021DA898(char *p) {
 if(func_021D8AA8(p)) {func_021DBA80(p);func_021DBAF8(p);func_021D8E84(p,(int)func_021DC370);}
 else {func_021DBA80(p);func_021DBAF8(p);}
 WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj00001 *)p)->f5F4);
 BG_SYS_SetMainVisiblePlanes(31);BG_SYS_SetSubVisiblePlanes(30);
}
