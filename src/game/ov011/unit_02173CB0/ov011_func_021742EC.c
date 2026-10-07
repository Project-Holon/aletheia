/*
 * function: func_021742EC
 * address: 0x021742EC
 * packet: pkt_ov011_021742EC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: func_021736D8's matched void forwarder leaves r0 live and the
 *       caller tests r0 at 021742F6; its extern returns int here.
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D4D0 0x0203D4D0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
u32 func_0203D4D0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 func_021742EC(u32 a)
{
    if (func_021736D8() == 0) return 1;
    return func_0203D4D0((u32)func_020399A8(), a, 0x21b, 0, 0, 0, 0, 0);
}
