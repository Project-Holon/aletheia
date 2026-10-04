/*
 * function: func_02173F74
 * address: 0x02173F74
 * packet: pkt_ov011_02173F74
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: The matched void forwarder func_021736D8 leaves r0 live and this
 *       caller tests it at 02173F7C. func_0203D3A8's final send result is
 *       returned in live r0 at 02173F94, so both externs return int here.
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned short u16;
int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);

int func_02173F74(int a, u8 *b)
{
    if (func_021736D8() == 0) return 0;
    return func_0203D3A8((struct Entry *)((int)func_020399A8()), 0x213, 0x34, (u32)(b + 0x78));
}
