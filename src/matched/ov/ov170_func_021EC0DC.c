/*
 * function: func_021EC0DC
 * address: 0x021EC0DC
 * packet: pkt_ov170_021EC0DC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned,u16);
extern void *func_0204A6C8(void *,unsigned,int,int,unsigned);
extern void *func_0204ABF0(void *,unsigned,int,unsigned,unsigned);
extern void *func_0204AF28(void *,unsigned,unsigned,unsigned);
extern void func_02049238(void *);
#define SLOT(p,o) (*(void **)((p)+(o)))
void func_021EC0DC(char *p)
{
    void *h;
    unsigned i,j;
    h=func_020490F4(116,76);
    for(j=0;j<6;j++) SLOT(p+j*4,0xA0D8)=func_0204A6C8(h,71,1,0,76);
    SLOT(p,0xA11C)=func_0204ABF0(h,72,0,0,76);
    SLOT(p,0xA148)=func_0204AF28(h,73,74,76);
    for(i=0;i<37;i++) SLOT(p+i*4,0x9FF4)=func_0204A6C8(h,75,1,0,76);
    SLOT(p,0xA0F0)=func_0204A6C8(h,67,1,0,76);
    SLOT(p,0xA120)=func_0204ABF0(h,70,0,192,76);
    SLOT(p,0xA14C)=func_0204AF28(h,68,69,76);
    SLOT(p,0xA0F4)=func_0204A6C8(h,64,1,0,76);
    SLOT(p,0xA150)=func_0204AF28(h,65,66,76);
    SLOT(p,0xA090)=func_0204A6C8(h,76,1,0,76);
    SLOT(p,0xA140)=func_0204AF28(h,77,78,76);
    func_02049238(h);
}
