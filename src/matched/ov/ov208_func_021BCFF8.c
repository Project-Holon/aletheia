/*
 * function: func_021BCFF8
 * address: 0x021BCFF8
 * packet: pkt_ov208_021BCFF8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021C81B4 0x021C81B4 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Ov208Bg { u32 bg; u8 pad[0x28]; };
extern const struct Ov208Bg d_021C81B4[8];
extern void func_020403F4(u8 bgId);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *, int, int);
void func_021BCFF8(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_020403F4(d_021C81B4[i].bg);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}
