/*
 * function: func_021F92CC
 * address: 0x021F92CC
 * packet: pkt_ov132_021F92CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045C44 0x02045C44 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(u32);
extern void func_020409B4(u32);
extern u32 func_0201D7EC(int,int,int,int,u32);
extern u32 func_02045C44(const void *,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_0203101C(u32,u16,u32,u32);
extern u32 func_0201C440(void *);
void func_021F92CC(u8 *p)
{
    int zero;
    *(u32 *)(p+0xd0)=func_020450F0(1,4,20,24,4,15,1);
    func_02045334((struct Descriptor *)*(u32 *)(p+0xd0));
    func_02045374(*(u32 *)(p+0xd0));
    func_020409B4(1);
    zero=0;
    *(u32 *)(p+0xd4)=func_0201D7EC(23,0,0,0,*(u16 *)p);
    *(u32 *)(p+0xdc)=func_02045C44(*(void **)(*(u8 **)(*(u8 **)(p+0x30)+0x18)+8),*(u16 *)p);
    func_02049B40(23,5,0,480,32,*(u16 *)p);
    *(u32 *)(p+0xcc)=func_0203101C(*(u16 *)p,*(u16 *)p,3,256);
    *(u32 *)(p+0xd8)=zero;
    *(u32 *)(p+0xe0)=zero;
    *(u32 *)(p+0xe4)=zero;
    *(u32 *)(p+0xe8)=func_0201C440((void *)(u32)*(u16 *)p);
}
