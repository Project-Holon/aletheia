/*
 * function: func_021BC3F0
 * address: 0x021BC3F0
 * packet: pkt_ov223_021BC3F0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: C660 heap remains int here: no caller truncation; callee u16 body also accepts the observed full-width input.
 * volatile: hardware accesses 0x021BC416-0x021BC42A.
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
 *   func_021BC54C 0x021BC54C thumb ov223
 *   func_021BC5F0 0x021BC5F0 thumb ov223
 *   func_021BC660 0x021BC660 thumb ov223
 *   func_021BC538 0x021BC538 thumb ov223
 *   d_021BCB08 0x021BCB08 data a1
 *   d_021BC980 0x021BC980 data a4
 */
extern char d_021BCB08[];
extern unsigned d_021BC980[];
extern void *func_02030734(unsigned,unsigned,unsigned,const char *,unsigned);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(int);
extern void func_020433E0(void *);
extern void func_0204363C(int);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BC54C(void *,int);
extern void func_021BC5F0(int *,int,int);
extern void func_021BC660(int *,int);
extern void func_021BC538(void *,char *);
extern void *func_020056A0(void (*)(void *,char *),void *,int);
void *func_021BC3F0(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_021BCB08,463);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0(d_021BC980);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021BC54C(p,heap);
    func_021BC5F0((int *)(p+1),(int)d_021BC980,heap);
    func_021BC660((int *)(p+2),heap);
    p[3]=(unsigned)func_020056A0(func_021BC538,p,0);
    return p;
}
