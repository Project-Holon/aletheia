/*
 * function: func_02197700
 * address:  0x02197700
 * packet:   pkt_ov021_02197700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02196228  0x02196228  thumb  ov021
 *   func_02041570  0x02041570  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02197644  0x02197644  thumb  ov021
 *   func_02196034  0x02196034  thumb  ov021
 *   func_021978AC  0x021978AC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void func_02196228(u8 *p, int flag);
extern void func_02041570(int channel, u16 val);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02197644(u8 *, u32);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_021978AC(u8 *a);

void func_02197700(u8 *a)
{
    func_02196228(a, 1);
    func_02041570(5, 0);
    func_02045CAC((struct MsgBank *)(*(u32 *)(a + 0x28)), 25, (void *)(*(u32 *)(a + 0x38)));
    func_02197644(a, 0);
    func_02196034(a, func_021978AC, 0x761);
}
