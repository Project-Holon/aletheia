/*
 * function: func_021C2048
 * address:  0x021C2048
 * packet:   pkt_ov093_021C2048
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C6CAC  0x021C6CAC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C20BC  0x021C20BC  thumb  ov093
 *   func_021C20D0  0x021C20D0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D5B68(u8 *a);
extern int func_021C6CAC(u8 *p, u8 *a, u32 b, u32 c, int *out);
extern void func_021C8838(u8 *l, int a, int b);
extern void func_021C8860(u8 *l, u32 v);
extern u8 func_021D5440(u8 *p);
extern int func_021C20BC(u8 *p, u8 *a, int r);
extern int func_021C20D0(u8 *p, u8 *a, int c, u8 *l);

void func_021C2048(u8 *p, u8 *a, u32 b, u32 c)
{
    int loc;
    int r;
    if (func_021D5B68(a) != 0)
        return;
    r = func_021C6CAC(p, a, b, c, &loc);
    if (r == 0)
        return;
    func_021C8838(p + 0x1AE4, 2, 378);
    func_021C8860(p + 0x1AE4, func_021D5440(a));
    if (loc == 0 && func_021C20BC(p, a, r) == 0)
        return;
    func_021C20D0(p, a, r, p + 0x1AE4);
}
