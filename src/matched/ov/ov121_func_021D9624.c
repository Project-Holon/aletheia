/*
 * function: func_021D9624
 * address: 0x021D9624
 * packet: pkt_ov121_021D9624
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware reads at 021D9654 and 021D965E
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
 *   func_021D97C8 0x021D97C8 thumb ov121
 *   func_021D986C 0x021D986C thumb ov121
 *   func_021D97B4 0x021D97B4 thumb ov121
 *   func_020056A0 0x020056A0 thumb
 *   d_021DFB8C 0x021DFB8C data a1
 *   d_021DF604 0x021DF604 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_021DFB8C[];
extern const int d_021DF604[];
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const void *);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021D97C8(void *p, u32 a);
extern void func_021D986C(void *,const void *,u16);
extern void func_021D97B4(void *,u8 *);
extern void *func_020056A0(void (*)(void *,u8 *),void *,int);
u8 *func_021D9624(int arg,u16 heap)
{
    u8 *p;
    p=func_02030734(heap,28,0,d_021DFB8C,448);
    func_02082BCC(p,0,28);
    *(u16 *)(p+24)=heap;
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0(d_021DF604);
    func_0204363C(arg);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021D97C8(p,heap);
    func_021D986C(p+4,d_021DF604,heap);
    *(void **)(p+20)=func_020056A0(func_021D97B4,p,0);
    return p;
}
