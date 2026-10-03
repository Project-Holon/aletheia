/*
 * function: func_021C1610
 * address: 0x021C1610
 * packet: pkt_ov110_021C1610
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Heap argument is u16: widening it adds a truncation before func_021C1738.
 * volatile: hardware display registers re-read at 021C163C and 021C1646.
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
 *   func_021C1738 0x021C1738 thumb ov110
 *   func_021C17DC 0x021C17DC thumb ov110
 *   func_021C1724 0x021C1724 thumb ov110
 *   func_020056A0 0x020056A0 thumb
 *   d_021C3C98 0x021C3C98 data a1
 *   d_021C3A44 0x021C3A44 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_021C3C98[];
extern const unsigned d_021C3A44[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,unsigned);
extern void func_0204335C(unsigned);
extern void func_020433E0(const void *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021C1738(void *,u16);
extern void func_021C17DC(void *,unsigned,unsigned);
extern void func_021C1724(int a, u8 *p);
extern void *func_020056A0(void *,void *,unsigned);
void *func_021C1610(unsigned arg, u16 heap) {
    u8 *p;
    p=func_02030734(heap,16,0,d_021C3C98,0x151);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0(d_021C3A44);
    func_0204363C(arg);
    func_0204361C(); func_020434CC(); func_02043588();
    func_0201DD60();
    func_021C1738(p,heap);
    func_021C17DC(p+4,(unsigned)d_021C3A44,heap);
    *(void **)(p+12)=func_020056A0(func_021C1724,p,0);
    return p;
}
