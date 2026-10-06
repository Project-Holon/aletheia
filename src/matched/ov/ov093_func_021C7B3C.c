/*
 * function: func_021C7B3C
 * address:  0x021C7B3C
 * packet:   pkt_ov093_021C7B3C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int line);

void func_021C7B3C(u8 *p, u32 a, u16 b, u16 c)
{
    func_021D74F8(13068);
    func_021D75EC(2, a);
    func_021D75EC(0xf, b);
    func_021D75EC(0x10, c);
    func_021D70F0(p, 0x89);
    func_021D7540(13073);
}
