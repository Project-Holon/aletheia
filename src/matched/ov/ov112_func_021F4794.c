/*
 * function: func_021F4794
 * address: 0x021F4794
 * packet: pkt_ov112_021F4794
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0201CE48(void *);
extern void func_02045808(void *);
extern u32 func_02045770(u32);
extern void func_02043B5C(u32,u32);
extern void *func_02045EC0(u32,u32);
extern u32 func_02012FFC(void);
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void func_0201F73C(void *,int,int,int);
void func_021F4794(u8 *p,u32 index)
{
    u32 t;
    if (*(void **)(p+0x24)) {
        func_0201CE48(*(void **)(p+0x24));
        *(u32 *)(p+0x24)=0;
    }
    if (*(void **)(p+0x2c)) {
        func_02045808(*(void **)(p+0x2c));
        *(u32 *)(p+0x2c)=0;
    }
    func_02043B5C(func_02045770(*(u32 *)(p+0x1c)),15);
    *(void **)(p+0x2c)=func_02045EC0(*(u32 *)(p+0x28),index);
    t=func_02012FFC();
    *(u32 *)(p+0x24)=func_0201CCE4(*(u32 *)(p+0x1c),0,0,*(u32 *)(p+0x2c),*(u32 *)(p+0x20),t,*(u32 *)(p+0x18),2,*(u16 *)p,0);
    func_0201F73C(*(void **)(p+0x1c),1,1,11);
}
