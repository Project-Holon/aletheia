/*
 * function: func_021F4C6C
 * address: 0x021F4C6C
 * packet: pkt_ov194_021F4C6C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: caller truncates id to u8 before 020403F4, whose own source uses u32.
 * symbols:
 *   d_021F5600 0x021F5600 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021F5600[];
extern void func_020403F4(u8);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *, u32, u32);
void func_021F4C6C(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_020403F4(*(const u32 *)(d_021F5600 + i * 0x2C));
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}
