/*
 * function: func_021E10D8
 * address: 0x021E10D8
 * packet: pkt_ov119_021E10D8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02028590 tail forwarder has a void legacy declaration; caller stores its live r0 at 021E117E.
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0203101C 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   func_02027F60 0x02027F60 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0201EC64(u32);
extern void *func_02045B38(u32,u32,u32,u32);
extern void *func_0201D7EC(int,int,int,int,u32);
extern void *func_020457B0(int,u16);
extern void *func_0201C440(u16);
extern void func_0201DD78(u32,u32,u32);
extern void *func_0203101C(u32,u16,u32,u32);
extern void *func_02028590(u32,u32,u32,u32);
extern void *func_02027F60(u16,u16,u32,u32,u16);
void func_021E10D8(char *p)
{
    *(void **)(p+0x724)=func_0201EC64(*(u16 *)(p+0x5f4));
    *(void **)(p+0x720)=func_02045B38(0,2,159,*(u16 *)(p+0x5f4));
    *(void **)(p+0x728)=func_0201D7EC(23,0,0,0,*(u16 *)(p+0x5f4));
    *(void **)(p+0x730)=func_020457B0(128,*(u16 *)(p+0x5f4));
    *(void **)(p+0x734)=func_020457B0(128,*(u16 *)(p+0x5f4));
    *(void **)(p+0x738)=func_020457B0(128,*(u16 *)(p+0x5f4));
    *(void **)(p+0x73c)=func_020457B0(128,*(u16 *)(p+0x5f4));
    *(void **)(p+0x740)=func_0201C440(*(u16 *)(p+0x5f4));
    func_0201DD78(1,2,15);
    *(void **)(p+0x744)=func_0203101C(*(u16 *)(p+0x5f4),*(u16 *)(p+0x5f4),2,0);
    *(void **)(p+0x74c)=func_02028590(15,1,0,*(u16 *)(p+0x5f4));
    *(void **)(p+0x6b0)=func_02027F60(6,9,*(u32 *)(p+0x728),*(u32 *)(p+0x740),*(u16 *)(p+0x5f4));
}
