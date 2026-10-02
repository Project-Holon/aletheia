/*
 * function: func_021BA41C
 * address: 0x021BA41C
 * packet: pkt_ov225_021BA41C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: B294 retains r0 read after call, although own forwarder declares void.
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02027614 0x02027614 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_02027618 0x02027618 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021B9A08 0x021B9A08 thumb ov225
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021BBF14 0x021BBF14 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern const u8 d_021BBF14[];
extern u32 func_020275E4(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_02027614(void);
extern int func_0204AC18(u32,u32,u32,u32,u16,u16,u16);
extern u32 func_02027618(void);
extern int func_0204A6C8(u32,u32,u32,u32,u16);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern int func_0204AF28(u32,u32,u32,u32);
extern void func_02049238(void *);
extern u8 *func_021B9A08(void *);
extern struct Obj *func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B92C(struct Obj *,u32);
void func_021BA41C(char *p)
{
    u8 i;
    void *loader;
    u32 first;
    loader=func_020490F4(func_020275E4(),*(u16 *)(*(char **)p+4));
    *(int *)(p+0x30)=func_0204AC18((u32)loader,func_02027614(),1,128,0,3,*(u16 *)(*(char **)p+4));
    *(int *)(p+0x2c)=func_0204A6C8((u32)loader,func_02027618(),0,1,*(u16 *)(*(char **)p+4));
    first=func_0202761C(0);
    *(int *)(p+0x34)=func_0204AF28((u32)loader,first,func_02027620(0),*(u16 *)(*(char **)p+4));
    func_02049238(loader);
    for(i=0;i<2;i++) {
        char *parent=*(char **)p;
        char *dest=p+i*4;
        *(struct Obj **)(dest+0x38)=func_0204B294((u32)func_021B9A08(*(void **)(parent+8)),*(u32 *)(p+0x2c),*(u32 *)(p+0x30),*(u32 *)(p+0x34),(u32)&d_021BBF14[i*28],1,*(u16 *)(parent+4));
        func_0204B3DC(*(struct Obj **)(dest+0x38),0);
        func_0204B92C(*(struct Obj **)(dest+0x38),1);
    }
}
