/*
 * function: func_021F63CC
 * address: 0x021F63CC
 * packet: pkt_ov215_021F63CC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 021F63F2,63F4,63F8,6400,6402,6406.
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
 *   func_021F651C 0x021F651C thumb ov215
 *   func_021F65C0 0x021F65C0 thumb ov215
 *   func_021F6630 0x021F6630 thumb ov215
 *   func_020056A0 0x020056A0 thumb
 *   func_021F6508 0x021F6508 thumb ov215
 *   d_021F73E0 0x021F73E0 data a4
 *   d_021F71C4 0x021F71C4 data a4
 */
typedef unsigned short u16;
extern const char d_021F73E0[];
extern const unsigned d_021F71C4[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(int);
extern void func_020433E0(const void *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021F651C(void *,unsigned);
extern void func_021F65C0(void *,int,unsigned);
extern void func_021F6630(void *,u16);
extern void func_021F6508(int,char *);
extern void *func_020056A0(void (*)(int,char *),char *,unsigned);
char *func_021F63CC(unsigned mode,u16 heap)
{
    char *p;
    p=func_02030734(heap,16,0,d_021F73E0,466);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0(d_021F71C4);
    func_0204363C(mode);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021F651C(p,heap);
    func_021F65C0(p+4,(int)d_021F71C4,heap);
    func_021F6630(p+8,heap);
    *(void **)(p+12)=func_020056A0(func_021F6508,p,0);
    return p;
}
