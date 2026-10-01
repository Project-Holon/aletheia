/*
 * function: func_021DD2E0
 * address: 0x021DD2E0
 * packet: pkt_ov137_021DD2E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_020457B0 0x020457B0 arm
 * func_02045CAC 0x02045CAC arm
 * func_02049F78 0x02049F78 arm
 * func_021DE6C0 0x021DE6C0 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020457B0(int,int);
extern void func_02045CAC(u32,int,u32);
extern void func_021DE6C0(void *,void *);
extern u32 func_02049F78(void *,int,void *,int);
void func_021DD2E0(u8 *p,void *q)
{
    int i;
    u32 v;
    for(i=0;i<5;i++) {
        *(u32 *)(p+i*4+68)=func_020457B0(8,114);
        *(u32 *)(p+i*8+312)=0; *(u32 *)(p+i*8+316)=0;
        *(u32 *)(p+i*4+352)=0;
    }
    *(u32 *)(p+92)=func_020457B0(180,114);
    v=func_020457B0(40,114); *(u32 *)(p+96)=v;
    *(u32 *)(p+280)=0;
    func_02045CAC(*(u32 *)(p+64),17,v);
    func_021DE6C0(p,q);
    *(u32 *)(p+24)=0; *(u32 *)(p+32)=0; *(u32 *)(p+28)=0;
    *(u32 *)(p+36)=func_02049F78(q,2,p+40,114);
    *(u32 *)(p+0x4804)=0; *(u32 *)(p+232)=0;
    *(u32 *)(*(u8 **)(p+16)+44)=2;
}
