/*
 * function: func_021C2F70
 * address:  0x021C2F70
 * packet:   pkt_ov093_021C2F70
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0201C0BC  0x0201C0BC  thumb
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 sub_0201C0BC(u16 id, u32 idx, s32 *out);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(u8 *p, int k);
extern int func_021D775C(int key);
extern void func_021D7540(int line);

void func_021C2F70(u8 *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2)
{
    u32 m;
    *s1 = sub_0201C0BC(x, y, s2);
    func_021D74F8(8275);
    func_021D75EC(3, func_021D5440(c));
    func_021D75EC(4, func_021D5440(s0));
    func_021D75A8(0x1F, *s1);
    func_021D75A8(0x20, *s2);
    func_021D75A8(0x35, 1);
    func_021D70F0(p, 0x59);
    *s1 = func_021D775C(0x1F);
    *s2 = func_021D775C(0x20);
    m = (u8)func_021D775C(0x35);
    if (m > 1)
        *s2 = *s2 * m;
    func_021D7540(8290);
    if (*s1 == 8)
        *s1 = 0;
}
