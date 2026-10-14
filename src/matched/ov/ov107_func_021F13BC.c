/*
 * unit: yes
 * function: MB_COMM_SYS_GetHeaderBuffer,MB_COMM_SYS_OnMonsReceived,MB_COMM_SYS_GetMonBuffer,MB_COMM_SYS_GetChildDataPtr,MB_COMM_SYS_GetMemberCount
 * address: 0x021F13BC
 * packet: pkt_ov107_021F13BC
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F6E28 0x021F6E28 data ov107 a1
 *   d_021F6EE8 0x021F6EE8 data a4
 */
#include "../include/Obj07995.h"
#include "../include/Obj22300.h"
#include "../include/Obj22301.h"
typedef unsigned short u16;
extern void *func_02030734(unsigned int,unsigned int,int,const char *,u16);
extern const char d_021F6E28[];
extern int d_021F6EE8[];
void *MB_COMM_SYS_GetHeaderBuffer(void *a,char *p)
{
    if(!((struct Obj07995 *)p)->f14) ((struct Obj07995 *)p)->f14=func_02030734(((struct Obj07995 *)p)->f0,8,1,d_021F6E28,862);
    return ((struct Obj07995 *)p)->f14;
}
void MB_COMM_SYS_OnMonsReceived(int a,int b,int c,char *p){((struct Obj22300 *)p)->f18|=2;}
void *MB_COMM_SYS_GetMonBuffer(int a,char *p){return ((struct Obj22301 *)p)->f10;}
int *MB_COMM_SYS_GetChildDataPtr(void){return d_021F6EE8;}
int MB_COMM_SYS_GetMemberCount(void){return 2;}
