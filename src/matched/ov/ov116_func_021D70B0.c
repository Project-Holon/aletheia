/*
 * function: func_021D70B0
 * address: 0x021D70B0
 * packet: pkt_ov116_021D70B0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D70EC 0x021D70EC thumb ov116
 *   func_021D7158 0x021D7158 thumb ov116
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021D70EC(u8 *, int *);
extern int func_021D7158(u8 *);
int func_021D70B0(void *unused, u8 *p)
{
    int result;
    if (func_021D70EC(p, &result) && func_021D7158(p) == 0) return 1;
    return 0;
}
