/*
 * function: func_02174954
 * address: 0x02174954
 * packet: pkt_ov011_02174954
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: caller consumes the live r0 result of legacy void forwarders.
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned int u32;
int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned short u16;
int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
u32 func_02174954(u32 p)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8((struct Entry *)((u32)func_020399A8()), 0x22a, 4, p);
}
