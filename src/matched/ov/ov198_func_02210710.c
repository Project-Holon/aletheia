/*
 * function: func_02210710
 * address: 0x02210710
 * packet: pkt_ov198_02210710
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_020457B0 0x020457B0 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02045B38(u32,u32,u32,u32);
extern void *func_0201D7EC(int,int,int,int,u32);
extern void *func_0201EC64(u32);
extern void *func_0201C450(u16,u32);
extern void *func_020457B0(u32,u32);
void func_02210710(char *p)
{
    *(void **)(p+0x1ea0)=func_02045B38(0,2,0x12,*(u16 *)(*(char **)p+0x10));
    *(void **)(p+0x1e9c)=func_0201D7EC(0x17,3,0,0,*(u16 *)(*(char **)p+0x10));
    *(void **)(p+0x1ea4)=func_0201EC64(*(u16 *)(*(char **)p+0x10));
    *(void **)(p+0x1eac)=func_0201C450(0x800,*(u16 *)(*(char **)p+0x10));
    *(void **)(p+0x1ea8)=func_020457B0(0x200,*(u16 *)(*(char **)p+0x10));
}
