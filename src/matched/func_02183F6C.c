/*
 * function: func_02183F6C
 * address:  0x02183F6C
 * packet:   pkt_02183F6C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A48C  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_021848D4     0x021848D4  data  ov168  a4
 */
typedef unsigned int u32;
typedef unsigned short u16;

extern void func_0204A48C(void *a, void *b, u16 c);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

void func_02183F6C(int unused, u32 b)
{
    func_0204A48C((void *)0x020A1448, (void *)0x021848D4, b);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
