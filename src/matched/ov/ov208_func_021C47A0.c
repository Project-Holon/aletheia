/*
 * function: func_021C47A0
 * address: 0x021C47A0
 * packet: pkt_ov208_021C47A0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02014D2C 0x02014D2C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct McssSys;
extern void func_02014D2C(struct McssSys *sys);
void func_021C47A0(u32 a, u32 b, u32 c, u8 *p)
{
    if (p != 0 && *(struct McssSys **)(p + 8) != 0)
        func_02014D2C(*(struct McssSys **)(p + 8));
}
