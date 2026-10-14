/*
 * function: MB_PARENT_SYS_Register
 * address: 0x021F080C
 * packet: pkt_ov107_021F080C
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_PARENT_SYS_SetState 0x021F0D1C thumb ov107
 *   func_021F5E7C 0x021F5E7C arm ov107
 *   MB_PARENT_SYS_LoadFileImage 0x021F0850 thumb ov107
 *   func_02034714 0x02034714 arm
 *   gMbParentSys 0x021F6EAC data a4
 *   d_021F6E24 0x021F6E24 data a4
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MB_PARENT_SYS_SetState(u16);
extern int func_021F5E7C(int);
extern int MB_PARENT_SYS_LoadFileImage(const char **p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern struct Masks gMbParentSys;
extern u8 d_021F6E24[];
void MB_PARENT_SYS_Register(void *p,int channel){
 MB_PARENT_SYS_SetState(2);
 if(func_021F5E7C(channel)){MB_PARENT_SYS_SetState(7);return;}
 *(int *)(((u8 *)&gMbParentSys)+24)=1;
 if(!MB_PARENT_SYS_LoadFileImage(p))func_02034714((const char *)d_021F6E24,0,(const char *)d_021F6E24);
}
