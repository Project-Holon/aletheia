/*
 * function: func_021BB0F8
 * address: 0x021BB0F8
 * packet: pkt_ov068_021BB0F8
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021BB138 0x021BB138 thumb ov068
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02082BCC(void *, u32, u32);
extern void func_021BB138(void *, int);
void func_021BB0F8(u8 *p, int value, int callback)
{
    func_02082BCC(p, 0, 16);
    *(int *)(p + 12) = value;
    func_021BB138(p, callback);
}
