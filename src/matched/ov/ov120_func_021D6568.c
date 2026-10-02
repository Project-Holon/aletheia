/*
 * function: func_021D6568
 * address: 0x021D6568
 * packet: pkt_ov120_021D6568
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0202E940 0x0202E940 thumb
 *   func_0202E9AC 0x0202E9AC thumb
 *   func_02049238 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(void *,u16);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern void func_02049990(void *,u32,u32,u32,u16,u32,u32,u16);
extern void *func_0204A6C8(void *,u32,u32,u32,u16);
extern void *func_0204AC18(void *,u32,u32,u32,u32,u32,u16);
extern void *func_0204AF28(void *,u32,u32,u16);
extern void *func_0202E940(u16,u16,u32,u16);
extern void func_0202E9AC(void *,void *,u32,u32,u32);
extern void func_02049238(void *);
extern void func_0207D63C(void *,int,int,int,int);
void func_021D6568(u8 *p)
{
    int i;
    void *t;
    t=func_020490F4((void *)144,*(u16 *)(p+0xf4));
    func_02049B68(t,3,4,0,192,*(u16 *)(p+0xf4));
    func_02049B68(t,1,4,0,64,*(u16 *)(p+0xf4));
    *(u32 *)(p+8)=func_02049740(t,6,7,0,0,*(u16 *)(p+0xf4));
    func_02049990(t,17,7,0,*(u32 *)(p+8),0,0,*(u16 *)(p+0xf4));
    *(u32 *)p=func_02049740(t,8,4,0,0,*(u16 *)(p+0xf4));
    func_02049990(t,18,4,0,*(u32 *)p,0,0,*(u16 *)(p+0xf4));
    func_02049B68(t,1,0,0,0,*(u16 *)(p+0xf4));
    *(u32 *)(p+4)=func_02049740(t,6,0,0,0,*(u16 *)(p+0xf4));
    func_02049990(t,12,0,0,*(u32 *)(p+4),0,0,*(u16 *)(p+0xf4));
    *(void **)(p+0x70)=func_0204A6C8(t,5,0,1,*(u16 *)(p+0xf4));
    *(void **)(p+0x24)=func_0204AC18(t,0,1,320,0,1,*(u16 *)(p+0xf4));
    *(void **)(p+0xbc)=func_0204AF28(t,10,22,*(u16 *)(p+0xf4));
    *(void **)(p+0x28)=func_0204A6C8(t,7,0,1,*(u16 *)(p+0xf4));
    *(void **)(p+0x18)=func_0204AC18(t,2,1,256,0,8,*(u16 *)(p+0xf4));
    *(void **)(p+0x74)=func_0204AF28(t,11,23,*(u16 *)(p+0xf4));
    *(void **)(p+0x2c)=func_0204A6C8(t,7,0,0,*(u16 *)(p+0xf4));
    *(void **)(p+0x1c)=func_0204AC18(t,2,0,0,0,8,*(u16 *)(p+0xf4));
    *(void **)(p+0x78)=func_0204AF28(t,11,23,*(u16 *)(p+0xf4));
    *(void **)(p+0xf8)=func_0202E940(0,16,0,*(u16 *)(p+0xf4));
    func_0202E9AC(*(void **)(p+0xf8),t,1,0,16);
    *(void **)(p+0xfc)=func_0202E940(0,16,7,*(u16 *)(p+0xf4));
    func_0202E9AC(*(void **)(p+0xfc),t,1,0,16);
    func_02049238(t);
    t=func_020490F4((void *)32,*(u16 *)(p+0xf4));
    for(i=0;i<16;i++) {
        *(void **)(p+i*4+0x30)=func_0204A6C8(t,i+1,0,1,*(u16 *)(p+0xf4));
        *(void **)(p+i*4+0x7c)=func_0204AF28(t,i*2+17,i*2+18,*(u16 *)(p+0xf4));
    }
    *(void **)(p+0x20)=func_0204AC18(t,0,1,0,0,8,*(u16 *)(p+0xf4));
    func_02049238(t);
    func_0207D63C((void *)0x04001050,5,24,15,9);
}
