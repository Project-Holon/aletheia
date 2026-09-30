/*
 * function: func_021D7A74
 * address: 0x021D7A74
 * packet: pkt_ov120_021D7A74
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02045CAC(void *,u16,int);
extern void *func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,int);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,int,int,int,int);
extern void func_0201F73C(void *,int,u16,int);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_02041B6C(u32);
void func_021D7A74(u8 *p,u16 n)
{
    void *q;
    func_02045CAC(*(void **)(p+0xc),n,*(int *)(p+0x18));
    if (!*(void **)(p+0x30)) *(void **)(p+0x30)=func_020450F0(1,1,21,30,2,11,1);
    q=*(void **)(p+0x30);
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,*(int *)(p+0x18),*(int *)(p+0x14));
    func_0201F73C(q,1,*(u32 *)(p+4),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}
