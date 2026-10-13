/*
 * function: P_STA_SKILL_ShowMovesPage
 * address: 0x021DA7A4
 * packet: pkt_ov131_021DA7A4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA84A.
 * symbols:
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   P_STA_SKILL_ApplyMovesScreen 0x021D9EF0 thumb ov131
 *   P_STA_SKILL_ShowSlot 0x021DB964 thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   P_STATUS_SetInputEnable 0x021D5A9C thumb ov131
 *   P_STA_SKILL_SetCursor 0x021DB468 thumb ov131
 */
#include "../include/Obj00136.h"
#include "../include/Obj00536.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(unsigned);
extern void P_STA_SKILL_ApplyMovesScreen(u8 *,u8 *);
extern void P_STA_SKILL_ShowSlot(u8 *,void *,u8 *);
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void P_STATUS_SetInputEnable(char *p, int a);
extern void P_STA_SKILL_SetCursor(u8 *,u8 *,u8,int);
void P_STA_SKILL_ShowMovesPage(u8 *a,u8 *b) {
    u8 i;
    func_020410D0(2,0,0,32,24,(u32)(*(u8 * *)&((struct Obj00536 *)b)->f34+12),0,0,32,32);
    func_02041B6C(2);
    P_STA_SKILL_ApplyMovesScreen(a,b);
    for(i=0;i<b[43];i++) P_STA_SKILL_ShowSlot(a,b,b+176+i*24);
    func_0204B878(((struct Obj00136 *)a)->f17C,4);
    if(b[43]==5) b[41]=4;else b[41]=0;
    P_STATUS_SetInputEnable((char *)a,0);
    P_STA_SKILL_SetCursor(a,b,b[41],0);
}
