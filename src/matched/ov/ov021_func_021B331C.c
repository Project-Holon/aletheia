/*
 * function: func_021B331C
 * address:  0x021B331C
 * packet:   pkt_ov021_021B331C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);

void func_021B331C(u8 *w, int b)
{
    if (b == 1) {
        *(u32 *)(w + 0x194) = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)(w + 0x188)), 0xd);
    } else {
        *(u32 *)(w + 0x194) = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)(w + 0x188)), 0xc);
    }
    *(u32 *)(w + 0x1A0) = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)(w + 0x188)), 0xe);
}
