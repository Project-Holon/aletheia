/*
 * function: func_021B9F10
 * address: 0x021B9F10
 * packet: pkt_ov222_021B9F10
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9F38..021B9F4C BLDCNT/DISPCNT stores and reads
 * prototype evidence: 434CC full 16B body and both 4349C/434B4 full bodies ignore all input; no caller setup.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA048 0x021BA048 thumb ov222
 *   func_021BA0EC 0x021BA0EC thumb ov222
 *   func_021BA15C 0x021BA15C thumb ov222
 *   func_021BA034 0x021BA034 thumb ov222
 *   d_021BA390 0x021BA390 data a1
 *   d_021BA2CC 0x021BA2CC data a4
 */
#include "../include/Obj26083.h"

typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021BA390[];
extern u32 d_021BA2CC[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void*,int,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void* func_020056A0(u32,u32,u32);
extern void func_021BA048(void*,u32);
extern void func_021BA0EC(unsigned char*,int,int);
extern void func_021BA15C(u32**,u32);
extern void func_021BA034(void*,char*);
void* func_021B9F10(u32 swap,u32 heap)
{
 char*p;
 u32*g;
 p=func_02030734(heap,16,0,d_021BA390,0x1cc);
 func_02082BCC(p,0,16);
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 BG_SYS_ClearGraphicsMemory(0);
 g=d_021BA2CC;
 func_020433E0((const struct DispVram *)g);
 func_0204363C(swap);
 func_0204361C();
 BG_SYS_ClearMainPlanes();
 BG_SYS_ClearSubPlanes();
 func_0201DD60();
 func_021BA048(p,heap);
 func_021BA0EC((unsigned char*)p+4,(int)g,heap);
 func_021BA15C((u32**)(p+8),heap);
 *(void* *)&((struct Obj26083 *)p)->fC=func_020056A0((u32)func_021BA034,(u32)p,0);
 return p;
}
