/*
 * function: P_STA_SKILL_LoadArcGraphics
 * address: 0x021D9980
 * packet: pkt_ov131_021D9980
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02049EF4 0x02049EF4 arm
 *   P_STA_OAM_CreateManager 0x021DBA90 thumb ov131
 */
#include "../include/Obj00776.h"
#include "../include/Obj05395.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02049EF4(void *,u32,u32,void **,u16);
struct S;
extern struct S *P_STA_OAM_CreateManager(u32 a, u32 b);
void P_STA_SKILL_LoadArcGraphics(u8 *a,u8 *p,void *resource)
{
    ((struct Obj05395 *)p)->f38=func_02049EF4(resource,72,0,(void **)(p+0x34),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f40=func_02049EF4(resource,73,0,(void **)(p+0x3c),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f48=func_02049EF4(resource,74,0,(void **)(p+0x44),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f50=func_02049EF4(resource,75,0,(void **)(p+0x4c),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f58=func_02049EF4(resource,76,0,(void **)(p+0x54),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->fA4=P_STA_OAM_CreateManager(((struct Obj00776 *)a)->f0,(u32)(((struct Obj00776 *)a)->f174));
}
