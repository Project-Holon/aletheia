/*
 * function: func_021D7724
 * address: 0x021D7724
 * packet: pkt_ov120_021D7724
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: 0201EC74 heap widened because caller passes the entire ldrh value without byte truncation.
 * symbols:
 *   s_021D8BEC 0x021D8BEC data a1
 *   func_02030734 0x02030734 arm
 *   func_02045088 0x02045088 arm
 *   func_0203101C 0x0203101C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern const char s_021D8BEC[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void *func_0203101C(u32,u16,u32,u32);
extern void *func_0201C440(void *);
extern void *func_020457B0(u32,u32);
extern void *func_0201D7EC(int,int,int,int,u32);
extern void *func_02045B38(u32,u32,u16,u16);
extern void *func_0201EC74(u32,u32,u32);
extern void *func_02027F60(u16,u16,u32,u32,u16);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
char *func_021D7724(u32 heap,u32 n)
{
    char *p=func_02030734(heap,0xd0,1,s_021D8BEC,0xa9);
    *(u16 *)(p+0xc8)=heap;
    func_02045088(*(u16 *)(p+0xc8));
    func_0201DD60();
    *(void **)(p+0xa0)=func_0203101C(*(u16 *)(p+0xc8),*(u16 *)(p+0xc8),1,0);
    *(void **)(p+0xa4)=func_0201C440((void *)(u32)*(u16 *)(p+0xc8));
    *(void **)(p+0x1c)=func_020457B0(240,*(u16 *)(p+0xc8));
    *(void **)(p+0x18)=func_020457B0(240,*(u16 *)(p+0xc8));
    *(void **)(p+0x20)=func_020457B0(240,*(u16 *)(p+0xc8));
    *(void **)(p+0x14)=func_0201D7EC(23,0,0,0,*(u16 *)(p+0xc8));
    *(void **)(p+12)=func_02045B38(0,2,n,*(u16 *)(p+0xc8));
    *(void **)(p+16)=func_0201EC74(6,64,*(u16 *)(p+0xc8));
    *(void **)(p+0xc0)=func_02027F60(5,9,*(u32 *)(p+20),*(u32 *)(p+0xa4),*(u16 *)(p+0xc8));
    *(void **)(p+4)=func_0201F5DC((void *)1,12,0,*(u16 *)(p+0xc8));
    *(void **)p=func_0201F5DC((void *)6,12,0,*(u16 *)(p+0xc8));
    func_02049B40(23,5,4,0x160,32,*(u16 *)(p+0xc8));
    func_02049B40(23,5,0,0x160,32,*(u16 *)(p+0xc8));
    return p;
}
