/*
 * function: func_021C67A8
 * address: 0x021C67A8
 * packet: pkt_ov128_021C67A8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * calls: Heap parameters are widened where the original supplies no truncation.
 * symbols:
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_02049238 0x02049238 arm
 *   d_020A1448 0x020A1448 data a4
 *   d_021CA5CC 0x021CA5CC data a4
 *   d_021CA7D0 0x021CA7D0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 a,b;u8 c,d,e,f;u32 g;u16 h[6];} Config;
extern const Config d_020A1448;
extern u8 d_021CA5CC[],d_021CA7D0[];
extern void func_0204A48C(const Config *,u32,u32);
struct Bank;
struct Obj;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern int func_0204A6C8(void *,u32,u32,u32,u32);
extern int func_0204ABF0(void *,u32,u32,u32,u32);
extern int func_0204AF28(void *,u32,u32,u32);
extern u32 func_020275E4(void);
extern void *func_020490F4(u32,u32);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void func_02049238(void *);
void func_021C67A8(char *p,int heap)
{
    Config config=d_020A1448;
    void *bank,*archive;
    u32 first,second;
    config.c=16;
    config.d=112;
    func_0204A48C(&config,(u32)d_021CA5CC,heap);
    bank=func_0204B100(32,0,heap);
    *(void **)(p+0x138)=bank;
    func_0204B270(bank);
    *(void **)(p+0x140)=func_0204B034(d_021CA7D0,1,heap);
    bank=func_0204B100(18,1,heap);
    *(void **)(p+0x13c)=bank;
    func_0204B258(bank,*(void **)(p+0x140));
    *(int *)(p+0x144)=func_0204A6C8(*(void **)(p+8),4,0,0,heap);
    *(int *)(p+0x14c)=func_0204ABF0(*(void **)(p+8),1,0,0,heap);
    *(int *)(p+0x154)=func_0204AF28(*(void **)(p+8),15,16,heap);
    archive=func_020490F4(func_020275E4(),heap);
    *(int *)(p+0x148)=func_0204A6C8(archive,func_02027618(),0,0,heap);
    *(int *)(p+0x150)=func_0204ABF0(archive,func_02027614(),0,96,heap);
    first=func_0202761C(2);
    second=func_02027620(2);
    *(int *)(p+0x158)=func_0204AF28(archive,first,second,heap);
    func_02049238(archive);
}
