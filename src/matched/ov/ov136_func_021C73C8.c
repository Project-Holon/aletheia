/*
 * function: func_021C73C8
 * address: 0x021C73C8
 * packet: pkt_ov136_021C73C8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 021C741E halfword is zero alignment padding.
 * symbols:
 *   func_02008FA4 0x02008FA4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Flags { u8 index : 7; u8 flag : 1; };
extern void *func_0201292C(void *);
extern u32 func_02008FA4(void *);
extern u16 func_020213AC(u32);
extern int func_02007E50(void *, u16, int, int);
void func_021C73C8(u8 *p)
{
    void *q = func_0201292C(**(void ***)(p + 4));
    *(u16 *)(p + 0x22) = func_020213AC(func_02008FA4(*(void **)(*(u8 **)(p + 8) + p[0x1F]*4 + 0x298)));
    if (func_02007E50(q, *(u16 *)(p + 0x22), 1, 0x66) == 1) {
        ((struct Flags *)(p + 0x21))->flag = 0;
        return;
    } else {
        ((struct Flags *)(p + 0x21))->flag = 1;
        return;
    }
}
