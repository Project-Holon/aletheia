/*
 * function: func_021F4804
 * address: 0x021F4804
 * packet: pkt_ov112_021F4804
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
typedef unsigned int u32;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32,u32);
extern void *func_02045EC0(u32,u32);
extern void func_0201C6FC(u32,u32,int,int,void *,u32);
extern void func_0201F73C(void *,int,int,int);
void func_021F4804(u8 *p,u32 index)
{
    u32 win;
    if (*(void **)(p+0x2c)) {
        func_02045808(*(void **)(p+0x2c));
        *(u32 *)(p+0x2c)=0;
    }
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(p+0x1c)),15);
    *(void **)(p+0x2c)=func_02045EC0(*(u32 *)(p+0x28),index);
    win=(u32)func_02045770((struct Descriptor *)*(u32 *)(p+0x1c));
    func_0201C6FC(*(u32 *)(p+0x38),win,0,0,*(void **)(p+0x2c),*(u32 *)(p+0x20));
    *(u32 *)(p+0x30)=1;
    func_0201F73C(*(void **)(p+0x1c),1,1,11);
}
