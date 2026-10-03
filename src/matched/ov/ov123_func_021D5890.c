/*
 * function: func_021D5890
 * address: 0x021D5890
 * packet: pkt_ov123_021D5890
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045808 0x02045808 arm
 *   func_0207D658 0x0207D658 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x,y,z,w; } Config;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02045808(struct U16Vec *vec);
extern int func_02027778(Config *,void *);
extern void func_0207D658(u32 addr, int plane, int brightness);
int func_021D5890(char *p,int mode)
{
    Config c;
    int result;
    c.size=*(u16 *)(p+0xb0);
    c.flag=2;
    c.target=p+0x8c;
    switch (mode) {
    case 0: c.x=32; c.y=12; c.mode=1; break;
    case 1: c.x=32; c.y=24; c.mode=1; break;
    }
    c.z=13;
    c.w=3;
    *(void **)(p+0x8c)=func_020457B0(100,*(u16 *)(p+0xb0));
    func_02045CAC(*(void **)(p+0x20),4,*(void **)(p+0x8c));
    *(u16 *)(p+0x90)=0x39e0;
    *(void **)(p+0x98)=func_020457B0(100,*(u16 *)(p+0xb0));
    func_02045CAC(*(void **)(p+0x20),5,*(void **)(p+0x98));
    *(u16 *)(p+0x9c)=0x39e0;
    result=func_02027778(&c,*(void **)(p+0xa4));
    func_02045808(*(void **)(p+0x8c));
    func_02045808(*(void **)(p+0x98));
    func_0207D658(0x04001050,9,-8);
    return result;
}
