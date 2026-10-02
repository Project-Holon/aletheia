/*
 * function: func_021F44F8
 * address: 0x021F44F8
 * packet: pkt_ov112_021F44F8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: 0204B294's own void file retains live r0, which the original stores at +88.
 * symbols:
 *   func_021F4684 0x021F4684 thumb ov112
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   d_021F8298 0x021F8298 data a4
 *   d_021F82B8 0x021F82B8 data a4
 *   d_021F82D8 0x021F82D8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x,y,z; u8 a,b; } Desc;
extern const u32 d_021F8298[],d_021F82B8[],d_021F82D8[];
extern void func_021F4684(const void *,u32,u32);
extern void *func_0204B100(int,u8,u32);
extern void func_0204B270(void *);
extern void func_02043598(u32,u32);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(u32,u32,u32,u32,u32,u16);
extern void func_02049658(u32,u32,u32,u32,u32,u32,u16);
extern void func_020498F4(u32,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern void func_020409B4(u32);
extern int func_0204AC18(u32,u32,u32,u32,u16,u16,u16);
extern u32 func_02027614(void);
extern int func_0204A6C8(u32,u32,u32,u32,u16);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern int func_0204AF28(u32,u32,u32,u32);
extern void *func_0204B294(u32,u32,u32,u32,u32,u16,u16);
void func_021F44F8(u8 *p)
{
    Desc d;
    void *t;
    u32 v;
    u32 w;
    func_021F4684(d_021F8298,4,0);
    func_021F4684(d_021F82B8,6,0);
    func_021F4684(d_021F82D8,7,0);
    *(void **)(p+72)=func_0204B100(8,0,*(u16 *)p);
    func_0204B270(*(void **)(p+72));
    func_02043598(16,1);
    t=func_020490F4((void *)46,*(u16 *)p);
    func_02049B68((u32)t,4,4,0,0,*(u16 *)p);
    func_02049658((u32)t,7,7,0,0,0,*(u16 *)p);
    func_020498F4((u32)t,12,7,0,0,0,*(u16 *)p);
    func_02049238(t);
    if (*(u32 *)(p+12)==0) {
        t=func_020490F4((void *)func_020275E4(),*(u16 *)p);
        func_02049B68((u32)t,func_02027624(),4,288,32,*(u16 *)p);
        func_02049658((u32)t,func_02027628(),6,0,0,0,*(u16 *)p);
        func_020498F4((u32)t,func_0202762C(),6,0,0,0,*(u16 *)p);
        func_020413B0(6,0,21,32,3,9);
        func_020409B4(6);
        *(u32 *)(p+76)=func_0204AC18((u32)t,func_02027614(),1,0,0,3,*(u16 *)p);
        *(u32 *)(p+80)=func_0204A6C8((u32)t,func_02027618(),0,1,*(u16 *)p);
        v=func_0202761C(0);
        w=func_02027620(0);
        *(u32 *)(p+84)=func_0204AF28((u32)t,v,w,*(u16 *)p);
        func_02049238(t);
        d.x=232;
        d.y=168;
        d.z=1;
        d.b=0;
        d.a=0;
        *(void **)(p+88)=func_0204B294(*(u32 *)(p+72),*(u32 *)(p+80),*(u32 *)(p+76),*(u32 *)(p+84),(u32)&d,1,*(u16 *)p);
    }
}
