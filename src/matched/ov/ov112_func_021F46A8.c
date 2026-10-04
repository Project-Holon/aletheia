/*
 * function: func_021F46A8
 * address: 0x021F46A8
 * packet: pkt_ov112_021F46A8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte padding at 0x021F4746.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0203101C 0x0203101C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(u32);
extern void func_020409B4(u32 index);
extern u32 func_0201D7EC(int,int,int,int,u16);
extern u32 func_02045B38(int,int,int,u16);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049B40(int,int,int,int,int,u16);
extern void func_0201DD68(u32);
extern u32 func_0203101C(u16,u16,int,int);
extern u32 func_0201C440(u16);
void func_021F46A8(u8 *p)
{
    int zero;
    *(u32 *)(p+0x1c)=func_020450F0(4,1,1,30,4,10,1);
    func_02045334((struct Descriptor *)*(u32 *)(p+0x1c));
    func_02045374(*(u32 *)(p+0x1c));
    func_020409B4(4);
    zero=0;
    *(u32 *)(p+0x20)=func_0201D7EC(23,0,0,0,*(u16 *)p);
    *(u32 *)(p+0x28)=func_02045B38(0,2,78,*(u16 *)p);
    func_0201F5BC(4,1,11,0,*(u16 *)p);
    func_0201DD68(func_02049B40(23,5,4,320,32,*(u16 *)p));
    *(u32 *)(p+0x18)=func_0203101C(*(u16 *)p,*(u16 *)p,3,256);
    *(u32 *)(p+0x24)=zero;
    *(u32 *)(p+0x2c)=zero;
    *(u32 *)(p+0x30)=zero;
    *(u32 *)(p+0x34)=zero;
    *(u32 *)(p+0x38)=func_0201C440(*(u16 *)p);
}
