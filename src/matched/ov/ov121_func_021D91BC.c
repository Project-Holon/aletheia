/*
 * function: func_021D91BC
 * address: 0x021D91BC
 * packet: pkt_ov121_021D91BC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021D6C58 0x021D6C58 thumb ov121
 *   func_0204B53C 0x0204B53C arm
 *   func_02005728 0x02005728 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_02082BCC(void *,int,int);
extern void *func_021D6C58(void *,int);
extern void func_0204B53C(void *,void *);
extern int func_02005728(int);
void func_021D91BC(u8 *p,void *q,u16 h)
{
    int i;
    u8 *r;
    s16 xy[2];
    func_02082BCC(p,0,296);
    *(int *)(p+16)=-819;
    *(void **)(p+280)=q;
    *(int *)(p+20)=-819;
    *(u16 *)(p+292)=h;
    for(i=0;i<32;i++) {
        func_0204B53C(func_021D6C58(*(void **)(p+280),i+1),xy);
        r=p+i*4;
        *(int *)(r+24)=xy[1]<<12;
        *(int *)(r+152)=func_02005728(4096)+6554;
    }
}
