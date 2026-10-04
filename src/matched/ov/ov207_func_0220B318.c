/*
 * function: func_0220B318
 * address: 0x0220B318
 * packet: pkt_ov207_0220B318
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware accesses 0x0220B33E-0x0220B352.
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
 *   func_0220B448 0x0220B448 thumb ov207
 *   func_0220B4EC 0x0220B4EC thumb ov207
 *   func_0220B434 0x0220B434 thumb ov207
 *   d_0220BC20 0x0220BC20 data a1
 *   d_0220BAE8 0x0220BAE8 data a4
 */
extern char d_0220BC20[];
extern unsigned d_0220BAE8[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(void *);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_0220B448(void *,int);
extern void func_0220B4EC(unsigned char *p, int a, int b);
extern void func_0220B434(void *,void *);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
void *func_0220B318(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_0220BC20,455);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0(d_0220BAE8);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_0220B448(p,heap);
    func_0220B4EC((unsigned char *)(p+1),(int)d_0220BAE8,heap);
    p[3]=(unsigned)func_020056A0(func_0220B434,p,0);
    return p;
}
