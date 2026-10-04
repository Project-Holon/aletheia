/*
 * function: func_021D821C
 * address: 0x021D821C
 * packet: pkt_ov116_021D821C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
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
 *   func_021D8304 0x021D8304 thumb ov116
 *   func_020056A0 0x020056A0 thumb
 *   d_021D858C 0x021D858C data a1
 *   d_021D83C0 0x021D83C0 data a4
 *   func_021D82F8 0x021D82F8 thumb ov116
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 are read/written at 021D8244..021D8258 or 021D82C4..021D82DA.
 */
#include "../include/Obj22632.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(unsigned);
extern void func_020433E0(void *);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021D8304(void *,unsigned);
extern void *func_020056A0(void *,void *,int);
extern void func_021D82F8(void *,void *);
extern char d_021D858C[], d_021D83C0[];
void *func_021D821C(int a,unsigned heap) {
 void *p;
 p=func_02030734(heap,16,0,d_021D858C,0x1bc);
 func_02082BCC(p,0,16);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 func_0204335C(0); func_020433E0(d_021D83C0); func_0204363C(a);
 func_0204361C(); func_020434CC(); func_02043588(); func_0201DD60();
 func_021D8304(p,heap);
 ((struct Obj22632 *)p)->fC=func_020056A0((void *)func_021D82F8,p,0);
 return p;
}
