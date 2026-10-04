/*
 * function: func_021B9E78
 * address: 0x021B9E78
 * packet: pkt_ov221_021B9E78
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9EA0..021B9EB4 BLDCNT/DISPCNT stores and reads
 * prototype evidence: 434CC full 16B body and both 4349C/434B4 full bodies ignore all input; no caller setup.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9FB0 0x021B9FB0 thumb ov221
 *   func_021BA054 0x021BA054 thumb ov221
 *   func_021BA0C4 0x021BA0C4 thumb ov221
 *   func_021B9F9C 0x021B9F9C thumb ov221
 *   d_021BA2F0 0x021BA2F0 data a1
 *   d_021BA220 0x021BA220 data a4
 */
#include "../include/Obj26071.h"

typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021BA2F0[];
extern u32 d_021BA220[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void*,int,u32);
extern void func_0204335C(u32);
extern void func_020433E0(const void*);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void* func_020056A0(u32,u32,u32);
extern void func_021B9FB0(void*,u32);
extern void func_021BA054(unsigned char*,int,int);
extern void func_021BA0C4(u32**,u32);
extern void func_021B9F9C(void*,char*);
void* func_021B9E78(u32 swap,u32 heap)
{
 char*p;
 u32*g;
 p=func_02030734(heap,16,0,d_021BA2F0,0x1cc);
 func_02082BCC(p,0,16);
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 func_0204335C(0);
 g=d_021BA220;
 func_020433E0(g);
 func_0204363C(swap);
 func_0204361C();
 func_020434CC();
 func_02043588();
 func_0201DD60();
 func_021B9FB0(p,heap);
 func_021BA054((unsigned char*)p+4,(int)g,heap);
 func_021BA0C4((u32**)(p+8),heap);
 *(void* *)&((struct Obj26071 *)p)->fC=func_020056A0((u32)func_021B9F9C,(u32)p,0);
 return p;
}
