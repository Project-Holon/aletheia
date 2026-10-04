/*
 * function: func_021C0134
 * address: 0x021C0134
 * packet: pkt_ov110_021C0134
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   overlay_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02024988 0x02024988 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02031324 0x02031324 arm
 *   func_021C0490 0x021C0490 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const u8 overlay_id[];
typedef signed int     s32;
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
extern int func_02034AC4(s32 handle);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0203064C(u32,u32,u32);
extern u8 *func_0203159C(void *,unsigned,unsigned);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_02024988(int a0);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201C440(void *p);
extern void *func_02031324(unsigned);
extern void func_021C0490(u8 *);
int func_021C0134(void *owner,int unused,void **input) {
    u8 *p;
    func_02034AC4((unsigned)overlay_id);
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    func_0203064C(1,81,0x1c000);
    p=func_0203159C(owner,176,81);
    func_02082BCC(p,0,176);
    *(u16 *)(p+4)=81;
    *(void **)(p+0x1c)=*input;
    *(void **)(p+0x20)=func_02024988((int)(*input));
    *(void ***)p=input;
    *(void **)(p+0x58)=func_0201D7EC(23,0,0,0,*(u16 *)(p+4));
    *(void **)(p+0x60)=func_02045B38(0,2,146,*(u16 *)(p+4));
    *(void **)(p+0x5c)=(void *)func_0201C440((void *)(*(u16 *)(p+4)));
    *(void **)(p+0xac)=func_02031324(*(u16 *)(p+4));
    *(u8 *)(p+0x94)=255;
    *(u8 *)(p+0x95)=255;
    func_021C0490(p);
    return 1;
}
