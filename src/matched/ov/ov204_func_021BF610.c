/*
 * function: func_021BF610
 * address: 0x021BF610
 * packet: pkt_ov204_021BF610
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02014C08 0x02014C08 thumb
 *   func_02014D2C 0x02014D2C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct McssSys;
extern void func_02014C08(char *);
extern void func_02014D2C(struct McssSys *);
void func_021BF610(u8 *p)
{
    func_02014C08(*(char **)(p+4));
    func_02014D2C(*(struct McssSys **)(p+4));
}
