/*
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete
 * address: 0x021B9F20
 * packet: pkt_ov221_021B9F20
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9F46..021B9F60 display registers
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera 0x021BA130 thumb ov221
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteClact 0x021BA094 thumb ov221
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg 0x021BA010 thumb ov221
 *   func_0201DD68 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj26072.h"

typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern int CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(int*);
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char*);
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void*);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void*,int,u32);
extern u32 func_020307B0(void *p);
/* volatile accesses: display cleanup, original 021B9F46..021B9F60. */
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete(char*p)
{
 func_02030EAC(*(void* *)&((struct Obj26072 *)p)->fC);
 CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera((int*)(p+8));
 CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteClact(p+4);
 CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg(p);
 func_0201DD68();
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 MI_CpuFill8(p,0,16);
 func_020307B0(p);
}
