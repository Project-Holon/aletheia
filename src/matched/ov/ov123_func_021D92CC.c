/*
 * function: func_021D92CC
 * address: 0x021D92CC
 * packet: pkt_ov123_021D92CC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02045088 0x02045088 arm
 *   func_0203101C 0x0203101C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   d_021DABA8 0x021DABA8 data ov123 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DABA8[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_0201EC64(u32);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void *func_0203101C(u32,u16,u32,u32);
extern u32 func_0201C440(void *);
extern void *func_020457B0(int,u16);
extern void *func_0201D7EC(int,int,int,int,u32);
extern void *func_02045B38(u32,u32,u16,u32);
extern void *func_02027F60(u16,u16,u32,u32,u16);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
u8 *func_021D92CC(u32 heap,u32 bank)
{
    u8 *p;
    p=func_02030734(heap,0xb4,1,d_021DABA8,0x9b);
    *(u16 *)(p+0xb0)=heap;
    func_02045088(*(u16 *)(p+0xb0));
    func_0201DD60();
    *(void **)(p+0x88)=func_0203101C(*(u16 *)(p+0xb0),*(u16 *)(p+0xb0),2,0);
    *(u32 *)(p+0x8c)=func_0201C440((void *)(u32)*(u16 *)(p+0xb0));
    *(void **)(p+0x2c)=func_020457B0(400,*(u16 *)(p+0xb0));
    *(void **)(p+0x30)=func_020457B0(400,*(u16 *)(p+0xb0));
    *(void **)(p+0x28)=func_0201D7EC(23,0,0,0,*(u16 *)(p+0xb0));
    *(void **)(p+0x20)=func_02045B38(0,2,bank,*(u16 *)(p+0xb0));
    *(void **)(p+0x24)=func_0201EC64(*(u16 *)(p+0xb0));
    *(void **)(p+0xac)=func_02027F60(5,9,*(u32 *)(p+0x28),*(u32 *)(p+0x8c),*(u16 *)(p+0xb0));
    *(void **)p=func_0201F5DC((void *)1,12,0,*(u16 *)(p+0xb0));
    *(void **)(p+8)=func_0201F5DC((void *)5,12,0,*(u16 *)(p+0xb0));
    *(void **)(p+4)=func_0201F5DC((void *)6,12,0,*(u16 *)(p+0xb0));
    func_02049B40(23,5,4,352,32,*(u16 *)(p+0xb0));
    func_02049B40(23,5,0,352,32,*(u16 *)(p+0xb0));
    return p;
}
