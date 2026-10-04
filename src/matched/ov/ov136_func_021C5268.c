/*
 * function: func_021C5268
 * address: 0x021C5268
 * packet: pkt_ov136_021C5268
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
void func_021C5268(u8 *p)
{
    if (p[0xB] == 1) {
        *(u32 *)(p + 0x130) = (u32)func_02045EC0(*(void **)(p + 0x20), 0);
        *(u16 *)(p + 0x134) = 0x39E3;
        *(u32 *)(p + 0x138) = 0;
        *(u32 *)(p + 0x13C) = (u32)func_02045EC0(*(void **)(p + 0x20), 1);
        *(u16 *)(p + 0x140) = 0x39E3;
        *(u32 *)(p + 0x144) = 1;
        *(u32 *)(p + 0x128) = func_02027FEC(*(u32 *)(p + 0x108), (u32)(p + 0x130), 21, 18, 10, (u16)*(u32 *)p);
        *(u32 *)(p + 0x12C) = func_02027FEC(*(u32 *)(p + 0x108), (u32)(p + 0x13C), 21, 21, 10, (u16)*(u32 *)p);
    }
}
