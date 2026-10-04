/*
 * function: func_021BA0D8
 * address: 0x021BA0D8
 * packet: pkt_ov220_021BA0D8
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BA104/021BA10E DISPCNT hardware masked reads.
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
 *   func_021BA200 0x021BA200 thumb ov220
 *   func_021BA2A4 0x021BA2A4 thumb ov220
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA1EC 0x021BA1EC thumb ov220
 *   d_021BA4F8 0x021BA4F8 data a4
 *   d_021BA428 0x021BA428 data a4
 */
#include "../include/Obj26061.h"
struct DispVram;
extern char d_021BA4F8[];
extern const struct DispVram d_021BA428;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,unsigned,unsigned);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BA200(void *,unsigned);
extern void func_021BA2A4(unsigned char *,int,int);
extern void func_021BA1EC(void *,char *);
extern void *func_020056A0(void *,void *,int);
void *func_021BA0D8(unsigned mode,unsigned heap)
{
    unsigned char *p;
    p=func_02030734(heap,16,0,d_021BA4F8,0x1CA);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0(&d_021BA428);
    func_0204363C(mode);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021BA200(p,heap);
    func_021BA2A4(p+4,(int)&d_021BA428,heap);
    ((struct Obj26061 *)p)->fC=func_020056A0((void *)func_021BA1EC,p,0);
    return p;
}
